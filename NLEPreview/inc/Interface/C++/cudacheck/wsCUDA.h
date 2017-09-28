//Ӳ�����������ͷ�ļ�
//֧�֣�cuda / intel / ati
#pragma once


#ifdef	WIN32

//����ϵͳ����
#define WIND_ME				1    // ME
#define WIND_98             2    // 98
#define WIND_95             3    // 95
#define WIND_2000           4    // 2000
#define WIND_XP             5    // XP
#define WIND_2003           6    // 2003
#define WIND_Vista          7    // Vista
#define WIND_2008           8    // server 2008
#define WIND_2008R2         9    // server 2008 rc2  
#define WIND_Win7           10   // Win7
#define WIND_UNK            0    // UNKNOWN

//����ϵͳλ��
#define WIND_BITTYPE_AMD64  1    //64
#define WIND_BITTYPE_IA64	2    //64
#define WIND_BITTYPE_X86	3    //32


#else

#ifndef __stdcall
#define __stdcall 
#endif


#ifndef BOOL
#define BOOL int 
#endif

#endif

#ifdef __cplusplus
extern "C" {
#endif

//************************************
// Method:    IsSupportCUDA
// FullName:  IsSupportCUDA
// Access:    public 
// Returns:   BOOL __stdcall
// Qualifier: �ж�ϵͳ�����Ƿ�֧��NVIDIA��Ӳ�����ټ�����CUDA�������Ӳ��֧�֣������벻֧�֣�����Ҫ������������������������֧�ֱ�ʾ�Կ��ù�����ʱ������
//************************************
BOOL __stdcall IsSupportCUDA();


//************************************
// Method:    IsNeedTwoNvcuvencDLL
// FullName:  IsNeedTwoNvcuvencDLL
// Access:    public 
// Returns:   BOOL __stdcall
// Qualifier: �ж�nvidia�Կ�֧�֣���������ȱ�ٿ⣬�ɲ�Ʒ��װʱд��
//************************************
BOOL __stdcall IsNeedTwoNvcuvencDLL(void);


//************************************
// Method:    IsSupportNvEncGpu
// FullName:  IsSupportNvEncGpu
// Access:    public 
// Returns:   BOOL __stdcall
// Qualifier: �ж�nvidia�Կ�֧�֣���������ȱ�ٿ⣬�ɲ�Ʒ��װʱд��
//************************************
BOOL __stdcall IsSupportNvEncGpu(void);


//************************************
// Method:    IsSupportCodecH264
// FullName:  IsSupportCodecH264
// Access:    public 
// Returns:   BOOL __stdcall
// Qualifier: �ж��Ƿ�֧��CUDA��h264�������
//************************************
BOOL __stdcall IsSupportEncoderH264();


//************************************
// Method:    IsSupportCodecVC1
// FullName:  IsSupportCodecVC1
// Access:    public 
// Returns:   BOOL __stdcall
// Qualifier: �Ƿ�֧��CUDA��VC1�������
//************************************
BOOL __stdcall IsSupportEncoderVC1();

//************************************
// Method:    IsDeviceSupportCUDA
// FullName:  IsDeviceSupportCUDA
// Access:    public 
// Returns:   BOOL __stdcall
// Qualifier: ���Ӳ���Ƿ�֧��CUDA�ļ��٣����Ӳ��֧�֣���IsSupportCUDA�������Ƿ�֧��
//************************************
#ifdef WIN32
BOOL __stdcall IsDeviceSupportCUDA();
#else
BOOL __stdcall IsDeviceSupportCUDA(int argc = 1, char * const argv[] = 0);	
#endif

//************************************
// Method:    IsATISupport
// FullName:  IsATISupport
// Access:    public 
// Returns:   BOOL __stdcall
// Qualifier: ����Ƿ�֧��ATI�ļ��� 0, ��֧�� 1, ֧��
BOOL __stdcall IsATISupport(void);

//************************************
// Method:    IsATIGpuDeviceSupport
// FullName:  IsATIGpuDeviceSupport
// Access:    public 
// Returns:   BOOL __stdcall
// Qualifier: ����Ƿ���ati�Կ� 0, ���� 1, ��
BOOL __stdcall IsATIGpuDeviceSupport(void);

BOOL __stdcall TempIsATIGpuDeviceSupport(void);
void __stdcall CrashIsATIGpuDeviceSupport(void);

//************************************
// Method:    IsIntelGPUEncodeSupport
// FullName:  IsIntelGPUEncodeSupport
// Access:    public 
// Returns:   BOOL __stdcall
// Qualifier: ����Ƿ�֧��IntelӲ��������� 0, ��֧�� 1, ֧��
BOOL __stdcall IsIntelGPUEncodeSupport(void);

//************************************
// Method:    IsIntelSupport
// FullName:  IsIntelSupport
// Access:    public 
// Returns:   BOOL __stdcall
// Qualifier: ����Ƿ�֧��Intel�ļ��� 0, ��֧�� 1, ֧��
BOOL __stdcall IsIntelSupport(void);

//************************************
// Method:    IsVCESupport
// FullName:  IsVCESupport
// Access:    public 
// Returns:   BOOL __stdcall
// Qualifier: ����Ƿ�֧��AMD VCE�ļ��� 0, ��֧�� 1, ֧��
BOOL __stdcall IsVCESupport(void);

//************************************
// Method:    GetWinOSVersion
// FullName:  GetWinOSVersion
// Access:    public 
// Returns:   int __stdcall
// Qualifier: ���ز���ϵͳ���ͣ�����ֵ��Ӧ����ϵͳö��ֵ
//************************************
int __stdcall GetWinOSVersion();

//************************************
// Method:    GetWinOSBit
// FullName:  GetWinOSBit
// Access:    public 
// Returns:   int __stdcall
// Qualifier: ���ز���ϵͳλ�����ͣ�����ֵ��Ӧ��λ������ö��ֵ
//************************************
int __stdcall GetWinOSBit();

//************************************
// Method:    IsDeviceSupportATI  
// FullName:  IsDeviceSupportATI
// Access:    public 
// Returns:   BOOL __stdcall
// Qualifier: ���Ӳ���Ƿ�֧��ATI�ļ��٣����Ӳ��֧�֣���IsDeviceSupportATI�������Ƿ�֧��,�������� MAC OS
//************************************
BOOL  __stdcall  IsDeviceSupportATI(int argc, char * const argv[]);

// ���fourcc�ڵ�ǰ�Կ����������£��Ƿ����֧��Ӳ������
/* ���÷���:
	 1.createCheckFourccObj 
	 2.SetAcerType
	 3.CheckAcerFormate
	 4.destroyCheckFourccObj

	 �����2 -3 ����

*/

#ifdef WIN32
void * __stdcall createCheckFourccObj(void);
BOOL __stdcall SetAcerType(int nAccelerateType, const wchar_t* pszDescript , void * pCheckFourccObj);
BOOL __stdcall CheckAcerFormate(DWORD& dwFileFourCC, DWORD& dwVideoFourCC, DWORD& dwAudioFourCC,void * pCheckFourccObj);
void __stdcall destroyCheckFourccObj(void * pCheckFourccObj);


// ��� ��ǰϵͳ���Կ��Ƿ�֧��gpu����
int  __stdcall IsIntelHw(int *nIsInXml);
int __stdcall  IsAtiAPP(int *nIsInXml);
int  __stdcall IsNvidiaCuda(int *nIsInXml);
//pdisplayCadName �ⲿ����
//����ֵΪ1��ʾ��ȡ���Կ��ͺ�
int __stdcall  wsGetdisplaycardName(wchar_t pdisplayCadName[]);

#endif

#ifdef __cplusplus
}
#endif