using DG.Tweening;
using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Reactor : MonoBehaviour, IPointOfInteraction, IHighlightable, IConsumer
{
    public float Energy;

    [SerializeField] private Transform pointOfInterestFROM, pointOfInterestTO, UIPositionPoint, greenLight, redLight, barrelExample, loadingBarrelEffects, panelForLoadingEff1, panelForLoadingEff2;
    [SerializeField] private settings GeneralSettings;
    [SerializeField] private SuppliesType currentSupplyToConsumeType;
    [SerializeField] private float standartBarrelCapacity = 1;
    [SerializeField] private float barrelConsuptionSpeed = 0.02f;

    //highlighting
    [SerializeField] private Material highlightMaterial;
    [SerializeField] private List<MeshRenderer> baseRenderersForHiglight = new List<MeshRenderer>();
    private List<Material> baseMaterialsForHiglight = new List<Material>();
    private bool isHighlightEffectInProgress;
    //===========

    //UI information mark
    //private GameObject uiInformationMark;
    //private RectTransform uiInformationMarkRect;
    //private Vector3 OnScreenPosition;

    private UIManager informationMark;

    private Action makeBlink;
    private Material barrelExampleMaterial;
    [SerializeField] private AudioSource alarmSound;
    private bool param1, param2, param3;
    //==================

    private float currentBarrelCapacity;
    private bool isReactorLoaded, isShowMediumLevelInColor, isReactorReadyToLoadAgain;

    [SerializeField] private bool isStartFromLoaded;
    [SerializeField] private float loadedAmount;


    private void Start()
    {
        for (int i = 0; i < baseRenderersForHiglight.Count; i++)
        {
            baseMaterialsForHiglight.Add(baseRenderersForHiglight[i].material);
        }

        
    }

    private void OnEnable()
    {
        barrelExampleMaterial = Instantiate(barrelExample.GetChild(0).GetChild(0).GetComponent<MeshRenderer>().material);
        barrelExample.GetChild(0).GetChild(0).GetComponent<MeshRenderer>().material = barrelExampleMaterial;

        greenLight.GetComponent<MeshRenderer>().material.SetColor("_BaseColor", Color.green);
        greenLight.GetComponent<MeshRenderer>().material.SetColor("_EmissionColor", Color.green * GeneralSettings.BaseBloomIntensityColor);

        redLight.GetComponent<MeshRenderer>().material.SetColor("_BaseColor", Color.red);
        redLight.GetComponent<MeshRenderer>().material.SetColor("_EmissionColor", Color.red * GeneralSettings.BaseBloomIntensityColor);

        loadingBarrelEffects.gameObject.SetActive(false);

        //icon of overheating
        //uiInformationMark = Instantiate(UIManager.GetUIPrefab(UIPanelTypes.information_mark), GameObject.Find("MainCanvas").transform);
        //uiInformationMark.transform.GetChild(1).GetComponent<Image>().sprite = UIManager.GetUIIconSprite(UIIconTypes.energy_fuel);
        //uiInformationMark.transform.GetChild(0).GetComponent<Image>().color = Color.black;
        //uiInformationMark.transform.GetChild(1).GetComponent<Image>().color = Color.white;
        //uiInformationMarkRect = uiInformationMark.GetComponent<RectTransform>();
        //GameManagement.MainUIHandler -= UpdateUIPosition;
        //uiInformationMarkRect.gameObject.SetActive(false);

        informationMark = new UIManager(UIPositionPoint, UIPanelTypes.information_mark, UIIconTypes.energy_fuel, Color.black, Color.white);

        if (!isStartFromLoaded)
        {
            SetStateToEmpty();
        }
        else
        {
            SetStateToEmpty();
            SetStateToLoaded();
            currentBarrelCapacity = loadedAmount;
        }

        
            
    }

    /*
    private void UpdateUIPosition(Camera camera)
    {
        OnScreenPosition = camera.WorldToScreenPoint(UIPositionPoint.position);
        uiInformationMarkRect.anchoredPosition = new Vector2(OnScreenPosition.x, OnScreenPosition.y + 40);
    }



    private void ShowUI()
    {
        if (!uiInformationMarkRect.gameObject.activeSelf)
        {            
            GameManagement.MainUIHandler += UpdateUIPosition;
            uiInformationMarkRect.gameObject.SetActive(true);
        }
    }

    private void HideUI()
    {
        if (uiInformationMarkRect.gameObject.activeSelf)
        {
            GameManagement.MainUIHandler -= UpdateUIPosition;
            uiInformationMarkRect.gameObject.SetActive(false);
        }
    }
    */


    private void SetStateToEmpty()
    {
        //uiInformationMark.GetComponent<MakeActiveInTimer>().enabled = false;
        informationMark.IsBlinking = false;
        makeBlink = null;
        param1 = param2 = param3 = false;

        currentBarrelCapacity = 0;
        Energy = 0;
        isReactorLoaded = false;
        isReactorReadyToLoadAgain = true;
        greenLight.gameObject.SetActive(false);
        redLight.gameObject.SetActive(true);
        barrelExample.gameObject.SetActive(false);
        //ShowUI();
        informationMark.ShowUI();
    }


    private void SetStateToLoaded()
    {
        //uiInformationMark.GetComponent<MakeActiveInTimer>().enabled = false;
        informationMark.IsBlinking = false;
        makeBlink = null;
        param1 = param2 = param3 = false;
        isShowMediumLevelInColor = false;

        barrelExample.GetChild(0).localScale = Vector3.one;
        barrelExampleMaterial.SetColor("_BaseColor", Color.green);
        barrelExampleMaterial.SetColor("_EmissionColor", Color.green * GeneralSettings.BaseBloomIntensityColor);

        currentBarrelCapacity = standartBarrelCapacity;
        Energy = 1;
        isReactorLoaded = true;
        isReactorReadyToLoadAgain = false;
        greenLight.gameObject.SetActive(true);
        redLight.gameObject.SetActive(false);
        barrelExample.gameObject.SetActive(true);
        //HideUI();
        informationMark.HideUI();
    }


    private void Update()
    {
        if (isReactorLoaded && currentBarrelCapacity>0)
        {
            currentBarrelCapacity -= barrelConsuptionSpeed * Time.deltaTime;
            barrelExample.GetChild(0).localScale = new Vector3(currentBarrelCapacity/standartBarrelCapacity, 1, currentBarrelCapacity / standartBarrelCapacity);
            
            if (currentBarrelCapacity < (standartBarrelCapacity * 0.21f) && makeBlink == null)
            {
                Energy = 0.5f;
                isReactorReadyToLoadAgain = true;
                barrelExampleMaterial.SetColor("_BaseColor", Color.red);
                barrelExampleMaterial.SetColor("_EmissionColor", Color.red * GeneralSettings.BaseBloomIntensityColor);
                //uiInformationMark.GetComponent<MakeActiveInTimer>().enabled = true;
                //uiInformationMark.GetComponent<MakeActiveInTimer>().isLeaveEnabled = true;
                informationMark.IsBlinking = true;
                informationMark.IsLeaveEnabledAfterBlinking = true;
                makeBlink = makeBlinkOnLowCapacity;
                //ShowUI();
                informationMark.ShowUI();
            }

            if (!isShowMediumLevelInColor && currentBarrelCapacity < (standartBarrelCapacity * 0.5f))
            {
                isShowMediumLevelInColor = true;
                barrelExampleMaterial.SetColor("_BaseColor", Color.yellow);
                barrelExampleMaterial.SetColor("_EmissionColor", Color.yellow * GeneralSettings.BaseBloomIntensityColor);
            }
                        
        }
        else if (isReactorLoaded && currentBarrelCapacity <= 0)
        {
            SetStateToEmpty();
        }

        makeBlink?.Invoke();
    }

    private void makeBlinkOnLowCapacity()
    {
        if (currentBarrelCapacity < (standartBarrelCapacity * 0.07f) && !param1)
        {
            param1 = true;
            //uiInformationMark.GetComponent<MakeActiveInTimer>().howLong = 0.15f;
            //uiInformationMark.GetComponent<MakeActiveInTimer>().whatInterval = 0.1f;
            informationMark.HowLongToBlink = 0.15f;
            informationMark.WhatIntervalToBlink = 0.1f;
            alarmSound.Play();
        }
        else if (currentBarrelCapacity < (standartBarrelCapacity * 0.14f) && !param2)
        {
            param2 = true;
            //uiInformationMark.GetComponent<MakeActiveInTimer>().howLong = 0.3f;
            //uiInformationMark.GetComponent<MakeActiveInTimer>().whatInterval = 0.15f;
            informationMark.HowLongToBlink = 0.3f;
            informationMark.WhatIntervalToBlink = 0.15f;
            alarmSound.Play();
        }
        else if(currentBarrelCapacity < (standartBarrelCapacity * 0.21f) && !param3)
        {
            param3 = true;
            //uiInformationMark.GetComponent<MakeActiveInTimer>().howLong = 0.5f;
            //uiInformationMark.GetComponent<MakeActiveInTimer>().whatInterval = 0.3f;
            informationMark.HowLongToBlink = 0.5f;
            informationMark.WhatIntervalToBlink = 0.3f;
            alarmSound.Play();
        }        
    }

    public Vector3 GetPointOfInteraction()
    {
        return Vector3.Lerp(pointOfInterestFROM.position, pointOfInterestTO.position, UnityEngine.Random.Range(0.1f, 1f));
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

            baseRenderersForHiglight[i].transform.DOShakeScale(GeneralSettings.TimeForShakeForSupply, new Vector3(GeneralSettings.StrenghtOfShakeOnHighlightingSupply.x * deltaX, GeneralSettings.StrenghtOfShakeOnHighlightingSupply.y * deltaY, GeneralSettings.StrenghtOfShakeOnHighlightingSupply.z * deltaZ), 10, 90, true);
            
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

    public bool ConsumeSupply(GameObject supply)
    {
        if (isReactorReadyToLoadAgain && supply.TryGetComponent(out Supply _supply) && (SuppliesType)_supply.GetTypeOfObject() == SuppliesType.full_engine_fuel)
        {
            supply.transform.SetParent(this.transform);
            supply.transform.localPosition = Vector3.one;
            supply.SetActive(false);
            ObjectPooling.ReturnSupply(supply);
            SetStateToLoaded();
            StartCoroutine(playBarrelLoadingEffect());
            return true;
        }

        return false;
    }

    public SuppliesType GetFacilityConsumerSupplyType()
    {
        return currentSupplyToConsumeType;
    }

    private IEnumerator playBarrelLoadingEffect()
    {
        loadingBarrelEffects.gameObject.SetActive(true);
        panelForLoadingEff1.DOLocalMoveY(-0.355f, 0.25f);
        panelForLoadingEff2.DOLocalMoveY(-0.355f, 0.25f);
        yield return new WaitForSeconds(0.5f);

        panelForLoadingEff1.DOLocalMoveY(0.355f, 0.25f);
        panelForLoadingEff2.DOLocalMoveY(0.355f, 0.25f);
        yield return new WaitForSeconds(0.5f);
        
        loadingBarrelEffects.gameObject.SetActive(false);
    }
}
