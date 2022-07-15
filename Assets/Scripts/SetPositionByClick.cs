using System.Collections;
using System.Collections.Generic;
using Unity.AI.Navigation;
using UnityEngine;
using UnityEngine.AI;


public class SetPositionByClick : MonoBehaviour
{
    // Start is called before the first frame update

    private Camera mainCam;
    private Ray ray;
    private RaycastHit hit;
    private NavMeshAgent agent;


    void Start()
    {
        mainCam = GameObject.Find("Main Camera").GetComponent<Camera>();
        agent = GetComponent<NavMeshAgent>();
        //p.AddData();
        //p.BuildNavMesh();

        //GameObject scene = Instantiate(Resources.Load<GameObject>("prefabs/build2"));
        //scene.transform.position = new Vector3(3, 0, 3);
        
    }

    // Update is called once per frame
    void Update()
    {
        if (Input.GetMouseButtonDown(0))
        {
            ray = mainCam.ScreenPointToRay(Input.mousePosition);

            if (Physics.Raycast(ray, out hit))
            {
                
                agent.Stop();
                agent.Resume();
                agent.SetDestination(hit.point);
               
            }
        }
    }
}
