using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MakeActiveInTimer : MonoBehaviour
{
    [SerializeField] private float howLong, whatInterval, startingTimer;
    [SerializeField] private MeshRenderer mesh;

    private float curTime, intTime, startTime;

    private void OnEnable()
    {
        mesh.enabled = false;
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
                    if (!mesh.enabled) mesh.enabled = true;
                    curTime += Time.deltaTime;
                }
                else
                {
                    if (mesh.enabled) mesh.enabled = false;
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
}
