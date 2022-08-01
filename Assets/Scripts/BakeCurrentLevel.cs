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
        currentSurface = this.transform.GetComponentInChildren<NavMeshSurface>();
        currentSurface.BuildNavMesh();
    }
}
