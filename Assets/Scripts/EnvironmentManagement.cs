using System.Collections;
using System.Collections.Generic;
using UnityEditor;
using UnityEngine;
using Unity.AI.Navigation;

public class EnvironmentManagement : MonoBehaviour
{
    private GameObject Environment;
    private NavMeshSurface currentSurface;

    // Start is called before the first frame update
    void Start()
    {
        //screen set==============================================
        GeneralSetting.AspectRatio = Screen.currentResolution.width / Screen.currentResolution.height;
        //Screen.SetResolution(Screen.currentResolution.width, Screen.currentResolution.height, true);        
        Screen.SetResolution(1280, 720, true);
        Camera.main.aspect = GeneralSetting.AspectRatio;
        Application.targetFrameRate = 60;

#if (UNITY_EDITOR)
        Camera.main.aspect = 16f/9f;
#endif

        Environment = GameObject.Find("Environment");

        small_one();
        
        currentSurface = Environment.GetComponentInChildren<NavMeshSurface>();
        currentSurface.BuildNavMesh();

        GameObject player = Instantiate(Resources.Load<GameObject>("prefabs/DefaultPlayer1"), new Vector3(0, 0, 0), Quaternion.Euler(0, 0, 0), Environment.transform);
    }

    // Update is called once per frame
    void Update()
    {
        
    }


