using ProtoBuf;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using UnityEngine;

public class ProtobufManagement : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    public byte[] ToSendMovementInBytes(float Horiz, float Vert)
    {       
        byte[] result = default;
        byte[] packetToSendMove = default;
        byte[] message = default;
        PacketToReceive dataPacket = default;


        using (var stream = new MemoryStream())
        {
            Serializer.Serialize(stream, packetToSendMove);
            result = stream.ToArray();
        }



        using (var stream = new MemoryStream(message))
        {
            dataPacket = Serializer.Deserialize<PacketToReceive>(stream);
        }




        return result;
    }
}

[ProtoContract]
public class PacketToReceive
{
    [ProtoMember(1)]
    public float x { get; set; }

    [ProtoMember(2)]
    public float z { get; set; }
}
