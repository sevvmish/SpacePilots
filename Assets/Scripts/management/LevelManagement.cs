using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using DG.Tweening;
using System;

public class LevelManagement : MonoBehaviour
{
    [SerializeField] private settings GeneralSettings;
    [SerializeField] private Transform cameraBody;
    [SerializeField] private Camera mainCam;
    [SerializeField] private Light directionalLight;
    
    private AudioManager audio;
    private float gameTimer;

    //colors for directional light
    private Color currentDirectionalLightColor;
    private float currentDirectionalLightIntensity;
    private Color type1_cameraBackGround_Color = new Color(26f / 255f, 16f / 255f, 43f / 255f);
    private Color type1_directionalLight_Color = new Color(220f / 255f, 202f / 255f, 233f / 255f);
    private Color type1_directionalLight_ColorPowerOff = new Color(138f / 255f, 105f / 255f, 162f / 255f);
    private bool isEnergyOffColors;

    //camera details
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

    //ship and crew
    public Dictionary<GameObject, CrewManager> crewMembers = new Dictionary<GameObject, CrewManager>();
    private ShipManager shipManager;
    private Transform STORAGE;

    //incidents handling
    public delegate void BaseIncidentHandler(float timer);
    public static BaseIncidentHandler PlayIncident;

    private void Start()
    {
        STORAGE = GameObject.Find("pool objects").transform;
        InitLevel();
    }

   
    private void Update()
    {
        gameTimer += Time.deltaTime;

        //change light when power off, on
        if (shipManager.Energy <= 0 && !isEnergyOffColors)
        {
            isEnergyOffColors = true;
            directionalLight.DOColor(type1_directionalLight_ColorPowerOff, 0.5f);
            directionalLight.DOIntensity(1.1f, 0.5f);
        }
        else if (shipManager.Energy > 0 && isEnergyOffColors)
        {
            isEnergyOffColors = false;
            directionalLight.DOColor(currentDirectionalLightColor, 0.5f);
            directionalLight.DOIntensity(currentDirectionalLightIntensity, 0.5f);
        }
        //===============================

        //ship floating
        if (isFloating) HandleShipFloatingEffect?.Invoke();

        //incident play
        if (PlayIncident != null) PlayIncident(Time.deltaTime);
    }


    private void MakeFloatingEffect()
    {
        if (currentTimer > defaultTimer && isFloating)
        {
            currentTimer = 0;

            if (isOneWay)
            {
                isOneWay = false;
                DOTween.To(() => floatingEffectVector, x => floatingEffectVector = x, new Vector3(UnityEngine.Random.Range(-2, 3) * floatKoeff, 0, UnityEngine.Random.Range(-2, 3)) * floatKoeff, defaultTimer);
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


    public void InitLevel()
    {
        switch(GeneralSettings.CurrentLevel)
        {
            case 1:
                level_1();
                break;
        }
    }

    private void level_1()
    {        
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

        //start logic

        IncidentManager i = new IncidentManager(IncidentsType.fire, 10);
        PlayIncident += i.play;
    }

















    public struct IncidentManager
    {
        private float interval, currentTime;
        private IncidentsType incident;

        public IncidentManager(IncidentsType _incident, float _interval)
        {
            interval = _interval;
            incident = _incident;
            currentTime = 0;
        }

        public void play(float deltaTime)
        {
            currentTime += deltaTime;
            
            if (currentTime>=interval)
            {
                currentTime = 0;
                ObjectPooling.AddIncident(incident, new Vector3(UnityEngine.Random.Range(-2f, 2f), 0, UnityEngine.Random.Range(-2f, 2f)));
            }
        }
    }
}


