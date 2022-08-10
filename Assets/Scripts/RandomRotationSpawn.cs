using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class RandomRotationSpawn : MonoBehaviour
{
    [SerializeField] private float rotationX, rotationY, rotationZ;

    private void OnEnable()
    {
        rotationX = rotationX == 0 ? transform.eulerAngles.x : UnityEngine.Random.Range(0, rotationX);
        rotationY = rotationY == 0 ? transform.eulerAngles.y : UnityEngine.Random.Range(0, rotationY);
        rotationZ = rotationZ == 0 ? transform.eulerAngles.z : UnityEngine.Random.Range(0, rotationZ);

        /*
        rotationX = rotationX == 0 ? transform.localRotation.x : UnityEngine.Random.Range(0, rotationX);
        rotationY = rotationY == 0 ? transform.localRotation.y : UnityEngine.Random.Range(0, rotationY);
        rotationZ = rotationZ == 0 ? transform.localRotation.z : UnityEngine.Random.Range(0, rotationZ);

        transform.localRotation = Quaternion.Euler(rotationX, rotationY, rotationZ);
        */

        //transform.rotation = Quaternion.Euler(transform.rotation.x, transform.rotation.y, transform.rotation.z);
        transform.eulerAngles = new Vector3(rotationX, rotationY, rotationZ);
    }

}
