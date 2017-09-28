#include "stdafx.h"
#include "MatterDataList.h"
#include "MatterDataBase.h"
#include "XmlOperation.h"
#include "FileOperation.h"
#include "PathOperation.h"
#include "MatterConfigFileManager.h"
#include "NLEWraper.h"
#include "PlayerMaterProvider.h"
#include "MatterDataDefine.h"
#include "inc_CommonLib/NLEWraper.h"
#include "inc_CommonLib/PlayerMaterProvider.h"
#include "inc_CommonLib/NLETimeline.h"
#include "Include/NLEPropComPtr/NLEKeyShortcut.h"
#include "Shared/NLECommon.h"
#include <QUuid>

MatterDataList::MatterDataList(const QString &strConfigFile,QObject *parent)
	: QObject(parent)
	, m_strConfigFile(strConfigFile)
{

}

MatterDataList::~MatterDataList()
{
	for (MatterDataBase *pData : m_vecDatas)
	{
		if (pData) delete pData;
	}
	m_vecDatas.clear();
}

bool MatterDataList::AddItem(MatterDataBase* pItem)
{
	if (!pItem) return false;
	if (!m_vecDatas.contains(pItem))
	{
		m_vecDatas.push_back(pItem);
	}
	return true;
}

void MatterDataList::RemoveItem(const QString &strId)
{
	for (MatterDataBase *pItem : m_vecDatas)
	{
		if (pItem->strId == strId)
		{
			delete pItem;
			m_vecDatas.removeOne(pItem);
			return;
		}
	}
}

MatterDataBase* MatterDataList::FindItem(const QString &strId)
{
	for (MatterDataBase *pItem : m_vecDatas)
	{
		if (pItem->strId == strId)
		{
			return pItem;
		}
	}
	return nullptr;
}

QVector<MatterDataBase*>& MatterDataList::GetDataList()
{
	return m_vecDatas;
}

QString MatterDataList::GetThumbnailDir()
{
	return m_strThumbnailDir;
}

//MediaDataList
/////////////////////////////////////////////////////////////
MediaDataList::MediaDataList(const QString &strConfigFile, QObject *parent)
:MatterDataList(strConfigFile,parent)
{

}

MediaDataList::~MediaDataList()
{

}

void MediaDataList::InitDataList()
{
	QList<MediaData*> listToRemove;
	QDomDocument doc;
	if (!XmlOperation::OpenXmlFile(doc, m_strConfigFile)) return;
	QDomElement rootElem = doc.documentElement();
	QDomElement fileResElem = rootElem.firstChildElement();
	while (!fileResElem.isNull())
	{
		if (fileResElem.tagName() == "Config")
		{
			QDomElement dirElem = fileResElem.firstChildElement();
			while (!dirElem.isNull())
			{
				if (dirElem.tagName() == "ThumbFileDir")
				{
					m_strThumbnailDir = PathOperation::MakeWorkPath(dirElem.text());
				}
				dirElem = dirElem.nextSiblingElement();
			}
		}
		else if (fileResElem.tagName() == "FileResourceInfo")
		{
			MediaData *pData = new MediaData(fileResElem.attribute("id"));
			QDomElement dataElem = fileResElem.firstChildElement();
			while (!dataElem.isNull())
			{
				if (dataElem.tagName() == "ResType")
				{
					pData->nResType = dataElem.text().toInt();
				}
				else if (dataElem.tagName() == "SourceFileUrl")
				{
					pData->strSourceFileUrl = dataElem.text();
				}
				else if (dataElem.tagName() == "Caption")
				{
					pData->strCaption = dataElem.text();
				}
				else if (dataElem.tagName() == "ResourceTag")
				{
					pData->strResourceTag = dataElem.text();
				}
				else if (dataElem.tagName() == "ThumbFileName")
				{
					pData->strThumbFilePath = m_strThumbnailDir + "\\" + dataElem.text();
				}
				else if (dataElem.tagName() == "Visible")
				{
					pData->bVisible = dataElem.text() == 0 ? false : true;
				}
				dataElem = dataElem.nextSiblingElement();
			}
			if (FileOperation::IsFileExist(pData->strSourceFileUrl))
			{
				if (!AddItem(pData)) listToRemove << pData;
			}
			else
			{
				listToRemove << pData;
			}
		}
		fileResElem = fileResElem.nextSiblingElement();
	}
	if (listToRemove.isEmpty()) return;
	for (MediaData *pData : listToRemove)
	{
		MatterConfigFileManager::GetInstance().RemoveMediaItem(pData);
		delete pData;
	}
}

