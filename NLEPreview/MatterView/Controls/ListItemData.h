#ifndef LISTITEMDATA_H
#define LISTITEMDATA_H
//#include <QListWidgetItem>
class QListWidget;
class MatterDataBase;

enum ListItemType
{
	ListItemType_base,
	ListItemType_normal,
	ListItemType_Image,
	ListItemType_music,
	ListItemType_video,
	ListItemType_effect,
	ListItemType_audio_effect,
	ListItemType_text,
	ListItemType_montage,
};

class ListItemDataBase : public QListWidgetItem
{
public:
	ListItemDataBase(MatterDataBase *pMatterData, QListWidget* owner, ListItemType eType = ListItemType_base);
	~ListItemDataBase();

	QSize frameSize;
	QColor clrBackground;
	ListItemType eType; 
	MatterDataBase *pMatterData;
};

class ListItemData : public ListItemDataBase
{
public:
	ListItemData(MatterDataBase *pMatterData, QListWidget* owner, ListItemType eType)
		:ListItemDataBase(pMatterData, owner, eType){}
	~ListItemData(){}
};


//class ListNormalItemData : public ListItemData
//{
//public:
//	ListNormalItemData(MatterDataBase *pMatterData,QListWidget* owner, ListItemType eType = ListItemType_normal);
//	~ListNormalItemData();
//
//	//int nProgressValue;
//	//bool bNeedDownload;   
//};
//
//class ListImageItemData : public ListNormalItemData
//{
//	ListImageItemData(MatterDataBase *pMatterData,QListWidget* owner, ListItemType eType = ListItemType_Image);
//	~ListImageItemData();
//};
//
//class ListMusicItemData : public ListNormalItemData
//{
//	ListMusicItemData(MatterDataBase *pMatterData, QListWidget* owner, ListItemType eType = ListItemType_music);
//	~ListMusicItemData();
//};
//
//class ListVideaItemData : public ListNormalItemData
//{
//public:
//	ListVideaItemData(MatterDataBase *pMatterData, QListWidget* owner, ListItemType eType = ListItemType_video);
//	~ListVideaItemData();
//};

#endif // LISTITEMDATA_H
