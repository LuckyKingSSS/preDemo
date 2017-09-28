#pragma once
#include "typedef.hpp"
/*! \file MetaDataInfo.h
* \brief	ý���ļ�MetaData��Ϣ(��ID3��Ϣ)
*/

enum vKind
{
	none = 1,
	tvShow = 10,
	movie = 9,
	homeVideo = 0,
};

enum ContentRating
{
	Norated,
	G,
	PG,
	PG13,
	R,
	NC17,
	Unrated,
	TVY,
	TVY7,
	TVG,
	TVPG,
	TV14,
	TVMA,
};
enum Definition
{
	SD,
	HD,
};


enum ImageFormat
{
	WS_JPEG,
	WS_BMP,
	WS_PNG,
};

typedef struct ImageData
{
	BYTE *data;
	ULONG size;
	ImageFormat format;
}ID3Pic;


/*!
* \struct MetaDataInfo
* \brief ý���ļ�MetaData��Ϣ(��ID3��Ϣ)
*/
typedef struct _MetaDataInfo
{
	/*! ������*/
	wchar_t szArtist[260];  

	/*! ����*/
	wchar_t szTitle[260];          

	/*! �����*/
	wchar_t szTrackNumber[260];    

	/*! ר��*/
	wchar_t szAlbum[260];           

	/*! ���*/
	wchar_t szDate[260];           

	/*! ���*/
	wchar_t szGenre[260];    

	/*! ������*/
	wchar_t szPublisher[260];   

	wchar_t szShow[260];
	vKind videoKind;
	wchar_t szReleaseDate[260];
	int season;
	int episode;
	wchar_t szActor[2600];
	wchar_t szDirector[2600];
	wchar_t szProducer[2600];
	wchar_t szScreenwriter[2600];
	wchar_t szTagline[260];
	wchar_t szDescription[500];
	wchar_t szComment[500];
	wchar_t szTvnetwork[500];
	ImageData *imagedata;
	ContentRating contentRating;
	Definition def;

	//METADATA_INFO_RELEASE_API   fnRelease;

} MetaDataInfo;
