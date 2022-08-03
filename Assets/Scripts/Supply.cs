using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.AI;

public class Supply : MonoBehaviour, ITakenAndMovable
{
    [SerializeField] private SuppliesType currentSupplyType;    
    [SerializeField] private float YCoordWhenThrownAway;

    private Dictionary<Incident, float> checkCurrentDealingWithIncident = new Dictionary<Incident, float>();

 

    public void SetStateIsThrownAway()
    {
        //currentMovableState = SupplyState.isThrownAway;
        //currentCollider.enabled = true;
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

    public object GetSupplyTypeOfSupply()
    {
        return currentSupplyType;
    }

    public GameObject GiveAwayTakeble()
    {
        return gameObject;
    }

    private void OnTriggerStay(Collider other)
    {
        if (other.gameObject.CompareTag("Incident"))
        {
            Incident currentIncident = other.gameObject.GetComponent<Incident>();

            if (checkCurrentDealingWithIncident.ContainsKey(currentIncident))
            {
                checkCurrentDealingWithIncident[currentIncident]+=Time.deltaTime;                
            }

            if (currentIncident.GetSupplyTypeToDealWithIncident() == currentSupplyType && currentIncident.Health>0 && checkCurrentDealingWithIncident[currentIncident]>1)
            {                
                currentIncident.ActWithSupply();
            }            
        }
    }

    private void OnTriggerEnter(Collider other)
    {
        if (other.gameObject.CompareTag("Incident"))
        {
            Incident currentIncident = other.gameObject.GetComponent<Incident>();
                        
            if (!checkCurrentDealingWithIncident.ContainsKey(currentIncident))
            {
                checkCurrentDealingWithIncident.Add(currentIncident, 0);
            }
        }       
    }

    private void OnTriggerExit(Collider other)
    {
        if (other.gameObject.CompareTag("Incident"))
        {
            Incident currentIncident = other.gameObject.GetComponent<Incident>();
            if (checkCurrentDealingWithIncident.ContainsKey(currentIncident))
            {
                checkCurrentDealingWithIncident.Remove(currentIncident);
            }
        }
    }



}

