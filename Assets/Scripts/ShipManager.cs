using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ShipManager : MonoBehaviour
{
    public Transform[] pointsOfCrewResp;
    public Transform mainShipTransform;

    private void OnEnable()
    {
        mainShipTransform = GetComponent<Transform>();
    }
}
