using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using DG.Tweening;
using System;
using UnityEngine.UI;

public class FuelRecharger : MonoBehaviour, IPointOfInteraction, ITakenAndMovable, IHighlightable, IConsumer
{
    [SerializeField] private SuppliesType currentSupplyToConsumeType;
    [SerializeField] private SuppliesType currentSupplyToProduceType;
    [SerializeField] private Transform pointOfInterestFROM, pointOfInterestTO, currentVisualTransform, UIPositionPoint;
    [SerializeField] private settings GeneralSettings;
    [SerializeField] private float secondsForCharge = 10;
    [SerializeField] private float secondsForOverCharge = 8;

    //highlighting
    [SerializeField] private Material highlightMaterial;
    [SerializeField] private List<MeshRenderer> baseRenderersForHiglight = new List<MeshRenderer>();
    private List<Material> baseMaterialsForHiglight = new List<Material>();
    private bool isHighlightEffectInProgress;
    //===========

    [SerializeField] private Transform fuelBarrel;
    [SerializeField] private Transform fuelLevel;
    private float rechargingLevel, overchargingLevel;

    public bool isRechargerEmpty, isBarrelRecharging, isBarrelOverCharging, isShowingMark;

    [SerializeField] private GameObject startRechargeEffect, stopRechargeEffect, giveAwayEffect, overChargeEffect, explosion;

    //UI information mark
    private GameObject uiInformationMark;
    private RectTransform uiInformationMarkRect;
    private Vector3 OnScreenPosition;

    private Action makeBlink;
    private Material barrelExampleMaterial;
    [SerializeField] private AudioSource alarmSound;
    private bool param1, param2, param3;
    //==================

    private float cur_sec;
    private bool start_sec;


    private void Start()
    {
        for (int i = 0; i < baseRenderersForHiglight.Count; i++)
        {
            baseMaterialsForHiglight.Add(baseRenderersForHiglight[i].material);
        }
    }

    private void OnEnable()
    {
        //icon of overheating
        uiInformationMark = Instantiate(UIManager.GetUIPrefab(UIPanelTypes.information_mark), GameObject.Find("MainCanvas").transform);
        uiInformationMark.transform.GetChild(1).GetComponent<Image>().sprite = UIManager.GetUIIconSprite(UIIconTypes.energy_fuel);
        uiInformationMark.transform.GetChild(0).GetComponent<Image>().color = Color.red;
        uiInformationMark.transform.GetChild(1).GetComponent<Image>().color = Color.white;
        uiInformationMarkRect = uiInformationMark.GetComponent<RectTransform>();
        GameManagement.MainUIHandler -= UpdateUIPosition;
        uiInformationMarkRect.gameObject.SetActive(false);

        explosion.SetActive(false);
        EmptyRecharger();
    }

    private void UpdateUIPosition(Camera camera)
    {
        OnScreenPosition = camera.WorldToScreenPoint(UIPositionPoint.position);
        uiInformationMarkRect.anchoredPosition = new Vector2(OnScreenPosition.x, OnScreenPosition.y + 40);
    }



    private void ShowUI()
    {
        if (!uiInformationMarkRect.gameObject.activeSelf)
        {            
            uiInformationMarkRect.gameObject.SetActive(true);
        }

        GameManagement.MainUIHandler += UpdateUIPosition;
    }

    private void HideUI()
    {
        if (uiInformationMarkRect.gameObject.activeSelf)
        {            
            uiInformationMarkRect.gameObject.SetActive(false);
        }

        GameManagement.MainUIHandler -= UpdateUIPosition;
    }


    private void Update()
    {
        

        if (isBarrelOverCharging && overchargingLevel < secondsForOverCharge)
        {
            overchargingLevel += Time.deltaTime;

            if (!isShowingMark)
            {
                isShowingMark = true;
                uiInformationMark.GetComponent<MakeActiveInTimer>().enabled = true;
                uiInformationMark.GetComponent<MakeActiveInTimer>().isLeaveEnabled = true;
                makeBlink = makeBlinkOnLowCapacity;
                ShowUI();
                StartCoroutine(PlayOverChargingProcess());
            }
        }
        else if (isBarrelOverCharging && overchargingLevel >= secondsForOverCharge)
        {
            isRechargerEmpty = false;
            isBarrelRecharging = false;
            isBarrelOverCharging = false;

            StartCoroutine(PlayExplosion());
            
        }


        if (start_sec)
        {
            if (cur_sec>6)
            {
                print("6 sec");
            }
            else
            {
                cur_sec += Time.deltaTime;
            }
        }

        makeBlink?.Invoke();
    }


    private void makeBlinkOnLowCapacity()
    {
        if (overchargingLevel > (secondsForOverCharge*0.7f) && !param1)
        {
            param1 = true;
            uiInformationMark.GetComponent<MakeActiveInTimer>().howLong = 0.15f;
            uiInformationMark.GetComponent<MakeActiveInTimer>().whatInterval = 0.1f;
            alarmSound.Play();
        }
        else if (overchargingLevel > (secondsForOverCharge * 0.35f) && !param2)
        {
            param2 = true;
            uiInformationMark.GetComponent<MakeActiveInTimer>().howLong = 0.3f;
            uiInformationMark.GetComponent<MakeActiveInTimer>().whatInterval = 0.15f;
            alarmSound.Play();
        }
        else if (overchargingLevel > 0 && !param3)
        {
            param3 = true;
            uiInformationMark.GetComponent<MakeActiveInTimer>().howLong = 0.5f;
            uiInformationMark.GetComponent<MakeActiveInTimer>().whatInterval = 0.3f;
            alarmSound.Play();
        }
    }


