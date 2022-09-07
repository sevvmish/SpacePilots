using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using DG.Tweening;
using TMPro;

public class MenuManagement : MonoBehaviour
{
    [SerializeField] private settings GeneralSettings;
    [SerializeField] private Camera mainCam;
    [SerializeField] private Transform mainShip;

    private Ray ray;
    private RaycastHit hit;
    private Sequence sequence;
    private float shipSpeed = 0.7f;

    private bool isEngineEffectActive;

    //crew UI delegates
    public delegate void BaseUIHandler(Camera camera);
    public static BaseUIHandler MainUIHandler;

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

        if (SaveLoad.isDataSaved())
        {
            GeneralSettings.GameLevelsData = SaveLoad.Load();
        }


        turnOffEngineEffect();
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
                    
                    if (hit.collider.CompareTag("Supply"))
                    {
                        hit.collider.GetComponent<LevelMenuManager>().PlayHighlight();
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

    private void turnOnEngineEffect()
    {
        isEngineEffectActive = true;
        mainShip.GetChild(0).transform.GetChild(0).transform.DOScale(Vector3.one, 0.3f);
    }

    private void turnOffEngineEffect()
    {
        isEngineEffectActive = false;
        mainShip.GetChild(0).transform.GetChild(0).transform.DOScale(Vector3.zero, 0.3f);
    }

    private void OnApplicationQuit()
    {
        SaveLoad.Save(GeneralSettings.GameLevelsData);
    }

}
