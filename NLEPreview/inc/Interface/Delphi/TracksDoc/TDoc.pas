unit
	TDoc;

{$MINENUMSIZE 4}
    
    
interface

uses
    Windows, TClip;

type
    HTRACK = Pointer;
    HTLDOC = Pointer;
    PHCLIP = ^HCLIP;

// ������Ͷ���
type
TrackType = 
(
	TT_NONE,			// δ֪����
	TT_VIDEO,			// ��Ƶ���
	TT_AUDIO,			// ��Ƶ���
	TT_OVERLAP			// ���ӹ��	
);


//==========================================================================
// Timeline Track����

//TrackType __stdcall TTGetType(HTRACK hTrack);
function TTGetType(hTrack: HTRACK) : TrackType; stdcall;

//double __stdcall TTGetLength(HTRACK hTrack); // ���ع����Ч����
function TTGetLength(hTrack: HTRACK) : double; stdcall;


// �����������ת������ģ�����clip

//int __stdcall TTGetClipCount(HTRACK hTrack);
function TTGetClipCount(hTrack: HTRACK) : Integer; stdcall;

//HCLIP __stdcall TTGetClip(HTRACK hTrack, int nIndex);
function TTGetClip(hTrack: HTRACK; nIndex : Integer) : HCLIP; stdcall;

//int __stdcall TTGetTransClipCount(HTRACK hTrack);
function TTGetTransClipCount(hTrack: HTRACK) : Integer; stdcall;

//HTRANSCLIP __stdcall TTGetTransClip(HTRACK hTrack, int nIndex);
function TTGetTransClip(hTrack: HTRACK; nIndex : Integer) : HCLIP; stdcall;


//int __stdcall TTInsertClipIndex(HTRACK hTrack, HCLIP hClip, int nBeforeIndex = -1); // ��hClip��������ΪnBeforeIndex��Clip��ǰ�棬nBeforeIndexΪ-1��ʾ���뵽���β�� ������Clip������ֵ clip������ת��clip
function TTInsertClipIndex(hTrack: HTRACK; hClip : HCLIP; nBeforeIndex : Integer = -1) : Integer; stdcall;

//int __stdcall TTInsertClip(HTRACK hTrack, HCLIP hClip, HCLIP hClipExist); //��hClip���뵽hClipExist��ǰ�� hClipExistΪ0��ʾ���뵽���β��
function TTInsertClip(hTrack: HTRACK; hClip : HCLIP; hClipExist : HCLIP) : Integer; stdcall;

//BOOL __stdcall TTEraseClip(HTRACK hTrack, HCLIP hClip); // ɾ��hClip
function TTEraseClip(hTrack: HTRACK; hClip : HCLIP) : BOOL; stdcall;

//BOOL __stdcall TTEraseClipIndex(HTRACK hTrack, int nIndex); // ɾ������ΪnIndex��clip
function TTEraseClipIndex(hTrack: HTRACK; nIndex : Integer) : BOOL; stdcall;


//int __stdcall TTMoveClips(HTRACK hTrack, int nIndexExist, int nStartIndex, int nClipCount, BOOL bCopyFlag = FALSE); // ����nStartIndex��ʼ��nClipCount��clip�ƶ�������ΪnIndexExist��clip��ǰ��
// ���ر��ƶ��ĵ�һ��clip��������ֵ TCGetIndex ��������ȡ��clip�������ڹ���е�λ�õ�������
function TTMoveClips(hTrack: HTRACK; nIndexExist : Integer; nStartIndex : Integer; nClipCount : Integer; bCopyFlag : BOOL = FALSE) : Integer; stdcall;


//extern "C" HCLIP __stdcall TTSetClipTailTransID(HTRACK hTrack, HCLIP hClip, const wchar_t* pTransID, double dLength = -1); // ����β��ת�� ����ת��Clip��� 
function TTSetClipTailTransID(hTrack: HTRACK; hClip : HCLIP; const pTransID : PWideChar; dLength : double = -1) : HCLIP; stdcall;

//BOOL __stdcall TTSetClipTailTrans(HTRACK hTrack, HCLIP hClip, HTRANSCLIP hTransClip); // ����β��ת��
function TTSetClipTailTrans(hTrack: HTRACK; hClip : HCLIP; hTransClip : HCLIP) : BOOL; stdcall;

