#include "stdafx.h"
#include "VideoItemView.h"
#include "ListItemData.h"
#include "PathOperation.h"


VideoItemView::VideoItemView(ListItemData *pListItem, QWidget *parent)
: NormalItemView(pListItem, parent)
{
	QPixmap videoImg(":/Image/Resources/video_1612.png");
	m_rcVideoImg = videoImg.rect();
	m_pVideoImg = new QLabel(this);
	m_pVideoImg->setPixmap(videoImg);
}

VideoItemView::~VideoItemView()
{

}

void VideoItemView::resizeEvent(QResizeEvent *e)
{
	NormalItemView::resizeEvent(e);
	int l = m_pThumbImg->geometry().right() - m_rcVideoImg.width();
	int t = m_pThumbImg->geometry().top();
	m_pVideoImg->setGeometry(l, t, m_rcVideoImg.width(), m_rcVideoImg.height());
}

