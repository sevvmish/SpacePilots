using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[RequireComponent(typeof(SphereCollider))]
public class DamageDealer : MonoBehaviour
{
    [SerializeField] private float damageAmount;
    [SerializeField] private NegativeEffects currentEffect;

    public float GetDamageAmount()
    {
        return damageAmount;
    }

    public NegativeEffects GetNegativeEffect()
    {
        return currentEffect;
    }

}
