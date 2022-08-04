using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.AI;

public class Supply : MonoBehaviour, ITakenAndMovable
{
    [SerializeField] private SuppliesType currentSupplyType;    
    [SerializeField] private float YCoordWhenThrownAway;
    private bool isCanBeTakenByCrew = false;


    public void MakeThrownAway()
    {
        isCanBeTakenByCrew = true;
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
            
        }

        return result;
    }

    public object GetTypeOfObject()
    {
        return currentSupplyType;
    }

    public bool IsCanBeTakenByCrew()
    {
        return isCanBeTakenByCrew;
    }

    public GameObject GiveAwayTakeble()
    {
        if (isCanBeTakenByCrew)
        {
            isCanBeTakenByCrew = false;
            return gameObject;
        }
        else
        {
            return null;
        }
    }



}

