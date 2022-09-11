using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Languages : MonoBehaviour
{
    public static localization lang = new localization();

    private void Awake()
    {
        settings.CurrentLanguage = Application.systemLanguage;
        if (settings.CurrentLanguage == SystemLanguage.Russian || settings.CurrentLanguage == SystemLanguage.Belarusian || settings.CurrentLanguage == SystemLanguage.Ukrainian)
        {
            lang.Rus();
        }
    }
        
}

public class localization
{
    public string LoginText = "ENTER";
    public string PlayText = "PLAY";

    public void Rus()
    {
        LoginText = "¬Œ…“»";
        PlayText = "»√–¿“‹";
    }
    
}
