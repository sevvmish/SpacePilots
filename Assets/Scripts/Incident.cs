using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Incident : MonoBehaviour
{
    [SerializeField] private SuppliesType whatSupplyDealThisIncident;
    [SerializeField] private float health;

    public float Health
    {
        get {return health;}

        set 
        {
            if (health<=0)
            {
                health = 0;
            }
            else
            {
                health = value;
            }
        }
    }

    public void ActWithSupply()
    {
        Health--;
        print(Health);
    }

    public SuppliesType GetSupplyTypeToDealWithIncident()
    {
        return whatSupplyDealThisIncident;
    }


}
