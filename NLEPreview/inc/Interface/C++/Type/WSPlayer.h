// WSPlayer.h

#pragma once

#ifdef WIN32

	typedef HWND HSUBVIEW;
	typedef HWND HVIEW;
#else

#ifndef WINDOWREF
    typedef void* WindowRef;
#define WINDOWREF

#endif
	typedef void * HSUBVIEW;
	typedef void * HVIEW;
	
#endif


typedef void *HPLAYER;

//class AudioDecoder;
//class VideoDecoder;
//typedef VideoDecoder *HVIDEODECODER;	// VideoDecoder�������
//typedef AudioDecoder *HAUDIODECODER;	// AudioDecoder�������
//
//typedef HVIDEODECODER HVDPROCESS;
//typedef HAUDIODECODER HADPROCESS;

typedef UINT  IDVPVIEW;

#define WM_PLAYERMSG		(WM_USER + 2001) //��������Ϣ

//��Ϣ����wParam
#define PM_Progress			1 //�����У�����VPGetPlayedTimeȡ�ò���ʱ���Լ������
#define PM_Finish			2 //���Ž��� ���Զ������Ż�Post����Ϣ��
#define PM_FrameSpeed       3 
#define PM_Buffering		4 //����

#define WM_AudioVolume		50 //��������Ϣ



#ifndef IMAGE_INTERPOLATION_DEFINE
#define IMAGE_INTERPOLATION_DEFINE
// ͼ���ֵ�㷨
enum IMAGE_INTERPOLATION
{
	IIN_AUTO,			// �Զ�ѡ���ֵ�㷨
	IIN_FAST,			// Nearest value (�ڽ���ֵ)
	IIN_BI_LINER,		// Bi-Liner Interpolation (˫���Բ�ֵ)
	IIN_TRI_CONVOLUTE	// Tri-Convolute Interpolation (�����ֵ)
};

#endif

#ifndef IMAGE_RESIZE_METHOD_DEFINE
#define IMAGE_RESIZE_METHOD_DEFINE

enum IMAGE_RESIZE_METHOD
{
	IRM_FULLSCREEN,		// stretch to full screen 
	IRM_ORIGINAL_SCALE, // keep scale, fit to size of output
	IRM_16_9,			// resize to 16:9, fit to size of output
	IRM_4_3,			// resize to 4:3, fit to size of output
	IRM_LETTERBOX,
	IRM_PAN_SCAN
};
#endif

#ifndef RESIZE_PARAM_DEFINE
#define RESIZE_PARAM_DEFINE

struct RESIZE_PARAM
{
	int					width;
	int					height;
	IMAGE_INTERPOLATION	uInterpolation;
	IMAGE_RESIZE_METHOD uStyle;
};
#endif

#ifndef DEINTERLACE_INTERPOLATION_DEF
#define DEINTERLACE_INTERPOLATION_DEF

enum DEINTERLACE_STYLE
{
	DIS_NONE,				
	DIS_ODD,				// �ظ�������
	DIS_EVEN,				// �ظ�ż����
	DIS_ODD_INTERPOLATE,	// ʹ�������в�ֵ
	DIS_EVEN_INTERPOLATE,	// ʹ��ż���в�ֵ
	DIS_AUTO,				// �Զ������ݲ�֧�֣�
};

#endif // DEINTERLACE_INTERPOLATION_DEF