QVector<MediaData*> MediaDataList::GetDatasWithResType(int nResType)
{
	return QVector<MediaData*>();
}

QVector<MediaData*> MediaDataList::GetDatasWithResourceTag(const QString &strTag)
{
	return QVector<MediaData*>();
}

bool MediaDataList::AddItem(MatterDataBase* pItem)
{
	MediaData *pMediaData = dynamic_cast<MediaData*>(pItem);
	if (!pMediaData) return false;

	if (pMediaData->nResType == MediaDataType_Video || 
		pMediaData->nResType == MediaDataType_Audio ||
		pMediaData->nResType == MediaDataType_Image)
	{
		ExactType etype = ExactType_Unknown;
		if (pMediaData->nResType == MediaDataType_Video)
		{
			etype = ExactType_Video;
		}
		else if (pMediaData->nResType == MediaDataType_Audio)
		{
			etype = ExactType_Audio;
		}
		else
		{
			etype = ExactType_Image;
		}
		NLEComPtr<INLETimelineBase> pTimeline  = NLEWraper::GetInstance().GetPlayerMaterProvider()->CreateMediaTimeline(pMediaData->strSourceFileUrl);
		Q_ASSERT(pTimeline != nullptr);
		pMediaData->pTimeline = new NLETimeline(pTimeline,etype);
		pMediaData->pTimeline->SetName(pItem->strCaption);
	}

	return MatterDataList::AddItem(pMediaData);
}

NLETimeline* MediaDataList::GetTimelineByGuid(const QString &strGuid)
{
	for (auto matterdata : m_vecDatas)
	{
		MediaData *pMediaData = dynamic_cast<MediaData *>(matterdata);
		if (!pMediaData) continue;
		
		GUID guid = pMediaData->pTimeline->GetGuid();
		QUuid uuid(guid.Data1, guid.Data2, guid.Data3, 
			guid.Data4[0], guid.Data4[1], guid.Data4[2], guid.Data4[3], guid.Data4[4], guid.Data4[5], guid.Data4[6], guid.Data4[7]);
		if (uuid.toString() == strGuid)
		{
			
			return pMediaData->pTimeline;
		}
	}
	return nullptr;
}

//FilterDataList
/////////////////////////////////////////////////////////////
FilterDataList::FilterDataList(const QString &strConfigFile, QObject *parent)
:MatterDataList(strConfigFile,parent)
{

}
FilterDataList::~FilterDataList()
{

}

void FilterDataList::InitDataList()
{
	QDomDocument doc;
	if (!XmlOperation::OpenXmlFile(doc, m_strConfigFile)) return;
	QDomElement rootElem = doc.documentElement();
	QDomElement effectElem = rootElem.firstChildElement();
	while (!effectElem.isNull())
	{
		if (effectElem.tagName() == "Config")
		{
			QDomElement dirElem = effectElem.firstChildElement();
			while (!dirElem.isNull())
			{
				if ( dirElem.tagName() == "ThumbFileDir")
				{
					m_strThumbnailDir = PathOperation::MakeWorkPath(dirElem.text());
				}
				else if (dirElem.tagName() == "MergeVideoFileDir")
				{
					m_strMergeVideoFileDir = PathOperation::MakeWorkPath(dirElem.text());
				}
				dirElem = dirElem.nextSiblingElement();
			}
		}
		else if (effectElem.tagName() == "EffectInfo")
		{
			FilterData *pData = new FilterData("");
			pData->strId = effectElem.attribute("id");
			QDomElement dataElem = effectElem.firstChildElement();
			while (!dataElem.isNull())
			{
				if (dataElem.tagName() == "GUID")
				{
					pData->strGuid = dataElem.text();
				}
				else if (dataElem.tagName() == "Caption")
				{
					pData->strCaption = dataElem.text();
				}
				else if (dataElem.tagName() == "ResourceTag")
				{
					pData->strResourceTag = dataElem.text();
				}
				else if (dataElem.tagName() == "ThumbFileName")
				{
					pData->strThumbFilePath = m_strThumbnailDir + "\\" + dataElem.text();
				}
				else if (dataElem.tagName() == "MergeVideoFileName")
				{
					pData->strMergeVideaFilePath = m_strMergeVideoFileDir + "\\" + dataElem.text();
				}
				else if (dataElem.tagName() == "Visible")
				{
					pData->bVisible = dataElem.text() == 0 ? false : true;
				}
				dataElem = dataElem.nextSiblingElement();
			}
			AddItem(pData);
		}
		effectElem = effectElem.nextSiblingElement();
	}
}

