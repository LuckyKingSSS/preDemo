#include "stdafx.h"
#include "matterviewprivate.h"
#include "matterviewtoolbar.h"
#include "MatterDataDefine.h"
#include "Controls/ResListView.h"
#include "MatterDataManager.h"
#include "ImportMediaDlg.h"
#include "MatterConfigFileManager.h"
#include "inc_CommonLib/NLEWraper.h"
#include "inc_CommonLib/PlayerMaterProvider.h"
#include "inc_MediaPlayerView/MediaPlayerControl.h"
#include "Interface/INLERender.h"
#include "Include/NLEKey.h"
#include "../Controls/IconButton.h"
#include "inc_CommonLib/NLETimeline.h"
#include "NLEComPtr.h"
#include "inc_MatterView/MatterDataBase.h"

#include "MatterDataManager.h"
#include "MatterDataList.h"

#include "ImportHelper.h"

MatterViewPrivate::MatterViewPrivate(QWidget *parent)
	: QWidget(parent)
{
	//m_pSplitter = new QSplitter(Qt::Vertical,this);
	//m_pSplitter->setChildrenCollapsible(false);

	m_pUpperView = new UpperView(this);
	m_pToolBarView = new MatterViewToolBar(this, "MatterViewToolBar");
	m_pToolBarView->setStyleSheet("background-color:white;");
	//m_pToolBarView->setMinimumHeight(m_nToolBarHeight);
	//m_pToolBarView->setMaximumHeight(m_nToolBarHeight);
	connect(m_pToolBarView, &MatterViewToolBar::Clicked, m_pUpperView->GetResView(), &ResViewArea::slotToolBtnClicked);

	//m_pSplitter->addWidget(m_pUpperView);
	//m_pSplitter->addWidget(m_pToolBarView);
	//m_pSplitter->setStyleSheet("background-color:white;");
}

MatterViewPrivate::~MatterViewPrivate()
{
	
}


void MatterViewPrivate::resizeEvent(QResizeEvent *event)
{
	m_pUpperView->setGeometry(0, 0, width(), height() - m_nToolBarHeight);
	m_pToolBarView->setGeometry(0, height() - m_nToolBarHeight, width(), m_nToolBarHeight);
	//m_pSplitter->setGeometry(rect());
	//m_pSplitter->setSizes(QList<int>() << (rect().height() - m_nToolBarHeight) << m_nToolBarHeight);

	emit sigViewSizeChanged(QSize(width(), height()));
}


////////////////////////////////////////////////////////////
// UpperView
////////////////////////////////////////////////////////////
UpperView::UpperView(QWidget *parent)
:QWidget(parent)
{
	m_pResView = new ResViewArea(this);
}

UpperView::~UpperView()
{

}

void UpperView::resizeEvent(QResizeEvent *event)
{
	QRect rc = rect();
	m_pResView->setGeometry(rc);

	QWidget::resizeEvent(event);
}


