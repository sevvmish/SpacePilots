using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GameManagement : MonoBehaviour
{
    [SerializeField] private Camera mainCam;
    [SerializeField] private Transform cameraBody;

    // Start is called before the first frame update
    void Start()
    {
        //camera lookup===================
        cameraBody.position = new Vector3(0, 13, -6);
        cameraBody.rotation = Quaternion.Euler(70, 0, 0);
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
