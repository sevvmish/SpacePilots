#include "pch-cpp.hpp"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif


#include <limits>
#include <stdint.h>


template <typename T1>
struct VirtualActionInvoker1
{
	typedef void (*Action)(void*, T1, const RuntimeMethod*);

	static inline void Invoke (Il2CppMethodSlot slot, RuntimeObject* obj, T1 p1)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_virtual_invoke_data(slot, obj);
		((Action)invokeData.methodPtr)(obj, p1, invokeData.method);
	}
};
template <typename R>
struct VirtualFuncInvoker0
{
	typedef R (*Func)(void*, const RuntimeMethod*);

	static inline R Invoke (Il2CppMethodSlot slot, RuntimeObject* obj)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_virtual_invoke_data(slot, obj);
		return ((Func)invokeData.methodPtr)(obj, invokeData.method);
	}
};
template <typename R, typename T1>
struct VirtualFuncInvoker1
{
	typedef R (*Func)(void*, T1, const RuntimeMethod*);

	static inline R Invoke (Il2CppMethodSlot slot, RuntimeObject* obj, T1 p1)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_virtual_invoke_data(slot, obj);
		return ((Func)invokeData.methodPtr)(obj, p1, invokeData.method);
	}
};
template <typename R, typename T1, typename T2, typename T3, typename T4, typename T5>
struct VirtualFuncInvoker5
{
	typedef R (*Func)(void*, T1, T2, T3, T4, T5, const RuntimeMethod*);

	static inline R Invoke (Il2CppMethodSlot slot, RuntimeObject* obj, T1 p1, T2 p2, T3 p3, T4 p4, T5 p5)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_virtual_invoke_data(slot, obj);
		return ((Func)invokeData.methodPtr)(obj, p1, p2, p3, p4, p5, invokeData.method);
	}
};
template <typename T1>
struct GenericVirtualActionInvoker1
{
	typedef void (*Action)(void*, T1, const RuntimeMethod*);

	static inline void Invoke (const RuntimeMethod* method, RuntimeObject* obj, T1 p1)
	{
		VirtualInvokeData invokeData;
		il2cpp_codegen_get_generic_virtual_invoke_data(method, obj, &invokeData);
		((Action)invokeData.methodPtr)(obj, p1, invokeData.method);
	}
};
template <typename T1>
struct InterfaceActionInvoker1
{
	typedef void (*Action)(void*, T1, const RuntimeMethod*);

	static inline void Invoke (Il2CppMethodSlot slot, RuntimeClass* declaringInterface, RuntimeObject* obj, T1 p1)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_interface_invoke_data(slot, obj, declaringInterface);
		((Action)invokeData.methodPtr)(obj, p1, invokeData.method);
	}
};
template <typename T1>
struct GenericInterfaceActionInvoker1
{
	typedef void (*Action)(void*, T1, const RuntimeMethod*);

	static inline void Invoke (const RuntimeMethod* method, RuntimeObject* obj, T1 p1)
	{
		VirtualInvokeData invokeData;
		il2cpp_codegen_get_generic_interface_invoke_data(method, obj, &invokeData);
		((Action)invokeData.methodPtr)(obj, p1, invokeData.method);
	}
};
template <typename T1, typename T2>
struct InvokerActionInvoker2;
template <typename T1, typename T2>
struct InvokerActionInvoker2<T1*, T2*>
{
	static inline void Invoke (Il2CppMethodPointer methodPtr, const RuntimeMethod* method, void* obj, T1* p1, T2* p2)
	{
		void* params[2] = { p1, p2 };
		method->invoker_method(methodPtr, method, obj, params, NULL);
	}
};
template <typename T1, typename T2, typename T3>
struct InvokerActionInvoker3;
template <typename T1, typename T2, typename T3>
struct InvokerActionInvoker3<T1*, T2*, T3*>
{
	static inline void Invoke (Il2CppMethodPointer methodPtr, const RuntimeMethod* method, void* obj, T1* p1, T2* p2, T3* p3)
	{
		void* params[3] = { p1, p2, p3 };
		method->invoker_method(methodPtr, method, obj, params, NULL);
	}
};

// System.Collections.Generic.Dictionary`2<System.Int32,System.Text.Encoding>
struct Dictionary_2_t87EDE08B2E48F793A22DE50D6B3CC2E7EBB2DB54;
// System.Collections.Generic.Dictionary`2<System.Object,System.Object>
struct Dictionary_2_t14FE4A752A83D53771C584E4C8D14E01F2AFD7BA;
// System.Collections.Generic.Dictionary`2<System.Type,LiteNetLib.Utils.NetSerializer/CustomType>
struct Dictionary_2_tE9744A9551C9F7ADCA9DCECD5809D05C5FCD8FB8;
// System.Collections.Generic.Dictionary`2<System.UInt64,System.Object>
struct Dictionary_2_t01A465CD199FB14D59FEC2DC7DDE76D2CD0A09F4;
// System.Collections.Generic.Dictionary`2<System.UInt64,LiteNetLib.Utils.NetPacketProcessor/SubscribeDelegate>
struct Dictionary_2_tC50529CA8871074E26D545E7CB9D085D0D295AEA;
// System.EventHandler`1<System.Net.Sockets.SocketAsyncEventArgs>
struct EventHandler_1_t5D3FC4609BD8133ED1226D6D49A1D8076B16A9ED;
// System.Collections.Generic.IEqualityComparer`1<System.Type>
struct IEqualityComparer_1_t0C79004BFE79D9DBCE6C2250109D31D468A9A68E;
// System.Collections.Generic.IEqualityComparer`1<System.UInt64>
struct IEqualityComparer_1_t958EAC5D5BD188327B4736D6F82A08EA1476A4C8;
// System.Collections.Generic.Dictionary`2/KeyCollection<System.Type,LiteNetLib.Utils.NetSerializer/CustomType>
struct KeyCollection_tD752C2A9C93F8183A12A3E3D004541A737F3D736;
// System.Collections.Generic.Dictionary`2/KeyCollection<System.UInt64,LiteNetLib.Utils.NetPacketProcessor/SubscribeDelegate>
struct KeyCollection_tAFBDC57E8592C415F79A6CBE0890633544392850;
// System.Net.Sockets.Socket/TaskSocketAsyncEventArgs`1<System.Net.Sockets.Socket>
struct TaskSocketAsyncEventArgs_1_tEB937620E5B15D91E5BFEFFA707CF800930F8401;
// System.Threading.Tasks.Task`1<System.Int32>
struct Task_1_t4C228DE57804012969575431CFF12D57C875552D;
// System.Collections.Generic.Dictionary`2/ValueCollection<System.Type,LiteNetLib.Utils.NetSerializer/CustomType>
struct ValueCollection_t7A52812EC6FF2B9CD02C8E6AF0E3BC151180E16B;
// System.Collections.Generic.Dictionary`2/ValueCollection<System.UInt64,LiteNetLib.Utils.NetPacketProcessor/SubscribeDelegate>
struct ValueCollection_tC21FCA18B2915DBE867AF5547AA4A0BD84C60A3C;
// System.Collections.Generic.Dictionary`2/Entry<System.Type,LiteNetLib.Utils.NetSerializer/CustomType>[]
struct EntryU5BU5D_t0DD7C363581F35C68130EED42136E05644E207CE;
// System.Collections.Generic.Dictionary`2/Entry<System.UInt64,LiteNetLib.Utils.NetPacketProcessor/SubscribeDelegate>[]
struct EntryU5BU5D_t5B431AAA2F863E29809A89C797DDC2665C2E21D1;
// System.Boolean[]
struct BooleanU5BU5D_tD317D27C31DB892BE79FAE3AEBC0B3FFB73DE9B4;
// System.Byte[]
struct ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031;
// System.Delegate[]
struct DelegateU5BU5D_tC5AB7E8F745616680F337909D3A8E6C722CDF771;
// System.Double[]
struct DoubleU5BU5D_tCC308475BD3B8229DB2582938669EF2F9ECC1FEE;
// System.Int16[]
struct Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB;
// System.Int32[]
struct Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C;
// System.Int64[]
struct Int64U5BU5D_tAEDFCBDB5414E2A140A6F34C0538BF97FCF67A1D;
// System.IntPtr[]
struct IntPtrU5BU5D_tFD177F8C806A6921AD7150264CCC62FA00CAD832;
// System.Object[]
struct ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918;
// System.SByte[]
struct SByteU5BU5D_t88116DA68378C3333DB73E7D36C1A06AFAA91913;
// System.Single[]
struct SingleU5BU5D_t89DEFE97BCEDB5857010E79ECE0F52CF6E93B87C;
// System.Diagnostics.StackTrace[]
struct StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF;
// System.String[]
struct StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248;
// System.UInt16[]
struct UInt16U5BU5D_tEB7C42D811D999D2AA815BADC3FCCDD9C67B3F83;
// System.UInt32[]
struct UInt32U5BU5D_t02FBD658AD156A17574ECE6106CF1FBFCC9807FA;
// System.UInt64[]
struct UInt64U5BU5D_tAB1A62450AC0899188486EDB9FC066B8BEED9299;
// System.ArgumentException
struct ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263;
// System.AsyncCallback
struct AsyncCallback_t7FEF460CBDCFB9C5FA2EF776984778B9A4145F4C;
// System.Globalization.CodePageDataItem
struct CodePageDataItem_t52460FA30AE37F4F26ACB81055E58002262F19F2;
// LiteNetLib.Layers.Crc32cLayer
struct Crc32cLayer_tE5B2EC9CF4B04BF362ED013C539E1401F2529BA6;
// System.Text.DecoderFallback
struct DecoderFallback_t7324102215E4ED41EC065C02EB501CB0BC23CD90;
// System.Delegate
struct Delegate_t;
// System.DelegateData
struct DelegateData_t9B286B493293CD2D23A5B2B5EF0E5B1324C2B77E;
// System.Text.EncoderFallback
struct EncoderFallback_tD2C40CE114AA9D8E1F7196608B2D088548015293;
// System.Text.Encoding
struct Encoding_t65CDEF28CF20A7B8C92E85A4E808920C2465F095;
// System.Net.EndPoint
struct EndPoint_t6233F4E2EB9F0F2D36E187F12BE050E6D8B73564;
// System.Exception
struct Exception_t;
// System.IAsyncResult
struct IAsyncResult_t7B9B5A0ECB35DCEC31B8A8122C37D687369253B5;
// System.Collections.IDictionary
struct IDictionary_t6D03155AF1FA9083817AA5B6AD7DEEACC26AB220;
// System.IOAsyncCallback
struct IOAsyncCallback_tDBBA8BBDA6B203613680E77BD4AD6320A1268388;
// System.Net.IPAddress
struct IPAddress_t2F4486449B0D73FF2D3B36A9FE5E9C3F63116484;
// System.Net.IPEndPoint
struct IPEndPoint_t2F09CBA7A808B67724B4E2954EEDC46D910F4ECB;
// System.InvalidOperationException
struct InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB;
// LiteNetLib.Utils.InvalidTypeException
struct InvalidTypeException_t3216C4E1075D00F909878A0C023BF525B9DFF127;
// System.Reflection.MethodInfo
struct MethodInfo_t;
// LiteNetLib.Utils.NetDataReader
struct NetDataReader_t28CDAC4E19A9CDCCE3F782A3E29084D50A2F58FF;
// LiteNetLib.Utils.NetDataWriter
struct NetDataWriter_t5AE108AEC4825ED3FB45AA93565703368228EB37;
// LiteNetLib.Utils.NetPacketProcessor
struct NetPacketProcessor_t535112850E31D87B64B84496790A24B227A1B65C;
// LiteNetLib.Utils.NetSerializer
struct NetSerializer_t6F1385A0BDE64EB9921D4351CFD84FF864E111DE;
// LiteNetLib.Utils.NtpPacket
struct NtpPacket_tF37CA19271AE795B037952A3137F652EF3B95E92;
// LiteNetLib.Utils.NtpRequest
struct NtpRequest_tC0955A6C23AED87A1C51BB5D441709CE3F6DDF1F;
// LiteNetLib.Layers.PacketLayerBase
struct PacketLayerBase_tAE86828E66E9B4065BBE4DD1125AE7D0394EBE34;
// LiteNetLib.Utils.ParseException
struct ParseException_t78F4289CD37365426C09D2D805B6EFE254DA2266;
// System.Runtime.Serialization.SafeSerializationManager
struct SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6;
// System.Net.Sockets.SafeSocketHandle
struct SafeSocketHandle_t5A597D30D951E736B750ED09D5B3AB72F98407EE;
// System.Threading.SemaphoreSlim
struct SemaphoreSlim_t0D5CB5685D9BFA5BF95CEC6E7395490F933E8DB2;
// System.Net.Sockets.Socket
struct Socket_t1F49472CDA22B581C29A258225ABF3ADA9DED67E;
// System.String
struct String_t;
// System.Text.UTF8Encoding
struct UTF8Encoding_t90B56215A1B0B7ED5CDEA772E695F0DDAFBCD3BE;
// System.Void
struct Void_t4861ACF8F4594C3437BB48B6E56783494B843915;
// LiteNetLib.Layers.XorEncryptLayer
struct XorEncryptLayer_tC167B2E4D09C6238B5F5AFD18AC29C99CD71A0C6;
// LiteNetLib.Utils.NetPacketProcessor/SubscribeDelegate
struct SubscribeDelegate_t5176AD87F22014A136F003FB651B6451DB2BE13F;
// LiteNetLib.Utils.NetSerializer/CustomType
struct CustomType_t5DD67989E7FD0AC65476233C7C30A0BE5282624B;
// System.Net.Sockets.Socket/CachedEventArgs
struct CachedEventArgs_tF0692E89962FD1A045B17BC985F838C11FB6822C;
// System.Net.Sockets.Socket/Int32TaskSocketAsyncEventArgs
struct Int32TaskSocketAsyncEventArgs_t36C5FC82499ED9DAFE7F05C38EF92D77A0B248E9;
// System.Text.UTF8Encoding/UTF8EncodingSealed
struct UTF8EncodingSealed_tF97A34F40CABE9CE1C168967D60396F51C43DD36;

IL2CPP_EXTERN_C RuntimeClass* ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* BitConverter_t6E99605185963BC12B3D369E13F2B88997E64A27_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* CRC32C_tFA7C9F5C10A64056F997BE1B4625419C3ED6B78A_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Convert_t7097FF336D592F7C06D88A98349A44646F91EFFC_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Dictionary_2_tC50529CA8871074E26D545E7CB9D085D0D295AEA_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Dictionary_2_tE9744A9551C9F7ADCA9DCECD5809D05C5FCD8FB8_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Exception_t_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Math_tEB65DE7CA8B083C412C969C92981C030865486CE_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* NetDataWriter_t5AE108AEC4825ED3FB45AA93565703368228EB37_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* NetDebug_t8F8390900D67D7F62A4852546BB041E9CAB6D90A_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* NetSerializer_t6F1385A0BDE64EB9921D4351CFD84FF864E111DE_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* NtpPacket_tF37CA19271AE795B037952A3137F652EF3B95E92_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* ParseException_t78F4289CD37365426C09D2D805B6EFE254DA2266_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* RuntimeObject_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* UInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* UTF8Encoding_t90B56215A1B0B7ED5CDEA772E695F0DDAFBCD3BE_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C String_t* _stringLiteral06C05B24B8AC51D50C3AA294D70C5E1E28E9A0E3;
IL2CPP_EXTERN_C String_t* _stringLiteral10F509F15EC5C6178F7787F554341A601F904E65;
IL2CPP_EXTERN_C String_t* _stringLiteral20578EED957D25675AEB69A727D4556E455C76A9;
IL2CPP_EXTERN_C String_t* _stringLiteral3B19916E896E08666992C24EA969EE6DE3B95722;
IL2CPP_EXTERN_C String_t* _stringLiteral49BEFE76EF933CC018C51D77F66B724C36F2CE09;
IL2CPP_EXTERN_C String_t* _stringLiteral54CC87BDCC203DBF3D08732C8F6B081BD50E7D62;
IL2CPP_EXTERN_C String_t* _stringLiteral6A616A2BD726354344808434F427B73FA98BDD24;
IL2CPP_EXTERN_C String_t* _stringLiteral77B615B8ED1ABB8FC1395D85A5AE524A9789D947;
IL2CPP_EXTERN_C String_t* _stringLiteral868EE9733DC26168EACBAC88A44D9E3DE178486F;
IL2CPP_EXTERN_C String_t* _stringLiteral88F1D02FAC5553C102E3A23C9A363D07A9C89238;
IL2CPP_EXTERN_C String_t* _stringLiteralA9FFA609F3AF81CBA0BEF31B92E98F7C0B64DA06;
IL2CPP_EXTERN_C String_t* _stringLiteralC90CADE37127E5B15A609569628F61937A864B5A;
IL2CPP_EXTERN_C String_t* _stringLiteralCB77237BCD39404C795BCB8688C2D3153355EBA0;
IL2CPP_EXTERN_C String_t* _stringLiteralF39AFC06F0127ED41BF2DBB29047355062D8065C;
IL2CPP_EXTERN_C String_t* _stringLiteralF62357F27A8ABD4B2897C89CFE2ABB3A9468CB41;
IL2CPP_EXTERN_C const RuntimeMethod* Array_Empty_TisRuntimeObject_m55011E8360A8199FB239A5787BA8631CDD6116FC_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Array_Resize_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m82FEC5823560947D2B12C8D675AED2C190DF4F3F_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Dictionary_2_TryGetValue_mC87F2380785378011E6B2A46B0B81908F6A5000C_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Dictionary_2__ctor_mD1E3D96A898D0AE25D21A35F907E8FD90F077ECF_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Dictionary_2__ctor_mE1C7F4DEE5EFADD1C6C6AFBEE21572DEF740AA96_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* NetDataWriter_Put_m81B08D1F055A09468E4DE6D60F7A28F12AD56B77_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* NetPacketProcessor_GetCallbackFromData_m9B87326F815691C0E39F42F97980101B151809A5_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* NtpPacket_CheckTimestamps_mD370D48027EFB0EC0A5129B2E90F545D44E5EE64_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* NtpPacket_ValidateReply_m871B39CA5A4182A368955E759666202F030E0F58_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* NtpPacket_ValidateRequest_m63E690888AB011E8D4C6AA93926598F6AAD343BE_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* NtpPacket__ctor_m42BD9C610A9863D191C040D0321813B1ED876932_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Nullable_1__ctor_mB17304720EA19F5469A4883827F53A75FEB492CF_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Nullable_1_get_HasValue_m092C73DCE052BFB5C60A39EF9F4E3401AA95221C_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Nullable_1_get_Value_m5A868F663848BC21C18F056731D3AC404CE59991_RuntimeMethod_var;
struct Delegate_t_marshaled_com;
struct Delegate_t_marshaled_pinvoke;
struct Exception_t_marshaled_com;
struct Exception_t_marshaled_pinvoke;

struct BooleanU5BU5D_tD317D27C31DB892BE79FAE3AEBC0B3FFB73DE9B4;
struct ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031;
struct DelegateU5BU5D_tC5AB7E8F745616680F337909D3A8E6C722CDF771;
struct DoubleU5BU5D_tCC308475BD3B8229DB2582938669EF2F9ECC1FEE;
struct Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB;
struct Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C;
struct Int64U5BU5D_tAEDFCBDB5414E2A140A6F34C0538BF97FCF67A1D;
struct ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918;
struct SByteU5BU5D_t88116DA68378C3333DB73E7D36C1A06AFAA91913;
struct SingleU5BU5D_t89DEFE97BCEDB5857010E79ECE0F52CF6E93B87C;
struct StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248;
struct UInt16U5BU5D_tEB7C42D811D999D2AA815BADC3FCCDD9C67B3F83;
struct UInt32U5BU5D_t02FBD658AD156A17574ECE6106CF1FBFCC9807FA;
struct UInt64U5BU5D_tAB1A62450AC0899188486EDB9FC066B8BEED9299;

IL2CPP_EXTERN_C_BEGIN
IL2CPP_EXTERN_C_END

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// System.Collections.Generic.Dictionary`2<System.Type,LiteNetLib.Utils.NetSerializer/CustomType>
struct Dictionary_2_tE9744A9551C9F7ADCA9DCECD5809D05C5FCD8FB8  : public RuntimeObject
{
	// System.Int32[] System.Collections.Generic.Dictionary`2::_buckets
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ____buckets_0;
	// System.Collections.Generic.Dictionary`2/Entry<TKey,TValue>[] System.Collections.Generic.Dictionary`2::_entries
	EntryU5BU5D_t0DD7C363581F35C68130EED42136E05644E207CE* ____entries_1;
	// System.Int32 System.Collections.Generic.Dictionary`2::_count
	int32_t ____count_2;
	// System.Int32 System.Collections.Generic.Dictionary`2::_freeList
	int32_t ____freeList_3;
	// System.Int32 System.Collections.Generic.Dictionary`2::_freeCount
	int32_t ____freeCount_4;
	// System.Int32 System.Collections.Generic.Dictionary`2::_version
	int32_t ____version_5;
	// System.Collections.Generic.IEqualityComparer`1<TKey> System.Collections.Generic.Dictionary`2::_comparer
	RuntimeObject* ____comparer_6;
	// System.Collections.Generic.Dictionary`2/KeyCollection<TKey,TValue> System.Collections.Generic.Dictionary`2::_keys
	KeyCollection_tD752C2A9C93F8183A12A3E3D004541A737F3D736* ____keys_7;
	// System.Collections.Generic.Dictionary`2/ValueCollection<TKey,TValue> System.Collections.Generic.Dictionary`2::_values
	ValueCollection_t7A52812EC6FF2B9CD02C8E6AF0E3BC151180E16B* ____values_8;
	// System.Object System.Collections.Generic.Dictionary`2::_syncRoot
	RuntimeObject* ____syncRoot_9;
};

// System.Collections.Generic.Dictionary`2<System.UInt64,LiteNetLib.Utils.NetPacketProcessor/SubscribeDelegate>
struct Dictionary_2_tC50529CA8871074E26D545E7CB9D085D0D295AEA  : public RuntimeObject
{
	// System.Int32[] System.Collections.Generic.Dictionary`2::_buckets
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ____buckets_0;
	// System.Collections.Generic.Dictionary`2/Entry<TKey,TValue>[] System.Collections.Generic.Dictionary`2::_entries
	EntryU5BU5D_t5B431AAA2F863E29809A89C797DDC2665C2E21D1* ____entries_1;
	// System.Int32 System.Collections.Generic.Dictionary`2::_count
	int32_t ____count_2;
	// System.Int32 System.Collections.Generic.Dictionary`2::_freeList
	int32_t ____freeList_3;
	// System.Int32 System.Collections.Generic.Dictionary`2::_freeCount
	int32_t ____freeCount_4;
	// System.Int32 System.Collections.Generic.Dictionary`2::_version
	int32_t ____version_5;
	// System.Collections.Generic.IEqualityComparer`1<TKey> System.Collections.Generic.Dictionary`2::_comparer
	RuntimeObject* ____comparer_6;
	// System.Collections.Generic.Dictionary`2/KeyCollection<TKey,TValue> System.Collections.Generic.Dictionary`2::_keys
	KeyCollection_tAFBDC57E8592C415F79A6CBE0890633544392850* ____keys_7;
	// System.Collections.Generic.Dictionary`2/ValueCollection<TKey,TValue> System.Collections.Generic.Dictionary`2::_values
	ValueCollection_tC21FCA18B2915DBE867AF5547AA4A0BD84C60A3C* ____values_8;
	// System.Object System.Collections.Generic.Dictionary`2::_syncRoot
	RuntimeObject* ____syncRoot_9;
};

// System.EmptyArray`1<System.Object>
struct EmptyArray_1_tDF0DD7256B115243AA6BD5558417387A734240EE  : public RuntimeObject
{
};

struct EmptyArray_1_tDF0DD7256B115243AA6BD5558417387A734240EE_StaticFields
{
	// T[] System.EmptyArray`1::Value
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* ___Value_0;
};
struct Il2CppArrayBounds;

// System.Text.Encoding
struct Encoding_t65CDEF28CF20A7B8C92E85A4E808920C2465F095  : public RuntimeObject
{
	// System.Int32 System.Text.Encoding::m_codePage
	int32_t ___m_codePage_9;
	// System.Globalization.CodePageDataItem System.Text.Encoding::dataItem
	CodePageDataItem_t52460FA30AE37F4F26ACB81055E58002262F19F2* ___dataItem_10;
	// System.Boolean System.Text.Encoding::m_deserializedFromEverett
	bool ___m_deserializedFromEverett_11;
	// System.Boolean System.Text.Encoding::m_isReadOnly
	bool ___m_isReadOnly_12;
	// System.Text.EncoderFallback System.Text.Encoding::encoderFallback
	EncoderFallback_tD2C40CE114AA9D8E1F7196608B2D088548015293* ___encoderFallback_13;
	// System.Text.DecoderFallback System.Text.Encoding::decoderFallback
	DecoderFallback_t7324102215E4ED41EC065C02EB501CB0BC23CD90* ___decoderFallback_14;
};

struct Encoding_t65CDEF28CF20A7B8C92E85A4E808920C2465F095_StaticFields
{
	// System.Text.Encoding modreq(System.Runtime.CompilerServices.IsVolatile) System.Text.Encoding::defaultEncoding
	Encoding_t65CDEF28CF20A7B8C92E85A4E808920C2465F095* ___defaultEncoding_0;
	// System.Text.Encoding modreq(System.Runtime.CompilerServices.IsVolatile) System.Text.Encoding::unicodeEncoding
	Encoding_t65CDEF28CF20A7B8C92E85A4E808920C2465F095* ___unicodeEncoding_1;
	// System.Text.Encoding modreq(System.Runtime.CompilerServices.IsVolatile) System.Text.Encoding::bigEndianUnicode
	Encoding_t65CDEF28CF20A7B8C92E85A4E808920C2465F095* ___bigEndianUnicode_2;
	// System.Text.Encoding modreq(System.Runtime.CompilerServices.IsVolatile) System.Text.Encoding::utf7Encoding
	Encoding_t65CDEF28CF20A7B8C92E85A4E808920C2465F095* ___utf7Encoding_3;
	// System.Text.Encoding modreq(System.Runtime.CompilerServices.IsVolatile) System.Text.Encoding::utf8Encoding
	Encoding_t65CDEF28CF20A7B8C92E85A4E808920C2465F095* ___utf8Encoding_4;
	// System.Text.Encoding modreq(System.Runtime.CompilerServices.IsVolatile) System.Text.Encoding::utf32Encoding
	Encoding_t65CDEF28CF20A7B8C92E85A4E808920C2465F095* ___utf32Encoding_5;
	// System.Text.Encoding modreq(System.Runtime.CompilerServices.IsVolatile) System.Text.Encoding::asciiEncoding
	Encoding_t65CDEF28CF20A7B8C92E85A4E808920C2465F095* ___asciiEncoding_6;
	// System.Text.Encoding modreq(System.Runtime.CompilerServices.IsVolatile) System.Text.Encoding::latin1Encoding
	Encoding_t65CDEF28CF20A7B8C92E85A4E808920C2465F095* ___latin1Encoding_7;
	// System.Collections.Generic.Dictionary`2<System.Int32,System.Text.Encoding> modreq(System.Runtime.CompilerServices.IsVolatile) System.Text.Encoding::encodings
	Dictionary_2_t87EDE08B2E48F793A22DE50D6B3CC2E7EBB2DB54* ___encodings_8;
	// System.Object System.Text.Encoding::s_InternalSyncObject
	RuntimeObject* ___s_InternalSyncObject_15;
};

// System.Net.EndPoint
struct EndPoint_t6233F4E2EB9F0F2D36E187F12BE050E6D8B73564  : public RuntimeObject
{
};

// System.Net.IPAddress
struct IPAddress_t2F4486449B0D73FF2D3B36A9FE5E9C3F63116484  : public RuntimeObject
{
	// System.UInt32 System.Net.IPAddress::_addressOrScopeId
	uint32_t ____addressOrScopeId_8;
	// System.UInt16[] System.Net.IPAddress::_numbers
	UInt16U5BU5D_tEB7C42D811D999D2AA815BADC3FCCDD9C67B3F83* ____numbers_9;
	// System.String System.Net.IPAddress::_toString
	String_t* ____toString_10;
	// System.Int32 System.Net.IPAddress::_hashCode
	int32_t ____hashCode_11;
};

struct IPAddress_t2F4486449B0D73FF2D3B36A9FE5E9C3F63116484_StaticFields
{
	// System.Net.IPAddress System.Net.IPAddress::Any
	IPAddress_t2F4486449B0D73FF2D3B36A9FE5E9C3F63116484* ___Any_0;
	// System.Net.IPAddress System.Net.IPAddress::Loopback
	IPAddress_t2F4486449B0D73FF2D3B36A9FE5E9C3F63116484* ___Loopback_1;
	// System.Net.IPAddress System.Net.IPAddress::Broadcast
	IPAddress_t2F4486449B0D73FF2D3B36A9FE5E9C3F63116484* ___Broadcast_2;
	// System.Net.IPAddress System.Net.IPAddress::None
	IPAddress_t2F4486449B0D73FF2D3B36A9FE5E9C3F63116484* ___None_3;
	// System.Net.IPAddress System.Net.IPAddress::IPv6Any
	IPAddress_t2F4486449B0D73FF2D3B36A9FE5E9C3F63116484* ___IPv6Any_5;
	// System.Net.IPAddress System.Net.IPAddress::IPv6Loopback
	IPAddress_t2F4486449B0D73FF2D3B36A9FE5E9C3F63116484* ___IPv6Loopback_6;
	// System.Net.IPAddress System.Net.IPAddress::IPv6None
	IPAddress_t2F4486449B0D73FF2D3B36A9FE5E9C3F63116484* ___IPv6None_7;
};

// LiteNetLib.Utils.NetDataReader
struct NetDataReader_t28CDAC4E19A9CDCCE3F782A3E29084D50A2F58FF  : public RuntimeObject
{
	// System.Byte[] LiteNetLib.Utils.NetDataReader::_data
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ____data_0;
	// System.Int32 LiteNetLib.Utils.NetDataReader::_position
	int32_t ____position_1;
	// System.Int32 LiteNetLib.Utils.NetDataReader::_dataSize
	int32_t ____dataSize_2;
	// System.Int32 LiteNetLib.Utils.NetDataReader::_offset
	int32_t ____offset_3;
};

struct NetDataReader_t28CDAC4E19A9CDCCE3F782A3E29084D50A2F58FF_StaticFields
{
	// System.Text.UTF8Encoding LiteNetLib.Utils.NetDataReader::_uTF8Encoding
	UTF8Encoding_t90B56215A1B0B7ED5CDEA772E695F0DDAFBCD3BE* ____uTF8Encoding_4;
};

// LiteNetLib.Utils.NetDataWriter
struct NetDataWriter_t5AE108AEC4825ED3FB45AA93565703368228EB37  : public RuntimeObject
{
	// System.Byte[] LiteNetLib.Utils.NetDataWriter::_data
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ____data_0;
	// System.Int32 LiteNetLib.Utils.NetDataWriter::_position
	int32_t ____position_1;
	// System.Boolean LiteNetLib.Utils.NetDataWriter::_autoResize
	bool ____autoResize_3;
	// System.Byte[] LiteNetLib.Utils.NetDataWriter::_stringBuffer
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ____stringBuffer_6;
};

struct NetDataWriter_t5AE108AEC4825ED3FB45AA93565703368228EB37_StaticFields
{
	// System.Text.UTF8Encoding LiteNetLib.Utils.NetDataWriter::_uTF8Encoding
	UTF8Encoding_t90B56215A1B0B7ED5CDEA772E695F0DDAFBCD3BE* ____uTF8Encoding_4;
};

// LiteNetLib.Utils.NetPacketProcessor
struct NetPacketProcessor_t535112850E31D87B64B84496790A24B227A1B65C  : public RuntimeObject
{
	// LiteNetLib.Utils.NetSerializer LiteNetLib.Utils.NetPacketProcessor::_netSerializer
	NetSerializer_t6F1385A0BDE64EB9921D4351CFD84FF864E111DE* ____netSerializer_0;
	// System.Collections.Generic.Dictionary`2<System.UInt64,LiteNetLib.Utils.NetPacketProcessor/SubscribeDelegate> LiteNetLib.Utils.NetPacketProcessor::_callbacks
	Dictionary_2_tC50529CA8871074E26D545E7CB9D085D0D295AEA* ____callbacks_1;
	// LiteNetLib.Utils.NetDataWriter LiteNetLib.Utils.NetPacketProcessor::_netDataWriter
	NetDataWriter_t5AE108AEC4825ED3FB45AA93565703368228EB37* ____netDataWriter_2;
};

// LiteNetLib.Utils.NetSerializer
struct NetSerializer_t6F1385A0BDE64EB9921D4351CFD84FF864E111DE  : public RuntimeObject
{
	// LiteNetLib.Utils.NetDataWriter LiteNetLib.Utils.NetSerializer::_writer
	NetDataWriter_t5AE108AEC4825ED3FB45AA93565703368228EB37* ____writer_0;
	// System.Int32 LiteNetLib.Utils.NetSerializer::_maxStringLength
	int32_t ____maxStringLength_1;
	// System.Collections.Generic.Dictionary`2<System.Type,LiteNetLib.Utils.NetSerializer/CustomType> LiteNetLib.Utils.NetSerializer::_registeredTypes
	Dictionary_2_tE9744A9551C9F7ADCA9DCECD5809D05C5FCD8FB8* ____registeredTypes_2;
};

// LiteNetLib.Utils.NtpRequest
struct NtpRequest_tC0955A6C23AED87A1C51BB5D441709CE3F6DDF1F  : public RuntimeObject
{
	// System.Net.IPEndPoint LiteNetLib.Utils.NtpRequest::_ntpEndPoint
	IPEndPoint_t2F09CBA7A808B67724B4E2954EEDC46D910F4ECB* ____ntpEndPoint_3;
	// System.Int32 LiteNetLib.Utils.NtpRequest::_resendTime
	int32_t ____resendTime_4;
	// System.Int32 LiteNetLib.Utils.NtpRequest::_killTime
	int32_t ____killTime_5;
};

// LiteNetLib.Layers.PacketLayerBase
struct PacketLayerBase_tAE86828E66E9B4065BBE4DD1125AE7D0394EBE34  : public RuntimeObject
{
	// System.Int32 LiteNetLib.Layers.PacketLayerBase::ExtraPacketSizeForLayer
	int32_t ___ExtraPacketSizeForLayer_0;
};

// System.Net.Sockets.Socket
struct Socket_t1F49472CDA22B581C29A258225ABF3ADA9DED67E  : public RuntimeObject
{
	// System.Net.Sockets.Socket/CachedEventArgs System.Net.Sockets.Socket::_cachedTaskEventArgs
	CachedEventArgs_tF0692E89962FD1A045B17BC985F838C11FB6822C* ____cachedTaskEventArgs_6;
	// System.Boolean System.Net.Sockets.Socket::is_closed
	bool ___is_closed_13;
	// System.Boolean System.Net.Sockets.Socket::is_listening
	bool ___is_listening_14;
	// System.Int32 System.Net.Sockets.Socket::linger_timeout
	int32_t ___linger_timeout_15;
	// System.Net.Sockets.AddressFamily System.Net.Sockets.Socket::addressFamily
	int32_t ___addressFamily_16;
	// System.Net.Sockets.SocketType System.Net.Sockets.Socket::socketType
	int32_t ___socketType_17;
	// System.Net.Sockets.ProtocolType System.Net.Sockets.Socket::protocolType
	int32_t ___protocolType_18;
	// System.Net.Sockets.SafeSocketHandle System.Net.Sockets.Socket::m_Handle
	SafeSocketHandle_t5A597D30D951E736B750ED09D5B3AB72F98407EE* ___m_Handle_19;
	// System.Net.EndPoint System.Net.Sockets.Socket::seed_endpoint
	EndPoint_t6233F4E2EB9F0F2D36E187F12BE050E6D8B73564* ___seed_endpoint_20;
	// System.Threading.SemaphoreSlim System.Net.Sockets.Socket::ReadSem
	SemaphoreSlim_t0D5CB5685D9BFA5BF95CEC6E7395490F933E8DB2* ___ReadSem_21;
	// System.Threading.SemaphoreSlim System.Net.Sockets.Socket::WriteSem
	SemaphoreSlim_t0D5CB5685D9BFA5BF95CEC6E7395490F933E8DB2* ___WriteSem_22;
	// System.Boolean System.Net.Sockets.Socket::is_blocking
	bool ___is_blocking_23;
	// System.Boolean System.Net.Sockets.Socket::is_bound
	bool ___is_bound_24;
	// System.Boolean System.Net.Sockets.Socket::is_connected
	bool ___is_connected_25;
	// System.Int32 System.Net.Sockets.Socket::m_IntCleanedUp
	int32_t ___m_IntCleanedUp_26;
	// System.Boolean System.Net.Sockets.Socket::connect_in_progress
	bool ___connect_in_progress_27;
};