////////////////////////////////////////////////////////////
// ResViewArea
////////////////////////////////////////////////////////////
ResViewArea::ResViewArea(QWidget *parent)
:QWidget(parent)
, m_bLoaded(false)
{
	m_pTopToolView = new QWidget(this);

	IconButton *btnImport = new IconButton(tr("IMPORT"), m_pTopToolView);
	connect(btnImport, &IconButton::clicked, this, &ResViewArea::slotImportBtnClicked);
	m_btnRemove = new IconButton(tr("REMOVE"), m_pTopToolView);
	connect(m_btnRemove, &IconButton::clicked, this, &ResViewArea::slotRemoveBtnClicked);
	btnImport->setGeometry(20, 10, 100, 20);
	m_btnRemove->setGeometry(100, 10, 100, 20);
	btnImport->SetIconImage(":/Image/Resources/import5213.png", QSize(13, 13));
	m_btnRemove->SetIconImage(":/Image/Resources/delete5213.png", QSize(13, 13));
	m_btnRemove->SetEnabled(false);


	m_pBottomListView = new QWidget(this);
	m_pBottomListView->setStyleSheet("background-color:white;");

	m_pStackLayout = new QStackedLayout(m_pBottomListView);
	m_pBottomListView->setLayout(m_pStackLayout);
	m_pStackLayout->setContentsMargins(0, 0, 0, 0);

	//用户资源列表
	ResListView *pList = CreateListCtrl(3); //3:多选
	m_pStackLayout->insertWidget(MatterDataType_Media, pList);
	connect(pList->GetListWidget(), &QListWidget::itemSelectionChanged, this, [&](){
		m_btnRemove->SetEnabled(!((QListWidget*)sender())->selectedItems().isEmpty());
	});

	ConnectSignlas(pList);

	//滤镜
	pList = CreateListCtrl(1); //1:单选
	m_pStackLayout->insertWidget(MatterDataType_Effect, pList);
	ConnectSignlas(pList);

	//声音滤镜
	pList = CreateListCtrl(1); //1:单选
	m_pStackLayout->insertWidget(MatterDataType_Audio_Effect, pList);
	ConnectSignlas(pList);

	//文字
	pList = CreateListCtrl(1); //1:单选
	m_pStackLayout->insertWidget(MatterDataType_Text, pList);
	ConnectSignlas(pList);

	//蒙太奇
	pList = CreateListCtrl(1); //1:单选
	m_pStackLayout->insertWidget(MatterDataType_Montage, pList);
	ConnectSignlas(pList);

	MatterDataManager::GetInstance().Init();
	SetupListView(MatterDataType_Media);
	SetupListView(MatterDataType_Effect);
	SetupListView(MatterDataType_Audio_Effect);
	SetupListView(MatterDataType_Text);
	SetupListView(MatterDataType_Montage);
	ShowListView(MatterDataType_Media);
}

ResViewArea::~ResViewArea()
{

}

void ResViewArea::ConnectSignlas(ResListView *pList)
{
	if (!pList) return;
	connect(pList, &ResListView::signalLBtnSingleSelected, this, [&](QListWidgetItem* pItem){
		ListItemData* pItemData = dynamic_cast<ListItemData*>(pItem);
		if (!pItemData) return;
		if (pItemData->eType != ListItemType_video 
			&& pItemData->eType != ListItemType_effect 
			&& pItemData->eType != ListItemType_text
			&&pItemData->eType != ListItemType_Image)
			return;
		emit signalLoad(false);
	});
	connect(pList, &ResListView::signalLBtnMultiSelected, this, [&](QList<QListWidgetItem*> pItems){
		ListItemData* pItemData = dynamic_cast<ListItemData*>(pItems.first());
		if (!pItemData) return;
		if (pItemData->eType != ListItemType_video 
			&& pItemData->eType != ListItemType_effect 
			&& pItemData->eType != ListItemType_text
			&&pItemData->eType != ListItemType_Image) return;
		emit signalLoad(false);
	});

	connect(pList, &ResListView::signalLBtnDClickedSelected, this, [&](QListWidgetItem* pItem){
		ListItemData* pItemData = dynamic_cast<ListItemData*>(pItem);
		if (!pItemData) return;
		if (pItemData->eType != ListItemType_video 
			&& pItemData->eType != ListItemType_effect 
			&& pItemData->eType != ListItemType_text
			&&pItemData->eType != ListItemType_Image) return;
		emit signalLoad(true);
	});
	connect(pList, &ResListView::signalBlankAreaLClick, this, [&](){
		emit signalUnload();
	});

	connect(pList, &ResListView::signalLBtnSingleSelectedDown, this, [&](QListWidgetItem* pItem){
		
		// 点击item时再加载资源
		ListItemData* pItemData = dynamic_cast<ListItemData*>(pItem);
		if (!pItemData) return;		
		if (pItemData->eType == ListItemType_text)
		{
			MatterDataManager::GetInstance().GetTextDataList()->LoadTimeline(pItemData->pMatterData);
		}
	});

}

