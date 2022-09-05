using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.Numerics;
using System;
using System.Text;
using System.Security.Cryptography;

public class Encryption : MonoBehaviour
{
    public RSAParameters publicKey;
    public string encoded_secret_key_instring;


    public void ProcessInitDataFromServerTCP(string data)
    {        
        string[] string_data = data.Split('~');
        settings.SecretKey = GetRandom256Code();
        settings.PacketID = string_data[3];


        //getting back real public key by public key string
        var sr = new System.IO.StringReader(string_data[4]);
        var xs = new System.Xml.Serialization.XmlSerializer(typeof(RSAParameters));
        publicKey = (RSAParameters)xs.Deserialize(sr);

        RSACryptoServiceProvider csp = new RSACryptoServiceProvider();
        csp.ImportParameters(publicKey);

        byte[] encoded_secret_key = csp.Encrypt(settings.SecretKey, false);

        //conver bytes to normal string
        var sw1 = new System.IO.StringWriter();
        var xs1 = new System.Xml.Serialization.XmlSerializer(typeof(byte[]));
        xs1.Serialize(sw1, encoded_secret_key);
        encoded_secret_key_instring = sw1.ToString();

        csp.Dispose();
    }


    public static byte[] GetByteArrFromCharByChar(string key_in_string)
    {
        byte[] result = new byte[key_in_string.Length];

        for (int i = 0; i < key_in_string.Length; i++)
        {
            result[i] = Byte.Parse(key_in_string.Substring(i, 1));
        }

        return result;
    }

    public static byte[] ConvertToByteArrByLenghtFromString(string data, int _lenght)
    {
        return Encoding.UTF8.GetBytes(data.Substring(0, _lenght));
    }

    public static byte[] TakeSomeToArrayTO(byte[] source, int numberToTake)
    {
        if (numberToTake > source.Length)
        {
            numberToTake = source.Length;
        }


        byte[] result = new byte[numberToTake];

        for (int i = 0; i < numberToTake; i++)
        {
            result[i] = source[i];
        }

        return result;
    }



    public static byte[] TakeSomeToArrayFromNumber(byte[] source, int fromNumber)
    {

        if (fromNumber > source.Length)
        {
            fromNumber = source.Length - 1;
        }

        byte[] result = new byte[source.Length - fromNumber];
        int delta = 0;

        for (int i = fromNumber; i < source.Length; i++)
        {
            result[delta] = source[i];
            delta++;
        }

        return result;
    }



    public static void Encode(ref byte[] source, byte[] key)
    {
        int index = 0;

        for (int i = 6; i < source.Length; i++)
        {
            source[i] = (byte)(source[i] + key[index]);

            if ((index + 1) == key.Length)
            {
                index = 0;
            }
            else
            {
                index++;
            }
        }
    }

    public static void Decode(ref byte[] source, byte[] key)
    {
        int index = 0;

        for (int i = 6; i < source.Length; i++)
        {
            source[i] = (byte)(source[i] - key[index]);

            if ((index + 1) == key.Length)
            {
                index = 0;
            }
            else
            {
                index++;
            }
        }
    }


    public static bool InitEncodingConnection()
    {
        settings.PlayerEncryption.ProcessInitDataFromServerTCP(DataTransfer.SendAndGetTCP("0~6~0", settings.SERVER_TCP_PORT, settings.SERVER_IP, false));
        string res = DataTransfer.SendAndGetTCP($"0~6~1~{settings.PacketID}~{settings.PlayerEncryption.encoded_secret_key_instring}", settings.SERVER_TCP_PORT, settings.SERVER_IP, false);
        string[] result = res.Split('~');

        if (result[3] == "ok")
        {
            return true;
        }
        else
        {
            return false;
        }       
    }

    public static byte[] GetHash384(string data)
    {
        SHA384 create_hash = SHA384.Create();
        return create_hash.ComputeHash(Encoding.UTF8.GetBytes(data));
    }

    public static string FromByteToString(byte[] data)
    {
        StringBuilder d = new StringBuilder();
        for (int i = 0; i < data.Length; i++)
        {
            d.Append(data[i]);
        }

        return d.ToString();
    }

    public static byte[] GetRandom256Code()
    {
        SHA256 sh = new SHA256Managed();
        return sh.ComputeHash(Encoding.UTF8.GetBytes(Encryption.get_random_set_of_symb(256)));
    }

    public static string get_random_set_of_symb(int nub_of_symb)
    {
        string[] arr_name = { "q", "w", "e", "r", "t", "y", "u", "i", "o", "p", "a", "s", "d", "f", "g", "h", "j", "k", "l", "z", "x", "c", "v", "b", "n", "m", "Q", "W", "E", "R", "T", "Y", "U", "I", "O", "P", "A", "S", "D", "F", "G", "H", "J", "K", "L", "Z", "X", "C", "V", "B", "N", "M", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "-", "=", "@", "#", "!", "<", ">", "&", "?", ".", ",", "+", "*", "$" };
        string result = "";
        System.Random rnd = new System.Random();
        for (int i = 0; i < nub_of_symb; i++)
        {
            result = result + arr_name[rnd.Next(0, arr_name.Length - 1)];
        }

        return result;
    }

    public static byte[] TakeSomeToArrayTO(Span<byte> source, int numberToTake)
    {
        if (numberToTake > source.Length)
        {
            numberToTake = source.Length;
        }

        return source.Slice(0, numberToTake).ToArray();
    }

    public static byte[] TakeSomeToArrayFromNumber(ReadOnlySpan<byte> source, int fromNumber)
    {
        if (fromNumber > source.Length)
        {
            fromNumber = source.Length - 1;
        }


        return source.Slice(fromNumber, (source.Length - fromNumber)).ToArray();
    }

}
