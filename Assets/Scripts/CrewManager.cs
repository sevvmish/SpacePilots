using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Unity.AI.Navigation;
using UnityEngine.AI;
using DG.Tweening;
using UnityEngine.UI;

[RequireComponent(typeof(CapsuleCollider))]
[RequireComponent(typeof(NavMeshAgent))]
[RequireComponent(typeof(Rigidbody))]
[RequireComponent(typeof(Animator))]
public class CrewManager : MonoBehaviour, IHighlightable
{
    [SerializeField] private string crewName;
    [SerializeField] private CrewSpecialization crewSpec;
    [SerializeField] private CrewMemberStates crewState;
    [SerializeField] private int health;
    [SerializeField] private float speed;
    [SerializeField] private Transform currentBaseTransform, currentModelTransform, UIPositionPoint;
    [SerializeField] private settings GeneralSettings;
    
    private Animator animator;
    private Vector3 pointOfRespawn, currentPos, previousPos, OnScreenPosition;
    private float currentSpeed;
    private NavMeshAgent navAgent;
    private Rigidbody rigidBody;
    private bool isHighlightEffectInProgress, isCarringSomething;

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
            if (value != null)
            {
                makeCarry();
            }
            else
            {
                makeCarryOff();
            }

            currentTakenObject = value;
        }
    }


    // Start is called before the first frame update
    void OnEnable()
    {
        navAgent = GetComponent<NavMeshAgent>();
        navAgent.speed = speed;
        currentBaseTransform = transform;
        crewState = CrewMemberStates.idle;
        animator = GetComponent<Animator>();
        animator.SetLayerWeight(1, 0);
        rigidBody = GetComponent<Rigidbody>();

        uiHealthBar = Instantiate(UIManager.GetUIPrefab(UIPanelTypes.health_bar), GameObject.Find("MainCanvas").transform);
        uiHealthBarRect = uiHealthBar.GetComponent<RectTransform>();
        GameManagement.MainUIHandler += ShowUIHealthBar;


    }

    private void ShowUIHealthBar(Camera camera)
    {
        OnScreenPosition = camera.WorldToScreenPoint(UIPositionPoint.position);
        uiHealthBarRect.anchoredPosition = new Vector2(OnScreenPosition.x, OnScreenPosition.y + 20);
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
    }

    public void SetRespawnPoint(Vector3 _point)
    {
        pointOfRespawn = _point;
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
    }

    private void makeCarryOff()
    {        
        if (animator.GetLayerWeight(1) > 0) animator.SetLayerWeight(1, 0);
    }
}
