unit ExportViewer;

interface

uses
  Windows,YUVImage;

type
  HEXPORTVIEWER = Pointer;

//�������ڣ�hParentWnd���������ڣ�rcPos������������
//HEXPORTVIEWER __stdcall EVCreate(HWND hParentWnd, LPRECT prcPos);
  function EVCreate(hParentWnd: HWND; prcPos: PRect):HEXPORTVIEWER; stdcall;

//���ٴ���
//void __stdcall EVDestroy(HEXPORTVIEWER hViewer);
  procedure EVDestroy(hViewer: HEXPORTVIEWER); stdcall;

// ȡ��Ԥ������HWND���
//HSUBVIEW __stdcall EVGetHwnd(HEXPORTVIEWER hViewer);
  function EVGetHwnd(hViewer: HEXPORTVIEWER): HWND; stdcall;


//��ʾ�豸�޹�λͼ
//BOOL __stdcall EVShowDib(HEXPORTVIEWER hViewer, const LPBITMAPINFO lpbi, const LPBYTE pBits = 0);
  function EVShowDib(hViewer: HEXPORTVIEWER; const lpbi: PBITMAPINFO; const pBits : PBYTE = 0): BOOL; stdcall;

//��ʾYUVͼ��
//BOOL __stdcall EVShowImage(HEXPORTVIEWER hViewer, const LPBITMAPINFO lpbi, const LPBYTE pBits = 0);
  function EVShowImage(hViewer: HEXPORTVIEWER; const lpbi: PBITMAPINFO; const pBits : PBYTE = 0): BOOL; stdcall;

//��ʾYUVImageͼ��
//BOOL __stdcall EVShowYUVImage(HEXPORTVIEWER hViewer, const YUVImage * pImage);
  function EVShowYUVImage(hViewer: HEXPORTVIEWER;const pImage:PYUVImage):boolean;stdcall;

implementation

const
  DLLNAME = 'GLPlayer.dll';

  function EVCreate 						; external DLLNAME Name 'EVCreate';
  procedure EVDestroy						; external DLLNAME Name 'EVDestroy';
  function EVShowDib						; external DLLNAME Name 'EVShowDib';
  function EVShowImage					; external DLLNAME Name 'EVShowImage';
  function EVGetHwnd					  ; external DLLNAME Name 'EVGetHwnd';
  function EVShowYUVImage       ; external DLLNAME Name 'EVShowYUVImage';
end.
 