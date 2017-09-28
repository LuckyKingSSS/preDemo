/********************************************************
����һ�����ֺ������ֵ���������
*********************************************************/

/*! \file TextDef.h
* \brief	����һ�����ֺ������ֵ���������
*/

#ifndef __PCS_TEAM_TEXTDEF_20051208_CREAM520_0_H__
#define __PCS_TEAM_TEXTDEF_20051208_CREAM520_0_H__

#pragma once


#define TEXT_BUF_MAX_LEN			1024
#define EFFECT_NAME_BUF_LEN			64

#define TEXT_FONT_NAME_LEN			128
#ifdef WIN32

/*!
* \struct ARTTEXTINFO
* \brief ��������Ϣ
*/
typedef struct tagARTTEXTINFO
{
	/*! ģ����*/
	HANDLE  hInst;

	/*! ���������� �� Hollow�� Trape�� Fashion�� Rainbow*/
	wchar_t  szArtID[64];

	/*! �����ֵ�ID*/
	UINT      uBmpID;

	/*! �����ֶ�*/
	DWORD     dwReserve;
}ARTTEXTINFO, *LPARTTEXTINFO;
#else
typedef void* LPARTTEXTINFO;
#endif

/*!
* \struct TEXTTRANSFORM
* \brief λ����Ϣ
*/
typedef struct tagTEXTTRANSFORM
{
	/*! ���ϽǶ�������*/
	POINT ptLeftTop;

	/*! ���½Ƕ�������*/
	POINT ptLeftBottom;

	/*! ���ϽǶ�������*/
	POINT ptRightTop;

	/*! ���½Ƕ�������*/
	POINT ptRightBottom;
}TEXTTRANSFORM, * LPTEXTTRANSFORM;

#ifdef WIN32
// �����ֲ����ṹ����
struct ARTTEXTPARAM
{
	wchar_t	strArtID[EFFECT_NAME_BUF_LEN];  // ����������ID
	int		nParam1;	
	int		nParam2;	
	int		nParam3;	
	int		nParam4;	
	int		nParam5;
	double	dParam6;	
	double	dParam7;	// 1-7�Ų���������ݾ�������������Ͷ���
};

#endif

#ifndef WIN32
//rgb��ɫ���壬����ȡֵ��ΧΪ[0, 255]
struct RGBCOLOR
{
	int Red;
	int Green;
	int Blue;
	int Opacity;
};

#define COLORREF RGBCOLOR
#endif

// ������Ӱ�ṹ����
/*!
* \struct SHADOWPARAM
* \brief ������Ӱ�ṹ����
*/
struct SHADOWPARAM
{
	/*! ��Ӱ��ɫ*/
	COLORREF	crColor;	

	/*! ��ӰX����ƫ��*/
	int			nXOffset;

	/*! ��ӰY����ƫ��*/
	int			nYOffset; 

#ifdef WIN32
	/*! ��Ӱ��͸����*/
	int			nOpacity;	
#endif

	/*! ��Ӱģ���̶�*/
	int			nBlurSize;	
};

// TEXT_STYLE
const int PCSFontStyleRegular		= 0;		// ����
const int PCSFontStyleBold			= 0x0001;	// ����
const int PCSFontStyleItalic		= 0x0002;	// б��
const int PCSFontStyleUnderline		= 0x0004;	// �»���
#ifdef WIN32
const int PCSFontStyleStrikeout		= 0x0008;	// ɾ����
#endif

// �ı����ݽṹ����
/*!
* \struct TEXTITEM
* \brief �ı����ݽṹ��
*/
struct TEXTITEM
{
	/*! �ı�����*/
	wchar_t		strText[TEXT_BUF_MAX_LEN];		

	/*! ��������*/
	wchar_t		strFontName[TEXT_FONT_NAME_LEN];

	/*! ������ɫ*/
	COLORREF	crFont;		

	/*! �ֺ�*/
	int			nFontSize;	

	/*! TEXT_STYLE �ɸ�style���������*/
	UINT		uStyle;	 

	/*! �Ƿ�ʹ����Ӱ*/
	int		bShadow;

	/*! ������Ӱ��bShadowΪ��ʱ��Ч�� �����ֲ�ʹ�øò��� */
	SHADOWPARAM	paramShadow;

#ifdef WIN32
	/*! ����ֵ 0Ϊ�޹���Ч��*/
	int			nHalation;	

	/*! ������ɫֵ*/
	COLORREF	crHalation;	
#endif
	
	/*! ��ת�Ƕ� ˳ʱ�루0-360��*/
	int			nAngle;	
	
	/*! ������������ ��δʹ��*/
	int			xScale;	

	/*! ������������ ��δʹ��*/
	int			yScale;		 

	/*! ����ʹ��*/
	DWORD		dwReserved;		

	/*! ����ʹ��*/
	DWORD		dwReserved2;
};
typedef TEXTITEM* LPTEXTITEM;

#ifdef WIN32
// ���������ݽṹ����

/*!
* \struct ARTTEXTITEM
* \brief ���������ݽṹ����
* \see TEXTITEM ARTTEXTPARAM
*/
struct ARTTEXTITEM
{
	/*! ������������*/
	TEXTITEM		txtBase;

	/*! �����ֲ���*/
	ARTTEXTPARAM	artTxtParam;
};
typedef ARTTEXTITEM* LPARTTEXTITEM;
#else
typedef void* LPARTTEXTITEM;
#endif

#endif //__PCS_TEAM_TEXTDEF_20051208_CREAM520_0_H__

