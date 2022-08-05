using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class UIManager : MonoBehaviour
{
    [SerializeField] private Camera mainCam;

    private List<UIObject> UITransforms = new List<UIObject>();

    private void Start()
    {
        mainCam = GameObject.Find("Main Camera").GetComponent<Camera>();
        //Vector3 OnScreenPosition = mainCam.WorldToScreenPoint(OtherGamers[i].PlayerTransform.position);
    }

    public static GameObject GetUIPrefab(UIPanelTypes _panel)
    {
        GameObject result = default;

        switch(_panel)
        {
            case UIPanelTypes.progress_bar:
                result = Resources.Load<GameObject>("prefabs/UI/progress mark");
                break;

            case UIPanelTypes.information_mark:
                result = Resources.Load<GameObject>("prefabs/UI/Information mark");
                break;

            case UIPanelTypes.health_bar:
                result = Resources.Load<GameObject>("prefabs/UI/health bar");
                break;
        }

        return result;
    }

    public void AddNewUIObject(Transform _transform, UIPanelTypes _currentPanel)
    {
        print("added");
        GameObject UIPanel = Instantiate(GetUIPrefab(_currentPanel), GameObject.Find("MainCanvas").transform);
        UITransforms.Add(new UIObject(_transform, UIPanel.GetComponent<RectTransform>(), _currentPanel));
    }

    private void Update()
    {
        print("rfreger");

        if (UITransforms.Count>0)
        {
            for (int i = 0; i < UITransforms.Count; i++)
            {
                Vector3 OnScreenPosition = mainCam.WorldToScreenPoint(UITransforms[i].transform.position);
                UITransforms[i].rectTransform.anchoredPosition = new Vector2(OnScreenPosition.x, OnScreenPosition.y);
            }
        }
    }

}

public struct UIObject
{
    public Transform transform;
    public RectTransform rectTransform;
    public UIPanelTypes currentPanel;

    public UIObject(Transform _transform, RectTransform _rectTransform, UIPanelTypes _currentPanel)
    {
        transform = _transform;
        rectTransform = _rectTransform;
        currentPanel = _currentPanel;
    }
}
