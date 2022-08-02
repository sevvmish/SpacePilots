using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class FacilityProducer : MonoBehaviour, IPointOfInteraction
{
    [SerializeField] private Supplies currentMovableToProduce;
    [SerializeField] private Transform pointOfInterest;
    private ObjectPooling currentPoolOfObjects;


    private void OnEnable()
    {
        currentPoolOfObjects = new ObjectPooling(10, Supply.GetMovablePrefab(currentMovableToProduce), this.transform);
    }

    public GameObject GetSupplyFromProducer()
    {
        return currentPoolOfObjects.GetObject();
    }

    public Vector3 GetPointOfInteraction()
    {
        return pointOfInterest.position;
    }
}


