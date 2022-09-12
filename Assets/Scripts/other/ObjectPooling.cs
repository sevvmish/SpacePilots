using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ObjectPooling : MonoBehaviour
{
    private GameObject example;
    private Transform storage;

    private Queue<GameObject> poolOfObjects;

    public static Transform basicTransform;
    
    //PUBLIC STATIC
    //incidents
    public static ObjectPooling fireIncident_pool, simpleWreckIncident_pool, smokeAfterFire_pool, repairAfterWreck_pool, poisonPatchAfterBarrel_pool, death_pool;
    //instruments
    public static ObjectPooling fireExtInstrument_pool, simpleRepairerInstrument_pool;
    //supply
    public static ObjectPooling fullFuelBarrel_pool, emptyFuelBarrel_pool;


    public static void InitPools(int size, Transform _transform)
    {
        basicTransform = _transform;

        //objectpooling 
        //incidents
        death_pool = new ObjectPooling(size, Incident.GetIncidentPrefab(IncidentsType.death), _transform);
        fireIncident_pool = new ObjectPooling(size, Incident.GetIncidentPrefab(IncidentsType.fire), _transform);
        simpleWreckIncident_pool = new ObjectPooling(size, Incident.GetIncidentPrefab(IncidentsType.simple_wreck), _transform);
        smokeAfterFire_pool = new ObjectPooling(size, Incident.GetIncidentPrefab(IncidentsType.smoke_after_fire), _transform);
        repairAfterWreck_pool = new ObjectPooling(size, Incident.GetIncidentPrefab(IncidentsType.after_wreck), _transform);
        poisonPatchAfterBarrel_pool = new ObjectPooling(size, Incident.GetIncidentPrefab(IncidentsType.poison_patch), _transform);

        //instruments
        fireExtInstrument_pool = new ObjectPooling(size, Instrument.GetInstrumentPrefab(InstrumentsType.fire_extinguisher), _transform);
        simpleRepairerInstrument_pool = new ObjectPooling(size, Instrument.GetInstrumentPrefab(InstrumentsType.repair_kit), _transform);

        //supply
        fullFuelBarrel_pool = new ObjectPooling(size, Supply.GetSupplyPrefab(SuppliesType.full_engine_fuel), _transform);
        emptyFuelBarrel_pool = new ObjectPooling(size, Supply.GetSupplyPrefab(SuppliesType.empty_engine_fuel), _transform);

    }


    public static void AddIncident(IncidentsType _type, Vector3 position)
    {
        GameObject incident = default;

        switch (_type)
        {
            case IncidentsType.fire:
                incident = fireIncident_pool.GetObject();
                break;

            case IncidentsType.simple_wreck:
                incident = simpleWreckIncident_pool.GetObject();
                break;

            case IncidentsType.poison_patch:
                incident = poisonPatchAfterBarrel_pool.GetObject();
                break;

            case IncidentsType.death:
                incident = death_pool.GetObject();
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
                instrument = fireExtInstrument_pool.GetObject();
                break;

            case InstrumentsType.repair_kit:
                instrument = simpleRepairerInstrument_pool.GetObject();
                break;
        }

        instrument.SetActive(true);
        instrument.transform.position = position;
        instrument.GetComponent<Instrument>().MakeThrownAway();
    }


    public static void AddSupply(SuppliesType _type, Vector3 position, bool isMakeThrowAway)
    {
        GameObject supply = default;

        switch (_type)
        {
            case SuppliesType.full_engine_fuel:
                supply = fullFuelBarrel_pool.GetObject();
                break;

            case SuppliesType.empty_engine_fuel:
                supply = emptyFuelBarrel_pool.GetObject();
                break;
        }

        supply.SetActive(true);
        supply.transform.position = position;        
        if (isMakeThrowAway) supply.GetComponent<Supply>().MakeThrownAway();
    }

    public static GameObject GetSupply(SuppliesType _type, Vector3 position, bool isMakeThrowAway)
    {
        GameObject supply = default;

        switch (_type)
        {
            case SuppliesType.full_engine_fuel:
                supply = fullFuelBarrel_pool.GetObject();
                supply.SetActive(true);
                supply.transform.position = position;
                if (isMakeThrowAway) supply.GetComponent<Supply>().MakeThrownAway();
                return supply;

            case SuppliesType.empty_engine_fuel:
                supply = emptyFuelBarrel_pool.GetObject();
                supply.SetActive(true);
                supply.transform.position = position;
                if (isMakeThrowAway) supply.GetComponent<Supply>().MakeThrownAway();
                return supply;
        }

        return supply;
    }


    public static void ReturnSupply(GameObject supply)
    {
        supply.transform.SetParent(basicTransform);

        switch (supply.GetComponent<Supply>().GetTypeOfObject())
        {
            case SuppliesType.full_engine_fuel:
                fullFuelBarrel_pool.ReturnObject(supply);
                break;

            case SuppliesType.empty_engine_fuel:
                emptyFuelBarrel_pool.ReturnObject(supply);
                break;
        }
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
