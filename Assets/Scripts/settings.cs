using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[CreateAssetMenu(fileName = "settings", menuName = "Settings")]
public class settings : ScriptableObject
{
    public static SystemLanguage CurrentLanguage;
   
    public const int SERVER_TCP_PORT = 2300;
    public const int SERVER_UDP_PORT = 2301;
    public const string SERVER_IP = "192.168.0.108";

    public static Encryption PlayerEncryption = new Encryption();
    public static byte[] SecretKey;
    public static string PacketID;

    //================================================================================

    public int ScreenHeight = 720;
    public int ScreenWidth = 1280;
    public float AspectRatio = 2f;
    public int targetFrameRate = 60;

    //current game setting
    public int CurrentLevel = 1;
    public int CurrentStars;


    //crew settings
    public Vector3 StrenghtOfShakeOnHighlightingCrew = new Vector3(0.6f, 0.15f, 0.6f);
    public float TimeForShakeForCrew = 0.5f;
    public float CrewBaseSpeed = 5f;
    public float CrewSpeedKoeff = 1f;
    public float CrewBaseHealth = 10f;
    public float CrewHealthKoeff = 1f;
    public float CrewHealthRegenPerSecond = 0.1f;
    public float CrewRespawnTime = 5f;

    //Facility settings
    public Vector3 StrenghtOfShakeOnHighlightingFacility = new Vector3(0.6f, 0.3f, 0.6f);
    public float TimeForShakeForFacility = 0.5f;

    //instrument settings
    public Vector3 StrenghtOfShakeOnHighlightingInstruments = new Vector3(0.8f, 0.5f, 0.8f);
    public float TimeForShakeForInstruments = 0.4f;

    //incident settings
    public float IncidentBaseHealth_fire = 2f;
    public float IncidentHealthKoeff_fire = 1f;
    
    public float IncidentBaseHealth_wreck = 2f;
    public float IncidentHealthKoeff_wreck = 1f;

    public float FireDamageAmount = 1f;
    public float PoisonDamageAmount = 1f;

    //supply settings
    public Vector3 StrenghtOfShakeOnHighlightingSupply = new Vector3(1f, 0.6f, 1f);
    public float TimeForShakeForSupply = 0.3f;
      
    //BLOOM
    public float BaseBloomIntensityColor = 1.5f;

    //SOUND=================================
    public float AudioSourceVolume_incidents = 0.2f;
    public float AudioSourceVolume_instruments = 0.5f;
    public float AudioSourceVolume_crew = 0.5f;
    public float AudioSourceVolume_UI = 0.7f;

    
    public levels[] GameLevelsData;

}

[System.Serializable]
public class levels
{
    public int LevelNumber;
    public string LevelName;
    public int StarsRequiredToEnter;
    public int CurrentStarsProgress;
    public bool IsVisited;
}

[Serializable]
public enum TypeOfLevel
{
    time_limit,
    fighting,
    survival,
    tutorial
}
