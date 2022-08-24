using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using DG.Tweening;

public class AnimationEffectControl : MonoBehaviour
{
    [SerializeField] private Transform [] barrels;
    [SerializeField] private int count;
    [SerializeField] private float startDelay;    
    [SerializeField] private float delayFirst;
    [SerializeField] private float centerDelay;
    [SerializeField] private float delaySecond;


    private int index;
    

    private void OnEnable()
    {
        StartCoroutine(playEff());
        
        if (count==1)
        {
            index = 0;
        }
        else
        {
            index = UnityEngine.Random.Range(0, count) * 3;
        }
            
    }

    private IEnumerator playEff()
    {
        yield return new WaitForSeconds(startDelay);
        Sequence seq = DOTween.Sequence();

        seq.Append(barrels[index].DOMove(barrels[index + 2].position, delayFirst));

        seq.AppendInterval(centerDelay);

        seq.Append(barrels[index].DOMove(barrels[index + 1].position, delaySecond));

        //barrels[index].DOMove(barrels[index + 2].position, 1);        
        //yield return new WaitForSeconds(1);
        //barrels[index].DOMove(barrels[index + 1].position, 1);

        yield return new WaitForSeconds(delayFirst + delaySecond + centerDelay);
        
        gameObject.SetActive(false);
    }

}
