using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using DG.Tweening;

public class AtmoActivity : MonoBehaviour
{
    public string _name;
    public float _from;
    public float _to;
    public float _time;
    public float cur_time;

    public MeshRenderer mesh;
    private Material material;
    private bool isOne;

    private void Start()
    {
        Material newMat = Instantiate(mesh.material);
        mesh.material = newMat;
        material = mesh.material;
    }

    // Update is called once per frame
    void Update()
    {
        
        if (cur_time> _time)
        {
            cur_time = 0;

            if (isOne)
            {
                isOne = false;
                material.SetFloat(_name, _from);
                material.DOFloat(_to, _name, _time);
            }
            else
            {
                isOne = true;
                material.SetFloat(_name, _to);
                material.DOFloat(_from, _name, _time);
            }
            
        }
        else
        {
            cur_time += Time.deltaTime;
        }
        
    }
}

public class atmo
{
    public string _name;    
    public float _from;
    public float _to;
    public float _time;
    public float cur_time;
}