struct Socket_t1F49472CDA22B581C29A258225ABF3ADA9DED67E_StaticFields
{
	// System.EventHandler`1<System.Net.Sockets.SocketAsyncEventArgs> System.Net.Sockets.Socket::AcceptCompletedHandler
	EventHandler_1_t5D3FC4609BD8133ED1226D6D49A1D8076B16A9ED* ___AcceptCompletedHandler_0;
	// System.EventHandler`1<System.Net.Sockets.SocketAsyncEventArgs> System.Net.Sockets.Socket::ReceiveCompletedHandler
	EventHandler_1_t5D3FC4609BD8133ED1226D6D49A1D8076B16A9ED* ___ReceiveCompletedHandler_1;
	// System.EventHandler`1<System.Net.Sockets.SocketAsyncEventArgs> System.Net.Sockets.Socket::SendCompletedHandler
	EventHandler_1_t5D3FC4609BD8133ED1226D6D49A1D8076B16A9ED* ___SendCompletedHandler_2;
	// System.Net.Sockets.Socket/TaskSocketAsyncEventArgs`1<System.Net.Sockets.Socket> System.Net.Sockets.Socket::s_rentedSocketSentinel
	TaskSocketAsyncEventArgs_1_tEB937620E5B15D91E5BFEFFA707CF800930F8401* ___s_rentedSocketSentinel_3;
	// System.Net.Sockets.Socket/Int32TaskSocketAsyncEventArgs System.Net.Sockets.Socket::s_rentedInt32Sentinel
	Int32TaskSocketAsyncEventArgs_t36C5FC82499ED9DAFE7F05C38EF92D77A0B248E9* ___s_rentedInt32Sentinel_4;
	// System.Threading.Tasks.Task`1<System.Int32> System.Net.Sockets.Socket::s_zeroTask
	Task_1_t4C228DE57804012969575431CFF12D57C875552D* ___s_zeroTask_5;
	// System.Object System.Net.Sockets.Socket::s_InternalSyncObject
	RuntimeObject* ___s_InternalSyncObject_7;
	// System.Boolean modreq(System.Runtime.CompilerServices.IsVolatile) System.Net.Sockets.Socket::s_SupportsIPv4
	bool ___s_SupportsIPv4_8;
	// System.Boolean modreq(System.Runtime.CompilerServices.IsVolatile) System.Net.Sockets.Socket::s_SupportsIPv6
	bool ___s_SupportsIPv6_9;
	// System.Boolean modreq(System.Runtime.CompilerServices.IsVolatile) System.Net.Sockets.Socket::s_OSSupportsIPv6
	bool ___s_OSSupportsIPv6_10;
	// System.Boolean modreq(System.Runtime.CompilerServices.IsVolatile) System.Net.Sockets.Socket::s_Initialized
	bool ___s_Initialized_11;
	// System.Boolean modreq(System.Runtime.CompilerServices.IsVolatile) System.Net.Sockets.Socket::s_LoggingEnabled
	bool ___s_LoggingEnabled_12;
	// System.AsyncCallback System.Net.Sockets.Socket::AcceptAsyncCallback
	AsyncCallback_t7FEF460CBDCFB9C5FA2EF776984778B9A4145F4C* ___AcceptAsyncCallback_28;
	// System.IOAsyncCallback System.Net.Sockets.Socket::BeginAcceptCallback
	IOAsyncCallback_tDBBA8BBDA6B203613680E77BD4AD6320A1268388* ___BeginAcceptCallback_29;
	// System.IOAsyncCallback System.Net.Sockets.Socket::BeginAcceptReceiveCallback
	IOAsyncCallback_tDBBA8BBDA6B203613680E77BD4AD6320A1268388* ___BeginAcceptReceiveCallback_30;
	// System.AsyncCallback System.Net.Sockets.Socket::ConnectAsyncCallback
	AsyncCallback_t7FEF460CBDCFB9C5FA2EF776984778B9A4145F4C* ___ConnectAsyncCallback_31;
	// System.IOAsyncCallback System.Net.Sockets.Socket::BeginConnectCallback
	IOAsyncCallback_tDBBA8BBDA6B203613680E77BD4AD6320A1268388* ___BeginConnectCallback_32;
	// System.AsyncCallback System.Net.Sockets.Socket::DisconnectAsyncCallback
	AsyncCallback_t7FEF460CBDCFB9C5FA2EF776984778B9A4145F4C* ___DisconnectAsyncCallback_33;
	// System.IOAsyncCallback System.Net.Sockets.Socket::BeginDisconnectCallback
	IOAsyncCallback_tDBBA8BBDA6B203613680E77BD4AD6320A1268388* ___BeginDisconnectCallback_34;
	// System.AsyncCallback System.Net.Sockets.Socket::ReceiveAsyncCallback
	AsyncCallback_t7FEF460CBDCFB9C5FA2EF776984778B9A4145F4C* ___ReceiveAsyncCallback_35;
	// System.IOAsyncCallback System.Net.Sockets.Socket::BeginReceiveCallback
	IOAsyncCallback_tDBBA8BBDA6B203613680E77BD4AD6320A1268388* ___BeginReceiveCallback_36;
	// System.IOAsyncCallback System.Net.Sockets.Socket::BeginReceiveGenericCallback
	IOAsyncCallback_tDBBA8BBDA6B203613680E77BD4AD6320A1268388* ___BeginReceiveGenericCallback_37;
	// System.AsyncCallback System.Net.Sockets.Socket::ReceiveFromAsyncCallback
	AsyncCallback_t7FEF460CBDCFB9C5FA2EF776984778B9A4145F4C* ___ReceiveFromAsyncCallback_38;
	// System.IOAsyncCallback System.Net.Sockets.Socket::BeginReceiveFromCallback
	IOAsyncCallback_tDBBA8BBDA6B203613680E77BD4AD6320A1268388* ___BeginReceiveFromCallback_39;
	// System.AsyncCallback System.Net.Sockets.Socket::SendAsyncCallback
	AsyncCallback_t7FEF460CBDCFB9C5FA2EF776984778B9A4145F4C* ___SendAsyncCallback_40;
	// System.IOAsyncCallback System.Net.Sockets.Socket::BeginSendGenericCallback
	IOAsyncCallback_tDBBA8BBDA6B203613680E77BD4AD6320A1268388* ___BeginSendGenericCallback_41;
	// System.AsyncCallback System.Net.Sockets.Socket::SendToAsyncCallback
	AsyncCallback_t7FEF460CBDCFB9C5FA2EF776984778B9A4145F4C* ___SendToAsyncCallback_42;
};

// System.String
struct String_t  : public RuntimeObject
{
	// System.Int32 System.String::_stringLength
	int32_t ____stringLength_4;
	// System.Char System.String::_firstChar
	Il2CppChar ____firstChar_5;
};

struct String_t_StaticFields
{
	// System.String System.String::Empty
	String_t* ___Empty_6;
};

// System.ValueType
struct ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F  : public RuntimeObject
{
};
// Native definition for P/Invoke marshalling of System.ValueType
struct ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F_marshaled_pinvoke
{
};
// Native definition for COM marshalling of System.ValueType
struct ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F_marshaled_com
{
};

// LiteNetLib.Utils.NetSerializer/CustomType
struct CustomType_t5DD67989E7FD0AC65476233C7C30A0BE5282624B  : public RuntimeObject
{
};

// System.Boolean
struct Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22 
{
	// System.Boolean System.Boolean::m_value
	bool ___m_value_0;
};

struct Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22_StaticFields
{
	// System.String System.Boolean::TrueString
	String_t* ___TrueString_5;
	// System.String System.Boolean::FalseString
	String_t* ___FalseString_6;
};

// System.Byte
struct Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3 
{
	// System.Byte System.Byte::m_value
	uint8_t ___m_value_0;
};

// System.Char
struct Char_t521A6F19B456D956AF452D926C32709DC03D6B17 
{
	// System.Char System.Char::m_value
	Il2CppChar ___m_value_0;
};

struct Char_t521A6F19B456D956AF452D926C32709DC03D6B17_StaticFields
{
	// System.Byte[] System.Char::s_categoryForLatin1
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___s_categoryForLatin1_3;
};

// LiteNetLib.Layers.Crc32cLayer
struct Crc32cLayer_tE5B2EC9CF4B04BF362ED013C539E1401F2529BA6  : public PacketLayerBase_tAE86828E66E9B4065BBE4DD1125AE7D0394EBE34
{
};

// System.DateTime
struct DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D 
{
	// System.UInt64 System.DateTime::_dateData
	uint64_t ____dateData_46;
};

struct DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D_StaticFields
{
	// System.Int32[] System.DateTime::s_daysToMonth365
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___s_daysToMonth365_30;
	// System.Int32[] System.DateTime::s_daysToMonth366
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___s_daysToMonth366_31;
	// System.DateTime System.DateTime::MinValue
	DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D ___MinValue_32;
	// System.DateTime System.DateTime::MaxValue
	DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D ___MaxValue_33;
	// System.DateTime System.DateTime::UnixEpoch
	DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D ___UnixEpoch_34;
};

// System.Double
struct Double_tE150EF3D1D43DEE85D533810AB4C742307EEDE5F 
{
	// System.Double System.Double::m_value
	double ___m_value_0;
};

// System.Net.IPEndPoint
struct IPEndPoint_t2F09CBA7A808B67724B4E2954EEDC46D910F4ECB  : public EndPoint_t6233F4E2EB9F0F2D36E187F12BE050E6D8B73564
{
	// System.Net.IPAddress System.Net.IPEndPoint::_address
	IPAddress_t2F4486449B0D73FF2D3B36A9FE5E9C3F63116484* ____address_0;
	// System.Int32 System.Net.IPEndPoint::_port
	int32_t ____port_1;
};

struct IPEndPoint_t2F09CBA7A808B67724B4E2954EEDC46D910F4ECB_StaticFields
{
	// System.Net.IPEndPoint System.Net.IPEndPoint::Any
	IPEndPoint_t2F09CBA7A808B67724B4E2954EEDC46D910F4ECB* ___Any_2;
	// System.Net.IPEndPoint System.Net.IPEndPoint::IPv6Any
	IPEndPoint_t2F09CBA7A808B67724B4E2954EEDC46D910F4ECB* ___IPv6Any_3;
};

// System.Int16
struct Int16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175 
{
	// System.Int16 System.Int16::m_value
	int16_t ___m_value_0;
};

// System.Int32
struct Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C 
{
	// System.Int32 System.Int32::m_value
	int32_t ___m_value_0;
};

// System.Int64
struct Int64_t092CFB123BE63C28ACDAF65C68F21A526050DBA3 
{
	// System.Int64 System.Int64::m_value
	int64_t ___m_value_0;
};

// System.IntPtr
struct IntPtr_t 
{
	// System.Void* System.IntPtr::m_value
	void* ___m_value_0;
};

struct IntPtr_t_StaticFields
{
	// System.IntPtr System.IntPtr::Zero
	intptr_t ___Zero_1;
};

// System.SByte
struct SByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5 
{
	// System.SByte System.SByte::m_value
	int8_t ___m_value_0;
};

// System.Single
struct Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C 
{
	// System.Single System.Single::m_value
	float ___m_value_0;
};

// System.TimeSpan
struct TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A 
{
	// System.Int64 System.TimeSpan::_ticks
	int64_t ____ticks_22;
};

struct TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A_StaticFields
{
	// System.TimeSpan System.TimeSpan::Zero
	TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A ___Zero_19;
	// System.TimeSpan System.TimeSpan::MaxValue
	TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A ___MaxValue_20;
	// System.TimeSpan System.TimeSpan::MinValue
	TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A ___MinValue_21;
};

// System.UInt16
struct UInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455 
{
	// System.UInt16 System.UInt16::m_value
	uint16_t ___m_value_0;
};

// System.UInt32
struct UInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B 
{
	// System.UInt32 System.UInt32::m_value
	uint32_t ___m_value_0;
};

// System.UInt64
struct UInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF 
{
	// System.UInt64 System.UInt64::m_value
	uint64_t ___m_value_0;
};

// System.Text.UTF8Encoding
struct UTF8Encoding_t90B56215A1B0B7ED5CDEA772E695F0DDAFBCD3BE  : public Encoding_t65CDEF28CF20A7B8C92E85A4E808920C2465F095
{
	// System.Boolean System.Text.UTF8Encoding::_emitUTF8Identifier
	bool ____emitUTF8Identifier_18;
	// System.Boolean System.Text.UTF8Encoding::_isThrowException
	bool ____isThrowException_19;
};

struct UTF8Encoding_t90B56215A1B0B7ED5CDEA772E695F0DDAFBCD3BE_StaticFields
{
	// System.Text.UTF8Encoding/UTF8EncodingSealed System.Text.UTF8Encoding::s_default
	UTF8EncodingSealed_tF97A34F40CABE9CE1C168967D60396F51C43DD36* ___s_default_16;
	// System.Byte[] System.Text.UTF8Encoding::s_preamble
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___s_preamble_17;
};

// System.Void
struct Void_t4861ACF8F4594C3437BB48B6E56783494B843915 
{
	union
	{
		struct
		{
		};
		uint8_t Void_t4861ACF8F4594C3437BB48B6E56783494B843915__padding[1];
	};
};

// LiteNetLib.Layers.XorEncryptLayer
struct XorEncryptLayer_tC167B2E4D09C6238B5F5AFD18AC29C99CD71A0C6  : public PacketLayerBase_tAE86828E66E9B4065BBE4DD1125AE7D0394EBE34
{
	// System.Byte[] LiteNetLib.Layers.XorEncryptLayer::_byteKey
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ____byteKey_1;
};

// <PrivateImplementationDetails>/__StaticArrayInitTypeSize=28
struct __StaticArrayInitTypeSizeU3D28_tDB8E14F4FE432F909C2C4CF59EC2A2F6760067D6 
{
	union
	{
		struct
		{
			union
			{
			};
		};
		uint8_t __StaticArrayInitTypeSizeU3D28_tDB8E14F4FE432F909C2C4CF59EC2A2F6760067D6__padding[28];
	};
};

// LiteNetLib.Utils.FastBitConverter/ConverterHelperDouble
struct ConverterHelperDouble_tEA01E41DCA5C15F9CEB90970D263BB7942F13935 
{
	union
	{
		#pragma pack(push, tp, 1)
		struct
		{
			// System.UInt64 LiteNetLib.Utils.FastBitConverter/ConverterHelperDouble::Along
			uint64_t ___Along_0;
		};
		#pragma pack(pop, tp)
		struct
		{
			uint64_t ___Along_0_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			// System.Double LiteNetLib.Utils.FastBitConverter/ConverterHelperDouble::Adouble
			double ___Adouble_1;
		};
		#pragma pack(pop, tp)
		struct
		{
			double ___Adouble_1_forAlignmentOnly;
		};
	};
};

// LiteNetLib.Utils.FastBitConverter/ConverterHelperFloat
struct ConverterHelperFloat_t8E65E8DEB449E589D8EA058CC702AE23CDA6D8C1 
{
	union
	{
		#pragma pack(push, tp, 1)
		struct
		{
			// System.Int32 LiteNetLib.Utils.FastBitConverter/ConverterHelperFloat::Aint
			int32_t ___Aint_0;
		};
		#pragma pack(pop, tp)
		struct
		{
			int32_t ___Aint_0_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			// System.Single LiteNetLib.Utils.FastBitConverter/ConverterHelperFloat::Afloat
			float ___Afloat_1;
		};
		#pragma pack(pop, tp)
		struct
		{
			float ___Afloat_1_forAlignmentOnly;
		};
	};
};

// System.Nullable`1<System.DateTime>
struct Nullable_1_tEADC262F7F8B8BC4CC0A003DBDD3CA7C1B63F9AC 
{
	// System.Boolean System.Nullable`1::hasValue
	bool ___hasValue_0;
	// T System.Nullable`1::value
	DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D ___value_1;
};

// <PrivateImplementationDetails>
struct U3CPrivateImplementationDetailsU3E_t0209332441E7E96BCF08FFBC46255A6DEC155AA9  : public RuntimeObject
{
};

struct U3CPrivateImplementationDetailsU3E_t0209332441E7E96BCF08FFBC46255A6DEC155AA9_StaticFields
{
	// <PrivateImplementationDetails>/__StaticArrayInitTypeSize=28 <PrivateImplementationDetails>::D79537A2F838755D540F3ECC461338CA43D2B18AEA28361726B8A7882AE00D99
	__StaticArrayInitTypeSizeU3D28_tDB8E14F4FE432F909C2C4CF59EC2A2F6760067D6 ___D79537A2F838755D540F3ECC461338CA43D2B18AEA28361726B8A7882AE00D99_0;
};

// System.Delegate
struct Delegate_t  : public RuntimeObject
{
	// System.IntPtr System.Delegate::method_ptr
	Il2CppMethodPointer ___method_ptr_0;
	// System.IntPtr System.Delegate::invoke_impl
	intptr_t ___invoke_impl_1;
	// System.Object System.Delegate::m_target
	RuntimeObject* ___m_target_2;
	// System.IntPtr System.Delegate::method
	intptr_t ___method_3;
	// System.IntPtr System.Delegate::delegate_trampoline
	intptr_t ___delegate_trampoline_4;
	// System.IntPtr System.Delegate::extra_arg
	intptr_t ___extra_arg_5;
	// System.IntPtr System.Delegate::method_code
	intptr_t ___method_code_6;
	// System.IntPtr System.Delegate::interp_method
	intptr_t ___interp_method_7;
	// System.IntPtr System.Delegate::interp_invoke_impl
	intptr_t ___interp_invoke_impl_8;
	// System.Reflection.MethodInfo System.Delegate::method_info
	MethodInfo_t* ___method_info_9;
	// System.Reflection.MethodInfo System.Delegate::original_method_info
	MethodInfo_t* ___original_method_info_10;
	// System.DelegateData System.Delegate::data
	DelegateData_t9B286B493293CD2D23A5B2B5EF0E5B1324C2B77E* ___data_11;
	// System.Boolean System.Delegate::method_is_virtual
	bool ___method_is_virtual_12;
};
// Native definition for P/Invoke marshalling of System.Delegate
struct Delegate_t_marshaled_pinvoke
{
	intptr_t ___method_ptr_0;
	intptr_t ___invoke_impl_1;
	Il2CppIUnknown* ___m_target_2;
	intptr_t ___method_3;
	intptr_t ___delegate_trampoline_4;
	intptr_t ___extra_arg_5;
	intptr_t ___method_code_6;
	intptr_t ___interp_method_7;
	intptr_t ___interp_invoke_impl_8;
	MethodInfo_t* ___method_info_9;
	MethodInfo_t* ___original_method_info_10;
	DelegateData_t9B286B493293CD2D23A5B2B5EF0E5B1324C2B77E* ___data_11;
	int32_t ___method_is_virtual_12;
};
// Native definition for COM marshalling of System.Delegate
struct Delegate_t_marshaled_com
{
	intptr_t ___method_ptr_0;
	intptr_t ___invoke_impl_1;
	Il2CppIUnknown* ___m_target_2;
	intptr_t ___method_3;
	intptr_t ___delegate_trampoline_4;
	intptr_t ___extra_arg_5;
	intptr_t ___method_code_6;
	intptr_t ___interp_method_7;
	intptr_t ___interp_invoke_impl_8;
	MethodInfo_t* ___method_info_9;
	MethodInfo_t* ___original_method_info_10;
	DelegateData_t9B286B493293CD2D23A5B2B5EF0E5B1324C2B77E* ___data_11;
	int32_t ___method_is_virtual_12;
};

// System.Exception
struct Exception_t  : public RuntimeObject
{
	// System.String System.Exception::_className
	String_t* ____className_1;
	// System.String System.Exception::_message
	String_t* ____message_2;
	// System.Collections.IDictionary System.Exception::_data
	RuntimeObject* ____data_3;
	// System.Exception System.Exception::_innerException
	Exception_t* ____innerException_4;
	// System.String System.Exception::_helpURL
	String_t* ____helpURL_5;
	// System.Object System.Exception::_stackTrace
	RuntimeObject* ____stackTrace_6;
	// System.String System.Exception::_stackTraceString
	String_t* ____stackTraceString_7;
	// System.String System.Exception::_remoteStackTraceString
	String_t* ____remoteStackTraceString_8;
	// System.Int32 System.Exception::_remoteStackIndex
	int32_t ____remoteStackIndex_9;
	// System.Object System.Exception::_dynamicMethods
	RuntimeObject* ____dynamicMethods_10;
	// System.Int32 System.Exception::_HResult
	int32_t ____HResult_11;
	// System.String System.Exception::_source
	String_t* ____source_12;
	// System.Runtime.Serialization.SafeSerializationManager System.Exception::_safeSerializationManager
	SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6* ____safeSerializationManager_13;
	// System.Diagnostics.StackTrace[] System.Exception::captured_traces
	StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF* ___captured_traces_14;
	// System.IntPtr[] System.Exception::native_trace_ips
	IntPtrU5BU5D_tFD177F8C806A6921AD7150264CCC62FA00CAD832* ___native_trace_ips_15;
	// System.Int32 System.Exception::caught_in_unmanaged
	int32_t ___caught_in_unmanaged_16;
};

struct Exception_t_StaticFields
{
	// System.Object System.Exception::s_EDILock
	RuntimeObject* ___s_EDILock_0;
};
// Native definition for P/Invoke marshalling of System.Exception
struct Exception_t_marshaled_pinvoke
{
	char* ____className_1;
	char* ____message_2;
	RuntimeObject* ____data_3;
	Exception_t_marshaled_pinvoke* ____innerException_4;
	char* ____helpURL_5;
	Il2CppIUnknown* ____stackTrace_6;
	char* ____stackTraceString_7;
	char* ____remoteStackTraceString_8;
	int32_t ____remoteStackIndex_9;
	Il2CppIUnknown* ____dynamicMethods_10;
	int32_t ____HResult_11;
	char* ____source_12;
	SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6* ____safeSerializationManager_13;
	StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF* ___captured_traces_14;
	Il2CppSafeArray/*NONE*/* ___native_trace_ips_15;
	int32_t ___caught_in_unmanaged_16;
};
// Native definition for COM marshalling of System.Exception
struct Exception_t_marshaled_com
{
	Il2CppChar* ____className_1;
	Il2CppChar* ____message_2;
	RuntimeObject* ____data_3;
	Exception_t_marshaled_com* ____innerException_4;
	Il2CppChar* ____helpURL_5;
	Il2CppIUnknown* ____stackTrace_6;
	Il2CppChar* ____stackTraceString_7;
	Il2CppChar* ____remoteStackTraceString_8;
	int32_t ____remoteStackIndex_9;
	Il2CppIUnknown* ____dynamicMethods_10;
	int32_t ____HResult_11;
	Il2CppChar* ____source_12;
	SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6* ____safeSerializationManager_13;
	StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF* ___captured_traces_14;
	Il2CppSafeArray/*NONE*/* ___native_trace_ips_15;
	int32_t ___caught_in_unmanaged_16;
};

// System.MulticastDelegate
struct MulticastDelegate_t  : public Delegate_t
{
	// System.Delegate[] System.MulticastDelegate::delegates
	DelegateU5BU5D_tC5AB7E8F745616680F337909D3A8E6C722CDF771* ___delegates_13;
};
// Native definition for P/Invoke marshalling of System.MulticastDelegate
struct MulticastDelegate_t_marshaled_pinvoke : public Delegate_t_marshaled_pinvoke
{
	Delegate_t_marshaled_pinvoke** ___delegates_13;
};
// Native definition for COM marshalling of System.MulticastDelegate
struct MulticastDelegate_t_marshaled_com : public Delegate_t_marshaled_com
{
	Delegate_t_marshaled_com** ___delegates_13;
};

// LiteNetLib.Utils.NtpPacket
struct NtpPacket_tF37CA19271AE795B037952A3137F652EF3B95E92  : public RuntimeObject
{
	// System.Byte[] LiteNetLib.Utils.NtpPacket::<Bytes>k__BackingField
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___U3CBytesU3Ek__BackingField_1;
	// System.Nullable`1<System.DateTime> LiteNetLib.Utils.NtpPacket::<DestinationTimestamp>k__BackingField
	Nullable_1_tEADC262F7F8B8BC4CC0A003DBDD3CA7C1B63F9AC ___U3CDestinationTimestampU3Ek__BackingField_2;
};

struct NtpPacket_tF37CA19271AE795B037952A3137F652EF3B95E92_StaticFields
{
	// System.DateTime LiteNetLib.Utils.NtpPacket::Epoch
	DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D ___Epoch_0;
};

// LiteNetLib.Utils.ParseException
struct ParseException_t78F4289CD37365426C09D2D805B6EFE254DA2266  : public Exception_t
{
};

// System.SystemException
struct SystemException_tCC48D868298F4C0705279823E34B00F4FBDB7295  : public Exception_t
{
};

// System.ArgumentException
struct ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263  : public SystemException_tCC48D868298F4C0705279823E34B00F4FBDB7295
{
	// System.String System.ArgumentException::_paramName
	String_t* ____paramName_18;
};

// System.AsyncCallback
struct AsyncCallback_t7FEF460CBDCFB9C5FA2EF776984778B9A4145F4C  : public MulticastDelegate_t
{
};

// System.InvalidOperationException
struct InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB  : public SystemException_tCC48D868298F4C0705279823E34B00F4FBDB7295
{
};

// LiteNetLib.Utils.NetPacketProcessor/SubscribeDelegate
struct SubscribeDelegate_t5176AD87F22014A136F003FB651B6451DB2BE13F  : public MulticastDelegate_t
{
};

// LiteNetLib.Utils.InvalidTypeException
struct InvalidTypeException_t3216C4E1075D00F909878A0C023BF525B9DFF127  : public ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263
{
};
#ifdef __clang__
#pragma clang diagnostic pop
#endif
// System.Byte[]
struct ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031  : public RuntimeArray
{
	ALIGN_FIELD (8) uint8_t m_Items[1];

	inline uint8_t GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline uint8_t* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, uint8_t value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline uint8_t GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline uint8_t* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, uint8_t value)
	{
		m_Items[index] = value;
	}
};
// System.SByte[]
struct SByteU5BU5D_t88116DA68378C3333DB73E7D36C1A06AFAA91913  : public RuntimeArray
{
	ALIGN_FIELD (8) int8_t m_Items[1];

	inline int8_t GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline int8_t* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, int8_t value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline int8_t GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline int8_t* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, int8_t value)
	{
		m_Items[index] = value;
	}
};
// System.Single[]
struct SingleU5BU5D_t89DEFE97BCEDB5857010E79ECE0F52CF6E93B87C  : public RuntimeArray
{
	ALIGN_FIELD (8) float m_Items[1];

	inline float GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline float* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, float value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline float GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline float* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, float value)
	{
		m_Items[index] = value;
	}
};
// System.Double[]
struct DoubleU5BU5D_tCC308475BD3B8229DB2582938669EF2F9ECC1FEE  : public RuntimeArray
{
	ALIGN_FIELD (8) double m_Items[1];

	inline double GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline double* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, double value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline double GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline double* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, double value)
	{
		m_Items[index] = value;
	}
};
// System.Int64[]
struct Int64U5BU5D_tAEDFCBDB5414E2A140A6F34C0538BF97FCF67A1D  : public RuntimeArray
{
	ALIGN_FIELD (8) int64_t m_Items[1];

	inline int64_t GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline int64_t* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, int64_t value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline int64_t GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline int64_t* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, int64_t value)
	{
		m_Items[index] = value;
	}
};
// System.UInt64[]
struct UInt64U5BU5D_tAB1A62450AC0899188486EDB9FC066B8BEED9299  : public RuntimeArray
{
	ALIGN_FIELD (8) uint64_t m_Items[1];

	inline uint64_t GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline uint64_t* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, uint64_t value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline uint64_t GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline uint64_t* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, uint64_t value)
	{
		m_Items[index] = value;
	}
};
// System.Int32[]
struct Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C  : public RuntimeArray
{
	ALIGN_FIELD (8) int32_t m_Items[1];

	inline int32_t GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline int32_t* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, int32_t value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline int32_t GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline int32_t* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, int32_t value)
	{
		m_Items[index] = value;
	}
};
// System.UInt32[]
struct UInt32U5BU5D_t02FBD658AD156A17574ECE6106CF1FBFCC9807FA  : public RuntimeArray
{
	ALIGN_FIELD (8) uint32_t m_Items[1];

	inline uint32_t GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline uint32_t* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, uint32_t value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline uint32_t GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline uint32_t* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, uint32_t value)
	{
		m_Items[index] = value;
	}
};
// System.UInt16[]
struct UInt16U5BU5D_tEB7C42D811D999D2AA815BADC3FCCDD9C67B3F83  : public RuntimeArray
{
	ALIGN_FIELD (8) uint16_t m_Items[1];

	inline uint16_t GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline uint16_t* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, uint16_t value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline uint16_t GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline uint16_t* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, uint16_t value)
	{
		m_Items[index] = value;
	}
};
// System.Int16[]
struct Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB  : public RuntimeArray
{
	ALIGN_FIELD (8) int16_t m_Items[1];

	inline int16_t GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline int16_t* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, int16_t value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline int16_t GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline int16_t* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, int16_t value)
	{
		m_Items[index] = value;
	}
};
// System.Boolean[]
struct BooleanU5BU5D_tD317D27C31DB892BE79FAE3AEBC0B3FFB73DE9B4  : public RuntimeArray
{
	ALIGN_FIELD (8) bool m_Items[1];

	inline bool GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline bool* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, bool value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline bool GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline bool* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, bool value)
	{
		m_Items[index] = value;
	}
};
// System.String[]
struct StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248  : public RuntimeArray
{
	ALIGN_FIELD (8) String_t* m_Items[1];

	inline String_t* GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline String_t** GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, String_t* value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
	inline String_t* GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline String_t** GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, String_t* value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
};
// System.Delegate[]
struct DelegateU5BU5D_tC5AB7E8F745616680F337909D3A8E6C722CDF771  : public RuntimeArray
{
	ALIGN_FIELD (8) Delegate_t* m_Items[1];

	inline Delegate_t* GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline Delegate_t** GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, Delegate_t* value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
	inline Delegate_t* GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline Delegate_t** GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, Delegate_t* value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
};
// System.Object[]
struct ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918  : public RuntimeArray
{
	ALIGN_FIELD (8) RuntimeObject* m_Items[1];

	inline RuntimeObject* GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline RuntimeObject** GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, RuntimeObject* value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
	inline RuntimeObject* GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline RuntimeObject** GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, RuntimeObject* value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
};


// System.Void System.Array::Resize<System.Byte>(T[]&,System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Array_Resize_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m82FEC5823560947D2B12C8D675AED2C190DF4F3F_gshared (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031** ___array0, int32_t ___newSize1, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.Dictionary`2<System.UInt64,System.Object>::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2__ctor_m5DA5AA64DE7BDB71265D475EF0B2D2E815A32E27_gshared (Dictionary_2_t01A465CD199FB14D59FEC2DC7DDE76D2CD0A09F4* __this, const RuntimeMethod* method) ;
// System.Boolean System.Collections.Generic.Dictionary`2<System.UInt64,System.Object>::TryGetValue(TKey,TValue&)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Dictionary_2_TryGetValue_m610AC9FAFAA596802CD176D49D81FC2E15278ABF_gshared (Dictionary_2_t01A465CD199FB14D59FEC2DC7DDE76D2CD0A09F4* __this, uint64_t ___key0, RuntimeObject** ___value1, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.Dictionary`2<System.Object,System.Object>::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2__ctor_m5B32FBC624618211EB461D59CFBB10E987FD1329_gshared (Dictionary_2_t14FE4A752A83D53771C584E4C8D14E01F2AFD7BA* __this, const RuntimeMethod* method) ;
// T System.Nullable`1<System.DateTime>::get_Value()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D Nullable_1_get_Value_m5A868F663848BC21C18F056731D3AC404CE59991_gshared (Nullable_1_tEADC262F7F8B8BC4CC0A003DBDD3CA7C1B63F9AC* __this, const RuntimeMethod* method) ;
// System.Void System.Nullable`1<System.DateTime>::.ctor(T)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Nullable_1__ctor_mB17304720EA19F5469A4883827F53A75FEB492CF_gshared (Nullable_1_tEADC262F7F8B8BC4CC0A003DBDD3CA7C1B63F9AC* __this, DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D ___value0, const RuntimeMethod* method) ;
// System.Boolean System.Nullable`1<System.DateTime>::get_HasValue()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Nullable_1_get_HasValue_m092C73DCE052BFB5C60A39EF9F4E3401AA95221C_gshared_inline (Nullable_1_tEADC262F7F8B8BC4CC0A003DBDD3CA7C1B63F9AC* __this, const RuntimeMethod* method) ;
// T[] System.Array::Empty<System.Object>()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* Array_Empty_TisRuntimeObject_m55011E8360A8199FB239A5787BA8631CDD6116FC_gshared_inline (const RuntimeMethod* method) ;

