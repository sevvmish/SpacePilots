using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class DisableAfterSeconds : MonoBehaviour
{
    [SerializeField] private float _sec;

    private void OnEnable()
    {
        StartCoroutine(DisableAfter(_sec));
    }

    private IEnumerator DisableAfter(float _sec)
    {        
        yield return new WaitForSeconds(_sec);
        gameObject.SetActive(false);
    }
}
