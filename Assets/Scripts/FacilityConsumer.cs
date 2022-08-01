using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class FacilityConsumer : MonoBehaviour, IPointOfInteraction
{
    [SerializeField] private Movables currentMovableToConsume;
    [SerializeField] private Transform pointOfInterest;

    public Vector3 GetPointOfInteraction()
    {
        return pointOfInterest.position;
    }

    public void ConsumeMovable(GameObject _movable)
    {
        _movable.transform.SetParent(this.transform);
        _movable.transform.localPosition = Vector3.one;
    }
    public Movables GetFacilityConsumerMovableType()
    {
        return currentMovableToConsume;
    }
}
