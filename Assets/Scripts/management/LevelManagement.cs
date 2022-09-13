using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using DG.Tweening;
using System;

public class LevelManagement : MonoBehaviour
{
    public float MainGameTimer;
    public int ShipMaxHealth;
    public int ShipCurrentHealth;

    [SerializeField] private settings GeneralSettings;
    [SerializeField] private Transform cameraBody;
    [SerializeField] private Camera mainCam;
    [SerializeField] private Light directionalLight;
    
    private AudioManager audio;    

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
    private delegate void BaseIncidentHandler(float timer, ref int health);
    private BaseIncidentHandler PlayIncident;

    private Action<int> healthHandler;

    //ZONES
    private float[] incidentZone_fire;
    private float[] incidentZone_wreck;


    private void Start()
    {
        STORAGE = GameObject.Find("pool objects").transform;
        InitLevel();
    }

   
    private void Update()
    {
        MainGameTimer += Time.deltaTime;

        print(ShipCurrentHealth + " curr health");

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
        if (PlayIncident != null) PlayIncident(Time.deltaTime, ref ShipCurrentHealth);
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
        directionalLight.intensity = 1.3f;
        currentDirectionalLightIntensity = 1.3f;
        directionalLight.color = type1_directionalLight_Color;
        currentDirectionalLightColor = type1_directionalLight_Color;
        mainCam.backgroundColor = type1_cameraBackGround_Color;

        //ship and crew
        AddMainShip("small ship 1");
        AddCrewMember(CrewSpecialization.Captain, shipManager.GetPointOfRespForCrew(0));
        AddCrewMember(CrewSpecialization.Captain, shipManager.GetPointOfRespForCrew(1));
        ShipMaxHealth = 15;
        ShipCurrentHealth = ShipMaxHealth;

        //init objects
        ObjectPooling.InitPools(50, STORAGE);

        //start logic
        incidentZone_fire = new float[] { 0,0,  1,0,  -1,0,  0,1,  0,-1,  -1,-1,  1,1,  -1,1,  1,-1 };

        

        IncidentManager fireIncidentManager = new IncidentManager(IncidentsType.fire, 10, incidentZone_fire);
        PlayIncident += fireIncidentManager.UpdateState;
    }

















    public struct IncidentManager
    {
        private float interval, currentTime;
        private IncidentsType incident;
        private float[] zoneArray;
        private List<GameObject> incidentsGameObjects;

        public IncidentManager(IncidentsType _incident, float _interval, float [] data)
        {
            interval = _interval;
            incident = _incident;
            currentTime = 0;
            zoneArray = data;
            incidentsGameObjects = new List<GameObject>();
        }

        public void UpdateState(float deltaTime, ref int shipHealth)
        {
            currentTime += deltaTime;

            if (incidentsGameObjects.Count > 0)
            {
                for (int i = 0; i < incidentsGameObjects.Count; i++)
                {
                    if (!incidentsGameObjects[i].activeSelf)
                    {
                        shipHealth++;
                        incidentsGameObjects.Remove(incidentsGameObjects[i]);
                    }
                }
            }
            
            if (currentTime>=interval)
            {
                currentTime = 0;
                shipHealth--;
                GameObject _incident = ObjectPooling.AddIncidentGameObject(incident, GetCoordsForIncident());                
                incidentsGameObjects.Add(_incident);
            }
        }

        private Vector3 GetCoordsForIncident()
        {
            Vector3 result = Vector3.zero;
            float delta = 0.25f;

            switch(incident)
            {
                case IncidentsType.fire:
                    delta = 0.25f;
                    break;
            }

            int index = 0;

            for (int i = 0; i < 10; i++)
            {
                index = UnityEngine.Random.Range(0, zoneArray.Length);

                if (index % 2 == 0)
                {
                    break;
                }
            }

            result = new Vector3(zoneArray[index] + UnityEngine.Random.Range(-delta, delta), 0.01f, zoneArray[index + 1] + UnityEngine.Random.Range(-delta, delta));

            return result;
        }
    }
}