void ResViewArea::SetFocus(bool bFocus)
{
	if (!bFocus)
	{
		ResListView* pListView = dynamic_cast<ResListView*>(m_pStackLayout->currentWidget());
		pListView->UnselectAllItems();
		emit signalUnload();
	}
}

NLETimeline* ResViewArea::GetCurrentTimeline()
{
	QList<QListWidgetItem*> items = GetSelectedItems();
	if (items.size() <= 0) 
		return nullptr;
	QListWidgetItem* item = items.first();

	ListItemData* selectedItemData = dynamic_cast<ListItemData*>(item);
	if (!selectedItemData) 
		return nullptr;

	NLEComPtr<INLETimelineBase> ptimeline;
	if (selectedItemData->pMatterData->nDataType == MatterDataType_Effect)
	{

		if (NLEWraper::GetInstance().GetPlayerMaterProvider()->GetVideoFilterCombineTimeline(selectedItemData->pMatterData->pTimeline->GetSrc(), &ptimeline))
		{
			return new NLETimeline(ptimeline);
		}

	}
	else
	{
		if (NLEWraper::GetInstance().GetPlayerMaterProvider()->GetMediaCombineTimeline(selectedItemData->pMatterData->pTimeline->GetSrc(), &ptimeline))
		{
			return new NLETimeline(ptimeline);
		}
	}
	return nullptr;
}

void ResViewArea::resizeEvent(QResizeEvent *event)
{
	static const int nTopToolH = 30;
	QRect rc = rect();
	m_pTopToolView->setGeometry(0, 0, rc.width(), nTopToolH);
	m_pBottomListView->setGeometry(0, nTopToolH, rc.width(), rc.height() - nTopToolH);
}

void ResViewArea::slotImportBtnClicked()
{
	QStringList filters;

	filters << QString("All supported files (%1 %2 %3)").arg(ImportFilter[FilterType_Video][1], ImportFilter[FilterType_Audio][1], ImportFilter[FilterType_Image][1])
		<< QString("%1 (%2)").arg(ImportFilter[FilterType_Video][0], ImportFilter[FilterType_Video][1])
		<< QString("%1 (%2)").arg(ImportFilter[FilterType_Audio][0], ImportFilter[FilterType_Audio][1])
		<< QString("%1 (%2)").arg(ImportFilter[FilterType_Image][0], ImportFilter[FilterType_Image][1])
		<< QString("%1 (%2)").arg(ImportFilter[FilterType_All][0], ImportFilter[FilterType_All][1]);

	QFileDialog dialog(this);
	dialog.setNameFilters(filters);
	dialog.setAcceptMode(QFileDialog::AcceptOpen);
	dialog.setFileMode(QFileDialog::ExistingFiles);
	if (dialog.exec())
	{
		QStringList list = dialog.selectedFiles();
		if (list.empty()) return;

		ImportMediaDlg dlg(list);
		connect(&dlg, &ImportMediaDlg::signalImported, this, [&](MatterDataBase* pData){
			MediaData* pMediaData = (MediaData*)pData;
			ListItemType itemType = MediaType2ListItemType(pMediaData->nResType);
			AddListItemWidget(MatterDataType_Media, pData, itemType);
		});
		dlg.DoImport();
	}
	
}

void ResViewArea::slotRemoveBtnClicked()
{
	ResListView* pListView = dynamic_cast<ResListView*>(m_pStackLayout->currentWidget());
	if (!pListView) return;
	emit signalUnload();
	QList<QListWidgetItem*> items =  pListView->GetListWidget()->selectedItems();
	for (QListWidgetItem* item : items)
	{
		ListItemData *pListItem = dynamic_cast<ListItemData *>(item);
		if (!pListItem) continue;
		MediaData *pMediaData = dynamic_cast<MediaData *>(pListItem->pMatterData);
		if (!pMediaData) continue;

		pListView->RemoveItemWidget(pListItem);
		MatterConfigFileManager::GetInstance().RemoveMediaItem(pMediaData);
		MatterDataManager::GetInstance().GetMediaDataList()->RemoveItem(pMediaData->strId);
	}
}

