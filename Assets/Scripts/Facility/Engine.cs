using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using DG.Tweening;
using UnityEngine.UI;
using EZCameraShake;
using System;

public class Engine : MonoBehaviour, IPointOfInteraction, IHighlightable
{
    [SerializeField] private MeshRenderer termoRenderer;
    [SerializeField] private float temperatureDelta;
    [SerializeField] private float fireExtHardness = 0.75f;
    [SerializeField] private Transform pointOfInterestFROM, pointOfInterestTO, UIPositionPoint, overheatVisualEff, rotator;
    [SerializeField] private settings GeneralSettings;    
    [SerializeField] private Incident heatIncident;
    [SerializeField] private AudioSource startEngineSound, machinerySound;
    private AudioClip startSound, stopSound;

    [SerializeField] private Material highlightMaterial;
    [SerializeField] private List<MeshRenderer> baseRenderersForHiglight = new List<MeshRenderer>();
    private List<Material> baseMaterialsForHiglight = new List<Material>();
    private bool isHighlightEffectInProgress;

    private UIManager alertMark;

    private Action makeBlink;
    [SerializeField] private AudioSource alarmSound;
    private bool param1, param2, param3;

    private float energy = 0;
    private float rotatorAngle = 0;
    private float productivity = 1;
    private float temperature = 0;
    private float lastHeatTemperature = 0;
    private Material termoMaterial;
    private bool isOverHeatInProgress, isTooOverheated;
    

    public float Energy
    {
        get { return energy; }

        set
        {
            if (value <= 0 && energy>0)
            {
                playStopEngineSound();
            }
            else if(value > 0 && energy == 0 && Productivity>0)
            {
                playStartEngineSound();
            }


            if (value < 0)
            {
                energy = 0;
            }
            else if (value > 1)
            {
                energy = 1;
            }
            else
            {
                energy = value;
                SetEffectOfEnginesFlame();
            }
        }
    }

    public float Productivity
    {
        get { return productivity; }

        set
        {
            if (value <= 0 && productivity > 0)
            {
                playStopEngineSound();
            }
            else if (value > 0 && productivity == 0 && Energy > 0)
            {
                playStartEngineSound();
            }

            if (value < 0)
            {
                productivity = 0;
            }
            else if (value > 1)
            {
                productivity = 1;
            }
            else
            {
                productivity = value;

                SetEffectOfEnginesFlame();
            }
        }
    }

    public float Temperature
    {
        get { return temperature; }

        set
        {
            if (value < 0)
            {
                temperature = 0;
            }
            else if (value > 1)
            {
                temperature = 1;
            }
            else
            {
                if (temperature != value)
                {
                    temperature = value;
                    SetTermoEffect();
                    termoMaterial.SetFloat("koeff", temperature);
                }
            }

            if (temperature >= 0.99f && !isTooOverheated)
            {
                isTooOverheated = true;
                CancelBlinking();
                Productivity = 0;                
            }
            else if(!isTooOverheated)
            {
                Productivity = 1;
            }
            
            if (temperature > 0.67f)
            {
                if (!overheatVisualEff.gameObject.activeSelf) overheatVisualEff.gameObject.SetActive(true);
                //ShowUI();
                alertMark.ShowUI();
            }
            else
            {
                if (overheatVisualEff.gameObject.activeSelf) overheatVisualEff.gameObject.SetActive(false);
                if (!isTooOverheated) alertMark.HideUI();//HideUI();
            }

            
            if (temperature < 0.33f)
            {
                isTooOverheated = false;
                //HideUI();
                if (alertMark.IsUIEnabled) alertMark.HideUI();
                CancelBlinking();
            }
              

        }
    }

    

    public Transform[] EngineEffects;

    private void Start()
    {        
        termoMaterial = Instantiate(termoRenderer.material);        
        termoRenderer.material = termoMaterial;
        termoMaterial.SetFloat("koeff", 0);
        termoMaterial.SetColor("_Color", Color.blue * 2f);

        
        for (int i = 0; i < baseRenderersForHiglight.Count; i++)
        {
            baseMaterialsForHiglight.Add(baseRenderersForHiglight[i].material);
        }
    }


    private void OnEnable()
    {
        startSound = Resources.Load<AudioClip>("audio/sounds/ignition up");
        stopSound = Resources.Load<AudioClip>("audio/sounds/ignition down");
        machinerySound.enabled = false;

        if (EngineEffects.Length > 0)
        {
            for (int i = 0; i < EngineEffects.Length; i++)
            {
                EngineEffects[0].localScale = Vector3.zero;
            }
        }

        overheatVisualEff.gameObject.SetActive(false);
        heatIncident.InitUI();
        heatIncident.gameObject.SetActive(false);

        //icon of overheating
        alertMark = new UIManager(UIPositionPoint, UIPanelTypes.alert_mark, UIIconTypes.fire, Color.red, Color.white);

    }

   

