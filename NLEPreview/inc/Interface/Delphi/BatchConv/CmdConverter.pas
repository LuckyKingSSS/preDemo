
unit
  CmdConverter;

{$MINENUMSIZE 4}

interface

uses
    Windows, Messages;

//------------------------------------------------------------------------------
// wParam��Ϊ0ʱ��ʾ��ͣ
//#define UM_CONV_PAUSE (WM_APP + 900)
const UM_CONV_PAUSE = (WM_APP + 900);

//------------------------------------------------------------------------------
// wParam Ϊ1��ʾ��ʾ��Ϊ0��ʾ����ʾ
//#define UM_SHOW_PREVIEW (WM_APP + 903)
const UM_SHOW_PREVIEW = (WM_APP + 903);

//------------------------------------------------------------------------------
// ��ʼת��
//#define UM_RUN_CONV (WM_APP + 904)
const UM_RUN_CONV = (WM_APP + 904);

//------------------------------------------------------------------------------
// ǿ����ֹ
//#define UM_FORCE_TERM (WM_APP + 906)
const UM_FORCE_TERM = (WM_APP + 906);

//------------------------------------------------------------------------------
// ����GetProgressInfo()
//#define UM_GET_PROGRESS_INFO (WM_APP + 907)
const UM_GET_PROGRESS_INFO = (WM_APP + 907);

//------------------------------------------------------------------------------
//#define UM_CONVERT_PROGRESS_WRAP   (WM_APP + 930)
const UM_CONVERT_PROGRESS_WRAP  = (WM_APP + 930);
// HIWORD(wParam)
// LOWROD(wParam) -  0 ����  lParam - ����(LOWORD:�ܽ��� HIWORD:��ǰ������� 0-100)  ��ϸ��Ϣ��ʹ�� BCGetProgressInfo
//           1 ת�����  wParam - 0 �������  1 �û���ֹ 2 �ⲿ�ص���ֹ 3 ��������
//         100 �ڶ��ν��ȿ�ʼ
//           101 ������Ϣ  lParam - ����(0-100)
//         110 �ڶ��ν��Ƚ��� �ڵڶ��ν����ڼ� ���ܵ���WEPause��WEStop����
// 	  1000 ��ʼ������


//#define UM_CONVERT_END_WRAP        (WM_APP + 931)
const UM_CONVERT_END_WRAP    =    (WM_APP + 931);

//#define UM_CONVERT_ERROR_WRAP      (WM_APP + 932)
const UM_CONVERT_ERROR_WRAP   =   (WM_APP + 932);

implementation


end.