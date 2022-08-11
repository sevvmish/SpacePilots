using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class RandomRotationSpawn : MonoBehaviour
{
    [SerializeField] private float rotationX, rotationY, rotationZ;

    private void OnEnable()
    {       


        rotationX = rotationX == 0 ? transform.rotation.x : UnityEngine.Random.Range(0, rotationX);
        rotationY = rotationY == 0 ? transform.rotation.y : UnityEngine.Random.Range(0, rotationY);
        rotationZ = rotationZ == 0 ? transform.rotation.z : UnityEngine.Random.Range(0, rotationZ);

        transform.localRotation = Quaternion.Euler(transform.localRotation.x, transform.localRotation.y, transform.localRotation.z);
    }
}
