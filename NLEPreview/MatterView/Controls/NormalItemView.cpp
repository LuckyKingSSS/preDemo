#include "stdafx.h"
#include "NormalItemView.h"
#include "ImgButton.h"
#include "ListItemData.h"
#include "PathOperation.h"

#define AddbtnW 15
#define AddbtnH 11

NormalItemView::NormalItemView(ListItemData *pListItem, QWidget *parent)
: ItemBaseView(pListItem,parent)
{
	//+°´Å¥
	m_pAddButton = new ImgButton(this);
	m_pAddButton->SetImage(":/Image/Resources/addbutton.png", QSize(AddbtnW, AddbtnH));
	connect(m_pAddButton, &ImgButton::clicked, this, [&](){
		signalAddBtnClicked(m_pListItemData);
	});
	m_pAddButton->setVisible(false);
}

NormalItemView::~NormalItemView()
{
	  
}

void NormalItemView::enterEvent(QEvent *e)
{
	m_pAddButton->setVisible(true);
	ItemBaseView::enterEvent(e);
}

void NormalItemView::leaveEvent(QEvent *e)
{
	m_pAddButton->setVisible(false);
	ItemBaseView::leaveEvent(e);
}

void NormalItemView::resizeEvent(QResizeEvent *e)
{
	ItemBaseView::resizeEvent(e);
	m_pAddButton->setGeometry(m_pThumbImg->geometry().right() - AddbtnW - 1, m_pThumbImg->geometry().bottom() - AddbtnH - 1,AddbtnW,AddbtnH);
}

//TextItemView
TextItemView::TextItemView(ListItemData *pListItem, QWidget *parent /*= 0*/)
:NormalItemView(pListItem, parent)
{

}

TextItemView::~TextItemView()
{

}

//AudioFilterItemView
AudioFilterItemView::AudioFilterItemView(ListItemData *pListItem, QWidget *parent /*= 0*/)
:NormalItemView(pListItem, parent)
{

}

AudioFilterItemView::~AudioFilterItemView()
{

}

MontageItemView::MontageItemView(ListItemData *pListItem, QWidget *parent /*= 0*/)
:NormalItemView(pListItem, parent)
{

}

MontageItemView::~MontageItemView()
{

}
