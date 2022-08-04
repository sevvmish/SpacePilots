using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Incident : MonoBehaviour, IPointOfInteraction
{
    [SerializeField] private InstrumentsType whatInstrumentDealThisIncident;
    [SerializeField] private Transform pointOfInterestFROM, pointOfInterestTO, currentVisualTransform;
    [SerializeField] private float health;

    public float Health
    {
        get {return health;}

        set 
        {
            if (health<=0)
            {
                health = 0;
            }
            else
            {
                health = value;
            }
        }
    }

    public static GameObject GetIncidentPrefab(IncidentsType _incident)
    {
        GameObject result = default;

        switch ((int)_incident)
        {
            case 0:
                result = Resources.Load<GameObject>("prefabs/incidents/test fire");
                break;
            case 1:
                result = Resources.Load<GameObject>("prefabs/incidents/test fire");
                break;
        }

        return result;
    }

    public void ActWithSupply()
    {
        Health--;
        print(Health);
    }

    public InstrumentsType GetInstrumentTypeToDealWithIncident()
    {
        return whatInstrumentDealThisIncident;
    }

    public Vector3 GetPointOfInteraction()
    {
        return Vector3.Lerp(pointOfInterestFROM.position, pointOfInterestTO.position, UnityEngine.Random.Range(0.1f, 1f));
    }
}
