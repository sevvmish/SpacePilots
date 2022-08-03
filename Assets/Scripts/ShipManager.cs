using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ShipManager : MonoBehaviour
{
    private int limitAmountOfCrew;
    public Transform[] pointsOfCrewResp;
    public Transform DefaultPointOfCrewResp;
    public Transform mainShipTransform;

    private void OnEnable()
    {
        mainShipTransform = GetComponent<Transform>();
        limitAmountOfCrew = pointsOfCrewResp.Length;
        if (DefaultPointOfCrewResp == null) DefaultPointOfCrewResp = pointsOfCrewResp[0];
    }

    public Vector3 GetPointOfRespForCrew(int orderOfCrewMember)
    {
        if (orderOfCrewMember >= limitAmountOfCrew) return DefaultPointOfCrewResp.position;

        return pointsOfCrewResp[orderOfCrewMember].position;
    }

    public int GetLimitAmountOfCrew() {return limitAmountOfCrew;}


}
