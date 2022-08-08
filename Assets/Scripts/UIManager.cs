using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class UIManager : MonoBehaviour
{

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
        }

        return result;
    }

  

}