// System.Void LiteNetLib.Utils.NetDataWriter::.ctor(System.Boolean,System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NetDataWriter__ctor_mD71BDDE9AA76BF0B2571DD9EC4DB2B5AEED23B65 (NetDataWriter_t5AE108AEC4825ED3FB45AA93565703368228EB37* __this, bool ___autoResize0, int32_t ___initialSize1, const RuntimeMethod* method) ;
// System.Void System.Object::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2 (RuntimeObject* __this, const RuntimeMethod* method) ;
// System.Void LiteNetLib.Utils.NetDataWriter::Put(System.Byte[])
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NetDataWriter_Put_m6620926E0379435BC731C6CF1D8A0F2B1FFAD8E8 (NetDataWriter_t5AE108AEC4825ED3FB45AA93565703368228EB37* __this, ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___data0, const RuntimeMethod* method) ;
// System.Void LiteNetLib.Utils.NetDataWriter::Put(System.Byte[],System.Int32,System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NetDataWriter_Put_mEE909D6E69A8733E062C5DB68417A58D1E4FF3B9 (NetDataWriter_t5AE108AEC4825ED3FB45AA93565703368228EB37* __this, ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___data0, int32_t ___offset1, int32_t ___length2, const RuntimeMethod* method) ;
// System.Void LiteNetLib.Utils.NetDataWriter::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NetDataWriter__ctor_m5DFECA4F51F5567F3C7EDC64103ED6B4DC772C2F (NetDataWriter_t5AE108AEC4825ED3FB45AA93565703368228EB37* __this, const RuntimeMethod* method) ;
// System.Void LiteNetLib.Utils.NetDataWriter::Put(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NetDataWriter_Put_m40A032F477E6C5A55E526FF9D8CF668DC018FB63 (NetDataWriter_t5AE108AEC4825ED3FB45AA93565703368228EB37* __this, String_t* ___value0, const RuntimeMethod* method) ;
// System.Int32 System.Math::Max(System.Int32,System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Math_Max_m830F00B616D7A2130E46E974DFB27E9DA7FE30E5 (int32_t ___val10, int32_t ___val21, const RuntimeMethod* method) ;
// System.Void System.Array::Resize<System.Byte>(T[]&,System.Int32)
inline void Array_Resize_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m82FEC5823560947D2B12C8D675AED2C190DF4F3F (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031** ___array0, int32_t ___newSize1, const RuntimeMethod* method)
{
	((  void (*) (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031**, int32_t, const RuntimeMethod*))Array_Resize_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m82FEC5823560947D2B12C8D675AED2C190DF4F3F_gshared)(___array0, ___newSize1, method);
}
// System.Void LiteNetLib.Utils.NetDataWriter::ResizeIfNeed(System.Int32)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void NetDataWriter_ResizeIfNeed_mC1A12154624528056AA89E4B791727615D27D9A5_inline (NetDataWriter_t5AE108AEC4825ED3FB45AA93565703368228EB37* __this, int32_t ___newSize0, const RuntimeMethod* method) ;
// System.Void System.Buffer::BlockCopy(System.Array,System.Int32,System.Array,System.Int32,System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Buffer_BlockCopy_mD8CF7EC96ADA7A542CCA3F3C73510624E10197A9 (RuntimeArray* ___src0, int32_t ___srcOffset1, RuntimeArray* ___dst2, int32_t ___dstOffset3, int32_t ___count4, const RuntimeMethod* method) ;
// System.Void LiteNetLib.Utils.FastBitConverter::GetBytes(System.Byte[],System.Int32,System.Single)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void FastBitConverter_GetBytes_m5098DCCC8484C2205A958CBAFE694B1DB9EABEDF_inline (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___bytes0, int32_t ___startIndex1, float ___value2, const RuntimeMethod* method) ;
// System.Void LiteNetLib.Utils.FastBitConverter::GetBytes(System.Byte[],System.Int32,System.Double)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void FastBitConverter_GetBytes_m70B89BF0E1D92548FF494E5E751A0CFA4231B2C0_inline (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___bytes0, int32_t ___startIndex1, double ___value2, const RuntimeMethod* method) ;
// System.Void LiteNetLib.Utils.FastBitConverter::GetBytes(System.Byte[],System.Int32,System.Int64)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void FastBitConverter_GetBytes_m4623FFD1516846C025379E4B184E917E45B1EEB1_inline (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___bytes0, int32_t ___startIndex1, int64_t ___value2, const RuntimeMethod* method) ;
// System.Void LiteNetLib.Utils.FastBitConverter::GetBytes(System.Byte[],System.Int32,System.UInt64)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void FastBitConverter_GetBytes_m3AB77751A0F1D6246D7AC61C8EC6CE7AC7B0D203_inline (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___bytes0, int32_t ___startIndex1, uint64_t ___value2, const RuntimeMethod* method) ;
// System.Void LiteNetLib.Utils.FastBitConverter::GetBytes(System.Byte[],System.Int32,System.Int32)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void FastBitConverter_GetBytes_m6815D55E22E42D242F5C31826AE4FDAB91F6CB6C_inline (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___bytes0, int32_t ___startIndex1, int32_t ___value2, const RuntimeMethod* method) ;
// System.Void LiteNetLib.Utils.FastBitConverter::GetBytes(System.Byte[],System.Int32,System.UInt32)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void FastBitConverter_GetBytes_m59C97C6CD1243787969924BFAE61424CE82DA806_inline (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___bytes0, int32_t ___startIndex1, uint32_t ___value2, const RuntimeMethod* method) ;
// System.Void LiteNetLib.Utils.NetDataWriter::Put(System.UInt16)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NetDataWriter_Put_m8AA9410DD0C00EB7BC6E8493298A98B0C69B917E (NetDataWriter_t5AE108AEC4825ED3FB45AA93565703368228EB37* __this, uint16_t ___value0, const RuntimeMethod* method) ;
// System.Void LiteNetLib.Utils.FastBitConverter::GetBytes(System.Byte[],System.Int32,System.UInt16)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void FastBitConverter_GetBytes_m447B17AD55B29DE95E6B761770D1A648BF953382_inline (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___bytes0, int32_t ___startIndex1, uint16_t ___value2, const RuntimeMethod* method) ;
// System.Void LiteNetLib.Utils.FastBitConverter::GetBytes(System.Byte[],System.Int32,System.Int16)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void FastBitConverter_GetBytes_m51BB8E43416F790D6ACD5FD3F5AB477568FDFBB2_inline (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___bytes0, int32_t ___startIndex1, int16_t ___value2, const RuntimeMethod* method) ;
// System.Void LiteNetLib.Utils.NetDataWriter::Put(System.Byte)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NetDataWriter_Put_m04CE888E8D3551B7E85403CEC1F0579368BA5C54 (NetDataWriter_t5AE108AEC4825ED3FB45AA93565703368228EB37* __this, uint8_t ___value0, const RuntimeMethod* method) ;
// System.Int32 System.Array::get_Length()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Array_get_Length_m361285FB7CF44045DC369834D1CD01F72F94EF57 (RuntimeArray* __this, const RuntimeMethod* method) ;
// System.Void LiteNetLib.Utils.NetDataWriter::PutArray(System.Array,System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NetDataWriter_PutArray_m706C91C3087F6FB84A527B0BC46366B42E2E26A9 (NetDataWriter_t5AE108AEC4825ED3FB45AA93565703368228EB37* __this, RuntimeArray* ___arr0, int32_t ___sz1, const RuntimeMethod* method) ;
// System.Void LiteNetLib.Utils.NetDataWriter::Put(System.String,System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NetDataWriter_Put_m81B08D1F055A09468E4DE6D60F7A28F12AD56B77 (NetDataWriter_t5AE108AEC4825ED3FB45AA93565703368228EB37* __this, String_t* ___value0, int32_t ___maxLength1, const RuntimeMethod* method) ;
// System.Net.IPAddress System.Net.IPEndPoint::get_Address()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR IPAddress_t2F4486449B0D73FF2D3B36A9FE5E9C3F63116484* IPEndPoint_get_Address_m72F783CB76E10E9DBDF680CCC1DAAED201BABB1C_inline (IPEndPoint_t2F09CBA7A808B67724B4E2954EEDC46D910F4ECB* __this, const RuntimeMethod* method) ;
// System.Int32 System.Net.IPEndPoint::get_Port()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t IPEndPoint_get_Port_mFBE1AF1C9CC7E68A46BF46AD3869CC9DC01CF429_inline (IPEndPoint_t2F09CBA7A808B67724B4E2954EEDC46D910F4ECB* __this, const RuntimeMethod* method) ;
// System.Void LiteNetLib.Utils.NetDataWriter::Put(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NetDataWriter_Put_m2F26BB86FF421E370E72E34145DE801E15DC5603 (NetDataWriter_t5AE108AEC4825ED3FB45AA93565703368228EB37* __this, int32_t ___value0, const RuntimeMethod* method) ;
// System.Int32 System.String::get_Length()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t String_get_Length_m42625D67623FA5CC7A44D47425CE86FB946542D2_inline (String_t* __this, const RuntimeMethod* method) ;
// System.Void System.Text.UTF8Encoding::.ctor(System.Boolean,System.Boolean)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UTF8Encoding__ctor_m128F4B4A103E718AAB699E2D64011DB13F486726 (UTF8Encoding_t90B56215A1B0B7ED5CDEA772E695F0DDAFBCD3BE* __this, bool ___encoderShouldEmitUTF8Identifier0, bool ___throwOnInvalidBytes1, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.Dictionary`2<System.UInt64,LiteNetLib.Utils.NetPacketProcessor/SubscribeDelegate>::.ctor()
inline void Dictionary_2__ctor_mD1E3D96A898D0AE25D21A35F907E8FD90F077ECF (Dictionary_2_tC50529CA8871074E26D545E7CB9D085D0D295AEA* __this, const RuntimeMethod* method)
{
	((  void (*) (Dictionary_2_tC50529CA8871074E26D545E7CB9D085D0D295AEA*, const RuntimeMethod*))Dictionary_2__ctor_m5DA5AA64DE7BDB71265D475EF0B2D2E815A32E27_gshared)(__this, method);
}
// System.Void LiteNetLib.Utils.NetSerializer::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NetSerializer__ctor_mD0D1DD7D5B57C35D5907108CB139C588A247DF1C (NetSerializer_t6F1385A0BDE64EB9921D4351CFD84FF864E111DE* __this, const RuntimeMethod* method) ;
// System.Void LiteNetLib.Utils.NetSerializer::.ctor(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NetSerializer__ctor_m11AB0F1B8B19828B0D3F334BD94BF415801C6CFB (NetSerializer_t6F1385A0BDE64EB9921D4351CFD84FF864E111DE* __this, int32_t ___maxStringLength0, const RuntimeMethod* method) ;
// System.UInt64 LiteNetLib.Utils.NetDataReader::GetULong()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint64_t NetDataReader_GetULong_mB830F45D1FB580C0FE865A3181548680E6EC53CC (NetDataReader_t28CDAC4E19A9CDCCE3F782A3E29084D50A2F58FF* __this, const RuntimeMethod* method) ;
// System.Boolean System.Collections.Generic.Dictionary`2<System.UInt64,LiteNetLib.Utils.NetPacketProcessor/SubscribeDelegate>::TryGetValue(TKey,TValue&)
inline bool Dictionary_2_TryGetValue_mC87F2380785378011E6B2A46B0B81908F6A5000C (Dictionary_2_tC50529CA8871074E26D545E7CB9D085D0D295AEA* __this, uint64_t ___key0, SubscribeDelegate_t5176AD87F22014A136F003FB651B6451DB2BE13F** ___value1, const RuntimeMethod* method)
{
	return ((  bool (*) (Dictionary_2_tC50529CA8871074E26D545E7CB9D085D0D295AEA*, uint64_t, SubscribeDelegate_t5176AD87F22014A136F003FB651B6451DB2BE13F**, const RuntimeMethod*))Dictionary_2_TryGetValue_m610AC9FAFAA596802CD176D49D81FC2E15278ABF_gshared)(__this, ___key0, ___value1, method);
}
// System.Void LiteNetLib.Utils.ParseException::.ctor(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ParseException__ctor_mF84E89C28BAD77FDEF412A03D7A25BBE5EDF2DC8 (ParseException_t78F4289CD37365426C09D2D805B6EFE254DA2266* __this, String_t* ___message0, const RuntimeMethod* method) ;
// System.Void LiteNetLib.Utils.NetPacketProcessor::ReadPacket(LiteNetLib.Utils.NetDataReader)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NetPacketProcessor_ReadPacket_m25BBA8ED257E115D193D695435756946944A8CE1 (NetPacketProcessor_t535112850E31D87B64B84496790A24B227A1B65C* __this, NetDataReader_t28CDAC4E19A9CDCCE3F782A3E29084D50A2F58FF* ___reader0, const RuntimeMethod* method) ;
// System.Int32 LiteNetLib.Utils.NetDataReader::get_AvailableBytes()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t NetDataReader_get_AvailableBytes_mEFB8DB278DBA8EAD90E606050F06B83BAFC260EB (NetDataReader_t28CDAC4E19A9CDCCE3F782A3E29084D50A2F58FF* __this, const RuntimeMethod* method) ;
// System.Void LiteNetLib.Utils.NetPacketProcessor::ReadPacket(LiteNetLib.Utils.NetDataReader,System.Object)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NetPacketProcessor_ReadPacket_m20EA197B034B623B752225213DD2240F4B9686DA (NetPacketProcessor_t535112850E31D87B64B84496790A24B227A1B65C* __this, NetDataReader_t28CDAC4E19A9CDCCE3F782A3E29084D50A2F58FF* ___reader0, RuntimeObject* ___userData1, const RuntimeMethod* method) ;
// System.Void LiteNetLib.Utils.NetPacketProcessor/SubscribeDelegate::Invoke(LiteNetLib.Utils.NetDataReader,System.Object)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void SubscribeDelegate_Invoke_m803C81F37C8A72A124C26584AD4938FA1F7FD77C_inline (SubscribeDelegate_t5176AD87F22014A136F003FB651B6451DB2BE13F* __this, NetDataReader_t28CDAC4E19A9CDCCE3F782A3E29084D50A2F58FF* ___reader0, RuntimeObject* ___userData1, const RuntimeMethod* method) ;
// System.Void System.ArgumentException::.ctor(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ArgumentException__ctor_m026938A67AF9D36BB7ED27F80425D7194B514465 (ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263* __this, String_t* ___message0, const RuntimeMethod* method) ;
// System.Void System.Exception::.ctor(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Exception__ctor_m9B2BD92CD68916245A75109105D9071C9D430E7F (Exception_t* __this, String_t* ___message0, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.Dictionary`2<System.Type,LiteNetLib.Utils.NetSerializer/CustomType>::.ctor()
inline void Dictionary_2__ctor_mE1C7F4DEE5EFADD1C6C6AFBEE21572DEF740AA96 (Dictionary_2_tE9744A9551C9F7ADCA9DCECD5809D05C5FCD8FB8* __this, const RuntimeMethod* method)
{
	((  void (*) (Dictionary_2_tE9744A9551C9F7ADCA9DCECD5809D05C5FCD8FB8*, const RuntimeMethod*))Dictionary_2__ctor_m5B32FBC624618211EB461D59CFBB10E987FD1329_gshared)(__this, method);
}
// System.Byte[] LiteNetLib.Utils.NtpPacket::get_Bytes()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* NtpPacket_get_Bytes_m6E68BBD8630A83EEB78A27E590D38FF01C83E6C3_inline (NtpPacket_tF37CA19271AE795B037952A3137F652EF3B95E92* __this, const RuntimeMethod* method) ;
// System.TimeSpan LiteNetLib.Utils.NtpPacket::GetTimeSpan32(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A NtpPacket_GetTimeSpan32_m9FFAC53FB307FD2C01EDB48D503D3030500FEC41 (NtpPacket_tF37CA19271AE795B037952A3137F652EF3B95E92* __this, int32_t ___offset0, const RuntimeMethod* method) ;
// System.UInt32 LiteNetLib.Utils.NtpPacket::GetUInt32BE(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint32_t NtpPacket_GetUInt32BE_m105480B326D4407FB1FBA477AE2B12D22A38F0D6 (NtpPacket_tF37CA19271AE795B037952A3137F652EF3B95E92* __this, int32_t ___offset0, const RuntimeMethod* method) ;
// System.Nullable`1<System.DateTime> LiteNetLib.Utils.NtpPacket::GetDateTime64(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Nullable_1_tEADC262F7F8B8BC4CC0A003DBDD3CA7C1B63F9AC NtpPacket_GetDateTime64_m486CD5CC1B530B599628C3FE1E7F0D4919DADC53 (NtpPacket_tF37CA19271AE795B037952A3137F652EF3B95E92* __this, int32_t ___offset0, const RuntimeMethod* method) ;
// System.Void LiteNetLib.Utils.NtpPacket::SetDateTime64(System.Int32,System.Nullable`1<System.DateTime>)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NtpPacket_SetDateTime64_mE26BA10DF6C3DB312C2FA0E912961C34FD5E20C6 (NtpPacket_tF37CA19271AE795B037952A3137F652EF3B95E92* __this, int32_t ___offset0, Nullable_1_tEADC262F7F8B8BC4CC0A003DBDD3CA7C1B63F9AC ___value1, const RuntimeMethod* method) ;
// System.Void LiteNetLib.Utils.NtpPacket::CheckTimestamps()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NtpPacket_CheckTimestamps_mD370D48027EFB0EC0A5129B2E90F545D44E5EE64 (NtpPacket_tF37CA19271AE795B037952A3137F652EF3B95E92* __this, const RuntimeMethod* method) ;
// System.Nullable`1<System.DateTime> LiteNetLib.Utils.NtpPacket::get_ReceiveTimestamp()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Nullable_1_tEADC262F7F8B8BC4CC0A003DBDD3CA7C1B63F9AC NtpPacket_get_ReceiveTimestamp_mB169F736E742626862CEB3BAB4CFC2C9B72D59F8 (NtpPacket_tF37CA19271AE795B037952A3137F652EF3B95E92* __this, const RuntimeMethod* method) ;
// T System.Nullable`1<System.DateTime>::get_Value()
inline DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D Nullable_1_get_Value_m5A868F663848BC21C18F056731D3AC404CE59991 (Nullable_1_tEADC262F7F8B8BC4CC0A003DBDD3CA7C1B63F9AC* __this, const RuntimeMethod* method)
{
	return ((  DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D (*) (Nullable_1_tEADC262F7F8B8BC4CC0A003DBDD3CA7C1B63F9AC*, const RuntimeMethod*))Nullable_1_get_Value_m5A868F663848BC21C18F056731D3AC404CE59991_gshared)(__this, method);
}
// System.Nullable`1<System.DateTime> LiteNetLib.Utils.NtpPacket::get_OriginTimestamp()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Nullable_1_tEADC262F7F8B8BC4CC0A003DBDD3CA7C1B63F9AC NtpPacket_get_OriginTimestamp_m787D1313D7FC4C68928379E18EFCA30BB0D1DC15 (NtpPacket_tF37CA19271AE795B037952A3137F652EF3B95E92* __this, const RuntimeMethod* method) ;
// System.TimeSpan System.DateTime::op_Subtraction(System.DateTime,System.DateTime)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A DateTime_op_Subtraction_m41335EF0E6DCD52B23C64916CB973A0B4A9E0387 (DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D ___d10, DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D ___d21, const RuntimeMethod* method) ;
// System.Nullable`1<System.DateTime> LiteNetLib.Utils.NtpPacket::get_DestinationTimestamp()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Nullable_1_tEADC262F7F8B8BC4CC0A003DBDD3CA7C1B63F9AC NtpPacket_get_DestinationTimestamp_m959365B0E7ED9A24A9159DC34CA1581CCD1544A9_inline (NtpPacket_tF37CA19271AE795B037952A3137F652EF3B95E92* __this, const RuntimeMethod* method) ;
// System.Nullable`1<System.DateTime> LiteNetLib.Utils.NtpPacket::get_TransmitTimestamp()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Nullable_1_tEADC262F7F8B8BC4CC0A003DBDD3CA7C1B63F9AC NtpPacket_get_TransmitTimestamp_mA8AE43E3EB22AB1AB3D47F8DEB624CE634B24CA3 (NtpPacket_tF37CA19271AE795B037952A3137F652EF3B95E92* __this, const RuntimeMethod* method) ;
// System.TimeSpan System.TimeSpan::op_Addition(System.TimeSpan,System.TimeSpan)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A TimeSpan_op_Addition_m4CA781FA121EB39944AE59C6BDD9304C42E74DFB (TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A ___t10, TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A ___t21, const RuntimeMethod* method) ;
// System.TimeSpan System.TimeSpan::op_Subtraction(System.TimeSpan,System.TimeSpan)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A TimeSpan_op_Subtraction_mFFB8933364C5E1E2187CA0605445893F2872FBB8 (TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A ___t10, TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A ___t21, const RuntimeMethod* method) ;
// System.Int64 System.TimeSpan::get_Ticks()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int64_t TimeSpan_get_Ticks_mC50131E57621F29FACC53B3241432ABB874FA1B5_inline (TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A* __this, const RuntimeMethod* method) ;
// System.TimeSpan System.TimeSpan::FromTicks(System.Int64)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A TimeSpan_FromTicks_mFA529928E79B4BF5EC0265418844B196D8979A73 (int64_t ___value0, const RuntimeMethod* method) ;
// System.Void LiteNetLib.Utils.NtpPacket::.ctor(System.Byte[])
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NtpPacket__ctor_m42BD9C610A9863D191C040D0321813B1ED876932 (NtpPacket_tF37CA19271AE795B037952A3137F652EF3B95E92* __this, ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___bytes0, const RuntimeMethod* method) ;
// System.Void LiteNetLib.Utils.NtpPacket::set_Mode(LiteNetLib.Utils.NtpMode)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NtpPacket_set_Mode_m0B5EEEC21B94479A31FAC030B6D5B67527C64EB3 (NtpPacket_tF37CA19271AE795B037952A3137F652EF3B95E92* __this, int32_t ___value0, const RuntimeMethod* method) ;
// System.Void LiteNetLib.Utils.NtpPacket::set_VersionNumber(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NtpPacket_set_VersionNumber_m7B86709BF5EDAC346CFAB1EB13282EB7BA00B384 (NtpPacket_tF37CA19271AE795B037952A3137F652EF3B95E92* __this, int32_t ___value0, const RuntimeMethod* method) ;
// System.DateTime System.DateTime::get_UtcNow()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D DateTime_get_UtcNow_m5D776FFEBC81592B361E4C7AF373297C5DFB46FD (const RuntimeMethod* method) ;
// System.Void System.Nullable`1<System.DateTime>::.ctor(T)
inline void Nullable_1__ctor_mB17304720EA19F5469A4883827F53A75FEB492CF (Nullable_1_tEADC262F7F8B8BC4CC0A003DBDD3CA7C1B63F9AC* __this, DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D ___value0, const RuntimeMethod* method)
{
	((  void (*) (Nullable_1_tEADC262F7F8B8BC4CC0A003DBDD3CA7C1B63F9AC*, DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D, const RuntimeMethod*))Nullable_1__ctor_mB17304720EA19F5469A4883827F53A75FEB492CF_gshared)(__this, ___value0, method);
}
// System.Void LiteNetLib.Utils.NtpPacket::set_TransmitTimestamp(System.Nullable`1<System.DateTime>)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NtpPacket_set_TransmitTimestamp_m4B21A40F4CFB42E78F92894F1BDB3E4718B9FB6B (NtpPacket_tF37CA19271AE795B037952A3137F652EF3B95E92* __this, Nullable_1_tEADC262F7F8B8BC4CC0A003DBDD3CA7C1B63F9AC ___value0, const RuntimeMethod* method) ;
// System.Void System.ArgumentException::.ctor(System.String,System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ArgumentException__ctor_m8F9D40CE19D19B698A70F9A258640EB52DB39B62 (ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263* __this, String_t* ___message0, String_t* ___paramName1, const RuntimeMethod* method) ;
// System.Void LiteNetLib.Utils.NtpPacket::set_DestinationTimestamp(System.Nullable`1<System.DateTime>)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void NtpPacket_set_DestinationTimestamp_mA6061675D2ABA51638455121F12621CE523FDD5A_inline (NtpPacket_tF37CA19271AE795B037952A3137F652EF3B95E92* __this, Nullable_1_tEADC262F7F8B8BC4CC0A003DBDD3CA7C1B63F9AC ___value0, const RuntimeMethod* method) ;
// LiteNetLib.Utils.NtpMode LiteNetLib.Utils.NtpPacket::get_Mode()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t NtpPacket_get_Mode_m301D434C5382328D6E1BEAE493ABEF3B3CE89BBA (NtpPacket_tF37CA19271AE795B037952A3137F652EF3B95E92* __this, const RuntimeMethod* method) ;
// System.Void System.InvalidOperationException::.ctor(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void InvalidOperationException__ctor_mE4CB6F4712AB6D99A2358FBAE2E052B3EE976162 (InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB* __this, String_t* ___message0, const RuntimeMethod* method) ;
// System.Int32 LiteNetLib.Utils.NtpPacket::get_VersionNumber()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t NtpPacket_get_VersionNumber_m8BBA6DBFF2942AFA98F08707E5C2DF9402ACBDEB (NtpPacket_tF37CA19271AE795B037952A3137F652EF3B95E92* __this, const RuntimeMethod* method) ;
// System.Boolean System.Nullable`1<System.DateTime>::get_HasValue()
inline bool Nullable_1_get_HasValue_m092C73DCE052BFB5C60A39EF9F4E3401AA95221C_inline (Nullable_1_tEADC262F7F8B8BC4CC0A003DBDD3CA7C1B63F9AC* __this, const RuntimeMethod* method)
{
	return ((  bool (*) (Nullable_1_tEADC262F7F8B8BC4CC0A003DBDD3CA7C1B63F9AC*, const RuntimeMethod*))Nullable_1_get_HasValue_m092C73DCE052BFB5C60A39EF9F4E3401AA95221C_gshared_inline)(__this, method);
}
// System.Int32 LiteNetLib.Utils.NtpPacket::get_Stratum()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t NtpPacket_get_Stratum_mA87F41632A21B205B8EBC172DC69BE6586764D9D (NtpPacket_tF37CA19271AE795B037952A3137F652EF3B95E92* __this, const RuntimeMethod* method) ;
// System.UInt32 LiteNetLib.Utils.NtpPacket::get_ReferenceId()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint32_t NtpPacket_get_ReferenceId_m767F85AC132891BC56829857A5F613F68B510152 (NtpPacket_tF37CA19271AE795B037952A3137F652EF3B95E92* __this, const RuntimeMethod* method) ;
// System.String System.String::Format(System.String,System.Object)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* String_Format_m8C122B26BC5AA10E2550AECA16E57DAE10F07E30 (String_t* ___format0, RuntimeObject* ___arg01, const RuntimeMethod* method) ;
// LiteNetLib.Utils.NtpLeapIndicator LiteNetLib.Utils.NtpPacket::get_LeapIndicator()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t NtpPacket_get_LeapIndicator_m2EF17809EDB88F7D10BF8848FFAB2A96BCF8C5DE (NtpPacket_tF37CA19271AE795B037952A3137F652EF3B95E92* __this, const RuntimeMethod* method) ;
// System.UInt64 LiteNetLib.Utils.NtpPacket::GetUInt64BE(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint64_t NtpPacket_GetUInt64BE_m93EC98DF49734420FC1680733687BCA664199B43 (NtpPacket_tF37CA19271AE795B037952A3137F652EF3B95E92* __this, int32_t ___offset0, const RuntimeMethod* method) ;
// System.Int64 System.DateTime::get_Ticks()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int64_t DateTime_get_Ticks_mC2CF04ED0EAB425C72C2532FFC5743777F3C93A6 (DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D* __this, const RuntimeMethod* method) ;
// System.Int64 System.Convert::ToInt64(System.Double)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int64_t Convert_ToInt64_m5B707D520332D512D2B81C10D2F4044FA468C3A4 (double ___value0, const RuntimeMethod* method) ;
// System.Void System.DateTime::.ctor(System.Int64)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void DateTime__ctor_m64AFCE84ABB24698256EB9F635EFD0A221823441 (DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D* __this, int64_t ___ticks0, const RuntimeMethod* method) ;
// System.UInt64 System.Convert::ToUInt64(System.Double)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint64_t Convert_ToUInt64_m4990F2CE28C4CE3079D458BA578EFBA46D875B3E (double ___value0, const RuntimeMethod* method) ;
// System.Void LiteNetLib.Utils.NtpPacket::SetUInt64BE(System.Int32,System.UInt64)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NtpPacket_SetUInt64BE_mA70D52969F236DEA0DDA42F63D4B14B5DDDBDD9F (NtpPacket_tF37CA19271AE795B037952A3137F652EF3B95E92* __this, int32_t ___offset0, uint64_t ___value1, const RuntimeMethod* method) ;
// System.Int32 LiteNetLib.Utils.NtpPacket::GetInt32BE(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t NtpPacket_GetInt32BE_mF60AB8BE45EA446257393803636A541FD724796B (NtpPacket_tF37CA19271AE795B037952A3137F652EF3B95E92* __this, int32_t ___offset0, const RuntimeMethod* method) ;
// System.TimeSpan System.TimeSpan::FromSeconds(System.Double)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A TimeSpan_FromSeconds_mE585CC8180040ED064DC8B6546E6C94A129BFFC5 (double ___value0, const RuntimeMethod* method) ;
// System.UInt64 System.BitConverter::ToUInt64(System.Byte[],System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint64_t BitConverter_ToUInt64_mD74DF4F6535FC635EB8697FC5175A7D99E3C62BF (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___value0, int32_t ___startIndex1, const RuntimeMethod* method) ;
// System.UInt64 LiteNetLib.Utils.NtpPacket::SwapEndianness(System.UInt64)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint64_t NtpPacket_SwapEndianness_mE50FA3DE29D75D5BE0BDD499E87183E664A3A14F (uint64_t ___x0, const RuntimeMethod* method) ;
// System.UInt32 System.BitConverter::ToUInt32(System.Byte[],System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint32_t BitConverter_ToUInt32_m7EFCF9D77ACD0F2DA29F69587DDF6130391E6164 (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___value0, int32_t ___startIndex1, const RuntimeMethod* method) ;
// System.UInt32 LiteNetLib.Utils.NtpPacket::SwapEndianness(System.UInt32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint32_t NtpPacket_SwapEndianness_m19BF014CC8A80CCD9BFAA9520ABDEFE36A7A6F21 (uint32_t ___x0, const RuntimeMethod* method) ;
// System.Void System.DateTime::.ctor(System.Int32,System.Int32,System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void DateTime__ctor_mA3BF7CE28807F0A02634FD43913FAAFD989CEE88 (DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D* __this, int32_t ___year0, int32_t ___month1, int32_t ___day2, const RuntimeMethod* method) ;
// System.Void LiteNetLib.Utils.NtpPacket::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NtpPacket__ctor_m4774A3EAADB433550E3042AEE01D672807D6CAA1 (NtpPacket_tF37CA19271AE795B037952A3137F652EF3B95E92* __this, const RuntimeMethod* method) ;
// System.Int32 System.Net.Sockets.Socket::SendTo(System.Byte[],System.Int32,System.Int32,System.Net.Sockets.SocketFlags,System.Net.EndPoint)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Socket_SendTo_m07A6D82F7ABD61B6B9C87931035FCF793AA3D6F6 (Socket_t1F49472CDA22B581C29A258225ABF3ADA9DED67E* __this, ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___buffer0, int32_t ___offset1, int32_t ___size2, int32_t ___socketFlags3, EndPoint_t6233F4E2EB9F0F2D36E187F12BE050E6D8B73564* ___remoteEP4, const RuntimeMethod* method) ;
// System.Void LiteNetLib.Layers.PacketLayerBase::.ctor(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void PacketLayerBase__ctor_m518745B375D4BBE9FE54C01A56CCFE84586C2060 (PacketLayerBase_tAE86828E66E9B4065BBE4DD1125AE7D0394EBE34* __this, int32_t ___extraPacketSizeForLayer0, const RuntimeMethod* method) ;
// T[] System.Array::Empty<System.Object>()
inline ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* Array_Empty_TisRuntimeObject_m55011E8360A8199FB239A5787BA8631CDD6116FC_inline (const RuntimeMethod* method)
{
	return ((  ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* (*) (const RuntimeMethod*))Array_Empty_TisRuntimeObject_m55011E8360A8199FB239A5787BA8631CDD6116FC_gshared_inline)(method);
}
// System.Void LiteNetLib.NetDebug::WriteError(System.String,System.Object[])
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NetDebug_WriteError_mCB960BBE748324E00F648B43EFB0D7CA0551979D (String_t* ___str0, ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* ___args1, const RuntimeMethod* method) ;
// System.UInt32 LiteNetLib.Utils.CRC32C::Compute(System.Byte[],System.Int32,System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint32_t CRC32C_Compute_m2B8A441E6CDFAE365F8DC45B8F715E6D98339206 (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___input0, int32_t ___offset1, int32_t ___length2, const RuntimeMethod* method) ;
// System.Void LiteNetLib.Layers.XorEncryptLayer::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void XorEncryptLayer__ctor_mE1DDFA466F3736CC05845DCD0474C0C57EE3B134 (XorEncryptLayer_tC167B2E4D09C6238B5F5AFD18AC29C99CD71A0C6* __this, const RuntimeMethod* method) ;
// System.Void LiteNetLib.Layers.XorEncryptLayer::SetKey(System.Byte[])
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void XorEncryptLayer_SetKey_m9481E86375D09871E727C07EA0B562C28A5E3180 (XorEncryptLayer_tC167B2E4D09C6238B5F5AFD18AC29C99CD71A0C6* __this, ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___key0, const RuntimeMethod* method) ;
// System.Void LiteNetLib.Layers.XorEncryptLayer::SetKey(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void XorEncryptLayer_SetKey_m78C57CD5E1FBCC59794D0008201C917A02BD6381 (XorEncryptLayer_tC167B2E4D09C6238B5F5AFD18AC29C99CD71A0C6* __this, String_t* ___key0, const RuntimeMethod* method) ;
// System.Text.Encoding System.Text.Encoding::get_UTF8()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Encoding_t65CDEF28CF20A7B8C92E85A4E808920C2465F095* Encoding_get_UTF8_m9700ADA8E0F244002B2A89B483F1B2133B8FE336 (const RuntimeMethod* method) ;
// System.Void LiteNetLib.Utils.FastBitConverter::WriteLittleEndian(System.Byte[],System.Int32,System.Int32)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void FastBitConverter_WriteLittleEndian_m39386A96620235D784DD14E9CBF2CD3260310E35_inline (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___buffer0, int32_t ___offset1, int32_t ___data2, const RuntimeMethod* method) ;
// System.Void LiteNetLib.Utils.FastBitConverter::WriteLittleEndian(System.Byte[],System.Int32,System.UInt64)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void FastBitConverter_WriteLittleEndian_m0FCFB2E03F9E6FCA7E2032F4E5EAF28EDFC15194_inline (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___buffer0, int32_t ___offset1, uint64_t ___data2, const RuntimeMethod* method) ;
// System.Void LiteNetLib.Utils.FastBitConverter::WriteLittleEndian(System.Byte[],System.Int32,System.Int16)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void FastBitConverter_WriteLittleEndian_m5374178503DA746A783E6C56D593D899853845A5_inline (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___buffer0, int32_t ___offset1, int16_t ___data2, const RuntimeMethod* method) ;
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Int32 LiteNetLib.Utils.NetDataWriter::get_Capacity()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t NetDataWriter_get_Capacity_mBF362C0466477A218A34723CDA161387D185083F (NetDataWriter_t5AE108AEC4825ED3FB45AA93565703368228EB37* __this, const RuntimeMethod* method) 
{
	{
		// public int Capacity => _data.Length;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_0 = __this->____data_0;
		NullCheck(L_0);
		return ((int32_t)(((RuntimeArray*)L_0)->max_length));
	}
}
// System.Byte[] LiteNetLib.Utils.NetDataWriter::get_Data()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* NetDataWriter_get_Data_mA7D60D2BCF3DAB2459E298A2B586CD7E84E3B89A (NetDataWriter_t5AE108AEC4825ED3FB45AA93565703368228EB37* __this, const RuntimeMethod* method) 
{
	{
		// public byte[] Data => _data;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_0 = __this->____data_0;
		return L_0;
	}
}
// System.Int32 LiteNetLib.Utils.NetDataWriter::get_Length()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t NetDataWriter_get_Length_m29BE8BF30196F806164C2D7B84AF341B7E421011 (NetDataWriter_t5AE108AEC4825ED3FB45AA93565703368228EB37* __this, const RuntimeMethod* method) 
{
	{
		// public int Length => _position;
		int32_t L_0 = __this->____position_1;
		return L_0;
	}
}
// System.Void LiteNetLib.Utils.NetDataWriter::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NetDataWriter__ctor_m5DFECA4F51F5567F3C7EDC64103ED6B4DC772C2F (NetDataWriter_t5AE108AEC4825ED3FB45AA93565703368228EB37* __this, const RuntimeMethod* method) 
{
	{
		// public NetDataWriter() : this(true, InitialSize)
		NetDataWriter__ctor_mD71BDDE9AA76BF0B2571DD9EC4DB2B5AEED23B65(__this, (bool)1, ((int32_t)64), NULL);
		// }
		return;
	}
}
// System.Void LiteNetLib.Utils.NetDataWriter::.ctor(System.Boolean)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NetDataWriter__ctor_m7179BBE008E6FA62110B2F577AE173A68DA2C647 (NetDataWriter_t5AE108AEC4825ED3FB45AA93565703368228EB37* __this, bool ___autoResize0, const RuntimeMethod* method) 
{
	{
		// public NetDataWriter(bool autoResize) : this(autoResize, InitialSize)
		bool L_0 = ___autoResize0;
		NetDataWriter__ctor_mD71BDDE9AA76BF0B2571DD9EC4DB2B5AEED23B65(__this, L_0, ((int32_t)64), NULL);
		// }
		return;
	}
}
// System.Void LiteNetLib.Utils.NetDataWriter::.ctor(System.Boolean,System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NetDataWriter__ctor_mD71BDDE9AA76BF0B2571DD9EC4DB2B5AEED23B65 (NetDataWriter_t5AE108AEC4825ED3FB45AA93565703368228EB37* __this, bool ___autoResize0, int32_t ___initialSize1, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// private readonly byte[] _stringBuffer = new byte[StringBufferMaxLength];
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_0 = (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)SZArrayNew(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var, (uint32_t)((int32_t)32768));
		__this->____stringBuffer_6 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____stringBuffer_6), (void*)L_0);
		// public NetDataWriter(bool autoResize, int initialSize)
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		// _data = new byte[initialSize];
		int32_t L_1 = ___initialSize1;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_2 = (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)SZArrayNew(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var, (uint32_t)L_1);
		__this->____data_0 = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____data_0), (void*)L_2);
		// _autoResize = autoResize;
		bool L_3 = ___autoResize0;
		__this->____autoResize_3 = L_3;
		// }
		return;
	}
}
// LiteNetLib.Utils.NetDataWriter LiteNetLib.Utils.NetDataWriter::FromBytes(System.Byte[],System.Boolean)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR NetDataWriter_t5AE108AEC4825ED3FB45AA93565703368228EB37* NetDataWriter_FromBytes_m513200E41B89D05A5860E42201C69D3F78BE831E (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___bytes0, bool ___copy1, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&NetDataWriter_t5AE108AEC4825ED3FB45AA93565703368228EB37_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// if (copy)
		bool L_0 = ___copy1;
		if (!L_0)
		{
			goto IL_0014;
		}
	}
	{
		// var netDataWriter = new NetDataWriter(true, bytes.Length);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_1 = ___bytes0;
		NullCheck(L_1);
		NetDataWriter_t5AE108AEC4825ED3FB45AA93565703368228EB37* L_2 = (NetDataWriter_t5AE108AEC4825ED3FB45AA93565703368228EB37*)il2cpp_codegen_object_new(NetDataWriter_t5AE108AEC4825ED3FB45AA93565703368228EB37_il2cpp_TypeInfo_var);
		NullCheck(L_2);
		NetDataWriter__ctor_mD71BDDE9AA76BF0B2571DD9EC4DB2B5AEED23B65(L_2, (bool)1, ((int32_t)(((RuntimeArray*)L_1)->max_length)), NULL);
		// netDataWriter.Put(bytes);
		NetDataWriter_t5AE108AEC4825ED3FB45AA93565703368228EB37* L_3 = L_2;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_4 = ___bytes0;
		NullCheck(L_3);
		NetDataWriter_Put_m6620926E0379435BC731C6CF1D8A0F2B1FFAD8E8(L_3, L_4, NULL);
		// return netDataWriter;
		return L_3;
	}

IL_0014:
	{
		// return new NetDataWriter(true, 0) {_data = bytes, _position = bytes.Length};
		NetDataWriter_t5AE108AEC4825ED3FB45AA93565703368228EB37* L_5 = (NetDataWriter_t5AE108AEC4825ED3FB45AA93565703368228EB37*)il2cpp_codegen_object_new(NetDataWriter_t5AE108AEC4825ED3FB45AA93565703368228EB37_il2cpp_TypeInfo_var);
		NullCheck(L_5);
		NetDataWriter__ctor_mD71BDDE9AA76BF0B2571DD9EC4DB2B5AEED23B65(L_5, (bool)1, 0, NULL);
		NetDataWriter_t5AE108AEC4825ED3FB45AA93565703368228EB37* L_6 = L_5;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_7 = ___bytes0;
		NullCheck(L_6);
		L_6->____data_0 = L_7;
		Il2CppCodeGenWriteBarrier((void**)(&L_6->____data_0), (void*)L_7);
		NetDataWriter_t5AE108AEC4825ED3FB45AA93565703368228EB37* L_8 = L_6;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_9 = ___bytes0;
		NullCheck(L_9);
		NullCheck(L_8);
		L_8->____position_1 = ((int32_t)(((RuntimeArray*)L_9)->max_length));
		return L_8;
	}
}
// LiteNetLib.Utils.NetDataWriter LiteNetLib.Utils.NetDataWriter::FromBytes(System.Byte[],System.Int32,System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR NetDataWriter_t5AE108AEC4825ED3FB45AA93565703368228EB37* NetDataWriter_FromBytes_m11001682345935B55F4BF77EFDF09E021F854A1A (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___bytes0, int32_t ___offset1, int32_t ___length2, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&NetDataWriter_t5AE108AEC4825ED3FB45AA93565703368228EB37_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// var netDataWriter = new NetDataWriter(true, bytes.Length);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_0 = ___bytes0;
		NullCheck(L_0);
		NetDataWriter_t5AE108AEC4825ED3FB45AA93565703368228EB37* L_1 = (NetDataWriter_t5AE108AEC4825ED3FB45AA93565703368228EB37*)il2cpp_codegen_object_new(NetDataWriter_t5AE108AEC4825ED3FB45AA93565703368228EB37_il2cpp_TypeInfo_var);
		NullCheck(L_1);
		NetDataWriter__ctor_mD71BDDE9AA76BF0B2571DD9EC4DB2B5AEED23B65(L_1, (bool)1, ((int32_t)(((RuntimeArray*)L_0)->max_length)), NULL);
		// netDataWriter.Put(bytes, offset, length);
		NetDataWriter_t5AE108AEC4825ED3FB45AA93565703368228EB37* L_2 = L_1;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_3 = ___bytes0;
		int32_t L_4 = ___offset1;
		int32_t L_5 = ___length2;
		NullCheck(L_2);
		NetDataWriter_Put_mEE909D6E69A8733E062C5DB68417A58D1E4FF3B9(L_2, L_3, L_4, L_5, NULL);
		// return netDataWriter;
		return L_2;
	}
}
// LiteNetLib.Utils.NetDataWriter LiteNetLib.Utils.NetDataWriter::FromString(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR NetDataWriter_t5AE108AEC4825ED3FB45AA93565703368228EB37* NetDataWriter_FromString_mDF5F7ACB9D10F510D26D9E4CA88817BD05651481 (String_t* ___value0, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&NetDataWriter_t5AE108AEC4825ED3FB45AA93565703368228EB37_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// var netDataWriter = new NetDataWriter();
		NetDataWriter_t5AE108AEC4825ED3FB45AA93565703368228EB37* L_0 = (NetDataWriter_t5AE108AEC4825ED3FB45AA93565703368228EB37*)il2cpp_codegen_object_new(NetDataWriter_t5AE108AEC4825ED3FB45AA93565703368228EB37_il2cpp_TypeInfo_var);
		NullCheck(L_0);
		NetDataWriter__ctor_m5DFECA4F51F5567F3C7EDC64103ED6B4DC772C2F(L_0, NULL);
		// netDataWriter.Put(value);
		NetDataWriter_t5AE108AEC4825ED3FB45AA93565703368228EB37* L_1 = L_0;
		String_t* L_2 = ___value0;
		NullCheck(L_1);
		NetDataWriter_Put_m40A032F477E6C5A55E526FF9D8CF668DC018FB63(L_1, L_2, NULL);
		// return netDataWriter;
		return L_1;
	}
}
// System.Void LiteNetLib.Utils.NetDataWriter::ResizeIfNeed(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NetDataWriter_ResizeIfNeed_mC1A12154624528056AA89E4B791727615D27D9A5 (NetDataWriter_t5AE108AEC4825ED3FB45AA93565703368228EB37* __this, int32_t ___newSize0, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Array_Resize_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m82FEC5823560947D2B12C8D675AED2C190DF4F3F_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Math_tEB65DE7CA8B083C412C969C92981C030865486CE_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// if (_data.Length < newSize)
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_0 = __this->____data_0;
		NullCheck(L_0);
		int32_t L_1 = ___newSize0;
		if ((((int32_t)((int32_t)(((RuntimeArray*)L_0)->max_length))) >= ((int32_t)L_1)))
		{
			goto IL_0026;
		}
	}
	{
		// Array.Resize(ref _data, Math.Max(newSize, _data.Length * 2));
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031** L_2 = (&__this->____data_0);
		int32_t L_3 = ___newSize0;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_4 = __this->____data_0;
		NullCheck(L_4);
		il2cpp_codegen_runtime_class_init_inline(Math_tEB65DE7CA8B083C412C969C92981C030865486CE_il2cpp_TypeInfo_var);
		int32_t L_5;
		L_5 = Math_Max_m830F00B616D7A2130E46E974DFB27E9DA7FE30E5(L_3, ((int32_t)il2cpp_codegen_multiply(((int32_t)(((RuntimeArray*)L_4)->max_length)), 2)), NULL);
		Array_Resize_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m82FEC5823560947D2B12C8D675AED2C190DF4F3F(L_2, L_5, Array_Resize_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m82FEC5823560947D2B12C8D675AED2C190DF4F3F_RuntimeMethod_var);
	}

