using DG.Tweening;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.AI;
using UnityEngine.UI;

[RequireComponent(typeof(SphereCollider))]
public class Supply : MonoBehaviour, ITakenAndMovable, IHighlightable, IHealthDestroyable
{
    [SerializeField] private SuppliesType currentSupplyType;    
    [SerializeField] private float YCoordWhenThrownAway;
    [SerializeField] private SphereCollider currentCollider;
    [SerializeField] private Transform currentVisualTransform, currentTransform, UIPositionPoint;
    [SerializeField] private bool isCanBeTakenByCrew = false;
    [SerializeField] private settings GeneralSettings;
    [SerializeField] private float maxHealth;
    [SerializeField] private bool isDestroyable;

    //highlighting
    [SerializeField] private Material highlightMaterial;
    [SerializeField] private List<MeshRenderer> baseRenderersForHiglight = new List<MeshRenderer>();
    private List<Material> baseMaterialsForHiglight = new List<Material>();
    private bool isHighlightEffectInProgress;
    //===========

    //damage dealing
    private Dictionary<GameObject, DamageDealer> damagingObjects = new Dictionary<GameObject, DamageDealer>();
    private HashSet<NegativeEffects> activatedEffects = new HashSet<NegativeEffects>();
    //============

    //health bar UI
    private GameObject uiHealthBar;
    private RectTransform uiHealthBarRect;
    //=============

    private float modelAngle, health;
    private Vector3 modelStandartRotation, OnScreenPosition;
    private bool isShowingUIBar, isDestroyed;

    public float Health
    {
        get { return health; }

        set
        {
            if (value < 0)
            {
                health = 0;
            }
            else if (value >= maxHealth)
            {
                health = maxHealth;
                if (!isShowingUIBar) StartCoroutine(ShowUIBarWhileActive());
            }
            else
            {                
                health = value;
                if (!isShowingUIBar) StartCoroutine(ShowUIBarWhileActive());
            }

            if (health <= 0 && !isDestroyed)
            {
                isDestroyed = true;
                StartCoroutine(makeThisSupplyInactive());
            }
        }
    }



    private void Start()
    {
        for (int i = 0; i < baseRenderersForHiglight.Count; i++)
        {
            baseMaterialsForHiglight.Add(baseRenderersForHiglight[i].material);
        }      
    }


    private void OnEnable()
    {
        health = maxHealth;

        currentTransform = GetComponent<Transform>();
        if (isCanBeTakenByCrew) MakeThrownAway();
        modelStandartRotation = currentVisualTransform.localEulerAngles;

        if (isDestroyable)
        {
            if (uiHealthBarRect != null)
            {
                HideUI();
            }
            else
            {
                InitUI();
            }
        }        
            
    }

