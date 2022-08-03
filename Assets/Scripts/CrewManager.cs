using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Unity.AI.Navigation;
using UnityEngine.AI;
using DG.Tweening;

public class CrewManager : MonoBehaviour, IHighlightable
{
    [SerializeField] private readonly string crewName;
    [SerializeField] private readonly CrewSpecialization crewSpec;
    [SerializeField] private int health;
    [SerializeField] private float speed;
    [SerializeField] private Transform currentBaseTransform, currentModelTransform;
    [SerializeField] private settings GeneralSettings;

    private NavMeshAgent navAgent;    
    private bool isHighlightEffectInProgress;

    //moving to points
    private GameObject PlaceOfDestination;
    private GameObject PlaceOfCurrentLocation;

    //interaction
    private GameObject currentTakenObject;

    [SerializeField] private CrewMemberStates crewState;
    


    // Start is called before the first frame update
    void OnEnable()
    {
        navAgent = GetComponent<NavMeshAgent>();
        navAgent.speed = speed;
        currentBaseTransform = transform;
        crewState = CrewMemberStates.idle;
    }

    

    // Update is called once per frame
    void Update()
    {
        if (crewState == CrewMemberStates.moving_to && navAgent.remainingDistance <=0.1f)
        {
            crewState = CrewMemberStates.idle;
        }

        if (Input.GetKeyDown(KeyCode.A))
        {
            if (currentTakenObject.GetComponent<Supply>()!=null)
            {
                currentTakenObject.GetComponent<Transform>().SetParent(GameObject.Find("SpaceShip").transform);
                currentTakenObject.GetComponent<Supply>().SetStateIsThrownAway();                
                currentTakenObject = null;
            }
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
        crewState = CrewMemberStates.moving_to;
        navAgent.SetDestination(destination);
        if (PlaceOfDestination != _objectOfDestination) PlaceOfDestination = _objectOfDestination;
    }

    private void OnTriggerStay(Collider other)
    {
        if (PlaceOfCurrentLocation != other.gameObject) PlaceOfCurrentLocation = other.gameObject;

        if (PlaceOfCurrentLocation == PlaceOfDestination)
        {
            print("reached destination");

            if (currentTakenObject == null)
            {                
                if (other.gameObject.GetComponent<ITakenAndMovable>() != null)
                {
                    ITakenAndMovable objectToTake = other.gameObject.GetComponent<ITakenAndMovable>();
                    print(objectToTake.GetSupplyTypeOfSupply() + " is taken");
                    TakeAnyObjectToCarry(objectToTake.GiveAwayTakeble());
                }
            }
            else if (currentTakenObject != null)
            {
                //print(((SuppliesType)currentTakenObject.GetComponent<ITakenAndMovable>().GetSupplyTypeOfSupply() == SuppliesType.tester).ToString());

                if (other.gameObject.CompareTag("FacilityConsumer") && (SuppliesType)currentTakenObject.GetComponent<ITakenAndMovable>().GetSupplyTypeOfSupply() == other.gameObject.GetComponent<FacilityConsumer>().GetFacilityConsumerSupplyType())
                {
                    print("interacted with FacilityConsumer");                    
                    other.gameObject.GetComponent<FacilityConsumer>().ConsumeMovable(currentTakenObject);
                    currentTakenObject = null;
                }

                if (other.gameObject.CompareTag("Incident") && (SuppliesType)currentTakenObject.GetComponent<Supply>().GetSupplyTypeOfSupply() == other.gameObject.GetComponent<Incident>().GetSupplyTypeToDealWithIncident())
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

    public GameObject GetDestinationPointGameObject()
    {
        return PlaceOfDestination;
    }

    private void TakeAnyObjectToCarry(GameObject _currentTakenObject)
    {
        currentTakenObject = _currentTakenObject;
        currentTakenObject.SetActive(true);
        currentTakenObject.transform.SetParent(currentBaseTransform);
        currentTakenObject.transform.localPosition = new Vector3(0, 0.72f, 0.72f);
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
}
