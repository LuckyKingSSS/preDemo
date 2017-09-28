/**
@file   ProcessType.h 
@brief  Ч������������ͣ��Լ��ṹ�嶨��
*/
#ifndef __PROCESS_TYPE_HEAD_FILE__
#define __PROCESS_TYPE_HEAD_FILE__

#include "CodecDefine.h"

#ifndef IMAGE_RESIZE_METHOD_DEFINE
#define IMAGE_RESIZE_METHOD_DEFINE

/**
@enum IMAGE_RESIZE_METHOD
@brief ͼ������
*/

enum IMAGE_RESIZE_METHOD
{
    IRM_FULLSCREEN,		///<stretch to full screen 
    IRM_ORIGINAL_SCALE, ///<keep scale, fit to size of output
    IRM_16_9,			///<resize to 16:9, fit to size of output
    IRM_4_3,			///<resize to 4:3, fit to size of output
    IRM_LETTERBOX,		///<lefterbox
    IRM_PAN_SCAN		///<pan scan
};
#endif

#ifndef RESIZE_PARAM_DEFINE
#define RESIZE_PARAM_DEFINE
/**
@struct RESIZE_PARAM
@brief ͼ�����Ž�֯���ͽṹ��
*/
struct RESIZE_PARAM
{
    int					width;	///< ͼ���
    int					height;	///< ͼ���
    IMAGE_INTERPOLATION	uInterpolation; ///< ��֯����
    IMAGE_RESIZE_METHOD uStyle; ///<ͼ��scale����
};

#endif

#ifndef DEINTERLACE_INTERPOLATION_DEF
#define DEINTERLACE_INTERPOLATION_DEF
/**
@enum DEINTERLACE_STYLE
@brief ��Ƶ��֯����
*/
enum DEINTERLACE_STYLE
{
    DIS_NONE,				///< ��ʹ��
    DIS_ODD,				///< �ظ�������
    DIS_EVEN,				///< �ظ�ż����
    DIS_ODD_INTERPOLATE,	///< ʹ�������в�ֵ
    DIS_EVEN_INTERPOLATE,	///< ʹ��ż���в�ֵ
    DIS_AUTO,				///< �Զ������ݲ�֧�֣�
};

#endif // DEINTERLACE_INTERPOLATION_DEF

#ifndef FLOAT_RECT_DEF
#define FLOAT_RECT_DEF
/**
@struct tagFRECT
@brief �������
*/
typedef struct tagFRECT
{
    float   left;	///< �������϶��� X ����
    float   top;	///<�������϶��� Y����
    float   right;	///<�������¶��� X ����
    float   bottom;	///<�������¶��� Y ����
} FRECT, *PFRECT;
#endif

// ��չ�˾�ID���� 
// EX_FILTER_ID


#define EX_FILTER_GRAY			0x0001	///<��ɫ
#define EX_FILTER_EMBOSS			0x0002	///<����
#define EX_FILTER_NEGATIVE		0x0004	///<��Ƭ
#define EX_FILTER_BLACK_WHITE		0x0008	///<�ڰ�
#define EX_FILTER_WHITE_BLACK		0x0010	///<�׺�
#define EX_FILTER_OLD_PHOTO		0x0020	///<����Ƭ

// FLIP_FLAG
#define FLIP_HORIZONTAL			0x0001 ///< ˮƽ��ת
#define FLIP_VERTICAL			0x0002 ///< ��ֱ��ת

#endif // __PROCESS_TYPE_HEAD_FILE__
