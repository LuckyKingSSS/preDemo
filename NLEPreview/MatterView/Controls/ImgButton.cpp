#include "stdafx.h"
#include "ImgButton.h"
#include <QPainter>
#include <QPaintEvent>
#include <QPixmap>
#include "RenderOperation.h"
ImgButton::ImgButton(QWidget *parent)
	: QPushButton(parent)
{
	m_state = STATE_NOMAL;
	m_pPixmap = new QPixmap();
}

ImgButton::~ImgButton()
{
}

void ImgButton::SetImage(const QString& strImageUrl, const QSize& sigleImgSize)
{
	m_pPixmap->load(strImageUrl);
	m_nW = sigleImgSize.width();
	m_nH = sigleImgSize.height();
	update();
}

void ImgButton::SetEnabled(bool bEnable)
{
	QPushButton::setEnabled(bEnable);
	m_state = bEnable ? STATE_NOMAL : STATE_DISABLE;
	update();
}

void ImgButton::enterEvent(QEvent * e)
{
	QPushButton::enterEvent(e);

	if (m_state == STATE_DISABLE)return;

	m_state = STATE_HOVER;
	update();
}

void ImgButton::leaveEvent(QEvent * e)
{
	QPushButton::leaveEvent(e);

	if (m_state == STATE_DISABLE) return;

	m_state = STATE_NOMAL;
	update();
}

void ImgButton::mousePressEvent(QMouseEvent *e)
{
	QPushButton::mousePressEvent(e);

	if (m_state == STATE_DISABLE) return;

	m_state = STATE_PRESS;
	update();
}

void ImgButton::mouseReleaseEvent(QMouseEvent *e)
{
	QPushButton::mouseReleaseEvent(e);

	if (m_state == STATE_DISABLE) return;

	m_state = STATE_HOVER;
	update();
}

void ImgButton::paintEvent(QPaintEvent * e)
{
	DrawButton(e);
}

void ImgButton::DrawButton(QPaintEvent * e)
{
	QPainter painter(this);
	int l = 0;
	int t = 0;
	switch (m_state)
	{
	case ImgButton::STATE_NOMAL:
		l = 0;
		break;
	case ImgButton::STATE_HOVER:
		l = m_nW;
		break;
	case ImgButton::STATE_PRESS:
		l = m_nW * 2;
		break;
	case ImgButton::STATE_DISABLE:
		l = m_nW * 3;
		break;
	case ImgButton::STATE_FOCUS:
		l = m_nW * 4;
		break;
	default:
		break;
	}
	QRect rcSrc(l,t,m_nW,m_nH);
	painter.drawPixmap(rect(), *m_pPixmap, rcSrc);
}