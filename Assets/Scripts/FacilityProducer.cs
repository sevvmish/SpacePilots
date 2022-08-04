using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using DG.Tweening;

public class FacilityProducer : MonoBehaviour, IPointOfInteraction, ITakenAndMovable, IHighlightable
{
    [SerializeField] private SuppliesType currentMovableToProduce;
    [SerializeField] private Transform pointOfInterestFROM, pointOfInterestTO, currentVisualTransform;
    [SerializeField] private int amountOfStockSupply = 10;
    [SerializeField] private settings GeneralSettings;

    private ObjectPooling currentPoolOfObjects;
    private bool isHighlightEffectInProgress;

    private void OnEnable()
    {
        currentPoolOfObjects = new ObjectPooling(amountOfStockSupply, Supply.GetSupplyPrefab(currentMovableToProduce), transform);
    }

    public Vector3 GetPointOfInteraction()
    {
        return Vector3.Lerp(pointOfInterestFROM.position, pointOfInterestTO.position, UnityEngine.Random.Range(0.1f, 1f));
    }

    public GameObject GiveAwayTakeble()
    {
        return currentPoolOfObjects.GetObject();
    }
    
    public object GetTypeOfObject()
    {
        return currentMovableToProduce;
    }

    public void HighlightCurrentObject()
    {
        if (!isHighlightEffectInProgress) StartCoroutine(HandleCurrentHighlight());
    }

    public IEnumerator HandleCurrentHighlight()
    {
        isHighlightEffectInProgress = true;
        currentVisualTransform.DOShakeScale(GeneralSettings.TimeForShakeForFacility, GeneralSettings.StrenghtOfShakeOnHighlightingFacility, 10, 90, true);

        yield return new WaitForSeconds(GeneralSettings.TimeForShakeForFacility);
        isHighlightEffectInProgress = false;
    }

    public void MakeThrownAway()
    {
        //FORBIDDEN
    }
    public bool IsCanBeTakenByCrew()
    {
        return true;
    }
}


