using DG.Tweening;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

[RequireComponent(typeof(SphereCollider))]
public class Instrument : MonoBehaviour, ITakenAndMovable, IHighlightable
{
    [SerializeField] private InstrumentsType currentInstrumentType;
    [SerializeField] private UIIconTypes currentIconType;
    [SerializeField] private float YCoordWhenThrownAway;
    [SerializeField] private Transform currentVisualTransform, UIPositionPoint, currentTransform, currentEffect, currentIncidentInAction, baseHighLight;
    [SerializeField] private SphereCollider currentCollider;
    [SerializeField] private settings GeneralSettings;
    [SerializeField] private float instrumentHealthEffect;
    [SerializeField] private Material highlightMaterial;
    [SerializeField] private bool isItSingleAttheBegining;

    private Material baseMaterial;
    private bool isCanBeTakenByCrew = false;
    private bool isHighlightEffectInProgress;
    
    private Vector3 modelStandartRotation;
    private float modelAngle;

    //UI information mark
    private GameObject uiInformationMark;
    private RectTransform uiInformationMarkRect;
    private Vector3 OnScreenPosition;

    private Dictionary<Incident, float> checkCurrentDealingWithIncident = new Dictionary<Incident, float>();

    private void OnEnable()
    {
        if (baseMaterial == null) baseMaterial = Highlighting.GetBaseMaterial(baseHighLight);
        currentTransform = GetComponent<Transform>();

        modelStandartRotation = currentVisualTransform.localEulerAngles;

        uiInformationMark = Instantiate(UIManager.GetUIPrefab(UIPanelTypes.information_mark), GameObject.Find("MainCanvas").transform);
        uiInformationMark.transform.GetChild(1).GetComponent<Image>().sprite = UIManager.GetUIIconSprite(currentIconType);
        uiInformationMarkRect = uiInformationMark.GetComponent<RectTransform>();
        uiInformationMarkRect.localScale = new Vector3(0.7f, 0.7f, 0.7f);


        uiInformationMarkRect.gameObject.SetActive(false);
        HideEffectOfWorkingInstrument();
        if (isItSingleAttheBegining) MakeThrownAway();
    }

    private void ShowUIInformationMark(Camera camera)
    {
        OnScreenPosition = camera.WorldToScreenPoint(UIPositionPoint.position);
        uiInformationMarkRect.anchoredPosition = new Vector2(OnScreenPosition.x, OnScreenPosition.y + 30);
    }



    public static GameObject GetInstrumentPrefab(InstrumentsType _instrument)
    {
        GameObject result = default;

        switch ((int)_instrument)
        {
            case 0:
                result = Resources.Load<GameObject>("prefabs/instruments/fire extinguisher");
                break;
            case 1:
                result = Resources.Load<GameObject>("prefabs/instruments/fire extinguisher");
                break;
            case 2:
                result = Resources.Load<GameObject>("prefabs/instruments/wrench");
                break;

        }

        return result;
    }

    private void ShowEffectOfWorkingInstrument()
    {
        if (!currentEffect.gameObject.activeSelf)
        {
            currentEffect.gameObject.SetActive(true);
        }

    }

    private void HideEffectOfWorkingInstrument()
    {
        if (currentEffect.gameObject.activeSelf) currentEffect.gameObject.SetActive(false);
    }

    public Transform GetCurrentIncidentInAction()
    {
        return currentIncidentInAction;
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
        
        if (checkCurrentDealingWithIncident.Count > 0)
        {
            foreach (var item in checkCurrentDealingWithIncident.Keys)
            {                
                if (item.IncidentHealth <= 0)
                {
                    HideEffectOfWorkingInstrument();
                    checkCurrentDealingWithIncident.Remove(item);
                    break;
                }
                else if(item.IncidentHealth > 0 && checkCurrentDealingWithIncident[item] > 0.5f && item.GetInstrumentTypeToDealWithIncident() == currentInstrumentType)
                {                    
                    //ShowEffectOfWorkingInstrument();
                }                    
            }                        
        }
        else
        {
            HideEffectOfWorkingInstrument();
            currentIncidentInAction = null;
        }
        
    }


    public object GetTypeOfObject()
    {
        return currentInstrumentType;
    }


