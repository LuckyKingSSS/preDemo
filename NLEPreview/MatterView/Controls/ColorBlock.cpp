#include "stdafx.h"
#include "ColorBlock.h"

ColorBlock::ColorBlock(QWidget *parent)
	: QLabel(parent)
{
	
}

ColorBlock::~ColorBlock()
{

}

void ColorBlock::SetColor(const QColor &clrBg)
{
	QPalette p = this->palette();
	p.setColor(QPalette::Background, clrBg);
	setPalette(p);
}