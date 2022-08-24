using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System;
using Unity.AI.Navigation;
using UnityEngine.AI;
using DG.Tweening;
using UnityEngine.UI;

[RequireComponent(typeof(CapsuleCollider))]
[RequireComponent(typeof(NavMeshAgent))]
[RequireComponent(typeof(Rigidbody))]
[RequireComponent(typeof(Animator))]
public class CrewManager : MonoBehaviour, IHighlightable, IHealthDestroyable
{
    [SerializeField] private string crewName;
    [SerializeField] private CrewSpecialization crewSpec;
    [SerializeField] private CrewMemberStates crewState;
    [SerializeField] private float maxHealth;
    [SerializeField] private float maxSpeed;
    [SerializeField] private Transform currentBaseTransform, currentModelTransform, UIPositionPoint, Effects, baseHighLight, leftHand, rightHand;
    [SerializeField] private settings GeneralSettings;
    [SerializeField] private Material highlightMaterial;
    [SerializeField] private Transform wrenchExample, hammerExample;
    [SerializeField] private AudioSource audio;
    [SerializeField] private bool isDestroyable = true;

    private AudioClip grabSound, grabOff;
    private Material baseMaterial;
    private Animator animator;
    private Vector3 pointOfRespawn, currentPos, previousPos, OnScreenPosition;
    private float currentSpeed;
    private NavMeshAgent navAgent;
    public Rigidbody rigidBody;
    private bool isHighlightEffectInProgress;
    private float health, speed;
    private bool isShowingUIBar;
    private bool isTakenObjectDestroyable;

    private Dictionary<GameObject, DamageDealer> damagingObjects = new Dictionary<GameObject, DamageDealer>();
    private HashSet<NegativeEffects> activatedEffects = new HashSet<NegativeEffects>(); 
    
    //moving to points
    private GameObject PlaceOfDestination;
    private GameObject PlaceOfCurrentLocation;

    //interaction
    private GameObject currentTakenObject;

    //health bar UI
    private GameObject uiHealthBar;
    private RectTransform uiHealthBarRect;

    public GameObject CurrentTakenObject
    {
        get
        {
            return currentTakenObject;
        }

        set
        {
            if (currentTakenObject == null && value != null)
            {
                if (value.GetComponent<Supply>() != null && (SuppliesType)value.GetComponent<Supply>().GetTypeOfObject() == SuppliesType.full_engine_fuel)
                {
                    Speed *= 0.5f;
                }

                audio.clip = grabSound;
                audio.Play();
            }

            if (currentTakenObject != null && value == null)
            {
                isTakenObjectDestroyable = false;
                Speed = maxSpeed;

                audio.clip = grabOff;
                audio.Play();
            }

            currentTakenObject = value;

            if (currentTakenObject != null && currentTakenObject.GetComponent<IHealthDestroyable>() != null && currentTakenObject.GetComponent<IHealthDestroyable>().IsDestroyable())
            {
                isTakenObjectDestroyable = true;
            }
            else
            {
                isTakenObjectDestroyable = false;
            }
        }
    }

    public float Health
    {
        get { return health; }

        set
        {
            if (value < 0)
            {
                health = 0;
            }
            else if (value >= maxHealth)
            {
                health = maxHealth;
                if (!isShowingUIBar) StartCoroutine(ShowUIBarWhileActive());
            }
            else
            {
                health = value;
                if (!isShowingUIBar) StartCoroutine(ShowUIBarWhileActive());
            }
        }
    }

    public float Speed
    {
        get { return speed; }

        set
        {
            if (value < 0)
            {
                speed = 0;
                navAgent.speed = speed;
            }
            else if (value >= maxSpeed)
            {
                speed = maxSpeed;
                navAgent.speed = speed;
            }
            else
            {
                speed = value;
                navAgent.speed = speed;
            }
        }
    }

    private void Start()
    {
        grabSound = Resources.Load<AudioClip>("audio/sounds/grab something");
        grabOff = Resources.Load<AudioClip>("audio/sounds/grab off");
    }