IL_0026:
	{
		// }
		return;
	}
}
// System.Void LiteNetLib.Utils.NetDataWriter::EnsureFit(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NetDataWriter_EnsureFit_m4087072F80F2086F6DE0FC6AA1E2F08EF863D0EB (NetDataWriter_t5AE108AEC4825ED3FB45AA93565703368228EB37* __this, int32_t ___additionalSize0, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Array_Resize_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m82FEC5823560947D2B12C8D675AED2C190DF4F3F_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Math_tEB65DE7CA8B083C412C969C92981C030865486CE_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// if (_data.Length < _position + additionalSize)
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_0 = __this->____data_0;
		NullCheck(L_0);
		int32_t L_1 = __this->____position_1;
		int32_t L_2 = ___additionalSize0;
		if ((((int32_t)((int32_t)(((RuntimeArray*)L_0)->max_length))) >= ((int32_t)((int32_t)il2cpp_codegen_add(L_1, L_2)))))
		{
			goto IL_0034;
		}
	}
	{
		// Array.Resize(ref _data, Math.Max(_position + additionalSize, _data.Length * 2));
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031** L_3 = (&__this->____data_0);
		int32_t L_4 = __this->____position_1;
		int32_t L_5 = ___additionalSize0;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_6 = __this->____data_0;
		NullCheck(L_6);
		il2cpp_codegen_runtime_class_init_inline(Math_tEB65DE7CA8B083C412C969C92981C030865486CE_il2cpp_TypeInfo_var);
		int32_t L_7;
		L_7 = Math_Max_m830F00B616D7A2130E46E974DFB27E9DA7FE30E5(((int32_t)il2cpp_codegen_add(L_4, L_5)), ((int32_t)il2cpp_codegen_multiply(((int32_t)(((RuntimeArray*)L_6)->max_length)), 2)), NULL);
		Array_Resize_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m82FEC5823560947D2B12C8D675AED2C190DF4F3F(L_3, L_7, Array_Resize_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m82FEC5823560947D2B12C8D675AED2C190DF4F3F_RuntimeMethod_var);
	}

IL_0034:
	{
		// }
		return;
	}
}
// System.Void LiteNetLib.Utils.NetDataWriter::Reset(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NetDataWriter_Reset_m430E03A2453CCE0B9D0077852F3193184E9F3DF9 (NetDataWriter_t5AE108AEC4825ED3FB45AA93565703368228EB37* __this, int32_t ___size0, const RuntimeMethod* method) 
{
	{
		// ResizeIfNeed(size);
		int32_t L_0 = ___size0;
		NetDataWriter_ResizeIfNeed_mC1A12154624528056AA89E4B791727615D27D9A5_inline(__this, L_0, NULL);
		// _position = 0;
		__this->____position_1 = 0;
		// }
		return;
	}
}
// System.Void LiteNetLib.Utils.NetDataWriter::Reset()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NetDataWriter_Reset_mDEA01FDD070287963708A3AAC4BA892F331E640F (NetDataWriter_t5AE108AEC4825ED3FB45AA93565703368228EB37* __this, const RuntimeMethod* method) 
{
	{
		// _position = 0;
		__this->____position_1 = 0;
		// }
		return;
	}
}
// System.Byte[] LiteNetLib.Utils.NetDataWriter::CopyData()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* NetDataWriter_CopyData_m15A5E3A89F4531B33F87437EA65AF9BEB61BB15A (NetDataWriter_t5AE108AEC4825ED3FB45AA93565703368228EB37* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* V_0 = NULL;
	{
		// byte[] resultData = new byte[_position];
		int32_t L_0 = __this->____position_1;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_1 = (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)SZArrayNew(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var, (uint32_t)L_0);
		V_0 = L_1;
		// Buffer.BlockCopy(_data, 0, resultData, 0, _position);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_2 = __this->____data_0;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_3 = V_0;
		int32_t L_4 = __this->____position_1;
		Buffer_BlockCopy_mD8CF7EC96ADA7A542CCA3F3C73510624E10197A9((RuntimeArray*)L_2, 0, (RuntimeArray*)L_3, 0, L_4, NULL);
		// return resultData;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_5 = V_0;
		return L_5;
	}
}
// System.Int32 LiteNetLib.Utils.NetDataWriter::SetPosition(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t NetDataWriter_SetPosition_m7D55B976D3EF961276AB831C041F8E9C91C462E4 (NetDataWriter_t5AE108AEC4825ED3FB45AA93565703368228EB37* __this, int32_t ___position0, const RuntimeMethod* method) 
{
	{
		// int prevPosition = _position;
		int32_t L_0 = __this->____position_1;
		// _position = position;
		int32_t L_1 = ___position0;
		__this->____position_1 = L_1;
		// return prevPosition;
		return L_0;
	}
}
// System.Void LiteNetLib.Utils.NetDataWriter::Put(System.Single)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NetDataWriter_Put_m06776CCC136DB9EC336A398DFBA6DFCE53B48140 (NetDataWriter_t5AE108AEC4825ED3FB45AA93565703368228EB37* __this, float ___value0, const RuntimeMethod* method) 
{
	{
		// if (_autoResize)
		bool L_0 = __this->____autoResize_3;
		if (!L_0)
		{
			goto IL_0016;
		}
	}
	{
		// ResizeIfNeed(_position + 4);
		int32_t L_1 = __this->____position_1;
		NetDataWriter_ResizeIfNeed_mC1A12154624528056AA89E4B791727615D27D9A5_inline(__this, ((int32_t)il2cpp_codegen_add(L_1, 4)), NULL);
	}

IL_0016:
	{
		// FastBitConverter.GetBytes(_data, _position, value);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_2 = __this->____data_0;
		int32_t L_3 = __this->____position_1;
		float L_4 = ___value0;
		FastBitConverter_GetBytes_m5098DCCC8484C2205A958CBAFE694B1DB9EABEDF_inline(L_2, L_3, L_4, NULL);
		// _position += 4;
		int32_t L_5 = __this->____position_1;
		__this->____position_1 = ((int32_t)il2cpp_codegen_add(L_5, 4));
		// }
		return;
	}
}
// System.Void LiteNetLib.Utils.NetDataWriter::Put(System.Double)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NetDataWriter_Put_mF0E6467135EA862A3692A53E596B9D04633FD420 (NetDataWriter_t5AE108AEC4825ED3FB45AA93565703368228EB37* __this, double ___value0, const RuntimeMethod* method) 
{
	{
		// if (_autoResize)
		bool L_0 = __this->____autoResize_3;
		if (!L_0)
		{
			goto IL_0016;
		}
	}
	{
		// ResizeIfNeed(_position + 8);
		int32_t L_1 = __this->____position_1;
		NetDataWriter_ResizeIfNeed_mC1A12154624528056AA89E4B791727615D27D9A5_inline(__this, ((int32_t)il2cpp_codegen_add(L_1, 8)), NULL);
	}

IL_0016:
	{
		// FastBitConverter.GetBytes(_data, _position, value);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_2 = __this->____data_0;
		int32_t L_3 = __this->____position_1;
		double L_4 = ___value0;
		FastBitConverter_GetBytes_m70B89BF0E1D92548FF494E5E751A0CFA4231B2C0_inline(L_2, L_3, L_4, NULL);
		// _position += 8;
		int32_t L_5 = __this->____position_1;
		__this->____position_1 = ((int32_t)il2cpp_codegen_add(L_5, 8));
		// }
		return;
	}
}
// System.Void LiteNetLib.Utils.NetDataWriter::Put(System.Int64)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NetDataWriter_Put_m8CFC86A2E2FB50624EEB3654565FDCA5408FB920 (NetDataWriter_t5AE108AEC4825ED3FB45AA93565703368228EB37* __this, int64_t ___value0, const RuntimeMethod* method) 
{
	{
		// if (_autoResize)
		bool L_0 = __this->____autoResize_3;
		if (!L_0)
		{
			goto IL_0016;
		}
	}
	{
		// ResizeIfNeed(_position + 8);
		int32_t L_1 = __this->____position_1;
		NetDataWriter_ResizeIfNeed_mC1A12154624528056AA89E4B791727615D27D9A5_inline(__this, ((int32_t)il2cpp_codegen_add(L_1, 8)), NULL);
	}

IL_0016:
	{
		// FastBitConverter.GetBytes(_data, _position, value);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_2 = __this->____data_0;
		int32_t L_3 = __this->____position_1;
		int64_t L_4 = ___value0;
		FastBitConverter_GetBytes_m4623FFD1516846C025379E4B184E917E45B1EEB1_inline(L_2, L_3, L_4, NULL);
		// _position += 8;
		int32_t L_5 = __this->____position_1;
		__this->____position_1 = ((int32_t)il2cpp_codegen_add(L_5, 8));
		// }
		return;
	}
}
// System.Void LiteNetLib.Utils.NetDataWriter::Put(System.UInt64)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NetDataWriter_Put_m23E1ADCBDC3CCF01B54E9D3BF424BF0A38F531E7 (NetDataWriter_t5AE108AEC4825ED3FB45AA93565703368228EB37* __this, uint64_t ___value0, const RuntimeMethod* method) 
{
	{
		// if (_autoResize)
		bool L_0 = __this->____autoResize_3;
		if (!L_0)
		{
			goto IL_0016;
		}
	}
	{
		// ResizeIfNeed(_position + 8);
		int32_t L_1 = __this->____position_1;
		NetDataWriter_ResizeIfNeed_mC1A12154624528056AA89E4B791727615D27D9A5_inline(__this, ((int32_t)il2cpp_codegen_add(L_1, 8)), NULL);
	}

IL_0016:
	{
		// FastBitConverter.GetBytes(_data, _position, value);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_2 = __this->____data_0;
		int32_t L_3 = __this->____position_1;
		uint64_t L_4 = ___value0;
		FastBitConverter_GetBytes_m3AB77751A0F1D6246D7AC61C8EC6CE7AC7B0D203_inline(L_2, L_3, L_4, NULL);
		// _position += 8;
		int32_t L_5 = __this->____position_1;
		__this->____position_1 = ((int32_t)il2cpp_codegen_add(L_5, 8));
		// }
		return;
	}
}
// System.Void LiteNetLib.Utils.NetDataWriter::Put(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NetDataWriter_Put_m2F26BB86FF421E370E72E34145DE801E15DC5603 (NetDataWriter_t5AE108AEC4825ED3FB45AA93565703368228EB37* __this, int32_t ___value0, const RuntimeMethod* method) 
{
	{
		// if (_autoResize)
		bool L_0 = __this->____autoResize_3;
		if (!L_0)
		{
			goto IL_0016;
		}
	}
	{
		// ResizeIfNeed(_position + 4);
		int32_t L_1 = __this->____position_1;
		NetDataWriter_ResizeIfNeed_mC1A12154624528056AA89E4B791727615D27D9A5_inline(__this, ((int32_t)il2cpp_codegen_add(L_1, 4)), NULL);
	}

IL_0016:
	{
		// FastBitConverter.GetBytes(_data, _position, value);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_2 = __this->____data_0;
		int32_t L_3 = __this->____position_1;
		int32_t L_4 = ___value0;
		FastBitConverter_GetBytes_m6815D55E22E42D242F5C31826AE4FDAB91F6CB6C_inline(L_2, L_3, L_4, NULL);
		// _position += 4;
		int32_t L_5 = __this->____position_1;
		__this->____position_1 = ((int32_t)il2cpp_codegen_add(L_5, 4));
		// }
		return;
	}
}
// System.Void LiteNetLib.Utils.NetDataWriter::Put(System.UInt32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NetDataWriter_Put_mCEDC11B8C976D0275173CCF1BE5FA417C9D6046B (NetDataWriter_t5AE108AEC4825ED3FB45AA93565703368228EB37* __this, uint32_t ___value0, const RuntimeMethod* method) 
{
	{
		// if (_autoResize)
		bool L_0 = __this->____autoResize_3;
		if (!L_0)
		{
			goto IL_0016;
		}
	}
	{
		// ResizeIfNeed(_position + 4);
		int32_t L_1 = __this->____position_1;
		NetDataWriter_ResizeIfNeed_mC1A12154624528056AA89E4B791727615D27D9A5_inline(__this, ((int32_t)il2cpp_codegen_add(L_1, 4)), NULL);
	}

IL_0016:
	{
		// FastBitConverter.GetBytes(_data, _position, value);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_2 = __this->____data_0;
		int32_t L_3 = __this->____position_1;
		uint32_t L_4 = ___value0;
		FastBitConverter_GetBytes_m59C97C6CD1243787969924BFAE61424CE82DA806_inline(L_2, L_3, L_4, NULL);
		// _position += 4;
		int32_t L_5 = __this->____position_1;
		__this->____position_1 = ((int32_t)il2cpp_codegen_add(L_5, 4));
		// }
		return;
	}
}
// System.Void LiteNetLib.Utils.NetDataWriter::Put(System.Char)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NetDataWriter_Put_m635D71BA5A6D4EA18890399A3C5F66067459E427 (NetDataWriter_t5AE108AEC4825ED3FB45AA93565703368228EB37* __this, Il2CppChar ___value0, const RuntimeMethod* method) 
{
	{
		// Put((ushort)value);
		Il2CppChar L_0 = ___value0;
		NetDataWriter_Put_m8AA9410DD0C00EB7BC6E8493298A98B0C69B917E(__this, L_0, NULL);
		// }
		return;
	}
}
// System.Void LiteNetLib.Utils.NetDataWriter::Put(System.UInt16)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NetDataWriter_Put_m8AA9410DD0C00EB7BC6E8493298A98B0C69B917E (NetDataWriter_t5AE108AEC4825ED3FB45AA93565703368228EB37* __this, uint16_t ___value0, const RuntimeMethod* method) 
{
	{
		// if (_autoResize)
		bool L_0 = __this->____autoResize_3;
		if (!L_0)
		{
			goto IL_0016;
		}
	}
	{
		// ResizeIfNeed(_position + 2);
		int32_t L_1 = __this->____position_1;
		NetDataWriter_ResizeIfNeed_mC1A12154624528056AA89E4B791727615D27D9A5_inline(__this, ((int32_t)il2cpp_codegen_add(L_1, 2)), NULL);
	}

IL_0016:
	{
		// FastBitConverter.GetBytes(_data, _position, value);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_2 = __this->____data_0;
		int32_t L_3 = __this->____position_1;
		uint16_t L_4 = ___value0;
		FastBitConverter_GetBytes_m447B17AD55B29DE95E6B761770D1A648BF953382_inline(L_2, L_3, L_4, NULL);
		// _position += 2;
		int32_t L_5 = __this->____position_1;
		__this->____position_1 = ((int32_t)il2cpp_codegen_add(L_5, 2));
		// }
		return;
	}
}
// System.Void LiteNetLib.Utils.NetDataWriter::Put(System.Int16)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NetDataWriter_Put_mEEA5B5DC6D4B02A2038894A48C8442DF2745148B (NetDataWriter_t5AE108AEC4825ED3FB45AA93565703368228EB37* __this, int16_t ___value0, const RuntimeMethod* method) 
{
	{
		// if (_autoResize)
		bool L_0 = __this->____autoResize_3;
		if (!L_0)
		{
			goto IL_0016;
		}
	}
	{
		// ResizeIfNeed(_position + 2);
		int32_t L_1 = __this->____position_1;
		NetDataWriter_ResizeIfNeed_mC1A12154624528056AA89E4B791727615D27D9A5_inline(__this, ((int32_t)il2cpp_codegen_add(L_1, 2)), NULL);
	}

IL_0016:
	{
		// FastBitConverter.GetBytes(_data, _position, value);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_2 = __this->____data_0;
		int32_t L_3 = __this->____position_1;
		int16_t L_4 = ___value0;
		FastBitConverter_GetBytes_m51BB8E43416F790D6ACD5FD3F5AB477568FDFBB2_inline(L_2, L_3, L_4, NULL);
		// _position += 2;
		int32_t L_5 = __this->____position_1;
		__this->____position_1 = ((int32_t)il2cpp_codegen_add(L_5, 2));
		// }
		return;
	}
}
// System.Void LiteNetLib.Utils.NetDataWriter::Put(System.SByte)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NetDataWriter_Put_m6A1085C3CE48C66051B74A25794D0C7033136164 (NetDataWriter_t5AE108AEC4825ED3FB45AA93565703368228EB37* __this, int8_t ___value0, const RuntimeMethod* method) 
{
	{
		// if (_autoResize)
		bool L_0 = __this->____autoResize_3;
		if (!L_0)
		{
			goto IL_0016;
		}
	}
	{
		// ResizeIfNeed(_position + 1);
		int32_t L_1 = __this->____position_1;
		NetDataWriter_ResizeIfNeed_mC1A12154624528056AA89E4B791727615D27D9A5_inline(__this, ((int32_t)il2cpp_codegen_add(L_1, 1)), NULL);
	}

IL_0016:
	{
		// _data[_position] = (byte)value;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_2 = __this->____data_0;
		int32_t L_3 = __this->____position_1;
		int8_t L_4 = ___value0;
		NullCheck(L_2);
		(L_2)->SetAt(static_cast<il2cpp_array_size_t>(L_3), (uint8_t)((int32_t)(uint8_t)L_4));
		// _position++;
		int32_t L_5 = __this->____position_1;
		__this->____position_1 = ((int32_t)il2cpp_codegen_add(L_5, 1));
		// }
		return;
	}
}
// System.Void LiteNetLib.Utils.NetDataWriter::Put(System.Byte)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NetDataWriter_Put_m04CE888E8D3551B7E85403CEC1F0579368BA5C54 (NetDataWriter_t5AE108AEC4825ED3FB45AA93565703368228EB37* __this, uint8_t ___value0, const RuntimeMethod* method) 
{
	{
		// if (_autoResize)
		bool L_0 = __this->____autoResize_3;
		if (!L_0)
		{
			goto IL_0016;
		}
	}
	{
		// ResizeIfNeed(_position + 1);
		int32_t L_1 = __this->____position_1;
		NetDataWriter_ResizeIfNeed_mC1A12154624528056AA89E4B791727615D27D9A5_inline(__this, ((int32_t)il2cpp_codegen_add(L_1, 1)), NULL);
	}

IL_0016:
	{
		// _data[_position] = value;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_2 = __this->____data_0;
		int32_t L_3 = __this->____position_1;
		uint8_t L_4 = ___value0;
		NullCheck(L_2);
		(L_2)->SetAt(static_cast<il2cpp_array_size_t>(L_3), (uint8_t)L_4);
		// _position++;
		int32_t L_5 = __this->____position_1;
		__this->____position_1 = ((int32_t)il2cpp_codegen_add(L_5, 1));
		// }
		return;
	}
}
// System.Void LiteNetLib.Utils.NetDataWriter::Put(System.Byte[],System.Int32,System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NetDataWriter_Put_mEE909D6E69A8733E062C5DB68417A58D1E4FF3B9 (NetDataWriter_t5AE108AEC4825ED3FB45AA93565703368228EB37* __this, ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___data0, int32_t ___offset1, int32_t ___length2, const RuntimeMethod* method) 
{
	{
		// if (_autoResize)
		bool L_0 = __this->____autoResize_3;
		if (!L_0)
		{
			goto IL_0016;
		}
	}
	{
		// ResizeIfNeed(_position + length);
		int32_t L_1 = __this->____position_1;
		int32_t L_2 = ___length2;
		NetDataWriter_ResizeIfNeed_mC1A12154624528056AA89E4B791727615D27D9A5_inline(__this, ((int32_t)il2cpp_codegen_add(L_1, L_2)), NULL);
	}

IL_0016:
	{
		// Buffer.BlockCopy(data, offset, _data, _position, length);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_3 = ___data0;
		int32_t L_4 = ___offset1;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_5 = __this->____data_0;
		int32_t L_6 = __this->____position_1;
		int32_t L_7 = ___length2;
		Buffer_BlockCopy_mD8CF7EC96ADA7A542CCA3F3C73510624E10197A9((RuntimeArray*)L_3, L_4, (RuntimeArray*)L_5, L_6, L_7, NULL);
		// _position += length;
		int32_t L_8 = __this->____position_1;
		int32_t L_9 = ___length2;
		__this->____position_1 = ((int32_t)il2cpp_codegen_add(L_8, L_9));
		// }
		return;
	}
}
// System.Void LiteNetLib.Utils.NetDataWriter::Put(System.Byte[])
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NetDataWriter_Put_m6620926E0379435BC731C6CF1D8A0F2B1FFAD8E8 (NetDataWriter_t5AE108AEC4825ED3FB45AA93565703368228EB37* __this, ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___data0, const RuntimeMethod* method) 
{
	{
		// if (_autoResize)
		bool L_0 = __this->____autoResize_3;
		if (!L_0)
		{
			goto IL_0018;
		}
	}
	{
		// ResizeIfNeed(_position + data.Length);
		int32_t L_1 = __this->____position_1;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_2 = ___data0;
		NullCheck(L_2);
		NetDataWriter_ResizeIfNeed_mC1A12154624528056AA89E4B791727615D27D9A5_inline(__this, ((int32_t)il2cpp_codegen_add(L_1, ((int32_t)(((RuntimeArray*)L_2)->max_length)))), NULL);
	}

IL_0018:
	{
		// Buffer.BlockCopy(data, 0, _data, _position, data.Length);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_3 = ___data0;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_4 = __this->____data_0;
		int32_t L_5 = __this->____position_1;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_6 = ___data0;
		NullCheck(L_6);
		Buffer_BlockCopy_mD8CF7EC96ADA7A542CCA3F3C73510624E10197A9((RuntimeArray*)L_3, 0, (RuntimeArray*)L_4, L_5, ((int32_t)(((RuntimeArray*)L_6)->max_length)), NULL);
		// _position += data.Length;
		int32_t L_7 = __this->____position_1;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_8 = ___data0;
		NullCheck(L_8);
		__this->____position_1 = ((int32_t)il2cpp_codegen_add(L_7, ((int32_t)(((RuntimeArray*)L_8)->max_length))));
		// }
		return;
	}
}
// System.Void LiteNetLib.Utils.NetDataWriter::PutSBytesWithLength(System.SByte[],System.Int32,System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NetDataWriter_PutSBytesWithLength_m46C1E86B41A1FC05CF5ACD27C9521BC9C03D7A57 (NetDataWriter_t5AE108AEC4825ED3FB45AA93565703368228EB37* __this, SByteU5BU5D_t88116DA68378C3333DB73E7D36C1A06AFAA91913* ___data0, int32_t ___offset1, int32_t ___length2, const RuntimeMethod* method) 
{
	{
		// if (_autoResize)
		bool L_0 = __this->____autoResize_3;
		if (!L_0)
		{
			goto IL_0018;
		}
	}
	{
		// ResizeIfNeed(_position + length + 4);
		int32_t L_1 = __this->____position_1;
		int32_t L_2 = ___length2;
		NetDataWriter_ResizeIfNeed_mC1A12154624528056AA89E4B791727615D27D9A5_inline(__this, ((int32_t)il2cpp_codegen_add(((int32_t)il2cpp_codegen_add(L_1, L_2)), 4)), NULL);
	}

IL_0018:
	{
		// FastBitConverter.GetBytes(_data, _position, length);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_3 = __this->____data_0;
		int32_t L_4 = __this->____position_1;
		int32_t L_5 = ___length2;
		FastBitConverter_GetBytes_m6815D55E22E42D242F5C31826AE4FDAB91F6CB6C_inline(L_3, L_4, L_5, NULL);
		// Buffer.BlockCopy(data, offset, _data, _position + 4, length);
		SByteU5BU5D_t88116DA68378C3333DB73E7D36C1A06AFAA91913* L_6 = ___data0;
		int32_t L_7 = ___offset1;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_8 = __this->____data_0;
		int32_t L_9 = __this->____position_1;
		int32_t L_10 = ___length2;
		Buffer_BlockCopy_mD8CF7EC96ADA7A542CCA3F3C73510624E10197A9((RuntimeArray*)L_6, L_7, (RuntimeArray*)L_8, ((int32_t)il2cpp_codegen_add(L_9, 4)), L_10, NULL);
		// _position += length + 4;
		int32_t L_11 = __this->____position_1;
		int32_t L_12 = ___length2;
		__this->____position_1 = ((int32_t)il2cpp_codegen_add(L_11, ((int32_t)il2cpp_codegen_add(L_12, 4))));
		// }
		return;
	}
}
// System.Void LiteNetLib.Utils.NetDataWriter::PutSBytesWithLength(System.SByte[])
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NetDataWriter_PutSBytesWithLength_m6F177D66792EC63ECF9B14DD74DF5707B05FC56A (NetDataWriter_t5AE108AEC4825ED3FB45AA93565703368228EB37* __this, SByteU5BU5D_t88116DA68378C3333DB73E7D36C1A06AFAA91913* ___data0, const RuntimeMethod* method) 
{
	{
		// if (_autoResize)
		bool L_0 = __this->____autoResize_3;
		if (!L_0)
		{
			goto IL_001a;
		}
	}
	{
		// ResizeIfNeed(_position + data.Length + 4);
		int32_t L_1 = __this->____position_1;
		SByteU5BU5D_t88116DA68378C3333DB73E7D36C1A06AFAA91913* L_2 = ___data0;
		NullCheck(L_2);
		NetDataWriter_ResizeIfNeed_mC1A12154624528056AA89E4B791727615D27D9A5_inline(__this, ((int32_t)il2cpp_codegen_add(((int32_t)il2cpp_codegen_add(L_1, ((int32_t)(((RuntimeArray*)L_2)->max_length)))), 4)), NULL);
	}

IL_001a:
	{
		// FastBitConverter.GetBytes(_data, _position, data.Length);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_3 = __this->____data_0;
		int32_t L_4 = __this->____position_1;
		SByteU5BU5D_t88116DA68378C3333DB73E7D36C1A06AFAA91913* L_5 = ___data0;
		NullCheck(L_5);
		FastBitConverter_GetBytes_m6815D55E22E42D242F5C31826AE4FDAB91F6CB6C_inline(L_3, L_4, ((int32_t)(((RuntimeArray*)L_5)->max_length)), NULL);
		// Buffer.BlockCopy(data, 0, _data, _position + 4, data.Length);
		SByteU5BU5D_t88116DA68378C3333DB73E7D36C1A06AFAA91913* L_6 = ___data0;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_7 = __this->____data_0;
		int32_t L_8 = __this->____position_1;
		SByteU5BU5D_t88116DA68378C3333DB73E7D36C1A06AFAA91913* L_9 = ___data0;
		NullCheck(L_9);
		Buffer_BlockCopy_mD8CF7EC96ADA7A542CCA3F3C73510624E10197A9((RuntimeArray*)L_6, 0, (RuntimeArray*)L_7, ((int32_t)il2cpp_codegen_add(L_8, 4)), ((int32_t)(((RuntimeArray*)L_9)->max_length)), NULL);
		// _position += data.Length + 4;
		int32_t L_10 = __this->____position_1;
		SByteU5BU5D_t88116DA68378C3333DB73E7D36C1A06AFAA91913* L_11 = ___data0;
		NullCheck(L_11);
		__this->____position_1 = ((int32_t)il2cpp_codegen_add(L_10, ((int32_t)il2cpp_codegen_add(((int32_t)(((RuntimeArray*)L_11)->max_length)), 4))));
		// }
		return;
	}
}
// System.Void LiteNetLib.Utils.NetDataWriter::PutBytesWithLength(System.Byte[],System.Int32,System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NetDataWriter_PutBytesWithLength_m00D8709909BAA3B1EEF2DD80A5B3C4C7DA66ACB6 (NetDataWriter_t5AE108AEC4825ED3FB45AA93565703368228EB37* __this, ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___data0, int32_t ___offset1, int32_t ___length2, const RuntimeMethod* method) 
{
	{
		// if (_autoResize)
		bool L_0 = __this->____autoResize_3;
		if (!L_0)
		{
			goto IL_0018;
		}
	}
	{
		// ResizeIfNeed(_position + length + 4);
		int32_t L_1 = __this->____position_1;
		int32_t L_2 = ___length2;
		NetDataWriter_ResizeIfNeed_mC1A12154624528056AA89E4B791727615D27D9A5_inline(__this, ((int32_t)il2cpp_codegen_add(((int32_t)il2cpp_codegen_add(L_1, L_2)), 4)), NULL);
	}

IL_0018:
	{
		// FastBitConverter.GetBytes(_data, _position, length);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_3 = __this->____data_0;
		int32_t L_4 = __this->____position_1;
		int32_t L_5 = ___length2;
		FastBitConverter_GetBytes_m6815D55E22E42D242F5C31826AE4FDAB91F6CB6C_inline(L_3, L_4, L_5, NULL);
		// Buffer.BlockCopy(data, offset, _data, _position + 4, length);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_6 = ___data0;
		int32_t L_7 = ___offset1;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_8 = __this->____data_0;
		int32_t L_9 = __this->____position_1;
		int32_t L_10 = ___length2;
		Buffer_BlockCopy_mD8CF7EC96ADA7A542CCA3F3C73510624E10197A9((RuntimeArray*)L_6, L_7, (RuntimeArray*)L_8, ((int32_t)il2cpp_codegen_add(L_9, 4)), L_10, NULL);
		// _position += length + 4;
		int32_t L_11 = __this->____position_1;
		int32_t L_12 = ___length2;
		__this->____position_1 = ((int32_t)il2cpp_codegen_add(L_11, ((int32_t)il2cpp_codegen_add(L_12, 4))));
		// }
		return;
	}
}
// System.Void LiteNetLib.Utils.NetDataWriter::PutBytesWithLength(System.Byte[])
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NetDataWriter_PutBytesWithLength_mDA4CE03ED587D15FE8D81B95B8FEADAD7C6ABD7A (NetDataWriter_t5AE108AEC4825ED3FB45AA93565703368228EB37* __this, ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___data0, const RuntimeMethod* method) 
{
	{
		// if (_autoResize)
		bool L_0 = __this->____autoResize_3;
		if (!L_0)
		{
			goto IL_001a;
		}
	}
	{
		// ResizeIfNeed(_position + data.Length + 4);
		int32_t L_1 = __this->____position_1;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_2 = ___data0;
		NullCheck(L_2);
		NetDataWriter_ResizeIfNeed_mC1A12154624528056AA89E4B791727615D27D9A5_inline(__this, ((int32_t)il2cpp_codegen_add(((int32_t)il2cpp_codegen_add(L_1, ((int32_t)(((RuntimeArray*)L_2)->max_length)))), 4)), NULL);
	}

IL_001a:
	{
		// FastBitConverter.GetBytes(_data, _position, data.Length);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_3 = __this->____data_0;
		int32_t L_4 = __this->____position_1;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_5 = ___data0;
		NullCheck(L_5);
		FastBitConverter_GetBytes_m6815D55E22E42D242F5C31826AE4FDAB91F6CB6C_inline(L_3, L_4, ((int32_t)(((RuntimeArray*)L_5)->max_length)), NULL);
		// Buffer.BlockCopy(data, 0, _data, _position + 4, data.Length);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_6 = ___data0;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_7 = __this->____data_0;
		int32_t L_8 = __this->____position_1;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_9 = ___data0;
		NullCheck(L_9);
		Buffer_BlockCopy_mD8CF7EC96ADA7A542CCA3F3C73510624E10197A9((RuntimeArray*)L_6, 0, (RuntimeArray*)L_7, ((int32_t)il2cpp_codegen_add(L_8, 4)), ((int32_t)(((RuntimeArray*)L_9)->max_length)), NULL);
		// _position += data.Length + 4;
		int32_t L_10 = __this->____position_1;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_11 = ___data0;
		NullCheck(L_11);
		__this->____position_1 = ((int32_t)il2cpp_codegen_add(L_10, ((int32_t)il2cpp_codegen_add(((int32_t)(((RuntimeArray*)L_11)->max_length)), 4))));
		// }
		return;
	}
}
// System.Void LiteNetLib.Utils.NetDataWriter::Put(System.Boolean)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NetDataWriter_Put_m58996BA019FF628A93F88A692D29B5A4E127D4CD (NetDataWriter_t5AE108AEC4825ED3FB45AA93565703368228EB37* __this, bool ___value0, const RuntimeMethod* method) 
{
	NetDataWriter_t5AE108AEC4825ED3FB45AA93565703368228EB37* G_B2_0 = NULL;
	NetDataWriter_t5AE108AEC4825ED3FB45AA93565703368228EB37* G_B1_0 = NULL;
	int32_t G_B3_0 = 0;
	NetDataWriter_t5AE108AEC4825ED3FB45AA93565703368228EB37* G_B3_1 = NULL;
	{
		// Put((byte)(value ? 1 : 0));
		bool L_0 = ___value0;
		G_B1_0 = __this;
		if (L_0)
		{
			G_B2_0 = __this;
			goto IL_0007;
		}
	}
	{
		G_B3_0 = 0;
		G_B3_1 = G_B1_0;
		goto IL_0008;
	}

IL_0007:
	{
		G_B3_0 = 1;
		G_B3_1 = G_B2_0;
	}

IL_0008:
	{
		NullCheck(G_B3_1);
		NetDataWriter_Put_m04CE888E8D3551B7E85403CEC1F0579368BA5C54(G_B3_1, (uint8_t)((int32_t)(uint8_t)G_B3_0), NULL);
		// }
		return;
	}
}
// System.Void LiteNetLib.Utils.NetDataWriter::PutArray(System.Array,System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NetDataWriter_PutArray_m706C91C3087F6FB84A527B0BC46366B42E2E26A9 (NetDataWriter_t5AE108AEC4825ED3FB45AA93565703368228EB37* __this, RuntimeArray* ___arr0, int32_t ___sz1, const RuntimeMethod* method) 
{
	uint16_t V_0 = 0;
	int32_t G_B3_0 = 0;
	{
		// ushort length = arr == null ? (ushort) 0 : (ushort)arr.Length;
		RuntimeArray* L_0 = ___arr0;
		if (!L_0)
		{
			goto IL_000c;
		}
	}
	{
		RuntimeArray* L_1 = ___arr0;
		NullCheck(L_1);
		int32_t L_2;
		L_2 = Array_get_Length_m361285FB7CF44045DC369834D1CD01F72F94EF57(L_1, NULL);
		G_B3_0 = ((int32_t)(uint16_t)L_2);
		goto IL_000d;
	}

IL_000c:
	{
		G_B3_0 = 0;
	}

IL_000d:
	{
		V_0 = (uint16_t)G_B3_0;
		// sz *= length;
		int32_t L_3 = ___sz1;
		uint16_t L_4 = V_0;
		___sz1 = ((int32_t)il2cpp_codegen_multiply(L_3, (int32_t)L_4));
		// if (_autoResize)
		bool L_5 = __this->____autoResize_3;
		if (!L_5)
		{
			goto IL_002b;
		}
	}
	{
		// ResizeIfNeed(_position + sz + 2);
		int32_t L_6 = __this->____position_1;
		int32_t L_7 = ___sz1;
		NetDataWriter_ResizeIfNeed_mC1A12154624528056AA89E4B791727615D27D9A5_inline(__this, ((int32_t)il2cpp_codegen_add(((int32_t)il2cpp_codegen_add(L_6, L_7)), 2)), NULL);
	}

IL_002b:
	{
		// FastBitConverter.GetBytes(_data, _position, length);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_8 = __this->____data_0;
		int32_t L_9 = __this->____position_1;
		uint16_t L_10 = V_0;
		FastBitConverter_GetBytes_m447B17AD55B29DE95E6B761770D1A648BF953382_inline(L_8, L_9, L_10, NULL);
		// if (arr != null)
		RuntimeArray* L_11 = ___arr0;
		if (!L_11)
		{
			goto IL_0056;
		}
	}
	{
		// Buffer.BlockCopy(arr, 0, _data, _position + 2, sz);
		RuntimeArray* L_12 = ___arr0;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_13 = __this->____data_0;
		int32_t L_14 = __this->____position_1;
		int32_t L_15 = ___sz1;
		Buffer_BlockCopy_mD8CF7EC96ADA7A542CCA3F3C73510624E10197A9(L_12, 0, (RuntimeArray*)L_13, ((int32_t)il2cpp_codegen_add(L_14, 2)), L_15, NULL);
	}

IL_0056:
	{
		// _position += sz + 2;
		int32_t L_16 = __this->____position_1;
		int32_t L_17 = ___sz1;
		__this->____position_1 = ((int32_t)il2cpp_codegen_add(L_16, ((int32_t)il2cpp_codegen_add(L_17, 2))));
		// }
		return;
	}
}
// System.Void LiteNetLib.Utils.NetDataWriter::PutArray(System.Single[])
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NetDataWriter_PutArray_m9462FC83BCAAF46051223086E66B1078DF7E7000 (NetDataWriter_t5AE108AEC4825ED3FB45AA93565703368228EB37* __this, SingleU5BU5D_t89DEFE97BCEDB5857010E79ECE0F52CF6E93B87C* ___value0, const RuntimeMethod* method) 
{
	{
		// PutArray(value, 4);
		SingleU5BU5D_t89DEFE97BCEDB5857010E79ECE0F52CF6E93B87C* L_0 = ___value0;
		NetDataWriter_PutArray_m706C91C3087F6FB84A527B0BC46366B42E2E26A9(__this, (RuntimeArray*)L_0, 4, NULL);
		// }
		return;
	}
}
// System.Void LiteNetLib.Utils.NetDataWriter::PutArray(System.Double[])
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NetDataWriter_PutArray_mA97A5ED857B549141FF59335E7F9F94870D1EACA (NetDataWriter_t5AE108AEC4825ED3FB45AA93565703368228EB37* __this, DoubleU5BU5D_tCC308475BD3B8229DB2582938669EF2F9ECC1FEE* ___value0, const RuntimeMethod* method) 
{
	{
		// PutArray(value, 8);
		DoubleU5BU5D_tCC308475BD3B8229DB2582938669EF2F9ECC1FEE* L_0 = ___value0;
		NetDataWriter_PutArray_m706C91C3087F6FB84A527B0BC46366B42E2E26A9(__this, (RuntimeArray*)L_0, 8, NULL);
		// }
		return;
	}
}
// System.Void LiteNetLib.Utils.NetDataWriter::PutArray(System.Int64[])
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NetDataWriter_PutArray_mF8E3A677D5F070D8EC08EB77B2AB90F399E6948D (NetDataWriter_t5AE108AEC4825ED3FB45AA93565703368228EB37* __this, Int64U5BU5D_tAEDFCBDB5414E2A140A6F34C0538BF97FCF67A1D* ___value0, const RuntimeMethod* method) 
{
	{
		// PutArray(value, 8);
		Int64U5BU5D_tAEDFCBDB5414E2A140A6F34C0538BF97FCF67A1D* L_0 = ___value0;
		NetDataWriter_PutArray_m706C91C3087F6FB84A527B0BC46366B42E2E26A9(__this, (RuntimeArray*)L_0, 8, NULL);
		// }
		return;
	}
}
// System.Void LiteNetLib.Utils.NetDataWriter::PutArray(System.UInt64[])
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NetDataWriter_PutArray_mEDBD8165CC9B4A24511C5FD51B9D49C50F4F9062 (NetDataWriter_t5AE108AEC4825ED3FB45AA93565703368228EB37* __this, UInt64U5BU5D_tAB1A62450AC0899188486EDB9FC066B8BEED9299* ___value0, const RuntimeMethod* method) 
{
	{
		// PutArray(value, 8);
		UInt64U5BU5D_tAB1A62450AC0899188486EDB9FC066B8BEED9299* L_0 = ___value0;
		NetDataWriter_PutArray_m706C91C3087F6FB84A527B0BC46366B42E2E26A9(__this, (RuntimeArray*)L_0, 8, NULL);
		// }
		return;
	}
}
// System.Void LiteNetLib.Utils.NetDataWriter::PutArray(System.Int32[])
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NetDataWriter_PutArray_m379F5B2A23D4AD65B19B958718FB0A35EA8AE600 (NetDataWriter_t5AE108AEC4825ED3FB45AA93565703368228EB37* __this, Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___value0, const RuntimeMethod* method) 
{
	{
		// PutArray(value, 4);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_0 = ___value0;
		NetDataWriter_PutArray_m706C91C3087F6FB84A527B0BC46366B42E2E26A9(__this, (RuntimeArray*)L_0, 4, NULL);
		// }
		return;
	}
}
// System.Void LiteNetLib.Utils.NetDataWriter::PutArray(System.UInt32[])
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NetDataWriter_PutArray_m21ECC3270CD459CA5714DF45A32AF6B53EC084E9 (NetDataWriter_t5AE108AEC4825ED3FB45AA93565703368228EB37* __this, UInt32U5BU5D_t02FBD658AD156A17574ECE6106CF1FBFCC9807FA* ___value0, const RuntimeMethod* method) 
{
	{
		// PutArray(value, 4);
		UInt32U5BU5D_t02FBD658AD156A17574ECE6106CF1FBFCC9807FA* L_0 = ___value0;
		NetDataWriter_PutArray_m706C91C3087F6FB84A527B0BC46366B42E2E26A9(__this, (RuntimeArray*)L_0, 4, NULL);
		// }
		return;
	}
}
// System.Void LiteNetLib.Utils.NetDataWriter::PutArray(System.UInt16[])
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NetDataWriter_PutArray_mD33CF4433A313948805E2FD0CED8BF9DC4E58EB5 (NetDataWriter_t5AE108AEC4825ED3FB45AA93565703368228EB37* __this, UInt16U5BU5D_tEB7C42D811D999D2AA815BADC3FCCDD9C67B3F83* ___value0, const RuntimeMethod* method) 
{
	{
		// PutArray(value, 2);
		UInt16U5BU5D_tEB7C42D811D999D2AA815BADC3FCCDD9C67B3F83* L_0 = ___value0;
		NetDataWriter_PutArray_m706C91C3087F6FB84A527B0BC46366B42E2E26A9(__this, (RuntimeArray*)L_0, 2, NULL);
		// }
		return;
	}
}
// System.Void LiteNetLib.Utils.NetDataWriter::PutArray(System.Int16[])
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NetDataWriter_PutArray_mBDA1E96B36BA4D2C0EB70D2F0722AEA3E92B3307 (NetDataWriter_t5AE108AEC4825ED3FB45AA93565703368228EB37* __this, Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* ___value0, const RuntimeMethod* method) 
{
	{
		// PutArray(value, 2);
		Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* L_0 = ___value0;
		NetDataWriter_PutArray_m706C91C3087F6FB84A527B0BC46366B42E2E26A9(__this, (RuntimeArray*)L_0, 2, NULL);
		// }
		return;
	}
}
// System.Void LiteNetLib.Utils.NetDataWriter::PutArray(System.Boolean[])
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NetDataWriter_PutArray_m8BA9DABB64603E5F2C52A21CA33270D5D942C673 (NetDataWriter_t5AE108AEC4825ED3FB45AA93565703368228EB37* __this, BooleanU5BU5D_tD317D27C31DB892BE79FAE3AEBC0B3FFB73DE9B4* ___value0, const RuntimeMethod* method) 
{
	{
		// PutArray(value, 1);
		BooleanU5BU5D_tD317D27C31DB892BE79FAE3AEBC0B3FFB73DE9B4* L_0 = ___value0;
		NetDataWriter_PutArray_m706C91C3087F6FB84A527B0BC46366B42E2E26A9(__this, (RuntimeArray*)L_0, 1, NULL);
		// }
		return;
	}
}
// System.Void LiteNetLib.Utils.NetDataWriter::PutArray(System.String[])
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NetDataWriter_PutArray_m3FEEC25E53BE6D80B448AAC81D93946AF26A642C (NetDataWriter_t5AE108AEC4825ED3FB45AA93565703368228EB37* __this, StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* ___value0, const RuntimeMethod* method) 
{
	uint16_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t G_B3_0 = 0;
	{
		// ushort strArrayLength = value == null ? (ushort)0 : (ushort)value.Length;
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_0 = ___value0;
		if (!L_0)
		{
			goto IL_0009;
		}
	}
	{
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_1 = ___value0;
		NullCheck(L_1);
		G_B3_0 = ((int32_t)(uint16_t)((int32_t)(((RuntimeArray*)L_1)->max_length)));
		goto IL_000a;
	}

IL_0009:
	{
		G_B3_0 = 0;
	}

IL_000a:
	{
		V_0 = (uint16_t)G_B3_0;
		// Put(strArrayLength);
		uint16_t L_2 = V_0;
		NetDataWriter_Put_m8AA9410DD0C00EB7BC6E8493298A98B0C69B917E(__this, L_2, NULL);
		// for (int i = 0; i < strArrayLength; i++)
		V_1 = 0;
		goto IL_0023;
	}

IL_0016:
	{
		// Put(value[i]);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_3 = ___value0;
		int32_t L_4 = V_1;
		NullCheck(L_3);
		int32_t L_5 = L_4;
		String_t* L_6 = (L_3)->GetAt(static_cast<il2cpp_array_size_t>(L_5));
		NetDataWriter_Put_m40A032F477E6C5A55E526FF9D8CF668DC018FB63(__this, L_6, NULL);
		// for (int i = 0; i < strArrayLength; i++)
		int32_t L_7 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_7, 1));
	}

