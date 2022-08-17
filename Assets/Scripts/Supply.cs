using DG.Tweening;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.AI;

[RequireComponent(typeof(SphereCollider))]
public class Supply : MonoBehaviour, ITakenAndMovable, IHighlightable
{
    [SerializeField] private SuppliesType currentSupplyType;    
    [SerializeField] private float YCoordWhenThrownAway;
    [SerializeField] private SphereCollider currentCollider;
    [SerializeField] private Transform currentVisualTransform, currentTransform;
    [SerializeField] private bool isCanBeTakenByCrew = false;
    [SerializeField] private settings GeneralSettings;

    //highlighting
    [SerializeField] private Material highlightMaterial;
    [SerializeField] private List<MeshRenderer> baseRenderersForHiglight = new List<MeshRenderer>();
    private List<Material> baseMaterialsForHiglight = new List<Material>();
    private bool isHighlightEffectInProgress;
    //===========


    private float modelAngle;
    private Vector3 modelStandartRotation;

    private void Start()
    {
        for (int i = 0; i < baseRenderersForHiglight.Count; i++)
        {
            baseMaterialsForHiglight.Add(baseRenderersForHiglight[i].material);
        }      
    }


    private void OnEnable()
    {
        currentTransform = GetComponent<Transform>();
        if (isCanBeTakenByCrew) MakeThrownAway();
        modelStandartRotation = currentVisualTransform.localEulerAngles;
    }

    public void RotateWhileThrownAway()
    {
        if (isCanBeTakenByCrew)
        {
            modelAngle += Time.deltaTime * 30;
            currentVisualTransform.localEulerAngles = new Vector3(modelStandartRotation.x, modelStandartRotation.y + modelAngle, modelStandartRotation.z);
        }
        else
        {
            modelAngle = 0;
        }
    }


    private void Update()
    {
        RotateWhileThrownAway();
    }

    public void MakeThrownAway()
    {
        currentTransform.rotation = Quaternion.Euler(Vector3.zero);
        currentTransform.localScale = Vector3.one;
        currentCollider.enabled = true;
        isCanBeTakenByCrew = true;
        GetComponent<Transform>().localPosition = new Vector3(GetComponent<Transform>().localPosition.x, YCoordWhenThrownAway, GetComponent<Transform>().localPosition.z);
    }


    public static GameObject GetSupplyPrefab(SuppliesType _movable)
    {
        GameObject result = default;

        switch(_movable)
        {
            case SuppliesType.tester:
                result = Resources.Load<GameObject>("prefabs/supplies/test movable");
                break;

            case SuppliesType.empty_engine_fuel:
                result = Resources.Load<GameObject>("prefabs/supplies/empty fuel barrel");
                break;

            case SuppliesType.full_engine_fuel:
                result = Resources.Load<GameObject>("prefabs/supplies/full fuel barrel");
                break;

        }

        return result;
    }

    public object GetTypeOfObject()
    {
        return currentSupplyType;
    }

    public bool IsCanBeTakenByCrew()
    {
        return isCanBeTakenByCrew;
    }

    public GameObject GiveAwayTakeble()
    {
        if (isCanBeTakenByCrew)
        {
            currentCollider.enabled = false;
            isCanBeTakenByCrew = false;
            currentVisualTransform.localEulerAngles = modelStandartRotation;
            return gameObject;
        }
        else
        {
            return null;
        }
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

    public void HighlightCurrentObject()
    {
        if (!isHighlightEffectInProgress) StartCoroutine(HandleCurrentHighlight());
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
}

