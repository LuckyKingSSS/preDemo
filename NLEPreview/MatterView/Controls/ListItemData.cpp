#include "stdafx.h"
#include "ListItemData.h"


ListItemDataBase::ListItemDataBase(MatterDataBase *pMatterData, QListWidget* owner, ListItemType eType)
:QListWidgetItem(owner)
{
	this->pMatterData = pMatterData;
	this->eType = eType;
}

ListItemDataBase::~ListItemDataBase()
{

}

//ListNormalItemData::ListNormalItemData(MatterDataBase *pMatterData,QListWidget* owner, ListItemType eType)
//:ListItemData(pMatterData,owner, eType)
//{
//}
//
//ListNormalItemData::~ListNormalItemData()
//{
//
//}
//
//ListImageItemData::ListImageItemData(MatterDataBase *pMatterData, QListWidget* owner, ListItemType eType)
//:ListNormalItemData(pMatterData,owner, eType)
//{
//
//}
//
//ListImageItemData::~ListImageItemData()
//{
//
//}
//
//ListMusicItemData::ListMusicItemData(MatterDataBase *pMatterData, QListWidget* owner, ListItemType eType)
//:ListNormalItemData(pMatterData,owner, eType)
//{
//
//}
//
//ListMusicItemData::~ListMusicItemData()
//{
//
//}
//
//ListVideaItemData::ListVideaItemData(MatterDataBase *pMatterData, QListWidget* owner, ListItemType eType)
//:ListNormalItemData(pMatterData,owner, eType)
//{
//
//}
//
//ListVideaItemData::~ListVideaItemData()
//{
//
//}
