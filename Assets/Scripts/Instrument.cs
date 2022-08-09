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
        if (baseMaterial == null) baseMaterial = Enums_n_Interfaces.GetBaseMaterial(baseHighLight);
        currentTransform = GetComponent<Transform>();

        modelStandartRotation = currentVisualTransform.localEulerAngles;

        uiInformationMark = Instantiate(UIManager.GetUIPrefab(UIPanelTypes.information_mark), GameObject.Find("MainCanvas").transform);
        uiInformationMark.transform.GetChild(1).GetComponent<Image>().sprite = UIManager.GetUIIconSprite(currentIconType);
        uiInformationMarkRect = uiInformationMark.GetComponent<RectTransform>();
        GameManagement.MainUIHandler += ShowUIInformationMark;
        uiInformationMarkRect.gameObject.SetActive(false);
        HideEffectOfWorkingInstrument();

    }

    private void ShowUIInformationMark(Camera camera)
    {
        OnScreenPosition = camera.WorldToScreenPoint(UIPositionPoint.position);
        uiInformationMarkRect.anchoredPosition = new Vector2(OnScreenPosition.x, OnScreenPosition.y + 40);
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
    }


    public object GetTypeOfObject()
    {
        return currentInstrumentType;
    }

    public bool IsCanBeTakenByCrew()
    {
        return isCanBeTakenByCrew;
    }

    public GameObject GiveAwayTakeble()
    {
        if (isCanBeTakenByCrew)
        {
            //currentCollider.enabled = false;

            isCanBeTakenByCrew = false;
            currentVisualTransform.localEulerAngles = modelStandartRotation;
            uiInformationMarkRect.gameObject.SetActive(false);
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
        GetComponent<Transform>().localPosition = new Vector3(GetComponent<Transform>().localPosition.x, YCoordWhenThrownAway, GetComponent<Transform>().localPosition.z);
    }

    public Transform GetVisualTransform() {return currentVisualTransform;}

    private void OnTriggerStay(Collider other)
    {
        currentIncidentInAction = null;

        if (other.gameObject.CompareTag("Incident"))
        {            
            Incident currentIncident = other.gameObject.GetComponent<Incident>();
                        
            if (checkCurrentDealingWithIncident.ContainsKey(currentIncident))
            {
                checkCurrentDealingWithIncident[currentIncident] += Time.deltaTime;
            }

            if (currentIncident.GetInstrumentTypeToDealWithIncident() == currentInstrumentType && currentIncident.Health > 0 && checkCurrentDealingWithIncident[currentIncident] > 0.5f)
            {
                //if (checkCurrentDealingWithIncident[currentIncident] > 0.75f) instrumentOwner.LookAt(other.gameObject.transform);

                currentIncidentInAction = other.gameObject.transform;
                ShowEffectOfWorkingInstrument();
                currentIncident.DecreaseHealthAmount(instrumentHealthEffect * Time.deltaTime);
            }              
        }
    }

    private void OnTriggerEnter(Collider other)
    {
        if (other.gameObject.CompareTag("Incident"))
        {
            Incident currentIncident = other.gameObject.GetComponent<Incident>();

            if (!checkCurrentDealingWithIncident.ContainsKey(currentIncident))
            {
                checkCurrentDealingWithIncident.Add(currentIncident, 0);
            }
        }
    }

    private void OnTriggerExit(Collider other)
    {
        if (other.gameObject.CompareTag("Incident"))
        {
            HideEffectOfWorkingInstrument();

            if (other.gameObject.transform == currentIncidentInAction)
            {
                currentIncidentInAction = null;
            }

            Incident currentIncident = other.gameObject.GetComponent<Incident>();
            if (checkCurrentDealingWithIncident.ContainsKey(currentIncident))
            {
                checkCurrentDealingWithIncident.Remove(currentIncident);
            }
        }

        
    }

    public void HighlightCurrentObject()
    {
        if (!isHighlightEffectInProgress) StartCoroutine(HandleCurrentHighlight());
    }

    public IEnumerator HandleCurrentHighlight()
    {
        isHighlightEffectInProgress = true;

        Enums_n_Interfaces.ChangeMaterial(highlightMaterial, baseHighLight);
        
        currentVisualTransform.DOShakeScale(GeneralSettings.TimeForShakeForInstruments, GeneralSettings.StrenghtOfShakeOnHighlightingInstruments, 10, 90, true);

        yield return new WaitForSeconds(GeneralSettings.TimeForShakeForInstruments);
        isHighlightEffectInProgress = false;

        Enums_n_Interfaces.ChangeMaterial(baseMaterial, baseHighLight);
    }
}
