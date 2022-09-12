using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using DG.Tweening;


[RequireComponent(typeof(SphereCollider))]
public class Incident : MonoBehaviour, IPointOfInteraction, IHighlightable
{
    
    public bool isIncidentActive;

    [SerializeField] private InstrumentsType whatInstrumentDealThisIncident;
    [SerializeField] private IncidentsType currentIncidentType;
    [SerializeField] private Transform pointOfInterestFROM, pointOfInterestTO, currentVisualTransform, UIPositionPoint, baseHighLight;    
    [SerializeField] private settings GeneralSettings;
    [SerializeField] private Material highlightMaterial;
    [SerializeField] private AudioSource audiosource;

    private float maxHealth;
    private Material baseMaterial;
    private bool isHighlightEffectInProgress, isInActivated;
    private float health;
    private int timesToShowHealthBar = 0;

    //UI
    private GameObject uiProgressBar;
    private RectTransform uiProgressBarRect;
    private Vector3 OnScreenPosition;
    private bool isShowingUIBar;

    

    public float IncidentHealth
    {
        get {return health;}

        set 
        {            

            if (value<0)
            {
                health = 0;
                isInActivated = true;
                StartCoroutine(makeThisIncidentInactive());
            }
            else if(value >= maxHealth)
            {
                health = maxHealth;
                timesToShowHealthBar = 0;
            }      
            else
            {
                if (value < health)
                {
                    timesToShowHealthBar++;
                    if (timesToShowHealthBar>2 && !isShowingUIBar) StartCoroutine(ShowUIBarWhileActive());
                }

                health = value;
                
            }
        }
    }


    private void OnEnable()
    {       
        if (audiosource!= null)
        {
            audiosource = GetComponent<AudioSource>();
            audiosource.volume = GeneralSettings.AudioSourceVolume_incidents;
        }
        

        if (baseHighLight != null)
        {
            if (baseMaterial == null) baseMaterial = Highlighting.GetBaseMaterial(baseHighLight);
        }

        timesToShowHealthBar = 0;

        switch(currentIncidentType)
        {
            case IncidentsType.fire:
                maxHealth = GeneralSettings.IncidentBaseHealth_fire * GeneralSettings.IncidentHealthKoeff_fire;
                break;

            case IncidentsType.simple_wreck:
                maxHealth = GeneralSettings.IncidentBaseHealth_wreck * GeneralSettings.IncidentHealthKoeff_wreck;
                break;
        }

        health = maxHealth;
        isIncidentActive = true;

        if (uiProgressBarRect == null)
        {
            InitUI();
        }
        else
        {
            uiProgressBarRect.gameObject.SetActive(false);
            GameManagement.MainUIHandler -= UpdateUIPosition;
        }        
    }


    private void Update()
    {
        if (IncidentHealth < maxHealth && !isInActivated)
        {
            IncidentHealth += Time.deltaTime / 10f;
        }
    }

    public void SetMaxHealth(float max_health, float _health)
    {
        maxHealth = max_health;
        IncidentHealth = _health;
    }

    public void InitUI()
    {        
        uiProgressBar = Instantiate(UIManager.GetUIPrefab(UIPanelTypes.round_progress_bar), GameObject.Find("MainCanvas").transform);
        uiProgressBarRect = uiProgressBar.GetComponent<RectTransform>();

        uiProgressBarRect.gameObject.SetActive(false);
        GameManagement.MainUIHandler -= UpdateUIPosition;
    }

  
    public void ShowUI()
    {
        if (!uiProgressBarRect.gameObject.activeSelf)
        {
            uiProgressBarRect.gameObject.SetActive(true);
            GameManagement.MainUIHandler += UpdateUIPosition;
        }
            
    }


    public void HideUI()
    {
        if (uiProgressBarRect.gameObject.activeSelf)
        {
            uiProgressBarRect.gameObject.SetActive(false);
            GameManagement.MainUIHandler -= UpdateUIPosition;
        }
            
        
    }

    public void UpdateUIHealthData()
    {
        uiProgressBarRect.transform.GetChild(1).GetComponent<Image>().fillAmount = IncidentHealth / maxHealth;
    }

    public void UpdateUIPosition(Camera camera)
    {
        if (uiProgressBarRect.gameObject.activeSelf)
        {
            OnScreenPosition = camera.WorldToScreenPoint(UIPositionPoint.position);
            uiProgressBarRect.anchoredPosition = new Vector2(OnScreenPosition.x, OnScreenPosition.y);
            UpdateUIHealthData();
        }   
        else
        {
            GameManagement.MainUIHandler -= UpdateUIPosition;
            print("!!!!!!!!");
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
            case IncidentsType.poison_patch:
                result = Resources.Load<GameObject>("prefabs/incidents/PoisonPatch");
                break;
            case IncidentsType.death:
                result = Resources.Load<GameObject>("prefabs/incidents/death effect");
                break;
        }

        return result;
    }


    public void DecreaseHealthAmount(float amount)
    {
        IncidentHealth -= amount;
        //print(IncidentHealth + " - incident");
        
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
       
        

        for (float i = 0; i < 2f; i+=0.1f)
        {
            ShowUI();

            if (isInActivated)
            {
                HideUI();
                yield break;
            }

            yield return new WaitForSeconds(0.1f);
        }

        
        isShowingUIBar = false;

        yield return new WaitForSeconds(0.5f);
        if (!isShowingUIBar) HideUI();
    }

    private IEnumerator makeThisIncidentInactive()
    {    
        GameObject afterEffect = default;

        switch (currentIncidentType)
        {
            case IncidentsType.none:
                
                break;

            case IncidentsType.fire:
                afterEffect = ObjectPooling.smokeAfterFire_pool.GetObject();                
                afterEffect.transform.position = transform.position;
                afterEffect.GetComponent<IncidentAfterEffect>().InitAfterEffect(ObjectPooling.smokeAfterFire_pool, 3);
                break;

            case IncidentsType.simple_wreck:
                afterEffect = ObjectPooling.repairAfterWreck_pool.GetObject();                
                afterEffect.transform.position = transform.position;
                afterEffect.GetComponent<IncidentAfterEffect>().InitAfterEffect(ObjectPooling.repairAfterWreck_pool, 3);
                break;
        }

        HideUI();
        StopCoroutine(ShowUIBarWhileActive());
        GetComponent<Transform>().DOScale(Vector3.zero, 0.3f);
        yield return new WaitForSeconds(0.3f);
        GetComponent<Transform>().localScale = Vector3.one;
        HideUI();

        isIncidentActive = false;
        gameObject.SetActive(false);
    }

    public void HighlightCurrentObject()
    {
        if (!isHighlightEffectInProgress && baseHighLight != null) StartCoroutine(HandleCurrentHighlight());
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
