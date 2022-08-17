using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MakeActiveInTimer : MonoBehaviour
{
    public float howLong, whatInterval, startingTimer;
    public bool isLeaveEnabled;
    
    [SerializeField] private MeshRenderer mesh;
    [SerializeField] private GameObject currentGameObject;
    [SerializeField] private GameObject [] currentGameObjects;
    [SerializeField] private WhatToBlink blinkType;

    private float curTime, intTime, startTime;

    private void OnEnable()
    {
        switch(blinkType)
        {
            case WhatToBlink.mesh_renderer:
                mesh.enabled = false;
                break;

            case WhatToBlink.gameobj:
                currentGameObject.SetActive(false);
                break;

            case WhatToBlink.array_of_gameobj:
                for (int i = 0; i < currentGameObjects.Length; i++)
                {
                    currentGameObjects[i].SetActive(false);
                }
                break;
        }
    }

    // Update is called once per frame
    void Update()
    {
        if (startTime > startingTimer)
        {
            if (intTime > whatInterval)
            {
                if (curTime < howLong)
                {
                    MakeOn();
                    curTime += Time.deltaTime;
                }
                else
                {
                    MakeOFF();
                    intTime = 0;
                }
            }
            else
            {
                intTime += Time.deltaTime;
                curTime = 0;
            }
        }
        else
        {
            startTime += Time.deltaTime;
        }
        
    }

    private void MakeOn()
    {        
        switch (blinkType)
        {
            case WhatToBlink.mesh_renderer:
                mesh.enabled = true;
                break;

            case WhatToBlink.gameobj:
                currentGameObject.SetActive(true);
                break;


            case WhatToBlink.array_of_gameobj:
                for (int i = 0; i < currentGameObjects.Length; i++)
                {
                    currentGameObjects[i].SetActive(true);
                }
                break;
        }
    }

    private void MakeOFF()
    {        
        switch (blinkType)
        {
            case WhatToBlink.mesh_renderer:
                mesh.enabled = false;
                break;

            case WhatToBlink.gameobj:
                currentGameObject.SetActive(false);
                break;


            case WhatToBlink.array_of_gameobj:
                for (int i = 0; i < currentGameObjects.Length; i++)
                {
                    currentGameObjects[i].SetActive(false);
                }
                break;
        }
    }

    private void OnDisable()
    {
        switch (blinkType)
        {
            case WhatToBlink.mesh_renderer:
                mesh.enabled = isLeaveEnabled;
                break;

            case WhatToBlink.gameobj:
                currentGameObject.SetActive(isLeaveEnabled);
                break;

            case WhatToBlink.array_of_gameobj:
                for (int i = 0; i < currentGameObjects.Length; i++)
                {
                    currentGameObjects[i].SetActive(isLeaveEnabled);
                }
                break;
        }
    }

    public enum WhatToBlink
    {
        mesh_renderer,
        gameobj,
        array_of_gameobj
    }
}
