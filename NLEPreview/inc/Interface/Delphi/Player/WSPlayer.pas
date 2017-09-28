unit WSPlayer;

{$WARNINGS OFF}

interface

uses
  Windows, Messages, CodecDefine;

{typedef void *HPLAYER;
typedef void *HVIDEODECODER;
typedef void *HAUDIODECODER;}



type
  HPLAYER = Pointer;
  HVIDEODECODER = Pointer;
  HAUDIODECODER = Pointer;
  HVDPROCESS = HVIDEODECODER;
  HADPROCESS = HAUDIODECODER;
  IDVPVIEW = UINT;

  HVIEW = HWND;
  HSUBVIEW = HWND;


const
  WM_PLAYERMSG = WM_USER + 2001; //��������Ϣ
  //��Ϣ����wParam
  PM_Progress = 1; //�����У�����VPGetPlayedTimeȡ�ò���ʱ���Լ������
  PM_Finish = 2;   //���Ž������Զ������Ż�Post����Ϣ��
  
  UM_CROP_CHANGE = (WM_USER + 4326); // Crop���������Ϣ
  
 

//����������
//HPLAYER __stdcall VPCreate();
function  VPCreate(): HPLAYER; stdcall;

//���ٲ�����
//void __stdcall VPDestroy(HPLAYER hPlayer);
procedure VPDestroy(hPlay: HPLAYER);stdcall;

//�趨������
//void __stdcall VPSetDecoder(HPLAYER hPlayer, HVIDEODECODER hVideo, HAUDIODECODER hAudio);
procedure VPSetDecoder(hPlay: HPLAYER; hVideo: HVIDEODECODER; hAudio: HAUDIODECODER);stdcall;

//����VPSetDecoder���趨decoder���õ���Ƶ�γ���
//double __stdcall VPGetMovieLength(HPLAYER hPlayer);
function  VPGetMovieLength(hPlayer:HPLAYER):double;stdcall;


//������Ƶ����ʱ�䣬 dBegin������ʼʱ�䣬dLength��������ʱ�䣬Ϊ0���ŵ���β
//void __stdcall VPSetPlayTime(HPLAYER hPlayer, double dBegin, double dLength);
procedure VPSetPlayTime(hPlayer: HPLAYER; dBegin: Double; dLength: Double);stdcall;

//���ţ�dBegin������ʼʱ�䣬dLength��������ʱ��
//void __stdcall VPPlay(HPLAYER hPlayer, double dBegin, double dLength);
procedure  VPPlay(hPlay: HPLAYER);stdcall;

//ֹͣ����
//void __stdcall VPStop(HPLAYER hPlayer);
procedure VPStop(hPlay: HPLAYER);stdcall;

//��ͣ
//void __stdcall VPPause(HPLAYER hPlayer);
procedure VPPause(hPlay: HPLAYER);stdcall;

//�ָ�
//void __stdcall VPResume(HPLAYER hPlayer);
procedure VPResume(hPlay: HPLAYER);stdcall;

//��λ��dTime,dTimeΪ���ʱ�� ��VPSetPlayTime���õ�dBeginΪ��׼
//void __stdcall VPSeek(HPLAYER hPlayer, double dTime, BOOL accurate = TRUE);
procedure VPSeek(hPlay:HPLAYER; dTime: Double; accurate : BOOL = TRUE);stdcall;

//��֡ǰ�������ȵ���VPPause
//void __stdcall VPForward(HPLAYER hPlayer);
procedure VPForward(hPlay: HPLAYER); stdcall;

//����ص�����,��ϢΪWM_PLAYERMSG,wParam������PM_Progress,PM_Finish����
//void __stdcall VPSetCallBack(HPLAYER hPlayer, HWND hCBWnd);
procedure VPSetCallBack(hPlay: HPLAYER; hCBWnd: HWND);stdcall;

