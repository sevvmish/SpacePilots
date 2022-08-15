using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using DG.Tweening;


[RequireComponent(typeof(SphereCollider))]
public class Incident : MonoBehaviour, IPointOfInteraction, IUIBars, IHighlightable
{
    [SerializeField] private InstrumentsType whatInstrumentDealThisIncident;
    [SerializeField] private IncidentsType currentIncidentType;
    [SerializeField] private Transform pointOfInterestFROM, pointOfInterestTO, currentVisualTransform, UIPositionPoint, baseHighLight;
    [SerializeField] private float maxHealth;
    [SerializeField] private settings GeneralSettings;
    [SerializeField] private Material highlightMaterial;
    [SerializeField] private AudioSource audiosource;

    private Material baseMaterial;
    private bool isHighlightEffectInProgress;
    public bool isIncidentActive;

    private float health;

    //UI
    private GameObject uiProgressBar;
    private RectTransform uiProgressBarRect;
    private Vector3 OnScreenPosition;
    private bool isShowingUIBar;

    

    public float Health
    {
        get {return health;}

        set 
        {            

            if (value<0)
            {
                health = 0;
                StartCoroutine(makeThisIncidentInactive());
            }
            else if(value >= maxHealth)
            {
                health = maxHealth;
                if (!isShowingUIBar) StartCoroutine(ShowUIBarWhileActive());
            }      
            else
            {
                health = value;
                if (!isShowingUIBar) StartCoroutine(ShowUIBarWhileActive());
            }
        }
    }


    private void OnEnable()
    {
        audiosource = GetComponent<AudioSource>();
        audiosource.volume = GeneralSettings.AudioSourceVolume_incidents;

        if (baseMaterial == null) baseMaterial = Enums_n_Interfaces.GetBaseMaterial(baseHighLight);

        health = maxHealth;
        isIncidentActive = true;

        if (uiProgressBarRect == null)
        {
            InitUI();
        }
        else
        {
            HideUI();
        }        
    }


    private void InitUI()
    {
        uiProgressBar = Instantiate(UIManager.GetUIPrefab(UIPanelTypes.progress_bar), GameObject.Find("MainCanvas").transform);
        uiProgressBarRect = uiProgressBar.GetComponent<RectTransform>();
        GameManagement.MainUIHandler += UpdateUIPosition;

        HideUI();
    }



    public void ShowUI()
    {
        if (!uiProgressBarRect.gameObject.activeSelf) uiProgressBarRect.gameObject.SetActive(true);
    }


    public void HideUI()
    {
        if (uiProgressBarRect.gameObject.activeSelf) uiProgressBarRect.gameObject.SetActive(false);
    }

    public void UpdateUIData()
    {
        uiProgressBarRect.transform.GetChild(1).GetComponent<Image>().fillAmount = Health / maxHealth;
    }

    public void UpdateUIPosition(Camera camera)
    {
        if (uiProgressBarRect.gameObject.activeSelf)
        {
            OnScreenPosition = camera.WorldToScreenPoint(UIPositionPoint.position);
            uiProgressBarRect.anchoredPosition = new Vector2(OnScreenPosition.x, OnScreenPosition.y + 20);
        }        
    }


    public static GameObject GetIncidentPrefab(IncidentsType _incident)
    {
        GameObject result = default;

        switch (_incident)
        {
            case IncidentsType.tester:
                result = Resources.Load<GameObject>("prefabs/incidents/test fire");
                break;
            case IncidentsType.fire:
                result = Resources.Load<GameObject>("prefabs/incidents/fire incident");
                break;
            case IncidentsType.simple_wreck:
                result = Resources.Load<GameObject>("prefabs/incidents/simple wreck");
                break;
            case IncidentsType.smoke_after_fire:
                result = Resources.Load<GameObject>("prefabs/incidents/SmokeAfterFire");
                break;
            case IncidentsType.after_wreck:
                result = Resources.Load<GameObject>("prefabs/incidents/RepairAfterWreck");
                break;
        }

        return result;
    }


    public void DecreaseHealthAmount(float amount)
    {
        Health -= amount;
        //print(Health + " - incident");
        UpdateUIData();
    }


    public InstrumentsType GetInstrumentTypeToDealWithIncident()
    {
        return whatInstrumentDealThisIncident;
    }


    public Vector3 GetPointOfInteraction()
    {
        return Vector3.Lerp(pointOfInterestFROM.position, pointOfInterestTO.position, UnityEngine.Random.Range(0.1f, 1f));
    }


    public IEnumerator ShowUIBarWhileActive()
    {
        isShowingUIBar = true;
        ShowUI();
        yield return new WaitForSeconds(2);
        
        isShowingUIBar = false;

        yield return new WaitForSeconds(0.5f);
        if (!isShowingUIBar) HideUI();
    }

    private IEnumerator makeThisIncidentInactive()
    {
        GameObject afterEffect = default;

        switch (currentIncidentType)
        {
            case IncidentsType.fire:
                afterEffect = ObjectPooling.smokeAfterFire_pool.GetObject();                
                afterEffect.transform.position = transform.position;
                afterEffect.GetComponent<IncidentAfterEffect>().InitAfterEffect(ObjectPooling.smokeAfterFire_pool, 2);
                break;

            case IncidentsType.simple_wreck:
                afterEffect = ObjectPooling.repairAfterWreck.GetObject();                
                afterEffect.transform.position = transform.position;
                afterEffect.GetComponent<IncidentAfterEffect>().InitAfterEffect(ObjectPooling.repairAfterWreck, 3);
                break;
        }


        HideUI();
        GetComponent<Transform>().DOScale(Vector3.zero, 0.3f);
        yield return new WaitForSeconds(0.3f);
        GetComponent<Transform>().localScale = Vector3.one;
        HideUI();

        


        isIncidentActive = false;
        gameObject.SetActive(false);
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
