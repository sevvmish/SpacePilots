using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System;
using Unity.AI.Navigation;
using UnityEngine.AI;
using DG.Tweening;
using UnityEngine.UI;
using EZCameraShake;

[RequireComponent(typeof(CapsuleCollider))]
[RequireComponent(typeof(NavMeshAgent))]
[RequireComponent(typeof(Rigidbody))]
[RequireComponent(typeof(Animator))]
public class CrewManager : MonoBehaviour, IHighlightable, IHealthDestroyable
{
    public bool isDead;

    [SerializeField] private string crewName;
    [SerializeField] private CrewSpecialization crewSpec;
    [SerializeField] private CrewMemberStates crewState;    
    [SerializeField] private Transform currentBaseTransform, currentModelTransform, UIPositionPoint, Effects, baseHighLight, leftHand, rightHand;
    [SerializeField] private settings GeneralSettings;
    [SerializeField] private Material highlightMaterial;
    [SerializeField] private Transform wrenchExample, hammerExample;
    [SerializeField] private AudioSource audio;
    [SerializeField] private bool isDestroyable = true;

    private float maxHealth;
    private float maxSpeed;

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

    private UIManager whaaatMark, respawnMark;


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
                if (!isDead) StartCoroutine(crewMemberKilled());
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
        isDead = false;
        
        if (audio == null) audio = GetComponent<AudioSource>();
        audio.volume = GeneralSettings.AudioSourceVolume_crew;
        if (baseMaterial == null) baseMaterial = Highlighting.GetBaseMaterial(baseHighLight);

        maxHealth = GeneralSettings.CrewBaseHealth * GeneralSettings.CrewHealthKoeff;
        health = maxHealth;
        currentBaseTransform.position = pointOfRespawn;
        currentModelTransform.gameObject.SetActive(true);
        PlaceOfDestination = null;
        PlaceOfCurrentLocation = null;
        currentTakenObject = null;

        damagingObjects.Clear();
        activatedEffects.Clear();
                

        navAgent = GetComponent<NavMeshAgent>();
        maxSpeed = GeneralSettings.CrewBaseSpeed * GeneralSettings.CrewSpeedKoeff;
        Speed = maxSpeed;
        navAgent.speed = maxSpeed;
        currentBaseTransform = transform;
        crewState = CrewMemberStates.idle;
        animator = GetComponent<Animator>();
        animator.SetLayerWeight(1, 0);
        rigidBody = GetComponent<Rigidbody>();
                
        if (uiHealthBarRect != null) HideUI();
        makeIdleAnimation();
        DeactivateAnyHandsInstruments();

        whaaatMark = new UIManager(UIPositionPoint, UIPanelTypes.information_mark, UIIconTypes.whaaat, new Color(0,0,0,0), Color.white);
        whaaatMark.ChangeScale(1.2f);
        
