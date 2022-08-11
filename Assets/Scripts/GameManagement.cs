using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Unity.AI.Navigation;
using DG.Tweening;
using System;
using EZCameraShake;


[RequireComponent(typeof(AudioManager))]
public class GameManagement : MonoBehaviour
{
    [SerializeField] private settings GeneralSettings;
    [SerializeField] private Camera mainCam;
    [SerializeField] private Transform cameraBody;
    [SerializeField] private AudioManager audio;
    

    private Vector3 cameraDefaultBodyShift = Vector3.zero;
    private Vector3 cameraDefaultBodyAngle = new Vector3(65, 0, 0);

    private Vector3 CAMERA_SHIFT_CLOSE = new Vector3(0, 11f, -5.5f);    
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


    //crew UI delegates
    public delegate void BaseUIHandler(Camera camera);
    public static BaseUIHandler MainUIHandler;

    //incidents
    private ObjectPooling fireIncident_pool, simpleWreckIncident_pool, fireExtInstrument_pool, simpleRepairerInstrument_pool;
    


    // Start is called before the first frame update
    void Start()
    {
        //screen set==============================================            
        Screen.SetResolution(GeneralSettings.ScreenWidth, GeneralSettings.ScreenHeight, true);
        Camera.main.aspect = GeneralSettings.AspectRatio;
        //Application.targetFrameRate = GeneralSettings.targetFrameRate;

#if (UNITY_EDITOR)
        Camera.main.aspect = 16f/9f;
#endif

        //init highlight and audio listener
        InitHighlightPlayer();

        //ship and crew
        AddMainShip();        
        AddCrewMember(CrewSpecialization.Captain, shipManager.GetPointOfRespForCrew(0));
        AddCrewMember(CrewSpecialization.Captain, shipManager.GetPointOfRespForCrew(1));

        //objectpooling 
        fireIncident_pool = new ObjectPooling(10, Incident.GetIncidentPrefab(IncidentsType.fire), shipManager.mainShipTransform);
        simpleWreckIncident_pool = new ObjectPooling(10, Incident.GetIncidentPrefab(IncidentsType.simple_wreck), shipManager.mainShipTransform);
        fireExtInstrument_pool = new ObjectPooling(10, Instrument.GetInstrumentPrefab(InstrumentsType.fire_extinguisher), shipManager.mainShipTransform);
        simpleRepairerInstrument_pool = new ObjectPooling(10, Instrument.GetInstrumentPrefab(InstrumentsType.repair_kit), shipManager.mainShipTransform);


        AddIncident(IncidentsType.fire, new Vector3(2.5f, 0, 4));
        AddIncident(IncidentsType.fire, new Vector3(2.5f, 0, 3));
        AddIncident(IncidentsType.fire, new Vector3(2.5f, 0, 2));

        AddIncident(IncidentsType.simple_wreck, new Vector3(4f, 0, 2));
        AddIncident(IncidentsType.simple_wreck, new Vector3(4f, 0, 4));

        AddInstrument(InstrumentsType.repair_kit, new Vector3(-2.5f, 0.5f, 4));
        AddInstrument(InstrumentsType.fire_extinguisher, new Vector3(-2.5f, 0.5f, -4));

        /*
        GameObject incident = Instantiate(Incident.GetIncidentPrefab(IncidentsType.fire), new Vector3(2.5f, 0, 4), Quaternion.Euler(0, 0, 0), shipManager.mainShipTransform);
        GameObject incident1 = Instantiate(Incident.GetIncidentPrefab(IncidentsType.fire), new Vector3(2.5f, 0, 3), Quaternion.Euler(0, 0, 0), shipManager.mainShipTransform);
        GameObject incident2 = Instantiate(Incident.GetIncidentPrefab(IncidentsType.fire), new Vector3(2.5f, 0, 2), Quaternion.Euler(0, 0, 0), shipManager.mainShipTransform);

        GameObject incident3 = Instantiate(Incident.GetIncidentPrefab(IncidentsType.simple_wreck), new Vector3(4f, 0, 2), Quaternion.Euler(0, 0, 0), shipManager.mainShipTransform);
        GameObject incident4 = Instantiate(Incident.GetIncidentPrefab(IncidentsType.simple_wreck), new Vector3(4f, 0, 4), Quaternion.Euler(0, 0, 0), shipManager.mainShipTransform);


        GameObject wren = Instantiate(Instrument.GetInstrumentPrefab(InstrumentsType.repair_kit), new Vector3(-2.5f, 0.5f, 4), Quaternion.Euler(0, 0, 0), shipManager.mainShipTransform);
        wren.GetComponent<Instrument>().MakeThrownAway();

        GameObject ext = Instantiate(Instrument.GetInstrumentPrefab(InstrumentsType.fire_extinguisher), new Vector3(-2.5f, 0.5f, -4), Quaternion.Euler(0, 0, 0), shipManager.mainShipTransform);
        ext.GetComponent<Instrument>().MakeThrownAway();
        */
    }

    // Update is called once per frame
    void Update()
    {
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

   
    private void AddCrewMember(CrewSpecialization _spec, Vector3 location)
    {
        GameObject player = Instantiate(CrewManager.GetCrewPrefab(_spec), location, Quaternion.Euler(0, 0, 0), GameObject.Find("SpaceShip").transform);
        crewMembers.Add(player, player.GetComponent<CrewManager>());
        player.GetComponent<CrewManager>().SetRespawnPoint(location);
        player.GetComponent<CrewManager>().InitUI();
    }

    private void AddMainShip()
    {
        GameObject ship = Instantiate(Resources.Load<GameObject>("prefabs/ships/small ship 1"), new Vector3(0, 0, 0), Quaternion.Euler(0, 0, 0), GameObject.Find("SpaceShip").transform);
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
        GameObject player = Instantiate(Resources.Load<GameObject>("prefabs/highlight"), Vector3.zero, Quaternion.Euler(0, 0.03f, 0), GameObject.Find("SpaceShip").transform);
        highlighter = player.transform;
        highlighter.gameObject.SetActive(true);
        highlighter.position = new Vector3(0, -1, 0);
        //============================
    }

    private void AddIncident(IncidentsType _type, Vector3 position)
    {
        GameObject incident = default;

        switch(_type)
        {
            case IncidentsType.fire:
                incident = fireIncident_pool.GetObject();
                break;

            case IncidentsType.simple_wreck:
                incident = simpleWreckIncident_pool.GetObject();
                break;

        }

        incident.SetActive(true);
        incident.transform.position = position;        
    }

  
    private void AddInstrument(InstrumentsType _type, Vector3 position)
    {
        GameObject instrument = default;

        switch (_type)
        {
            case InstrumentsType.fire_extinguisher:
                instrument = fireExtInstrument_pool.GetObject();
                break;

            case InstrumentsType.repair_kit:
                instrument = simpleRepairerInstrument_pool.GetObject();
                break;
        }

        instrument.SetActive(true);
        instrument.transform.position = position;        
        instrument.GetComponent<Instrument>().MakeThrownAway();
    }

    

}



