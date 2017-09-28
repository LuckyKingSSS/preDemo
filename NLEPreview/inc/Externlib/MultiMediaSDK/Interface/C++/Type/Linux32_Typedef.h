﻿// Linux32_Typedef.h
//

#pragma once
#include "wstypedef.h"
#ifndef WIN32
#define  UNICODE
#define  _UNICODE
#ifndef LINUX32_TYPEDEF
#define LINUX32_TYPEDEF

#pragma pack(push,1)

	#define TRUE  1
	#define FALSE 0
	
	#define __stdcall
	#define __cdecl
	#define APIENTRY
	#define WINAPI __stdcall
	#define CALLBACK __stdcall
	
	// add new define
	#define __declspec(dllexport) 
	#define  BOOL signed char
//	typedef long long int64_t;
//	typedef void* HANDLE;
//	typedef void* HMODULE;
//	typedef void* HPALETTE;
////	typedef unsigned int BOOL;
//#define  BOOL unsigned int
//	typedef unsigned int UINT;
//	typedef unsigned long ULONG;
//	typedef unsigned long long UINT64;
//	typedef unsigned long DWORD;
//	typedef unsigned short WORD;
//	typedef long LONG;
//	typedef unsigned char BYTE;
//	typedef BYTE* LPBYTE;
//	typedef BYTE* PBYTE;
//	typedef int64_t __int64;
////s	typedef unsigned int64_t uint64_t;
//	typedef void* LPVOID;
//	typedef DWORD* PDWORD;//, DWORD_PTR;
//	typedef DWORD* DWORD_PTR;
//	typedef WORD* LPWORD;
//
//	typedef long long WPARAM;
//	typedef long long LPARAM;
//	
//	//add new typedef
//	typedef int		INT;
//	typedef char	CHAR;
//	typedef short	SHORT;
//	typedef SHORT	*PSHORT;
//	typedef float	FLOAT;
//	typedef FLOAT	*PFLOAT;
//	typedef void	VOID;
//	typedef	const CHAR	*LPCSTR;
//	typedef CHAR	*LPSTR;
//	
//typedef unsigned char       uint8_t;
//typedef unsigned char       uint8_t;
//typedef signed char         int8_t;
//typedef unsigned short      uint16_t;
//typedef signed short        int16_t;
//typedef unsigned int        uint32_t;
//typedef signed int          int32_t;
//typedef long long  int64_t;
//typedef unsigned long long  uint64_t;

	
	#ifdef  UNICODE                     
		typedef wchar_t TCHAR;
		#define _T(x) L ## x
		#define _ttoi(x) atoi(W2A(x))
		#define _tstof(x) atof(W2A(x))
		#define _stscanf swscanf
		#define _tcstoul wcstoul
		#define lstrlen wcslen
		#define _tcslen wcslen
		#define lstrcpy wcscpy
		#define _tcscpy wcscpy
		#define lstrcat wcscat
		#define _tcscat wcscat
		#define _tcschr wcschr
		#define _tcsrchr wcsrchr
		#define _tcsicmp wcscmp
		#define _tcscmp wcscmp
		#define _tcsncpy wcsncpy

	#else
		typedef char TCHAR;
		#define _T(x) x
		#define _ttoi atoi
		#define _tstof atof
		#define _stscanf sscanf
		#define _tcstoul strtoul
		#define lstrlen strlen
		#define _tcslen strlen
		#define lstrcpy strcpy
		#define _tcscpy strcpy
		#define lstrcat strcat
		#define _tcscat strcat
		#define _tcschr strchr
		#define _tcsrchr strrchr
		#define _tcsncpy strncpy
		#define _tcsicmp strcmp
		#define _tcscmp strcmp
		#define _tcsncpy strncpy

	#endif
	
	typedef wchar_t WCHAR;
	typedef wchar_t *LPWSTR;

	typedef const TCHAR* LPCTSTR;
	typedef TCHAR*LPTSTR, PTSTR;
	
	typedef struct tagPOINT
	{
		LONG x;
		LONG y;
	} POINT, *PPOINT, *LPPOINT;
	
	typedef struct tagRECT
	{
		LONG left;
		LONG top;
		LONG right;
		LONG bottom;
	} RECT, *PRECT, *LPRECT;
	
	typedef DWORD COLORREF;
	

