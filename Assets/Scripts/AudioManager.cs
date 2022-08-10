using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[RequireComponent(typeof(AudioSource))]
public class AudioManager : MonoBehaviour
{
    [SerializeField] private AudioSource audiosourse;
    [SerializeField] private settings GeneralSettings;
    
    
    private AudioClip simpleClick, grabSound;


    // Start is called before the first frame update
    void Start()
    {
        audiosourse = GetComponent<AudioSource>();
        audiosourse.volume = GeneralSettings.AudioSourceVolume_UI;
        audiosourse.loop = false;
        audiosourse.playOnAwake = false;

        simpleClick = Resources.Load<AudioClip>("audio/sounds/tiny click");
        grabSound = Resources.Load<AudioClip>("audio/sounds/grab something");
    }

    public void MakeClick()
    {        
        audiosourse.clip = simpleClick;
        audiosourse.Play();
    }

    public void MakeGrab()
    {
        audiosourse.clip = simpleClick;
        audiosourse.Play();
    }


}
