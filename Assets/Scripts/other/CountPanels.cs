using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CountPanels : MonoBehaviour
{
    // Start is called before the first frame update
    private void OnEnable()
    {
        string data = default;

        for (int i = 0; i < transform.childCount; i++)
        {
            data += transform.GetChild(i).position.x.ToString("f0") + "," + transform.GetChild(i).position.z.ToString("f0") + ", ";
        }

        print(data);
    }
}