typedef struct tagSIZE {
	LONG cx;
	LONG cy;
}SIZE, *PSIZE, *LPSIZE;

typedef struct tagRGBQUAD {
    BYTE    rgbBlue;
    BYTE    rgbGreen;
    BYTE    rgbRed;
    BYTE    rgbReserved;
} RGBQUAD;
typedef RGBQUAD *LPRGBQUAD;

typedef struct tagBITMAPINFOHEADER{
    DWORD      biSize;
    LONG       biWidth;
    LONG       biHeight;
    WORD       biPlanes;
    WORD       biBitCount;
    DWORD      biCompression;
    DWORD      biSizeImage;
    LONG       biXPelsPerMeter;
    LONG       biYPelsPerMeter;
    DWORD      biClrUsed;
    DWORD      biClrImportant;
} BITMAPINFOHEADER,  *LPBITMAPINFOHEADER, *PBITMAPINFOHEADER;

typedef struct tagBITMAPINFO {
    BITMAPINFOHEADER    bmiHeader;
    RGBQUAD             bmiColors[1];
} BITMAPINFO,  *LPBITMAPINFO, *PBITMAPINFO;

typedef struct tagBITMAPFILEHEADER {
    WORD    bfType;
    DWORD   bfSize;
    WORD    bfReserved1;
    WORD    bfReserved2;
    DWORD   bfOffBits;
} BITMAPFILEHEADER,  *LPBITMAPFILEHEADER, *PBITMAPFILEHEADER;



/* flags for wFormatTag field of WAVEFORMAT */
#define WAVE_FORMAT_PCM     1

#ifndef _WAVEFORMATEX_
#define _WAVEFORMATEX_

/*
 *  extended waveform format structure used for all non-PCM formats. this
 *  structure is common to all non-PCM formats.
 */
typedef struct tWAVEFORMATEX
{
    WORD        wFormatTag;         /* format type */
    WORD        nChannels;          /* number of channels (i.e. mono, stereo...) */
    DWORD       nSamplesPerSec;     /* sample rate */
    DWORD       nAvgBytesPerSec;    /* for buffer estimation */
    WORD        nBlockAlign;        /* block size of data */
    WORD        wBitsPerSample;     /* number of bits per sample of mono data */
    WORD        cbSize;             /* the count in bytes of the size of */
                                    /* extra information (after cbSize) */
} WAVEFORMATEX, *PWAVEFORMATEX, *NPWAVEFORMATEX, *LPWAVEFORMATEX;

#endif /* _WAVEFORMATEX_ */
typedef const WAVEFORMATEX *LPCWAVEFORMATEX;


#pragma pack(pop)
	
#ifndef ARGB
	#define ARGB DWORD 
#endif
	
#ifndef RGB
	#define RGB(r,g,b)          ((COLORREF)(((BYTE)(r)|((WORD)((BYTE)(g))<<8))|(((DWORD)(BYTE)(b))<<16)))
#endif
	
#endif
	
#ifndef WM_USER
#define WM_USER                         0x0400
#endif

#ifndef MAX_PATH
#  define MAX_PATH 512
#endif

#ifndef NOERROR
#  define NOERROR 0
#endif

#ifndef CLASS_E_NOAGGREGATION
#  define CLASS_E_NOAGGREGATION 0x80040110L
#endif

#ifndef CLASS_E_CLASSNOTAVAILABLE
#  define CLASS_E_CLASSNOTAVAILABLE 0x80040111L
#endif

#ifndef CLASS_E_NOTLICENSED
#  define CLASS_E_NOTLICENSED 0x80040112L
#endif

#endif



