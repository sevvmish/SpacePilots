using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using DG.Tweening;
using System;

public class LevelManagement : MonoBehaviour
{
    public float MainGameTimer;
    
    [SerializeField] private settings GeneralSettings;
    [SerializeField] private Transform cameraBody;
    [SerializeField] private Camera mainCam;
    [SerializeField] private Light directionalLight;
    [SerializeField] private Light secondDirectionalLight;

    private AudioManager audio;    

    //colors for directional light
    private Color currentDirectionalLightColor;
    private float currentDirectionalLightIntensity;
    private Color type1_cameraBackGround_Color = new Color(26f / 255f, 16f / 255f, 43f / 255f);
    private Color type1_directionalLight_Color = new Color(220f / 255f, 202f / 255f, 233f / 255f);
    private Color type1_directionalLight_ColorPowerOff = new Color(138f / 255f, 105f / 255f, 162f / 255f);
    private bool isEnergyOffColors;
    private float timeForOnOff = 1f;

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

        //print(ShipCurrentHealth + " curr health");

        //change light when power off, on
        if (shipManager.Energy <= 0 && !isEnergyOffColors)
        {
            isEnergyOffColors = true;
            directionalLight.DOColor(type1_directionalLight_ColorPowerOff, timeForOnOff);
            directionalLight.DOIntensity(0.5f, timeForOnOff);
            secondDirectionalLight.gameObject.SetActive(false);
        }
        else if (shipManager.Energy > 0 && isEnergyOffColors)
        {
            isEnergyOffColors = false;
            directionalLight.DOColor(currentDirectionalLightColor, timeForOnOff);
            directionalLight.DOIntensity(currentDirectionalLightIntensity, timeForOnOff);
            secondDirectionalLight.gameObject.SetActive(true);
        }
        //===============================

        //ship floating
        if (isFloating) HandleShipFloatingEffect?.Invoke();

        //incident play
        if (PlayIncident != null) PlayIncident(Time.deltaTime, ref shipManager.ShipCurrentHealth);
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
        player.transform.rotation = Quaternion.Euler(0, 180, 0);
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
        //light and cameras
        directionalLight.intensity = 1.3f;
        currentDirectionalLightIntensity = 1.3f;
        directionalLight.color = type1_directionalLight_Color;
        currentDirectionalLightColor = type1_directionalLight_Color;
        mainCam.backgroundColor = type1_cameraBackGround_Color;

        //ship and crew
        AddMainShip("small ship 1");
        AddCrewMember(CrewSpecialization.Captain, shipManager.GetPointOfRespForCrew(0));
        AddCrewMember(CrewSpecialization.Captain, shipManager.GetPointOfRespForCrew(1));
        shipManager.ShipMaxHealth = 15;
        shipManager.ShipCurrentHealth = shipManager.ShipMaxHealth;

        //init objects and facility===================================================
        ObjectPooling.InitPools(50, STORAGE);
        
        //reactor        
        AddFacility(FacilityObject.Reactor_1, new Vector3(-3.2f, 0, -3.4f), new Vector3(0, -30, 0));
        for (int i = 0; i < shipManager.ShipReactors.Count; i++)
        {
            shipManager.ShipReactors[i].SetReactorStartFromLoaded(0.5f);
        }
          
        //recharger        
        AddFacility(FacilityObject.fuel_recharger, new Vector3(2.5f, 0, 3.5f), new Vector3(0, 0, 0));
        
        //empty fuel barrel        
        AddFacility(FacilityObject.empty_fuel_barrel_producer1, new Vector3(-3.5f, 0, 3.8f), new Vector3(0, -20, 0));

        //fire ext & wrench
        AddFacility(FacilityObject.fire_extinguisher, new Vector3(2f, 0.5f, -2f));
        AddFacility(FacilityObject.wrench, new Vector3(2f, 0.5f, -3.5f));

        //exact parts
        GameObject part = Instantiate(Resources.Load<GameObject>("prefabs/ship parts/exact level constructions/level1 main separator"), new Vector3(-0.5f, 0, 0), Quaternion.Euler(Vector3.zero), shipManager.mainShipTransform);
        incidentZone_fire = new float[] { -2, 0, -2, 1, -2, 2, -2, 3, -3, 2, -4, 2, -3, 1, -4, 1, -3, 0, -4, 0, -2, -1, -3, -1, -4, -1, -2, -2, -3, -2, -4, -2, -2, -3, 1, 0, 1, 1, 1, 2, 1, 3, 1, -1, 1, -2, 1, -3, 2, 0, 2, 1, 2, 2, 2, -1, 2, -2, 2, -3, 3, 0, 3, 1, 3, 2, 3, -1, 3, -2, 3, -3, 4, 0, 4, 1, 4, -1};
        incidentZone_wreck = new float[] { -2, 0, -2, 1, -2, 2, -2, 3, -3, 2, -3, 1, -4, 1, -3, 0, -4, 0, -2, -1, -3, -1, -4, -1, -2, -2, -3, -2, -2, -3, 1, 0, 1, 1, 1, 2, 1, 3, 1, -1, 1, -2, 1, -3, 2, 0, 2, 1, 2, 2, 2, -1, 2, -2, 3, 0, 3, 1, 3, -1, 4, 0 };


