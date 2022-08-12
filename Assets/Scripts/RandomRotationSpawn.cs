using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using DG.Tweening;

public class RandomRotationSpawn : MonoBehaviour
{
    [SerializeField] private float delta;
    [SerializeField] private Axis axiz;

    private float rotationX, rotationY, rotationZ;

    private void OnEnable()
    {
        print(transform.localEulerAngles.x + " 1");

        rotationX = axiz == Axis.X ? UnityEngine.Random.Range(0, delta) : transform.localEulerAngles.x;
        rotationY = axiz == Axis.Y ? UnityEngine.Random.Range(0, delta) : transform.localEulerAngles.y;
        rotationZ = axiz == Axis.Z ? UnityEngine.Random.Range(0, delta) : transform.localEulerAngles.z;

        transform.localRotation = Quaternion.Euler(rotationX, rotationY, rotationZ);
       
    }
}

public enum Axis
{
    X,
    Y,
    Z
}