bool FilterDataList::AddItem(MatterDataBase* pItem)
{
	FilterData *pFilterData = dynamic_cast<FilterData*>(pItem);
	if (!pFilterData) return false;

	NLEComPtr<INLETimelineBase> pTimeline = NLEWraper::GetInstance().GetPlayerMaterProvider()->CreateVideoFilterTimeline("{" + pFilterData->strGuid + "}" + "." + pFilterData->strCaption);
	Q_ASSERT(pTimeline != nullptr);
	pFilterData->pTimeline = new NLETimeline(pTimeline,ExactType_VideoFilter);
	pFilterData->pTimeline->SetName(pItem->strCaption);
	return MatterDataList::AddItem(pFilterData);
}



//TextDataList
TextDataList::TextDataList(const QString &strConfigFile, QObject *parent /*= nullptr*/)
:MatterDataList(strConfigFile, parent)
{

}

TextDataList::~TextDataList()
{

}

#include <QtCore/QDir>
void TextDataList::InitDataList()
{
	QDomDocument doc;
	if (!XmlOperation::OpenXmlFile(doc, m_strConfigFile)) return;
	QDomElement rootElem = doc.documentElement();
	QDomElement captionArrayElem = rootElem.firstChildElement();
	if (captionArrayElem.isNull() || captionArrayElem.tagName()!="CaptionArray") return;

	QDomElement captionResource = captionArrayElem.firstChildElement();
	while (!captionResource.isNull())
	{
		TextData *pData = nullptr; 
		QDomElement dataElem = captionResource.firstChildElement();
		if (!dataElem.isNull())
		{
			pData = new TextData("");
			pData->strThumbFilePath = PathOperation::MakeWorkPath("Captions\\Thumbnail\\Caption_Test.png");
		}
			
		while (!dataElem.isNull())
		{
			if (dataElem.tagName() == "Alias")
			{
				pData->strCaption = dataElem.text();
			}
			else if (dataElem.tagName() == "BackImage")
			{
				pData->strBackImage = dataElem.text();
			}
			else if (dataElem.tagName() == "BackVideo")
			{
				pData->strBackVideo = dataElem.text();
			}
			else if (dataElem.tagName() == "GUID")
			{
				pData->strId = dataElem.text();
				pData->strGuid = dataElem.text();
			}
			else if (dataElem.tagName() == "TemplateStyle")
			{
				pData->m_nTemplateStyle = dataElem.text().toInt();
			}
			else if (dataElem.tagName() == "ResourceTag")
			{
				pData->strResourceTag = dataElem.text();
			}
			else if (dataElem.tagName() == "ResFile")
			{
				QString resDir = PathOperation::MakeWorkPath("Captions\\");
				resDir = QDir::toNativeSeparators(resDir);
				pData->strResFile = resDir + dataElem.text();
			}
			dataElem = dataElem.nextSiblingElement();
		}
		if(pData) AddItem(pData);
		captionResource = captionResource.nextSiblingElement();
	}
}

bool TextDataList::LoadTimeline(MatterDataBase *pItem)
{
	auto textData = static_cast<TextData*>(pItem);
	if (pItem->pTimeline == nullptr && FileOperation::IsFileExist(textData->strResFile))
	{
		NLEComPtr<INLETimelineBase> pTimeline = NLEWraper::GetInstance().GetPlayerMaterProvider()->CreateCaptionTimeline(textData->strResFile, pItem->strCaption);
		Q_ASSERT(pTimeline != nullptr);
		pItem->pTimeline = new NLETimeline(pTimeline,ExactType_Caption);
		pItem->pTimeline->SetName(pItem->strCaption);
	}
	return true;
}

