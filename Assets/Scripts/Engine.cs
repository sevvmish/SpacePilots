using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using DG.Tweening;
using UnityEngine.UI;

public class Engine : MonoBehaviour, IPointOfInteraction, IHighlightable
{
    [SerializeField] private MeshRenderer termoRenderer;
    [SerializeField] private float temperatureDelta;
    [SerializeField] private float fireExtHardness = 0.75f;
    [SerializeField] private Transform pointOfInterestFROM, pointOfInterestTO, UIPositionPoint;
    [SerializeField] private settings GeneralSettings;    
    [SerializeField] private Incident heatIncident;


    [SerializeField] private Material highlightMaterial;
    [SerializeField] private List<MeshRenderer> baseRenderersForHiglight = new List<MeshRenderer>();
    private List<Material> baseMaterialsForHiglight = new List<Material>();
    private bool isHighlightEffectInProgress;


    //UI information mark
    private GameObject uiInformationMark;
    private RectTransform uiInformationMarkRect;
    private Vector3 OnScreenPosition;


    private float energy = 0;
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
                temperature = value;
                
                SetTermoEffect();
                termoMaterial.SetFloat("koeff", temperature);
            }

            if (temperature >= 0.99f)
            {
                isTooOverheated = true;
                Productivity = 0;                
            }
            else if(!isTooOverheated)
            {
                Productivity = 1;
            }
            
            if (temperature > 0.67f)
            {
                ShowUI();
            }
            else
            {
                if (!isTooOverheated) HideUI();
            }

            if (temperature < 0.33f)
            {
                isTooOverheated = false;
                HideUI();
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
        if (EngineEffects.Length > 0)
        {
            for (int i = 0; i < EngineEffects.Length; i++)
            {
                EngineEffects[0].localScale = Vector3.zero;
            }
        }

        heatIncident.InitUI();
        heatIncident.gameObject.SetActive(false);

        //icon of overheating
        uiInformationMark = Instantiate(UIManager.GetUIPrefab(UIPanelTypes.information_mark), GameObject.Find("MainCanvas").transform);
        uiInformationMark.transform.GetChild(1).GetComponent<Image>().sprite = UIManager.GetUIIconSprite(UIIconTypes.fire);
        uiInformationMark.transform.GetChild(1).GetComponent<Image>().color = Color.red;
        uiInformationMarkRect = uiInformationMark.GetComponent<RectTransform>();        
        HideUI();
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



    private void Update()
    {
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
        }
    
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
            //Temperature += temperatureDelta * 0;
        }
            
        return result;
    }


    private void SetEffectOfEnginesFlame()
    {
        if (EngineEffects.Length > 0)
        {
            for (int i = 0; i < EngineEffects.Length; i++)
            {
                EngineEffects[0].localScale = Vector3.one * Productivity * Energy;
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
            baseRenderersForHiglight[i].transform.DOShakeScale(GeneralSettings.TimeForShakeForFacility, GeneralSettings.StrenghtOfShakeOnHighlightingFacility, 10, 90, true);
        }
        
        yield return new WaitForSeconds(GeneralSettings.TimeForShakeForFacility);
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
}
