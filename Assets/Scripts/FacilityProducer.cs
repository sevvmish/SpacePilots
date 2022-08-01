using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class FacilityProducer : MonoBehaviour, IPointOfInteraction
{
    [SerializeField] private Movables currentMovableToProduce;
    [SerializeField] private Transform pointOfInterest;
    private ObjectPooling currentPoolOfObjects;


    private void OnEnable()
    {
        currentPoolOfObjects = new ObjectPooling(10, Movable.GetMovablePrefab(currentMovableToProduce), this.transform);
    }

    public GameObject GetMovableFromProducer()
    {
        return currentPoolOfObjects.GetObject();
    }

    public Vector3 GetPointOfInteraction()
    {
        return pointOfInterest.position;
    }
}


