using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using DG.Tweening;
using TMPro;

public class UIManager : MonoBehaviour
{
    //UI information mark
    private GameObject uiMark;
    private RectTransform uiMarkRect;
    private Vector3 OnScreenPosition;
    private UIPanelTypes currentUIPanelType;
    private Transform UIPositionPoint;

    private MakeActiveInTimer blinker;

    float scaleKoeff;
    //==================



    public UIManager(Transform _UIPositionPoint, UIPanelTypes whatTypeOfPanel, UIIconTypes whatTypeOfSprite, Color backColor, Color iconColor)
    {
        UIPositionPoint = _UIPositionPoint;
        currentUIPanelType = whatTypeOfPanel;

        uiMark = Instantiate(GetUIPrefab(whatTypeOfPanel), GameObject.Find("MainCanvas").transform);
        uiMark.transform.GetChild(1).GetComponent<Image>().sprite = GetUIIconSprite(whatTypeOfSprite);
        uiMark.transform.GetChild(0).GetComponent<Image>().color = backColor;
        uiMark.transform.GetChild(1).GetComponent<Image>().color = iconColor;
        uiMarkRect = uiMark.GetComponent<RectTransform>();        
        uiMarkRect.gameObject.SetActive(false);

        blinker = uiMark.GetComponent<MakeActiveInTimer>();
        blinker.enabled = false;
    }

    public UIManager(Transform _UIPositionPoint, UIPanelTypes whatTypeOfPanel)
    {
        UIPositionPoint = _UIPositionPoint;
        currentUIPanelType = whatTypeOfPanel;

        uiMark = Instantiate(GetUIPrefab(whatTypeOfPanel), GameObject.Find("MainCanvas").transform);        
        uiMarkRect = uiMark.GetComponent<RectTransform>();
        uiMarkRect.gameObject.SetActive(false);                
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

    public bool IsUIEnabled
    {
        get
        {
            return uiMarkRect.gameObject.activeSelf;
        }

        set
        {
            uiMarkRect.gameObject.SetActive(value);
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
        
        switch(currentUIPanelType)
        {
            case UIPanelTypes.alert_mark:
                uiMarkRect.anchoredPosition = new Vector2(OnScreenPosition.x, OnScreenPosition.y + 40);
                break;

            case UIPanelTypes.health_bar :
                uiMarkRect.anchoredPosition = new Vector2(OnScreenPosition.x, OnScreenPosition.y + 40);
                break;

            case UIPanelTypes.information_mark :
                uiMarkRect.anchoredPosition = new Vector2(OnScreenPosition.x, OnScreenPosition.y + 40);
                break;

            case UIPanelTypes.level_data_stars:
                uiMarkRect.anchoredPosition = new Vector2(OnScreenPosition.x, OnScreenPosition.y);
                break;

            case UIPanelTypes.progress_bar:
                uiMarkRect.anchoredPosition = new Vector2(OnScreenPosition.x, OnScreenPosition.y + 40);
                break;

        }
        
        uiMarkRect.anchoredPosition = new Vector2(OnScreenPosition.x, OnScreenPosition.y + 40);
    }


    public bool isShown()
    {
        return uiMarkRect.gameObject.activeSelf;
    }

    public void ShowUI()
    {
        if (!uiMarkRect.gameObject.activeSelf)
        {
            GameManagement.MainUIHandler += UpdateUIPosition;
            MenuManagement.MainUIHandler += UpdateUIPosition;
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
        MenuManagement.MainUIHandler -= UpdateUIPosition;
    }

    public void ChangeScale(float koeff)
    {
        scaleKoeff = koeff;
        uiMarkRect.localScale = Vector3.one * scaleKoeff;
    }


    public void MakeShake(float _time)
    {
        uiMarkRect.DOShakeScale(_time, Vector3.one * scaleKoeff);
        //uiMarkRect.DOPunchScale(Vector3.one * scaleKoeff, _time);
    }

    public void SetLevelNumber(int number)
    {
        uiMark.transform.GetChild(9).GetComponent<TextMeshProUGUI>().text = number.ToString();
    }

    public void SetStarsForLevelData(int howManyStars)
    {
        switch(howManyStars)
        {
            case 0:
                uiMark.transform.GetChild(5).gameObject.SetActive(false);
                uiMark.transform.GetChild(6).gameObject.SetActive(false);
                uiMark.transform.GetChild(7).gameObject.SetActive(false);
                break;

            case 1:
                uiMark.transform.GetChild(5).gameObject.SetActive(true);
                uiMark.transform.GetChild(6).gameObject.SetActive(false);
                uiMark.transform.GetChild(7).gameObject.SetActive(false);
                break;

            case 2:
                uiMark.transform.GetChild(5).gameObject.SetActive(true);
                uiMark.transform.GetChild(6).gameObject.SetActive(true);
                uiMark.transform.GetChild(7).gameObject.SetActive(false);
                break;

            case 3:
                uiMark.transform.GetChild(5).gameObject.SetActive(true);
                uiMark.transform.GetChild(6).gameObject.SetActive(true);
                uiMark.transform.GetChild(7).gameObject.SetActive(true);
                break;
        }
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

            case UIIconTypes.whaaat:
                result = Resources.Load<Sprite>("prefabs/sprites/whaaat");
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

            case UIPanelTypes.level_data_stars:
                result = Resources.Load<GameObject>("prefabs/UI/level data stars");
                break;
        }

        return result;
    }

  

}
