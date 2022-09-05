using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using DG.Tweening;

public class FacilityProducer : MonoBehaviour, IPointOfInteraction, ITakenAndMovable, IHighlightable
{
    [SerializeField] private SuppliesType currentMovableToProduce;
    [SerializeField] private Transform pointOfInterestFROM, pointOfInterestTO, currentVisualTransform;    
    [SerializeField] private settings GeneralSettings;

    //highlighting
    [SerializeField] private Material highlightMaterial;
    [SerializeField] private List<MeshRenderer> baseRenderersForHiglight = new List<MeshRenderer>();
    private List<Material> baseMaterialsForHiglight = new List<Material>();
    private bool isHighlightEffectInProgress;
    //===========

    [SerializeField] private GameObject giveAwayEffect;

    private void Start()
    {
        for (int i = 0; i < baseRenderersForHiglight.Count; i++)
        {
            baseMaterialsForHiglight.Add(baseRenderersForHiglight[i].material);
        }
    }


    public Vector3 GetPointOfInteraction()
    {
        return Vector3.Lerp(pointOfInterestFROM.position, pointOfInterestTO.position, UnityEngine.Random.Range(0.1f, 1f));
    }

    public GameObject GiveAwayTakeble()
    {
        if (giveAwayEffect != null) giveAwayEffect.SetActive(true);
        return ObjectPooling.GetSupply(currentMovableToProduce, transform.position, false);
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

        HighLightObject();

        for (int i = 0; i < baseRenderersForHiglight.Count; i++)
        {
            float deltaX = baseRenderersForHiglight[i].transform.localScale.x / 1f;
            float deltaY = baseRenderersForHiglight[i].transform.localScale.y / 1f;
            float deltaZ = baseRenderersForHiglight[i].transform.localScale.z / 1f;

            baseRenderersForHiglight[i].transform.DOShakeScale(GeneralSettings.TimeForShakeForSupply, new Vector3(GeneralSettings.StrenghtOfShakeOnHighlightingSupply.x * deltaX, GeneralSettings.StrenghtOfShakeOnHighlightingSupply.y * deltaY, GeneralSettings.StrenghtOfShakeOnHighlightingSupply.z * deltaZ) * 2f, 10, 90, true);
        }

        yield return new WaitForSeconds(GeneralSettings.TimeForShakeForSupply);
        isHighlightEffectInProgress = false;

        UnHighLightObject();
    }

    private void HighLightObject()
    {
        for (int i = 0; i < baseRenderersForHiglight.Count; i++)
        {
            baseRenderersForHiglight[i].material = highlightMaterial;
        }
    }

    private void UnHighLightObject()
    {
        for (int i = 0; i < baseRenderersForHiglight.Count; i++)
        {
            baseRenderersForHiglight[i].material = baseMaterialsForHiglight[i];
        }
    }

    public void MakeThrownAway()
    {
        //FORBIDDEN
    }

    public void RotateWhileThrownAway()
    {
        //FORBIDDEN
    }

    public bool IsCanBeTakenByCrew()
    {
        return true;
    }
}


