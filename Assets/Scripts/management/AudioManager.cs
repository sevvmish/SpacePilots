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

        simpleClick = Resources.Load<AudioClip>("audio/sounds/tiny click short");
        grabSound = Resources.Load<AudioClip>("audio/sounds/grab something");
    }

    public void MakeClick()
    {
        if (audiosourse.isPlaying && audiosourse.clip == simpleClick) return;
        audiosourse.clip = simpleClick;
        audiosourse.Play();
    }

    public void MakeGrab()
    {
        if (audiosourse.isPlaying) audiosourse.Stop();
        audiosourse.clip = simpleClick;
        audiosourse.Play();
    }


}
