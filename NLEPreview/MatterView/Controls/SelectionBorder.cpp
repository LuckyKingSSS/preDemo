#include "stdafx.h"
#include "SelectionBorder.h"
#include <QPainter>

SelectionBorder::SelectionBorder(QWidget *parent)
	: QLabel(parent)
{
	setAttribute(Qt::WA_TransparentForMouseEvents, true);
	setVisible(false);
	setStyleSheet("background-color:rgba(0,0,0,0);");
	m_pen = new QPen;
	m_pen->setWidth(3);
	m_pen->setJoinStyle(Qt::RoundJoin);
	m_pen->setCapStyle(Qt::RoundCap);
}

SelectionBorder::~SelectionBorder()
{
	delete m_pen;
}

void SelectionBorder::setSelectionState(SelectionState s)
{
	QString strStyleSheet;
	switch (s)
	{
	case SelectionBorder::SelectionState_Normal:
		setVisible(false);
		break;
	case SelectionBorder::SelectionState_Hover:
		m_pen->setColor(QColor(255,0,0));
		setVisible(true);
		break;
	case SelectionBorder::SelectionState_Seleted:
		m_pen->setColor(QColor(154, 156, 192));
		setVisible(true);
		break;
	default:
		break;
	}
}

void SelectionBorder::paintEvent(QPaintEvent *e)
{
	QPainter painter(this);
	painter.setPen(*m_pen);
	painter.drawRect(rect().adjusted(1,1,-2,-2));
}