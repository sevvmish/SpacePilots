using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Unity.AI.Navigation;
using DG.Tweening;
using System;
using EZCameraShake;
using UnityEngine.AI;

[RequireComponent(typeof(AudioManager))]
public class GameManagement : MonoBehaviour
{
    [SerializeField] private settings GeneralSettings;
    [SerializeField] private Camera mainCam;
    [SerializeField] private Transform cameraBody;
    [SerializeField] private AudioManager audio;
    [SerializeField] private Light directionalLight;
    [SerializeField] private Joystick joystick;
    [SerializeField] private Material screenEffect;

    //colors for directional light
    private Color currentDirectionalLightColor;
    private float currentDirectionalLightIntensity;
    private Color type1_cameraBackGround_Color = new Color(26f/255f, 16f/255f, 43f/255f);
    private Color type1_directionalLight_Color = new Color(220f/255f, 202f/255f, 233f/255f);
    private Color type1_directionalLight_ColorPowerOff = new Color(138f/255f, 105f/255f, 162f/255f);
    private bool isEnergyOffColors;
    private CharacterController playerCharController;


    private Vector3 cameraDefaultBodyShift = Vector3.zero;
    private Vector3 cameraDefaultBodyAngle = new Vector3(65, 0, 0);

    private Vector3 CAMERA_SHIFT_CLOSE = new Vector3(0, 9.5f, -5f);    
    private Vector3 CAMERA_SHIFT_MEDIUM = new Vector3(0, 13f, -6.4f);

    //floating effect
    private bool isFloating;
    private bool isOneWay;
    private Action HandleShipFloatingEffect;
    private Vector3 floatingEffectVector = Vector3.zero;
    private float currentTimer = 4;
    private float floatKoeff = 1;
    private readonly float defaultTimer = 4;

    private Ray ray;
    private RaycastHit hit;

    //init level
    private Transform highlighter;
    private GameObject selectedGameObject;
    private Dictionary<GameObject, CrewManager> crewMembers = new Dictionary<GameObject, CrewManager>();
    private ShipManager shipManager;
    private Transform STORAGE;

    //crew UI delegates
    public delegate void BaseUIHandler(Camera camera);
    public static BaseUIHandler MainUIHandler;
        

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

        STORAGE = GameObject.Find("pool objects").transform;

        //init highlight and audio listener
        InitHighlightPlayer();
        levelDesign(GeneralSettings.CurrentLevel);

