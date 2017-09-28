#include "stdafx.h"
#include "ResListView.h"
#include "ListItemData.h"
#include <QPainter>
#include "FileOperation.h"
#include "ItemBaseView.h"
#include "NormalItemView.h"
#include "VideoItemView.h"
#include "ImageItemView.h"
#include "MusicItemView.h"
#include "EffectItemView.h"
#include "PathOperation.h"
/************************************************************************/
/*         ResListWidget                                                */
/************************************************************************/

ResListWidget::ResListWidget(QWidget *parent) 
: QListWidget(parent) 
{
	m_pPreClickItem = NULL;
	setLayoutMode(QListView::Batched);
	m_interval.start();
}

ResListWidget::~ResListWidget()
{
}

void ResListWidget::lBtnDClicked()
{
	if (selectedItems().size() > 0)
	{
		emit signalLBtnDClickedSelected(selectedItems().first());
	}
}

void ResListWidget::lBtnClicked()
{
	int nCnt = selectedItems().size();
	if (nCnt == 1)
	{
		emit signalLBtnSingleSelected(selectedItems().first());
	}
	else if(nCnt > 1)
	{
		emit signalLBtnMultiSelected(selectedItems());
	}
}

void ResListWidget::mouseReleaseEvent(QMouseEvent *e)
{
	QListWidget::mouseReleaseEvent(e);
	dragStartPosition.setX(0);
	dragStartPosition.setY(0);
	emit signalShowSelectionRect(false, QRect());
	if (e->button() == Qt::LeftButton)
	{
		if (m_interval.elapsed() < QApplication::doubleClickInterval())
		{
			disconnect(&m_timer, &QTimer::timeout, 0, 0);
			m_timer.stop();
			//双击，先判断上一次点击的对象是不是当前点击的对象
			if (itemAt(e->pos()) == m_pPreClickItem)
			{
				lBtnDClicked();
			}
			else
			{
				lBtnClicked();
			}
			m_interval.restart();
		}
		else
		{
			m_interval.restart();
			m_pPreClickItem = itemAt(e->pos());
			m_timer.start(QApplication::doubleClickInterval());
			connect(&m_timer, &QTimer::timeout, this, [&](){
				disconnect(&m_timer, &QTimer::timeout, 0, 0);
				m_timer.stop();
				//单击
				m_pPreClickItem = NULL;
				lBtnClicked();
			});
		}
	}
}

void ResListWidget::mousePressEvent(QMouseEvent *e)
{
	QListWidget::mousePressEvent(e);
	auto selectItem = itemAt(e->pos());
	if (selectItem == nullptr)
	{
		if (e->button() == Qt::LeftButton)
		{
			UnselectAllItems();
			dragStartPosition = e->pos();
			emit signalBlankAreaLClick();
		}
		else if (e->button() == Qt::RightButton)
		{
			UnselectAllItems();
			emit signalBlankAreaRClick();
		}
	}
	else
	{
		emit signalLBtnSingleSelectedDown(selectItem);
	}
	
}

void ResListWidget::mouseMoveEvent(QMouseEvent *e)
{
	QListWidget::mouseMoveEvent(e);
	if (!(e->buttons() & Qt::LeftButton))
		return;
	if (dragStartPosition.isNull()) return;
	if ((e->pos() - dragStartPosition).manhattanLength()< QApplication::startDragDistance()) return;
	emit signalShowSelectionRect(true, QRect(dragStartPosition,e->pos()));
}


void ResListWidget::UnselectAllItems()
{
	QList<QListWidgetItem*> listItems = selectedItems();
	for (QListWidgetItem* item : listItems)
	{
		setItemSelected(item, false);
	}
}

void ResListWidget::resizeEvent(QResizeEvent *e)
{
	QListWidget::resizeEvent(e);
}

/************************************************************************/
/*         ResListView                                                  */
/************************************************************************/
ResListView::ResListView(QWidget *parent ,int selectMode)
	: QWidget(parent)
{
	m_pListWidget = new ResListWidget(this);
	InitListWidget(selectMode);

	m_pSelectionWidget = new SelectionWidget(this);
	m_pSelectionWidget->setVisible(false);

	connect(m_pListWidget, &ResListWidget::signalShowSelectionRect, this, [&](bool bShow,QRect rc){
		m_pSelectionWidget->setVisible(bShow);
		if (!bShow) return;
		if (m_pListWidget->selectionMode() == QAbstractItemView::SingleSelection) return;
		m_pSelectionWidget->SetSelectedRect(rc);
	});
}


ResListView::~ResListView()
{
}