IL_0023:
	{
		// for (int i = 0; i < strArrayLength; i++)
		int32_t L_8 = V_1;
		uint16_t L_9 = V_0;
		if ((((int32_t)L_8) < ((int32_t)L_9)))
		{
			goto IL_0016;
		}
	}
	{
		// }
		return;
	}
}
// System.Void LiteNetLib.Utils.NetDataWriter::PutArray(System.String[],System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NetDataWriter_PutArray_m6DB8CBFCCE83D5DE17D76385960FD433E073C379 (NetDataWriter_t5AE108AEC4825ED3FB45AA93565703368228EB37* __this, StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* ___value0, int32_t ___strMaxLength1, const RuntimeMethod* method) 
{
	uint16_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t G_B3_0 = 0;
	{
		// ushort strArrayLength = value == null ? (ushort)0 : (ushort)value.Length;
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_0 = ___value0;
		if (!L_0)
		{
			goto IL_0009;
		}
	}
	{
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_1 = ___value0;
		NullCheck(L_1);
		G_B3_0 = ((int32_t)(uint16_t)((int32_t)(((RuntimeArray*)L_1)->max_length)));
		goto IL_000a;
	}

IL_0009:
	{
		G_B3_0 = 0;
	}

IL_000a:
	{
		V_0 = (uint16_t)G_B3_0;
		// Put(strArrayLength);
		uint16_t L_2 = V_0;
		NetDataWriter_Put_m8AA9410DD0C00EB7BC6E8493298A98B0C69B917E(__this, L_2, NULL);
		// for (int i = 0; i < strArrayLength; i++)
		V_1 = 0;
		goto IL_0024;
	}

IL_0016:
	{
		// Put(value[i], strMaxLength);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_3 = ___value0;
		int32_t L_4 = V_1;
		NullCheck(L_3);
		int32_t L_5 = L_4;
		String_t* L_6 = (L_3)->GetAt(static_cast<il2cpp_array_size_t>(L_5));
		int32_t L_7 = ___strMaxLength1;
		NetDataWriter_Put_m81B08D1F055A09468E4DE6D60F7A28F12AD56B77(__this, L_6, L_7, NULL);
		// for (int i = 0; i < strArrayLength; i++)
		int32_t L_8 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_8, 1));
	}

IL_0024:
	{
		// for (int i = 0; i < strArrayLength; i++)
		int32_t L_9 = V_1;
		uint16_t L_10 = V_0;
		if ((((int32_t)L_9) < ((int32_t)L_10)))
		{
			goto IL_0016;
		}
	}
	{
		// }
		return;
	}
}
// System.Void LiteNetLib.Utils.NetDataWriter::Put(System.Net.IPEndPoint)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NetDataWriter_Put_mEB46156ACA5D3526A67AD9BE579B009AF4E95432 (NetDataWriter_t5AE108AEC4825ED3FB45AA93565703368228EB37* __this, IPEndPoint_t2F09CBA7A808B67724B4E2954EEDC46D910F4ECB* ___endPoint0, const RuntimeMethod* method) 
{
	{
		// Put(endPoint.Address.ToString());
		IPEndPoint_t2F09CBA7A808B67724B4E2954EEDC46D910F4ECB* L_0 = ___endPoint0;
		NullCheck(L_0);
		IPAddress_t2F4486449B0D73FF2D3B36A9FE5E9C3F63116484* L_1;
		L_1 = IPEndPoint_get_Address_m72F783CB76E10E9DBDF680CCC1DAAED201BABB1C_inline(L_0, NULL);
		NullCheck(L_1);
		String_t* L_2;
		L_2 = VirtualFuncInvoker0< String_t* >::Invoke(3 /* System.String System.Object::ToString() */, L_1);
		NetDataWriter_Put_m40A032F477E6C5A55E526FF9D8CF668DC018FB63(__this, L_2, NULL);
		// Put(endPoint.Port);
		IPEndPoint_t2F09CBA7A808B67724B4E2954EEDC46D910F4ECB* L_3 = ___endPoint0;
		NullCheck(L_3);
		int32_t L_4;
		L_4 = IPEndPoint_get_Port_mFBE1AF1C9CC7E68A46BF46AD3869CC9DC01CF429_inline(L_3, NULL);
		NetDataWriter_Put_m2F26BB86FF421E370E72E34145DE801E15DC5603(__this, L_4, NULL);
		// }
		return;
	}
}
// System.Void LiteNetLib.Utils.NetDataWriter::Put(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NetDataWriter_Put_m40A032F477E6C5A55E526FF9D8CF668DC018FB63 (NetDataWriter_t5AE108AEC4825ED3FB45AA93565703368228EB37* __this, String_t* ___value0, const RuntimeMethod* method) 
{
	{
		// Put(value, 0);
		String_t* L_0 = ___value0;
		NetDataWriter_Put_m81B08D1F055A09468E4DE6D60F7A28F12AD56B77(__this, L_0, 0, NULL);
		// }
		return;
	}
}
// System.Void LiteNetLib.Utils.NetDataWriter::Put(System.String,System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NetDataWriter_Put_m81B08D1F055A09468E4DE6D60F7A28F12AD56B77 (NetDataWriter_t5AE108AEC4825ED3FB45AA93565703368228EB37* __this, String_t* ___value0, int32_t ___maxLength1, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&NetDataWriter_Put_m81B08D1F055A09468E4DE6D60F7A28F12AD56B77_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&NetDataWriter_t5AE108AEC4825ED3FB45AA93565703368228EB37_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t G_B6_0 = 0;
	{
		// if (value == null)
		String_t* L_0 = ___value0;
		if (L_0)
		{
			goto IL_000b;
		}
	}
	{
		// Put((ushort)0);
		NetDataWriter_Put_m8AA9410DD0C00EB7BC6E8493298A98B0C69B917E(__this, (uint16_t)0, NULL);
		// return;
		return;
	}

IL_000b:
	{
		// int length = maxLength > 0 && value.Length > maxLength ? maxLength : value.Length;
		int32_t L_1 = ___maxLength1;
		if ((((int32_t)L_1) <= ((int32_t)0)))
		{
			goto IL_0018;
		}
	}
	{
		String_t* L_2 = ___value0;
		NullCheck(L_2);
		int32_t L_3;
		L_3 = String_get_Length_m42625D67623FA5CC7A44D47425CE86FB946542D2_inline(L_2, NULL);
		int32_t L_4 = ___maxLength1;
		if ((((int32_t)L_3) > ((int32_t)L_4)))
		{
			goto IL_0020;
		}
	}

IL_0018:
	{
		String_t* L_5 = ___value0;
		NullCheck(L_5);
		int32_t L_6;
		L_6 = String_get_Length_m42625D67623FA5CC7A44D47425CE86FB946542D2_inline(L_5, NULL);
		G_B6_0 = L_6;
		goto IL_0021;
	}

IL_0020:
	{
		int32_t L_7 = ___maxLength1;
		G_B6_0 = L_7;
	}

IL_0021:
	{
		V_0 = G_B6_0;
		// int size = _uTF8Encoding.GetBytes(value, 0, length, _stringBuffer, 0);
		il2cpp_codegen_runtime_class_init_inline(NetDataWriter_t5AE108AEC4825ED3FB45AA93565703368228EB37_il2cpp_TypeInfo_var);
		UTF8Encoding_t90B56215A1B0B7ED5CDEA772E695F0DDAFBCD3BE* L_8 = ((NetDataWriter_t5AE108AEC4825ED3FB45AA93565703368228EB37_StaticFields*)il2cpp_codegen_static_fields_for(NetDataWriter_t5AE108AEC4825ED3FB45AA93565703368228EB37_il2cpp_TypeInfo_var))->____uTF8Encoding_4;
		String_t* L_9 = ___value0;
		int32_t L_10 = V_0;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_11 = __this->____stringBuffer_6;
		NullCheck(L_8);
		int32_t L_12;
		L_12 = VirtualFuncInvoker5< int32_t, String_t*, int32_t, int32_t, ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*, int32_t >::Invoke(19 /* System.Int32 System.Text.Encoding::GetBytes(System.String,System.Int32,System.Int32,System.Byte[],System.Int32) */, L_8, L_9, 0, L_10, L_11, 0);
		V_1 = L_12;
		// if (size >= StringBufferMaxLength)
		int32_t L_13 = V_1;
		if ((((int32_t)L_13) < ((int32_t)((int32_t)32768))))
		{
			goto IL_0047;
		}
	}
	{
		// Put((ushort)0);
		NetDataWriter_Put_m8AA9410DD0C00EB7BC6E8493298A98B0C69B917E(__this, (uint16_t)0, NULL);
		// return;
		return;
	}

IL_0047:
	{
		// Put(checked((ushort)(size + 1)));
		int32_t L_14 = V_1;
		if (((int64_t)L_14 + (int64_t)1 < (int64_t)kIl2CppInt32Min) || ((int64_t)L_14 + (int64_t)1 > (int64_t)kIl2CppInt32Max))
			IL2CPP_RAISE_MANAGED_EXCEPTION(il2cpp_codegen_get_overflow_exception(), NetDataWriter_Put_m81B08D1F055A09468E4DE6D60F7A28F12AD56B77_RuntimeMethod_var);
		if ((int64_t)(((int32_t)il2cpp_codegen_add(L_14, 1))) > 65535LL) IL2CPP_RAISE_MANAGED_EXCEPTION(il2cpp_codegen_get_overflow_exception(), NetDataWriter_Put_m81B08D1F055A09468E4DE6D60F7A28F12AD56B77_RuntimeMethod_var);
		NetDataWriter_Put_m8AA9410DD0C00EB7BC6E8493298A98B0C69B917E(__this, ((uint16_t)((int32_t)il2cpp_codegen_add(L_14, 1))), NULL);
		// Put(_stringBuffer, 0, size);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_15 = __this->____stringBuffer_6;
		int32_t L_16 = V_1;
		NetDataWriter_Put_mEE909D6E69A8733E062C5DB68417A58D1E4FF3B9(__this, L_15, 0, L_16, NULL);
		// }
		return;
	}
}
// System.Void LiteNetLib.Utils.NetDataWriter::.cctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NetDataWriter__cctor_m4A731B438A9C64B2FD80237F8D2C4B5D4C8C43D9 (const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&NetDataWriter_t5AE108AEC4825ED3FB45AA93565703368228EB37_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UTF8Encoding_t90B56215A1B0B7ED5CDEA772E695F0DDAFBCD3BE_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// private static readonly UTF8Encoding _uTF8Encoding = new UTF8Encoding(false, true);
		UTF8Encoding_t90B56215A1B0B7ED5CDEA772E695F0DDAFBCD3BE* L_0 = (UTF8Encoding_t90B56215A1B0B7ED5CDEA772E695F0DDAFBCD3BE*)il2cpp_codegen_object_new(UTF8Encoding_t90B56215A1B0B7ED5CDEA772E695F0DDAFBCD3BE_il2cpp_TypeInfo_var);
		NullCheck(L_0);
		UTF8Encoding__ctor_m128F4B4A103E718AAB699E2D64011DB13F486726(L_0, (bool)0, (bool)1, NULL);
		((NetDataWriter_t5AE108AEC4825ED3FB45AA93565703368228EB37_StaticFields*)il2cpp_codegen_static_fields_for(NetDataWriter_t5AE108AEC4825ED3FB45AA93565703368228EB37_il2cpp_TypeInfo_var))->____uTF8Encoding_4 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&((NetDataWriter_t5AE108AEC4825ED3FB45AA93565703368228EB37_StaticFields*)il2cpp_codegen_static_fields_for(NetDataWriter_t5AE108AEC4825ED3FB45AA93565703368228EB37_il2cpp_TypeInfo_var))->____uTF8Encoding_4), (void*)L_0);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void LiteNetLib.Utils.NetPacketProcessor::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NetPacketProcessor__ctor_mEE9890BB52B9DC21FF24B2BB713D10D365DE5873 (NetPacketProcessor_t535112850E31D87B64B84496790A24B227A1B65C* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2__ctor_mD1E3D96A898D0AE25D21A35F907E8FD90F077ECF_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_tC50529CA8871074E26D545E7CB9D085D0D295AEA_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&NetDataWriter_t5AE108AEC4825ED3FB45AA93565703368228EB37_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&NetSerializer_t6F1385A0BDE64EB9921D4351CFD84FF864E111DE_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// private readonly Dictionary<ulong, SubscribeDelegate> _callbacks = new Dictionary<ulong, SubscribeDelegate>();
		Dictionary_2_tC50529CA8871074E26D545E7CB9D085D0D295AEA* L_0 = (Dictionary_2_tC50529CA8871074E26D545E7CB9D085D0D295AEA*)il2cpp_codegen_object_new(Dictionary_2_tC50529CA8871074E26D545E7CB9D085D0D295AEA_il2cpp_TypeInfo_var);
		NullCheck(L_0);
		Dictionary_2__ctor_mD1E3D96A898D0AE25D21A35F907E8FD90F077ECF(L_0, Dictionary_2__ctor_mD1E3D96A898D0AE25D21A35F907E8FD90F077ECF_RuntimeMethod_var);
		__this->____callbacks_1 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____callbacks_1), (void*)L_0);
		// private readonly NetDataWriter _netDataWriter = new NetDataWriter();
		NetDataWriter_t5AE108AEC4825ED3FB45AA93565703368228EB37* L_1 = (NetDataWriter_t5AE108AEC4825ED3FB45AA93565703368228EB37*)il2cpp_codegen_object_new(NetDataWriter_t5AE108AEC4825ED3FB45AA93565703368228EB37_il2cpp_TypeInfo_var);
		NullCheck(L_1);
		NetDataWriter__ctor_m5DFECA4F51F5567F3C7EDC64103ED6B4DC772C2F(L_1, NULL);
		__this->____netDataWriter_2 = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____netDataWriter_2), (void*)L_1);
		// public NetPacketProcessor()
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		// _netSerializer = new NetSerializer();
		NetSerializer_t6F1385A0BDE64EB9921D4351CFD84FF864E111DE* L_2 = (NetSerializer_t6F1385A0BDE64EB9921D4351CFD84FF864E111DE*)il2cpp_codegen_object_new(NetSerializer_t6F1385A0BDE64EB9921D4351CFD84FF864E111DE_il2cpp_TypeInfo_var);
		NullCheck(L_2);
		NetSerializer__ctor_mD0D1DD7D5B57C35D5907108CB139C588A247DF1C(L_2, NULL);
		__this->____netSerializer_0 = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____netSerializer_0), (void*)L_2);
		// }
		return;
	}
}
// System.Void LiteNetLib.Utils.NetPacketProcessor::.ctor(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NetPacketProcessor__ctor_mD572373B34CD0748101FADA194214C4134A3C7E9 (NetPacketProcessor_t535112850E31D87B64B84496790A24B227A1B65C* __this, int32_t ___maxStringLength0, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2__ctor_mD1E3D96A898D0AE25D21A35F907E8FD90F077ECF_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_tC50529CA8871074E26D545E7CB9D085D0D295AEA_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&NetDataWriter_t5AE108AEC4825ED3FB45AA93565703368228EB37_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&NetSerializer_t6F1385A0BDE64EB9921D4351CFD84FF864E111DE_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// private readonly Dictionary<ulong, SubscribeDelegate> _callbacks = new Dictionary<ulong, SubscribeDelegate>();
		Dictionary_2_tC50529CA8871074E26D545E7CB9D085D0D295AEA* L_0 = (Dictionary_2_tC50529CA8871074E26D545E7CB9D085D0D295AEA*)il2cpp_codegen_object_new(Dictionary_2_tC50529CA8871074E26D545E7CB9D085D0D295AEA_il2cpp_TypeInfo_var);
		NullCheck(L_0);
		Dictionary_2__ctor_mD1E3D96A898D0AE25D21A35F907E8FD90F077ECF(L_0, Dictionary_2__ctor_mD1E3D96A898D0AE25D21A35F907E8FD90F077ECF_RuntimeMethod_var);
		__this->____callbacks_1 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____callbacks_1), (void*)L_0);
		// private readonly NetDataWriter _netDataWriter = new NetDataWriter();
		NetDataWriter_t5AE108AEC4825ED3FB45AA93565703368228EB37* L_1 = (NetDataWriter_t5AE108AEC4825ED3FB45AA93565703368228EB37*)il2cpp_codegen_object_new(NetDataWriter_t5AE108AEC4825ED3FB45AA93565703368228EB37_il2cpp_TypeInfo_var);
		NullCheck(L_1);
		NetDataWriter__ctor_m5DFECA4F51F5567F3C7EDC64103ED6B4DC772C2F(L_1, NULL);
		__this->____netDataWriter_2 = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____netDataWriter_2), (void*)L_1);
		// public NetPacketProcessor(int maxStringLength)
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		// _netSerializer = new NetSerializer(maxStringLength);
		int32_t L_2 = ___maxStringLength0;
		NetSerializer_t6F1385A0BDE64EB9921D4351CFD84FF864E111DE* L_3 = (NetSerializer_t6F1385A0BDE64EB9921D4351CFD84FF864E111DE*)il2cpp_codegen_object_new(NetSerializer_t6F1385A0BDE64EB9921D4351CFD84FF864E111DE_il2cpp_TypeInfo_var);
		NullCheck(L_3);
		NetSerializer__ctor_m11AB0F1B8B19828B0D3F334BD94BF415801C6CFB(L_3, L_2, NULL);
		__this->____netSerializer_0 = L_3;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____netSerializer_0), (void*)L_3);
		// }
		return;
	}
}
// LiteNetLib.Utils.NetPacketProcessor/SubscribeDelegate LiteNetLib.Utils.NetPacketProcessor::GetCallbackFromData(LiteNetLib.Utils.NetDataReader)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR SubscribeDelegate_t5176AD87F22014A136F003FB651B6451DB2BE13F* NetPacketProcessor_GetCallbackFromData_m9B87326F815691C0E39F42F97980101B151809A5 (NetPacketProcessor_t535112850E31D87B64B84496790A24B227A1B65C* __this, NetDataReader_t28CDAC4E19A9CDCCE3F782A3E29084D50A2F58FF* ___reader0, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_TryGetValue_mC87F2380785378011E6B2A46B0B81908F6A5000C_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	uint64_t V_0 = 0;
	SubscribeDelegate_t5176AD87F22014A136F003FB651B6451DB2BE13F* V_1 = NULL;
	{
		// ulong hash = reader.GetULong();
		NetDataReader_t28CDAC4E19A9CDCCE3F782A3E29084D50A2F58FF* L_0 = ___reader0;
		NullCheck(L_0);
		uint64_t L_1;
		L_1 = NetDataReader_GetULong_mB830F45D1FB580C0FE865A3181548680E6EC53CC(L_0, NULL);
		V_0 = L_1;
		// if (!_callbacks.TryGetValue(hash, out var action))
		Dictionary_2_tC50529CA8871074E26D545E7CB9D085D0D295AEA* L_2 = __this->____callbacks_1;
		uint64_t L_3 = V_0;
		NullCheck(L_2);
		bool L_4;
		L_4 = Dictionary_2_TryGetValue_mC87F2380785378011E6B2A46B0B81908F6A5000C(L_2, L_3, (&V_1), Dictionary_2_TryGetValue_mC87F2380785378011E6B2A46B0B81908F6A5000C_RuntimeMethod_var);
		if (L_4)
		{
			goto IL_0022;
		}
	}
	{
		// throw new ParseException("Undefined packet in NetDataReader");
		ParseException_t78F4289CD37365426C09D2D805B6EFE254DA2266* L_5 = (ParseException_t78F4289CD37365426C09D2D805B6EFE254DA2266*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ParseException_t78F4289CD37365426C09D2D805B6EFE254DA2266_il2cpp_TypeInfo_var)));
		NullCheck(L_5);
		ParseException__ctor_mF84E89C28BAD77FDEF412A03D7A25BBE5EDF2DC8(L_5, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral54CC87BDCC203DBF3D08732C8F6B081BD50E7D62)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_5, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NetPacketProcessor_GetCallbackFromData_m9B87326F815691C0E39F42F97980101B151809A5_RuntimeMethod_var)));
	}

