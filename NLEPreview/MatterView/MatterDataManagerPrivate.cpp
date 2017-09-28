#include "stdafx.h"
#include "MatterDataManagerPrivate.h"
#include "MatterDataList.h"
#include <QPixmap>
#include <QCoreApplication>
#include "PathOperation.h"
#include "MatterConfigFileManager.h"
#include "NLECostTimeTest.h"

#define Res_config_file_dir "ResConfig/configfile/"
#define Res_thumbnail_dir	"ResConfig/thumbnail/"
#define Res_text_dir		"Captions/"
MatterDataManagerPrivate::MatterDataManagerPrivate(QObject *parent)
	: QObject(parent)
{
	QString strMediaConfigFile = PathOperation::MakeWorkPath(Res_config_file_dir) + "res_media.xml";
	QString strFilterConfigFile = PathOperation::MakeWorkPath(Res_config_file_dir) + "res_filter.xml";
	QString strTextConfigFile = PathOperation::MakeWorkPath(Res_text_dir) + "NewCaptionResource.xml";
	QString strAudioFilterConfigFile = PathOperation::MakeWorkPath(Res_config_file_dir) + "res_audiofilter.xml";
	QString strMontageConfigFile = PathOperation::MakeWorkPath(Res_config_file_dir) + "res_montage.xml";
	m_pMediaDataList = new MediaDataList(strMediaConfigFile, this);
	m_pFilterDataList = new FilterDataList(strFilterConfigFile, this);
	m_pTextDataList = new TextDataList(strTextConfigFile, this);
	m_pAudioFilterDataList = new AudioFilterDataList(strAudioFilterConfigFile, this);
	m_pMontageDataList = new MontageDataList(strMontageConfigFile, this);

	MatterConfigFileManager::GetInstance().SetMediaConfigFile(strMediaConfigFile);
}

MatterDataManagerPrivate::~MatterDataManagerPrivate()
{

}

void MatterDataManagerPrivate::Init(int nDataType)
{
	//TEST_COST_TIME_BEGIN;
	if (nDataType == MatterDataType_All)
	{
		m_pMediaDataList->InitDataList();
		m_pFilterDataList->InitDataList();
		m_pTextDataList->InitDataList();
		m_pAudioFilterDataList->InitDataList();
		m_pMontageDataList->InitDataList();
		return;
	}

	if (nDataType == MatterDataType_Media)
	{
		m_pMediaDataList->InitDataList();
	}
	else if (nDataType == MatterDataType_Effect)
	{
		m_pFilterDataList->InitDataList();
	}
	else if (nDataType == MatterDataType_Text)
	{
		m_pTextDataList->InitDataList();
	}
	else if (nDataType == MatterDataType_Audio_Effect)
	{
		m_pAudioFilterDataList->InitDataList();
	}
	else if (nDataType == MatterDataType_Montage)
	{
		m_pMontageDataList->InitDataList();
	}

	//TEST_COST_TIME_END;
}
