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
public class CrewManager : MonoBehaviour, IHighlightable, IUIBars
{
    [SerializeField] private string crewName;
    [SerializeField] private CrewSpecialization crewSpec;
    [SerializeField] private CrewMemberStates crewState;
    [SerializeField] private float maxHealth;
    [SerializeField] private float speed;
    [SerializeField] private Transform currentBaseTransform, currentModelTransform, UIPositionPoint, Effects;
    [SerializeField] private settings GeneralSettings;
    

    private Animator animator;
    private Vector3 pointOfRespawn, currentPos, previousPos, OnScreenPosition;
    private float currentSpeed;
    private NavMeshAgent navAgent;
    public Rigidbody rigidBody;
    private bool isHighlightEffectInProgress;
    private float health;
    private bool isShowingUIBar;

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
            /*
            if (value != null && (crewState == CrewMemberStates.walk || crewState == CrewMemberStates.run))
            {
                makeCarry();
            }
            else if(value == null)
            {
                makeCarryOff();
            }
            */

            currentTakenObject = value;
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


    // Start is called before the first frame update
    void OnEnable()
    {
        health = maxHealth;
        currentBaseTransform.position = pointOfRespawn;

        PlaceOfDestination = null;
        PlaceOfCurrentLocation = null;
        currentTakenObject = null;

        damagingObjects.Clear();
        activatedEffects.Clear();

        

        navAgent = GetComponent<NavMeshAgent>();
        navAgent.speed = speed;
        currentBaseTransform = transform;
        crewState = CrewMemberStates.idle;
        animator = GetComponent<Animator>();
        animator.SetLayerWeight(1, 0);
        rigidBody = GetComponent<Rigidbody>();
                
        if (uiHealthBarRect != null) HideUI();
        makeIdle();
        navAgent.isStopped = true;
    }

    public void InitUI()
    {
        uiHealthBar = Instantiate(UIManager.GetUIPrefab(UIPanelTypes.health_bar), GameObject.Find("MainCanvas").transform);
        uiHealthBarRect = uiHealthBar.GetComponent<RectTransform>();
        GameManagement.MainUIHandler += UpdateUIPosition;
        HideUI();
    }

    public void UpdateUIPosition(Camera camera)
    {
        if (uiHealthBarRect.gameObject.activeSelf)
        {
            OnScreenPosition = camera.WorldToScreenPoint(UIPositionPoint.position);
            uiHealthBarRect.anchoredPosition = new Vector2(OnScreenPosition.x, OnScreenPosition.y + 20);
        }        
    }

    public void ShowUI()
    {
        if (!uiHealthBarRect.gameObject.activeSelf) uiHealthBarRect.gameObject.SetActive(true);
    }

    public void HideUI()
    {
        if (uiHealthBarRect.gameObject.activeSelf) uiHealthBarRect.gameObject.SetActive(false);
    }

    public void UpdateUIData()
    {
        uiHealthBarRect.transform.GetChild(1).GetComponent<Image>().fillAmount = Health / maxHealth;
    }


    public void DecreaseHealthAmount(float amount)
    {
        Health -= amount;
        //print(Health + " - crew");
        UpdateUIData();
    }


