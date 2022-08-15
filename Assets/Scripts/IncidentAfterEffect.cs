using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using DG.Tweening;


public class IncidentAfterEffect : MonoBehaviour
{    
    private ObjectPooling returnPool;
    private float time;

  
    public void InitAfterEffect(ObjectPooling _returnPool, float _time)
    {
        time = _time;
        returnPool = _returnPool;
        gameObject.SetActive(true);


        StartCoroutine(playAfterEffect());
    }

    private IEnumerator playAfterEffect()
    {
        transform.position = transform.position;
        gameObject.SetActive(true);

        yield return new WaitForSeconds(time - 0.5f);

        gameObject.transform.DOScale(Vector3.zero, 0.5f);
        yield return new WaitForSeconds(0.5f);

        gameObject.transform.localScale = Vector3.one;
        returnPool.ReturnObject(gameObject);
    }
}