IL_0022:
	{
		// return action;
		SubscribeDelegate_t5176AD87F22014A136F003FB651B6451DB2BE13F* L_6 = V_1;
		return L_6;
	}
}
// System.Void LiteNetLib.Utils.NetPacketProcessor::ReadAllPackets(LiteNetLib.Utils.NetDataReader)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NetPacketProcessor_ReadAllPackets_m1D764A5D19A5640B4AC1C61A88CC5B379D3AD83C (NetPacketProcessor_t535112850E31D87B64B84496790A24B227A1B65C* __this, NetDataReader_t28CDAC4E19A9CDCCE3F782A3E29084D50A2F58FF* ___reader0, const RuntimeMethod* method) 
{
	{
		goto IL_0009;
	}

IL_0002:
	{
		// ReadPacket(reader);
		NetDataReader_t28CDAC4E19A9CDCCE3F782A3E29084D50A2F58FF* L_0 = ___reader0;
		NetPacketProcessor_ReadPacket_m25BBA8ED257E115D193D695435756946944A8CE1(__this, L_0, NULL);
	}

IL_0009:
	{
		// while (reader.AvailableBytes > 0)
		NetDataReader_t28CDAC4E19A9CDCCE3F782A3E29084D50A2F58FF* L_1 = ___reader0;
		NullCheck(L_1);
		int32_t L_2;
		L_2 = NetDataReader_get_AvailableBytes_mEFB8DB278DBA8EAD90E606050F06B83BAFC260EB(L_1, NULL);
		if ((((int32_t)L_2) > ((int32_t)0)))
		{
			goto IL_0002;
		}
	}
	{
		// }
		return;
	}
}
// System.Void LiteNetLib.Utils.NetPacketProcessor::ReadAllPackets(LiteNetLib.Utils.NetDataReader,System.Object)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NetPacketProcessor_ReadAllPackets_m6F4CF10C3C78C5D0BF6882C93C95D2F6BCBFE8CF (NetPacketProcessor_t535112850E31D87B64B84496790A24B227A1B65C* __this, NetDataReader_t28CDAC4E19A9CDCCE3F782A3E29084D50A2F58FF* ___reader0, RuntimeObject* ___userData1, const RuntimeMethod* method) 
{
	{
		goto IL_000a;
	}

IL_0002:
	{
		// ReadPacket(reader, userData);
		NetDataReader_t28CDAC4E19A9CDCCE3F782A3E29084D50A2F58FF* L_0 = ___reader0;
		RuntimeObject* L_1 = ___userData1;
		NetPacketProcessor_ReadPacket_m20EA197B034B623B752225213DD2240F4B9686DA(__this, L_0, L_1, NULL);
	}

IL_000a:
	{
		// while (reader.AvailableBytes > 0)
		NetDataReader_t28CDAC4E19A9CDCCE3F782A3E29084D50A2F58FF* L_2 = ___reader0;
		NullCheck(L_2);
		int32_t L_3;
		L_3 = NetDataReader_get_AvailableBytes_mEFB8DB278DBA8EAD90E606050F06B83BAFC260EB(L_2, NULL);
		if ((((int32_t)L_3) > ((int32_t)0)))
		{
			goto IL_0002;
		}
	}
	{
		// }
		return;
	}
}
// System.Void LiteNetLib.Utils.NetPacketProcessor::ReadPacket(LiteNetLib.Utils.NetDataReader)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NetPacketProcessor_ReadPacket_m25BBA8ED257E115D193D695435756946944A8CE1 (NetPacketProcessor_t535112850E31D87B64B84496790A24B227A1B65C* __this, NetDataReader_t28CDAC4E19A9CDCCE3F782A3E29084D50A2F58FF* ___reader0, const RuntimeMethod* method) 
{
	{
		// ReadPacket(reader, null);
		NetDataReader_t28CDAC4E19A9CDCCE3F782A3E29084D50A2F58FF* L_0 = ___reader0;
		NetPacketProcessor_ReadPacket_m20EA197B034B623B752225213DD2240F4B9686DA(__this, L_0, NULL, NULL);
		// }
		return;
	}
}
// System.Void LiteNetLib.Utils.NetPacketProcessor::ReadPacket(LiteNetLib.Utils.NetDataReader,System.Object)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NetPacketProcessor_ReadPacket_m20EA197B034B623B752225213DD2240F4B9686DA (NetPacketProcessor_t535112850E31D87B64B84496790A24B227A1B65C* __this, NetDataReader_t28CDAC4E19A9CDCCE3F782A3E29084D50A2F58FF* ___reader0, RuntimeObject* ___userData1, const RuntimeMethod* method) 
{
	{
		// GetCallbackFromData(reader)(reader, userData);
		NetDataReader_t28CDAC4E19A9CDCCE3F782A3E29084D50A2F58FF* L_0 = ___reader0;
		SubscribeDelegate_t5176AD87F22014A136F003FB651B6451DB2BE13F* L_1;
		L_1 = VirtualFuncInvoker1< SubscribeDelegate_t5176AD87F22014A136F003FB651B6451DB2BE13F*, NetDataReader_t28CDAC4E19A9CDCCE3F782A3E29084D50A2F58FF* >::Invoke(5 /* LiteNetLib.Utils.NetPacketProcessor/SubscribeDelegate LiteNetLib.Utils.NetPacketProcessor::GetCallbackFromData(LiteNetLib.Utils.NetDataReader) */, __this, L_0);
		NetDataReader_t28CDAC4E19A9CDCCE3F782A3E29084D50A2F58FF* L_2 = ___reader0;
		RuntimeObject* L_3 = ___userData1;
		NullCheck(L_1);
		SubscribeDelegate_Invoke_m803C81F37C8A72A124C26584AD4938FA1F7FD77C_inline(L_1, L_2, L_3, NULL);
		// }
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
void SubscribeDelegate_Invoke_m803C81F37C8A72A124C26584AD4938FA1F7FD77C_Multicast(SubscribeDelegate_t5176AD87F22014A136F003FB651B6451DB2BE13F* __this, NetDataReader_t28CDAC4E19A9CDCCE3F782A3E29084D50A2F58FF* ___reader0, RuntimeObject* ___userData1, const RuntimeMethod* method)
{
	il2cpp_array_size_t length = __this->___delegates_13->max_length;
	Delegate_t** delegatesToInvoke = reinterpret_cast<Delegate_t**>(__this->___delegates_13->GetAddressAtUnchecked(0));
	for (il2cpp_array_size_t i = 0; i < length; i++)
	{
		SubscribeDelegate_t5176AD87F22014A136F003FB651B6451DB2BE13F* currentDelegate = reinterpret_cast<SubscribeDelegate_t5176AD87F22014A136F003FB651B6451DB2BE13F*>(delegatesToInvoke[i]);
		typedef void (*FunctionPointerType) (RuntimeObject*, NetDataReader_t28CDAC4E19A9CDCCE3F782A3E29084D50A2F58FF*, RuntimeObject*, const RuntimeMethod*);
		((FunctionPointerType)currentDelegate->___invoke_impl_1)((Il2CppObject*)currentDelegate->___method_code_6, ___reader0, ___userData1, reinterpret_cast<RuntimeMethod*>(currentDelegate->___method_3));
	}
}
void SubscribeDelegate_Invoke_m803C81F37C8A72A124C26584AD4938FA1F7FD77C_OpenInst(SubscribeDelegate_t5176AD87F22014A136F003FB651B6451DB2BE13F* __this, NetDataReader_t28CDAC4E19A9CDCCE3F782A3E29084D50A2F58FF* ___reader0, RuntimeObject* ___userData1, const RuntimeMethod* method)
{
	NullCheck(___reader0);
	typedef void (*FunctionPointerType) (NetDataReader_t28CDAC4E19A9CDCCE3F782A3E29084D50A2F58FF*, RuntimeObject*, const RuntimeMethod*);
	((FunctionPointerType)__this->___method_ptr_0)(___reader0, ___userData1, method);
}
void SubscribeDelegate_Invoke_m803C81F37C8A72A124C26584AD4938FA1F7FD77C_OpenStatic(SubscribeDelegate_t5176AD87F22014A136F003FB651B6451DB2BE13F* __this, NetDataReader_t28CDAC4E19A9CDCCE3F782A3E29084D50A2F58FF* ___reader0, RuntimeObject* ___userData1, const RuntimeMethod* method)
{
	typedef void (*FunctionPointerType) (NetDataReader_t28CDAC4E19A9CDCCE3F782A3E29084D50A2F58FF*, RuntimeObject*, const RuntimeMethod*);
	((FunctionPointerType)__this->___method_ptr_0)(___reader0, ___userData1, method);
}
void SubscribeDelegate_Invoke_m803C81F37C8A72A124C26584AD4938FA1F7FD77C_OpenStaticInvoker(SubscribeDelegate_t5176AD87F22014A136F003FB651B6451DB2BE13F* __this, NetDataReader_t28CDAC4E19A9CDCCE3F782A3E29084D50A2F58FF* ___reader0, RuntimeObject* ___userData1, const RuntimeMethod* method)
{
	InvokerActionInvoker2< NetDataReader_t28CDAC4E19A9CDCCE3F782A3E29084D50A2F58FF*, RuntimeObject* >::Invoke(__this->___method_ptr_0, method, NULL, ___reader0, ___userData1);
}
void SubscribeDelegate_Invoke_m803C81F37C8A72A124C26584AD4938FA1F7FD77C_ClosedStaticInvoker(SubscribeDelegate_t5176AD87F22014A136F003FB651B6451DB2BE13F* __this, NetDataReader_t28CDAC4E19A9CDCCE3F782A3E29084D50A2F58FF* ___reader0, RuntimeObject* ___userData1, const RuntimeMethod* method)
{
	InvokerActionInvoker3< RuntimeObject*, NetDataReader_t28CDAC4E19A9CDCCE3F782A3E29084D50A2F58FF*, RuntimeObject* >::Invoke(__this->___method_ptr_0, method, NULL, __this->___m_target_2, ___reader0, ___userData1);
}
void SubscribeDelegate_Invoke_m803C81F37C8A72A124C26584AD4938FA1F7FD77C_OpenVirtual(SubscribeDelegate_t5176AD87F22014A136F003FB651B6451DB2BE13F* __this, NetDataReader_t28CDAC4E19A9CDCCE3F782A3E29084D50A2F58FF* ___reader0, RuntimeObject* ___userData1, const RuntimeMethod* method)
{
	NullCheck(___reader0);
	VirtualActionInvoker1< RuntimeObject* >::Invoke(il2cpp_codegen_method_get_slot(method), ___reader0, ___userData1);
}
void SubscribeDelegate_Invoke_m803C81F37C8A72A124C26584AD4938FA1F7FD77C_OpenInterface(SubscribeDelegate_t5176AD87F22014A136F003FB651B6451DB2BE13F* __this, NetDataReader_t28CDAC4E19A9CDCCE3F782A3E29084D50A2F58FF* ___reader0, RuntimeObject* ___userData1, const RuntimeMethod* method)
{
	NullCheck(___reader0);
	InterfaceActionInvoker1< RuntimeObject* >::Invoke(il2cpp_codegen_method_get_slot(method), il2cpp_codegen_method_get_declaring_type(method), ___reader0, ___userData1);
}
void SubscribeDelegate_Invoke_m803C81F37C8A72A124C26584AD4938FA1F7FD77C_OpenGenericVirtual(SubscribeDelegate_t5176AD87F22014A136F003FB651B6451DB2BE13F* __this, NetDataReader_t28CDAC4E19A9CDCCE3F782A3E29084D50A2F58FF* ___reader0, RuntimeObject* ___userData1, const RuntimeMethod* method)
{
	NullCheck(___reader0);
	GenericVirtualActionInvoker1< RuntimeObject* >::Invoke(method, ___reader0, ___userData1);
}
void SubscribeDelegate_Invoke_m803C81F37C8A72A124C26584AD4938FA1F7FD77C_OpenGenericInterface(SubscribeDelegate_t5176AD87F22014A136F003FB651B6451DB2BE13F* __this, NetDataReader_t28CDAC4E19A9CDCCE3F782A3E29084D50A2F58FF* ___reader0, RuntimeObject* ___userData1, const RuntimeMethod* method)
{
	NullCheck(___reader0);
	GenericInterfaceActionInvoker1< RuntimeObject* >::Invoke(method, ___reader0, ___userData1);
}
// System.Void LiteNetLib.Utils.NetPacketProcessor/SubscribeDelegate::.ctor(System.Object,System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SubscribeDelegate__ctor_mBF6813CBE194B4F72764072D77AF65D68CDD44B0 (SubscribeDelegate_t5176AD87F22014A136F003FB651B6451DB2BE13F* __this, RuntimeObject* ___object0, intptr_t ___method1, const RuntimeMethod* method) 
{
	__this->___method_ptr_0 = il2cpp_codegen_get_virtual_call_method_pointer((RuntimeMethod*)___method1);
	__this->___method_3 = ___method1;
	__this->___m_target_2 = ___object0;
	Il2CppCodeGenWriteBarrier((void**)(&__this->___m_target_2), (void*)___object0);
	int parameterCount = il2cpp_codegen_method_parameter_count((RuntimeMethod*)___method1);
	__this->___method_code_6 = (intptr_t)__this;
	if (MethodIsStatic((RuntimeMethod*)___method1))
	{
		bool isOpen = parameterCount == 2;
		if (il2cpp_codegen_call_method_via_invoker((RuntimeMethod*)___method1))
			if (isOpen)
				__this->___invoke_impl_1 = (intptr_t)&SubscribeDelegate_Invoke_m803C81F37C8A72A124C26584AD4938FA1F7FD77C_OpenStaticInvoker;
			else
				__this->___invoke_impl_1 = (intptr_t)&SubscribeDelegate_Invoke_m803C81F37C8A72A124C26584AD4938FA1F7FD77C_ClosedStaticInvoker;
		else
			if (isOpen)
				__this->___invoke_impl_1 = (intptr_t)&SubscribeDelegate_Invoke_m803C81F37C8A72A124C26584AD4938FA1F7FD77C_OpenStatic;
			else
				{
					__this->___invoke_impl_1 = (intptr_t)__this->___method_ptr_0;
					__this->___method_code_6 = (intptr_t)__this->___m_target_2;
				}
	}
	else
	{
		bool isOpen = parameterCount == 1;
		if (isOpen)
		{
			if (__this->___method_is_virtual_12)
			{
				if (il2cpp_codegen_method_is_generic_instance_method((RuntimeMethod*)___method1))
					if (il2cpp_codegen_method_is_interface_method((RuntimeMethod*)___method1))
						__this->___invoke_impl_1 = (intptr_t)&SubscribeDelegate_Invoke_m803C81F37C8A72A124C26584AD4938FA1F7FD77C_OpenGenericInterface;
					else
						__this->___invoke_impl_1 = (intptr_t)&SubscribeDelegate_Invoke_m803C81F37C8A72A124C26584AD4938FA1F7FD77C_OpenGenericVirtual;
				else
					if (il2cpp_codegen_method_is_interface_method((RuntimeMethod*)___method1))
						__this->___invoke_impl_1 = (intptr_t)&SubscribeDelegate_Invoke_m803C81F37C8A72A124C26584AD4938FA1F7FD77C_OpenInterface;
					else
						__this->___invoke_impl_1 = (intptr_t)&SubscribeDelegate_Invoke_m803C81F37C8A72A124C26584AD4938FA1F7FD77C_OpenVirtual;
			}
			else
			{
				__this->___invoke_impl_1 = (intptr_t)&SubscribeDelegate_Invoke_m803C81F37C8A72A124C26584AD4938FA1F7FD77C_OpenInst;
			}
		}
		else
		{
			if (___object0 == NULL)
				il2cpp_codegen_raise_exception(il2cpp_codegen_get_argument_exception(NULL, "Delegate to an instance method cannot have null 'this'."), NULL);
			__this->___invoke_impl_1 = (intptr_t)__this->___method_ptr_0;
			__this->___method_code_6 = (intptr_t)__this->___m_target_2;
		}
	}
	__this->___extra_arg_5 = (intptr_t)&SubscribeDelegate_Invoke_m803C81F37C8A72A124C26584AD4938FA1F7FD77C_Multicast;
}
// System.Void LiteNetLib.Utils.NetPacketProcessor/SubscribeDelegate::Invoke(LiteNetLib.Utils.NetDataReader,System.Object)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SubscribeDelegate_Invoke_m803C81F37C8A72A124C26584AD4938FA1F7FD77C (SubscribeDelegate_t5176AD87F22014A136F003FB651B6451DB2BE13F* __this, NetDataReader_t28CDAC4E19A9CDCCE3F782A3E29084D50A2F58FF* ___reader0, RuntimeObject* ___userData1, const RuntimeMethod* method) 
{
	typedef void (*FunctionPointerType) (RuntimeObject*, NetDataReader_t28CDAC4E19A9CDCCE3F782A3E29084D50A2F58FF*, RuntimeObject*, const RuntimeMethod*);
	((FunctionPointerType)__this->___invoke_impl_1)((Il2CppObject*)__this->___method_code_6, ___reader0, ___userData1, reinterpret_cast<RuntimeMethod*>(__this->___method_3));
}
// System.IAsyncResult LiteNetLib.Utils.NetPacketProcessor/SubscribeDelegate::BeginInvoke(LiteNetLib.Utils.NetDataReader,System.Object,System.AsyncCallback,System.Object)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* SubscribeDelegate_BeginInvoke_m84F50D9139A055C26847C9FFA8747AF13DBB1B52 (SubscribeDelegate_t5176AD87F22014A136F003FB651B6451DB2BE13F* __this, NetDataReader_t28CDAC4E19A9CDCCE3F782A3E29084D50A2F58FF* ___reader0, RuntimeObject* ___userData1, AsyncCallback_t7FEF460CBDCFB9C5FA2EF776984778B9A4145F4C* ___callback2, RuntimeObject* ___object3, const RuntimeMethod* method) 
{
	void *__d_args[3] = {0};
	__d_args[0] = ___reader0;
	__d_args[1] = ___userData1;
	return (RuntimeObject*)il2cpp_codegen_delegate_begin_invoke((RuntimeDelegate*)__this, __d_args, (RuntimeDelegate*)___callback2, (RuntimeObject*)___object3);
}
// System.Void LiteNetLib.Utils.NetPacketProcessor/SubscribeDelegate::EndInvoke(System.IAsyncResult)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SubscribeDelegate_EndInvoke_mAFD56B1AA0A25DA56D1B808C9A6292C88DDF8897 (SubscribeDelegate_t5176AD87F22014A136F003FB651B6451DB2BE13F* __this, RuntimeObject* ___result0, const RuntimeMethod* method) 
{
	il2cpp_codegen_delegate_end_invoke((Il2CppAsyncResult*) ___result0, 0);
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void LiteNetLib.Utils.InvalidTypeException::.ctor(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void InvalidTypeException__ctor_mFB78F67FE632DDC9174C6A78FDEEDBCF442B3150 (InvalidTypeException_t3216C4E1075D00F909878A0C023BF525B9DFF127* __this, String_t* ___message0, const RuntimeMethod* method) 
{
	{
		// public InvalidTypeException(string message) : base(message) { }
		String_t* L_0 = ___message0;
		ArgumentException__ctor_m026938A67AF9D36BB7ED27F80425D7194B514465(__this, L_0, NULL);
		// public InvalidTypeException(string message) : base(message) { }
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void LiteNetLib.Utils.ParseException::.ctor(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ParseException__ctor_mF84E89C28BAD77FDEF412A03D7A25BBE5EDF2DC8 (ParseException_t78F4289CD37365426C09D2D805B6EFE254DA2266* __this, String_t* ___message0, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Exception_t_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// public ParseException(string message) : base(message) { }
		String_t* L_0 = ___message0;
		il2cpp_codegen_runtime_class_init_inline(Exception_t_il2cpp_TypeInfo_var);
		Exception__ctor_m9B2BD92CD68916245A75109105D9071C9D430E7F(__this, L_0, NULL);
		// public ParseException(string message) : base(message) { }
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void LiteNetLib.Utils.NetSerializer::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NetSerializer__ctor_mD0D1DD7D5B57C35D5907108CB139C588A247DF1C (NetSerializer_t6F1385A0BDE64EB9921D4351CFD84FF864E111DE* __this, const RuntimeMethod* method) 
{
	{
		// public NetSerializer() : this(0)
		NetSerializer__ctor_m11AB0F1B8B19828B0D3F334BD94BF415801C6CFB(__this, 0, NULL);
		// }
		return;
	}
}
// System.Void LiteNetLib.Utils.NetSerializer::.ctor(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NetSerializer__ctor_m11AB0F1B8B19828B0D3F334BD94BF415801C6CFB (NetSerializer_t6F1385A0BDE64EB9921D4351CFD84FF864E111DE* __this, int32_t ___maxStringLength0, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2__ctor_mE1C7F4DEE5EFADD1C6C6AFBEE21572DEF740AA96_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_tE9744A9551C9F7ADCA9DCECD5809D05C5FCD8FB8_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// private readonly Dictionary<Type, CustomType> _registeredTypes = new Dictionary<Type, CustomType>();
		Dictionary_2_tE9744A9551C9F7ADCA9DCECD5809D05C5FCD8FB8* L_0 = (Dictionary_2_tE9744A9551C9F7ADCA9DCECD5809D05C5FCD8FB8*)il2cpp_codegen_object_new(Dictionary_2_tE9744A9551C9F7ADCA9DCECD5809D05C5FCD8FB8_il2cpp_TypeInfo_var);
		NullCheck(L_0);
		Dictionary_2__ctor_mE1C7F4DEE5EFADD1C6C6AFBEE21572DEF740AA96(L_0, Dictionary_2__ctor_mE1C7F4DEE5EFADD1C6C6AFBEE21572DEF740AA96_RuntimeMethod_var);
		__this->____registeredTypes_2 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____registeredTypes_2), (void*)L_0);
		// public NetSerializer(int maxStringLength)
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		// _maxStringLength = maxStringLength;
		int32_t L_1 = ___maxStringLength0;
		__this->____maxStringLength_1 = L_1;
		// }
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void LiteNetLib.Utils.NetSerializer/CustomType::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void CustomType__ctor_m0BFD67DC656CFC4B8F4A6636DDE6CA3DECEC1EA1 (CustomType_t5DD67989E7FD0AC65476233C7C30A0BE5282624B* __this, const RuntimeMethod* method) 
{
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Byte[] LiteNetLib.Utils.NtpPacket::get_Bytes()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* NtpPacket_get_Bytes_m6E68BBD8630A83EEB78A27E590D38FF01C83E6C3 (NtpPacket_tF37CA19271AE795B037952A3137F652EF3B95E92* __this, const RuntimeMethod* method) 
{
	{
		// public byte[] Bytes { get; }
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_0 = __this->___U3CBytesU3Ek__BackingField_1;
		return L_0;
	}
}
// LiteNetLib.Utils.NtpLeapIndicator LiteNetLib.Utils.NtpPacket::get_LeapIndicator()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t NtpPacket_get_LeapIndicator_m2EF17809EDB88F7D10BF8848FFAB2A96BCF8C5DE (NtpPacket_tF37CA19271AE795B037952A3137F652EF3B95E92* __this, const RuntimeMethod* method) 
{
	{
		// public NtpLeapIndicator LeapIndicator => (NtpLeapIndicator)((Bytes[0] & 0xC0) >> 6);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_0;
		L_0 = NtpPacket_get_Bytes_m6E68BBD8630A83EEB78A27E590D38FF01C83E6C3_inline(__this, NULL);
		NullCheck(L_0);
		int32_t L_1 = 0;
		uint8_t L_2 = (L_0)->GetAt(static_cast<il2cpp_array_size_t>(L_1));
		return (int32_t)(((int32_t)(((int32_t)((int32_t)L_2&((int32_t)192)))>>6)));
	}
}
// System.Int32 LiteNetLib.Utils.NtpPacket::get_VersionNumber()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t NtpPacket_get_VersionNumber_m8BBA6DBFF2942AFA98F08707E5C2DF9402ACBDEB (NtpPacket_tF37CA19271AE795B037952A3137F652EF3B95E92* __this, const RuntimeMethod* method) 
{
	{
		// get => (Bytes[0] & 0x38) >> 3;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_0;
		L_0 = NtpPacket_get_Bytes_m6E68BBD8630A83EEB78A27E590D38FF01C83E6C3_inline(__this, NULL);
		NullCheck(L_0);
		int32_t L_1 = 0;
		uint8_t L_2 = (L_0)->GetAt(static_cast<il2cpp_array_size_t>(L_1));
		return ((int32_t)(((int32_t)((int32_t)L_2&((int32_t)56)))>>3));
	}
}
// System.Void LiteNetLib.Utils.NtpPacket::set_VersionNumber(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NtpPacket_set_VersionNumber_m7B86709BF5EDAC346CFAB1EB13282EB7BA00B384 (NtpPacket_tF37CA19271AE795B037952A3137F652EF3B95E92* __this, int32_t ___value0, const RuntimeMethod* method) 
{
	{
		// private set => Bytes[0] = (byte)((Bytes[0] & ~0x38) | value << 3);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_0;
		L_0 = NtpPacket_get_Bytes_m6E68BBD8630A83EEB78A27E590D38FF01C83E6C3_inline(__this, NULL);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_1;
		L_1 = NtpPacket_get_Bytes_m6E68BBD8630A83EEB78A27E590D38FF01C83E6C3_inline(__this, NULL);
		NullCheck(L_1);
		int32_t L_2 = 0;
		uint8_t L_3 = (L_1)->GetAt(static_cast<il2cpp_array_size_t>(L_2));
		int32_t L_4 = ___value0;
		NullCheck(L_0);
		(L_0)->SetAt(static_cast<il2cpp_array_size_t>(0), (uint8_t)((int32_t)(uint8_t)((int32_t)(((int32_t)((int32_t)L_3&((int32_t)-57)))|((int32_t)(L_4<<3))))));
		return;
	}
}
// LiteNetLib.Utils.NtpMode LiteNetLib.Utils.NtpPacket::get_Mode()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t NtpPacket_get_Mode_m301D434C5382328D6E1BEAE493ABEF3B3CE89BBA (NtpPacket_tF37CA19271AE795B037952A3137F652EF3B95E92* __this, const RuntimeMethod* method) 
{
	{
		// get => (NtpMode)(Bytes[0] & 0x07);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_0;
		L_0 = NtpPacket_get_Bytes_m6E68BBD8630A83EEB78A27E590D38FF01C83E6C3_inline(__this, NULL);
		NullCheck(L_0);
		int32_t L_1 = 0;
		uint8_t L_2 = (L_0)->GetAt(static_cast<il2cpp_array_size_t>(L_1));
		return (int32_t)(((int32_t)((int32_t)L_2&7)));
	}
}
// System.Void LiteNetLib.Utils.NtpPacket::set_Mode(LiteNetLib.Utils.NtpMode)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NtpPacket_set_Mode_m0B5EEEC21B94479A31FAC030B6D5B67527C64EB3 (NtpPacket_tF37CA19271AE795B037952A3137F652EF3B95E92* __this, int32_t ___value0, const RuntimeMethod* method) 
{
	{
		// private set => Bytes[0] = (byte)((Bytes[0] & ~0x07) | (int)value);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_0;
		L_0 = NtpPacket_get_Bytes_m6E68BBD8630A83EEB78A27E590D38FF01C83E6C3_inline(__this, NULL);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_1;
		L_1 = NtpPacket_get_Bytes_m6E68BBD8630A83EEB78A27E590D38FF01C83E6C3_inline(__this, NULL);
		NullCheck(L_1);
		int32_t L_2 = 0;
		uint8_t L_3 = (L_1)->GetAt(static_cast<il2cpp_array_size_t>(L_2));
		int32_t L_4 = ___value0;
		NullCheck(L_0);
		(L_0)->SetAt(static_cast<il2cpp_array_size_t>(0), (uint8_t)((int32_t)(uint8_t)((int32_t)(((int32_t)((int32_t)L_3&((int32_t)-8)))|(int32_t)L_4))));
		return;
	}
}
// System.Int32 LiteNetLib.Utils.NtpPacket::get_Stratum()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t NtpPacket_get_Stratum_mA87F41632A21B205B8EBC172DC69BE6586764D9D (NtpPacket_tF37CA19271AE795B037952A3137F652EF3B95E92* __this, const RuntimeMethod* method) 
{
	{
		// public int Stratum => Bytes[1];
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_0;
		L_0 = NtpPacket_get_Bytes_m6E68BBD8630A83EEB78A27E590D38FF01C83E6C3_inline(__this, NULL);
		NullCheck(L_0);
		int32_t L_1 = 1;
		uint8_t L_2 = (L_0)->GetAt(static_cast<il2cpp_array_size_t>(L_1));
		return L_2;
	}
}
// System.Int32 LiteNetLib.Utils.NtpPacket::get_Poll()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t NtpPacket_get_Poll_m0654EE5DFD7BC5B3FED03F23EAD79277B111DFCB (NtpPacket_tF37CA19271AE795B037952A3137F652EF3B95E92* __this, const RuntimeMethod* method) 
{
	{
		// public int Poll => Bytes[2];
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_0;
		L_0 = NtpPacket_get_Bytes_m6E68BBD8630A83EEB78A27E590D38FF01C83E6C3_inline(__this, NULL);
		NullCheck(L_0);
		int32_t L_1 = 2;
		uint8_t L_2 = (L_0)->GetAt(static_cast<il2cpp_array_size_t>(L_1));
		return L_2;
	}
}
// System.Int32 LiteNetLib.Utils.NtpPacket::get_Precision()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t NtpPacket_get_Precision_m8D2ECADA18A4FE2A9AC028BEC9B364341034E4A0 (NtpPacket_tF37CA19271AE795B037952A3137F652EF3B95E92* __this, const RuntimeMethod* method) 
{
	{
		// public int Precision => (sbyte)Bytes[3];
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_0;
		L_0 = NtpPacket_get_Bytes_m6E68BBD8630A83EEB78A27E590D38FF01C83E6C3_inline(__this, NULL);
		NullCheck(L_0);
		int32_t L_1 = 3;
		uint8_t L_2 = (L_0)->GetAt(static_cast<il2cpp_array_size_t>(L_1));
		return ((int8_t)L_2);
	}
}
// System.TimeSpan LiteNetLib.Utils.NtpPacket::get_RootDelay()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A NtpPacket_get_RootDelay_mB27140DB1EB7774A72A2D0DC6211383613A4E64F (NtpPacket_tF37CA19271AE795B037952A3137F652EF3B95E92* __this, const RuntimeMethod* method) 
{
	{
		// public TimeSpan RootDelay => GetTimeSpan32(4);
		TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A L_0;
		L_0 = NtpPacket_GetTimeSpan32_m9FFAC53FB307FD2C01EDB48D503D3030500FEC41(__this, 4, NULL);
		return L_0;
	}
}
// System.TimeSpan LiteNetLib.Utils.NtpPacket::get_RootDispersion()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A NtpPacket_get_RootDispersion_m0D294F6EC3325960B50FD4A87D9400A02238DB04 (NtpPacket_tF37CA19271AE795B037952A3137F652EF3B95E92* __this, const RuntimeMethod* method) 
{
	{
		// public TimeSpan RootDispersion => GetTimeSpan32(8);
		TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A L_0;
		L_0 = NtpPacket_GetTimeSpan32_m9FFAC53FB307FD2C01EDB48D503D3030500FEC41(__this, 8, NULL);
		return L_0;
	}
}
// System.UInt32 LiteNetLib.Utils.NtpPacket::get_ReferenceId()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint32_t NtpPacket_get_ReferenceId_m767F85AC132891BC56829857A5F613F68B510152 (NtpPacket_tF37CA19271AE795B037952A3137F652EF3B95E92* __this, const RuntimeMethod* method) 
{
	{
		// public uint ReferenceId => GetUInt32BE(12);
		uint32_t L_0;
		L_0 = NtpPacket_GetUInt32BE_m105480B326D4407FB1FBA477AE2B12D22A38F0D6(__this, ((int32_t)12), NULL);
		return L_0;
	}
}
// System.Nullable`1<System.DateTime> LiteNetLib.Utils.NtpPacket::get_ReferenceTimestamp()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Nullable_1_tEADC262F7F8B8BC4CC0A003DBDD3CA7C1B63F9AC NtpPacket_get_ReferenceTimestamp_mF39F9FAB7FA95A9458EBB63E72A1C207EC865A4C (NtpPacket_tF37CA19271AE795B037952A3137F652EF3B95E92* __this, const RuntimeMethod* method) 
{
	{
		// public DateTime? ReferenceTimestamp => GetDateTime64(16);
		Nullable_1_tEADC262F7F8B8BC4CC0A003DBDD3CA7C1B63F9AC L_0;
		L_0 = NtpPacket_GetDateTime64_m486CD5CC1B530B599628C3FE1E7F0D4919DADC53(__this, ((int32_t)16), NULL);
		return L_0;
	}
}
// System.Nullable`1<System.DateTime> LiteNetLib.Utils.NtpPacket::get_OriginTimestamp()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Nullable_1_tEADC262F7F8B8BC4CC0A003DBDD3CA7C1B63F9AC NtpPacket_get_OriginTimestamp_m787D1313D7FC4C68928379E18EFCA30BB0D1DC15 (NtpPacket_tF37CA19271AE795B037952A3137F652EF3B95E92* __this, const RuntimeMethod* method) 
{
	{
		// public DateTime? OriginTimestamp => GetDateTime64(24);
		Nullable_1_tEADC262F7F8B8BC4CC0A003DBDD3CA7C1B63F9AC L_0;
		L_0 = NtpPacket_GetDateTime64_m486CD5CC1B530B599628C3FE1E7F0D4919DADC53(__this, ((int32_t)24), NULL);
		return L_0;
	}
}
// System.Nullable`1<System.DateTime> LiteNetLib.Utils.NtpPacket::get_ReceiveTimestamp()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Nullable_1_tEADC262F7F8B8BC4CC0A003DBDD3CA7C1B63F9AC NtpPacket_get_ReceiveTimestamp_mB169F736E742626862CEB3BAB4CFC2C9B72D59F8 (NtpPacket_tF37CA19271AE795B037952A3137F652EF3B95E92* __this, const RuntimeMethod* method) 
{
	{
		// public DateTime? ReceiveTimestamp => GetDateTime64(32);
		Nullable_1_tEADC262F7F8B8BC4CC0A003DBDD3CA7C1B63F9AC L_0;
		L_0 = NtpPacket_GetDateTime64_m486CD5CC1B530B599628C3FE1E7F0D4919DADC53(__this, ((int32_t)32), NULL);
		return L_0;
	}
}
// System.Nullable`1<System.DateTime> LiteNetLib.Utils.NtpPacket::get_TransmitTimestamp()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Nullable_1_tEADC262F7F8B8BC4CC0A003DBDD3CA7C1B63F9AC NtpPacket_get_TransmitTimestamp_mA8AE43E3EB22AB1AB3D47F8DEB624CE634B24CA3 (NtpPacket_tF37CA19271AE795B037952A3137F652EF3B95E92* __this, const RuntimeMethod* method) 
{
	{
		// public DateTime? TransmitTimestamp { get { return GetDateTime64(40); } private set { SetDateTime64(40, value); } }
		Nullable_1_tEADC262F7F8B8BC4CC0A003DBDD3CA7C1B63F9AC L_0;
		L_0 = NtpPacket_GetDateTime64_m486CD5CC1B530B599628C3FE1E7F0D4919DADC53(__this, ((int32_t)40), NULL);
		return L_0;
	}
}
// System.Void LiteNetLib.Utils.NtpPacket::set_TransmitTimestamp(System.Nullable`1<System.DateTime>)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NtpPacket_set_TransmitTimestamp_m4B21A40F4CFB42E78F92894F1BDB3E4718B9FB6B (NtpPacket_tF37CA19271AE795B037952A3137F652EF3B95E92* __this, Nullable_1_tEADC262F7F8B8BC4CC0A003DBDD3CA7C1B63F9AC ___value0, const RuntimeMethod* method) 
{
	{
		// public DateTime? TransmitTimestamp { get { return GetDateTime64(40); } private set { SetDateTime64(40, value); } }
		Nullable_1_tEADC262F7F8B8BC4CC0A003DBDD3CA7C1B63F9AC L_0 = ___value0;
		NtpPacket_SetDateTime64_mE26BA10DF6C3DB312C2FA0E912961C34FD5E20C6(__this, ((int32_t)40), L_0, NULL);
		// public DateTime? TransmitTimestamp { get { return GetDateTime64(40); } private set { SetDateTime64(40, value); } }
		return;
	}
}
// System.Nullable`1<System.DateTime> LiteNetLib.Utils.NtpPacket::get_DestinationTimestamp()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Nullable_1_tEADC262F7F8B8BC4CC0A003DBDD3CA7C1B63F9AC NtpPacket_get_DestinationTimestamp_m959365B0E7ED9A24A9159DC34CA1581CCD1544A9 (NtpPacket_tF37CA19271AE795B037952A3137F652EF3B95E92* __this, const RuntimeMethod* method) 
{
	{
		// public DateTime? DestinationTimestamp { get; private set; }
		Nullable_1_tEADC262F7F8B8BC4CC0A003DBDD3CA7C1B63F9AC L_0 = __this->___U3CDestinationTimestampU3Ek__BackingField_2;
		return L_0;
	}
}
// System.Void LiteNetLib.Utils.NtpPacket::set_DestinationTimestamp(System.Nullable`1<System.DateTime>)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NtpPacket_set_DestinationTimestamp_mA6061675D2ABA51638455121F12621CE523FDD5A (NtpPacket_tF37CA19271AE795B037952A3137F652EF3B95E92* __this, Nullable_1_tEADC262F7F8B8BC4CC0A003DBDD3CA7C1B63F9AC ___value0, const RuntimeMethod* method) 
{
	{
		// public DateTime? DestinationTimestamp { get; private set; }
		Nullable_1_tEADC262F7F8B8BC4CC0A003DBDD3CA7C1B63F9AC L_0 = ___value0;
		__this->___U3CDestinationTimestampU3Ek__BackingField_2 = L_0;
		return;
	}
}
// System.TimeSpan LiteNetLib.Utils.NtpPacket::get_RoundTripTime()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A NtpPacket_get_RoundTripTime_m08B2B88452DBABFE350FC60DCBCAF8A9AF6B981B (NtpPacket_tF37CA19271AE795B037952A3137F652EF3B95E92* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Nullable_1_get_Value_m5A868F663848BC21C18F056731D3AC404CE59991_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	Nullable_1_tEADC262F7F8B8BC4CC0A003DBDD3CA7C1B63F9AC V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		// CheckTimestamps();
		NtpPacket_CheckTimestamps_mD370D48027EFB0EC0A5129B2E90F545D44E5EE64(__this, NULL);
		// return (ReceiveTimestamp.Value - OriginTimestamp.Value) + (DestinationTimestamp.Value - TransmitTimestamp.Value);
		Nullable_1_tEADC262F7F8B8BC4CC0A003DBDD3CA7C1B63F9AC L_0;
		L_0 = NtpPacket_get_ReceiveTimestamp_mB169F736E742626862CEB3BAB4CFC2C9B72D59F8(__this, NULL);
		V_0 = L_0;
		DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D L_1;
		L_1 = Nullable_1_get_Value_m5A868F663848BC21C18F056731D3AC404CE59991((&V_0), Nullable_1_get_Value_m5A868F663848BC21C18F056731D3AC404CE59991_RuntimeMethod_var);
		Nullable_1_tEADC262F7F8B8BC4CC0A003DBDD3CA7C1B63F9AC L_2;
		L_2 = NtpPacket_get_OriginTimestamp_m787D1313D7FC4C68928379E18EFCA30BB0D1DC15(__this, NULL);
		V_0 = L_2;
		DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D L_3;
		L_3 = Nullable_1_get_Value_m5A868F663848BC21C18F056731D3AC404CE59991((&V_0), Nullable_1_get_Value_m5A868F663848BC21C18F056731D3AC404CE59991_RuntimeMethod_var);
		il2cpp_codegen_runtime_class_init_inline(DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D_il2cpp_TypeInfo_var);
		TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A L_4;
		L_4 = DateTime_op_Subtraction_m41335EF0E6DCD52B23C64916CB973A0B4A9E0387(L_1, L_3, NULL);
		Nullable_1_tEADC262F7F8B8BC4CC0A003DBDD3CA7C1B63F9AC L_5;
		L_5 = NtpPacket_get_DestinationTimestamp_m959365B0E7ED9A24A9159DC34CA1581CCD1544A9_inline(__this, NULL);
		V_0 = L_5;
		DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D L_6;
		L_6 = Nullable_1_get_Value_m5A868F663848BC21C18F056731D3AC404CE59991((&V_0), Nullable_1_get_Value_m5A868F663848BC21C18F056731D3AC404CE59991_RuntimeMethod_var);
		Nullable_1_tEADC262F7F8B8BC4CC0A003DBDD3CA7C1B63F9AC L_7;
		L_7 = NtpPacket_get_TransmitTimestamp_mA8AE43E3EB22AB1AB3D47F8DEB624CE634B24CA3(__this, NULL);
		V_0 = L_7;
		DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D L_8;
		L_8 = Nullable_1_get_Value_m5A868F663848BC21C18F056731D3AC404CE59991((&V_0), Nullable_1_get_Value_m5A868F663848BC21C18F056731D3AC404CE59991_RuntimeMethod_var);
		TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A L_9;
		L_9 = DateTime_op_Subtraction_m41335EF0E6DCD52B23C64916CB973A0B4A9E0387(L_6, L_8, NULL);
		il2cpp_codegen_runtime_class_init_inline(TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A_il2cpp_TypeInfo_var);
		TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A L_10;
		L_10 = TimeSpan_op_Addition_m4CA781FA121EB39944AE59C6BDD9304C42E74DFB(L_4, L_9, NULL);
		return L_10;
	}
}
// System.TimeSpan LiteNetLib.Utils.NtpPacket::get_CorrectionOffset()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A NtpPacket_get_CorrectionOffset_mA5A4BC152761ECDF0800E167C801BD1848E57020 (NtpPacket_tF37CA19271AE795B037952A3137F652EF3B95E92* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Nullable_1_get_Value_m5A868F663848BC21C18F056731D3AC404CE59991_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	Nullable_1_tEADC262F7F8B8BC4CC0A003DBDD3CA7C1B63F9AC V_0;
	memset((&V_0), 0, sizeof(V_0));
	TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		// CheckTimestamps();
		NtpPacket_CheckTimestamps_mD370D48027EFB0EC0A5129B2E90F545D44E5EE64(__this, NULL);
		// return TimeSpan.FromTicks(((ReceiveTimestamp.Value - OriginTimestamp.Value) - (DestinationTimestamp.Value - TransmitTimestamp.Value)).Ticks / 2);
		Nullable_1_tEADC262F7F8B8BC4CC0A003DBDD3CA7C1B63F9AC L_0;
		L_0 = NtpPacket_get_ReceiveTimestamp_mB169F736E742626862CEB3BAB4CFC2C9B72D59F8(__this, NULL);
		V_0 = L_0;
		DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D L_1;
		L_1 = Nullable_1_get_Value_m5A868F663848BC21C18F056731D3AC404CE59991((&V_0), Nullable_1_get_Value_m5A868F663848BC21C18F056731D3AC404CE59991_RuntimeMethod_var);
		Nullable_1_tEADC262F7F8B8BC4CC0A003DBDD3CA7C1B63F9AC L_2;
		L_2 = NtpPacket_get_OriginTimestamp_m787D1313D7FC4C68928379E18EFCA30BB0D1DC15(__this, NULL);
		V_0 = L_2;
		DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D L_3;
		L_3 = Nullable_1_get_Value_m5A868F663848BC21C18F056731D3AC404CE59991((&V_0), Nullable_1_get_Value_m5A868F663848BC21C18F056731D3AC404CE59991_RuntimeMethod_var);
		il2cpp_codegen_runtime_class_init_inline(DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D_il2cpp_TypeInfo_var);
		TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A L_4;
		L_4 = DateTime_op_Subtraction_m41335EF0E6DCD52B23C64916CB973A0B4A9E0387(L_1, L_3, NULL);
		Nullable_1_tEADC262F7F8B8BC4CC0A003DBDD3CA7C1B63F9AC L_5;
		L_5 = NtpPacket_get_DestinationTimestamp_m959365B0E7ED9A24A9159DC34CA1581CCD1544A9_inline(__this, NULL);
		V_0 = L_5;
		DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D L_6;
		L_6 = Nullable_1_get_Value_m5A868F663848BC21C18F056731D3AC404CE59991((&V_0), Nullable_1_get_Value_m5A868F663848BC21C18F056731D3AC404CE59991_RuntimeMethod_var);
		Nullable_1_tEADC262F7F8B8BC4CC0A003DBDD3CA7C1B63F9AC L_7;
		L_7 = NtpPacket_get_TransmitTimestamp_mA8AE43E3EB22AB1AB3D47F8DEB624CE634B24CA3(__this, NULL);
		V_0 = L_7;
		DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D L_8;
		L_8 = Nullable_1_get_Value_m5A868F663848BC21C18F056731D3AC404CE59991((&V_0), Nullable_1_get_Value_m5A868F663848BC21C18F056731D3AC404CE59991_RuntimeMethod_var);
		TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A L_9;
		L_9 = DateTime_op_Subtraction_m41335EF0E6DCD52B23C64916CB973A0B4A9E0387(L_6, L_8, NULL);
		il2cpp_codegen_runtime_class_init_inline(TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A_il2cpp_TypeInfo_var);
		TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A L_10;
		L_10 = TimeSpan_op_Subtraction_mFFB8933364C5E1E2187CA0605445893F2872FBB8(L_4, L_9, NULL);
		V_1 = L_10;
		int64_t L_11;
		L_11 = TimeSpan_get_Ticks_mC50131E57621F29FACC53B3241432ABB874FA1B5_inline((&V_1), NULL);
		TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A L_12;
		L_12 = TimeSpan_FromTicks_mFA529928E79B4BF5EC0265418844B196D8979A73(((int64_t)(L_11/((int64_t)2))), NULL);
		return L_12;
	}
}
// System.Void LiteNetLib.Utils.NtpPacket::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NtpPacket__ctor_m4774A3EAADB433550E3042AEE01D672807D6CAA1 (NtpPacket_tF37CA19271AE795B037952A3137F652EF3B95E92* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Nullable_1__ctor_mB17304720EA19F5469A4883827F53A75FEB492CF_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// public NtpPacket() : this(new byte[48])
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_0 = (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)SZArrayNew(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var, (uint32_t)((int32_t)48));
		NtpPacket__ctor_m42BD9C610A9863D191C040D0321813B1ED876932(__this, L_0, NULL);
		// Mode = NtpMode.Client;
		NtpPacket_set_Mode_m0B5EEEC21B94479A31FAC030B6D5B67527C64EB3(__this, 3, NULL);
		// VersionNumber = 4;
		NtpPacket_set_VersionNumber_m7B86709BF5EDAC346CFAB1EB13282EB7BA00B384(__this, 4, NULL);
		// TransmitTimestamp = DateTime.UtcNow;
		il2cpp_codegen_runtime_class_init_inline(DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D_il2cpp_TypeInfo_var);
		DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D L_1;
		L_1 = DateTime_get_UtcNow_m5D776FFEBC81592B361E4C7AF373297C5DFB46FD(NULL);
		Nullable_1_tEADC262F7F8B8BC4CC0A003DBDD3CA7C1B63F9AC L_2;
		memset((&L_2), 0, sizeof(L_2));
		Nullable_1__ctor_mB17304720EA19F5469A4883827F53A75FEB492CF((&L_2), L_1, /*hidden argument*/Nullable_1__ctor_mB17304720EA19F5469A4883827F53A75FEB492CF_RuntimeMethod_var);
		NtpPacket_set_TransmitTimestamp_m4B21A40F4CFB42E78F92894F1BDB3E4718B9FB6B(__this, L_2, NULL);
		// }
		return;
	}
}
// System.Void LiteNetLib.Utils.NtpPacket::.ctor(System.Byte[])
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NtpPacket__ctor_m42BD9C610A9863D191C040D0321813B1ED876932 (NtpPacket_tF37CA19271AE795B037952A3137F652EF3B95E92* __this, ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___bytes0, const RuntimeMethod* method) 
{
	{
		// internal NtpPacket(byte[] bytes)
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		// if (bytes.Length < 48)
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_0 = ___bytes0;
		NullCheck(L_0);
		if ((((int32_t)((int32_t)(((RuntimeArray*)L_0)->max_length))) >= ((int32_t)((int32_t)48))))
		{
			goto IL_001d;
		}
	}
	{
		// throw new ArgumentException("SNTP reply packet must be at least 48 bytes long.", "bytes");
		ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263* L_1 = (ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263_il2cpp_TypeInfo_var)));
		NullCheck(L_1);
		ArgumentException__ctor_m8F9D40CE19D19B698A70F9A258640EB52DB39B62(L_1, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral6A616A2BD726354344808434F427B73FA98BDD24)), ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral77B615B8ED1ABB8FC1395D85A5AE524A9789D947)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_1, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NtpPacket__ctor_m42BD9C610A9863D191C040D0321813B1ED876932_RuntimeMethod_var)));
	}