        //start logic
        IncidentManager fireIncidentManager = new IncidentManager(IncidentsType.fire, 10, 2, incidentZone_fire);
        PlayIncident += fireIncidentManager.UpdateState;

        IncidentManager wreckIncidentManager = new IncidentManager(IncidentsType.simple_wreck, 15, 5, incidentZone_wreck);
        PlayIncident += wreckIncidentManager.UpdateState;
    }

















    public struct IncidentManager
    {
        private float interval, currentTime;
        private IncidentsType incident;
        private float[] zoneArray;
        private List<GameObject> incidentsGameObjects;

        public IncidentManager(IncidentsType _incident, float _interval, float startDelay, float [] data)
        {
            interval = _interval;
            incident = _incident;
            currentTime = startDelay;
            zoneArray = data;

            if (data.Length % 2 != 0) print("erroê in number of incident points");

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

    private void AddFacility(FacilityObject facility, Vector3 position)
    {
        AddFacility(facility, position, Vector3.zero);
    }

    private void AddFacility(FacilityObject facility)
    {
        AddFacility(facility, Vector3.zero, Vector3.zero);
    }


    private void AddFacility(FacilityObject facility, Vector3 position, Vector3 angle)
    {
        GameObject facilityObject = default;

        switch(facility)
        {
            case FacilityObject.empty_fuel_barrel_producer:
                facilityObject = Instantiate(Resources.Load<GameObject>("prefabs/ship parts/main facility/empty fuel barrel producer"), position, Quaternion.Euler(angle), shipManager.mainShipTransform);
                break;

            case FacilityObject.empty_fuel_barrel_producer1:
                facilityObject = Instantiate(Resources.Load<GameObject>("prefabs/ship parts/main facility/empty fuel barrel producer 1"), position, Quaternion.Euler(angle), shipManager.mainShipTransform);
                break;

            case FacilityObject.Engine_1:
                facilityObject = Instantiate(Resources.Load<GameObject>("prefabs/ship parts/main facility/Engine 1"), position, Quaternion.Euler(angle), shipManager.mainShipTransform);
                shipManager.ShipEngines.Add(facilityObject.GetComponent<Engine>());
                break;

            case FacilityObject.fire_extinguisher_producer:
                facilityObject = Instantiate(Resources.Load<GameObject>("prefabs/ship parts/main facility/fire extinguisher producer"), position, Quaternion.Euler(angle), shipManager.mainShipTransform);
                break;

            case FacilityObject.fuel_recharger:
                facilityObject = Instantiate(Resources.Load<GameObject>("prefabs/ship parts/main facility/fuel recharger"), position, Quaternion.Euler(angle), shipManager.mainShipTransform);
                break;

            case FacilityObject.full_fuel_barrel_producer:
                facilityObject = Instantiate(Resources.Load<GameObject>("prefabs/ship parts/main facility/full fuel barrel producer"), position, Quaternion.Euler(angle), shipManager.mainShipTransform);
                break;

            case FacilityObject.Reactor_1:
                facilityObject = Instantiate(Resources.Load<GameObject>("prefabs/ship parts/main facility/Reactor 1"), position, Quaternion.Euler(angle), shipManager.mainShipTransform);
                shipManager.ShipReactors.Add(facilityObject.GetComponent<Reactor>());
                break;

            case FacilityObject.space_control_point01:
                facilityObject = Instantiate(Resources.Load<GameObject>("prefabs/ship parts/main facility/space control point01"), position, Quaternion.Euler(angle), shipManager.mainShipTransform);
                shipManager.AllMonitorsAndElectrics.Add(facilityObject);
                break;

            case FacilityObject.transceiver_1:
                facilityObject = Instantiate(Resources.Load<GameObject>("prefabs/ship parts/main facility/transceiver 1"), position, Quaternion.Euler(angle), shipManager.mainShipTransform);
                break;

            case FacilityObject.moving_effect_particles:
                facilityObject = Instantiate(Resources.Load<GameObject>("prefabs/effects/moving effect - particles"), position, Quaternion.Euler(angle), shipManager.mainShipTransform);                
                shipManager.MovingEffects.Add(facilityObject.GetComponent<ParticleSystem>());
                break;

            case FacilityObject.fire_extinguisher:
                facilityObject = Instantiate(Resources.Load<GameObject>("prefabs/instruments/fire extinguisher"), position, Quaternion.Euler(angle), shipManager.mainShipTransform);
                facilityObject.GetComponent<Instrument>().MakeThrownAway();                
                break;

            case FacilityObject.wrench:
                facilityObject = Instantiate(Resources.Load<GameObject>("prefabs/instruments/wrench"), position, Quaternion.Euler(angle), shipManager.mainShipTransform);
                facilityObject.GetComponent<Instrument>().MakeThrownAway();                
                break;
        }
    }


}

public enum FacilityObject
{
    empty_fuel_barrel_producer,
    empty_fuel_barrel_producer1,
    Engine_1,
    fire_extinguisher_producer,
    fuel_recharger,
    full_fuel_barrel_producer,
    Reactor_1,
    space_control_point01,
    transceiver_1,
    moving_effect_particles,
    fire_extinguisher,
    wrench
}