    // Start is called before the first frame update
    void OnEnable()
    {        
        if (audio == null) audio = GetComponent<AudioSource>();
        audio.volume = GeneralSettings.AudioSourceVolume_crew;
        if (baseMaterial == null) baseMaterial = Highlighting.GetBaseMaterial(baseHighLight);

        health = maxHealth;
        currentBaseTransform.position = pointOfRespawn;

        PlaceOfDestination = null;
        PlaceOfCurrentLocation = null;
        currentTakenObject = null;

        damagingObjects.Clear();
        activatedEffects.Clear();

        

        navAgent = GetComponent<NavMeshAgent>();
        Speed = maxSpeed;
        navAgent.speed = maxSpeed;
        currentBaseTransform = transform;
        crewState = CrewMemberStates.idle;
        animator = GetComponent<Animator>();
        animator.SetLayerWeight(1, 0);
        rigidBody = GetComponent<Rigidbody>();
                
        if (uiHealthBarRect != null) HideUI();
        makeIdleAnimation();
        //navAgent.isStopped = true;
        DeactivateAnyHandsInstruments();
    }

    public void InitUI()
    {
        uiHealthBar = Instantiate(UIManager.GetUIPrefab(UIPanelTypes.health_bar), GameObject.Find("MainCanvas").transform);
        uiHealthBarRect = uiHealthBar.GetComponent<RectTransform>();
        //GameManagement.MainUIHandler += UpdateUIPosition;
        HideUI();
    }

    public void UpdateUIPosition(Camera camera)
    {        
        if (uiHealthBarRect.gameObject.activeSelf)
        {
            OnScreenPosition = camera.WorldToScreenPoint(UIPositionPoint.position);
            uiHealthBarRect.anchoredPosition = new Vector2(OnScreenPosition.x, OnScreenPosition.y + 20);
        }
        else
        {
            GameManagement.MainUIHandler -= UpdateUIPosition;
            print("!!!!!!!!!!!");
        }
    }

    public void ShowUI()
    {
        if (!uiHealthBarRect.gameObject.activeSelf) uiHealthBarRect.gameObject.SetActive(true);
        GameManagement.MainUIHandler += UpdateUIPosition;
    }

    public void HideUI()
    {
        if (uiHealthBarRect.gameObject.activeSelf) uiHealthBarRect.gameObject.SetActive(false);
        GameManagement.MainUIHandler -= UpdateUIPosition;
    }

    public void UpdateUIHealthData()
    {
        uiHealthBarRect.transform.GetChild(1).GetComponent<Image>().fillAmount = Health / maxHealth;
    }

    
    public void DecreaseHealthAmount(float amount)
    {
        Health -= amount;
        //print(Health + " - crew");
        UpdateUIHealthData();
    }
    


    // Update is called once per frame
    void Update()
    {
        if (CurrentTakenObject != null && isTakenObjectDestroyable)
        {
            if (!CurrentTakenObject.activeSelf || CurrentTakenObject.GetComponent<IHealthDestroyable>().CurrentHealthAmount() <= 0)
            {
                ThrowAwayCurrentTakenObject();
            }
        }

        //print(crewState);
        currentPos = currentBaseTransform.position;
        currentSpeed = Vector3.Distance(currentPos, previousPos);
        
        if (crewState != CrewMemberStates.sit)
        {
            if (currentSpeed <= 0.01f)
            {
                makeIdleAnimation();
            }
            else if (currentSpeed > 0.01f && currentSpeed <= 0.03f)
            {
                makeWalkAnimation();
            }
            else if (currentSpeed > 0.03f)
            {
                makeRunAnimation();
            }
        }
        

        if (Input.GetKeyDown(KeyCode.A))
        {
            if (CurrentTakenObject!=null && CurrentTakenObject.GetComponent<ITakenAndMovable>()!=null)
            {
                ThrowAwayCurrentTakenObject();
            }
        }

        previousPos = currentPos;
        
        //=================
        if (CurrentTakenObject !=null && CurrentTakenObject.GetComponent<Instrument>() != null && CurrentTakenObject.GetComponent<Instrument>().GetCurrentIncidentInAction() != null)
        {
            
            Transform aim = CurrentTakenObject.GetComponent<Instrument>().GetCurrentIncidentInAction();
            currentBaseTransform.LookAt(new Vector3(aim.position.x, 0, aim.position.z));
                   
            switch((InstrumentsType)CurrentTakenObject.GetComponent<Instrument>().GetTypeOfObject())
            {
                case InstrumentsType.fire_extinguisher:
                    break;

                case InstrumentsType.repair_kit:
                    makeRepairAnimation();
                    break;
            }
        }
        else if (CurrentTakenObject != null)
        {            
            if (CurrentTakenObject.GetComponent<Instrument>() != null && (InstrumentsType)CurrentTakenObject.GetComponent<Instrument>().GetTypeOfObject() == InstrumentsType.repair_kit) 
            {
                makeCarryOffAnimation();
            }
            else 
            {
                makeCarryAnimation();
            }            
        }
        else if (CurrentTakenObject == null)
        {
            makeCarryOffAnimation();
        }       
    }

