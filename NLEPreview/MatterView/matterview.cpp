#include "stdafx.h"
#include "matterview.h"
#include "matterviewprivate.h"
#include "MatterDataManager.h"
#include "MatterDataList.h"
#include "INLETimelineBase.h"
#include "inc_CommonLib/NLETimeline.h"

MatterView::MatterView(QWidget *parent)
:NLEBaseWidget(parent)
{
	m_p = new MatterViewPrivate(this);

	connect(m_p->m_pUpperView->GetResView(), &ResViewArea::signalLoad, this, &MatterView::signalLoad);
	connect(m_p->m_pUpperView->GetResView(), &ResViewArea::signalUnload, this, &MatterView::signlaUnload);
	connect(m_p, &MatterViewPrivate::sigViewSizeChanged, this, [&](QSize size)
	{
		emit sigViewSizeChanged(size);
	});
	QVBoxLayout *vLayout = new QVBoxLayout;
	vLayout->setContentsMargins(0, 0, 0, 0);
	vLayout->addWidget(m_p);
	setLayout(vLayout);
}

MatterView::~MatterView()
{

}

NLETimeline* MatterView::GetTimeline()
{
	return m_p->m_pUpperView->GetResView()->GetCurrentTimeline();
}

NLETimeline* MatterView::GetMediaTimelineByGuid(const QString &strGuid)
{
	return MatterDataManager::GetInstance().GetMediaDataList()->GetTimelineByGuid(strGuid);
}

void MatterView::SetFocus(bool foucs)
{
	m_p->m_pUpperView->GetResView()->SetFocus(foucs);
}
