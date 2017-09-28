#include "stdafx.h"

#include "ImportHelper.h"
#include <QImage>
#include "MatterConfigFileManager.h"
#include "inc_CommonLib/NLEWraper.h"
#include "inc_CommonLib/PlayerMaterProvider.h"
#include "inc_MatterView/MatterDataBase.h"
#include "MatterDataManager.h"
#include "MatterDataList.h"
#include "FileOperation.h"
#include "MatterDataDefine.h"



#define ThumbnailW 88
#define ThumbnailH 66

ImportHelper::ImportHelper(const QStringList &list,QObject *parent)
: QThread(parent)
, m_bUserCancel(false)
{
	fileNames = list;
}

ImportHelper::~ImportHelper()
{
	
}

void ImportHelper::run()
{
	if (!PreCheck()) return;
#ifdef WIN32
	::CoInitialize(0);
#endif
	m_bUserCancel = false;
	MediaData *pMatterData = nullptr;
	int nFileCnt = fileNames.size();
	int nFinished = 0;
	QString strProgressText = QString("%1/%2").arg(nFinished).arg(nFileCnt);
	emit signalImportProgressText(strProgressText);
	emit signalImportProgress(0);
	
	for (QString &fileName : fileNames)
	{
		if (m_bUserCancel) return;
		if (!FileOperation::IsFileExist(fileName)) continue;
		emit signalImportBegin(FileOperation::GetFileName(fileName));
		pMatterData = dynamic_cast<MediaData *>(CreateMatterData(fileName));
		if (!pMatterData) continue;
		MatterDataManager::GetInstance().GetMediaDataList()->AddItem(pMatterData);
		MatterConfigFileManager::GetInstance().AddMediaItem(pMatterData);

		++nFinished;
		strProgressText = QString("%1/%2").arg(nFinished).arg(nFileCnt);
		emit signalImportProgressText(strProgressText);
		emit signalImportProgress((float)nFinished / (float)nFileCnt * 100);

		emit signalImported(pMatterData);
	}
}

void ImportHelper::DoImportAsync()
{
	start();
}

void ImportHelper::UserCancel()
{
	m_bUserCancel = true;
}

bool ImportHelper::PreCheck()
{
	for (QString &fileName : fileNames)
	{
		if(MatterDataManager::GetInstance().GetMediaDataList()->FindItem(fileName))
		{
			fileNames.removeOne(fileName);
		}
	}
	return !fileNames.isEmpty();
}

MatterDataBase* ImportHelper::CreateMatterData(const QString &fullName)
{
	int nType = GetDataType(fullName);
	QString strCaption = GetCaption(fullName);
	QString strThumbnail = ExtractThumbnail(fullName, MatterDataManager::GetInstance().GetMediaDataList()->GetThumbnailDir(),nType);

	MediaData *pData = new MediaData(fullName);
	pData->strSourceFileUrl = fullName;
	pData->nResType = nType;
	pData->strCaption = strCaption;
	pData->strThumbFilePath = strThumbnail;
	pData->bVisible = true;
	return pData;
}

int ImportHelper::GetDataType(const QString &fullName)
{
	//static QString videoFilter = "*.wmv *.mov *.mp4 *.avi *.flv *.rmvb *.mkv";
	//static QString musicFilter = "*.mp3 *.mp2 *.wav *.wma";
	//static QString imageFilter = "*.bmp *.jpg *.png *.jpeg";

	QString strSuffix = FileOperation::GetFileSuffixName(fullName).toLower();

	if (ImportFilter[FilterType_Video][1].contains(strSuffix)) return MediaDataType_Video;
	if (ImportFilter[FilterType_Audio][1].contains(strSuffix)) return MediaDataType_Audio;
	if (ImportFilter[FilterType_Image][1].contains(strSuffix)) return MediaDataType_Image;

	return MediaDataType_All;
}

QString ImportHelper::GetCaption(const QString &fullName)
{
	return FileOperation::GetFileBaseName(fullName);
}

QString ImportHelper::ExtractThumbnail(const QString &fullName, const QString &saveDir,int nType)
{
	if (nType == MediaDataType_Video)
	{
		return ExtractVideoThumbnail(fullName, saveDir);
	}
	else if (nType == MediaDataType_Audio)
	{
		return ExtractMusicThumbnail(fullName, saveDir);
	}
	else if (nType == MediaDataType_Image)
	{
		return ExtractImageThumbnail(fullName, saveDir);
	}
	return "";
}

QString ImportHelper::ExtractVideoThumbnail(const QString &fullName, const QString &saveDir)
{

	//IMediaStream *pVideoStream = NULL, *pAudioStream = NULL;
	//NLEWraper::GetInstance().GetPlayerMaterProvider()->GetMediaStreamFromPath(fullName, &pVideoStream, &pAudioStream);

	//INLEThumbnailExtractor *pThumb = NULL;
	//NLEThumbnailExtractorLib::CreateNLEThumbExtractorInstance(&pThumb);
	//pThumb->SetVideoInput(pVideoStream, 1);
	//IThumbnail *pThumbnail = NULL;
	//pThumb->GetThumbnail(&pThumbnail);


	//LPBITMAPINFOHEADER ppbiHedader = NULL;
	//LPBYTE ppData = NULL;
	//pThumbnail->GetThumbData(&ppbiHedader, &ppData);


	//HDIBIMAGE pOrigThumbnail = DICreateIndirect((LPBYTE)ppbiHedader, ppData);
	//HDIBIMAGE pNewThumbnail = DICreate();
	//DISetContent(pNewThumbnail, ThumbnailW, ThumbnailH);
	////ippResize(pOrigThumbnail, pNewThumbnail, 1);

	//QString strFileName = FileOperation::GetFileBaseName(fullName);
	//QString strSaveFile = saveDir + "\\" + strFileName + ".bmp";
	//const wchar_t *saveFile = reinterpret_cast<const wchar_t *>(strSaveFile.utf16());

	//DISave(pNewThumbnail, saveFile);
	//DIDestroy(pNewThumbnail);
	//DIDestroy(pOrigThumbnail);

	//if (pThumbnail) pThumbnail->Release();
	//if (pThumb) pThumb->Release();
	//return strSaveFile;

	return "";
}

QString ImportHelper::ExtractMusicThumbnail(const QString &fullName, const QString &saveDir)
{
	QString strSaveFile = saveDir + "\\" + "Music.png";
	return strSaveFile;
}

QString ImportHelper::ExtractImageThumbnail(const QString &fullName, const QString &saveDir)
{

	//const wchar_t *strPath = reinterpret_cast<const wchar_t *>(fullName.utf16());
	//HDIBIMAGE pOrigThumbnail = DICreate();
	//DILoadImage32B(pOrigThumbnail, strPath);
	//HDIBIMAGE pNewThumbnail = DICreate();
	//DISetContent(pNewThumbnail, ThumbnailW, ThumbnailH);
	////ippResize(pOrigThumbnail, pNewThumbnail, 1);

	//QString strBaseName = FileOperation::GetFileBaseName(fullName);
	//QString strSaveFile = saveDir + "\\" + strBaseName + ".bmp";

	//const wchar_t *saveFile = reinterpret_cast<const wchar_t *>(strSaveFile.utf16());
	//DISave(pNewThumbnail, saveFile);
	//DIDestroy(pNewThumbnail);
	//DIDestroy(pOrigThumbnail);

	//return strSaveFile;

	return "";
}
