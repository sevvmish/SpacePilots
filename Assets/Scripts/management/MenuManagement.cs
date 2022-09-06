using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MenuManagement : MonoBehaviour
{
    [SerializeField] private settings GeneralSettings;
    [SerializeField] private Camera mainCam;
    [SerializeField] private Transform mainShip;

    private Ray ray;
    private RaycastHit hit;

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


    }

    // Update is called once per frame
    void Update()
    {
        if (Input.GetMouseButtonDown(0))
        {
            ray = mainCam.ScreenPointToRay(Input.mousePosition);

            if (Physics.Raycast(ray, out hit, 50))
            {

                
            }
        }
    }
}
