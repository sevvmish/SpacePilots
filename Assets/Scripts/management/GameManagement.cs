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
    [SerializeField] private AudioManager audio;
    [SerializeField] private Light directionalLight;
    [SerializeField] private Joystick joystick;
    [SerializeField] private Material screenEffect;
    [SerializeField] private LevelManagement levelManagement;
        
    private CharacterController playerCharController;

    private Ray ray;
    private RaycastHit hit;
    private float timerSecondClick;
    private float secondClickResponse = 0.3f;


    //init level
    private Transform highlighter;
    private GameObject selectedGameObject;
    

    //crew UI delegates
    public delegate void BaseUIHandler(Camera camera);
    public static BaseUIHandler MainUIHandler;
    public static HashSet<CrewManager> crewMemberDead = new HashSet<CrewManager>();
        

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

        //init highlight and audio listener
        InitHighlightPlayer();

        //screen effect
        makeScreenOn();

    }

    // Update is called once per frame
    void Update()
    {        
        if (timerSecondClick>0)
        {
            timerSecondClick -= Time.deltaTime;
        }

        if (crewMemberDead.Count > 0)
        {
            foreach (CrewManager item in crewMemberDead)
            {
                if (selectedGameObject == item.gameObject)
                {
                    highlighter.SetParent(GameObject.Find("SpaceShip").transform);
                    highlighter.localPosition = new Vector3(0, -1, 0);
                    selectedGameObject = null;
                    playerCharController = null;
                    crewMemberDead.Remove(item);
                    break;
                }
            }
        }


        if (playerCharController != null)
        {
            if (Mathf.Abs(joystick.Horizontal) > 0 || Mathf.Abs(joystick.Vertical) > 0)
            {
                playerCharController.gameObject.GetComponent<NavMeshAgent>().ResetPath();
                playerCharController.transform.LookAt(playerCharController.transform.position + new Vector3(joystick.Horizontal, 0, joystick.Vertical));
                playerCharController.Move(playerCharController.transform.TransformDirection(Vector3.forward) * Time.deltaTime * 5);
            }
        }        
          
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

                    timerSecondClick = secondClickResponse;
                }
                else
                {

                    if (selectedGameObject.TryGetComponent(out CrewManager crew) && selectedGameObject != hit.collider.gameObject)
                    {                        
                        IPointOfInteraction _point = hit.collider.gameObject.GetComponent<IPointOfInteraction>();
                        Vector3 pointToMove = _point == null ? hit.point : _point.GetPointOfInteraction();

                        crew.MoveCrewMemberTo(pointToMove, hit.collider.gameObject);
                    }
                    else if (crew != null && selectedGameObject == hit.collider.gameObject)
                    {                        

                        if (timerSecondClick <= 0)
                        {
                            timerSecondClick = secondClickResponse;
                        }
                        else
                        {
                            //second click
                            if (!crew.ThrowAwayCurrentTakenObject())
                            {
                                crew.TakeObjectOnDoubleClick();
                            }
                            timerSecondClick = 0;
                        }
                    }
                }
            }
        }
               

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

    
    private void HighlightSelectedCrewMember(Transform crewMember)
    {
        highlighter.SetParent(crewMember);
        highlighter.gameObject.SetActive(true);
        highlighter.localPosition = Vector3.zero;
    }

    private void InitHighlightPlayer()
    {
        //highlighting player system
        GameObject player = Instantiate(Resources.Load<GameObject>("prefabs/highlight"), new Vector3(100,100,100), Quaternion.Euler(0, 0, 0), GameObject.Find("SpaceShip").transform);
        highlighter = player.transform;
        highlighter.gameObject.SetActive(true);
        //highlighter.position = new Vector3(0, -1, 0);
        //============================
    }

    

}