    public void MoveCrewMemberTo(Vector3 destination, GameObject _objectOfDestination) 
    {
        if (crewState == CrewMemberStates.stunned)
        {
            //show negative info
            return;
        }

        if (crewState == CrewMemberStates.dead)
        {
            //show negative info
            return;
        }

        if (_objectOfDestination.GetComponent<IHighlightable>() != null && _objectOfDestination != gameObject)
        {
            
            _objectOfDestination.GetComponent<IHighlightable>().HighlightCurrentObject();
        }

        
        navAgent.isStopped = false;
        navAgent.SetDestination(destination);
        if (crewState == CrewMemberStates.sit)
        {
            makeIdleAnimation();
        }

        if (PlaceOfDestination != _objectOfDestination && !_objectOfDestination.CompareTag("Floor")) PlaceOfDestination = _objectOfDestination;
    }

    private void OnTriggerStay(Collider other)
    {
        if (PlaceOfCurrentLocation != other.gameObject) PlaceOfCurrentLocation = other.gameObject;

        

        if (PlaceOfCurrentLocation == PlaceOfDestination)
        {
            if (CurrentTakenObject == null)
            {
                if (other.gameObject.GetComponent<ITakenAndMovable>() != null && other.gameObject.GetComponent<ITakenAndMovable>().IsCanBeTakenByCrew())
                {
                    ITakenAndMovable objectToTake = other.gameObject.GetComponent<ITakenAndMovable>();
                    print(objectToTake.GetTypeOfObject() + " is taken");
                    TakeAnyObjectToCarry(objectToTake.GiveAwayTakeble());
                }
            }

            if (other.gameObject.GetComponent<SpaceControlPanel>() != null && !other.gameObject.GetComponent<SpaceControlPanel>().isChairBusy)
            {
                if (CurrentTakenObject != null) ThrowAwayCurrentTakenObject();
                makeSitAnimation();
                StartCoroutine(PlaySit(other.gameObject.GetComponent<SpaceControlPanel>().GetSitPoint(), other.gameObject.GetComponent<SpaceControlPanel>().GetLookPoint()));
                               
            }
            

            navAgent.isStopped = true;
            PlaceOfCurrentLocation = null;
            PlaceOfDestination = null;
                            
        }

        
        if (CurrentTakenObject != null)
        {
            //print(((SuppliesType)currentTakenObject.GetComponent<ITakenAndMovable>().GetSupplyTypeOfSupply() == SuppliesType.tester).ToString());



            if (other.gameObject.GetComponent<IConsumer>() != null && (SuppliesType)CurrentTakenObject.GetComponent<ITakenAndMovable>().GetTypeOfObject() == other.gameObject.GetComponent<IConsumer>().GetFacilityConsumerSupplyType())
            {
                
                if (other.gameObject.GetComponent<IConsumer>().ConsumeSupply(CurrentTakenObject))
                {
                    CurrentTakenObject = null;
                }

            }

            if (other.gameObject.GetComponent<Incident>() != null && CurrentTakenObject.GetComponent<Instrument>() != null && (InstrumentsType)CurrentTakenObject.GetComponent<Instrument>().GetTypeOfObject() == other.gameObject.GetComponent<Incident>().GetInstrumentTypeToDealWithIncident())
            {
                //print("WEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE!!!!!!");

                currentBaseTransform.LookAt(new Vector3(other.gameObject.transform.position.x, 0, other.gameObject.transform.position.z));
            }
        }


    }

 

