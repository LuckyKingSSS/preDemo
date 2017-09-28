#pragma once

#ifdef WIN32

	typedef HWND HSUBVIEW;
	typedef HWND HVIEW;
#else
	typedef void * HSUBVIEW;
	typedef void * HVIEW;
	
#endif


typedef void *HPLAYER;

class AudioDecoder;
class VideoDecoder;
typedef VideoDecoder *HVIDEODECODER;	// VideoDecoder�������
typedef AudioDecoder *HAUDIODECODER;	// AudioDecoder�������

#define WM_PLAYERMSG		(WM_USER + 2001) //��������Ϣ
#ifndef WIN32
#define WM_CLOSE                       WM_USER + 0x0010
#endif
//��Ϣ����wParam
#define PM_Progress			1 //�����У�����VPGetPlayedTimeȡ�ò���ʱ���Լ������
#define PM_Finish			2 //���Ž��� ���Զ������Ż�Post����Ϣ��
#define PM_SeekFinish		3 //SEEK���� ����׼ȷ��ȡ����

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

#ifdef WIN32
void __stdcall VPInit();

// �ر�GDI+
void __stdcall VPUninit();
#endif

//��������������rcPos������λ��
HPLAYER __stdcall VPCreate(HVIEW hWndParent, LPRECT pRect); 

//���ٲ���������
void __stdcall VPDestroy(HPLAYER hPlayer);

//�趨������
void __stdcall VPSetDecoder(HPLAYER hPlayer, HVIDEODECODER hVideo, HAUDIODECODER hAudio);

//����VPSetDecoder���趨decoder���õ���Ƶ�γ���
double __stdcall VPGetMovieLength(HPLAYER hPlayer);

//������Ƶ����ʱ�䣬 dBegin������ʼʱ�䣬dLength��������ʱ�䣬Ϊ0���ŵ���β
void __stdcall VPSetPlayTime(HPLAYER hPlayer, double dBegin, double dLength);

//���ţ�dBegin������ʼʱ�䣬dLength��������ʱ�䣬Ϊ0���ŵ���β
void __stdcall VPPlay(HPLAYER hPlayer);

//ֹͣ����
void __stdcall VPStop(HPLAYER hPlayer);

//��ͣ
void __stdcall VPPause(HPLAYER hPlayer);

//�ָ�
void __stdcall VPResume(HPLAYER hPlayer);

//��λ��dTime,dTimeΪ���ʱ�� ��VPSetPlayTime���õ�dBeginΪ��׼ 
void __stdcall VPSeek(HPLAYER hPlayer, double dTime, int accurate = TRUE);

//����ͬVPSeek����ȴ���ɲŷ��� 
void __stdcall VPSyncSeek(HPLAYER hPlayer, double dTime, int accurate = TRUE);

//��֡ǰ�������ȵ���VPPause
void __stdcall VPForward(HPLAYER hPlayer);

//����ͬVPForward����ȴ���ɲŷ��� 
void __stdcall VPSyncForward(HPLAYER hPlayer);

//����ص�����,��ϢΪWM_PLAYERMSG,wParam������PM_Progress,PM_Finish����
void __stdcall VPSetCallBack(HPLAYER hPlayer, HVIEW hCBWnd);

//ȡ�ò������Ӵ��ھ��
HSUBVIEW __stdcall VPGetPlayerHwnd(HPLAYER hPlayer);

//ȡ�ò���ʱ��,�����VPSetPlayTime��dBegin,0��dLength
double __stdcall VPGetPlayedTime(HPLAYER hPlayer);

//ȡ��ʾ��Ϣ
IMAGE_RESIZE_METHOD __stdcall VPGetDisplayResizeMode(HPLAYER hPlayer);

//���ò��ű���
int __stdcall VPSetDisplayResizeMode(HPLAYER hPlayer, IMAGE_RESIZE_METHOD irm);


// Crop���������Ϣ
#define UM_CROP_CHANGE		(WM_USER + 4326)

// ���ò��������ڵı༭ģʽ 
void __stdcall VPSetCropEditStyle(HPLAYER hPlayer, UINT uCropStyle = 1);

// ����Crop����  ͼ������ �Ǵ�������
void __stdcall VPSetCropRect(HPLAYER hPlayer, LPRECT pCropRect); 

// ��ȡCrop����  ͼ������ �Ǵ�������
void __stdcall VPGetCropRect(HPLAYER hPlayer, LPRECT pCropRect); 

//ˢ����ʾ
void __stdcall VPUpdate(HPLAYER hPlayer);

// �������Ƿ��ڻ״̬���������ڲ��ź�Pause״̬
// 0 - ���״̬�� 1- ���ڲ��ţ� 2 - ��ͣ״̬
int __stdcall VPIsActivate(HPLAYER hPlayer);

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



	#pragma warning(disable: 4996)
	#pragma warning(disable: 4995)

// ʱ�䣬֡��Timecodeת��

__inline double Frame2Time(int nFrame, double dFrameRate)
{
	if (dFrameRate < 0.00001)
		return 0;
	return nFrame / dFrameRate;
}

__inline int Time2Frame(double dTime, double dFrameRate)
{
	return (int)(dTime * dFrameRate + 0.5);
}

__inline const char* Frame2TimeCode(int nFrame, double dFrameRate, char szBuf[16])
{
	int nFrameRate = (int)(dFrameRate + 0.5); 
	if (nFrameRate <= 0)
	{
		sprintf(szBuf, "%02x:%02x:%02x:%02x", (BYTE)-1, (BYTE)-1, (BYTE)-1, (BYTE)-1);
		return szBuf;
	}

	int h = nFrame / (nFrameRate * 3600);
	int tmp = nFrame - h * nFrameRate * 3600;
	int m = tmp / (nFrameRate * 60);
	tmp -= m * nFrameRate * 60;
	int s = tmp / nFrameRate;
	tmp -= s * nFrameRate;
	int f = tmp;

	sprintf(szBuf, "%02d:%02d:%02d:%02d", h, m, s, f);

	return szBuf;
}

__inline const char* Time2TimeCode(double dTime, double dFrameRate, char szBuf[16])
{
	if (dFrameRate < 0.001)
		dFrameRate = 100;
	if (dTime < 0)
		dTime = 0;

	int nFrame = Time2Frame(dTime, dFrameRate);
	return Frame2TimeCode(nFrame, dFrameRate, szBuf);
}

__inline int TimeCode2Frame(const char* pszTimeCode, double dFrameRate)
{
	int nFrameRate = (int)(dFrameRate + 0.5); 
	int h, m, s, f;
	sscanf(pszTimeCode, "%02d:%02d:%02d:%02d", &h, &m, &s, &f);

	return h * 3600 * nFrameRate + m * 60 * nFrameRate + s * nFrameRate + f;
}

__inline double TimeCode2Time(const char* pszTimeCode, double dFrameRate)
{
	int nFrame = TimeCode2Frame(pszTimeCode, dFrameRate);
	return Frame2Time(nFrame, dFrameRate);
}



