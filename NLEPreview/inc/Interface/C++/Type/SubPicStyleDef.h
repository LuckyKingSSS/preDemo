/**
@file	SubPicStyleDef.h 
@brief	��Ļ��ʽͨ�ýṹ��

���峣�õ���Ļ��ʽ�ṹ�壬�Լ���Ļ��Ϣ��
*/
#pragma once 
#include "TextDef.h"

/**
@brief	�û��Զ������Ļ��Ϣ

	����SetExDecodeParam(UINT uMsg, WPARAM wParam, LPARAM lParam) ��uMsg����
	- wParam:ΪUSERSUBPIC�ṹ��ĵ�ַ
	- lParam: Ϊ��͸����
*/
#define USER_SUBPIC 8888  

/**
@brief	�û���ѡ��Ļ��Ϣ

	����SetExDecodeParam(UINT uMsg, WPARAM wParam, LPARAM lParam) ��uMsg����
	- wParam: ΪUSERSUBPIC�ṹ��ĵ�ַ
	- lParam: Ϊ��͸����
*/
#define USER_SUBPICEX 8889 


/**
@struct tagSubPicStyle
@brief �û��Զ������Ļ��ʽ
*/
typedef struct tagSubPicStyle
{
	int        bUseDefaultStyle;  ///< �Ƿ�ʹ��Ĭ����ʽ
	wchar_t     szFontName[128];  ///<  ������
	int         nFontSize;        ///<  �����С
	UINT        uStyle;           ///<  ������ʽ PCSFontStyleRegular | PCSFontStyleBold | PCSFontStyleItalic | PCSFontStyleUnderline
	COLORREF    Color;            ///<  ������ɫ
	int        bShadow;           ///<  �Ƿ�ʹ����Ӱ
	SHADOWPARAM	paramShadow;	  ///<  ������Ӱ��bShadowΪ��ʱ��Ч��
#ifdef WIN32
	int			nHalation;		  ///<  ����ֵ 0Ϊ�޹���Ч��
	COLORREF	crHalation;		  ///<  ������ɫֵ
#endif

	int			nAngle;			  ///<  ��ת�Ƕ� ˳ʱ�루0-360��
	int         nLeftTopX;        ///<  ��ĻͼƬ���Ͻ�����ƵͼƬ�ϵ�X����
	int         nLeftTopY;        ///<  ��ĻͼƬ���Ͻ�����ƵͼƬ�ϵ�Y����
}SUBPICSTYLE, *PSUBPICSTYLE;

/**
@struct tagUserSubPic
@brief ��ĻID��������Ļ��ʽ
*/

typedef struct tagUserSubPic
{
	UINT         uSubPicID;        ///<  ��ĻID
	SUBPICSTYLE  Style;            ///<  ��Ļ��ʽ
}USERSUBPIC, *PUSERSUBPIC;


/**
@struct tagUserSubPicEx
@brief ��Ļ��������Ļ��ʽ
*/
typedef struct tagUserSubPicEx
{
	wchar_t     *pSubPicPath;        ///<   ��Ļ��	
	SUBPICSTYLE  Style;            ///<  ��Ļ��ʽ
}USERSUBPICEX, *PUSERSUBPICEX;
