#include "stdafx.h"
#include "ResProgressBar.h"
#include <QPainter>
#include <QPaintEvent>


ResProgressBar::ResProgressBar(QWidget *parent)
	: QWidget(parent)
	, m_nValue(0)
{
	m_clrClientBg.setRgb(0, 0, 0, 120);
	m_clrBodyBg.setRgb(217, 213, 210);
	m_clrChunk.setRgb(87, 190, 200);
}

ResProgressBar::~ResProgressBar()
{

}

void ResProgressBar::SetValue(int nValue)
{
	m_nValue = nValue;
	if (nValue < 0) m_nValue = 0;
	if (nValue > 100) m_nValue = 100;
	update();
}

void ResProgressBar::paintEvent(QPaintEvent *e)
{
	QPainter painter(this);
	QRect rcClient = e->rect();
	QRect rcBody = rcClient.adjusted(6, 3, -6, -3);

	int w = rcBody.width() * (100 - m_nValue) / 100;
	QRect rcChunk = rcBody.adjusted(0, 0, 0 - w, 0);

	painter.fillRect(rcClient, m_clrClientBg);
	painter.fillRect(rcBody, m_clrBodyBg);
	painter.fillRect(rcChunk, m_clrChunk);
}