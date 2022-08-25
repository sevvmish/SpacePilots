using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class UIManager : MonoBehaviour
{
    //UI information mark
    private GameObject uiMark;
    private RectTransform uiMarkRect;
    private Vector3 OnScreenPosition;

    private Transform UIPositionPoint;

    private MakeActiveInTimer blinker;
    //==================

    public UIManager(Transform _UIPositionPoint, UIPanelTypes whatTypeOfPanel, UIIconTypes whatTypeOfSprite, Color backColor, Color iconColor)
    {
        UIPositionPoint = _UIPositionPoint;

        uiMark = Instantiate(GetUIPrefab(whatTypeOfPanel), GameObject.Find("MainCanvas").transform);
        uiMark.transform.GetChild(1).GetComponent<Image>().sprite = GetUIIconSprite(whatTypeOfSprite);
        uiMark.transform.GetChild(0).GetComponent<Image>().color = backColor;
        uiMark.transform.GetChild(1).GetComponent<Image>().color = iconColor;
        uiMarkRect = uiMark.GetComponent<RectTransform>();        
        uiMarkRect.gameObject.SetActive(false);

        blinker = uiMark.GetComponent<MakeActiveInTimer>();
        blinker.enabled = false;
    }

    public bool IsBlinking
    {
        get
        {
            return blinker.enabled;
        }

        set
        {
            blinker.enabled = value;
        }
    }


    public bool IsLeaveEnabledAfterBlinking
    {
        get
        {
            return blinker.isLeaveEnabled;
        }

        set
        {
            blinker.isLeaveEnabled = value;
        }
    }

    public float HowLongToBlink
    {
        get
        {
            return blinker.howLong;
        }

        set
        {
            blinker.howLong = value;
        }
    }

    public float WhatIntervalToBlink
    {
        get
        {
            return blinker.whatInterval;
        }

        set
        {
            blinker.whatInterval = value;
        }
    }



    private void UpdateUIPosition(Camera camera)
    {
        OnScreenPosition = camera.WorldToScreenPoint(UIPositionPoint.position);
        uiMarkRect.anchoredPosition = new Vector2(OnScreenPosition.x, OnScreenPosition.y + 40);
    }

    public void ShowUI()
    {
        if (!uiMarkRect.gameObject.activeSelf)
        {
            GameManagement.MainUIHandler += UpdateUIPosition;
            uiMarkRect.gameObject.SetActive(true);
        }
    }

    public void HideUI()
    {
        if (uiMarkRect.gameObject.activeSelf)
        {            
            uiMarkRect.gameObject.SetActive(false);
        }

        GameManagement.MainUIHandler -= UpdateUIPosition;
    }


    public static Sprite GetUIIconSprite(UIIconTypes _panel)
    {
        Sprite result = default;

        switch (_panel)
        {
            case UIIconTypes.fire_extinguisher:
                result = Resources.Load<Sprite>("prefabs/sprites/fire ext");
                break;

            case UIIconTypes.wrench:
                result = Resources.Load<Sprite>("prefabs/sprites/wrench");
                break;

            case UIIconTypes.energy_fuel:
                result = Resources.Load<Sprite>("prefabs/sprites/energy barrel");
                break;

            case UIIconTypes.shell_for_cannon:
                result = Resources.Load<Sprite>("prefabs/sprites/shell cannon");
                break;

            case UIIconTypes.fire:
                result = Resources.Load<Sprite>("prefabs/sprites/fire sign");
                break;

            case UIIconTypes.frost:
                result = Resources.Load<Sprite>("prefabs/sprites/cold sign");
                break;

            case UIIconTypes.energy:
                result = Resources.Load<Sprite>("prefabs/sprites/energy sign");
                break;

            case UIIconTypes.radiation:
                result = Resources.Load<Sprite>("prefabs/sprites/radiation sign");
                break;

            case UIIconTypes.ok:
                result = Resources.Load<Sprite>("prefabs/sprites/ok");
                break;

            case UIIconTypes.no:
                result = Resources.Load<Sprite>("prefabs/sprites/no");
                break;
        }

        return result;
    }

    public static GameObject GetUIPrefab(UIPanelTypes _panel)
    {
        GameObject result = default;

        switch(_panel)
        {
            case UIPanelTypes.progress_bar:
                result = Resources.Load<GameObject>("prefabs/UI/progress bar");
                break;

            case UIPanelTypes.information_mark:
                result = Resources.Load<GameObject>("prefabs/UI/Information mark");
                break;

            case UIPanelTypes.health_bar:
                result = Resources.Load<GameObject>("prefabs/UI/health bar");
                break;

            case UIPanelTypes.alert_mark:
                result = Resources.Load<GameObject>("prefabs/UI/alert mark");
                break;
        }

        return result;
    }

  

}
