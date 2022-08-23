using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using DG.Tweening;

public class FullBarrelGiveAwayEffect : MonoBehaviour
{
    [SerializeField] private Transform [] barrels;
    [SerializeField] private int count;
    // Start is called before the first frame update
    private int index;

    private void OnEnable()
    {
        StartCoroutine(playEff());
        index = UnityEngine.Random.Range(0, count) * 3 ;
    }

    private IEnumerator playEff()
    {
        barrels[index].DOMove(barrels[index + 2].position, 0);
        barrels[index].DOMove(barrels[index + 1].position, 1.5f);
        yield return new WaitForSeconds(1.5f);
        gameObject.SetActive(false);
    }

}