//ȡ�ò���ʱ��,�����VPSetPlayTime��dBegin,0��dLength
//double __stdcall VPGetPlayedTime(HPLAYER hPlayer);
function VPGetPlayedTime(hPlay: HPLAYER): Double; stdcall;

//����,0~200, 100����ԭ����
//int __stdcall VPSetVolume(HPLAYER hPlayer, int nValue);
function VPSetVolume(hPlay: HPLAYER; nValue : Integer) : Integer; stdcall;


//��������������rcPos������λ��,����0��ʾʧ�ܣ�>0�ɹ�
// ˫��������Ŀ�겥���� nViewMode ����Ϊ1
//IDVPVIEW __stdcall VPCreateView(HPLAYER hPlayer, HVIEW hWndParent, LPRECT pRect, int nViewMode = 0);
function VPCreateView(hPlay: HPLAYER; hWndParent : HWND; PRect : PRECT; nViewMode : Integer = 0) : IDVPVIEW; stdcall;

//���ٲ���������
//void __stdcall VPDestroyView(HPLAYER hPlayer, IDVPVIEW id);
procedure VPDestroyView(hPlay: HPLAYER; id : IDVPVIEW); stdcall;

//ȡ�ò������Ӵ��ھ��
//HSUBVIEW __stdcall VPGetPlayerHwnd(HPLAYER hPlayer, IDVPVIEW id);
function VPGetPlayerHwnd(hPlay: HPLAYER; id : IDVPVIEW): HWND; stdcall;

//ȡ��VideoDataProcess���
//HVDPROCESS __stdcall VPGetVDataProcessHandle(HPLAYER hPlayer, IDVPVIEW id);
function VPGetVDataProcessHandle(hPlay: HPLAYER; id : IDVPVIEW): HVDPROCESS; stdcall;

//ȡ��ʾ��Ϣ
//IMAGE_RESIZE_METHOD __stdcall VPGetDisplayResizeMode(HPLAYER hPlayer, IDVPVIEW id);
function VPGetDisplayResizeMode(hPlay: HPLAYER; id : IDVPVIEW): IMAGE_RESIZE_METHOD; stdcall;

//���ò��ű���������һ��Ϊ0��ԭ��Ƶ������Ĭ��Ϊ0
//BOOL __stdcall VPSetDisplayResizeMode(HPLAYER hPlayer, IDVPVIEW id, IMAGE_RESIZE_METHOD irm);
function VPSetDisplayResizeMode(hPlay: HPLAYER; id : IDVPVIEW; irm: IMAGE_RESIZE_METHOD): BOOL; stdcall;


// Crop���������Ϣ
//#define UM_CROP_CHANGE		(WM_USER + 4326)

// ���ò��������ڵı༭ģʽ
//void __stdcall VPSetCropEditStyle(HPLAYER hPlayer, IDVPVIEW id, UINT uCropStyle = 1);
procedure VPSetCropEditStyle(hPlay: HPLAYER; id : IDVPVIEW; uCropStyle: UINT = 1);stdcall;

// ����Crop����  ͼ������ �Ǵ�������
//void __stdcall VPSetCropRect(HPLAYER hPlayer, IDVPVIEW id, LPRECT pCropRect);
procedure VPSetCropRect(hPlay: HPLAYER; id : IDVPVIEW; pCropRect: PRECT);stdcall;

// ��ȡCrop����  ͼ������ �Ǵ�������
//void __stdcall VPGetCropRect(HPLAYER hPlayer, IDVPVIEW id, LPRECT pCropRect);
procedure VPGetCropRect(hPlay: HPLAYER; id : IDVPVIEW; pCropRect: PRECT);stdcall;

//ˢ����ʾ
//void __stdcall VPUpdate(HPLAYER hPlayer);
procedure VPUpdate(hPlay: HPLAYER); stdcall;

