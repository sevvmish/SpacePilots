using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class FacilityConsumer : MonoBehaviour, IPointOfInteraction
{
    [SerializeField] private SuppliesType currentSupplyToConsume;
    [SerializeField] private Transform pointOfInterestFROM, pointOfInterestTO;

    public Vector3 GetPointOfInteraction()
    {
        return Vector3.Lerp(pointOfInterestFROM.position, pointOfInterestTO.position, UnityEngine.Random.Range(0.1f, 1f));
    }

    public void ConsumeMovable(GameObject _movable)
    {
        _movable.transform.SetParent(this.transform);
        _movable.transform.localPosition = Vector3.one;
    }
    public SuppliesType GetFacilityConsumerSupplyType()
    {
        return currentSupplyToConsume;
    }
}