bool TextDataList::AddItem(MatterDataBase* pItem)
{
	TextData *pTextData = dynamic_cast<TextData*>(pItem);
	if (!pTextData) return false;

	return MatterDataList::AddItem(pTextData);
}

//AudioFilterDataList
AudioFilterDataList::AudioFilterDataList(const QString &strConfigFile, QObject *parent /*= nullptr*/)
:MatterDataList(strConfigFile, parent)
{
	
}

AudioFilterDataList::~AudioFilterDataList()
{

}

void AudioFilterDataList::InitDataList()
{
	QDomDocument doc;
	if (!XmlOperation::OpenXmlFile(doc, m_strConfigFile)) return;
	QDomElement rootElem = doc.documentElement();
	QDomElement effectElem = rootElem.firstChildElement();
	while (!effectElem.isNull())
	{
		if (effectElem.tagName() == "Config")
		{
			QDomElement dirElem = effectElem.firstChildElement();
			while (!dirElem.isNull())
			{
				if (dirElem.tagName() == "ThumbFileDir")
				{
					m_strThumbnailDir = PathOperation::MakeWorkPath(dirElem.text());
				}
				else if (dirElem.tagName() == "MergeAudioFile")
				{
					m_strMergeAudioFile = PathOperation::MakeWorkPath(dirElem.text());
				}
				dirElem = dirElem.nextSiblingElement();
			}
		}
		else if (effectElem.tagName() == "EffectInfo")
		{
			AudioFilterData *pData = new AudioFilterData("");
			pData->strId = effectElem.attribute("id");
			QDomElement dataElem = effectElem.firstChildElement();
			while (!dataElem.isNull())
			{
				if (dataElem.tagName() == "GUID")
				{
					pData->strGuid = dataElem.text();
				}
				else if (dataElem.tagName() == "Caption")
				{
					pData->strCaption = dataElem.text();
				}
				else if (dataElem.tagName() == "ResourceTag")
				{
					pData->strResourceTag = dataElem.text();
				}
				else if (dataElem.tagName() == "ThumbFileName")
				{
					pData->strThumbFilePath = m_strThumbnailDir + "\\" + dataElem.text();
				}
				else if (dataElem.tagName() == "Visible")
				{
					pData->bVisible = dataElem.text() == 0 ? false : true;
				}
				dataElem = dataElem.nextSiblingElement();
			}
			pData->strMergeAudioFilePath = m_strMergeAudioFile;
			AddItem(pData);
		}
		effectElem = effectElem.nextSiblingElement();
	}
}

bool AudioFilterDataList::AddItem(MatterDataBase* pItem)
{
	AudioFilterData *pFilterData = dynamic_cast<AudioFilterData*>(pItem);
	if (!pFilterData) return false;

	NLEComPtr<INLETimelineBase> pTimeline = NLEWraper::GetInstance().GetPlayerMaterProvider()->CreateAudioFilterTimeline("{" + pFilterData->strGuid + "}");
	Q_ASSERT(pTimeline != nullptr);

	if (pTimeline)
	{
		pFilterData->pTimeline = new NLETimeline(pTimeline, ExactType_AudioFilter);
		pFilterData->pTimeline->SetName(pItem->strCaption);

		return MatterDataList::AddItem(pFilterData);

	}
	else
		return false;

}

MontageDataList::MontageDataList(const QString &strConfigFile, QObject *parent /*= nullptr*/)
:MatterDataList(strConfigFile, parent)
{

}

MontageDataList::~MontageDataList()
{

}