//extern "C" BOOL __stdcall TTAddFile(HTRACK hTrack, const wchar_t* pFileName, const wchar_t* pTransID = 0, double dLength = 0); // pTransID ת��ID
function TTAddFile(hTrack: HTRACK; const pFileName : PWideChar; const pTransID : PWideChar = nil; dLength : double = 0) : BOOL; stdcall;

//void __stdcall TTDeleteSelectedClips(HTRACK hTrack); // ɾ��ѡ��
procedure TTDeleteSelectedClips(hTrack: HTRACK); stdcall;

//void __stdcall TTDeleteAllClips(HTRACK hTrack); // ɾ������
procedure TTDeleteAllClips(hTrack: HTRACK); stdcall;

//void __stdcall TTAdjustClipPos(HTRACK hTrack);
procedure TTAdjustClipPos(hTrack: HTRACK); stdcall;

//BOOL __stdcall TTSetAutoAdjust(HTRACK hTrack, BOOL bFlag = TRUE); // ������ǰ��ֵ
function TTSetAutoAdjust(hTrack: HTRACK; bFlag : BOOL = TRUE) : BOOL; stdcall;

//void __stdcall TTSetVolume(HTRACK hTrack, int nVolume);
procedure TTSetVolume(hTrack: HTRACK; nVolume : Integer); stdcall;

//int __stdcall TTGetVolume(HTRACK hTrack);
function TTGetVolume(hTrack: HTRACK) : Integer; stdcall;



//==========================================================================
// �ĵ��ӿں���

//HTRACK __stdcall TDGetTrack(HTLDOC hDoc, TrackType uTrackType, int nIndex); // ��ȡuTrackType���͵�����ΪnIndex�Ĺ�����
function TDGetTrack(hDoc: HTLDOC; uTrackType : TrackType; nIndex : Integer) : HTRACK; stdcall;

//int __stdcall TDGetTracksCount(HTLDOC hDoc); 
function TDGetTracksCount(hDoc: HTLDOC) : Integer; stdcall;

//int __stdcall TDGetTypeTrackCount(HTLDOC hDoc, TrackType uType);
function TDGetTypeTrackCount(hDoc: HTLDOC; uType : TrackType) : Integer; stdcall;

//double __stdcall TDGetLength(HTLDOC hDoc); // �����ĵ���Ч����
function TDGetLength(hDoc: HTLDOC) : double; stdcall;

//void __stdcall TDDeleteSelectedClips(HTLDOC hDoc);
procedure TDDeleteSelectedClips(hDoc: HTLDOC); stdcall;

//void __stdcall TDDeleteAllClips(HTLDOC hDoc);
procedure TDDeleteAllClips(hDoc: HTLDOC); stdcall;


//HCLIP __stdcall TDGetFocusClip(HTLDOC hDoc); // ȡ�ý���Clip
function TDGetFocusClip(hDoc: HTLDOC) : HCLIP; stdcall;

//void __stdcall TDSetFocusClip(HTLDOC hDoc, HCLIP hClip); // ���ý���Clip
procedure TDSetFocusClip(hDoc: HTLDOC; hClip : HCLIP); stdcall;

//BOOL __stdcall TDSelectAddClip(HTLDOC hDoc, HCLIP hClip, BOOL bClearOld = FALSE); // ѡ��clip, bClearOld - �Ƿ������ǰ��ѡ��
function TDSelectAddClip(hDoc: HTLDOC; hClip : HCLIP; bClearOld : BOOL = FALSE) : BOOL; stdcall;

//BOOL __stdcall TDSelectEraseClip(HTLDOC hDoc, HCLIP hClip); // ��ѡ����ȥ��clip
function TDSelectEraseClip(hDoc: HTLDOC; hClip : HCLIP) : BOOL; stdcall;

//BOOL __stdcall TDSelectClear(HTLDOC hDoc); // ���ѡ��
function TDSelectClear(hDoc: HTLDOC) : BOOL; stdcall;

//int __stdcall TDSelectAllClips(HTLDOC hDoc); // ѡ�����е�Ԫ�أ�����ѡ�е�Ԫ�ظ���������ת��
function TDSelectAllClips(hDoc: HTLDOC) : Integer; stdcall;


