using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Unity.AI.Navigation;
using DG.Tweening;
using System;
using EZCameraShake;

public class GameManagement : MonoBehaviour
{
    [SerializeField] private settings GeneralSettings;
    [SerializeField] private Camera mainCam;
    [SerializeField] private Transform cameraBody;
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

        
                
        AddMainShip();        
        AddCrewMember(CrewSpecialization.Captain, shipManager.GetPointOfRespForCrew(0));
        AddCrewMember(CrewSpecialization.Captain, shipManager.GetPointOfRespForCrew(1));

        //highlighting player
        GameObject player = Instantiate(Resources.Load<GameObject>("prefabs/highlight"), Vector3.zero, Quaternion.Euler(0, 0.03f, 0), GameObject.Find("SpaceShip").transform);
        highlighter = player.transform;
        highlighter.gameObject.SetActive(false);
        //============================

        GameObject incident = Instantiate(Incident.GetIncidentPrefab(IncidentsType.fire), new Vector3(2.5f, 0, 4), Quaternion.Euler(0, 0, 0), shipManager.mainShipTransform);
        GameObject incident1 = Instantiate(Incident.GetIncidentPrefab(IncidentsType.fire), new Vector3(2.5f, 0, 3), Quaternion.Euler(0, 0, 0), shipManager.mainShipTransform);
        GameObject incident2 = Instantiate(Incident.GetIncidentPrefab(IncidentsType.fire), new Vector3(2.5f, 0, 2), Quaternion.Euler(0, 0, 0), shipManager.mainShipTransform);

        GameObject incident3 = Instantiate(Incident.GetIncidentPrefab(IncidentsType.simple_wreck), new Vector3(4f, 0, 2), Quaternion.Euler(0, 0, 0), shipManager.mainShipTransform);
        GameObject incident4 = Instantiate(Incident.GetIncidentPrefab(IncidentsType.simple_wreck), new Vector3(4f, 0, 4), Quaternion.Euler(0, 0, 0), shipManager.mainShipTransform);

        incident.GetComponent<Incident>().InitUI();
        incident1.GetComponent<Incident>().InitUI();
        incident2.GetComponent<Incident>().InitUI();
        incident3.GetComponent<Incident>().InitUI();
        incident4.GetComponent<Incident>().InitUI();

        GameObject wren = Instantiate(Instrument.GetInstrumentPrefab(InstrumentsType.repair_kit), new Vector3(-2.5f, 0.5f, 4), Quaternion.Euler(0, 0, 0), shipManager.mainShipTransform);
        wren.GetComponent<Instrument>().MakeThrownAway();

        GameObject ext = Instantiate(Instrument.GetInstrumentPrefab(InstrumentsType.fire_extinguisher), new Vector3(-2.5f, 0.5f, -4), Quaternion.Euler(0, 0, 0), shipManager.mainShipTransform);
        ext.GetComponent<Instrument>().MakeThrownAway();
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
                //if (hit.collider != null) print(hit.collider.name);

                if (hit.collider.GetComponent<CrewManager>() != null && selectedGameObject != hit.collider.gameObject)
                {
                    selectedGameObject = hit.collider.gameObject;
                    
                    selectedGameObject.GetComponent<IHighlightable>().HighlightCurrentObject();
                    HighlightSelectedCrewMember(hit.collider.gameObject.transform);
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
        GameObject player = Instantiate(CrewManager.GetCrewPrefab(_spec), location, Quaternion.Euler(0, 0, 0), shipManager.mainShipTransform);
        crewMembers.Add(player, player.GetComponent<CrewManager>());
        player.GetComponent<CrewManager>().SetRespawnPoint(location);
        player.GetComponent<CrewManager>().InitUI();
    }

    private void AddMainShip()
    {
        GameObject ship = Instantiate(Resources.Load<GameObject>("prefabs/ships/test ship1"), new Vector3(0, 0, 0), Quaternion.Euler(0, 0, 0), GameObject.Find("SpaceShip").transform);
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

}



