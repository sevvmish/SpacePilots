using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[RequireComponent(typeof(SphereCollider))]
public class Instrument : MonoBehaviour, ITakenAndMovable
{
    [SerializeField] private InstrumentsType currentInstrumentType;
    [SerializeField] private float YCoordWhenThrownAway;

    private bool isCanBeTakenByCrew = false;
    

    private Dictionary<Incident, float> checkCurrentDealingWithIncident = new Dictionary<Incident, float>();

    public static GameObject GetInstrumentPrefab(InstrumentsType _instrument)
    {
        GameObject result = default;

        switch ((int)_instrument)
        {
            case 0:
                result = Resources.Load<GameObject>("prefabs/instruments/fire extinguisher");
                break;
            case 1:
                result = Resources.Load<GameObject>("prefabs/instruments/fire extinguisher");
                break;
            case 2:
                result = Resources.Load<GameObject>("prefabs/instruments/fire extinguisher");
                break;

        }

        return result;
    }

    private void ShowEffectOfWorkingInstrument()
    {

    }

    public object GetTypeOfObject()
    {
        return currentInstrumentType;
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

    public void MakeThrownAway()
    {
        isCanBeTakenByCrew = true;
        GetComponent<Transform>().localPosition = new Vector3(GetComponent<Transform>().localPosition.x, YCoordWhenThrownAway, GetComponent<Transform>().localPosition.z);
    }


    private void OnTriggerStay(Collider other)
    {
        if (other.gameObject.CompareTag("Incident"))
        {
            Incident currentIncident = other.gameObject.GetComponent<Incident>();

            if (checkCurrentDealingWithIncident.ContainsKey(currentIncident))
            {
                checkCurrentDealingWithIncident[currentIncident] += Time.deltaTime;
            }

            if (currentIncident.GetInstrumentTypeToDealWithIncident() == currentInstrumentType && currentIncident.Health > 0 && checkCurrentDealingWithIncident[currentIncident] > 0.6f)
            {
                ShowEffectOfWorkingInstrument();
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
