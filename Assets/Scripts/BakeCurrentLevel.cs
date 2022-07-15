using System.Collections;
using System.Collections.Generic;
using Unity.AI.Navigation;
using Unity.AI;
using UnityEngine;

public class BakeCurrentLevel : MonoBehaviour
{
    private NavMeshSurface currentSurface;

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    private void OnEnable()
    {

        currentSurface = GetComponentInChildren<NavMeshSurface>();

        currentSurface.BuildNavMesh();
    }
}