    public void SetRespawnPoint(Vector3 _point)
    {
        pointOfRespawn = _point;
        currentBaseTransform.position = pointOfRespawn;
    }

    public GameObject GetDestinationPointGameObject()
    {
        return PlaceOfDestination;
    }

    private void TakeAnyObjectToCarry(GameObject _currentTakenObject)
    {
        CurrentTakenObject = _currentTakenObject;
        CurrentTakenObject.SetActive(true);
        CurrentTakenObject.transform.SetParent(currentBaseTransform);

        
        if (_currentTakenObject.GetComponent<Instrument>() != null)
        {
            switch((InstrumentsType)_currentTakenObject.GetComponent<Instrument>().GetTypeOfObject())
            {
                case InstrumentsType.fire_extinguisher:
                    CurrentTakenObject.GetComponent<Instrument>().GetVisualTransform().localScale = new Vector3(0.8f, 0.8f, 1f);
                    CurrentTakenObject.GetComponent<Instrument>().GetVisualTransform().localPosition = new Vector3(0.186f, 0.72f, 0.028f);

                    CurrentTakenObject.transform.localPosition = new Vector3(0, 0, 0.65f); //0.72
                    CurrentTakenObject.transform.localEulerAngles = new Vector3(0, 90, 0);
                    break;

                case InstrumentsType.repair_kit:
                    CurrentTakenObject.transform.localPosition = new Vector3(0, 0, 0.65f);
                    CurrentTakenObject.GetComponent<Instrument>().GetVisualTransform().gameObject.SetActive(false);

                    hammerExample.gameObject.SetActive(true);
                    wrenchExample.gameObject.SetActive(true);

                    //CurrentTakenObject.transform.localScale = Vector3.one / 2f;
                    //CurrentTakenObject.transform.SetParent(rightHand);
                    //CurrentTakenObject.transform.localPosition = Vector3.zero;

                    break;

            }
        }
        else if (_currentTakenObject.GetComponent<Supply>() != null)
        {            
            CurrentTakenObject.transform.localPosition = new Vector3(0, 0.72f, 0.72f);
            CurrentTakenObject.transform.localEulerAngles = new Vector3(0, 0, 0);

            switch ((SuppliesType)_currentTakenObject.GetComponent<Supply>().GetTypeOfObject() )
            {
                case SuppliesType.full_engine_fuel:
                    CurrentTakenObject.transform.localPosition = new Vector3(0.056f, 0.81f, 0.616f);
                    CurrentTakenObject.transform.localEulerAngles  = new Vector3(0, -23, 71.5f);
                    break;
            }
        }
       
        
    }

    public void HighlightCurrentObject()
    {
        if (!isHighlightEffectInProgress) StartCoroutine(HandleCurrentHighlight());
    }

    public IEnumerator HandleCurrentHighlight()
    {
        isHighlightEffectInProgress = true;
        Highlighting.ChangeMaterial(highlightMaterial, baseHighLight);
        currentModelTransform.DOShakeScale(GeneralSettings.TimeForShakeForCrew, GeneralSettings.StrenghtOfShakeOnHighlightingCrew, 10, 90, true);
        
        yield return new WaitForSeconds(GeneralSettings.TimeForShakeForCrew);
        isHighlightEffectInProgress = false;
        Highlighting.ChangeMaterial(baseMaterial, baseHighLight);
    }

    public static GameObject GetCrewPrefab(CrewSpecialization _crewSpec)
    {
        GameObject result = default;

        switch (_crewSpec)
        {
            case CrewSpecialization.tester:
                result = Resources.Load<GameObject>("prefabs/crew/DefaultPlayer1");
                break;

            case CrewSpecialization.Captain: //captain
                result = Resources.Load<GameObject>("prefabs/crew/captain01");
                break;

        }

        return result;
    }

    private void makeRunAnimation()
    {
        if (crewState == CrewMemberStates.run) return;
        crewState = CrewMemberStates.run;
        if (!animator.GetCurrentAnimatorStateInfo(0).IsName("Run")) animator.Play("Run");        
    }