void MontageDataList::LoadMontageConfig(MontageData *pData, QString &fileName)
{
	//QDomDocument doc;
	//if (!XmlOperation::OpenXmlFile(doc, fileName)) return;
	//QDomElement rootElem = doc.documentElement();
	//QDomElement effectElem = rootElem.firstChildElement();
	//while (!effectElem.isNull())
	//{
	//	if (effectElem.tagName() == "Config")
	//	{
	//		QDomElement dirElem = effectElem.firstChildElement();
	//		while (!dirElem.isNull())
	//		{
	//			if (dirElem.tagName() == "ThumbFileDir")
	//			{
	//				m_strThumbnailDir = PathOperation::MakeWorkPath(dirElem.text());
	//			}
	//			else if (dirElem.tagName() == "MergeAudioFile")
	//			{
	//				m_strMontageConfigFileDir = PathOperation::MakeWorkPath(dirElem.text());
	//			}
	//			dirElem = dirElem.nextSiblingElement();
	//		}
	//	}
	//	else if (effectElem.tagName() == "MontageInfo")
	//	{
	//		MontageData *pData = new MontageData("");

	//		QDomElement dataElem = effectElem.firstChildElement();
	//		while (!dataElem.isNull())
	//		{
	//			if (dataElem.tagName() == "Caption")
	//			{
	//				pData->strMontageName = dataElem.text();
	//				pData->strCaption = dataElem.text();
	//			}				
	//			else if (dataElem.tagName() == "ThumbFileName")
	//			{
	//				pData->strThumbFilePath = m_strThumbnailDir + "\\" + dataElem.text();
	//			}
	//			else if (dataElem.tagName() == "Visible")
	//			{
	//				pData->bVisible = dataElem.text() == 0 ? false : true;
	//			}
	//			else if (dataElem.tagName() == "MontageConfigFile")
	//			{
	//				pData->strTemplateFileName = dataElem.text();
	//			}

	//			dataElem = dataElem.nextSiblingElement();
	//		}
	//		pData->strMergeAudioFilePath = m_strMontageConfigFileDir;
	//		AddItem(pData);
	//	}
	//	effectElem = effectElem.nextSiblingElement();
	//}
}

void MontageDataList::InitDataList()
{
	QDomDocument doc;
	if (!XmlOperation::OpenXmlFile(doc, m_strConfigFile)) return;
	QDomElement rootElem = doc.documentElement();
	QDomElement effectElem = rootElem.firstChildElement();
	while (!effectElem.isNull())
	{
		if (effectElem.tagName() == "Config")
		{
			QDomElement dirElem = effectElem.firstChildElement();
			while (!dirElem.isNull())
			{
				if (dirElem.tagName() == "ThumbFileDir")
				{
					m_strThumbnailDir = PathOperation::MakeWorkPath(dirElem.text());
				}
				else if (dirElem.tagName() == "MontageTemplateDir")
				{
					m_strMontageTemplateDir = PathOperation::MakeWorkPath(dirElem.text());
				}
				dirElem = dirElem.nextSiblingElement();
			}
		}
		else if (effectElem.tagName() == "MontageInfo")
		{
			MontageData *pData = new MontageData("");

			QDomElement dataElem = effectElem.firstChildElement();
			while (!dataElem.isNull())
			{
				if (dataElem.tagName() == "MontageConfigFile")
				{
					pData->strTemplateFileName = dataElem.text();
				}
				else if (dataElem.tagName() == "MontageName")
				{
					pData->strMontageName = dataElem.text();
				}
				else if (dataElem.tagName() == "Caption")
				{
					pData->strCaption = dataElem.text();
				}
				else if (dataElem.tagName() == "ThumbFileName")
				{
					pData->strThumbFilePath = m_strThumbnailDir + "\\" + dataElem.text();
				}
				else if (dataElem.tagName() == "Visible")
				{
					pData->bVisible = dataElem.text() == 0 ? false : true;
				}
				dataElem = dataElem.nextSiblingElement();
			}

			AddItem(pData);
		}
		effectElem = effectElem.nextSiblingElement();
	}
}

bool MontageDataList::AddItem(MatterDataBase* pItem)
{
	MontageData *pMontageData = dynamic_cast<MontageData*>(pItem);
	if (!pMontageData) return false;


	NLEComPtr<INLETimelineBase> pTimeline = NLEWraper::GetInstance().GetPlayerMaterProvider()->CreateMontageTimeline(m_strMontageTemplateDir + "\\" + pMontageData->strTemplateFileName, pMontageData->strMontageName);
	Q_ASSERT(pTimeline != nullptr);
	if (pTimeline)
	{
		pMontageData->pTimeline = new NLETimeline(pTimeline, ExactType_Montage);
		pMontageData->pTimeline->SetName(pItem->strCaption);
		return MatterDataList::AddItem(pMontageData);
	}
	else
		return false;
}