// ȡ������ѡ��
//int __stdcall TDGetSelectedClips(HTLDOC hDoc, HCLIP* pClips, int nCount); // ȡ����ͨClipѡ�� pClips - HCLIP����ָ�� nCount - ����������
// �������뻺������clip���� ���pClipsΪ0����ֱ�ӷ��ص�ǰѡ��clip������
function TDGetSelectedClips(hDoc: HTLDOC; pClips : PHCLIP; nCount : Integer) : Integer; stdcall;

//int __stdcall TDGetSelectedTransClips(HTLDOC hDoc, HTRANSCLIP* pClips, int nCount); // ȡ��ת��Clipѡ�� ��������ͬ TDGetSelectedClips
function TDGetSelectedTransClips(hDoc: HTLDOC; pClips : PHCLIP; nCount : Integer) : Integer; stdcall;

//BOOL __stdcall TDSelectedIsContinuous(HTLDOC hDoc); // ��ǰѡ���Ƿ����� ����ת��
function TDSelectedIsContinuous(hDoc: HTLDOC) : BOOL; stdcall;

//BOOL __stdcall TDSelectedIsContinuousWithTrans(HTLDOC hDoc); // ��ǰѡ�񼯣���ת�����Ƿ����� ����ѡ�е���ͨclip��ת��Clip�ܹ���һ������������
function TDSelectedIsContinuousWithTrans(hDoc: HTLDOC) : BOOL; stdcall;



implementation

const
    DLLNAME = 'WS_Timeline.dll';

function TTGetType; external DLLNAME Name 'TTGetType';
function TTGetLength; external DLLNAME Name 'TTGetLength';
function TTGetClipCount; external DLLNAME Name 'TTGetClipCount';
function TTGetClip; external DLLNAME Name 'TTGetClip';
function TTGetTransClipCount; external DLLNAME Name 'TTGetTransClipCount';
function TTGetTransClip; external DLLNAME Name 'TTGetTransClip';
function TTInsertClipIndex; external DLLNAME Name 'TTInsertClipIndex';
function TTInsertClip; external DLLNAME Name 'TTInsertClip';
function TTEraseClip; external DLLNAME Name 'TTEraseClip';
function TTEraseClipIndex; external DLLNAME Name 'TTEraseClipIndex';
function TTMoveClips; external DLLNAME Name 'TTMoveClips';
function TTSetClipTailTransID; external DLLNAME Name 'TTSetClipTailTransID';
function TTSetClipTailTrans; external DLLNAME Name 'TTSetClipTailTrans';
function TTAddFile; external DLLNAME Name 'TTAddFile';
procedure TTDeleteSelectedClips; external DLLNAME Name 'TTDeleteSelectedClips';
procedure TTDeleteAllClips; external DLLNAME Name 'TTDeleteAllClips';
procedure TTAdjustClipPos; external DLLNAME Name 'TTAdjustClipPos';
function TTSetAutoAdjust; external DLLNAME Name 'TTSetAutoAdjust';
procedure TTSetVolume; external DLLNAME Name 'TTSetVolume';
function TTGetVolume; external DLLNAME Name 'TTGetVolume';

function TDGetTrack; external DLLNAME Name 'TDGetTrack';
function TDGetTracksCount; external DLLNAME Name 'TDGetTracksCount';
function TDGetTypeTrackCount; external DLLNAME Name 'TDGetTypeTrackCount';
function TDGetLength; external DLLNAME Name 'TDGetLength';
procedure TDDeleteSelectedClips; external DLLNAME Name 'TDDeleteSelectedClips';
procedure TDDeleteAllClips; external DLLNAME Name 'TDDeleteAllClips';
function TDGetFocusClip; external DLLNAME Name 'TDGetFocusClip';
procedure TDSetFocusClip; external DLLNAME Name 'TDSetFocusClip';
function TDSelectAddClip; external DLLNAME Name 'TDSelectAddClip';
function TDSelectEraseClip; external DLLNAME Name 'TDSelectEraseClip';
function TDSelectClear; external DLLNAME Name 'TDSelectClear';
function TDGetSelectedClips; external DLLNAME Name 'TDGetSelectedClips';
function TDGetSelectedTransClips; external DLLNAME Name 'TDGetSelectedTransClips';
function TDSelectedIsContinuous; external DLLNAME Name 'TDSelectedIsContinuous';
function TDSelectedIsContinuousWithTrans; external DLLNAME Name 'TDSelectedIsContinuousWithTrans';
function TDSelectAllClips; external DLLNAME Name 'TDSelectAllClips';



end.