void ResViewArea::slotToolBtnClicked(int id)
{
	ShowListView(id);
}

void ResViewArea::ShowListView(int nWhichList)
{
	if (m_pStackLayout->currentIndex() == nWhichList) return;
	emit signalUnload();
	ResListView* pListView = dynamic_cast<ResListView*>(m_pStackLayout->currentWidget());
	pListView->UnselectAllItems();
	m_pStackLayout->setCurrentIndex(nWhichList);

	if (nWhichList == MatterDataType_Media)
	{
		m_pTopToolView->setVisible(true);  //导入和删除按钮
	}
	else
	{
		m_pTopToolView->setVisible(false);
	}
}

void ResViewArea::SetupListView(int nWhichList)
{
	if (nWhichList == MatterDataType_Effect)
	{
		FilterDataList* listData = MatterDataManager::GetInstance().GetFilterDataList();
		for (auto pData : listData->GetDataList())
		{
			if (!pData) continue;
			AddListItemWidget(nWhichList, pData, ListItemType_effect);
		}
	}
	else if (nWhichList == MatterDataType_Audio_Effect)
	{
		AudioFilterDataList* listData = MatterDataManager::GetInstance().GetAudioFilterDataList();
		for (auto pData : listData->GetDataList())
		{
			if (!pData) continue;
			AddListItemWidget(nWhichList, pData, ListItemType_audio_effect);
		}
	}
	else if (nWhichList == MatterDataType_Montage)
	{
		MontageDataList* listData = MatterDataManager::GetInstance().GetMontageDataList();
		for (auto pData : listData->GetDataList())
		{
			if (!pData) continue;
			AddListItemWidget(nWhichList, pData, ListItemType_montage);
		}
	}
	else if (nWhichList == MatterDataType_Media)
	{
		MediaDataList* listData = MatterDataManager::GetInstance().GetMediaDataList();
		for (auto pData : listData->GetDataList())
		{
			if (!pData) continue;
			MediaData* pMediaData = (MediaData*)pData;
			ListItemType itemType = MediaType2ListItemType(pMediaData->nResType);
			AddListItemWidget(nWhichList, pData, itemType);
		}
	}
	else if (nWhichList == MatterDataType_Text)
	{
		TextDataList* listData = MatterDataManager::GetInstance().GetTextDataList();
		for (auto pData : listData->GetDataList())
		{
			if (!pData) continue;
			AddListItemWidget(nWhichList, pData, ListItemType_text);
		}
	}
}

ResListView* ResViewArea::CreateListCtrl(int nSeletionMode)
{
	return new ResListView(m_pBottomListView, nSeletionMode);
}

void ResViewArea::AddListItemWidget(int nWhichList, MatterDataBase *pData,ListItemType eListItemType)
{
	ResListView* pListView = dynamic_cast<ResListView*>(m_pStackLayout->widget(nWhichList));
	if (!pListView) return;

	static const int ItemViewW = 92;
	static const int ItemViewH = 82;
	QSize itemViewSize(ItemViewW, ItemViewH);

	ListItemData * pItemData = new ListItemData(pData, pListView->GetListWidget(), eListItemType);

	if (!pItemData) return;
	pItemData->frameSize = itemViewSize;
	pListView->AddItemWidget(pItemData);
}

ListItemType ResViewArea::MediaType2ListItemType(int nMediaType)
{
	ListItemType itemType = ListItemType_base;
	if (nMediaType == MediaDataType_Video)
	{
		itemType = ListItemType_video;
	}
	else if (nMediaType == MediaDataType_Audio)
	{
		itemType = ListItemType_music;
	}
	else if (nMediaType == MediaDataType_Image)
	{
		itemType = ListItemType_Image;
	}
	return itemType;
}

QList<QListWidgetItem*> ResViewArea::GetSelectedItems()
{
	ResListView* pListView = dynamic_cast<ResListView*>(m_pStackLayout->currentWidget());
	return pListView->GetListWidget()->selectedItems();
}
