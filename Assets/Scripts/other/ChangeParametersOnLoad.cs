using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ChangeParametersOnLoad : MonoBehaviour
{
    public ParamToChange[] dataToChange;

    private void OnEnable()
    {
        if (dataToChange.Length > 0)
        {
            for (int i = 0; i < dataToChange.Length; i++)
            {
                dataToChange[i].Activate();
            }
        }
    }


}

[System.Serializable]
public struct ParamToChange
{
    public WhatToChange paramToChange;
    public Transform transform;
    public float dataFrom, dataTo;

    public ParamToChange(WhatToChange _paramToChange, Transform _transform, float _dataFrom, float _dataTo)
    {
        paramToChange = _paramToChange;
        transform = _transform;
        dataFrom = _dataFrom;
        dataTo = _dataTo;
    }

    public void Activate()
    {
        switch(paramToChange)
        {
            case WhatToChange.positionX:
                transform.position = new Vector3(Random.Range(dataFrom, dataTo), transform.position.y, transform.position.z);
                break;

            case WhatToChange.positionY:
                transform.position = new Vector3(transform.position.x, Random.Range(dataFrom, dataTo), transform.position.z);
                break;

            case WhatToChange.positionZ:
                transform.position = new Vector3(transform.position.x, transform.position.y, Random.Range(dataFrom, dataTo));
                break;

            case WhatToChange.rotationX:
                transform.rotation = Quaternion.Euler(new Vector3(Random.Range(dataFrom, dataTo), transform.eulerAngles.y, transform.eulerAngles.z));
                break;

            case WhatToChange.rotationY:
                transform.rotation = Quaternion.Euler(new Vector3(transform.eulerAngles.x, Random.Range(dataFrom, dataTo), transform.eulerAngles.z));
                break;

            case WhatToChange.rotationZ:
                transform.rotation = Quaternion.Euler(new Vector3(transform.eulerAngles.x, transform.eulerAngles.y, Random.Range(dataFrom, dataTo)));
                break;

            case WhatToChange.scaleX:
                transform.localScale = new Vector3(Random.Range(dataFrom, dataTo), transform.localScale.y, transform.localScale.z);
                break;

            case WhatToChange.scaleY:
                transform.localScale = new Vector3(transform.localScale.x, Random.Range(dataFrom, dataTo), transform.localScale.z);
                break;

            case WhatToChange.scaleZ:
                transform.localScale = new Vector3(transform.localScale.x, transform.localScale.y, Random.Range(dataFrom, dataTo));
                break;
        }
    }

}

[System.Serializable]
public enum WhatToChange
{
    positionX,
    positionY,
    positionZ,
    rotationX,
    rotationY,
    rotationZ,
    scaleX,
    scaleY,
    scaleZ
}