IL_001d:
	{
		// Bytes = bytes;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_2 = ___bytes0;
		__this->___U3CBytesU3Ek__BackingField_1 = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CBytesU3Ek__BackingField_1), (void*)L_2);
		// }
		return;
	}
}
// LiteNetLib.Utils.NtpPacket LiteNetLib.Utils.NtpPacket::FromServerResponse(System.Byte[],System.DateTime)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR NtpPacket_tF37CA19271AE795B037952A3137F652EF3B95E92* NtpPacket_FromServerResponse_mA71FAC35B31EC480A4D7D4AB654D9238C5E05905 (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___bytes0, DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D ___destinationTimestamp1, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&NtpPacket_tF37CA19271AE795B037952A3137F652EF3B95E92_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Nullable_1__ctor_mB17304720EA19F5469A4883827F53A75FEB492CF_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// return new NtpPacket(bytes) { DestinationTimestamp = destinationTimestamp };
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_0 = ___bytes0;
		NtpPacket_tF37CA19271AE795B037952A3137F652EF3B95E92* L_1 = (NtpPacket_tF37CA19271AE795B037952A3137F652EF3B95E92*)il2cpp_codegen_object_new(NtpPacket_tF37CA19271AE795B037952A3137F652EF3B95E92_il2cpp_TypeInfo_var);
		NullCheck(L_1);
		NtpPacket__ctor_m42BD9C610A9863D191C040D0321813B1ED876932(L_1, L_0, NULL);
		NtpPacket_tF37CA19271AE795B037952A3137F652EF3B95E92* L_2 = L_1;
		DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D L_3 = ___destinationTimestamp1;
		Nullable_1_tEADC262F7F8B8BC4CC0A003DBDD3CA7C1B63F9AC L_4;
		memset((&L_4), 0, sizeof(L_4));
		Nullable_1__ctor_mB17304720EA19F5469A4883827F53A75FEB492CF((&L_4), L_3, /*hidden argument*/Nullable_1__ctor_mB17304720EA19F5469A4883827F53A75FEB492CF_RuntimeMethod_var);
		NullCheck(L_2);
		NtpPacket_set_DestinationTimestamp_mA6061675D2ABA51638455121F12621CE523FDD5A_inline(L_2, L_4, NULL);
		return L_2;
	}
}
// System.Void LiteNetLib.Utils.NtpPacket::ValidateRequest()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NtpPacket_ValidateRequest_m63E690888AB011E8D4C6AA93926598F6AAD343BE (NtpPacket_tF37CA19271AE795B037952A3137F652EF3B95E92* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Nullable_1_get_HasValue_m092C73DCE052BFB5C60A39EF9F4E3401AA95221C_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	Nullable_1_tEADC262F7F8B8BC4CC0A003DBDD3CA7C1B63F9AC V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		// if (Mode != NtpMode.Client)
		int32_t L_0;
		L_0 = NtpPacket_get_Mode_m301D434C5382328D6E1BEAE493ABEF3B3CE89BBA(__this, NULL);
		if ((((int32_t)L_0) == ((int32_t)3)))
		{
			goto IL_0014;
		}
	}
	{
		// throw new InvalidOperationException("This is not a request SNTP packet.");
		InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB* L_1 = (InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB_il2cpp_TypeInfo_var)));
		NullCheck(L_1);
		InvalidOperationException__ctor_mE4CB6F4712AB6D99A2358FBAE2E052B3EE976162(L_1, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralA9FFA609F3AF81CBA0BEF31B92E98F7C0B64DA06)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_1, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NtpPacket_ValidateRequest_m63E690888AB011E8D4C6AA93926598F6AAD343BE_RuntimeMethod_var)));
	}

IL_0014:
	{
		// if (VersionNumber == 0)
		int32_t L_2;
		L_2 = NtpPacket_get_VersionNumber_m8BBA6DBFF2942AFA98F08707E5C2DF9402ACBDEB(__this, NULL);
		if (L_2)
		{
			goto IL_0027;
		}
	}
	{
		// throw new InvalidOperationException("Protocol version of the request is not specified.");
		InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB* L_3 = (InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB_il2cpp_TypeInfo_var)));
		NullCheck(L_3);
		InvalidOperationException__ctor_mE4CB6F4712AB6D99A2358FBAE2E052B3EE976162(L_3, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral868EE9733DC26168EACBAC88A44D9E3DE178486F)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_3, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NtpPacket_ValidateRequest_m63E690888AB011E8D4C6AA93926598F6AAD343BE_RuntimeMethod_var)));
	}

IL_0027:
	{
		// if (TransmitTimestamp == null)
		Nullable_1_tEADC262F7F8B8BC4CC0A003DBDD3CA7C1B63F9AC L_4;
		L_4 = NtpPacket_get_TransmitTimestamp_mA8AE43E3EB22AB1AB3D47F8DEB624CE634B24CA3(__this, NULL);
		V_0 = L_4;
		bool L_5;
		L_5 = Nullable_1_get_HasValue_m092C73DCE052BFB5C60A39EF9F4E3401AA95221C_inline((&V_0), Nullable_1_get_HasValue_m092C73DCE052BFB5C60A39EF9F4E3401AA95221C_RuntimeMethod_var);
		if (L_5)
		{
			goto IL_0042;
		}
	}
	{
		// throw new InvalidOperationException("TransmitTimestamp must be set in request packet.");
		InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB* L_6 = (InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB_il2cpp_TypeInfo_var)));
		NullCheck(L_6);
		InvalidOperationException__ctor_mE4CB6F4712AB6D99A2358FBAE2E052B3EE976162(L_6, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralC90CADE37127E5B15A609569628F61937A864B5A)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_6, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NtpPacket_ValidateRequest_m63E690888AB011E8D4C6AA93926598F6AAD343BE_RuntimeMethod_var)));
	}

IL_0042:
	{
		// }
		return;
	}
}
// System.Void LiteNetLib.Utils.NtpPacket::ValidateReply()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NtpPacket_ValidateReply_m871B39CA5A4182A368955E759666202F030E0F58 (NtpPacket_tF37CA19271AE795B037952A3137F652EF3B95E92* __this, const RuntimeMethod* method) 
{
	{
		// if (Mode != NtpMode.Server)
		int32_t L_0;
		L_0 = NtpPacket_get_Mode_m301D434C5382328D6E1BEAE493ABEF3B3CE89BBA(__this, NULL);
		if ((((int32_t)L_0) == ((int32_t)4)))
		{
			goto IL_0014;
		}
	}
	{
		// throw new InvalidOperationException("This is not a reply SNTP packet.");
		InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB* L_1 = (InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB_il2cpp_TypeInfo_var)));
		NullCheck(L_1);
		InvalidOperationException__ctor_mE4CB6F4712AB6D99A2358FBAE2E052B3EE976162(L_1, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral06C05B24B8AC51D50C3AA294D70C5E1E28E9A0E3)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_1, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NtpPacket_ValidateReply_m871B39CA5A4182A368955E759666202F030E0F58_RuntimeMethod_var)));
	}

IL_0014:
	{
		// if (VersionNumber == 0)
		int32_t L_2;
		L_2 = NtpPacket_get_VersionNumber_m8BBA6DBFF2942AFA98F08707E5C2DF9402ACBDEB(__this, NULL);
		if (L_2)
		{
			goto IL_0027;
		}
	}
	{
		// throw new InvalidOperationException("Protocol version of the reply is not specified.");
		InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB* L_3 = (InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB_il2cpp_TypeInfo_var)));
		NullCheck(L_3);
		InvalidOperationException__ctor_mE4CB6F4712AB6D99A2358FBAE2E052B3EE976162(L_3, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral88F1D02FAC5553C102E3A23C9A363D07A9C89238)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_3, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NtpPacket_ValidateReply_m871B39CA5A4182A368955E759666202F030E0F58_RuntimeMethod_var)));
	}

IL_0027:
	{
		// if (Stratum == 0)
		int32_t L_4;
		L_4 = NtpPacket_get_Stratum_mA87F41632A21B205B8EBC172DC69BE6586764D9D(__this, NULL);
		if (L_4)
		{
			goto IL_004a;
		}
	}
	{
		// throw new InvalidOperationException(string.Format("Received Kiss-o'-Death SNTP packet with code 0x{0:x}.", ReferenceId));
		uint32_t L_5;
		L_5 = NtpPacket_get_ReferenceId_m767F85AC132891BC56829857A5F613F68B510152(__this, NULL);
		uint32_t L_6 = L_5;
		RuntimeObject* L_7 = Box(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&UInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B_il2cpp_TypeInfo_var)), &L_6);
		String_t* L_8;
		L_8 = String_Format_m8C122B26BC5AA10E2550AECA16E57DAE10F07E30(((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral10F509F15EC5C6178F7787F554341A601F904E65)), L_7, NULL);
		InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB* L_9 = (InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB_il2cpp_TypeInfo_var)));
		NullCheck(L_9);
		InvalidOperationException__ctor_mE4CB6F4712AB6D99A2358FBAE2E052B3EE976162(L_9, L_8, NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_9, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NtpPacket_ValidateReply_m871B39CA5A4182A368955E759666202F030E0F58_RuntimeMethod_var)));
	}

IL_004a:
	{
		// if (LeapIndicator == NtpLeapIndicator.AlarmCondition)
		int32_t L_10;
		L_10 = NtpPacket_get_LeapIndicator_m2EF17809EDB88F7D10BF8848FFAB2A96BCF8C5DE(__this, NULL);
		if ((!(((uint32_t)L_10) == ((uint32_t)3))))
		{
			goto IL_005e;
		}
	}
	{
		// throw new InvalidOperationException("SNTP server has unsynchronized clock.");
		InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB* L_11 = (InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB_il2cpp_TypeInfo_var)));
		NullCheck(L_11);
		InvalidOperationException__ctor_mE4CB6F4712AB6D99A2358FBAE2E052B3EE976162(L_11, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralCB77237BCD39404C795BCB8688C2D3153355EBA0)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_11, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NtpPacket_ValidateReply_m871B39CA5A4182A368955E759666202F030E0F58_RuntimeMethod_var)));
	}

IL_005e:
	{
		// CheckTimestamps();
		NtpPacket_CheckTimestamps_mD370D48027EFB0EC0A5129B2E90F545D44E5EE64(__this, NULL);
		// }
		return;
	}
}
// System.Void LiteNetLib.Utils.NtpPacket::CheckTimestamps()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NtpPacket_CheckTimestamps_mD370D48027EFB0EC0A5129B2E90F545D44E5EE64 (NtpPacket_tF37CA19271AE795B037952A3137F652EF3B95E92* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Nullable_1_get_HasValue_m092C73DCE052BFB5C60A39EF9F4E3401AA95221C_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	Nullable_1_tEADC262F7F8B8BC4CC0A003DBDD3CA7C1B63F9AC V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		// if (OriginTimestamp == null)
		Nullable_1_tEADC262F7F8B8BC4CC0A003DBDD3CA7C1B63F9AC L_0;
		L_0 = NtpPacket_get_OriginTimestamp_m787D1313D7FC4C68928379E18EFCA30BB0D1DC15(__this, NULL);
		V_0 = L_0;
		bool L_1;
		L_1 = Nullable_1_get_HasValue_m092C73DCE052BFB5C60A39EF9F4E3401AA95221C_inline((&V_0), Nullable_1_get_HasValue_m092C73DCE052BFB5C60A39EF9F4E3401AA95221C_RuntimeMethod_var);
		if (L_1)
		{
			goto IL_001b;
		}
	}
	{
		// throw new InvalidOperationException("Origin timestamp is missing.");
		InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB* L_2 = (InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB_il2cpp_TypeInfo_var)));
		NullCheck(L_2);
		InvalidOperationException__ctor_mE4CB6F4712AB6D99A2358FBAE2E052B3EE976162(L_2, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralF39AFC06F0127ED41BF2DBB29047355062D8065C)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_2, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NtpPacket_CheckTimestamps_mD370D48027EFB0EC0A5129B2E90F545D44E5EE64_RuntimeMethod_var)));
	}

IL_001b:
	{
		// if (ReceiveTimestamp == null)
		Nullable_1_tEADC262F7F8B8BC4CC0A003DBDD3CA7C1B63F9AC L_3;
		L_3 = NtpPacket_get_ReceiveTimestamp_mB169F736E742626862CEB3BAB4CFC2C9B72D59F8(__this, NULL);
		V_0 = L_3;
		bool L_4;
		L_4 = Nullable_1_get_HasValue_m092C73DCE052BFB5C60A39EF9F4E3401AA95221C_inline((&V_0), Nullable_1_get_HasValue_m092C73DCE052BFB5C60A39EF9F4E3401AA95221C_RuntimeMethod_var);
		if (L_4)
		{
			goto IL_0036;
		}
	}
	{
		// throw new InvalidOperationException("Receive timestamp is missing.");
		InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB* L_5 = (InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB_il2cpp_TypeInfo_var)));
		NullCheck(L_5);
		InvalidOperationException__ctor_mE4CB6F4712AB6D99A2358FBAE2E052B3EE976162(L_5, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralF62357F27A8ABD4B2897C89CFE2ABB3A9468CB41)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_5, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NtpPacket_CheckTimestamps_mD370D48027EFB0EC0A5129B2E90F545D44E5EE64_RuntimeMethod_var)));
	}

IL_0036:
	{
		// if (TransmitTimestamp == null)
		Nullable_1_tEADC262F7F8B8BC4CC0A003DBDD3CA7C1B63F9AC L_6;
		L_6 = NtpPacket_get_TransmitTimestamp_mA8AE43E3EB22AB1AB3D47F8DEB624CE634B24CA3(__this, NULL);
		V_0 = L_6;
		bool L_7;
		L_7 = Nullable_1_get_HasValue_m092C73DCE052BFB5C60A39EF9F4E3401AA95221C_inline((&V_0), Nullable_1_get_HasValue_m092C73DCE052BFB5C60A39EF9F4E3401AA95221C_RuntimeMethod_var);
		if (L_7)
		{
			goto IL_0051;
		}
	}
	{
		// throw new InvalidOperationException("Transmit timestamp is missing.");
		InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB* L_8 = (InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB_il2cpp_TypeInfo_var)));
		NullCheck(L_8);
		InvalidOperationException__ctor_mE4CB6F4712AB6D99A2358FBAE2E052B3EE976162(L_8, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral49BEFE76EF933CC018C51D77F66B724C36F2CE09)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_8, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NtpPacket_CheckTimestamps_mD370D48027EFB0EC0A5129B2E90F545D44E5EE64_RuntimeMethod_var)));
	}

IL_0051:
	{
		// if (DestinationTimestamp == null)
		Nullable_1_tEADC262F7F8B8BC4CC0A003DBDD3CA7C1B63F9AC L_9;
		L_9 = NtpPacket_get_DestinationTimestamp_m959365B0E7ED9A24A9159DC34CA1581CCD1544A9_inline(__this, NULL);
		V_0 = L_9;
		bool L_10;
		L_10 = Nullable_1_get_HasValue_m092C73DCE052BFB5C60A39EF9F4E3401AA95221C_inline((&V_0), Nullable_1_get_HasValue_m092C73DCE052BFB5C60A39EF9F4E3401AA95221C_RuntimeMethod_var);
		if (L_10)
		{
			goto IL_006c;
		}
	}
	{
		// throw new InvalidOperationException("Destination timestamp is missing.");
		InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB* L_11 = (InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB_il2cpp_TypeInfo_var)));
		NullCheck(L_11);
		InvalidOperationException__ctor_mE4CB6F4712AB6D99A2358FBAE2E052B3EE976162(L_11, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral3B19916E896E08666992C24EA969EE6DE3B95722)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_11, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NtpPacket_CheckTimestamps_mD370D48027EFB0EC0A5129B2E90F545D44E5EE64_RuntimeMethod_var)));
	}

IL_006c:
	{
		// }
		return;
	}
}
// System.Nullable`1<System.DateTime> LiteNetLib.Utils.NtpPacket::GetDateTime64(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Nullable_1_tEADC262F7F8B8BC4CC0A003DBDD3CA7C1B63F9AC NtpPacket_GetDateTime64_m486CD5CC1B530B599628C3FE1E7F0D4919DADC53 (NtpPacket_tF37CA19271AE795B037952A3137F652EF3B95E92* __this, int32_t ___offset0, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Convert_t7097FF336D592F7C06D88A98349A44646F91EFFC_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&NtpPacket_tF37CA19271AE795B037952A3137F652EF3B95E92_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Nullable_1__ctor_mB17304720EA19F5469A4883827F53A75FEB492CF_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	uint64_t V_0 = 0;
	Nullable_1_tEADC262F7F8B8BC4CC0A003DBDD3CA7C1B63F9AC V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		// var field = GetUInt64BE(offset);
		int32_t L_0 = ___offset0;
		uint64_t L_1;
		L_1 = NtpPacket_GetUInt64BE_m93EC98DF49734420FC1680733687BCA664199B43(__this, L_0, NULL);
		V_0 = L_1;
		// if (field == 0)
		uint64_t L_2 = V_0;
		if (L_2)
		{
			goto IL_0015;
		}
	}
	{
		// return null;
		il2cpp_codegen_initobj((&V_1), sizeof(Nullable_1_tEADC262F7F8B8BC4CC0A003DBDD3CA7C1B63F9AC));
		Nullable_1_tEADC262F7F8B8BC4CC0A003DBDD3CA7C1B63F9AC L_3 = V_1;
		return L_3;
	}

IL_0015:
	{
		// return new DateTime(Epoch.Ticks + Convert.ToInt64(field * (1.0 / (1L << 32) * 10000000.0)));
		il2cpp_codegen_runtime_class_init_inline(NtpPacket_tF37CA19271AE795B037952A3137F652EF3B95E92_il2cpp_TypeInfo_var);
		int64_t L_4;
		L_4 = DateTime_get_Ticks_mC2CF04ED0EAB425C72C2532FFC5743777F3C93A6((&((NtpPacket_tF37CA19271AE795B037952A3137F652EF3B95E92_StaticFields*)il2cpp_codegen_static_fields_for(NtpPacket_tF37CA19271AE795B037952A3137F652EF3B95E92_il2cpp_TypeInfo_var))->___Epoch_0), NULL);
		uint64_t L_5 = V_0;
		il2cpp_codegen_runtime_class_init_inline(Convert_t7097FF336D592F7C06D88A98349A44646F91EFFC_il2cpp_TypeInfo_var);
		int64_t L_6;
		L_6 = Convert_ToInt64_m5B707D520332D512D2B81C10D2F4044FA468C3A4(((double)il2cpp_codegen_multiply(((double)((double)(uint64_t)L_5)), (0.0023283064365386963))), NULL);
		DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D L_7;
		memset((&L_7), 0, sizeof(L_7));
		DateTime__ctor_m64AFCE84ABB24698256EB9F635EFD0A221823441((&L_7), ((int64_t)il2cpp_codegen_add(L_4, L_6)), /*hidden argument*/NULL);
		Nullable_1_tEADC262F7F8B8BC4CC0A003DBDD3CA7C1B63F9AC L_8;
		memset((&L_8), 0, sizeof(L_8));
		Nullable_1__ctor_mB17304720EA19F5469A4883827F53A75FEB492CF((&L_8), L_7, /*hidden argument*/Nullable_1__ctor_mB17304720EA19F5469A4883827F53A75FEB492CF_RuntimeMethod_var);
		return L_8;
	}
}
// System.Void LiteNetLib.Utils.NtpPacket::SetDateTime64(System.Int32,System.Nullable`1<System.DateTime>)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NtpPacket_SetDateTime64_mE26BA10DF6C3DB312C2FA0E912961C34FD5E20C6 (NtpPacket_tF37CA19271AE795B037952A3137F652EF3B95E92* __this, int32_t ___offset0, Nullable_1_tEADC262F7F8B8BC4CC0A003DBDD3CA7C1B63F9AC ___value1, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Convert_t7097FF336D592F7C06D88A98349A44646F91EFFC_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&NtpPacket_tF37CA19271AE795B037952A3137F652EF3B95E92_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Nullable_1_get_HasValue_m092C73DCE052BFB5C60A39EF9F4E3401AA95221C_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Nullable_1_get_Value_m5A868F663848BC21C18F056731D3AC404CE59991_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D V_0;
	memset((&V_0), 0, sizeof(V_0));
	int32_t G_B2_0 = 0;
	NtpPacket_tF37CA19271AE795B037952A3137F652EF3B95E92* G_B2_1 = NULL;
	int32_t G_B1_0 = 0;
	NtpPacket_tF37CA19271AE795B037952A3137F652EF3B95E92* G_B1_1 = NULL;
	uint64_t G_B3_0 = 0;
	int32_t G_B3_1 = 0;
	NtpPacket_tF37CA19271AE795B037952A3137F652EF3B95E92* G_B3_2 = NULL;
	{
		// SetUInt64BE(offset, value == null ? 0 : Convert.ToUInt64((value.Value.Ticks - Epoch.Ticks) * (0.0000001 * (1L << 32))));
		int32_t L_0 = ___offset0;
		bool L_1;
		L_1 = Nullable_1_get_HasValue_m092C73DCE052BFB5C60A39EF9F4E3401AA95221C_inline((&___value1), Nullable_1_get_HasValue_m092C73DCE052BFB5C60A39EF9F4E3401AA95221C_RuntimeMethod_var);
		G_B1_0 = L_0;
		G_B1_1 = __this;
		if (!L_1)
		{
			G_B2_0 = L_0;
			G_B2_1 = __this;
			goto IL_0037;
		}
	}
	{
		DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D L_2;
		L_2 = Nullable_1_get_Value_m5A868F663848BC21C18F056731D3AC404CE59991((&___value1), Nullable_1_get_Value_m5A868F663848BC21C18F056731D3AC404CE59991_RuntimeMethod_var);
		V_0 = L_2;
		int64_t L_3;
		L_3 = DateTime_get_Ticks_mC2CF04ED0EAB425C72C2532FFC5743777F3C93A6((&V_0), NULL);
		il2cpp_codegen_runtime_class_init_inline(NtpPacket_tF37CA19271AE795B037952A3137F652EF3B95E92_il2cpp_TypeInfo_var);
		int64_t L_4;
		L_4 = DateTime_get_Ticks_mC2CF04ED0EAB425C72C2532FFC5743777F3C93A6((&((NtpPacket_tF37CA19271AE795B037952A3137F652EF3B95E92_StaticFields*)il2cpp_codegen_static_fields_for(NtpPacket_tF37CA19271AE795B037952A3137F652EF3B95E92_il2cpp_TypeInfo_var))->___Epoch_0), NULL);
		il2cpp_codegen_runtime_class_init_inline(Convert_t7097FF336D592F7C06D88A98349A44646F91EFFC_il2cpp_TypeInfo_var);
		uint64_t L_5;
		L_5 = Convert_ToUInt64_m4990F2CE28C4CE3079D458BA578EFBA46D875B3E(((double)il2cpp_codegen_multiply(((double)((int64_t)il2cpp_codegen_subtract(L_3, L_4))), (429.49672959999998))), NULL);
		G_B3_0 = L_5;
		G_B3_1 = G_B1_0;
		G_B3_2 = G_B1_1;
		goto IL_0039;
	}

IL_0037:
	{
		G_B3_0 = ((uint64_t)(((int64_t)0)));
		G_B3_1 = G_B2_0;
		G_B3_2 = G_B2_1;
	}

IL_0039:
	{
		NullCheck(G_B3_2);
		NtpPacket_SetUInt64BE_mA70D52969F236DEA0DDA42F63D4B14B5DDDBDD9F(G_B3_2, G_B3_1, G_B3_0, NULL);
		// }
		return;
	}
}
// System.TimeSpan LiteNetLib.Utils.NtpPacket::GetTimeSpan32(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A NtpPacket_GetTimeSpan32_m9FFAC53FB307FD2C01EDB48D503D3030500FEC41 (NtpPacket_tF37CA19271AE795B037952A3137F652EF3B95E92* __this, int32_t ___offset0, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// return TimeSpan.FromSeconds(GetInt32BE(offset) / (double)(1 << 16));
		int32_t L_0 = ___offset0;
		int32_t L_1;
		L_1 = NtpPacket_GetInt32BE_mF60AB8BE45EA446257393803636A541FD724796B(__this, L_0, NULL);
		il2cpp_codegen_runtime_class_init_inline(TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A_il2cpp_TypeInfo_var);
		TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A L_2;
		L_2 = TimeSpan_FromSeconds_mE585CC8180040ED064DC8B6546E6C94A129BFFC5(((double)(((double)L_1)/(65536.0))), NULL);
		return L_2;
	}
}
// System.UInt64 LiteNetLib.Utils.NtpPacket::GetUInt64BE(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint64_t NtpPacket_GetUInt64BE_m93EC98DF49734420FC1680733687BCA664199B43 (NtpPacket_tF37CA19271AE795B037952A3137F652EF3B95E92* __this, int32_t ___offset0, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&BitConverter_t6E99605185963BC12B3D369E13F2B88997E64A27_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&NtpPacket_tF37CA19271AE795B037952A3137F652EF3B95E92_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// return SwapEndianness(BitConverter.ToUInt64(Bytes, offset));
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_0;
		L_0 = NtpPacket_get_Bytes_m6E68BBD8630A83EEB78A27E590D38FF01C83E6C3_inline(__this, NULL);
		int32_t L_1 = ___offset0;
		il2cpp_codegen_runtime_class_init_inline(BitConverter_t6E99605185963BC12B3D369E13F2B88997E64A27_il2cpp_TypeInfo_var);
		uint64_t L_2;
		L_2 = BitConverter_ToUInt64_mD74DF4F6535FC635EB8697FC5175A7D99E3C62BF(L_0, L_1, NULL);
		il2cpp_codegen_runtime_class_init_inline(NtpPacket_tF37CA19271AE795B037952A3137F652EF3B95E92_il2cpp_TypeInfo_var);
		uint64_t L_3;
		L_3 = NtpPacket_SwapEndianness_mE50FA3DE29D75D5BE0BDD499E87183E664A3A14F(L_2, NULL);
		return L_3;
	}
}
// System.Void LiteNetLib.Utils.NtpPacket::SetUInt64BE(System.Int32,System.UInt64)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NtpPacket_SetUInt64BE_mA70D52969F236DEA0DDA42F63D4B14B5DDDBDD9F (NtpPacket_tF37CA19271AE795B037952A3137F652EF3B95E92* __this, int32_t ___offset0, uint64_t ___value1, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&NtpPacket_tF37CA19271AE795B037952A3137F652EF3B95E92_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// FastBitConverter.GetBytes(Bytes, offset, SwapEndianness(value));
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_0;
		L_0 = NtpPacket_get_Bytes_m6E68BBD8630A83EEB78A27E590D38FF01C83E6C3_inline(__this, NULL);
		int32_t L_1 = ___offset0;
		uint64_t L_2 = ___value1;
		il2cpp_codegen_runtime_class_init_inline(NtpPacket_tF37CA19271AE795B037952A3137F652EF3B95E92_il2cpp_TypeInfo_var);
		uint64_t L_3;
		L_3 = NtpPacket_SwapEndianness_mE50FA3DE29D75D5BE0BDD499E87183E664A3A14F(L_2, NULL);
		FastBitConverter_GetBytes_m3AB77751A0F1D6246D7AC61C8EC6CE7AC7B0D203_inline(L_0, L_1, L_3, NULL);
		// }
		return;
	}
}
// System.Int32 LiteNetLib.Utils.NtpPacket::GetInt32BE(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t NtpPacket_GetInt32BE_mF60AB8BE45EA446257393803636A541FD724796B (NtpPacket_tF37CA19271AE795B037952A3137F652EF3B95E92* __this, int32_t ___offset0, const RuntimeMethod* method) 
{
	{
		// return (int)GetUInt32BE(offset);
		int32_t L_0 = ___offset0;
		uint32_t L_1;
		L_1 = NtpPacket_GetUInt32BE_m105480B326D4407FB1FBA477AE2B12D22A38F0D6(__this, L_0, NULL);
		return L_1;
	}
}
// System.UInt32 LiteNetLib.Utils.NtpPacket::GetUInt32BE(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint32_t NtpPacket_GetUInt32BE_m105480B326D4407FB1FBA477AE2B12D22A38F0D6 (NtpPacket_tF37CA19271AE795B037952A3137F652EF3B95E92* __this, int32_t ___offset0, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&BitConverter_t6E99605185963BC12B3D369E13F2B88997E64A27_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&NtpPacket_tF37CA19271AE795B037952A3137F652EF3B95E92_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// return SwapEndianness(BitConverter.ToUInt32(Bytes, offset));
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_0;
		L_0 = NtpPacket_get_Bytes_m6E68BBD8630A83EEB78A27E590D38FF01C83E6C3_inline(__this, NULL);
		int32_t L_1 = ___offset0;
		il2cpp_codegen_runtime_class_init_inline(BitConverter_t6E99605185963BC12B3D369E13F2B88997E64A27_il2cpp_TypeInfo_var);
		uint32_t L_2;
		L_2 = BitConverter_ToUInt32_m7EFCF9D77ACD0F2DA29F69587DDF6130391E6164(L_0, L_1, NULL);
		il2cpp_codegen_runtime_class_init_inline(NtpPacket_tF37CA19271AE795B037952A3137F652EF3B95E92_il2cpp_TypeInfo_var);
		uint32_t L_3;
		L_3 = NtpPacket_SwapEndianness_m19BF014CC8A80CCD9BFAA9520ABDEFE36A7A6F21(L_2, NULL);
		return L_3;
	}
}
// System.UInt32 LiteNetLib.Utils.NtpPacket::SwapEndianness(System.UInt32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint32_t NtpPacket_SwapEndianness_m19BF014CC8A80CCD9BFAA9520ABDEFE36A7A6F21 (uint32_t ___x0, const RuntimeMethod* method) 
{
	{
		// return ((x & 0xff) << 24) | ((x & 0xff00) << 8) | ((x & 0xff0000) >> 8) | ((x & 0xff000000) >> 24);
		uint32_t L_0 = ___x0;
		uint32_t L_1 = ___x0;
		uint32_t L_2 = ___x0;
		uint32_t L_3 = ___x0;
		return ((int32_t)(((int32_t)(((int32_t)(((int32_t)(((int32_t)((int32_t)L_0&((int32_t)255)))<<((int32_t)24)))|((int32_t)(((int32_t)((int32_t)L_1&((int32_t)65280)))<<8))))|((int32_t)((uint32_t)((int32_t)((int32_t)L_2&((int32_t)16711680)))>>8))))|((int32_t)((uint32_t)((int32_t)((int32_t)L_3&((int32_t)-16777216)))>>((int32_t)24)))));
	}
}
// System.UInt64 LiteNetLib.Utils.NtpPacket::SwapEndianness(System.UInt64)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint64_t NtpPacket_SwapEndianness_mE50FA3DE29D75D5BE0BDD499E87183E664A3A14F (uint64_t ___x0, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&NtpPacket_tF37CA19271AE795B037952A3137F652EF3B95E92_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// return ((ulong)SwapEndianness((uint)x) << 32) | SwapEndianness((uint)(x >> 32));
		uint64_t L_0 = ___x0;
		il2cpp_codegen_runtime_class_init_inline(NtpPacket_tF37CA19271AE795B037952A3137F652EF3B95E92_il2cpp_TypeInfo_var);
		uint32_t L_1;
		L_1 = NtpPacket_SwapEndianness_m19BF014CC8A80CCD9BFAA9520ABDEFE36A7A6F21(((int32_t)(uint32_t)L_0), NULL);
		uint64_t L_2 = ___x0;
		uint32_t L_3;
		L_3 = NtpPacket_SwapEndianness_m19BF014CC8A80CCD9BFAA9520ABDEFE36A7A6F21(((int32_t)(uint32_t)((int64_t)((uint64_t)L_2>>((int32_t)32)))), NULL);
		return ((int64_t)(((int64_t)(((int64_t)(uint64_t)L_1)<<((int32_t)32)))|((int64_t)(uint64_t)L_3)));
	}
}
// System.Void LiteNetLib.Utils.NtpPacket::.cctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NtpPacket__cctor_m927B919AC9DC54FA7D03DA4345C6E044A96629A5 (const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&NtpPacket_tF37CA19271AE795B037952A3137F652EF3B95E92_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// private static readonly DateTime Epoch = new DateTime(1900, 1, 1);
		DateTime_t66193957C73913903DDAD89FEDC46139BCA5802D L_0;
		memset((&L_0), 0, sizeof(L_0));
		DateTime__ctor_mA3BF7CE28807F0A02634FD43913FAAFD989CEE88((&L_0), ((int32_t)1900), 1, 1, /*hidden argument*/NULL);
		((NtpPacket_tF37CA19271AE795B037952A3137F652EF3B95E92_StaticFields*)il2cpp_codegen_static_fields_for(NtpPacket_tF37CA19271AE795B037952A3137F652EF3B95E92_il2cpp_TypeInfo_var))->___Epoch_0 = L_0;
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void LiteNetLib.Utils.NtpRequest::.ctor(System.Net.IPEndPoint)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NtpRequest__ctor_m05CE1746EBFD1FE073746A5E3037943A0CB04ACF (NtpRequest_tC0955A6C23AED87A1C51BB5D441709CE3F6DDF1F* __this, IPEndPoint_t2F09CBA7A808B67724B4E2954EEDC46D910F4ECB* ___endPoint0, const RuntimeMethod* method) 
{
	{
		// private int _resendTime = ResendTimer;
		__this->____resendTime_4 = ((int32_t)1000);
		// public NtpRequest(IPEndPoint endPoint)
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		// _ntpEndPoint = endPoint;
		IPEndPoint_t2F09CBA7A808B67724B4E2954EEDC46D910F4ECB* L_0 = ___endPoint0;
		__this->____ntpEndPoint_3 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____ntpEndPoint_3), (void*)L_0);
		// }
		return;
	}
}
// System.Boolean LiteNetLib.Utils.NtpRequest::get_NeedToKill()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool NtpRequest_get_NeedToKill_mB9F3A4C7571EC3D0B001EDD1D0E5609A3DFD0049 (NtpRequest_tC0955A6C23AED87A1C51BB5D441709CE3F6DDF1F* __this, const RuntimeMethod* method) 
{
	{
		// public bool NeedToKill => _killTime >= KillTimer;
		int32_t L_0 = __this->____killTime_5;
		return (bool)((((int32_t)((((int32_t)L_0) < ((int32_t)((int32_t)10000)))? 1 : 0)) == ((int32_t)0))? 1 : 0);
	}
}
// System.Boolean LiteNetLib.Utils.NtpRequest::Send(System.Net.Sockets.Socket,System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool NtpRequest_Send_mE41FFAF619AD70AB7C43E8D65587D4B17B831AE2 (NtpRequest_tC0955A6C23AED87A1C51BB5D441709CE3F6DDF1F* __this, Socket_t1F49472CDA22B581C29A258225ABF3ADA9DED67E* ___socket0, int32_t ___time1, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&NtpPacket_tF37CA19271AE795B037952A3137F652EF3B95E92_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	NtpPacket_tF37CA19271AE795B037952A3137F652EF3B95E92* V_0 = NULL;
	bool V_1 = false;
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		// _resendTime += time;
		int32_t L_0 = __this->____resendTime_4;
		int32_t L_1 = ___time1;
		__this->____resendTime_4 = ((int32_t)il2cpp_codegen_add(L_0, L_1));
		// _killTime += time;
		int32_t L_2 = __this->____killTime_5;
		int32_t L_3 = ___time1;
		__this->____killTime_5 = ((int32_t)il2cpp_codegen_add(L_2, L_3));
		// if (_resendTime < ResendTimer)
		int32_t L_4 = __this->____resendTime_4;
		if ((((int32_t)L_4) >= ((int32_t)((int32_t)1000))))
		{
			goto IL_002b;
		}
	}
	{
		// return false;
		return (bool)0;
	}

IL_002b:
	{
		// var packet = new NtpPacket();
		NtpPacket_tF37CA19271AE795B037952A3137F652EF3B95E92* L_5 = (NtpPacket_tF37CA19271AE795B037952A3137F652EF3B95E92*)il2cpp_codegen_object_new(NtpPacket_tF37CA19271AE795B037952A3137F652EF3B95E92_il2cpp_TypeInfo_var);
		NullCheck(L_5);
		NtpPacket__ctor_m4774A3EAADB433550E3042AEE01D672807D6CAA1(L_5, NULL);
		V_0 = L_5;
	}
	try
	{// begin try (depth: 1)
		// int sendCount = socket.SendTo(packet.Bytes, 0, packet.Bytes.Length, SocketFlags.None, _ntpEndPoint);
		Socket_t1F49472CDA22B581C29A258225ABF3ADA9DED67E* L_6 = ___socket0;
		NtpPacket_tF37CA19271AE795B037952A3137F652EF3B95E92* L_7 = V_0;
		NullCheck(L_7);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_8;
		L_8 = NtpPacket_get_Bytes_m6E68BBD8630A83EEB78A27E590D38FF01C83E6C3_inline(L_7, NULL);
		NtpPacket_tF37CA19271AE795B037952A3137F652EF3B95E92* L_9 = V_0;
		NullCheck(L_9);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_10;
		L_10 = NtpPacket_get_Bytes_m6E68BBD8630A83EEB78A27E590D38FF01C83E6C3_inline(L_9, NULL);
		NullCheck(L_10);
		IPEndPoint_t2F09CBA7A808B67724B4E2954EEDC46D910F4ECB* L_11 = __this->____ntpEndPoint_3;
		NullCheck(L_6);
		int32_t L_12;
		L_12 = Socket_SendTo_m07A6D82F7ABD61B6B9C87931035FCF793AA3D6F6(L_6, L_8, 0, ((int32_t)(((RuntimeArray*)L_10)->max_length)), 0, L_11, NULL);
		// return sendCount == packet.Bytes.Length;
		NtpPacket_tF37CA19271AE795B037952A3137F652EF3B95E92* L_13 = V_0;
		NullCheck(L_13);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_14;
		L_14 = NtpPacket_get_Bytes_m6E68BBD8630A83EEB78A27E590D38FF01C83E6C3_inline(L_13, NULL);
		NullCheck(L_14);
		V_1 = (bool)((((int32_t)L_12) == ((int32_t)((int32_t)(((RuntimeArray*)L_14)->max_length))))? 1 : 0);
		goto IL_005f;
	}// end try (depth: 1)
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&RuntimeObject_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_005a;
		}
		throw e;
	}

