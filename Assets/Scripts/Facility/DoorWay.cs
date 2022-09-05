using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using DG.Tweening;

[RequireComponent(typeof(BoxCollider))]
public class DoorWay : MonoBehaviour
{
    [SerializeField] private Transform leftDoor, rightDoor, leftDoorClosePosition, rightDoorClosePosition, leftDoorOpenPosition, rightDoorOpenPosition;
    [SerializeField] private float openSpeed;
    [SerializeField] private AudioSource audio;
    [SerializeField] private AudioClip doorOpenSound;
    [SerializeField] private AudioClip doorCloseSound;


    private bool isDoorOpened, isDoorClosing, isDoorOpening;
    private float defaultDelta;
    private HashSet<GameObject> crew = new HashSet<GameObject>();

    private void OnEnable()
    {
        isDoorOpened = false;
        isDoorClosing = false;
        isDoorOpening = false;

        leftDoor.DOLocalMove(leftDoorClosePosition.localPosition, 0);
        rightDoor.DOLocalMove(rightDoorClosePosition.localPosition, 0);

        defaultDelta = Vector3.Distance(leftDoorOpenPosition.localPosition, leftDoorClosePosition.localPosition);
                
    }



    private void Update()
    {
        if (crew.Count == 0 && (isDoorOpened || isDoorOpening))
        {
            StartCoroutine(doorIsClosing());
        }
    }

    private void OnTriggerEnter(Collider other)
    {
        if (other.gameObject.CompareTag("Crew"))
        {            
            if (!crew.Contains(other.gameObject))
            {
                crew.Add(other.gameObject);
            }

            if (!isDoorOpened || isDoorClosing)
            {
                StartCoroutine(doorIsOpening());
            }
        }
    }

    private void OnTriggerExit(Collider other)
    {
        if (other.gameObject.CompareTag("Crew"))
        {
            if (crew.Contains(other.gameObject))
            {
                crew.Remove(other.gameObject);
            }

            if (crew.Count==0 && (isDoorOpened || isDoorOpening))
            {
                StartCoroutine(doorIsClosing());
            }
        }
    }

    private IEnumerator doorIsClosing()
    {
        StopCoroutine(doorIsOpening());
        if (audio.isPlaying) audio.Stop();
        audio.clip = doorCloseSound;
        audio.Play();

        isDoorClosing = true;
        isDoorOpening = false;
        
        float speed = openSpeed * Vector3.Distance(leftDoor.localPosition, leftDoorClosePosition.localPosition) / defaultDelta;

        leftDoor.DOLocalMove(leftDoorClosePosition.localPosition, speed);
        rightDoor.DOLocalMove(rightDoorClosePosition.localPosition, speed);
        yield return new WaitForSeconds(speed);

        audio.Stop();
        isDoorOpened = false;
        isDoorClosing = false;        
    }

    private IEnumerator doorIsOpening()
    {
        StopCoroutine(doorIsClosing());
        if (audio.isPlaying) audio.Stop();
        audio.clip = doorOpenSound;
        audio.Play();

        isDoorClosing = false;
        isDoorOpening = true;        

        float speed = openSpeed * Vector3.Distance(leftDoor.localPosition, leftDoorOpenPosition.localPosition) / defaultDelta;

        leftDoor.DOLocalMove(leftDoorOpenPosition.localPosition, speed);
        rightDoor.DOLocalMove(rightDoorOpenPosition.localPosition, speed);
        yield return new WaitForSeconds(speed);

        audio.Stop();
        isDoorOpened = true;
        isDoorOpening = false;
    }


}
