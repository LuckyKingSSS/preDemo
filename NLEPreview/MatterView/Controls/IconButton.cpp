#include "stdafx.h"
#include "IconButton.h"
#include <QPainter>
#include <QPaintEvent>
#include <QPixmap>
#include "RenderOperation.h"
IconButton::IconButton(const QString &text, QWidget *parent)
: QPushButton(text,parent)
{
	m_state = STATE_NOMAL;
	m_pPixmap = new QPixmap();
}

IconButton::~IconButton()
{
}

void IconButton::SetIconImage(const QString& strImageUrl, const QSize& sigleIconSize)
{
	m_pPixmap->load(strImageUrl);
	m_nW = sigleIconSize.width();
	m_nH = sigleIconSize.height();
	update();
}

void IconButton::SetEnabled(bool bEnable)
{
	QPushButton::setEnabled(bEnable);
	m_state = bEnable ? STATE_NOMAL : STATE_DISABLE;
	update();
}

void IconButton::enterEvent(QEvent * e)
{
	QPushButton::enterEvent(e);

	if (m_state == STATE_DISABLE)return;

	m_state = STATE_HOVER;
	update();
}

void IconButton::leaveEvent(QEvent * e)
{
	QPushButton::leaveEvent(e);

	if (m_state == STATE_DISABLE) return;

	m_state = STATE_NOMAL;
	update();
}

void IconButton::mousePressEvent(QMouseEvent *e)
{
	QPushButton::mousePressEvent(e);

	if (m_state == STATE_DISABLE) return;

	m_state = STATE_PRESS;
	update();
}

void IconButton::mouseReleaseEvent(QMouseEvent *e)
{
	QPushButton::mouseReleaseEvent(e);

	if (m_state == STATE_DISABLE) return;

	m_state = STATE_HOVER;
	update();
}

void IconButton::paintEvent(QPaintEvent * e)
{
	DrawButton(e);
}

void IconButton::DrawButton(QPaintEvent * e)
{
	QPainter painter(this);
	int l = 0;
	int t = 0;
	switch (m_state)
	{
	case IconButton::STATE_NOMAL:
		l = 0;
		break;
	case IconButton::STATE_HOVER:
		l = m_nW;
		break;
	case IconButton::STATE_PRESS:
		l = m_nW * 2;
		break;
	case IconButton::STATE_DISABLE:
		l = m_nW * 3;
		break;
	default:
		break;
	}
	QRect rcSrc(l,t,m_nW,m_nH);
	QRect rcAll = rect();

	int nMargin = 3;
	int iconL = rcAll.left() + nMargin;
	int iconT = (rcAll.height() - m_nH) * 0.5;
	QRect rcIcon(iconL, iconT, m_nW, m_nH);

	int textL = rcIcon.right() + nMargin * 3;
	int textT = rcAll.top();
	int textW = rcAll.width() - m_nW - 2 * nMargin;
	int textH = rcAll.height();
	QRect rcText(textL, textT, textW, textH);

	//icon
	painter.drawPixmap(rcIcon, *m_pPixmap, rcSrc);
	//text
	painter.drawText(rcText, Qt::AlignLeft | Qt::AlignVCenter, text());
}