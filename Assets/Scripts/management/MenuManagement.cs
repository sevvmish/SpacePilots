using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using DG.Tweening;
using TMPro;
using UnityEngine.UI;

public class MenuManagement : MonoBehaviour
{
    [SerializeField] private settings GeneralSettings;
    [SerializeField] private Camera mainCam;    
    [SerializeField] private Material screenEffect;

    private Transform mainShip;

    private Ray ray;
    private RaycastHit hit;
    private Sequence sequence;
    private float shipSpeed = 0.5f;

    private bool isEngineEffectActive;
    private AudioSource audio, shipAudio;
    private AudioClip goodClick, negativeClick, openAudio;

    //crew UI delegates
    public delegate void BaseUIHandler(Camera camera);
    public static BaseUIHandler MainUIHandler;
    public static LevelMenuManager currentLevel;
    private HashSet<LevelMenuManager> nearLevel = new HashSet<LevelMenuManager>();
    private UIManager levelUI;

    // Start is called before the first frame update
    void Start()
    {
        //screen set==============================================            
        Screen.SetResolution(GeneralSettings.ScreenWidth, GeneralSettings.ScreenHeight, true);
        Camera.main.aspect = GeneralSettings.AspectRatio;
        Application.targetFrameRate = GeneralSettings.targetFrameRate;

#if (UNITY_EDITOR)
        Camera.main.aspect = 16f/9f;
#endif
        audio = GetComponent<AudioSource>();
        goodClick = Resources.Load<AudioClip>("audio/sounds/bonus sound short");
        negativeClick = Resources.Load<AudioClip>("audio/sounds/negative click");
        openAudio = Resources.Load<AudioClip>("audio/sounds/grab something");

        //small ship
        GameObject mainShipGameObject = Instantiate(Resources.Load<GameObject>("prefabs/ships/menu main ship 1"));
        mainShip = mainShipGameObject.transform;
        mainShip.position = Vector3.zero;
        shipAudio = mainShip.GetChild(1).GetComponent<AudioSource>();
        turnOffEngineEffect();
        //==================================


        if (SaveLoad.isDataSaved())
        {
            GeneralSettings.GameLevelsData = SaveLoad.Load();
        }

        makeScreenOn();

        
    }

    // Update is called once per frame
    void Update()
    {
        if (Input.GetMouseButtonDown(0))
        {
            ray = mainCam.ScreenPointToRay(Input.mousePosition);

            if (Physics.Raycast(ray, out hit, 50))
            {
                if (hit.collider.CompareTag("Floor") || hit.collider.CompareTag("Supply"))
                {
                    sequence.Kill();
                    sequence = DOTween.Sequence();
                    sequence.Append(mainShip.DOMove(hit.point, Vector3.Distance(hit.point, mainShip.position) * shipSpeed));
                    sequence.Join(mainShip.DOLookAt(hit.point, 0.3f));
                    
                    if (hit.collider.TryGetComponent(out LevelMenuManager _level))
                    {
                        if (currentLevel != _level)
                        {
                            currentLevel?.StopHighlight();
                            _level.PlayHighlight();
                            currentLevel = _level;
                        }
                            
                        if (GeneralSettings.GameLevelsData[_level.LevelNumber].StarsRequiredToEnter > GeneralSettings.CurrentStars)
                        {
                            audio.clip = negativeClick;
                            audio.Play();
                        }
                        else
                        {
                            audio.clip = goodClick;
                            audio.Play();
                        }
                    }
                    else
                    {
                        currentLevel?.StopHighlight();
                        currentLevel = null;
                    }

                }
                
            }
        }

        if (Input.GetKeyDown(KeyCode.S))
        {
            for (int i = 0; i < GeneralSettings.GameLevelsData.Length; i++)
            {
                GeneralSettings.GameLevelsData[i].IsVisited = false;
                GeneralSettings.GameLevelsData[i].CurrentStarsProgress = 0;
            }

            SaveLoad.Save(GeneralSettings.GameLevelsData);
        }

        //engine effect for ship
        if (sequence.IsActive() && !isEngineEffectActive)
        {
            turnOnEngineEffect();
        }
        else if (!sequence.IsActive() && isEngineEffectActive)
        {
            turnOffEngineEffect();
        }

        //crew UI
        if (MainUIHandler != null) MainUIHandler(mainCam);
    }

    public void PlayGoodClick()
    {
        audio.clip = goodClick;
        audio.Play();
    }

    public void PlayNegativeClick()
    {
        audio.clip = negativeClick;
        audio.Play();
    }

    public void PlayOpenClick()
    {
        audio.clip = openAudio;
        audio.Play();
    }

    public void makeScreenOff()
    {
        GameObject.Find("screen effect canvas").transform.GetChild(0).gameObject.SetActive(true);
        screenEffect.DOFloat(0, "_slider", 0);
        screenEffect.DOFloat(1, "_slider", 1);
    }

    public void makeScreenOn()
    {
        GameObject.Find("screen effect canvas").transform.GetChild(0).gameObject.SetActive(true);
        screenEffect.DOFloat(1, "_slider", 0);
        screenEffect.DOFloat(0, "_slider", 1);
        Invoke("ScreenObjectOff", 1);
    }

    public void ScreenObjectOff()
    {
        GameObject.Find("screen effect canvas").transform.GetChild(0).gameObject.SetActive(false);
    }

    private void turnOnEngineEffect()
    {
        if (!shipAudio.isPlaying) shipAudio.Play();
        isEngineEffectActive = true;
        mainShip.GetChild(1).transform.DOScale(Vector3.one, 0.3f);
    }

    private void turnOffEngineEffect()
    {
        shipAudio.Stop();
        isEngineEffectActive = false;
        mainShip.GetChild(1).transform.DOScale(Vector3.zero, 0.3f);
    }

    private void OnApplicationQuit()
    {
        SaveLoad.Save(GeneralSettings.GameLevelsData);
    }
        

}
