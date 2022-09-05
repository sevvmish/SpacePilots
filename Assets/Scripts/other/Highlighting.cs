using System.Collections;
using System.Collections.Generic;
using UnityEngine;


public class Highlighting : MonoBehaviour
{
    public static Material GetBaseMaterial(Transform transform)
    {
        if (transform.GetComponent<MeshRenderer>() != null)
        {
            return transform.GetComponent<MeshRenderer>().material;
        }

        if (transform.GetComponent<SkinnedMeshRenderer>() != null)
        {
            return transform.GetComponent<SkinnedMeshRenderer>().material;
        }

        if (transform.GetComponent<ParticleSystemRenderer>() != null)
        {
            return transform.GetComponent<ParticleSystemRenderer>().material;
        }

        return default;
    }

    public static void ChangeMaterial(Material _material, Transform transform)
    {
        if (transform.GetComponent<MeshRenderer>() != null)
        {
            transform.GetComponent<MeshRenderer>().material = _material;
            return;
        }

        if (transform.GetComponent<SkinnedMeshRenderer>() != null)
        {
            transform.GetComponent<SkinnedMeshRenderer>().material = _material;
            return;
        }

        if (transform.GetComponent<ParticleSystemRenderer>() != null)
        {
            transform.GetComponent<ParticleSystemRenderer>().material = _material;
            return;
        }

        print("error in changing material");
    }

    
}
