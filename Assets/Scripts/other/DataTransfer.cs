using System;
using System.Collections;
using System.Collections.Generic;
using System.Net;
using System.Linq;
using System.Net.Sockets;
using System.Text;
using UnityEngine;
using System.Threading.Tasks;
using NetCoreServer;
using System.Threading;


public class DataTransfer: MonoBehaviour
{
    

    public static string SendAndGetTCP(string DataForSending, int CurrentPort_tcp, string CurrentIP_tcp, bool is_it_encoded)
    {        
       
        string result = null;

        IPEndPoint endpoint_tcp = new IPEndPoint(IPAddress.Parse(CurrentIP_tcp), CurrentPort_tcp);
        Socket sck_tcp = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
        //=============================CONNECT======================================
        try
        {
            sck_tcp.Connect(endpoint_tcp);
        }
        catch (Exception ex)
        {
            UnityEngine.Debug.Log(ex);
            result = "error";

            //sck_tcp.Shutdown(SocketShutdown.Both);
            //sck_tcp.Close();
            return result;
        }
        //===============================SEND======================================
        try
        {
            byte[] data_to_s = Encoding.UTF8.GetBytes(DataForSending);

            if (is_it_encoded)
            {
                Encryption.Encode(ref data_to_s, settings.SecretKey);
            }

            sck_tcp.Send(data_to_s);
        }
        catch (Exception ex)
        {
            UnityEngine.Debug.Log(ex);
            result = ex.ToString();

            sck_tcp.Shutdown(SocketShutdown.Both);
            sck_tcp.Close();
            return result;
        }
        //================================GET======================================
        try
        {
            StringBuilder messrec = new StringBuilder();
            byte[] msgBuff = new byte[1024];
            int size = 0;

            {
                size = sck_tcp.Receive(msgBuff);
                messrec.Append(Encoding.UTF8.GetString(msgBuff, 0, size));
            }
            while (sck_tcp.Available > 0) ;



            if (messrec.ToString() == "nsc")
            {
                sck_tcp.Shutdown(SocketShutdown.Both);
                sck_tcp.Close();
                return "nsc";
            }

            if (is_it_encoded)
            {
                byte[] data_r = new byte[size];

                for (int i = 0; i < size; i++)
                {
                    data_r[i] = msgBuff[i];
                }
                Encryption.Decode(ref data_r, settings.SecretKey);
                messrec.Clear();
                messrec.Append(Encoding.UTF8.GetString(data_r, 0, data_r.Length));
            }

            if (messrec.ToString() != "" && messrec.ToString() != null)
            {
                result = messrec.ToString();
            }
            else
            {
                result = "error in received data";
            }
        }
        catch (Exception ex)
        {
            UnityEngine.Debug.Log(ex);
            result = ex.ToString();

            sck_tcp.Shutdown(SocketShutdown.Both);
            sck_tcp.Close();
            return result;
        }
        //error case
        sck_tcp.Shutdown(SocketShutdown.Both);
        sck_tcp.Close();
        return result;

    }


    public static bool SendTCP(string DataForSending, int CurrentPort_tcp, string CurrentIP_tcp, bool is_it_encoded)
    {
                
        IPEndPoint endpoint_tcp = new IPEndPoint(IPAddress.Parse(CurrentIP_tcp), CurrentPort_tcp);
        Socket sck_tcp = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
        //=============================CONNECT======================================
        try
        {
            sck_tcp.Connect(endpoint_tcp);
        }
        catch (Exception ex)
        {
            UnityEngine.Debug.Log(ex);
            
            sck_tcp.Shutdown(SocketShutdown.Both);
            sck_tcp.Close();
            return false;
        }
        //===============================SEND======================================
        try
        {
            byte[] data_to_s = Encoding.UTF8.GetBytes(DataForSending);

            if (is_it_encoded)
            {
                Encryption.Encode(ref data_to_s, settings.SecretKey);
            }

            sck_tcp.Send(data_to_s);
        }
        catch (Exception ex)
        {
            UnityEngine.Debug.Log(ex);
            
            sck_tcp.Shutdown(SocketShutdown.Both);
            sck_tcp.Close();
            return false;
        }

        return true;
    }

}
