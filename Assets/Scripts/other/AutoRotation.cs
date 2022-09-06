using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class AutoRotation : MonoBehaviour
{
    [SerializeField] private float speed;
    [SerializeField] private Axis axis;

    private float rotationX, rotationY, rotationZ;

    private void OnEnable()
    {
        rotationX = axis == Axis.X ? speed : 0;
        rotationY = axis == Axis.Y ? speed : 0;
        rotationZ = axis == Axis.Z ? speed : 0;

    }

    // Update is called once per frame
    void Update()
    {
        transform.Rotate(new Vector3(rotationX * Time.deltaTime, rotationY * Time.deltaTime, rotationZ * Time.deltaTime));        
    }
}
