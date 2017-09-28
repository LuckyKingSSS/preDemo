#include "stdafx.h"
#include "MatterDataManager.h"
#include "MatterDataManagerPrivate.h"
#include "NLECostTimeTest.h"


MatterDataManager::MatterDataManager(QObject *parent)
:QObject(parent)
{
	m_p = new MatterDataManagerPrivate(this);
}

MatterDataManager::~MatterDataManager()
{
}

MatterDataManager& MatterDataManager::GetInstance()
{
	static MatterDataManager instance;
	return instance;
}

static MatterDataManager *s_MatterDataManager = nullptr;
MatterDataManager* MatterDataManager::GetInstanceEx()
{
	if (s_MatterDataManager == nullptr)
	{
		s_MatterDataManager = new MatterDataManager();
	}
	return s_MatterDataManager;
}

void MatterDataManager::Init()
{
	//TEST_COST_TIME_BEGIN;
	m_p->Init(MatterDataType_All);
	//TEST_COST_TIME_END;
}

MediaDataList* MatterDataManager::GetMediaDataList()
{
	return m_p->m_pMediaDataList;
}

FilterDataList* MatterDataManager::GetFilterDataList()
{
	return m_p->m_pFilterDataList;
}

TextDataList* MatterDataManager::GetTextDataList()
{
	return m_p->m_pTextDataList;
}

AudioFilterDataList* MatterDataManager::GetAudioFilterDataList()
{
	return m_p->m_pAudioFilterDataList;
}

MontageDataList* MatterDataManager::GetMontageDataList()
{
	return m_p->m_pMontageDataList;
}
