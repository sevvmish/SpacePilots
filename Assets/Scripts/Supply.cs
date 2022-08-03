using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.AI;

public class Supply : MonoBehaviour, ITakenAndMovable
{
    [SerializeField] private SuppliesType currentSupplyType;
    [SerializeField] private SupplyState currentMovableState;    
    [SerializeField] private SphereCollider currentCollider;
    [SerializeField] private float YCoordWhenThrownAway;

    private void OnEnable()
    {
        currentMovableState = SupplyState.inProducer;

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
        currentCollider.enabled = false;
    }

    public void SetStateInCrewHands()
    {
        currentMovableState = SupplyState.inCrewHands;
        currentCollider.enabled = false;
    }

    public void SetStateIsThrownAway()
    {
        currentMovableState = SupplyState.isThrownAway;
        currentCollider.enabled = true;
        GetComponent<Transform>().localPosition = new Vector3(GetComponent<Transform>().localPosition.x, YCoordWhenThrownAway, GetComponent<Transform>().localPosition.z);
    }


    public static GameObject GetSupplyPrefab(SuppliesType _movable)
    {
        GameObject result = default;

        switch((int)_movable)
        {
            case 0:
                result = Resources.Load<GameObject>("prefabs/supplies/test movable");
                break;
            case 3:
                result = Resources.Load<GameObject>("prefabs/supplies/fire extinguisher");
                break;
        }

        return result;
    }

    public object GetTypeOfTakeble()
    {
        return currentSupplyType;
    }

    public GameObject GiveAwayTakeble()
    {
        return gameObject;
    }
}

