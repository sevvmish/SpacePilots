using System.Collections;
using System.Collections.Generic;
using Unity.AI.Navigation;
using Unity.AI;
using UnityEngine;

public class BakeCurrentLevel : MonoBehaviour
{
    private NavMeshSurface currentSurface;

    private void OnEnable()
    {
        /*
        for (int i = 0; i < transform.childCount; i++)
        {
            if (transform.GetChild(i).GetComponent<NavMeshSurface>() )
            {
                currentSurface = transform.GetChild(i).GetComponent<NavMeshSurface>();
            }
        }
        */
        
        //currentSurface = this.transform.GetComponentInChildren<NavMeshSurface>();
        //currentSurface.BuildNavMesh();
    }

    private void Start()
    {
        currentSurface = this.transform.GetComponentInChildren<NavMeshSurface>();
        currentSurface.BuildNavMesh();
    }
}
