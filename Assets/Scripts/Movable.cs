using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Movable : MonoBehaviour
{
    [SerializeField] private Movables currentMovableType;

    public static GameObject GetMovablePrefab(Movables _movable)
    {
        GameObject result = default;

        switch((int)_movable)
        {
            case 0:
                result = Resources.Load<GameObject>("prefabs/movables/test movable");
                break;
        }

        return result;
    }

    public Movables GetMovableType()
    {
        return currentMovableType;
    }
}

public enum Movables
{
    tester = 0,
    engine_fuel,
    repairer,
    fire_extinguisher

}