    private void EmptyRecharger()
    {
        overChargeEffect.SetActive(false);
        fuelBarrel.localScale = Vector3.one;
        fuelBarrel.localPosition = new Vector3(-0.5f, 1, 0);

        stopRechargeEffect.SetActive(true);

        uiInformationMark.GetComponent<MakeActiveInTimer>().enabled = false;
        makeBlink = null;
        param1 = param2 = param3 = false;
        HideUI();

        rechargingLevel = 0;
        overchargingLevel = 0;

        fuelBarrel.gameObject.SetActive(false);
        isRechargerEmpty = true;
        isBarrelRecharging = false;
        isBarrelOverCharging = false;
        isShowingMark = false;
    }

    private void StartRechargingProcess()
    {
        startRechargeEffect.SetActive(true);

        isRechargerEmpty = false;
        isBarrelRecharging = true;
        isBarrelOverCharging = false;

        fuelBarrel.gameObject.SetActive(true);
        fuelLevel.localPosition = new Vector3(0, -0.35f, 0);
        fuelLevel.localScale = new Vector3(1, 0.01f, 1);
        rechargingLevel = 0;

        StartCoroutine(PlayRechargingProcess());
    }


    public Vector3 GetPointOfInteraction()
    {
        return Vector3.Lerp(pointOfInterestFROM.position, pointOfInterestTO.position, UnityEngine.Random.Range(0.1f, 1f));
    }

    public GameObject GiveAwayTakeble()
    {
        giveAwayEffect.SetActive(true);
        
        EmptyRecharger();
        return ObjectPooling.GetSupply(currentSupplyToProduceType, transform.position, false);
    }

    public object GetTypeOfObject()
    {
        if (isBarrelOverCharging)
        {
            return currentSupplyToProduceType;
        }
        else
        {
            return SuppliesType.none;
        }
        
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
        return isBarrelOverCharging;
    }

    private IEnumerator PlayRechargingProcess()
    {
        yield return new WaitForSeconds(0.5f);

        isBarrelRecharging = true;
        isBarrelOverCharging = false;

        fuelLevel.DOScaleY (0.8f, secondsForCharge);
        fuelLevel.DOLocalMoveY(0, secondsForCharge);

        float delta = 20;

        for (int i = 0; i < delta; i++)
        {
            rechargingLevel += 1f / delta;
            yield return new WaitForSeconds(secondsForCharge / delta);
        }

        rechargingLevel = 1f;
        fuelLevel.localScale = Vector3.one;
        fuelLevel.localPosition = Vector3.zero;

        isBarrelRecharging = false;
        isBarrelOverCharging = true;
    }

    private IEnumerator PlayOverChargingProcess()
    {
        Sequence seq = DOTween.Sequence();
        overChargeEffect.SetActive(true);
        seq.Append(fuelBarrel.DOShakeRotation(secondsForOverCharge + 1f, new Vector3(10f, 0, 10f), 10, 90, true));

        for (float i = 0; i < secondsForOverCharge; i+=0.1f)
        {
            if (isRechargerEmpty)
            {
                seq.Kill();
                overChargeEffect.SetActive(false);
                yield break;
            }
            yield return new WaitForSeconds(0.1f);
        }

        seq.Kill();
        overChargeEffect.SetActive(false);
    }

    private IEnumerator PlayExplosion()
    {
        
        explosion.SetActive(true);
        fuelBarrel.gameObject.SetActive(false);
        yield return new WaitForSeconds(0.2f);

        GameObject afterEffect = ObjectPooling.poisonPatchAfterBarrel_pool.GetObject();
        afterEffect.transform.position = new Vector3(transform.position.x - 0.5f, 0, transform.position.z);
        afterEffect.GetComponent<IncidentAfterEffect>().InitAfterEffect(ObjectPooling.poisonPatchAfterBarrel_pool, 6);

        GameObject afterEffect1 = ObjectPooling.poisonPatchAfterBarrel_pool.GetObject();
        afterEffect1.transform.position = new Vector3(transform.position.x + 0.5f, 0, transform.position.z);
        afterEffect1.GetComponent<IncidentAfterEffect>().InitAfterEffect(ObjectPooling.poisonPatchAfterBarrel_pool, 6);

        yield return new WaitForSeconds(0.8f);
        EmptyRecharger();

        
    }

    public bool ConsumeSupply(GameObject supply)
    {
        if (isRechargerEmpty)
        {
            supply.transform.SetParent(this.transform);
            supply.transform.localPosition = Vector3.one;
            supply.SetActive(false);
            ObjectPooling.ReturnSupply(supply);

            StartRechargingProcess();

            return true;
        }

        return false;
    }

    public SuppliesType GetFacilityConsumerSupplyType()
    {
        return currentSupplyToConsumeType;
    }

}
