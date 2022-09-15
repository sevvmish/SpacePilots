using System.Collections;
using System.Collections.Generic;
using UnityEngine;


public class ShipManager : MonoBehaviour
{
    public List<GameObject> AllMonitorsAndElectrics = new List<GameObject>();

    public List<Reactor> ShipReactors = new List<Reactor>();

    public List<Engine> ShipEngines = new List<Engine>();

    public List<ParticleSystem> MovingEffects = new List<ParticleSystem>();
    
    private int limitAmountOfCrew;
    public Transform[] pointsOfCrewResp;
    public Transform DefaultPointOfCrewResp;
    public Transform mainShipTransform;

    [SerializeField] private float shipHealth;
    [SerializeField] private float EnginesProductivity;
    [SerializeField] private float shipSpeed;
    [SerializeField] private float energy = 0;
    [SerializeField] private AudioSource audio;

    private AudioClip powerOn, powerOff;
    private bool isPowerDown;


    public float Energy
    {
        get { return energy; }

        set
        {
            if (AllMonitorsAndElectrics.Count>0)
            {
                if (value <= 0 && energy > 0)
                {
                    for (int i = 0; i < AllMonitorsAndElectrics.Count; i++)
                    {
                        AllMonitorsAndElectrics[i].SetActive(false);
                    }
                }
                else if (value > 0 && energy <= 0)
                {
                    for (int i = 0; i < AllMonitorsAndElectrics.Count; i++)
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
                
                
                if (ShipEngines.Count>0)
                {
                    for (int i = 0; i < ShipEngines.Count; i++)
                    {
                        ShipEngines[i].Energy = energy;
                    }
                }

            }
        }
    }


    private void OnEnable()
    {
        powerOn = Resources.Load<AudioClip>("audio/sounds/power on");
        powerOff = Resources.Load<AudioClip>("audio/sounds/power off");

        mainShipTransform = GetComponent<Transform>();
        limitAmountOfCrew = pointsOfCrewResp.Length;
        if (DefaultPointOfCrewResp == null) DefaultPointOfCrewResp = pointsOfCrewResp[0];

        Energy = 0;

        if (AllMonitorsAndElectrics.Count > 0 && Energy <= 0)
        {            
            for (int i = 0; i < AllMonitorsAndElectrics.Count; i++)
            {
                AllMonitorsAndElectrics[i].SetActive(false);
            }            
        }
    }

    private void Update()
    {        
        if (ShipEngines.Count>0)
        {
            EnginesProductivity = 0;

            for (int i = 0; i < ShipEngines.Count; i++)
            {
                EnginesProductivity += ShipEngines[i].Productivity;
            }

            EnginesProductivity /= ShipEngines.Count;
            SetEffectsOfMovingInParticles();
        }

        if (ShipReactors.Count > 0)
        {
            float _energy = 0;

            for (int i = 0; i < ShipReactors.Count; i++)
            {
                _energy += ShipReactors[i].Energy;
            }

            Energy = _energy / ShipReactors.Count;            
        }

        if (!isPowerDown && Energy <= 0)
        {
            isPowerDown = true;
            audio.clip = powerOff;
            audio.Play();
        }
        else if (isPowerDown && Energy > 0)
        {
            isPowerDown = false;
            audio.clip = powerOn;
            audio.Play();
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

        if (MovingEffects.Count > 0)
        {
            for (int i = 0; i < MovingEffects.Count; i++)
            {
                MovingEffects[i].startSpeed = koef * koef * 15f;
                MovingEffects[i].startLifetime = timeTL;                
            }
        }
    }
    
}
