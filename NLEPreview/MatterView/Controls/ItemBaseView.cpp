#include "stdafx.h"
#include "ItemBaseView.h"
#include <QPainter>
#include <QPaintEvent>
#include "ListItemData.h"
#include <QMimeData>
#include <QDrag>
#include "SelectionBorder.h"
#include "ColorBlock.h"
#include "MatterDataBase.h"
#include "MatterDataDefine.h"
#include "NLEWraper.h"
#include "PlayerMaterProvider.h"
#include "inc_CommonLib/NLETimeline.h"
ItemBaseView::ItemBaseView(ListItemData *pListItem, QWidget *parent) : QWidget(parent)
{
	qRegisterMetaType<ListItemData*>("ListItemData");
	m_mousePress = false;
	m_pParentList = qobject_cast<QListWidget *>(parent);
	m_viewState = ViewState_Normal;
	Q_ASSERT(pListItem);
	m_pListItemData = pListItem;
	//ËõÂÔÍ¼
	m_pThumbImg = new QLabel(this);
	m_pThumbImg->setPixmap(QPixmap(m_pListItemData->pMatterData->strThumbFilePath));

	//ÎÄ±¾
	m_plabel = new QLabel(this);
	m_plabel->setAlignment(Qt::AlignCenter);

	m_textFont.setPointSize(10);
	m_plabel->setFont(m_textFont);
	m_plabel->setStyleSheet("color:#9a9cc0;background-color:none;");
	
	//Ñ¡Ôñ±ß¿ò
	m_pSelectionBorder = new SelectionBorder(this);
	setFixedSize(m_pListItemData->frameSize);
}

ItemBaseView::~ItemBaseView()
{

}

void ItemBaseView::enterEvent(QEvent *e)
{
	m_viewState = ViewState_MouseMove;
	update();
	QWidget::enterEvent(e);
}

void ItemBaseView::leaveEvent(QEvent *e)
{
	m_viewState = ViewState_Normal;
	update();
	QWidget::leaveEvent(e);
}

void ItemBaseView::mousePressEvent(QMouseEvent *e)
{
	if (e->button() == Qt::LeftButton)
	{
		m_mousePress = true;
		m_pressPoint = e->pos();
	}
	QWidget::mousePressEvent(e);
}

void ItemBaseView::mouseMoveEvent(QMouseEvent *e)
{
	if (m_mousePress && m_pressPoint.manhattanLength() > QApplication::startDragDistance())
	{
		auto mimeData = new QMimeData;
		mimeData->setData("MatterView_TimelineItem", "");
		mimeData->setProperty("MatterView_TimelineItem", qptrdiff(m_pListItemData->pMatterData->pTimeline));
		int nMatterType = -1;
		int nLen = 0;
		if (m_pListItemData->pMatterData->nDataType == MatterDataType_Media)
		{
			MediaData* pMediaData = dynamic_cast<MediaData*>(m_pListItemData->pMatterData);
			if (pMediaData)
			{
				if (pMediaData->nResType == MediaDataType_Video || pMediaData->nResType == MediaDataType_Image)
				{
					nMatterType = MatterType_Video;
				}
				else if (pMediaData->nResType == MediaDataType_Audio)
				{
					nMatterType = MatterType_Audio;
				}
			}
			m_pListItemData->pMatterData->pTimeline->SetRenderFrameRate(25);
			nLen = m_pListItemData->pMatterData->pTimeline->GetTotalLength();
		}
		else if (m_pListItemData->pMatterData->nDataType == MatterDataType_Effect 
			|| m_pListItemData->pMatterData->nDataType == MatterDataType_Audio_Effect
			|| m_pListItemData->pMatterData->nDataType == MatterDataType_Text)
		{
			nMatterType = MatterType_Effect;
			nLen = 25 * 5;
		}
		else if (m_pListItemData->pMatterData->nDataType == MatterDataType_Montage)
		{
			nMatterType = MatterType_Video;
			nLen = m_pListItemData->pMatterData->pTimeline->GetTotalLength();
		}

		mimeData->setProperty("MatterType", nMatterType);
		mimeData->setProperty("Duration", nLen);
		QDrag drag(this);
		drag.setMimeData(mimeData);
		drag.exec();
	}
	QWidget::mouseMoveEvent(e);
}

void ItemBaseView::resizeEvent(QResizeEvent *e)
{
	static const int RC_TEXT_HEIGH = 20;
	QRect rcClient = rect();
	QRect rcContent = rcClient.adjusted(8, 5, -8, 0);
	QRect rcImg = rcContent.adjusted(0, 0, 0, 0 - RC_TEXT_HEIGH);
	QRect rcText = rcContent.adjusted(0, rcContent.height() - RC_TEXT_HEIGH, 0, 0);
	//ËõÂÔÍ¼
	m_pThumbImg->setGeometry(rcImg);
	//ÎÄ±¾
	m_plabel->setGeometry(rcText);
	QFontMetrics elidfont(m_textFont);
	m_plabel->setText(elidfont.elidedText(m_pListItemData->pMatterData->strCaption, Qt::ElideRight, rcText.width()));
	//Ñ¡Ôñ±ß¿ò
	QRect rcSeletion = rcImg.adjusted(-1, 0, 1, 1);
	m_pSelectionBorder->setGeometry(rcSeletion);
}

void ItemBaseView::paintEvent(QPaintEvent *e)
{
	if (m_pParentList->isItemSelected(m_pListItemData))
	{
		m_pSelectionBorder->setSelectionState(SelectionBorder::SelectionState_Seleted);
	}
	else if (m_viewState == ViewState_MouseMove)
	{
		m_pSelectionBorder->setSelectionState(SelectionBorder::SelectionState_Hover);
	}
	else
	{
		m_pSelectionBorder->setSelectionState(SelectionBorder::SelectionState_Normal);
	}
	QWidget::paintEvent(e);
}

void ItemBaseView::showEvent(QShowEvent *e)
{
	RaiseSubControls();
	QWidget::showEvent(e);
}

void ItemBaseView::RaiseSubControls()
{
	m_pSelectionBorder->raise();
}

void ItemBaseView::SetThumbnail(const QString &strImageUrl)
{
	m_pListItemData->pMatterData->strThumbFilePath = strImageUrl;
	m_pThumbImg->setPixmap(QPixmap(strImageUrl));
}
