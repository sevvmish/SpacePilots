using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.AI;

public class Supply : MonoBehaviour
{
    [SerializeField] private Supplies currentMovableType;
    [SerializeField] private SupplyState currentMovableState;
    //[SerializeField] private NavMeshAgent currentNavMeshAgent;
    [SerializeField] private SphereCollider currentCollider;
    [SerializeField] private float YCoordWhenThrownAway;

    private void OnEnable()
    {
        currentMovableState = SupplyState.inProducer;

        //currentNavMeshAgent = GetComponent<NavMeshAgent>();
        //currentNavMeshAgent.enabled = false;

        currentCollider = GetComponent<SphereCollider>();
        currentCollider.enabled = false;
    }

    public SupplyState GetCurrentState()
    {
        return currentMovableState;
    }

    public void SetStateInConsumer()
    {
        currentMovableState = SupplyState.inConsumer;
        //currentNavMeshAgent.enabled = false;
        currentCollider.enabled = false;
    }

    public void SetStateInCrewHands()
    {
        currentMovableState = SupplyState.inCrewHands;
        //currentNavMeshAgent.enabled = false;
        currentCollider.enabled = false;
    }

    public void SetStateIsThrownAway()
    {
        currentMovableState = SupplyState.isThrownAway;
        //currentNavMeshAgent.enabled = true;
        currentCollider.enabled = true;
        GetComponent<Transform>().localPosition = new Vector3(GetComponent<Transform>().localPosition.x, YCoordWhenThrownAway, GetComponent<Transform>().localPosition.z);
    }


    public static GameObject GetMovablePrefab(Supplies _movable)
    {
        GameObject result = default;

        switch((int)_movable)
        {
            case 0:
                result = Resources.Load<GameObject>("prefabs/supplies/test movable");
                break;
        }

        return result;
    }

    public Supplies GetMovableType()
    {
        return currentMovableType;
    }
}

public enum Supplies
{
    tester = 0,
    engine_fuel,
    repairer,
    fire_extinguisher

}

public enum SupplyState
{
    inProducer = 0,
    inConsumer,
    inCrewHands,
    isThrownAway
}
