using System.Collections;
using System.Collections.Generic;
using UnityEngine;


public class ShipManager : MonoBehaviour
{
    public GameObject[] AllMonitorsAndElectrics;

    public Reactor[] ShipReactors;

    public Engine[] ShipEngines;
    public Transform[] MovingEffects;
    
    private int limitAmountOfCrew;
    public Transform[] pointsOfCrewResp;
    public Transform DefaultPointOfCrewResp;
    public Transform mainShipTransform;

    [SerializeField] private float shipHealth;
    [SerializeField] private float EnginesProductivity;
    [SerializeField] private float shipSpeed;
    [SerializeField] private float energy = 0;

    public float Energy
    {
        get { return energy; }

        set
        {
            if (AllMonitorsAndElectrics.Length>0)
            {
                if (value <= 0 && energy > 0)
                {
                    for (int i = 0; i < AllMonitorsAndElectrics.Length; i++)
                    {
                        AllMonitorsAndElectrics[i].SetActive(false);
                    }
                }
                else if (value > 0 && energy <= 0)
                {
                    for (int i = 0; i < AllMonitorsAndElectrics.Length; i++)
                    {
                        AllMonitorsAndElectrics[i].SetActive(true);
                    }
                }
            }
            

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
                
                
                if (ShipEngines.Length>0)
                {
                    for (int i = 0; i < ShipEngines.Length; i++)
                    {
                        ShipEngines[i].Energy = energy;
                    }
                }

            }
        }
    }


    private void OnEnable()
    {
        mainShipTransform = GetComponent<Transform>();
        limitAmountOfCrew = pointsOfCrewResp.Length;
        if (DefaultPointOfCrewResp == null) DefaultPointOfCrewResp = pointsOfCrewResp[0];

        Energy = 0;

        if (AllMonitorsAndElectrics.Length > 0 && Energy <= 0)
        {            
            for (int i = 0; i < AllMonitorsAndElectrics.Length; i++)
            {
                AllMonitorsAndElectrics[i].SetActive(false);
            }            
        }
    }

    private void Update()
    {
        if (ShipEngines.Length>0)
        {
            EnginesProductivity = 0;

            for (int i = 0; i < ShipEngines.Length; i++)
            {
                EnginesProductivity += ShipEngines[i].Productivity;
            }

            EnginesProductivity /= ShipEngines.Length;
            SetEffectsOfMovingInParticles();
        }

        if (ShipReactors.Length > 0)
        {
            float _energy = 0;

            for (int i = 0; i < ShipReactors.Length; i++)
            {
                _energy += ShipReactors[i].Energy;
            }

            Energy = _energy / ShipReactors.Length;            
        }


    }

    public Vector3 GetPointOfRespForCrew(int orderOfCrewMember)
    {
        if (orderOfCrewMember >= limitAmountOfCrew) return DefaultPointOfCrewResp.position;

        return pointsOfCrewResp[orderOfCrewMember].position;
    }

    public int GetLimitAmountOfCrew() {return limitAmountOfCrew;}

    private void SetEffectsOfMovingInParticles()
    {

        float koef = EnginesProductivity * Energy;


        float timeTL = (1 / (koef + 0.01f) * 3f) < 10f ? (1 / (koef + 0.01f) * 3f) : 10f;

        if (koef < 0.2f) timeTL = 0;

        if (MovingEffects.Length>0)
        {
            for (int i = 0; i < MovingEffects.Length; i++)
            {
                MovingEffects[i].GetComponent<ParticleSystem>().startSpeed = koef * koef * 15f;
                MovingEffects[i].GetComponent<ParticleSystem>().startLifetime = timeTL;                
            }
        }
    }
    
}
