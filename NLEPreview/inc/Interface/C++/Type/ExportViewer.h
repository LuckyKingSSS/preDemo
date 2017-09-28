//
// ���巢��Ԥ�����ڽӿ�
//

#pragma once



#ifdef WIN32

	typedef HWND HSUBVIEW;
	typedef HWND HVIEW;
#else
	typedef void * HSUBVIEW;
	typedef WindowRef HVIEW;
	
#endif

#include "YUVImage.h"

typedef void *HEXPORTVIEWER;


#ifdef	__cplusplus
extern "C" {
#endif

//�������ڣ�hParent���������ڣ�rcPos������������
HEXPORTVIEWER __stdcall EVCreate(HVIEW hParentWnd, LPRECT prcPos);

//���ٴ���
void __stdcall EVDestroy(HEXPORTVIEWER hViewer);

//��ʾ�豸�޹�λͼ
int __stdcall EVShowDib(HEXPORTVIEWER hViewer, const LPBITMAPINFO lpbi, const LPBYTE pBits = 0);

//��ʾYUVͼ��
int __stdcall EVShowImage(HEXPORTVIEWER hViewer, const LPBITMAPINFO lpbi, const LPBYTE pBits = 0);

//��ʾYUVImageͼ��
int __stdcall EVShowYUVImage(HEXPORTVIEWER hViewer, const YUVImage * pImage);

// ȡ��Ԥ������HWND���
HSUBVIEW __stdcall EVGetHwnd(HEXPORTVIEWER hViewer);


#ifdef	__cplusplus
}
#endif