        respawnMark = new UIManager(UIPositionPoint, UIPanelTypes.respawn_bar);
        respawnMark.HideUI();
    }

    private void restart()
    {
        isDead = false;
        
        maxHealth = GeneralSettings.CrewBaseHealth * GeneralSettings.CrewHealthKoeff;
        health = maxHealth;
        currentBaseTransform.position = pointOfRespawn;
        currentModelTransform.gameObject.SetActive(true);
        PlaceOfDestination = null;
        PlaceOfCurrentLocation = null;
        currentTakenObject = null;

        damagingObjects.Clear();
        activatedEffects.Clear();
                        
        maxSpeed = GeneralSettings.CrewBaseSpeed * GeneralSettings.CrewSpeedKoeff;
        Speed = maxSpeed;
        navAgent.speed = maxSpeed;
        
        crewState = CrewMemberStates.idle;
        
        animator.SetLayerWeight(1, 0);
                
        makeIdleAnimation();
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
            
        }
    }

    public void ShowUI()
    {
        if (!uiHealthBarRect.gameObject.activeSelf)
        {
            uiHealthBarRect.gameObject.SetActive(true);
            GameManagement.MainUIHandler += UpdateUIPosition;
        }
            
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
        if (!isDead)
        {
            if (Health < maxHealth)
            {
                Health += Time.deltaTime * GeneralSettings.CrewHealthRegenPerSecond;
            }
        }

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


        if (Input.GetKeyDown(KeyCode.H))
        {         
            whaaatMark.MakeShake(0.7f);
        }


        previousPos = currentPos;
        
        //=================
        if (CurrentTakenObject !=null && CurrentTakenObject.GetComponent<Instrument>() != null && CurrentTakenObject.GetComponent<Instrument>().GetCurrentIncidentInAction() != null)
        {
            
            Transform aim = CurrentTakenObject.GetComponent<Instrument>().GetCurrentIncidentInAction();
            //currentBaseTransform.LookAt(new Vector3(aim.position.x, 0, aim.position.z));
                   
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

        //print("nav: " + navAgent.destination);
                    
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
               
        if (PlaceOfDestination!=null && PlaceOfCurrentLocation == PlaceOfDestination)
        {
            if (CurrentTakenObject == null && (other.GetComponent<Incident>()!=null || other.GetComponent<FacilityConsumer>() != null))
            {
                StartCoroutine(PlayMarkOfWrongInteraction());
            }

            if (other.TryGetComponent(out ITakenAndMovable canBeTaken) && canBeTaken.IsCanBeTakenByCrew())
            {
                
                if (currentTakenObject != null && currentTakenObject.TryGetComponent(out ITakenAndMovable allreadyTaken) 
                    && (canBeTaken.GetTypeOfObject().GetType() != allreadyTaken.GetTypeOfObject().GetType() ||
                     ((canBeTaken.GetTypeOfObject().GetType() == typeof(SuppliesType) && (SuppliesType)canBeTaken.GetTypeOfObject() != (SuppliesType)allreadyTaken.GetTypeOfObject()) || (canBeTaken.GetTypeOfObject().GetType() == typeof(InstrumentsType) && (InstrumentsType)canBeTaken.GetTypeOfObject() != (InstrumentsType)allreadyTaken.GetTypeOfObject())))
                                        
                    )
                {
                    ThrowAwayCurrentTakenObject();
                    TakeAnyObjectToCarry(canBeTaken.GiveAwayTakeble());
                }
                else if(currentTakenObject == null)
                {
                    TakeAnyObjectToCarry(canBeTaken.GiveAwayTakeble());
                }
                else
                {
                    StartCoroutine(PlayMarkOfWrongInteraction());
                }

            } 
            

            if (CurrentTakenObject != null)
            {
               
                if (CurrentTakenObject.TryGetComponent(out Instrument instr) && other.TryGetComponent(out Incident incident))
                {
                    if (instr.GetCurrentTypeOfInstrument() == incident.GetInstrumentTypeToDealWithIncident())
                    {
                        currentBaseTransform.LookAt(new Vector3(other.gameObject.transform.position.x, 0, other.gameObject.transform.position.z));
                    }
                    else
                    {
                        StartCoroutine(PlayMarkOfWrongInteraction());
                    }
                }
                


                if (other.gameObject.GetComponent<FacilityProducer>() != null 
                    || (other.gameObject.GetComponent<Reactor>() != null && (currentTakenObject.GetComponent<Supply>() == null || (SuppliesType)currentTakenObject.GetComponent<Supply>().GetTypeOfObject() != SuppliesType.full_engine_fuel)) 
                    || other.gameObject.GetComponent<Instrument>() != null)
                {
                    //StartCoroutine(PlayMarkOfWrongInteraction());
                } 
                else if (other.gameObject.GetComponent<IConsumer>() != null && (SuppliesType)CurrentTakenObject.GetComponent<ITakenAndMovable>().GetTypeOfObject() != other.gameObject.GetComponent<IConsumer>().GetFacilityConsumerSupplyType())
                {
                    //StartCoroutine(PlayMarkOfWrongInteraction());
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
            if (other.TryGetComponent(out IConsumer consumer) /*other.gameObject.GetComponent<IConsumer>() != null*/ && (SuppliesType)CurrentTakenObject.GetComponent<ITakenAndMovable>().GetTypeOfObject() == consumer.GetFacilityConsumerSupplyType())
            {
                
                if (other.gameObject.GetComponent<IConsumer>().ConsumeSupply(CurrentTakenObject))
                {
                    CurrentTakenObject = null;
                }                
            }
            
            if (other.TryGetComponent(out Instrument instr) && other.TryGetComponent(out Incident incident) &&  instr.GetCurrentTypeOfInstrument() == incident.GetInstrumentTypeToDealWithIncident())
            {                
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

                case SuppliesType.empty_engine_fuel:
                    CurrentTakenObject.transform.localPosition = new Vector3(0, 0.72f, 0.6f);
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
        //currentModelTransform.DOShakeScale(GeneralSettings.TimeForShakeForCrew, GeneralSettings.StrenghtOfShakeOnHighlightingCrew, 10, 90, true);
        currentModelTransform.DOPunchScale(GeneralSettings.StrenghtOfShakeOnHighlightingCrew, GeneralSettings.TimeForShakeForCrew);

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

    public void SetNegativeEffect(NegativeEffects _effect, float _time)
    {   
        switch (_effect)
        {
            case NegativeEffects.burning:
                StartCoroutine(PlayNegativeEffect(Effects.GetChild(0).gameObject, _time));                
                break;

            case NegativeEffects.electricity:

                break;

            case NegativeEffects.slow_down:
                Speed *= 0.5f;
                break;

            case NegativeEffects.poisoned:
                StartCoroutine(PlayNegativeEffect(Effects.GetChild(1).gameObject, _time));
                break;
        }
    }


    public IEnumerator PlayNegativeEffect(GameObject _effect, float _time)
    {
        _effect.SetActive(true);

        for (int i = 0; i < 10; i++)
        {
            if (!_effect.activeSelf) _effect.SetActive(true);
            yield return new WaitForSeconds(_time / 10f);
        }

        _effect.SetActive(false);
    }

    
    public float CurrentHealthAmount()
    {
        return Health;
    }

    private void ThrowAwayCurrentTakenObject()
    {
        if (CurrentTakenObject == null) return;

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

    private IEnumerator PlayMarkOfWrongInteraction()
    {
        if (whaaatMark.isShown()) yield break;
        whaaatMark.ShowUI();
        whaaatMark.MakeShake(0.7f);
        yield return new WaitForSeconds(1f);
        whaaatMark.HideUI();
    }

    private IEnumerator crewMemberKilled()
    {
        //Effects.GetChild(2).gameObject.SetActive(true);
        GameObject deathEffect = ObjectPooling.death_pool.GetObject();
        deathEffect.transform.position = new Vector3(currentBaseTransform.position.x, 0.5f, currentBaseTransform.position.z);
        deathEffect.transform.SetParent(GameObject.Find("SpaceShip").transform);
        deathEffect.SetActive(true);

        Effects.GetChild(3).gameObject.SetActive(false);

        isDead = true;
        GameManagement.crewMemberDead.Add(this);
        ThrowAwayCurrentTakenObject();
        navAgent.isStopped = true;
        PlaceOfCurrentLocation = null;
        PlaceOfDestination = null;
        

        //death effect

        whaaatMark.HideUI();
        HideUI();
        
        currentBaseTransform.position = new Vector3(pointOfRespawn.x, 0, pointOfRespawn.z);
        
        currentBaseTransform.GetChild(0).gameObject.SetActive(false);
        navAgent.enabled = false;
        GetComponent<CapsuleCollider>().enabled = false;

        respawnMark.ChangePosition(pointOfRespawn);
        respawnMark.ShowUI();

        for (float i = GeneralSettings.CrewRespawnTime+10; i > 0; i--)
        {
            respawnMark.ShowTimeOnRespawnTimer((int)i);
            yield return new WaitForSeconds(1f);
        }

        //Effects.GetChild(2).gameObject.SetActive(false);
        ObjectPooling.death_pool.ReturnObject(deathEffect);

        Effects.GetChild(3).gameObject.SetActive(true);

        yield return new WaitForSeconds(1f);
        CameraShaker.Instance.ShakeOnce(3, 5, 0.2f, 1);
        currentBaseTransform.GetChild(0).gameObject.SetActive(true);
        navAgent.enabled = true;
        GetComponent<CapsuleCollider>().enabled = true;
        
        respawnMark.HideUI();
        restart();
    }

}