    public bool IsCanBeTakenByCrew()
    {
        return isCanBeTakenByCrew;
    }

    public InstrumentsType GetCurrentTypeOfInstrument()
    {
        return currentInstrumentType;
    }


    public GameObject GiveAwayTakeble()
    {
        if (isCanBeTakenByCrew)
        {
            //currentCollider.enabled = false;

            isCanBeTakenByCrew = false;
            currentVisualTransform.localEulerAngles = modelStandartRotation;
            uiInformationMarkRect.gameObject.SetActive(false);
            GameManagement.MainUIHandler -= ShowUIInformationMark;
            return gameObject;
        }
        else
        {
            return null;
        }
    }

    public void MakeThrownAway()
    {
        currentTransform.rotation = Quaternion.Euler(Vector3.zero);
        currentTransform.localScale = Vector3.one;
        currentVisualTransform.gameObject.SetActive(true);
        currentVisualTransform.localScale = Vector3.one;
        currentVisualTransform.localPosition = Vector3.zero;

        isCanBeTakenByCrew = true;

        //currentCollider.enabled = true;
        uiInformationMarkRect.gameObject.SetActive(true);
        GameManagement.MainUIHandler += ShowUIInformationMark;
        GetComponent<Transform>().localPosition = new Vector3(GetComponent<Transform>().localPosition.x, YCoordWhenThrownAway, GetComponent<Transform>().localPosition.z);
    }

    public Transform GetVisualTransform() {return currentVisualTransform;}

    private void OnTriggerStay(Collider other)
    {
        //currentIncidentInAction = null;

        if (other.TryGetComponent(out Incident currentIncident) && currentIncident.IncidentHealth > 0 && !isCanBeTakenByCrew)
        {   
            if (!checkCurrentDealingWithIncident.ContainsKey(currentIncident))
            {
                checkCurrentDealingWithIncident.Add(currentIncident, 0);
            }

            if (checkCurrentDealingWithIncident.ContainsKey(currentIncident))
            {
                checkCurrentDealingWithIncident[currentIncident] += Time.deltaTime;
            }

            if (currentIncident.GetInstrumentTypeToDealWithIncident() == currentInstrumentType && currentIncident.IncidentHealth > 0 && checkCurrentDealingWithIncident[currentIncident] > 0.5f)
            {                
                currentIncidentInAction = other.gameObject.transform;
                ShowEffectOfWorkingInstrument();
                currentIncident.DecreaseHealthAmount(instrumentHealthEffect * Time.deltaTime);
            }              
            
        }
        //else if ()
    }

    private void OnTriggerEnter(Collider other)
    {
        if (other.TryGetComponent(out Incident currentIncident) && !checkCurrentDealingWithIncident.ContainsKey(currentIncident) && currentIncident.IncidentHealth > 0)
        {            
            checkCurrentDealingWithIncident.Add(currentIncident, 0);            
        }
    }

    private void OnTriggerExit(Collider other)
    {
        if (other.TryGetComponent(out Incident currentIncident)/* && currentIncident.IncidentHealth > 0*/)
        {
            HideEffectOfWorkingInstrument();

            if (other.gameObject.transform == currentIncidentInAction)
            {
                currentIncidentInAction = null;
            }
                        
            if (checkCurrentDealingWithIncident.ContainsKey(currentIncident))
            {
                checkCurrentDealingWithIncident.Remove(currentIncident);
            }
        }

        
    }

    public void HighlightCurrentObject()
    {
        if (!isHighlightEffectInProgress && isCanBeTakenByCrew) StartCoroutine(HandleCurrentHighlight());
    }

    public IEnumerator HandleCurrentHighlight()
    {
        isHighlightEffectInProgress = true;

        Highlighting.ChangeMaterial(highlightMaterial, baseHighLight);
        
        currentVisualTransform.DOShakeScale(GeneralSettings.TimeForShakeForInstruments, GeneralSettings.StrenghtOfShakeOnHighlightingInstruments, 10, 90, true);

        yield return new WaitForSeconds(GeneralSettings.TimeForShakeForInstruments);
        isHighlightEffectInProgress = false;

        Highlighting.ChangeMaterial(baseMaterial, baseHighLight);
    }
}
