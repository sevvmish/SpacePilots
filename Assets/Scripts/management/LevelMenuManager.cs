using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using DG.Tweening;

public class LevelMenuManager : MonoBehaviour
{
    public int LevelNumber;

    [SerializeField] private settings GeneralSettings;
    [SerializeField] private float timeToShine = 0.6f;
    [SerializeField] private float timeToOff = 0.5f;

    private MeshRenderer mesh;
    private Material material;
    private Color color;
    private float cur_time;
    private float maxLight = 2;
    private bool isON, isHighlightEffectInProcess, isLevelStarsShown;


    private UIManager levelUIstars;

    public bool IsON
    {
        get
        {
            return isON;
        }
        set
        {
            if (value && !isON)
            {
                material.DOColor(color * maxLight, "_EmissionColor", timeToShine);
                material.DOFade(1, 0);
            }
            else if (!value && isON)
            {
                material.DOColor(color * 0, "_EmissionColor", timeToOff);
                material.DOFade(0, timeToOff);
            }

            isON = value;
        }
    }

    // Start is called before the first frame update
    void Start()
    {
        mesh = GetComponent<MeshRenderer>();

        Material newMat = Instantiate(mesh.material);
        mesh.material = newMat;
        material = mesh.material;
        color = material.GetColor("_EmissionColor");

        IsON = true;
        levelUIstars = new UIManager(transform, UIPanelTypes.level_data_stars);
        levelUIstars.HideUI();

        if (GeneralSettings.GameLevelsData[LevelNumber] != null && GeneralSettings.GameLevelsData[LevelNumber].IsVisited)
        {
            OpenLevelStarsUI();
        }
    }

    // Update is called once per frame
    void Update()
    {
        if (!isLevelStarsShown)
        {
            if (cur_time > timeToOff)
            {
                cur_time = 0;
                IsON = true;
            }
            else
            {
                cur_time += Time.deltaTime;
                if (IsON) IsON = false;
            }
        }
        
        
    }

    public void PlayHighlight()
    {
        if (!isHighlightEffectInProcess)
        {
            StartCoroutine(playHighlightEffect());
        }
    }

    private IEnumerator playHighlightEffect()
    {
        isHighlightEffectInProcess = true;
        transform.DOPunchScale(Vector3.one, 1.5f);
        yield return new WaitForSeconds(1.5f);
        isHighlightEffectInProcess = false;
    }

    private void OnTriggerEnter(Collider other)
    {
        if (other!=null && other.CompareTag("Player"))
        {
            print(other.name);

            if (GeneralSettings.GameLevelsData[LevelNumber] != null && !GeneralSettings.GameLevelsData[LevelNumber].IsVisited)
            {                
                OpenLevelStarsUI();

                SaveLoad.Save(GeneralSettings.GameLevelsData);
            }
        }
    }

    private void OpenLevelStarsUI()
    {
        GeneralSettings.GameLevelsData[LevelNumber].IsVisited = true;
        isLevelStarsShown = true;
        IsON = false;
        levelUIstars.ShowUI();
        levelUIstars.SetStarsForLevelData(GeneralSettings.GameLevelsData[LevelNumber].CurrentStarsProgress);
        levelUIstars.SetLevelNumber(GeneralSettings.GameLevelsData[LevelNumber].LevelNumber);
    }
}
