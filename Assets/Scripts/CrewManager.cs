using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Unity.AI.Navigation;
using UnityEngine.AI;

public class CrewManager : MonoBehaviour
{
    [SerializeField] private readonly string crewName;
    [SerializeField] private readonly CrewSpecialization crewSpec;
    [SerializeField] private int health;
    [SerializeField] private float speed;

    private NavMeshAgent navAgent;
    private Transform currentTransform;

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
        currentTransform = GetComponent<Transform>();

        crewState = CrewMemberStates.idle;
    }

    

    // Update is called once per frame
    void Update()
    {
        if (crewState == CrewMemberStates.moving_to && navAgent.remainingDistance <=0.1f)
        {
            crewState = CrewMemberStates.idle;
        }

    }

    public void MoveCrewMemberTo(Vector3 destination, GameObject _objectOfDestination) 
    {
        if (crewState == CrewMemberStates.stunned)
        {
            //show negative info
            return;
        }

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
            
            if (other.gameObject.CompareTag("FacilityProducer"))
            {
                if (currentTakenObject == null)
                {
                    print("interacted with FacilityProducer");
                    GetMovableFromProducer(other.gameObject.GetComponent<FacilityProducer>().GetMovableFromProducer());
                }
                
                PlaceOfCurrentLocation = null;
                PlaceOfDestination = null;
            }

            if (other.gameObject.CompareTag("FacilityConsumer"))
            {
                if (currentTakenObject != null && currentTakenObject.GetComponent<Movable>()!=null && currentTakenObject.GetComponent<Movable>().GetMovableType() == PlaceOfCurrentLocation.GetComponent<FacilityConsumer>().GetFacilityConsumerMovableType() )
                {
                    print("interacted with FacilityConsumer");
                    GetMovableToConsumer(PlaceOfCurrentLocation.GetComponent<FacilityConsumer>());
                }                
                
                PlaceOfCurrentLocation = null;
                PlaceOfDestination = null;
            }
        }
    }

    private void GetMovableFromProducer(GameObject _currentTakenObject)
    {
        currentTakenObject = _currentTakenObject;
        currentTakenObject.SetActive(true);
        currentTakenObject.transform.SetParent(currentTransform);
        currentTakenObject.transform.localPosition = new Vector3(0, 0.72f, 0.72f);
    }

    private void GetMovableToConsumer(FacilityConsumer _consumer)
    {   
        _consumer.ConsumeMovable(currentTakenObject);
        currentTakenObject = null;        
    }




}

public enum CrewSpecialization
{
    tester = 0,
    Captain,
    Engineer,
    Soldier,
    Scientist
}

public enum CrewMemberStates
{
    idle = 0,
    moving_to,
    repairing,
    fire_extinguish,
    stunned,
    carring


}