#ifdef	__cplusplus
extern "C" {
#endif

//#ifdef WIN32
//void __stdcall VPInit();
//
//// �ر�GDI+
//void __stdcall VPUninit();
//#endif
//
////����������
//HPLAYER __stdcall VPCreate(); 
//
////���ٲ���������
//void __stdcall VPDestroy(HPLAYER hPlayer);
//
////�趨������
//void __stdcall VPSetDecoder(HPLAYER hPlayer, HVIDEODECODER hVideo, HAUDIODECODER hAudio);
//
////����VPSetDecoder���趨decoder���õ���Ƶ�γ���
//double __stdcall VPGetMovieLength(HPLAYER hPlayer);
//
////������Ƶ����ʱ�䣬 dBegin������ʼʱ�䣬dLength��������ʱ�䣬Ϊ0���ŵ���β
//void __stdcall VPSetPlayTime(HPLAYER hPlayer, double dBegin, double dLength);
//
////���ţ�dBegin������ʼʱ�䣬dLength��������ʱ�䣬Ϊ0���ŵ���β
//void __stdcall VPPlay(HPLAYER hPlayer);
//
////ֹͣ����
//void __stdcall VPStop(HPLAYER hPlayer);
//
////��ͣ
//void __stdcall VPPause(HPLAYER hPlayer);
//
////�ָ�
//void __stdcall VPResume(HPLAYER hPlayer);
//
////��λ��dTime,dTimeΪ���ʱ�� ��VPSetPlayTime���õ�dBeginΪ��׼ 
//void __stdcall VPSeek(HPLAYER hPlayer, double dTime, int accurate = TRUE);
//
////����ͬVPSeek����ȴ���ɲŷ��� 
//void __stdcall VPSyncSeek(HPLAYER hPlayer, double dTime, int accurate = TRUE);
//
////��֡ǰ�������ȵ���VPPause
//void __stdcall VPForward(HPLAYER hPlayer);
//
////����ͬVPForward����ȴ���ɲŷ��� 
//void __stdcall VPSyncForward(HPLAYER hPlayer);
//
////����ص�����,��ϢΪWM_PLAYERMSG,wParam������PM_Progress,PM_Finish����
//void __stdcall VPSetCallBack(HPLAYER hPlayer, HVIEW hCBWnd);
//
//// ָ����Ϣ�ص�ָ�롣MAC�²���COCOA��������ʱ�޷�ʹ����Ϣ�ص�����ר����Ӵ˽ӿ����ڷ��ؽ�����Ϣ
//#ifndef WIN32
//typedef int (__stdcall *MACPROC)(HVIEW hWnd, UINT msg, DWORD wParam, DWORD lParam);
//void __stdcall VPSetCallBackPtr(HPLAYER hPlayer, MACPROC proc);
//#endif
//
////ȡ�ò���ʱ��,�����VPSetPlayTime��dBegin,0��dLength
//double __stdcall VPGetPlayedTime(HPLAYER hPlayer);
//
////����,0~200, 100����ԭ����
//int __stdcall VPSetVolume(HPLAYER hPlayer, int nValue);
//
////��������������rcPos������λ��,����0��ʾʧ�ܣ�>0�ɹ�
//// ˫��������Ŀ�겥���� nViewMode ����Ϊ1
//IDVPVIEW __stdcall VPCreateView(HPLAYER hPlayer, HVIEW hWndParent, LPRECT pRect, int nViewMode = 0);
//IDVPVIEW __stdcall VPCreateViewEx(HPLAYER hPlayer, HVIEW hWndParent, LPRECT pRect, const RESIZE_PARAM *pResizeParam = 0, int nViewMode = 0);
//
////���ٲ���������
//void __stdcall VPDestroyView(HPLAYER hPlayer, IDVPVIEW id);
//
//// �������Ų���
//int __stdcall VPSetResizeParam(HPLAYER hPlayer, const RESIZE_PARAM *pResizeParam);
//
////ȡ�ò������Ӵ��ھ��
//HSUBVIEW __stdcall VPGetPlayerHwnd(HPLAYER hPlayer, IDVPVIEW id);
//
////ȡ��VideoDataProcess���
//HVDPROCESS __stdcall VPGetVideoDataProcessHandle(HPLAYER hPlayer, IDVPVIEW id);
//
//
////ȡ��ʾ��Ϣ
//IMAGE_RESIZE_METHOD __stdcall VPGetDisplayResizeMode(HPLAYER hPlayer, IDVPVIEW id);
//
////���ò��ű���������һ��Ϊ0��ԭ��Ƶ������Ĭ��Ϊ0
//int __stdcall VPSetDisplayResizeMode(HPLAYER hPlayer, IDVPVIEW id, IMAGE_RESIZE_METHOD irm);
//
//
//
//// Crop���������Ϣ
//#define UM_CROP_CHANGE		(WM_USER + 4326)
//
//// ���ò��������ڵı༭ģʽ 
//void __stdcall VPSetCropEditStyle(HPLAYER hPlayer, IDVPVIEW id, UINT uCropStyle = 1);
//
//// ����Crop����  ͼ������ �Ǵ�������
//void __stdcall VPSetCropRect(HPLAYER hPlayer, IDVPVIEW id, LPRECT pCropRect); 
//
//// ��ȡCrop����  ͼ������ �Ǵ�������
//void __stdcall VPGetCropRect(HPLAYER hPlayer, IDVPVIEW id, LPRECT pCropRect); 
//
//// ����Crop����ģʽ
//// Ĭ���л�ɫ����
//void __stdcall VPSetCropMaskMode(HPLAYER hPlayer, IDVPVIEW id, int bMask = 1);
//
////ˢ����ʾ
//void __stdcall VPUpdate(HPLAYER hPlayer);
//
//// �������Ƿ��ڻ״̬���������ڲ��ź�Pause״̬
//// 0 - ���״̬�� 1- ���ڲ��ţ� 2 - ��ͣ״̬
//int __stdcall VPIsActivate(HPLAYER hPlayer);

enum IMAGE_TYPE
{
	IMAGE_BMP,
	IMAGE_JPG,
	IMAGE_PNG
};

struct CaptureImageInfo
{
	RESIZE_PARAM		uResizeParam;
	DEINTERLACE_STYLE	uDeInterlace;
	IMAGE_TYPE			uImageType;
};

// ץȡ��ƵͼƬ
int __stdcall VPCaptureCurrentImage(HPLAYER hPlayer, const CaptureImageInfo *pCaptureImageInfo, const wchar_t *pszFile);

// Message Code:
//
#define VM_SAVE_IMAGE			0x0100 // wParam - LPBITMAPINFO  lParam - file name (char*)
#define VM_SAVE_YUV_2_BMP		0x0101 // wParam - const YUVImage *  lParam - file name (char*)

#define VM_TRACE_TEXT			0x0200 // wParam - COLORREF  lParam - Text (char*)

#define VM_FULL_SPEED			0x0800
#define VM_NORMAL_SPEED			0x0801
#define VM_GET_SPEED			0x0802 // ȡ�õ�ǰ������ÿ�벥�ŵ�֡��

DWORD __stdcall VPSendCommand(HPLAYER hPlayer, UINT uMsg, WPARAM wParam, LPARAM lParam);

#ifdef	__cplusplus
}
#endif

