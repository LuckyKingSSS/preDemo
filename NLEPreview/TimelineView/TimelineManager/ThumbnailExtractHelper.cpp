#include "stdafx.h"
#include "ThumbnailExtractHelper.h"

ThumbnailExtractHelper* ThumbnailExtractHelper::pThis = nullptr;

ThumbnailExtractHelper::ThumbnailExtractHelper(QObject *parent)
	: QObject(parent)
{

}

ThumbnailExtractHelper::~ThumbnailExtractHelper()
{

}

ThumbnailExtractHelper* ThumbnailExtractHelper::GetInstance()
{
	
	if (pThis == nullptr)
	{
		pThis = new ThumbnailExtractHelper;
	}
	return pThis;
}

void ThumbnailExtractHelper::InsertThumbnail(const QString &strGuid, int nFrame, QPixmap pix)
{
	ThumbnailInfo *info = GetThumbnailInfo(strGuid);
	if (info->GetThumbnailInfo().contains(nFrame)) return;
	info->insertItem(nFrame, pix);
}

QPixmap ThumbnailExtractHelper::GetThumbnail(const QString &strGuid, int nFrame)
{
	ThumbnailInfo *info = GetThumbnailInfo(strGuid);
	return info->GetThumbnail(nFrame);
}

int ThumbnailExtractHelper::GetSize(const QString &strGuid)
{
	return GetThumbnailInfo(strGuid)->GetSize();
}

bool ThumbnailExtractHelper::IsThumbnailExist(const QString &strGuid, int nFrame)
{
	ThumbnailInfo *info = GetThumbnailInfo(strGuid);
	return info->IsThumbnailExist(nFrame);
}

ThumbnailInfo* ThumbnailExtractHelper::GetThumbnailInfo(const QString &strGuid)
{
	if (!m_mapThumbnails.contains(strGuid))
	{
		ThumbnailInfo *info = new ThumbnailInfo(strGuid);
		m_mapThumbnails.insert(strGuid, info);
	}
	return m_mapThumbnails.value(strGuid);
}