    public void InitUI()
    {
        uiHealthBar = Instantiate(UIManager.GetUIPrefab(UIPanelTypes.health_bar), GameObject.Find("MainCanvas").transform);
        uiHealthBarRect = uiHealthBar.GetComponent<RectTransform>();

        if (uiHealthBarRect.gameObject.activeSelf) uiHealthBarRect.gameObject.SetActive(false);
        GameManagement.MainUIHandler -= UpdateUIPosition;
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
            //currentCollider.enabled = false;
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

    /*
    private void OnTriggerEnter(Collider other)
    {
        if (isDestroyable && !damagingObjects.ContainsKey(other.gameObject) && other.gameObject.GetComponent<DamageDealer>() != null)
        {            
            damagingObjects.Add(other.gameObject, other.gameObject.GetComponent<DamageDealer>());
        }
    }


    private void OnTriggerExit(Collider other)
    {
        if (damagingObjects.ContainsKey(other.gameObject))
        {
            damagingObjects.Remove(other.gameObject);
        }
    }


    private void OnTriggerStay(Collider other)
    {
        if (isDestroyable && !damagingObjects.ContainsKey(other.gameObject) && other.gameObject.GetComponent<DamageDealer>() != null)
        {
            damagingObjects.Add(other.gameObject, other.gameObject.GetComponent<DamageDealer>());
        }

        //damage receiver
        if (isDestroyable && damagingObjects.ContainsKey(other.gameObject))
        {
            switch (damagingObjects[other.gameObject].GetNegativeEffect())
            {
                case NegativeEffects.burning:
                         
                    if (!activatedEffects.Contains(NegativeEffects.burning) && Vector3.Distance(other.gameObject.transform.position, currentTransform.position) <= 1.5f)
                    {                       
                        activatedEffects.Add(NegativeEffects.burning);
                        SetDamageEffect(damagingObjects[other.gameObject].GetDamageAmount());
                    }
                    break;

                case NegativeEffects.electricity:

                    break;
            }
        }
    }
    */

    private void SetDamageEffect(float amount) => StartCoroutine(PlayDamageEffect(amount));

    private IEnumerator PlayDamageEffect(float amount)
    {        
        float damageTime = 2f;


        
        for (float i = 0; i < damageTime; i += 0.1f)
        {
            DecreaseHealthAmount(amount / damageTime / 10f);
            
            yield return new WaitForSeconds(0.1f);
        }

        if (activatedEffects.Contains(NegativeEffects.burning)) activatedEffects.Remove(NegativeEffects.burning);
        
        yield return new WaitForSeconds(0.2f);        
    }

    public void DecreaseHealthAmount(float amount)
    {
        Health -= amount;
        //print(Health + " - supply");
        UpdateUIHealthData();
    }

    public void UpdateUIHealthData()
    {
        uiHealthBarRect.transform.GetChild(1).GetComponent<Image>().fillAmount = Health / maxHealth;
    }


    public void UpdateUIPosition(Camera camera)
    {
        if (uiHealthBarRect.gameObject.activeSelf)
        {
            OnScreenPosition = camera.WorldToScreenPoint(UIPositionPoint.position);
            uiHealthBarRect.anchoredPosition = new Vector2(OnScreenPosition.x, OnScreenPosition.y + 20);
        }
        else
        {
            GameManagement.MainUIHandler -= UpdateUIPosition;
            print("!!!!!!!!!!!");
        }
    }

    public void ShowUI()
    {
        if (!uiHealthBarRect.gameObject.activeSelf) uiHealthBarRect.gameObject.SetActive(true);
        GameManagement.MainUIHandler += UpdateUIPosition;
    }

    public void HideUI()
    {
        if (uiHealthBarRect.gameObject.activeSelf) uiHealthBarRect.gameObject.SetActive(false);
        GameManagement.MainUIHandler -= UpdateUIPosition;
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

    public bool IsDestroyable()
    {
        return isDestroyable;
    }

    public void PlayNegativeEffect(NegativeEffects _effect)
    {
        switch (_effect)
        {
            case NegativeEffects.burning:
                //Effects.GetChild(0).gameObject.SetActive(true);
                break;

            case NegativeEffects.electricity:

                break;
        }


    }
    public void StopNegativeEffect(NegativeEffects _effect)
    {
        switch (_effect)
        {
            case NegativeEffects.burning:
                //Effects.GetChild(0).gameObject.SetActive(false);
                break;

            case NegativeEffects.electricity:

                break;
        }
    }

    private IEnumerator makeThisSupplyInactive()
    {
        GameObject afterEffect = ObjectPooling.poisonPatchAfterBarrel_pool.GetObject();
        afterEffect.transform.position = new Vector3(currentTransform.position.x, 0, currentTransform.position.z);
        afterEffect.GetComponent<IncidentAfterEffect>().InitAfterEffect(ObjectPooling.poisonPatchAfterBarrel_pool, 4);

        HideUI();
        StopCoroutine(ShowUIBarWhileActive());

        yield return new WaitForSeconds(0.3f);

        HideUI();

        ObjectPooling.ReturnSupply(gameObject);        
    }

    public float CurrentHealthAmount()
    {
        return Health;
    }

}

