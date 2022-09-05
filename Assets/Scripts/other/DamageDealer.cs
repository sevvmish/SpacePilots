using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[RequireComponent(typeof(SphereCollider))]
public class DamageDealer : MonoBehaviour
{
    [SerializeField] private float damageAmount;
    [SerializeField] private NegativeEffects currentEffect;


    private Dictionary<GameObject, DamageData> objectsToDamage = new Dictionary<GameObject, DamageData>();
    


    public float GetDamageAmount()
    {
        return damageAmount;
    }

    public NegativeEffects GetNegativeEffect()
    {
        return currentEffect;
    }


    private void OnTriggerEnter(Collider other)
    {
        if (!objectsToDamage.ContainsKey(other.gameObject) && other.TryGetComponent(out IHealthDestroyable victim) && victim.IsDestroyable())
        {
            objectsToDamage.Add(other.gameObject, new DamageData(other.gameObject));
        }
    }


    
    private void OnTriggerExit(Collider other)
    {
        if (objectsToDamage.ContainsKey(other.gameObject))
        {
            objectsToDamage.Remove(other.gameObject);                           
        }
    }

    


    private void OnTriggerStay(Collider other)
    {
        
        if (!objectsToDamage.ContainsKey(other.gameObject) && other.TryGetComponent(out IHealthDestroyable victim) && victim.IsDestroyable())
        {
            objectsToDamage.Add(other.gameObject, new DamageData(other.gameObject));
        }

        foreach (var key in objectsToDamage.Keys)
        {
            //print(other.gameObject.name + " = " + Vector3.Distance(transform.position, key.transform.position));


            if (!objectsToDamage[key].CurrentEffects.Contains(currentEffect))
            {
                switch (currentEffect)
                {
                    case NegativeEffects.burning:
                        if (other.gameObject.GetComponent<CrewManager>() != null && Vector3.Distance(transform.position, key.transform.position)<=0.65f) StartCoroutine(PlayAddEffect(objectsToDamage[key], currentEffect));
                        if (other.gameObject.GetComponent<Supply>() != null && Vector3.Distance(transform.position, key.transform.position) <= 1f) StartCoroutine(PlayAddEffect(objectsToDamage[key], currentEffect));
                        break;

                    case NegativeEffects.electricity:

                        break;

                    case NegativeEffects.slow_down:
                        if (Vector3.Distance(transform.position, key.transform.position) <= 0.6f) StartCoroutine(PlayAddEffect(objectsToDamage[key], currentEffect));
                        break;

                    case NegativeEffects.poisoned:
                        /*if (Vector3.Distance(transform.position, key.transform.position) <= 0.8f)*/ StartCoroutine(PlayAddEffect(objectsToDamage[key], currentEffect));
                        break;
                }
                
            }


        }

    
    }

    private IEnumerator PlayAddEffect(DamageData data, NegativeEffects _effect)
    {
        
        float damageTime = 2f;

        data.currentIHDestroyable.SetNegativeEffect(_effect, 2);
        data.AddNegativeEffect(_effect);

        for (float i = 0; i < damageTime; i += 0.1f)
        {
            data.currentIHDestroyable.DecreaseHealthAmount(damageAmount / damageTime / 10f);

            yield return new WaitForSeconds(0.1f);
        }
                
        data.RemoveNegativeEffect(_effect);
    }


}


public struct DamageData
{
    public HashSet<NegativeEffects> CurrentEffects;
    public IHealthDestroyable currentIHDestroyable;

    public DamageData(GameObject _object)
    {
        CurrentEffects = new HashSet<NegativeEffects>();
        currentIHDestroyable = _object.GetComponent<IHealthDestroyable>();
    }

    public bool AddNegativeEffect(NegativeEffects _effect)
    {
        if (!CurrentEffects.Contains(_effect))
        {
            CurrentEffects.Add(_effect);
            return true;
        }
        else
        {
            return false;
        }
    }

    public bool RemoveNegativeEffect(NegativeEffects _effect)
    {
        if (CurrentEffects.Contains(_effect))
        {
            CurrentEffects.Remove(_effect);
            return true;
        }
        else
        {
            return false;
        }
    }

    


}
