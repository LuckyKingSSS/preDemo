unit
	Language;

// Ϊ�˷�������Ե�֧�֣�  ���������ʹ�����ֵĵط�һ��ʹ
// �� MLGetText(const wchar_t* lpTextID)������ȡ
    
interface

uses
    Windows;


//int _stdcall MLInit(LPCTSTR lpPrefix); // lpPrefix - �����ļ���ǰ׺ ��չ��Ϊdat ���ؿ���������Ŀ
function MLInit(lpPrefix : PWideChar) : Integer; stdcall;

//void _stdcall MLClose();
procedure MLClose(); stdcall;

//int _stdcall MLGetLanguageCount();
function MLGetLanguageCount() : Integer; stdcall;

//const wchar_t* _stdcall MLGetLanguageName(int nLanguageIndex);
function MLGetLanguageName(nLanguageIndex : Integer) : PWideChar; stdcall;

//BOOL _stdcall MLLoadLanguageRes(int nLanguageIndex);
function MLLoadLanguageRes(nLanguageIndex : Integer) : BOOL; stdcall;

//BOOL __stdcall MLLoadLanguageResByName(LPCTSTR lpName);
function MLLoadLanguageResByName(lpName : PWideChar) : BOOL; stdcall;

//const wchar_t* __stdcall MLGetText(LPCTSTR lpTextID);
function MLGetText(lpTextID: PWideChar) : PWideChar; stdcall;

//const wchar_t* __stdcall MLGetImage(LPCTSTR lpImageID);
function MLGetImage(lpImageID: PWideChar) : PWideChar; stdcall;

//const wchar_t* __stdcall MLGetTextEx(LPCTSTR lpDir, LPCTSTR lpTextID); // ָ��TextĿ¼�µ����·�� ���lpTextID��lpDir�����ڣ� ����0
function MLGetTextEx(lpDir: PWideChar; lpTextID: PWideChar) : PWideChar; stdcall;

//const wchar_t* __stdcall MLGetAttribute(LPCTSTR lpTextID, LPCTSTR lpAttribName);
function MLGetAttribute(lpTextID: PWideChar; lpAttribName: PWideChar) : PWideChar; stdcall;

//const wchar_t* __stdcall MLGetAttributeEx(LPCTSTR lpDir, LPCTSTR lpTextID, LPCTSTR lpAttribName); // ָ��TextĿ¼�µ����·�� ���lpTextID��lpDir�����ڣ� ����0
function MLGetAttributeEx(lpDir: PWideChar; lpTextID: PWideChar; lpAttribName: PWideChar) : PWideChar; stdcall;


implementation

const
    DLLNAME = 'WS_Language.dll';

function MLInit								; external DLLNAME Name 'MLInit';
procedure MLClose							; external DLLNAME Name 'MLClose';
function MLGetLanguageCount					; external DLLNAME Name 'MLGetLanguageCount';
function MLGetLanguageName					; external DLLNAME Name 'MLGetLanguageName';
function MLLoadLanguageRes					; external DLLNAME Name 'MLLoadLanguageRes';
function MLLoadLanguageResByName			; external DLLNAME Name 'MLLoadLanguageResByName';
function MLGetText							; external DLLNAME Name 'MLGetText';
function MLGetImage							; external DLLNAME Name 'MLGetImage';
function MLGetTextEx						; external DLLNAME Name 'MLGetTextEx';

function MLGetAttribute						; external DLLNAME Name 'MLGetAttribute';
function MLGetAttributeEx					; external DLLNAME Name 'MLGetAttributeEx';


end.