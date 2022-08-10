using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[CreateAssetMenu(fileName = "settings", menuName = "Settings")]
public class settings : ScriptableObject
{
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

    //crew settings
    public Vector3 StrenghtOfShakeOnHighlightingCrew = new Vector3(0.6f, 0.15f, 0.6f);
    public float TimeForShakeForCrew = 0.5f;

    //Facility settings
    public Vector3 StrenghtOfShakeOnHighlightingFacility = new Vector3(0.6f, 0.3f, 0.6f);
    public float TimeForShakeForFacility = 0.5f;

    //instrument settings
    public Vector3 StrenghtOfShakeOnHighlightingInstruments = new Vector3(0.6f, 0.3f, 0.6f);
    public float TimeForShakeForInstruments = 0.5f;

    //SOUND=================================
    public float AudioSourceVolume_incidents = 0.2f;
    public float AudioSourceVolume_instruments = 0.5f;
    public float AudioSourceVolume_crew = 0.5f;
    public float AudioSourceVolume_UI = 1f;

}