        makeScreenOn();

    }

    // Update is called once per frame
    void Update()
    {
        if (playerCharController != null)
        {
            if (Mathf.Abs(joystick.Horizontal) > 0 || Mathf.Abs(joystick.Vertical) > 0)
            {
                playerCharController.gameObject.GetComponent<NavMeshAgent>().ResetPath();
                playerCharController.transform.LookAt(playerCharController.transform.position + new Vector3(joystick.Horizontal, 0, joystick.Vertical));
                playerCharController.Move(playerCharController.transform.TransformDirection(Vector3.forward) * Time.deltaTime * 5);
            }
        }        
        

        //change light when power off, on
        if (shipManager.Energy<=0 && !isEnergyOffColors)
        {
            isEnergyOffColors = true;
            directionalLight.DOColor(type1_directionalLight_ColorPowerOff, 0.5f);
            directionalLight.DOIntensity(1.1f, 0.5f);
        }
        else if(shipManager.Energy > 0 && isEnergyOffColors)
        {
            isEnergyOffColors = false;
            directionalLight.DOColor(currentDirectionalLightColor, 0.5f);
            directionalLight.DOIntensity(currentDirectionalLightIntensity, 0.5f);
        }
        //===============================

        if (Input.GetKeyDown(KeyCode.O))
        {
            CameraShaker.Instance.ShakeOnce(5, 6, 2, 1);
        }

    


        if (Input.GetMouseButtonDown(0))
        {
            ray = mainCam.ScreenPointToRay(Input.mousePosition);

            if (Physics.Raycast(ray, out hit, 50))
            {
                
                if (hit.collider != null && !hit.collider.CompareTag("Floor"))
                {
                    //print(hit.collider.name);
                    audio.MakeClick();
                }
                

                
                if (hit.collider.GetComponent<CrewManager>() != null && selectedGameObject != hit.collider.gameObject)
                {
                    selectedGameObject = hit.collider.gameObject;
                    playerCharController = selectedGameObject.GetComponent<CharacterController>();

                    selectedGameObject.GetComponent<IHighlightable>().HighlightCurrentObject();
                    HighlightSelectedCrewMember(hit.collider.gameObject.transform);
                    audio.MakeClick();
                }
                else
                {
                    if (selectedGameObject!=null && selectedGameObject.GetComponent<CrewManager>() != null && selectedGameObject != hit.collider.gameObject)
                    {                        
                        IPointOfInteraction _point = hit.collider.gameObject.GetComponent<IPointOfInteraction>();
                        Vector3 pointToMove = _point == null ? hit.point : _point.GetPointOfInteraction();

                        crewMembers[selectedGameObject].MoveCrewMemberTo(pointToMove, hit.collider.gameObject);
                    }
                }
            }
        }


        //ship
        if (isFloating) HandleShipFloatingEffect?.Invoke();

        //crew UI
        if (MainUIHandler != null) MainUIHandler(mainCam);
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

    private void AddCrewMember(CrewSpecialization _spec, Vector3 location)
    {
        GameObject player = Instantiate(CrewManager.GetCrewPrefab(_spec), location, Quaternion.Euler(0, 0, 0), GameObject.Find("SpaceShip").transform);
        crewMembers.Add(player, player.GetComponent<CrewManager>());
        player.GetComponent<CrewManager>().SetRespawnPoint(location);
        player.GetComponent<CrewManager>().InitUI();
    }

    private void AddMainShip(string shipName)
    {
        GameObject ship = Instantiate(Resources.Load<GameObject>($"prefabs/ships/{shipName}"), new Vector3(0, 0, 0), Quaternion.Euler(0, 0, 0), GameObject.Find("SpaceShip").transform);
        ship.SetActive(true);
        shipManager = ship.GetComponent<ShipManager>();
        cameraDefaultBodyShift = CAMERA_SHIFT_CLOSE;
        floatKoeff = 1;

        //camera lookup===================
        cameraBody.position = cameraDefaultBodyShift;
        cameraBody.rotation = Quaternion.Euler(cameraDefaultBodyAngle);

        float angle = UnityEngine.Random.Range(-10f, 10f);
        
        cameraBody.position = new Vector3(cameraDefaultBodyShift.x + (angle / -10f), cameraDefaultBodyShift.y, cameraDefaultBodyShift.z);
        cameraDefaultBodyAngle = new Vector3(cameraDefaultBodyAngle.x, cameraDefaultBodyAngle.y + angle, cameraDefaultBodyAngle.z);

        isFloating = true;
        HandleShipFloatingEffect += MakeFloatingEffect;
    }

    private void MakeFloatingEffect()
    {        
        if (currentTimer > defaultTimer && isFloating)
        {            
            currentTimer = 0;
            
            if (isOneWay)
            {
                isOneWay = false;
                DOTween.To(() => floatingEffectVector, x => floatingEffectVector = x, new Vector3(UnityEngine.Random.Range(-2,3) * floatKoeff, 0, UnityEngine.Random.Range(-2, 3)) * floatKoeff, defaultTimer);
            }
            else
            {
                isOneWay = true;
                DOTween.To(() => floatingEffectVector, x => floatingEffectVector = x, new Vector3(0, 0, 0), defaultTimer);
            }
        }
        else if (currentTimer <= defaultTimer && isFloating)
        {
            currentTimer += Time.deltaTime;
            cameraBody.rotation = Quaternion.Euler(cameraDefaultBodyAngle + floatingEffectVector);
        }        
    }

    private void HighlightSelectedCrewMember(Transform crewMember)
    {
        highlighter.SetParent(crewMember);
        highlighter.gameObject.SetActive(true);
        highlighter.localPosition = Vector3.zero;
    }

    private void InitHighlightPlayer()
    {
        //highlighting player system
        GameObject player = Instantiate(Resources.Load<GameObject>("prefabs/highlight"), new Vector3(100,100,100), Quaternion.Euler(0, 0.03f, 0), GameObject.Find("SpaceShip").transform);
        highlighter = player.transform;
        highlighter.gameObject.SetActive(true);
        //highlighter.position = new Vector3(0, -1, 0);
        //============================
    }


    private void levelDesign(int level)
    {
        switch(level)
        {
            case 0:

                break;

            case 1: //small ship #1

                directionalLight.intensity = 1.4f;
                currentDirectionalLightIntensity = 1.4f;
                directionalLight.color = type1_directionalLight_Color;
                currentDirectionalLightColor = type1_directionalLight_Color;
                mainCam.backgroundColor = type1_cameraBackGround_Color;

                //ship and crew
                AddMainShip("small ship 1");
                AddCrewMember(CrewSpecialization.Captain, shipManager.GetPointOfRespForCrew(0));
                
                AddCrewMember(CrewSpecialization.Captain, shipManager.GetPointOfRespForCrew(1));

                //init objects
                ObjectPooling.InitPools(50, STORAGE);

                /*
                ObjectPooling.AddIncident(IncidentsType.fire, new Vector3(2.5f, 0, 4));
                ObjectPooling.AddIncident(IncidentsType.fire, new Vector3(2.5f, 0, 3));
                ObjectPooling.AddIncident(IncidentsType.fire, new Vector3(2.5f, 0, 2));
                ObjectPooling.AddIncident(IncidentsType.poison_patch, new Vector3(2.5f, 0, 0));

                ObjectPooling.AddIncident(IncidentsType.simple_wreck, new Vector3(-2f, 0, 2));
                ObjectPooling.AddIncident(IncidentsType.simple_wreck, new Vector3(-2f, 0, 4));
                */

                //GameObject o = Instantiate(Resources.Load<GameObject>("prefabs/ship parts/main facility/full fuel barrel producer"), new Vector3(-3.5f, 0, 3.5f), Quaternion.Euler(0, -45, 0), shipManager.mainShipTransform);
                                
                break;

            case 2:

                break;
        }


        
    }

    

}