    private void small_one()
    {
        GameObject walls = default;
        Vector2 center = Vector2.zero;

        //front room and glass to right
        center = new Vector2(6, 0);
        walls = Instantiate(Resources.Load<GameObject>("prefabs/walls/corner_wall_1"), new Vector3(center.x - 1, 0, center.y + 2), Quaternion.Euler(0, 90, 0), Environment.transform);
        walls = Instantiate(Resources.Load<GameObject>("prefabs/walls/wall_1"), new Vector3(center.x + 1, 0, center.y + 2), Quaternion.Euler(0, 180, 0), Environment.transform);
        walls = Instantiate(Resources.Load<GameObject>("prefabs/walls/corner_wall_1"), new Vector3(center.x - 1, 0, center.y - 2), Quaternion.Euler(0, 0, 0), Environment.transform);
        walls = Instantiate(Resources.Load<GameObject>("prefabs/walls/wall_1"), new Vector3(center.x + 1, 0, center.y - 2), Quaternion.Euler(0, 0, 0), Environment.transform);
        walls = Instantiate(Resources.Load<GameObject>("prefabs/walls/front glass_1"), new Vector3(center.x + 2, 0, center.y), Quaternion.Euler(0, 0, 0), Environment.transform);
        
        walls = Instantiate(Resources.Load<GameObject>("prefabs/walls/floor_1"), new Vector3(center.x - 1, 0, center.y + 2), Quaternion.Euler(0, 0, 0), Environment.transform);
        walls = Instantiate(Resources.Load<GameObject>("prefabs/walls/floor_1"), new Vector3(center.x + 1, 0, center.y + 2), Quaternion.Euler(0, 0, 0), Environment.transform);
        walls = Instantiate(Resources.Load<GameObject>("prefabs/walls/floor_1"), new Vector3(center.x - 1, 0, center.y), Quaternion.Euler(0, 0, 0), Environment.transform);
        walls = Instantiate(Resources.Load<GameObject>("prefabs/walls/floor_1"), new Vector3(center.x + 1, 0, center.y), Quaternion.Euler(0, 0, 0), Environment.transform);
        walls = Instantiate(Resources.Load<GameObject>("prefabs/walls/floor_1"), new Vector3(center.x - 1, 0, center.y - 2), Quaternion.Euler(0, 0, 0), Environment.transform);
        walls = Instantiate(Resources.Load<GameObject>("prefabs/walls/floor_1"), new Vector3(center.x + 1, 0, center.y - 2), Quaternion.Euler(0, 0, 0), Environment.transform);

        walls = Instantiate(Resources.Load<GameObject>("prefabs/walls/navmesh_floor"), new Vector3(center.x, 0, center.y), Quaternion.Euler(0, 0, 0), Environment.transform);
        walls.transform.localScale = new Vector3(4, 1, 6);


        //lower room 3/2 doors up 
        center = new Vector2(1, -3);
        walls = Instantiate(Resources.Load<GameObject>("prefabs/walls/corner_wall_1"), new Vector3(center.x - 2, 0, center.y - 1), Quaternion.Euler(0, 0, 0), Environment.transform);
        walls = Instantiate(Resources.Load<GameObject>("prefabs/walls/wall_1"), new Vector3(center.x, 0, center.y - 1), Quaternion.Euler(0, 0, 0), Environment.transform);
        walls = Instantiate(Resources.Load<GameObject>("prefabs/walls/corner_wall_1"), new Vector3(center.x + 2, 0, center.y - 1), Quaternion.Euler(0, -90, 0), Environment.transform);
        walls = Instantiate(Resources.Load<GameObject>("prefabs/walls/corner_wall_1"), new Vector3(center.x - 2, 0, center.y + 1), Quaternion.Euler(0, 90, 0), Environment.transform);
        walls = Instantiate(Resources.Load<GameObject>("prefabs/walls/corner_wall_1"), new Vector3(center.x + 2, 0, center.y + 1), Quaternion.Euler(0, 180, 0), Environment.transform);

        walls = Instantiate(Resources.Load<GameObject>("prefabs/walls/floor_1"), new Vector3(center.x - 2, 0, center.y + 1), Quaternion.Euler(0, 0, 0), Environment.transform);
        walls = Instantiate(Resources.Load<GameObject>("prefabs/walls/floor_1"), new Vector3(center.x, 0, center.y + 1), Quaternion.Euler(0, 0, 0), Environment.transform);
        walls = Instantiate(Resources.Load<GameObject>("prefabs/walls/floor_1"), new Vector3(center.x + 2, 0, center.y + 1), Quaternion.Euler(0, 0, 0), Environment.transform);
        walls = Instantiate(Resources.Load<GameObject>("prefabs/walls/floor_1"), new Vector3(center.x - 2, 0, center.y - 1), Quaternion.Euler(0, 0, 0), Environment.transform);
        walls = Instantiate(Resources.Load<GameObject>("prefabs/walls/floor_1"), new Vector3(center.x, 0, center.y - 1), Quaternion.Euler(0, 0, 0), Environment.transform);
        walls = Instantiate(Resources.Load<GameObject>("prefabs/walls/floor_1"), new Vector3(center.x + 2, 0, center.y - 1), Quaternion.Euler(0, 0, 0), Environment.transform);

        walls = Instantiate(Resources.Load<GameObject>("prefabs/walls/navmesh_floor"), new Vector3(center.x, 0, center.y), Quaternion.Euler(0, 0, 0), Environment.transform);
        walls.transform.localScale = new Vector3(6, 1, 4);


        //lower room 3/2 doors down 
        center = new Vector2(1, 3);
        walls = Instantiate(Resources.Load<GameObject>("prefabs/walls/corner_wall_1"), new Vector3(center.x - 2, 0, center.y - 1), Quaternion.Euler(0, 0, 0), Environment.transform);
        walls = Instantiate(Resources.Load<GameObject>("prefabs/walls/wall_1"), new Vector3(center.x, 0, center.y + 1), Quaternion.Euler(0, 180, 0), Environment.transform);
        walls = Instantiate(Resources.Load<GameObject>("prefabs/walls/corner_wall_1"), new Vector3(center.x + 2, 0, center.y - 1), Quaternion.Euler(0, -90, 0), Environment.transform);
        walls = Instantiate(Resources.Load<GameObject>("prefabs/walls/corner_wall_1"), new Vector3(center.x - 2, 0, center.y + 1), Quaternion.Euler(0, 90, 0), Environment.transform);
        walls = Instantiate(Resources.Load<GameObject>("prefabs/walls/corner_wall_1"), new Vector3(center.x + 2, 0, center.y + 1), Quaternion.Euler(0, 180, 0), Environment.transform);

        walls = Instantiate(Resources.Load<GameObject>("prefabs/walls/floor_1"), new Vector3(center.x - 2, 0, center.y + 1), Quaternion.Euler(0, 0, 0), Environment.transform);
        walls = Instantiate(Resources.Load<GameObject>("prefabs/walls/floor_1"), new Vector3(center.x, 0, center.y + 1), Quaternion.Euler(0, 0, 0), Environment.transform);
        walls = Instantiate(Resources.Load<GameObject>("prefabs/walls/floor_1"), new Vector3(center.x + 2, 0, center.y + 1), Quaternion.Euler(0, 0, 0), Environment.transform);
        walls = Instantiate(Resources.Load<GameObject>("prefabs/walls/floor_1"), new Vector3(center.x - 2, 0, center.y - 1), Quaternion.Euler(0, 0, 0), Environment.transform);
        walls = Instantiate(Resources.Load<GameObject>("prefabs/walls/floor_1"), new Vector3(center.x, 0, center.y - 1), Quaternion.Euler(0, 0, 0), Environment.transform);
        walls = Instantiate(Resources.Load<GameObject>("prefabs/walls/floor_1"), new Vector3(center.x + 2, 0, center.y - 1), Quaternion.Euler(0, 0, 0), Environment.transform);

        walls = Instantiate(Resources.Load<GameObject>("prefabs/walls/navmesh_floor"), new Vector3(center.x, 0, center.y), Quaternion.Euler(0, 0, 0), Environment.transform);
        walls.transform.localScale = new Vector3(6, 1, 4);

        //others
        center = new Vector2(0, 0);
        walls = Instantiate(Resources.Load<GameObject>("prefabs/walls/floor_1"), new Vector3(center.x + 3, 0, center.y), Quaternion.Euler(0, 0, 0), Environment.transform);
        walls = Instantiate(Resources.Load<GameObject>("prefabs/walls/floor_1"), new Vector3(center.x + 1, 0, center.y), Quaternion.Euler(0, 0, 0), Environment.transform);
        walls = Instantiate(Resources.Load<GameObject>("prefabs/walls/floor_1"), new Vector3(center.x - 1, 0, center.y), Quaternion.Euler(0, 0, 0), Environment.transform);
        walls = Instantiate(Resources.Load<GameObject>("prefabs/walls/floor_1"), new Vector3(center.x - 3, 0, center.y), Quaternion.Euler(0, 0, 0), Environment.transform);
        walls = Instantiate(Resources.Load<GameObject>("prefabs/walls/floor_1"), new Vector3(center.x - 5, 0, center.y), Quaternion.Euler(0, 0, 0), Environment.transform);

        walls = Instantiate(Resources.Load<GameObject>("prefabs/walls/navmesh_floor"), new Vector3(-1, 0, 0), Quaternion.Euler(0, 0, 0), Environment.transform);
        walls.transform.localScale = new Vector3(10, 1, 2);
    }

}