    // Update is called once per frame
    void Update()
    {        

        //print(crewState);
        currentPos = currentBaseTransform.position;
        currentSpeed = Vector3.Distance(currentPos, previousPos);
        

        if (currentSpeed <= 0.01f) 
        {
            makeIdle();
        }
        else if (currentSpeed > 0.01f && currentSpeed <= 0.03f)
        {
            makeWalk();
        }
        else if (currentSpeed > 0.03f)
        {
            makeRun();
        }

        if (Input.GetKeyDown(KeyCode.A))
        {
            if (CurrentTakenObject.GetComponent<ITakenAndMovable>()!=null)
            {
                CurrentTakenObject.GetComponent<Transform>().SetParent(GameObject.Find("SpaceShip").transform);
                CurrentTakenObject.GetComponent<ITakenAndMovable>().MakeThrownAway();
                CurrentTakenObject = null;
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
                    makeRepair();
                    break;
            }
        }
        else if (CurrentTakenObject != null)
        {
            makeCarry();
        }
        else if (CurrentTakenObject == null)
        {
            makeCarryOff();
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
        if (PlaceOfDestination != _objectOfDestination) PlaceOfDestination = _objectOfDestination;
    }

    private void OnTriggerStay(Collider other)
    {
        if (PlaceOfCurrentLocation != other.gameObject) PlaceOfCurrentLocation = other.gameObject;

        if (PlaceOfCurrentLocation == PlaceOfDestination)
        {
            print("reached destination");

            if (CurrentTakenObject == null)
            {                
                if (other.gameObject.GetComponent<ITakenAndMovable>() != null && other.gameObject.GetComponent<ITakenAndMovable>().IsCanBeTakenByCrew())
                {
                    ITakenAndMovable objectToTake = other.gameObject.GetComponent<ITakenAndMovable>();
                    print(objectToTake.GetTypeOfObject() + " is taken");
                    TakeAnyObjectToCarry(objectToTake.GiveAwayTakeble());
                }
            }
            else if (CurrentTakenObject != null)
            {
                //print(((SuppliesType)currentTakenObject.GetComponent<ITakenAndMovable>().GetSupplyTypeOfSupply() == SuppliesType.tester).ToString());

                if (other.gameObject.GetComponent<FacilityConsumer>() != null && (SuppliesType)CurrentTakenObject.GetComponent<ITakenAndMovable>().GetTypeOfObject() == other.gameObject.GetComponent<FacilityConsumer>().GetFacilityConsumerSupplyType())
                {
                    print("interacted with FacilityConsumer");                    
                    other.gameObject.GetComponent<FacilityConsumer>().ConsumeMovable(CurrentTakenObject);
                    CurrentTakenObject = null;
                }

                if (other.gameObject.GetComponent<Incident>() != null && (InstrumentsType)CurrentTakenObject.GetComponent<Instrument>().GetTypeOfObject() == other.gameObject.GetComponent<Incident>().GetInstrumentTypeToDealWithIncident())
                {
                    print("WEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE!!!!!!");

                    currentBaseTransform.LookAt(new Vector3(other.gameObject.transform.position.x, 0, other.gameObject.transform.position.z));
                }
            }

            navAgent.isStopped = true;
            PlaceOfCurrentLocation = null;
            PlaceOfDestination = null;
                            
        }

        //damage receiver
        if (damagingObjects.ContainsKey(other.gameObject))
        {            
            switch(damagingObjects[other.gameObject].GetNegativeEffect())
            {
                case NegativeEffects.burning:
                    //print(Vector3.Distance(other.gameObject.transform.position, currentBaseTransform.position));

                    if (!activatedEffects.Contains(NegativeEffects.burning) && Vector3.Distance(other.gameObject.transform.position, currentBaseTransform.position) <=0.6f)
                    {
                        activatedEffects.Add(NegativeEffects.burning);
                        SetEffectBurning(damagingObjects[other.gameObject].GetDamageAmount());
                    }
                    break;

                case NegativeEffects.electricity:

                    break;
            }
        }

    }


    private void OnTriggerEnter(Collider other)
    {
        if (!damagingObjects.ContainsKey(other.gameObject) && other.gameObject.GetComponent<DamageDealer>() != null)
        {
            damagingObjects.Add(other.gameObject, other.gameObject.GetComponent<DamageDealer>());
        }
    }


    private void OnTriggerExit(Collider other)
    {
        if (damagingObjects.ContainsKey(other.gameObject))
        {
            damagingObjects.Remove(other.gameObject);
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
                    CurrentTakenObject.transform.localPosition = new Vector3(0, 0.72f, 0.65f);
                    CurrentTakenObject.transform.localEulerAngles = new Vector3(0, 90, 0);
                    break;

                case InstrumentsType.repair_kit:
                    CurrentTakenObject.transform.localPosition = new Vector3(0, 0.64f, 0.52f);
                    CurrentTakenObject.transform.localEulerAngles = new Vector3(-60, -44, 63);
                    break;

            }
        }
        else
        {
            CurrentTakenObject.transform.localPosition = new Vector3(0, 0.72f, 0.72f);
        }
       
        
    }

    public void HighlightCurrentObject()
    {
        if (!isHighlightEffectInProgress) StartCoroutine(HandleCurrentHighlight());
    }

    public IEnumerator HandleCurrentHighlight()
    {
        isHighlightEffectInProgress = true;
        currentModelTransform.DOShakeScale(GeneralSettings.TimeForShakeForCrew, GeneralSettings.StrenghtOfShakeOnHighlightingCrew, 10, 90, true);
        
        yield return new WaitForSeconds(GeneralSettings.TimeForShakeForCrew);
        isHighlightEffectInProgress = false;
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

    private void makeRun()
    {
        if (crewState == CrewMemberStates.run) return;
        crewState = CrewMemberStates.run;
        if (!animator.GetCurrentAnimatorStateInfo(0).IsName("Run")) animator.Play("Run");        
    }

    private void makeIdle()
    {
        if (crewState == CrewMemberStates.idle) return;
        crewState = CrewMemberStates.idle;
        if (!animator.GetCurrentAnimatorStateInfo(0).IsName("Idle")) animator.Play("Idle");
    }

    private void makeWalk()
    {
        if (crewState == CrewMemberStates.walk) return;
        crewState = CrewMemberStates.walk;
        if (!animator.GetCurrentAnimatorStateInfo(0).IsName("Walk")) animator.Play("Walk");
    }

    private void makeCarry()
    {        
        if (animator.GetLayerWeight(1)<1) animator.SetLayerWeight(1, 1);
        if (!animator.GetCurrentAnimatorStateInfo(1).IsName("Carry")) animator.Play("Carry");        
    }

    private void makeCarryOff()
    {        
        if (animator.GetLayerWeight(1) > 0) animator.SetLayerWeight(1, 0);
        if (!animator.GetCurrentAnimatorStateInfo(1).IsName("idle 2")) animator.Play("isle 2");        
    }

    private void makeRepair()
    {
        if (animator.GetLayerWeight(1) < 1) animator.SetLayerWeight(1, 1);
        if (!animator.GetCurrentAnimatorStateInfo(1).IsName("Repair") && !animator.GetCurrentAnimatorStateInfo(1).IsName("Repair 1")) animator.Play("Repair");
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

    

    private void SetEffectBurning(float amount) => StartCoroutine(BurningEff(amount));

    private IEnumerator BurningEff(float amount)
    {
        float damageTime = 2f;
        Effects.GetChild(0).gameObject.SetActive(true);

        for (float i = 0; i < damageTime; i+=0.1f)
        {
            DecreaseHealthAmount(amount / damageTime / 10f);

            yield return new WaitForSeconds(0.1f);
        }
                
        if (activatedEffects.Contains(NegativeEffects.burning)) activatedEffects.Remove(NegativeEffects.burning);
        Effects.GetChild(0).gameObject.SetActive(false);

        yield return new WaitForSeconds(0.2f);
        if (!activatedEffects.Contains(NegativeEffects.burning)) Effects.GetChild(0).gameObject.SetActive(false);
    }
}
