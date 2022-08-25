using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using DG.Tweening;

public class test : MonoBehaviour
{
    public Vector3 from, too;
    public Transform platform, tester;
    public float _time;
    private bool isFrom;
    private float curTime;

    private Vector3 previousPos, newPos, deltaPos;
    private HashSet<CrewManager> crews = new HashSet<CrewManager>();

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        newPos = platform.position;
        deltaPos = (previousPos - newPos);
        previousPos = newPos;

        foreach (var item in crews)
        {
            item.GetCorrectionForPosition(deltaPos);
        }

        if (curTime>_time)
        {
            curTime = 0;
            if (isFrom)
            {
                isFrom = false;
                platform.position = too;
                platform.DOMove(from, _time);
            }
            else
            {
                isFrom = true;
                platform.position = from;
                platform.DOMove(too, _time);
            }
        }
        else
        {
            curTime += Time.deltaTime;
        }

        print(deltaPos);
    }

  

    private void OnTriggerEnter(Collider other)
    {
        if (other.TryGetComponent(out CrewManager crew))
        {
            crews.Add(crew);
        }
    }

    private void OnTriggerExit(Collider other)
    {
        if (other.TryGetComponent(out CrewManager crew))
        {
            crews.Remove(crew);
        }
    }
}