    private void makeIdleAnimation()
    {
        if (crewState == CrewMemberStates.idle) return;
        crewState = CrewMemberStates.idle;
        if (!animator.GetCurrentAnimatorStateInfo(0).IsName("Idle")) animator.Play("Idle");
    }

    private void makeWalkAnimation()
    {
        if (crewState == CrewMemberStates.walk) return;
        crewState = CrewMemberStates.walk;
        if (!animator.GetCurrentAnimatorStateInfo(0).IsName("Walk") && !animator.GetCurrentAnimatorStateInfo(0).IsName("Run")) animator.Play("Walk");
    }

    private void makeSitAnimation()
    {
        if (crewState == CrewMemberStates.sit) return;
        crewState = CrewMemberStates.sit;
        if (!animator.GetCurrentAnimatorStateInfo(0).IsName("Sit"))
        {
            if (animator.GetLayerWeight(1) > 0) animator.SetLayerWeight(1, 0);
            if (!animator.GetCurrentAnimatorStateInfo(1).IsName("idle 2")) animator.Play("idle 2");
            animator.Play("Sit");
        }
            
    }

    private void makeCarryAnimation()
    {        
        if (animator.GetLayerWeight(1)<1) animator.SetLayerWeight(1, 1);
        if (!animator.GetCurrentAnimatorStateInfo(1).IsName("Carry")) animator.Play("Carry");        
    }

    private void makeCarryOffAnimation()
    {        
        if (animator.GetLayerWeight(1) > 0) animator.SetLayerWeight(1, 0);
        if (!animator.GetCurrentAnimatorStateInfo(1).IsName("idle 2")) animator.Play("idle 2");        
    }

    private void makeRepairAnimation()
    {
        if (animator.GetLayerWeight(1) < 1) animator.SetLayerWeight(1, 1);
        if (!animator.GetCurrentAnimatorStateInfo(1).IsName("Repair") && !animator.GetCurrentAnimatorStateInfo(1).IsName("Repair 1")) animator.Play("Repair");
    }

    private void DeactivateAnyHandsInstruments()
    {
        wrenchExample.gameObject.SetActive(false);
        hammerExample.gameObject.SetActive(false);
    }

    public IEnumerator ShowUIBarWhileActive()
    {
        isShowingUIBar = true;
        ShowUI();
        yield return new WaitForSeconds(2);
        
        isShowingUIBar = false;

        yield return new WaitForSeconds(0.5f);
        if (!isShowingUIBar) HideUI();
    }

   
    public bool IsDestroyable()
    {
        return isDestroyable;
    }

    public void PlayNegativeEffect(NegativeEffects _effect)
    {
        switch (_effect)
        {
            case NegativeEffects.burning:
                Effects.GetChild(0).gameObject.SetActive(true);
                break;

            case NegativeEffects.electricity:

                break;

            case NegativeEffects.slow_down:
                Speed *= 0.5f;
                break;

            case NegativeEffects.poisoned:
                Effects.GetChild(1).gameObject.SetActive(true);
                break;
        }

        
    }
    public void StopNegativeEffect(NegativeEffects _effect)
    {
        switch (_effect)
        {
            case NegativeEffects.burning:
                Effects.GetChild(0).gameObject.SetActive(false);
                break;

            case NegativeEffects.electricity:

                break;

            case NegativeEffects.slow_down:
                Speed /= 0.5f;
                break;

            case NegativeEffects.poisoned:
                Effects.GetChild(1).gameObject.SetActive(false);
                break;
        }
    }

    public float CurrentHealthAmount()
    {
        return Health;
    }

    private void ThrowAwayCurrentTakenObject()
    {
        CurrentTakenObject.GetComponent<Transform>().SetParent(GameObject.Find("SpaceShip").transform);
        CurrentTakenObject.transform.position = currentBaseTransform.position;
        CurrentTakenObject.GetComponent<ITakenAndMovable>().MakeThrownAway();
        DeactivateAnyHandsInstruments();
        CurrentTakenObject = null;
    }

    private IEnumerator PlaySit(Vector3 pos, Vector3 look)
    {
        yield return new WaitForSeconds(0.2f);
        currentBaseTransform.LookAt(look);
        currentBaseTransform.position = pos;        
    }

}
