using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.AI;

[RequireComponent(typeof(SphereCollider))]
public class Supply : MonoBehaviour, ITakenAndMovable
{
    [SerializeField] private SuppliesType currentSupplyType;    
    [SerializeField] private float YCoordWhenThrownAway;
    [SerializeField] private SphereCollider currentCollider;
    [SerializeField] private Transform currentVisualTransform, currentTransform;

    private bool isCanBeTakenByCrew = false;
    private float modelAngle;
    private Vector3 modelStandartRotation;

    private void OnEnable()
    {
        currentTransform = GetComponent<Transform>();
                
        modelStandartRotation = currentVisualTransform.localEulerAngles;
    }

    public void RotateWhileThrownAway()
    {
        if (isCanBeTakenByCrew)
        {
            modelAngle += Time.deltaTime * 30;
            currentVisualTransform.localEulerAngles = new Vector3(modelStandartRotation.x, modelStandartRotation.y + modelAngle, modelStandartRotation.z);
        }
        else
        {
            modelAngle = 0;
        }
    }


    private void Update()
    {
        RotateWhileThrownAway();
    }

    public void MakeThrownAway()
    {
        currentTransform.rotation = Quaternion.Euler(Vector3.zero);
        currentTransform.localScale = Vector3.one;
        currentCollider.enabled = true;
        isCanBeTakenByCrew = true;
        GetComponent<Transform>().localPosition = new Vector3(GetComponent<Transform>().localPosition.x, YCoordWhenThrownAway, GetComponent<Transform>().localPosition.z);
    }


    public static GameObject GetSupplyPrefab(SuppliesType _movable)
    {
        GameObject result = default;

        switch((int)_movable)
        {
            case 0:
                result = Resources.Load<GameObject>("prefabs/supplies/test movable");
                break;
            
        }

        return result;
    }

    public object GetTypeOfObject()
    {
        return currentSupplyType;
    }

    public bool IsCanBeTakenByCrew()
    {
        return isCanBeTakenByCrew;
    }

    public GameObject GiveAwayTakeble()
    {
        if (isCanBeTakenByCrew)
        {
            currentCollider.enabled = false;
            isCanBeTakenByCrew = false;
            currentVisualTransform.localEulerAngles = modelStandartRotation;
            return gameObject;
        }
        else
        {
            return null;
        }
    }



}