CATCH_005a:
	{// begin catch(System.Object)
		// catch
		// return false;
		V_1 = (bool)0;
		IL2CPP_POP_ACTIVE_EXCEPTION();
		goto IL_005f;
	}// end catch (depth: 1)

IL_005f:
	{
		// }
		bool L_15 = V_1;
		return L_15;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void LiteNetLib.Layers.Crc32cLayer::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Crc32cLayer__ctor_mECC8B679C84C0291B9C072D9F69D4FE80536A76A (Crc32cLayer_tE5B2EC9CF4B04BF362ED013C539E1401F2529BA6* __this, const RuntimeMethod* method) 
{
	{
		// public Crc32cLayer() : base(CRC32C.ChecksumSize)
		PacketLayerBase__ctor_m518745B375D4BBE9FE54C01A56CCFE84586C2060(__this, 4, NULL);
		// }
		return;
	}
}
// System.Void LiteNetLib.Layers.Crc32cLayer::ProcessInboundPacket(System.Net.IPEndPoint&,System.Byte[]&,System.Int32&,System.Int32&)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Crc32cLayer_ProcessInboundPacket_m5881350C82A6E907541E8B1920100A747376170D (Crc32cLayer_tE5B2EC9CF4B04BF362ED013C539E1401F2529BA6* __this, IPEndPoint_t2F09CBA7A808B67724B4E2954EEDC46D910F4ECB** ___endPoint0, ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031** ___data1, int32_t* ___offset2, int32_t* ___length3, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Array_Empty_TisRuntimeObject_m55011E8360A8199FB239A5787BA8631CDD6116FC_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&BitConverter_t6E99605185963BC12B3D369E13F2B88997E64A27_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&CRC32C_tFA7C9F5C10A64056F997BE1B4625419C3ED6B78A_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&NetDebug_t8F8390900D67D7F62A4852546BB041E9CAB6D90A_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral20578EED957D25675AEB69A727D4556E455C76A9);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	{
		// if (length < NetConstants.HeaderSize + CRC32C.ChecksumSize)
		int32_t* L_0 = ___length3;
		int32_t L_1 = *((int32_t*)L_0);
		if ((((int32_t)L_1) >= ((int32_t)5)))
		{
			goto IL_001a;
		}
	}
	{
		// NetDebug.WriteError("[NM] DataReceived size: bad!");
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_2;
		L_2 = Array_Empty_TisRuntimeObject_m55011E8360A8199FB239A5787BA8631CDD6116FC_inline(Array_Empty_TisRuntimeObject_m55011E8360A8199FB239A5787BA8631CDD6116FC_RuntimeMethod_var);
		il2cpp_codegen_runtime_class_init_inline(NetDebug_t8F8390900D67D7F62A4852546BB041E9CAB6D90A_il2cpp_TypeInfo_var);
		NetDebug_WriteError_mCB960BBE748324E00F648B43EFB0D7CA0551979D(_stringLiteral20578EED957D25675AEB69A727D4556E455C76A9, L_2, NULL);
		// length = 0;
		int32_t* L_3 = ___length3;
		*((int32_t*)L_3) = (int32_t)0;
		// return;
		return;
	}

IL_001a:
	{
		// int checksumPoint = length - CRC32C.ChecksumSize;
		int32_t* L_4 = ___length3;
		int32_t L_5 = *((int32_t*)L_4);
		V_0 = ((int32_t)il2cpp_codegen_subtract(L_5, 4));
		// if (CRC32C.Compute(data, offset, checksumPoint) != BitConverter.ToUInt32(data, checksumPoint))
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031** L_6 = ___data1;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_7 = *((ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031**)L_6);
		int32_t* L_8 = ___offset2;
		int32_t L_9 = *((int32_t*)L_8);
		int32_t L_10 = V_0;
		il2cpp_codegen_runtime_class_init_inline(CRC32C_tFA7C9F5C10A64056F997BE1B4625419C3ED6B78A_il2cpp_TypeInfo_var);
		uint32_t L_11;
		L_11 = CRC32C_Compute_m2B8A441E6CDFAE365F8DC45B8F715E6D98339206(L_7, L_9, L_10, NULL);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031** L_12 = ___data1;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_13 = *((ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031**)L_12);
		int32_t L_14 = V_0;
		il2cpp_codegen_runtime_class_init_inline(BitConverter_t6E99605185963BC12B3D369E13F2B88997E64A27_il2cpp_TypeInfo_var);
		uint32_t L_15;
		L_15 = BitConverter_ToUInt32_m7EFCF9D77ACD0F2DA29F69587DDF6130391E6164(L_13, L_14, NULL);
		if ((((int32_t)L_11) == ((int32_t)L_15)))
		{
			goto IL_0039;
		}
	}
	{
		// length = 0;
		int32_t* L_16 = ___length3;
		*((int32_t*)L_16) = (int32_t)0;
		// return;
		return;
	}

IL_0039:
	{
		// length -= CRC32C.ChecksumSize;
		int32_t* L_17 = ___length3;
		int32_t* L_18 = ___length3;
		int32_t L_19 = *((int32_t*)L_18);
		*((int32_t*)L_17) = (int32_t)((int32_t)il2cpp_codegen_subtract(L_19, 4));
		// }
		return;
	}
}
// System.Void LiteNetLib.Layers.Crc32cLayer::ProcessOutBoundPacket(System.Net.IPEndPoint&,System.Byte[]&,System.Int32&,System.Int32&)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Crc32cLayer_ProcessOutBoundPacket_mB97DCDBE502A70FD3DFEB48630E786CBDB2F53A5 (Crc32cLayer_tE5B2EC9CF4B04BF362ED013C539E1401F2529BA6* __this, IPEndPoint_t2F09CBA7A808B67724B4E2954EEDC46D910F4ECB** ___endPoint0, ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031** ___data1, int32_t* ___offset2, int32_t* ___length3, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&CRC32C_tFA7C9F5C10A64056F997BE1B4625419C3ED6B78A_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// FastBitConverter.GetBytes(data, length, CRC32C.Compute(data, offset, length));
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031** L_0 = ___data1;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_1 = *((ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031**)L_0);
		int32_t* L_2 = ___length3;
		int32_t L_3 = *((int32_t*)L_2);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031** L_4 = ___data1;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_5 = *((ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031**)L_4);
		int32_t* L_6 = ___offset2;
		int32_t L_7 = *((int32_t*)L_6);
		int32_t* L_8 = ___length3;
		int32_t L_9 = *((int32_t*)L_8);
		il2cpp_codegen_runtime_class_init_inline(CRC32C_tFA7C9F5C10A64056F997BE1B4625419C3ED6B78A_il2cpp_TypeInfo_var);
		uint32_t L_10;
		L_10 = CRC32C_Compute_m2B8A441E6CDFAE365F8DC45B8F715E6D98339206(L_5, L_7, L_9, NULL);
		FastBitConverter_GetBytes_m59C97C6CD1243787969924BFAE61424CE82DA806_inline(L_1, L_3, L_10, NULL);
		// length += CRC32C.ChecksumSize;
		int32_t* L_11 = ___length3;
		int32_t* L_12 = ___length3;
		int32_t L_13 = *((int32_t*)L_12);
		*((int32_t*)L_11) = (int32_t)((int32_t)il2cpp_codegen_add(L_13, 4));
		// }
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void LiteNetLib.Layers.PacketLayerBase::.ctor(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void PacketLayerBase__ctor_m518745B375D4BBE9FE54C01A56CCFE84586C2060 (PacketLayerBase_tAE86828E66E9B4065BBE4DD1125AE7D0394EBE34* __this, int32_t ___extraPacketSizeForLayer0, const RuntimeMethod* method) 
{
	{
		// protected PacketLayerBase(int extraPacketSizeForLayer)
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		// ExtraPacketSizeForLayer = extraPacketSizeForLayer;
		int32_t L_0 = ___extraPacketSizeForLayer0;
		__this->___ExtraPacketSizeForLayer_0 = L_0;
		// }
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void LiteNetLib.Layers.XorEncryptLayer::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void XorEncryptLayer__ctor_mE1DDFA466F3736CC05845DCD0474C0C57EE3B134 (XorEncryptLayer_tC167B2E4D09C6238B5F5AFD18AC29C99CD71A0C6* __this, const RuntimeMethod* method) 
{
	{
		// public XorEncryptLayer() : base(0)
		PacketLayerBase__ctor_m518745B375D4BBE9FE54C01A56CCFE84586C2060(__this, 0, NULL);
		// }
		return;
	}
}
// System.Void LiteNetLib.Layers.XorEncryptLayer::.ctor(System.Byte[])
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void XorEncryptLayer__ctor_mBE472800FABBC9C6A837AA68D949FBF18F2ADD07 (XorEncryptLayer_tC167B2E4D09C6238B5F5AFD18AC29C99CD71A0C6* __this, ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___key0, const RuntimeMethod* method) 
{
	{
		// public XorEncryptLayer(byte[] key) : this()
		XorEncryptLayer__ctor_mE1DDFA466F3736CC05845DCD0474C0C57EE3B134(__this, NULL);
		// SetKey(key);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_0 = ___key0;
		XorEncryptLayer_SetKey_m9481E86375D09871E727C07EA0B562C28A5E3180(__this, L_0, NULL);
		// }
		return;
	}
}
// System.Void LiteNetLib.Layers.XorEncryptLayer::.ctor(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void XorEncryptLayer__ctor_mB4CC4220890C88B2F19AE4857B00D443590668F3 (XorEncryptLayer_tC167B2E4D09C6238B5F5AFD18AC29C99CD71A0C6* __this, String_t* ___key0, const RuntimeMethod* method) 
{
	{
		// public XorEncryptLayer(string key) : this()
		XorEncryptLayer__ctor_mE1DDFA466F3736CC05845DCD0474C0C57EE3B134(__this, NULL);
		// SetKey(key);
		String_t* L_0 = ___key0;
		XorEncryptLayer_SetKey_m78C57CD5E1FBCC59794D0008201C917A02BD6381(__this, L_0, NULL);
		// }
		return;
	}
}
// System.Void LiteNetLib.Layers.XorEncryptLayer::SetKey(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void XorEncryptLayer_SetKey_m78C57CD5E1FBCC59794D0008201C917A02BD6381 (XorEncryptLayer_tC167B2E4D09C6238B5F5AFD18AC29C99CD71A0C6* __this, String_t* ___key0, const RuntimeMethod* method) 
{
	{
		// _byteKey = Encoding.UTF8.GetBytes(key);
		Encoding_t65CDEF28CF20A7B8C92E85A4E808920C2465F095* L_0;
		L_0 = Encoding_get_UTF8_m9700ADA8E0F244002B2A89B483F1B2133B8FE336(NULL);
		String_t* L_1 = ___key0;
		NullCheck(L_0);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_2;
		L_2 = VirtualFuncInvoker1< ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*, String_t* >::Invoke(18 /* System.Byte[] System.Text.Encoding::GetBytes(System.String) */, L_0, L_1);
		__this->____byteKey_1 = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____byteKey_1), (void*)L_2);
		// }
		return;
	}
}
// System.Void LiteNetLib.Layers.XorEncryptLayer::SetKey(System.Byte[])
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void XorEncryptLayer_SetKey_m9481E86375D09871E727C07EA0B562C28A5E3180 (XorEncryptLayer_tC167B2E4D09C6238B5F5AFD18AC29C99CD71A0C6* __this, ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___key0, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// if (_byteKey == null || _byteKey.Length != key.Length)
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_0 = __this->____byteKey_1;
		if (!L_0)
		{
			goto IL_0015;
		}
	}
	{
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_1 = __this->____byteKey_1;
		NullCheck(L_1);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_2 = ___key0;
		NullCheck(L_2);
		if ((((int32_t)((int32_t)(((RuntimeArray*)L_1)->max_length))) == ((int32_t)((int32_t)(((RuntimeArray*)L_2)->max_length)))))
		{
			goto IL_0023;
		}
	}

IL_0015:
	{
		// _byteKey = new byte[key.Length];
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_3 = ___key0;
		NullCheck(L_3);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_4 = (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)SZArrayNew(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var, (uint32_t)((int32_t)(((RuntimeArray*)L_3)->max_length)));
		__this->____byteKey_1 = L_4;
		Il2CppCodeGenWriteBarrier((void**)(&__this->____byteKey_1), (void*)L_4);
	}

IL_0023:
	{
		// Buffer.BlockCopy(key, 0, _byteKey, 0, key.Length);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_5 = ___key0;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_6 = __this->____byteKey_1;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_7 = ___key0;
		NullCheck(L_7);
		Buffer_BlockCopy_mD8CF7EC96ADA7A542CCA3F3C73510624E10197A9((RuntimeArray*)L_5, 0, (RuntimeArray*)L_6, 0, ((int32_t)(((RuntimeArray*)L_7)->max_length)), NULL);
		// }
		return;
	}
}
// System.Void LiteNetLib.Layers.XorEncryptLayer::ProcessInboundPacket(System.Net.IPEndPoint&,System.Byte[]&,System.Int32&,System.Int32&)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void XorEncryptLayer_ProcessInboundPacket_m718258E696642A83BEA30290F705E9A2A1CD98B7 (XorEncryptLayer_tC167B2E4D09C6238B5F5AFD18AC29C99CD71A0C6* __this, IPEndPoint_t2F09CBA7A808B67724B4E2954EEDC46D910F4ECB** ___endPoint0, ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031** ___data1, int32_t* ___offset2, int32_t* ___length3, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		// if (_byteKey == null)
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_0 = __this->____byteKey_1;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		// return;
		return;
	}

IL_0009:
	{
		// var cur = offset;
		int32_t* L_1 = ___offset2;
		int32_t L_2 = *((int32_t*)L_1);
		V_0 = L_2;
		// for (var i = 0; i < length; i++, cur++)
		V_1 = 0;
		goto IL_0033;
	}

IL_0010:
	{
		// data[cur] = (byte)(data[cur] ^ _byteKey[i % _byteKey.Length]);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031** L_3 = ___data1;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_4 = *((ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031**)L_3);
		int32_t L_5 = V_0;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031** L_6 = ___data1;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_7 = *((ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031**)L_6);
		int32_t L_8 = V_0;
		NullCheck(L_7);
		int32_t L_9 = L_8;
		uint8_t L_10 = (L_7)->GetAt(static_cast<il2cpp_array_size_t>(L_9));
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_11 = __this->____byteKey_1;
		int32_t L_12 = V_1;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_13 = __this->____byteKey_1;
		NullCheck(L_13);
		NullCheck(L_11);
		int32_t L_14 = ((int32_t)(L_12%((int32_t)(((RuntimeArray*)L_13)->max_length))));
		uint8_t L_15 = (L_11)->GetAt(static_cast<il2cpp_array_size_t>(L_14));
		NullCheck(L_4);
		(L_4)->SetAt(static_cast<il2cpp_array_size_t>(L_5), (uint8_t)((int32_t)(uint8_t)((int32_t)((int32_t)L_10^(int32_t)L_15))));
		// for (var i = 0; i < length; i++, cur++)
		int32_t L_16 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_16, 1));
		// for (var i = 0; i < length; i++, cur++)
		int32_t L_17 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_17, 1));
	}

IL_0033:
	{
		// for (var i = 0; i < length; i++, cur++)
		int32_t L_18 = V_1;
		int32_t* L_19 = ___length3;
		int32_t L_20 = *((int32_t*)L_19);
		if ((((int32_t)L_18) < ((int32_t)L_20)))
		{
			goto IL_0010;
		}
	}
	{
		// }
		return;
	}
}
// System.Void LiteNetLib.Layers.XorEncryptLayer::ProcessOutBoundPacket(System.Net.IPEndPoint&,System.Byte[]&,System.Int32&,System.Int32&)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void XorEncryptLayer_ProcessOutBoundPacket_mA5AEAA2B20EECE132D148E2E176971AF0271F737 (XorEncryptLayer_tC167B2E4D09C6238B5F5AFD18AC29C99CD71A0C6* __this, IPEndPoint_t2F09CBA7A808B67724B4E2954EEDC46D910F4ECB** ___endPoint0, ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031** ___data1, int32_t* ___offset2, int32_t* ___length3, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		// if (_byteKey == null)
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_0 = __this->____byteKey_1;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		// return;
		return;
	}

IL_0009:
	{
		// var cur = offset;
		int32_t* L_1 = ___offset2;
		int32_t L_2 = *((int32_t*)L_1);
		V_0 = L_2;
		// for (var i = 0; i < length; i++, cur++)
		V_1 = 0;
		goto IL_0033;
	}

IL_0010:
	{
		// data[cur] = (byte)(data[cur] ^ _byteKey[i % _byteKey.Length]);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031** L_3 = ___data1;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_4 = *((ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031**)L_3);
		int32_t L_5 = V_0;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031** L_6 = ___data1;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_7 = *((ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031**)L_6);
		int32_t L_8 = V_0;
		NullCheck(L_7);
		int32_t L_9 = L_8;
		uint8_t L_10 = (L_7)->GetAt(static_cast<il2cpp_array_size_t>(L_9));
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_11 = __this->____byteKey_1;
		int32_t L_12 = V_1;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_13 = __this->____byteKey_1;
		NullCheck(L_13);
		NullCheck(L_11);
		int32_t L_14 = ((int32_t)(L_12%((int32_t)(((RuntimeArray*)L_13)->max_length))));
		uint8_t L_15 = (L_11)->GetAt(static_cast<il2cpp_array_size_t>(L_14));
		NullCheck(L_4);
		(L_4)->SetAt(static_cast<il2cpp_array_size_t>(L_5), (uint8_t)((int32_t)(uint8_t)((int32_t)((int32_t)L_10^(int32_t)L_15))));
		// for (var i = 0; i < length; i++, cur++)
		int32_t L_16 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_16, 1));
		// for (var i = 0; i < length; i++, cur++)
		int32_t L_17 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_17, 1));
	}

IL_0033:
	{
		// for (var i = 0; i < length; i++, cur++)
		int32_t L_18 = V_1;
		int32_t* L_19 = ___length3;
		int32_t L_20 = *((int32_t*)L_19);
		if ((((int32_t)L_18) < ((int32_t)L_20)))
		{
			goto IL_0010;
		}
	}
	{
		// }
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
#ifdef __clang__
#pragma clang diagnostic pop
#endif
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void NetDataWriter_ResizeIfNeed_mC1A12154624528056AA89E4B791727615D27D9A5_inline (NetDataWriter_t5AE108AEC4825ED3FB45AA93565703368228EB37* __this, int32_t ___newSize0, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Array_Resize_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m82FEC5823560947D2B12C8D675AED2C190DF4F3F_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Math_tEB65DE7CA8B083C412C969C92981C030865486CE_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// if (_data.Length < newSize)
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_0 = __this->____data_0;
		NullCheck(L_0);
		int32_t L_1 = ___newSize0;
		if ((((int32_t)((int32_t)(((RuntimeArray*)L_0)->max_length))) >= ((int32_t)L_1)))
		{
			goto IL_0026;
		}
	}
	{
		// Array.Resize(ref _data, Math.Max(newSize, _data.Length * 2));
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031** L_2 = (&__this->____data_0);
		int32_t L_3 = ___newSize0;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_4 = __this->____data_0;
		NullCheck(L_4);
		il2cpp_codegen_runtime_class_init_inline(Math_tEB65DE7CA8B083C412C969C92981C030865486CE_il2cpp_TypeInfo_var);
		int32_t L_5;
		L_5 = Math_Max_m830F00B616D7A2130E46E974DFB27E9DA7FE30E5(L_3, ((int32_t)il2cpp_codegen_multiply(((int32_t)(((RuntimeArray*)L_4)->max_length)), 2)), NULL);
		Array_Resize_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m82FEC5823560947D2B12C8D675AED2C190DF4F3F(L_2, L_5, Array_Resize_TisByte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_m82FEC5823560947D2B12C8D675AED2C190DF4F3F_RuntimeMethod_var);
	}

IL_0026:
	{
		// }
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void FastBitConverter_GetBytes_m5098DCCC8484C2205A958CBAFE694B1DB9EABEDF_inline (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___bytes0, int32_t ___startIndex1, float ___value2, const RuntimeMethod* method) 
{
	ConverterHelperFloat_t8E65E8DEB449E589D8EA058CC702AE23CDA6D8C1 V_0;
	memset((&V_0), 0, sizeof(V_0));
	ConverterHelperFloat_t8E65E8DEB449E589D8EA058CC702AE23CDA6D8C1 V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		// ConverterHelperFloat ch = new ConverterHelperFloat { Afloat = value };
		il2cpp_codegen_initobj((&V_1), sizeof(ConverterHelperFloat_t8E65E8DEB449E589D8EA058CC702AE23CDA6D8C1));
		float L_0 = ___value2;
		(&V_1)->___Afloat_1 = L_0;
		ConverterHelperFloat_t8E65E8DEB449E589D8EA058CC702AE23CDA6D8C1 L_1 = V_1;
		V_0 = L_1;
		// WriteLittleEndian(bytes, startIndex, ch.Aint);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_2 = ___bytes0;
		int32_t L_3 = ___startIndex1;
		ConverterHelperFloat_t8E65E8DEB449E589D8EA058CC702AE23CDA6D8C1 L_4 = V_0;
		int32_t L_5 = L_4.___Aint_0;
		FastBitConverter_WriteLittleEndian_m39386A96620235D784DD14E9CBF2CD3260310E35_inline(L_2, L_3, L_5, NULL);
		// }
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void FastBitConverter_GetBytes_m70B89BF0E1D92548FF494E5E751A0CFA4231B2C0_inline (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___bytes0, int32_t ___startIndex1, double ___value2, const RuntimeMethod* method) 
{
	ConverterHelperDouble_tEA01E41DCA5C15F9CEB90970D263BB7942F13935 V_0;
	memset((&V_0), 0, sizeof(V_0));
	ConverterHelperDouble_tEA01E41DCA5C15F9CEB90970D263BB7942F13935 V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		// ConverterHelperDouble ch = new ConverterHelperDouble { Adouble = value };
		il2cpp_codegen_initobj((&V_1), sizeof(ConverterHelperDouble_tEA01E41DCA5C15F9CEB90970D263BB7942F13935));
		double L_0 = ___value2;
		(&V_1)->___Adouble_1 = L_0;
		ConverterHelperDouble_tEA01E41DCA5C15F9CEB90970D263BB7942F13935 L_1 = V_1;
		V_0 = L_1;
		// WriteLittleEndian(bytes, startIndex, ch.Along);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_2 = ___bytes0;
		int32_t L_3 = ___startIndex1;
		ConverterHelperDouble_tEA01E41DCA5C15F9CEB90970D263BB7942F13935 L_4 = V_0;
		uint64_t L_5 = L_4.___Along_0;
		FastBitConverter_WriteLittleEndian_m0FCFB2E03F9E6FCA7E2032F4E5EAF28EDFC15194_inline(L_2, L_3, L_5, NULL);
		// }
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void FastBitConverter_GetBytes_m4623FFD1516846C025379E4B184E917E45B1EEB1_inline (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___bytes0, int32_t ___startIndex1, int64_t ___value2, const RuntimeMethod* method) 
{
	{
		// WriteLittleEndian(bytes, startIndex, (ulong)value);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_0 = ___bytes0;
		int32_t L_1 = ___startIndex1;
		int64_t L_2 = ___value2;
		FastBitConverter_WriteLittleEndian_m0FCFB2E03F9E6FCA7E2032F4E5EAF28EDFC15194_inline(L_0, L_1, L_2, NULL);
		// }
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void FastBitConverter_GetBytes_m3AB77751A0F1D6246D7AC61C8EC6CE7AC7B0D203_inline (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___bytes0, int32_t ___startIndex1, uint64_t ___value2, const RuntimeMethod* method) 
{
	{
		// WriteLittleEndian(bytes, startIndex, value);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_0 = ___bytes0;
		int32_t L_1 = ___startIndex1;
		uint64_t L_2 = ___value2;
		FastBitConverter_WriteLittleEndian_m0FCFB2E03F9E6FCA7E2032F4E5EAF28EDFC15194_inline(L_0, L_1, L_2, NULL);
		// }
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void FastBitConverter_GetBytes_m6815D55E22E42D242F5C31826AE4FDAB91F6CB6C_inline (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___bytes0, int32_t ___startIndex1, int32_t ___value2, const RuntimeMethod* method) 
{
	{
		// WriteLittleEndian(bytes, startIndex, value);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_0 = ___bytes0;
		int32_t L_1 = ___startIndex1;
		int32_t L_2 = ___value2;
		FastBitConverter_WriteLittleEndian_m39386A96620235D784DD14E9CBF2CD3260310E35_inline(L_0, L_1, L_2, NULL);
		// }
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void FastBitConverter_GetBytes_m59C97C6CD1243787969924BFAE61424CE82DA806_inline (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___bytes0, int32_t ___startIndex1, uint32_t ___value2, const RuntimeMethod* method) 
{
	{
		// WriteLittleEndian(bytes, startIndex, (int)value);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_0 = ___bytes0;
		int32_t L_1 = ___startIndex1;
		uint32_t L_2 = ___value2;
		FastBitConverter_WriteLittleEndian_m39386A96620235D784DD14E9CBF2CD3260310E35_inline(L_0, L_1, L_2, NULL);
		// }
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void FastBitConverter_GetBytes_m447B17AD55B29DE95E6B761770D1A648BF953382_inline (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___bytes0, int32_t ___startIndex1, uint16_t ___value2, const RuntimeMethod* method) 
{
	{
		// WriteLittleEndian(bytes, startIndex, (short)value);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_0 = ___bytes0;
		int32_t L_1 = ___startIndex1;
		uint16_t L_2 = ___value2;
		FastBitConverter_WriteLittleEndian_m5374178503DA746A783E6C56D593D899853845A5_inline(L_0, L_1, ((int16_t)L_2), NULL);
		// }
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void FastBitConverter_GetBytes_m51BB8E43416F790D6ACD5FD3F5AB477568FDFBB2_inline (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___bytes0, int32_t ___startIndex1, int16_t ___value2, const RuntimeMethod* method) 
{
	{
		// WriteLittleEndian(bytes, startIndex, value);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_0 = ___bytes0;
		int32_t L_1 = ___startIndex1;
		int16_t L_2 = ___value2;
		FastBitConverter_WriteLittleEndian_m5374178503DA746A783E6C56D593D899853845A5_inline(L_0, L_1, L_2, NULL);
		// }
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR IPAddress_t2F4486449B0D73FF2D3B36A9FE5E9C3F63116484* IPEndPoint_get_Address_m72F783CB76E10E9DBDF680CCC1DAAED201BABB1C_inline (IPEndPoint_t2F09CBA7A808B67724B4E2954EEDC46D910F4ECB* __this, const RuntimeMethod* method) 
{
	{
		IPAddress_t2F4486449B0D73FF2D3B36A9FE5E9C3F63116484* L_0 = __this->____address_0;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t IPEndPoint_get_Port_mFBE1AF1C9CC7E68A46BF46AD3869CC9DC01CF429_inline (IPEndPoint_t2F09CBA7A808B67724B4E2954EEDC46D910F4ECB* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____port_1;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t String_get_Length_m42625D67623FA5CC7A44D47425CE86FB946542D2_inline (String_t* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____stringLength_4;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void SubscribeDelegate_Invoke_m803C81F37C8A72A124C26584AD4938FA1F7FD77C_inline (SubscribeDelegate_t5176AD87F22014A136F003FB651B6451DB2BE13F* __this, NetDataReader_t28CDAC4E19A9CDCCE3F782A3E29084D50A2F58FF* ___reader0, RuntimeObject* ___userData1, const RuntimeMethod* method) 
{
	typedef void (*FunctionPointerType) (RuntimeObject*, NetDataReader_t28CDAC4E19A9CDCCE3F782A3E29084D50A2F58FF*, RuntimeObject*, const RuntimeMethod*);
	((FunctionPointerType)__this->___invoke_impl_1)((Il2CppObject*)__this->___method_code_6, ___reader0, ___userData1, reinterpret_cast<RuntimeMethod*>(__this->___method_3));
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* NtpPacket_get_Bytes_m6E68BBD8630A83EEB78A27E590D38FF01C83E6C3_inline (NtpPacket_tF37CA19271AE795B037952A3137F652EF3B95E92* __this, const RuntimeMethod* method) 
{
	{
		// public byte[] Bytes { get; }
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_0 = __this->___U3CBytesU3Ek__BackingField_1;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Nullable_1_tEADC262F7F8B8BC4CC0A003DBDD3CA7C1B63F9AC NtpPacket_get_DestinationTimestamp_m959365B0E7ED9A24A9159DC34CA1581CCD1544A9_inline (NtpPacket_tF37CA19271AE795B037952A3137F652EF3B95E92* __this, const RuntimeMethod* method) 
{
	{
		// public DateTime? DestinationTimestamp { get; private set; }
		Nullable_1_tEADC262F7F8B8BC4CC0A003DBDD3CA7C1B63F9AC L_0 = __this->___U3CDestinationTimestampU3Ek__BackingField_2;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int64_t TimeSpan_get_Ticks_mC50131E57621F29FACC53B3241432ABB874FA1B5_inline (TimeSpan_t8195C5B013A2C532FEBDF0B64B6911982E750F5A* __this, const RuntimeMethod* method) 
{
	{
		int64_t L_0 = __this->____ticks_22;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void NtpPacket_set_DestinationTimestamp_mA6061675D2ABA51638455121F12621CE523FDD5A_inline (NtpPacket_tF37CA19271AE795B037952A3137F652EF3B95E92* __this, Nullable_1_tEADC262F7F8B8BC4CC0A003DBDD3CA7C1B63F9AC ___value0, const RuntimeMethod* method) 
{
	{
		// public DateTime? DestinationTimestamp { get; private set; }
		Nullable_1_tEADC262F7F8B8BC4CC0A003DBDD3CA7C1B63F9AC L_0 = ___value0;
		__this->___U3CDestinationTimestampU3Ek__BackingField_2 = L_0;
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Nullable_1_get_HasValue_m092C73DCE052BFB5C60A39EF9F4E3401AA95221C_gshared_inline (Nullable_1_tEADC262F7F8B8BC4CC0A003DBDD3CA7C1B63F9AC* __this, const RuntimeMethod* method) 
{
	{
		bool L_0 = (bool)__this->___hasValue_0;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* Array_Empty_TisRuntimeObject_m55011E8360A8199FB239A5787BA8631CDD6116FC_gshared_inline (const RuntimeMethod* method) 
{
	{
		il2cpp_codegen_runtime_class_init_inline(il2cpp_rgctx_data(method->rgctx_data, 0));
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_0 = ((EmptyArray_1_tDF0DD7256B115243AA6BD5558417387A734240EE_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->rgctx_data, 0)))->___Value_0;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void FastBitConverter_WriteLittleEndian_m39386A96620235D784DD14E9CBF2CD3260310E35_inline (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___buffer0, int32_t ___offset1, int32_t ___data2, const RuntimeMethod* method) 
{
	{
		// buffer[offset] = (byte)(data);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_0 = ___buffer0;
		int32_t L_1 = ___offset1;
		int32_t L_2 = ___data2;
		NullCheck(L_0);
		(L_0)->SetAt(static_cast<il2cpp_array_size_t>(L_1), (uint8_t)((int32_t)(uint8_t)L_2));
		// buffer[offset + 1] = (byte)(data >> 8);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_3 = ___buffer0;
		int32_t L_4 = ___offset1;
		int32_t L_5 = ___data2;
		NullCheck(L_3);
		(L_3)->SetAt(static_cast<il2cpp_array_size_t>(((int32_t)il2cpp_codegen_add(L_4, 1))), (uint8_t)((int32_t)(uint8_t)((int32_t)(L_5>>8))));
		// buffer[offset + 2] = (byte)(data >> 16);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_6 = ___buffer0;
		int32_t L_7 = ___offset1;
		int32_t L_8 = ___data2;
		NullCheck(L_6);
		(L_6)->SetAt(static_cast<il2cpp_array_size_t>(((int32_t)il2cpp_codegen_add(L_7, 2))), (uint8_t)((int32_t)(uint8_t)((int32_t)(L_8>>((int32_t)16)))));
		// buffer[offset + 3] = (byte)(data >> 24);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_9 = ___buffer0;
		int32_t L_10 = ___offset1;
		int32_t L_11 = ___data2;
		NullCheck(L_9);
		(L_9)->SetAt(static_cast<il2cpp_array_size_t>(((int32_t)il2cpp_codegen_add(L_10, 3))), (uint8_t)((int32_t)(uint8_t)((int32_t)(L_11>>((int32_t)24)))));
		// }
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void FastBitConverter_WriteLittleEndian_m0FCFB2E03F9E6FCA7E2032F4E5EAF28EDFC15194_inline (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___buffer0, int32_t ___offset1, uint64_t ___data2, const RuntimeMethod* method) 
{
	{
		// buffer[offset] = (byte)(data);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_0 = ___buffer0;
		int32_t L_1 = ___offset1;
		uint64_t L_2 = ___data2;
		NullCheck(L_0);
		(L_0)->SetAt(static_cast<il2cpp_array_size_t>(L_1), (uint8_t)((int32_t)(uint8_t)L_2));
		// buffer[offset + 1] = (byte)(data >> 8);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_3 = ___buffer0;
		int32_t L_4 = ___offset1;
		uint64_t L_5 = ___data2;
		NullCheck(L_3);
		(L_3)->SetAt(static_cast<il2cpp_array_size_t>(((int32_t)il2cpp_codegen_add(L_4, 1))), (uint8_t)((int32_t)(uint8_t)((int64_t)((uint64_t)L_5>>8))));
		// buffer[offset + 2] = (byte)(data >> 16);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_6 = ___buffer0;
		int32_t L_7 = ___offset1;
		uint64_t L_8 = ___data2;
		NullCheck(L_6);
		(L_6)->SetAt(static_cast<il2cpp_array_size_t>(((int32_t)il2cpp_codegen_add(L_7, 2))), (uint8_t)((int32_t)(uint8_t)((int64_t)((uint64_t)L_8>>((int32_t)16)))));
		// buffer[offset + 3] = (byte)(data >> 24);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_9 = ___buffer0;
		int32_t L_10 = ___offset1;
		uint64_t L_11 = ___data2;
		NullCheck(L_9);
		(L_9)->SetAt(static_cast<il2cpp_array_size_t>(((int32_t)il2cpp_codegen_add(L_10, 3))), (uint8_t)((int32_t)(uint8_t)((int64_t)((uint64_t)L_11>>((int32_t)24)))));
		// buffer[offset + 4] = (byte)(data >> 32);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_12 = ___buffer0;
		int32_t L_13 = ___offset1;
		uint64_t L_14 = ___data2;
		NullCheck(L_12);
		(L_12)->SetAt(static_cast<il2cpp_array_size_t>(((int32_t)il2cpp_codegen_add(L_13, 4))), (uint8_t)((int32_t)(uint8_t)((int64_t)((uint64_t)L_14>>((int32_t)32)))));
		// buffer[offset + 5] = (byte)(data >> 40);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_15 = ___buffer0;
		int32_t L_16 = ___offset1;
		uint64_t L_17 = ___data2;
		NullCheck(L_15);
		(L_15)->SetAt(static_cast<il2cpp_array_size_t>(((int32_t)il2cpp_codegen_add(L_16, 5))), (uint8_t)((int32_t)(uint8_t)((int64_t)((uint64_t)L_17>>((int32_t)40)))));
		// buffer[offset + 6] = (byte)(data >> 48);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_18 = ___buffer0;
		int32_t L_19 = ___offset1;
		uint64_t L_20 = ___data2;
		NullCheck(L_18);
		(L_18)->SetAt(static_cast<il2cpp_array_size_t>(((int32_t)il2cpp_codegen_add(L_19, 6))), (uint8_t)((int32_t)(uint8_t)((int64_t)((uint64_t)L_20>>((int32_t)48)))));
		// buffer[offset + 7] = (byte)(data >> 56);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_21 = ___buffer0;
		int32_t L_22 = ___offset1;
		uint64_t L_23 = ___data2;
		NullCheck(L_21);
		(L_21)->SetAt(static_cast<il2cpp_array_size_t>(((int32_t)il2cpp_codegen_add(L_22, 7))), (uint8_t)((int32_t)(uint8_t)((int64_t)((uint64_t)L_23>>((int32_t)56)))));
		// }
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void FastBitConverter_WriteLittleEndian_m5374178503DA746A783E6C56D593D899853845A5_inline (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___buffer0, int32_t ___offset1, int16_t ___data2, const RuntimeMethod* method) 
{
	{
		// buffer[offset] = (byte)(data);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_0 = ___buffer0;
		int32_t L_1 = ___offset1;
		int16_t L_2 = ___data2;
		NullCheck(L_0);
		(L_0)->SetAt(static_cast<il2cpp_array_size_t>(L_1), (uint8_t)((int32_t)(uint8_t)L_2));
		// buffer[offset + 1] = (byte)(data >> 8);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_3 = ___buffer0;
		int32_t L_4 = ___offset1;
		int16_t L_5 = ___data2;
		NullCheck(L_3);
		(L_3)->SetAt(static_cast<il2cpp_array_size_t>(((int32_t)il2cpp_codegen_add(L_4, 1))), (uint8_t)((int32_t)(uint8_t)((int32_t)((int32_t)L_5>>8))));
		// }
		return;
	}
}
