#include "stdafx.h"
#include "ThumbnailExtractor.h"
#include "inc_CommonLib/NLEWraper.h"
#include "inc_CommonLib/PlayerMaterProvider.h"
#include "INLETimelineBase.h"
#include "ThumbnailExtractHelper.h"

#define ThumbnailWidth  60
#define ThumbnailHeight 40

ThumbnailExtractor::ThumbnailExtractor(NLETimeline *pTimeline, QObject *parent)
: QThread(parent)
, m_pNLETimeline(pTimeline)
{
	m_bQuit = false;
	m_pClonedTimeline = nullptr;
	m_bFirst = true;
	m_nShowLen = 0;
	m_bReStart = false;
	//m_nTotalFrames = m_pNLETimeline->GetTotalLength();
	m_nTotalFrames = 0;

	NLESize sz;
	NLEPropComPtr pProp = NLEWraper::GetInstance().GetPlayerMaterProvider()->NLEGetProperties(m_pNLETimeline->GetSrc());
	pProp->GetRenderSize(&sz);
	m_RenderSize = QSize(sz.Width, sz.Height);

	m_pHelper = ThumbnailExtractHelper::GetInstance();
}

ThumbnailExtractor::~ThumbnailExtractor()
{
}

void ThumbnailExtractor::Stop()
{
	m_bQuit = true;
}

void ThumbnailExtractor::WaitForQuit()
{
	while (true)
	{
		if (!isRunning()) return;
	}
}

void ThumbnailExtractor::run()
{
#ifdef WIN32
	::CoInitialize(0);
#endif
	m_listNeededs.clear();
	while (!m_bQuit)
	{
		if (m_bFirst)
		{
			m_bFirst = false;
			if (!IsFull()) CloneTimeline();
			CalToGetFrames();
		}
		else if (m_bReStart)
		{
			m_bReStart = false;
			CalToGetFrames();
		}

		if (m_bQuit || IsFull())
		{
			return;
		}
		else
		{
			msleep(200);
		}

		if (!m_listFramesToGet.isEmpty())
		{
			for (int nFrameToGet : m_listFramesToGet)
			{
				if (m_bQuit) return;
				if (m_bReStart) break;
				if (m_pHelper->IsThumbnailExist(GetAncestralGuid(),nFrameToGet))
				{
					m_listNeededs.push_back(m_pHelper->GetThumbnail(GetAncestralGuid(), nFrameToGet));
					emit signalGetNeededThumbnail();
				}
				else
				{
					QPixmap pix = ExtractImage(nFrameToGet);
					m_pHelper->InsertThumbnail(GetAncestralGuid(), nFrameToGet, pix);
					m_listNeededs.push_back(pix);
					emit signalGetNeededThumbnail();
				}
			}
			m_listFramesToGet.clear();
		}
	}
}

void ThumbnailExtractor::SetTotalLen(int nLen)
{
	//if (m_nShowLen == nLen) return;
	m_nShowLen = nLen;

	if (IsFull())
	{
		CalToGetFrames();
		FillNeededList();
		emit signalGetNeededThumbnail();
		return;
	}

	if (m_bFirst)
	{
		start();
	}
	else
	{
		m_bReStart = true;
	}
}

int ThumbnailExtractor::GetTotalLen()
{
	return m_nShowLen;
}

QList<QPixmap> ThumbnailExtractor::GetThumbnails()
{
	return m_listNeededs;
}

QPixmap ThumbnailExtractor::ExtractImage(int nFrame)
{
	INLERender *pVideoRender = NULL;
	INLERender *pAudioRender = NULL;
	NLEWraper::GetInstance().GetPlayerMaterProvider()->GetMediaRender(m_pClonedTimeline->GetSrc(), &pVideoRender, &pAudioRender);
	if (!pVideoRender) return QPixmap();

	NLEComPtr<INLEFrame> pFrame = NLEWraper::GetInstance().GetPlayerMaterProvider()->CreateVideoFrame(m_RenderSize.width(), m_RenderSize.height());
	if (!pFrame) return QPixmap();

	
	int nPlayLen = m_pClonedTimeline->GetPlayLen();
	int nSrcLen = m_pClonedTimeline->GetSrcLen();

	pVideoRender->Seek(nFrame);
	pVideoRender->Prepare(pFrame);
	pVideoRender->Render(pFrame);
	if (!pFrame) return QPixmap();

	void* pData = pFrame->GetData();
	int nDataLen = pFrame->GetDataSize();

	QImage img((uchar*)pData, m_RenderSize.width(), m_RenderSize.height(), QImage::Format_ARGB32);
	QPixmap pix = QPixmap::fromImage(img).scaled(ThumbnailWidth, ThumbnailHeight);

	return pix;
}

void ThumbnailExtractor::FillNeededList()
{
	m_listNeededs.clear();
	for (int nFrameNeed : m_listFramesToGet)
	{
		QPixmap pix = m_pHelper->GetThumbnail(GetAncestralGuid(), nFrameNeed);
		m_listNeededs.push_back(pix);
	}
}

void ThumbnailExtractor::CalToGetFrames()
{
	m_listNeededs.clear();
	int nToGetCnt = m_nShowLen / ThumbnailWidth + (m_nShowLen % ThumbnailWidth == 0 ? 0 : 1);
	if (nToGetCnt <= 0) return;
	m_listFramesToGet.clear();

	int nTrimin = 0;// m_pClonedTimeline->GetTrimin();
	int nPlayLen = m_pClonedTimeline->GetPlayLen();

	//int nPlayLen2 = m_pClonedTimeline->GetPlayLen();


	int nDeltaFrames = nPlayLen / nToGetCnt;

	int nFrame = 0;
	for (int i = 0; i < nToGetCnt; ++i)
	{
		nFrame = nTrimin + i * nDeltaFrames;
		m_listFramesToGet.push_back(nFrame);
	}
}

QSize ThumbnailExtractor::GetThumbnailSize()
{
	return QSize(ThumbnailWidth, ThumbnailHeight);
}

void ThumbnailExtractor::CloneTimeline()
{
	SAFE_DELETE(m_pClonedTimeline);
	m_pClonedTimeline = m_pNLETimeline->Clone();

	//int nLen1 = m_pNLETimeline->GetPlayLen();
	//int nLen2 = m_pClonedTimeline->GetPlayLen();
	m_nTotalFrames = m_pClonedTimeline->GetTotalLength();
}

QString ThumbnailExtractor::GetAncestralGuid()
{
	return m_pNLETimeline->GetAncestralGuid();
}

bool ThumbnailExtractor::IsFull()
{
	if (m_nTotalFrames == 0) return false; //一开始 m_nTotalFrame还没获取到，是0
	return m_pHelper->GetSize(GetAncestralGuid()) >= m_nTotalFrames;
}

