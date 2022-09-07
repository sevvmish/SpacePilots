using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.IO;
using System.Runtime.Serialization.Formatters.Binary;

public class SaveLoad : MonoBehaviour
{
    public static void Save(levels[] _GameLevelsData)
    {
        BinaryFormatter formattter = new BinaryFormatter();
        string path = Application.persistentDataPath + "/save.file";

        FileStream stream = new FileStream(path, FileMode.OpenOrCreate);
        formattter.Serialize(stream, _GameLevelsData);
        stream.Close();
        print("Saved...");
    }

    public static bool isDataSaved()
    {        
        string path = Application.persistentDataPath + "/save.file";

        return File.Exists(path);        
    }

    public static levels[] Load()
    {
        BinaryFormatter formattter = new BinaryFormatter();
        string path = Application.persistentDataPath + "/save.file";
        if (!File.Exists(path))
        {
            return new levels[] { };
        }


        FileStream stream = new FileStream(path, FileMode.Open);
        levels[] data = formattter.Deserialize(stream) as levels[];
        stream.Close();
        print("Loaded...");
        return data;
    }
}
