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
    fire    
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
