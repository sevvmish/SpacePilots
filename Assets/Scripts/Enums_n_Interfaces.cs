using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Enums_n_Interfaces : MonoBehaviour
{
    
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


public interface IHealthDestroyable
{
    public void DecreaseHealthAmount(float amount);

    public void UpdateUIPosition(Camera camera);

    public void ShowUI();

    public void HideUI();

    public IEnumerator ShowUIBarWhileActive();

    public void UpdateUIHealthData();

    public bool IsDestroyable();

    public IEnumerator PlayNegativeEffect(GameObject _effect, float _time);
    public void SetNegativeEffect(NegativeEffects _effect, float _time);

    public float CurrentHealthAmount();
}


public interface IConsumer
{

    public bool ConsumeSupply(GameObject supply);

    public SuppliesType GetFacilityConsumerSupplyType();
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
    dead,
    sit
}
//==================================================================


//SUPPLY ENUMS======================================================
public enum SuppliesType
{
    tester = 0,
    empty_engine_fuel,
    full_engine_fuel,
    shell_for_cannon,
    none
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
    after_wreck,
    none,
    poison_patch,
    death
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
    health_bar,
    alert_mark,
    level_data_stars,
    level_data_select,
    round_progress_bar,
    respawn_bar,
    ok_green,
    no_red


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
    radiation,
    ok,
    no,
    whaaat
}

//===================================================================


//CREW NEGATIVE EFFECTS ENUMS======================================================
public enum NegativeEffects
{
    burning,
    electricity,
    direct_hit,
    slow_down,
    poisoned
}
//===================================================================