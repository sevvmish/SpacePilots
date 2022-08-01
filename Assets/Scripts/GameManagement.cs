using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Unity.AI.Navigation;
using DG.Tweening;
using System;

public class GameManagement : MonoBehaviour
{
    [SerializeField] private settings GeneralSettings;
    [SerializeField] private Camera mainCam;
    [SerializeField] private Transform cameraBody;
    private Vector3 cameraDefaultBodyShift = Vector3.zero;
    private Vector3 cameraDefaultBodyAngle = new Vector3(70, 0, 0);

    private readonly Vector3 CAMERA_SHIFT_CLOSE = new Vector3(0, 10, -4.5f);
    private readonly Vector3 CAMERA_SHIFT_MEDIUM = new Vector3(0, 13, -6f);

    //floating effect
    private bool isFloating;
    private bool isOneWay;
    private Action HandleFloatingEffect;
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
    private Transform mainShipTransform;

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



        //init level===================
        GameObject player = Instantiate(Resources.Load<GameObject>("prefabs/highlight"), Vector3.zero, Quaternion.Euler(0, 0, 0), GameObject.Find("Crew").transform);
        highlighter = player.transform;
        highlighter.gameObject.SetActive(false);

        AddCrewMember(CrewSpecialization.tester, new Vector3(2, 0, 0));
        AddCrewMember(CrewSpecialization.tester, new Vector3(-2, 0, 0));
        AddMainShip();
        mainShipTransform.rotation = Quaternion.Euler(0, 90, 0);


        //camera lookup===================
        cameraBody.position = cameraDefaultBodyShift;
        cameraBody.rotation = Quaternion.Euler(cameraDefaultBodyAngle);
        isFloating = true;
        HandleFloatingEffect += MakeFloatingEffect;
    }

    // Update is called once per frame
    void Update()
    {
        if (Input.GetMouseButtonDown(0))
        {
            ray = mainCam.ScreenPointToRay(Input.mousePosition);

            if (Physics.Raycast(ray, out hit))
            {
                if (hit.collider.CompareTag("Crew"))
                {
                    selectedGameObject = hit.collider.gameObject;
                    HighlightSelectedCrewMember(hit.collider.gameObject.transform);
                }
                else
                {
                    if (selectedGameObject!=null && selectedGameObject.CompareTag("Crew"))
                    {
                        IPointOfInteraction _point = hit.collider.gameObject.GetComponent<IPointOfInteraction>();
                        Vector3 pointToMove = _point == null ? hit.point : _point.GetPointOfInteraction();

                        crewMembers[selectedGameObject].MoveCrewMemberTo(pointToMove, hit.collider.gameObject);
                    }
                }
            }
        }



        if (isFloating) HandleFloatingEffect?.Invoke();
    }


    private void AddCrewMember(CrewSpecialization _spec, Vector3 location)
    {
        GameObject player = Instantiate(Resources.Load<GameObject>("prefabs/crew/DefaultPlayer1"), location, Quaternion.Euler(0, 0, 0), GameObject.Find("Crew").transform);
        crewMembers.Add(player, player.GetComponent<CrewManager>());

    }

    private void AddMainShip()
    {
        GameObject ship = Instantiate(Resources.Load<GameObject>("prefabs/ships/test ship1"), new Vector3(0, 0, 0), Quaternion.Euler(0, 0, 0), GameObject.Find("SpaceShip").transform);
        mainShipTransform = ship.transform;
        cameraDefaultBodyShift = CAMERA_SHIFT_CLOSE;
        floatKoeff = 1;
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

public interface IPointOfInteraction
{
    public Vector3 GetPointOfInteraction();
}