void ResListView::InitListWidget(int nSelectMode)
{
	m_pListWidget->setViewMode(QListView::IconMode);
	m_pListWidget->setResizeMode(QListView::Adjust);
	m_pListWidget->setSelectionMode((QAbstractItemView::SelectionMode)nSelectMode);
	m_pListWidget->setDragEnabled(true);
	m_pListWidget->setSpacing(10);
	m_pListWidget->setFocusPolicy(Qt::FocusPolicy::NoFocus);
	m_pListWidget->setStyleSheet("QListWidget{border: none;background: rgb(245,244,244);}");
	m_pListWidget->setSelectionRectVisible(false);
	
	connect(m_pListWidget, &ResListWidget::signalBlankAreaLClick, this, &ResListView::signalBlankAreaLClick);
	connect(m_pListWidget, &ResListWidget::signalBlankAreaRClick, this, &ResListView::signalBlankAreaRClick);

	connect(m_pListWidget, &ResListWidget::signalLBtnMultiSelected, this, &ResListView::signalLBtnMultiSelected);
	connect(m_pListWidget, &ResListWidget::signalLBtnSingleSelected, this, &ResListView::signalLBtnSingleSelected);
	connect(m_pListWidget, &ResListWidget::signalLBtnDClickedSelected, this, &ResListView::signalLBtnDClickedSelected);

	connect(m_pListWidget, &ResListWidget::signalLBtnSingleSelectedDown, this, &ResListView::signalLBtnSingleSelectedDown);

	QString s = FileOperation::ReadFile(PathOperation::MakeWorkPath("ResConfig\\qss\\list_scroolbar.qss"));
	m_pListWidget->verticalScrollBar()->setStyleSheet(s);
}

void ResListView::resizeEvent(QResizeEvent *e)
{
	m_pListWidget->setGeometry(rect());
	m_pSelectionWidget->setGeometry(rect());
}

void ResListView::AddItemWidget(ListItemData* pItemData)
{
	if (!pItemData) return;
	pItemData->setSizeHint(pItemData->frameSize);

	ItemBaseView *itemView = CreateItemViewByItemData(pItemData);
	if (!itemView) return;

	if (pItemData->eType != ListItemType_base)
	{
		connect((NormalItemView*)itemView, &NormalItemView::signalAddBtnClicked, this, &ResListView::signalItemAddBtnClicked);
	}
	m_pListWidget->setItemWidget(pItemData, itemView);
	m_pListWidget->sortItems();
}

void ResListView::RemoveItemWidget(ListItemData* pItemData)
{
	int nRow = m_pListWidget->row(pItemData);
	m_pListWidget->removeItemWidget(pItemData);
	m_pListWidget->model()->removeRow(nRow);
}

void ResListView::SetSpacing(int nSpacing)
{
	m_pListWidget->setSpacing(nSpacing);
}

ItemBaseView* ResListView::CreateItemViewByItemData(ListItemData* pItemData)
{
	ItemBaseView *pItemView = NULL;
	switch (pItemData->eType)
	{
	case ListItemType_base:
		pItemView = new ItemBaseView(pItemData, m_pListWidget);
		break;
	case ListItemType_normal:
		pItemView = new NormalItemView(pItemData, m_pListWidget);
		break;
	case ListItemType_Image:
		pItemView = new ImageItemView(pItemData, m_pListWidget);
		break;
	case ListItemType_music:
		pItemView = new MusicItemView(pItemData, m_pListWidget);
		break;
	case ListItemType_video:
		pItemView = new VideoItemView(pItemData, m_pListWidget);
		break;
	case ListItemType_effect:
		pItemView = new EffectItemView(pItemData, m_pListWidget);
		break;
	case ListItemType_text:
		pItemView = new TextItemView(pItemData, m_pListWidget);
		break;
	case ListItemType_audio_effect:
		pItemView = new AudioFilterItemView(pItemData, m_pListWidget);
		break;
	case ListItemType_montage:
		pItemView = new MontageItemView(pItemData, m_pListWidget);
		break;
	}
	return pItemView;
}

QWidget* ResListView::GetItemWidget(ListItemData* pItemData)
{
	return m_pListWidget->itemWidget(pItemData);
}

void ResListView::UnselectAllItems()
{
	m_pListWidget->UnselectAllItems();
}
/************************************************************************/
/*         SelectionWidget                                                  */
/************************************************************************/

SelectionWidget::SelectionWidget(QWidget *parent)
:QWidget(parent)
{
	setAttribute(Qt::WA_TransparentForMouseEvents, true);
	setStyleSheet("background:none;background-color:none;");
}
SelectionWidget::~SelectionWidget()
{

}

void SelectionWidget::SetSelectedRect(const QRect &rcSelected)
{
	QRect rcTag = m_rcSelected.united(rcSelected);
	m_rcSelected = rcSelected;
	
	repaint(rcTag.adjusted(0, 0, 1, 1));
	//update(rcTag.adjusted(0,0,1,1));
}

void SelectionWidget::paintEvent(QPaintEvent *e)
{
	QPainter painter(this);
	painter.drawRect(m_rcSelected);
	QWidget::paintEvent(e);
}