// // �������Ƿ��ڻ״̬���������ڲ��ź�Pause״̬
// 0 - ���״̬�� 1- ���ڲ��ţ� 2 - ��ͣ״̬
//BOOL __stdcall VPIsActivate(HPLAYER hPlayer);
function VPIsActivate(hPlayer:HPLAYER):integer;stdcall;
//int __stdcall VPIsActivate(HPLAYER hPlayer);
// 0 - ���״̬�� 1- ���ڲ��ţ� 2 - ��ͣ״̬
//function VPIsActivate(hPlayer:HPLAYER): Integer;stdcall;


const
// Message Code:
//#define VM_SAVE_IMAGE			0x0100 // wParam - LPBITMAPINFO  lParam - file name (char*)
  VM_SAVE_IMAGE		    =	$0100;
//#define VM_SAVE_YUV_2_BMP		0x0101 // wParam - const YUVImage *  lParam - file name (char*)
  VM_SAVE_YUV_2_BMP		= $0101;

//#define VM_FULL_SPEED			0x0800
  VM_FULL_SPEED			  = $0800;
//#define VM_NORMAL_SPEED			0x0801
  VM_NORMAL_SPEED			= $0801;
//#define VM_GET_SPEED			0x0802 // ȡ�õ�ǰ������ÿ�벥�ŵ�֡��
  VM_GET_SPEED			  = $0802;

//DWORD __stdcall VPSendCommand(HPLAYER hPlayer, UINT uMsg, WPARAM wParam, LPARAM lParam);
  function  VPSendCommand(hPlayer:HPLAYER; uMsg:UINT; wParam:WPARAM; lParam:LPARAM):DWORD;stdcall;

implementation

const
  DLLNAME = 'WSPlayer.dll';

function  VPCreate                    ; external DLLNAME Name 'VPCreate';
procedure VPDestroy                   ; external DLLNAME Name 'VPDestroy';
procedure VPSetDecoder                ; external DLLNAME index 3;
function  VPGetMovieLength            ; external DLLNAME Name 'VPGetMovieLength';
procedure VPSetPlayTime               ; external DLLNAME Name 'VPSetPlayTime';
procedure VPPlay                      ; external DLLNAME Name 'VPPlay';
procedure VPStop                      ; external DLLNAME Name 'VPStop';
procedure VPPause                     ; external DLLNAME Name 'VPPause';
procedure VPResume                    ; external DLLNAME Name 'VPResume';
procedure VPSeek                      ; external DLLNAME Name 'VPSeek';
procedure VPForward                   ; external DLLNAME Name 'VPForward';
procedure VPSetCallBack               ; external DLLNAME Name 'VPSetCallBack';
function  VPGetPlayedTime             ; external DLLNAME Name 'VPGetPlayedTime';
function VPSetVolume                  ; external DLLNAME Name 'VPSetVolume';
function  VPCreateView                ; external DLLNAME Name 'VPCreateView';
procedure VPDestroyView               ; external DLLNAME Name 'VPDestroyView';
function  VPGetVDataProcessHandle     ; external DLLNAME Name 'VPGetVideoDataProcessHandle';
function  VPGetPlayerHwnd             ; external DLLNAME Name 'VPGetPlayerHwnd';
function  VPGetDisplayResizeMode      ; external DLLNAME Name 'VPGetDisplayResizeMode';
function  VPSetDisplayResizeMode      ; external DLLNAME Name 'VPSetDisplayResizeMode';

procedure VPSetCropEditStyle          ; external DLLNAME Name 'VPSetCropEditStyle';
procedure VPSetCropRect               ; external DLLNAME Name 'VPSetCropRect';
procedure VPGetCropRect               ; external DLLNAME Name 'VPGetCropRect';

procedure VPUpdate                    ; external DLLNAME Name 'VPUpdate';

function  VPIsActivate                ; external DLLNAME Name 'VPIsActivate';

function  VPSendCommand               ; external DLLNAME Name 'VPSendCommand';

end.
 