    private void Update()
    {
        rotator.rotation = Quaternion.Euler(rotatorAngle, 0, -90);
        rotatorAngle += Time.deltaTime * Productivity * Energy * 100f;

        
        if (!isOverHeatInProgress)
        {
            Temperature += AssessTemperatureDelta();
        }
        else
        {
            heatIncident.IncidentHealth += AssessTemperatureDelta();
            if (heatIncident.IncidentHealth < lastHeatTemperature)
            {
                heatIncident.IncidentHealth += (lastHeatTemperature - heatIncident.IncidentHealth) * fireExtHardness;
            }
                        

            Temperature = heatIncident.IncidentHealth;

            lastHeatTemperature = heatIncident.IncidentHealth;

            if (Temperature <= 0.2f)
            {
                Temperature = 0;
                heatIncident.IncidentHealth = 0;                
                isOverHeatInProgress = false;                
            }
        }


        if (Temperature>=0.67f && !isOverHeatInProgress)
        {
            heatIncident.gameObject.SetActive(true);
            isOverHeatInProgress = true;
            heatIncident.SetMaxHealth(1, Temperature);
            lastHeatTemperature = 0;

            
            alertMark.IsBlinking = true;
            alertMark.IsLeaveEnabledAfterBlinking = true;

            makeBlink = makeBlinkOnLowCapacity;
        }

        makeBlink?.Invoke();

    }

    private void makeBlinkOnLowCapacity()
    {
        if (Temperature >= 0.9f && !param1)
        {
            param1 = true;
            //uiInformationMark.GetComponent<MakeActiveInTimer>().howLong = 0.15f;
            //uiInformationMark.GetComponent<MakeActiveInTimer>().whatInterval = 0.1f;
            alertMark.HowLongToBlink = 0.15f;
            alertMark.WhatIntervalToBlink = 0.1f;
            alarmSound.Play();
        }
        else if (Temperature >= 0.8f && !param2)
        {
            param2 = true;
            //uiInformationMark.GetComponent<MakeActiveInTimer>().howLong = 0.3f;
            //uiInformationMark.GetComponent<MakeActiveInTimer>().whatInterval = 0.15f;
            alertMark.HowLongToBlink = 0.3f;
            alertMark.WhatIntervalToBlink = 0.15f;
            alarmSound.Play();
        }
        else if (Temperature >= 0.67f && !param3)
        {
            param3 = true;
            //uiInformationMark.GetComponent<MakeActiveInTimer>().howLong = 0.5f;
            //uiInformationMark.GetComponent<MakeActiveInTimer>().whatInterval = 0.3f;
            alertMark.HowLongToBlink = 0.5f;
            alertMark.WhatIntervalToBlink = 0.3f;
            alarmSound.Play();
        }
    }

    private void CancelBlinking()
    {
        //uiInformationMark.GetComponent<MakeActiveInTimer>().enabled = false;
        alertMark.IsBlinking = false;

        makeBlink = null;
        param1 = param2 = param3 = false;
    }

    private float AssessTemperatureDelta()
    {
        float result = 0;

        if (Energy > 0.8f)
        {
            result = temperatureDelta * Time.deltaTime;
        }
        else if (Energy <= 0.8f && Energy > 0.5f)
        {
            result = temperatureDelta * Time.deltaTime * 0.6f;
        }
        else if (Energy <= 0.5f && Energy > 0.3f)
        {
            result = temperatureDelta * Time.deltaTime * 0.3f;
        }
        else if (Energy <= 0.3f)
        {
            result = temperatureDelta * Time.deltaTime * 0.1f;
        }
            
        return result;
    }


    private void SetEffectOfEnginesFlame()
    {
        if (EngineEffects.Length > 0)
        {
            for (int i = 0; i < EngineEffects.Length; i++)
            {
                EngineEffects[0].localScale =  Vector3.one * Productivity * Energy;
            }
        }
    }


    private void SetTermoEffect()
    {
        if (Temperature < 0.33f)
        {
            termoMaterial.SetColor("_Color", Color.cyan * 2f);
        }
        else if (Temperature >= 0.33f && temperature < 0.66f)
        {
            termoMaterial.SetColor("_Color", Color.yellow * 3f);
        }
        else if (Temperature >= 0.66f)
        {
            termoMaterial.SetColor("_Color", Color.red * 4f);
        }

    }

    public Vector3 GetPointOfInteraction()
    {
        return Vector3.Lerp(pointOfInterestFROM.position, pointOfInterestTO.position, UnityEngine.Random.Range(0.1f, 1f));
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

    private void playStartEngineSound()
    {
        startEngineSound.clip = startSound;
        startEngineSound.volume = 0.9f;
        startEngineSound.pitch = 0.7f;
        startEngineSound.Play();
        
        CameraShaker.Instance.ShakeOnce(3, 5, 0.2f, 1);

        machinerySound.enabled = true;
    }

    private void playStopEngineSound()
    {
        startEngineSound.clip = stopSound;
        startEngineSound.volume = 0.9f;
        startEngineSound.pitch = 0.5f;
        startEngineSound.Play();
        
        machinerySound.enabled = false;
    }
}
