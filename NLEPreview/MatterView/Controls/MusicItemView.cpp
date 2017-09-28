#include "stdafx.h"
#include "MusicItemView.h"
#include "ListItemData.h"


MusicItemView::MusicItemView(ListItemData *pListItem, QWidget *parent)
: NormalItemView(pListItem, parent)
{
	QPixmap musicImg(":/Image/Resources/music_1613.png");
	m_rcMusicImg = musicImg.rect();
	m_pMusicImg = new QLabel(this);
	m_pMusicImg->setPixmap(musicImg);
}

MusicItemView::~MusicItemView()
{

}

void MusicItemView::resizeEvent(QResizeEvent *e)
{
	NormalItemView::resizeEvent(e);
	int l = m_pThumbImg->geometry().right() - m_rcMusicImg.width();
	int t = m_pThumbImg->geometry().top();
	QRect rcMusicImg(l, t, m_rcMusicImg.width(), m_rcMusicImg.height());
	m_pMusicImg->setGeometry(rcMusicImg);
}
