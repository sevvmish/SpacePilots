using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Enums_n_Interfaces : MonoBehaviour
{
    public static Material GetBaseMaterial(Transform transform)
    {
        if (transform.GetComponent<MeshRenderer>() != null)
        {
            return transform.GetComponent<MeshRenderer>().material;
        }

        if (transform.GetComponent<SkinnedMeshRenderer>() != null)
        {
            return transform.GetComponent<SkinnedMeshRenderer>().material;
        }

        if (transform.GetComponent<ParticleSystemRenderer>() != null)
        {            
            return transform.GetComponent<ParticleSystemRenderer>().material;
        }

        return default;
    }

    public static void ChangeMaterial(Material _material, Transform transform)
    {
        if (transform.GetComponent<MeshRenderer>() != null)
        {
            transform.GetComponent<MeshRenderer>().material = _material;
            return;
        }

        if (transform.GetComponent<SkinnedMeshRenderer>() != null)
        {
            transform.GetComponent<SkinnedMeshRenderer>().material = _material;
            return;
        }

        if (transform.GetComponent<ParticleSystemRenderer>() != null)
        {
            transform.GetComponent<ParticleSystemRenderer>().material = _material;
            return;
        }

        print("error in changing material");
    }
}


//MAIN INTERFACES==================================================
public interface IPointOfInteraction
{
    public Vector3 GetPointOfInteraction();
}

public interface ITakenAndMovable
{
    public System.Object GetTypeOfObject();
    public GameObject GiveAwayTakeble();    
    public void MakeThrownAway();
    public bool IsCanBeTakenByCrew();
    public void RotateWhileThrownAway();
}

public interface IHighlightable
{
    public void HighlightCurrentObject();    

    public IEnumerator HandleCurrentHighlight();
}


public interface IUIBars
{    

    public void UpdateUIPosition(Camera camera);

    public void ShowUI();

    public void HideUI();

    public IEnumerator ShowUIBarWhileActive();
}





//================================================================

//SPECIALLY FOR CREW==============================================
public enum CrewSpecialization
{
    tester = 0,
    Captain,
    Engineer,
    Soldier,
    Scientist
}

public enum CrewMemberStates
{
    idle = 0,
    run,
    walk,
    repairing,
    fire_extinguish,
    stunned,
    dead
}
//==================================================================


//SUPPLY ENUMS======================================================
public enum SuppliesType
{
    tester = 0,
    engine_fuel,
    shell_for_cannon    
}

public enum SupplyState
{
    inProducer = 0,
    inConsumer,
    inCrewHands,
    isThrownAway
}
//===================================================================


//INCIDENTS ENUMS======================================================
public enum IncidentsType
{
    tester = 0,
    fire,
    simple_wreck,
    smoke_after_fire,
    after_wreck
}
//===================================================================


//INSTRUMENTS ENUMS======================================================
public enum InstrumentsType
{
    tester,
    fire_extinguisher,
    repair_kit
}
//===================================================================


//UI======================================================
public enum UIPanelTypes
{
    progress_bar,
    information_mark,
    health_bar
}

public enum UIIconTypes
{
    fire_extinguisher,
    wrench,
    energy_fuel,
    shell_for_cannon,
    fire,
    frost,
    energy,
    repair,
    radiation
}

//===================================================================


//CREW NEGATIVE EFFECTS ENUMS======================================================
public enum NegativeEffects
{
    burning,
    electricity
}
//===================================================================