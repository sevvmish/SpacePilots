using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ObjectPooling : MonoBehaviour
{
    private GameObject example;
    private Transform storage;

    private Queue<GameObject> poolOfObjects;
    
    //PUBLIC STATIC
    //incidents
    public static ObjectPooling fireIncident_pool, simpleWreckIncident_pool, smokeAfterFire_pool, repairAfterWreck;
    //instruments
    public static ObjectPooling fireExtInstrument_pool, simpleRepairerInstrument_pool;

    public static void InitPools(int size, Transform transform)
    {
        //objectpooling 
        //incidents
        fireIncident_pool = new ObjectPooling(size, Incident.GetIncidentPrefab(IncidentsType.fire), transform);
        simpleWreckIncident_pool = new ObjectPooling(size, Incident.GetIncidentPrefab(IncidentsType.simple_wreck), transform);
        smokeAfterFire_pool = new ObjectPooling(size, Incident.GetIncidentPrefab(IncidentsType.smoke_after_fire), transform);
        repairAfterWreck = new ObjectPooling(size, Incident.GetIncidentPrefab(IncidentsType.after_wreck), transform);

        //instruments
        fireExtInstrument_pool = new ObjectPooling(size, Instrument.GetInstrumentPrefab(InstrumentsType.fire_extinguisher), transform);
        simpleRepairerInstrument_pool = new ObjectPooling(size, Instrument.GetInstrumentPrefab(InstrumentsType.repair_kit), transform);
    }


    public static void AddIncident(IncidentsType _type, Vector3 position)
    {
        GameObject incident = default;

        switch (_type)
        {
            case IncidentsType.fire:
                incident = ObjectPooling.fireIncident_pool.GetObject();
                break;

            case IncidentsType.simple_wreck:
                incident = ObjectPooling.simpleWreckIncident_pool.GetObject();
                break;

        }

        incident.SetActive(true);
        incident.transform.position = position;
    }


    public static void AddInstrument(InstrumentsType _type, Vector3 position)
    {
        GameObject instrument = default;

        switch (_type)
        {
            case InstrumentsType.fire_extinguisher:
                instrument = ObjectPooling.fireExtInstrument_pool.GetObject();
                break;

            case InstrumentsType.repair_kit:
                instrument = ObjectPooling.simpleRepairerInstrument_pool.GetObject();
                break;
        }

        instrument.SetActive(true);
        instrument.transform.position = position;
        instrument.GetComponent<Instrument>().MakeThrownAway();
    }



    public ObjectPooling(int Index, GameObject Example, Transform Storage)
    {
        example = Example;
        storage = Storage;

        poolOfObjects = new Queue<GameObject>();


        for (int i = 0; i < Index; i++)
        {
            GameObject _object = Instantiate(Example, Vector3.zero, Quaternion.identity, Storage);
            _object.SetActive(false);
            poolOfObjects.Enqueue(_object);
        }
    }

    public ObjectPooling(int Index, GameObject Example)
    {
        example = Example;
        storage = null;

        poolOfObjects = new Queue<GameObject>();


        for (int i = 0; i < Index; i++)
        {
            GameObject _object = Instantiate(Example);
            _object.SetActive(false);
            poolOfObjects.Enqueue(_object);
        }
    }

    public GameObject GetObject()
    {
        if (poolOfObjects.Count > 0) return poolOfObjects.Dequeue();

        print("instantiated new object of type: queue is full");
        GameObject _object = null;
        if (storage == null)
        {
            _object = Instantiate(example);
        }
        else
        {
            _object = Instantiate(example, storage);
        }

        _object.SetActive(false);

        return _object;
    }

    public GameObject GetObject(bool isActiveBeforeTaken)
    {
        if (poolOfObjects.Count > 0)
        {
            GameObject result = poolOfObjects.Dequeue();
            result.SetActive(isActiveBeforeTaken);
            return result;
        }


        print("instantiated new object of type: queue is full");
        GameObject _object = null;
        if (storage == null)
        {
            Instantiate(example);
        }
        else
        {
            Instantiate(example, storage);
        }

        _object.SetActive(isActiveBeforeTaken);

        return _object;
    }

    public void ReturnObject(GameObject _object)
    {
        _object.SetActive(false);
        poolOfObjects.Enqueue(_object);
    }

}
