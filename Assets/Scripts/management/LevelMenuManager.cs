using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using DG.Tweening;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

public class LevelMenuManager : MonoBehaviour
{
    public int LevelNumber;

    [SerializeField] private settings GeneralSettings;
    [SerializeField] private float timeToShine = 0.6f;
    [SerializeField] private float timeToOff = 0.5f;
    [SerializeField] private MenuManagement menuManager;

    private MeshRenderer mesh;
    private Material material;
    private Color color;
    private float cur_time;
    private float maxLight = 2;
    private float highlightEffect = 0.5f;
    private bool isON, isShipCollided;

    

    private UIManager levelUIstars, levelUISelect;

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

        

        if (GeneralSettings.GameLevelsData[LevelNumber] != null)
        {
            OpenLevelStarsUI();
        }

        Invoke("InitSelectableUI", 0.1f);
    }

    private void InitSelectableUI()
    {
        levelUISelect = new UIManager(transform, UIPanelTypes.level_data_select);
        levelUISelect.HideUI();
        levelUISelect.SetPositionOffset(150, 113);

        levelUISelect.yesButton().onClick.AddListener(() =>
        {
            menuManager.PlayGoodClick();
            menuManager.makeScreenOff();
            UIManager.ResetHandlers();
            Invoke("ChangeSceneToGame", 1);
        });

        levelUISelect.noButton().onClick.AddListener(() =>
        {
            menuManager.PlayNegativeClick();
            levelUISelect.HideUI();
        });
    }

    public void PlayHighlight() => levelUIstars.ShowHighLight();
    public void StopHighlight() => levelUIstars.HideHighLight();


    private IEnumerator playHighlightEffect()
    {
        //isHighlightEffectInProcess = true;
        transform.DOPunchScale(Vector3.one, highlightEffect);
        yield return new WaitForSeconds(highlightEffect);
        //isHighlightEffectInProcess = false;
    }

    
    private void OpenLevelStarsUI()
    {
        GeneralSettings.GameLevelsData[LevelNumber].IsVisited = true;
        IsON = false;
        levelUIstars.ShowUI(GeneralSettings.GameLevelsData[LevelNumber], GeneralSettings.CurrentStars);        
    }

    private void OnTriggerStay(Collider other)
    {
        if (!isShipCollided && MenuManagement.currentLevel == this && GeneralSettings.GameLevelsData[LevelNumber].StarsRequiredToEnter <= GeneralSettings.CurrentStars)
        {
            isShipCollided = true;            
            levelUISelect.ShowUI();
            menuManager.PlayOpenClick();
            
        }
    }

    private void OnTriggerExit(Collider other)
    {
        if (other.CompareTag("Player"))
        {
            isShipCollided = false;
        }

        if (levelUISelect.isShown())
        {
            levelUISelect.HideUI();
        }
    }

    private void ChangeSceneToGame()
    {
        
        GeneralSettings.CurrentLevel = LevelNumber;
        
        SceneManager.LoadScene("GameScene");
    }
}
