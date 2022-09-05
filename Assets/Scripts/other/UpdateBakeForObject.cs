using System.Collections;
using System.Collections.Generic;
using Unity.AI.Navigation;
using UnityEngine;
using DG.Tweening;
using UnityEngine.AI;

public class UpdateBakeForObject : MonoBehaviour
{
    private NavMeshSurface currentSurface;
    [SerializeField] private Transform currentTransform;
    [SerializeField] private NavMeshSurface[] toBake;
    private Vector3 lastPosition;
    private bool isOneSide;

    // Start is called before the first frame update
    void Start()
    {
        

        
    }

    private void OnEnable()
    {
        //currentSurface = currentTransform.GetComponentInChildren<NavMeshSurface>();
        bake();

        //currentTransform = gameObject.transform;
        lastPosition = currentTransform.position;
    }

    // Update is called once per frame
    void Update()
    {
        if (lastPosition != currentTransform.position)
        {
            print("updated");
            //gameObject.GetComponent<NavMeshLink>().UpdateLink();
            //currentSurface.BuildNavMesh();
            bake();
            lastPosition = currentTransform.position;
        }

        if (!isOneSide)
        {
            isOneSide = true;
            StartCoroutine(anotherSide());
        }
    }

    private void bake()
    {
        for (int i = 0; i < toBake.Length; i++)
        {
            toBake[i].BuildNavMesh();
        }
    }

    IEnumerator anotherSide()
    {
        currentTransform.DOMove(new Vector3(-2, 0, 0), 0);
        currentTransform.DOMove(new Vector3(2, 0, 0), 3);
        yield return new WaitForSeconds(2);

        currentTransform.DOMove(new Vector3(-2, 0, 0), 3);
        yield return new WaitForSeconds(2);
        isOneSide = false;
    }

}
