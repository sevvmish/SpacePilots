using System.Collections;
using System.Collections.Generic;
using UnityEngine;


public class ShipManager : MonoBehaviour
{
    public Transform[] MovingEffects;

    public Transform[] EngineEffects;

    private int limitAmountOfCrew;
    public Transform[] pointsOfCrewResp;
    public Transform DefaultPointOfCrewResp;
    public Transform mainShipTransform;

    [SerializeField] private float shipHealth;
    [SerializeField] private float shipSpeed;
    [SerializeField] private float energy;

    public float Energy
    {
        get { return energy; }

        set
        {
            if (value < 0)
            {
                energy = 0;
            }
            else if(value > 1)
            {
                energy = 1;
            }
            else
            {                
                energy = value;

                SetEffectsOfMovingInParticles();
                SetEffectOfEnginesFlame();
            }
        }
    }


    private void OnEnable()
    {
        mainShipTransform = GetComponent<Transform>();
        limitAmountOfCrew = pointsOfCrewResp.Length;
        if (DefaultPointOfCrewResp == null) DefaultPointOfCrewResp = pointsOfCrewResp[0];

        Energy = 0;
        StartCoroutine(AfterSec());
    }

    public Vector3 GetPointOfRespForCrew(int orderOfCrewMember)
    {
        if (orderOfCrewMember >= limitAmountOfCrew) return DefaultPointOfCrewResp.position;

        return pointsOfCrewResp[orderOfCrewMember].position;
    }

    public int GetLimitAmountOfCrew() {return limitAmountOfCrew;}

    private void SetEffectsOfMovingInParticles()
    {
        float timeTL = (1 / (Energy + 0.01f) * 3f) < 10f ? (1 / (Energy + 0.01f) * 3f) : 10f;

        if (Energy < 0.2f) timeTL = 0;

        if (MovingEffects.Length>0)
        {
            for (int i = 0; i < MovingEffects.Length; i++)
            {
                MovingEffects[i].GetComponent<ParticleSystem>().startSpeed = Energy * Energy * 15f;
                MovingEffects[i].GetComponent<ParticleSystem>().startLifetime = timeTL;                
            }
        }
    }

    private void SetEffectOfEnginesFlame()
    {
        if (EngineEffects.Length > 0)
        {
            for (int i = 0; i < EngineEffects.Length; i++)
            {
                EngineEffects[0].localScale = Vector3.one * energy;
            }
        }
    }

    public IEnumerator AfterSec()
    {
        yield return new WaitForSeconds(3);
        Energy = 0.5f;

        yield return new WaitForSeconds(10);
        Energy = 1;
    }
}
