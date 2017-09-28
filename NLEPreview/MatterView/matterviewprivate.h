#ifndef MATTERVIEWPRIVATE_H
#define MATTERVIEWPRIVATE_H
//#include <QWidget>
//#include <QMap>
#include "Controls/ListItemData.h"


class QSplitter;
class MatterViewToolBar;
class UpperView;
class IMediaPlayerControl;
class INLERender;
class MatterViewPrivate : public QWidget
{
	Q_OBJECT

public:
	MatterViewPrivate(QWidget *parent = nullptr);
	~MatterViewPrivate();

	void resizeEvent(QResizeEvent *event);

Q_SIGNALS:
	void sigViewSizeChanged(QSize size);

public:
	//QSplitter *m_pSplitter;
	UpperView *m_pUpperView;
	MatterViewToolBar *m_pToolBarView;

	const int m_nToolBarHeight = 60;
};

class ResViewArea;
class UpperView : public QWidget
{
	Q_OBJECT
public:
	UpperView(QWidget *parent = nullptr);
	~UpperView();
	ResViewArea* GetResView() { return m_pResView; }
protected:
	void resizeEvent(QResizeEvent *event);
private:
	//QWidget *m_pListView;
	ResViewArea *m_pResView;

	const int m_nListViewW = 148;
};

class ResListView;
class QStackedLayout;
class MatterDataBase;
class IconButton;
class INLERender;
class INLETimelineBase;
class NLETimeline;
class ResViewArea : public QWidget
{
	Q_OBJECT
public:
	ResViewArea(QWidget *parent = nullptr);
	~ResViewArea();

	NLETimeline* GetCurrentTimeline();
	void SetFocus(bool bFocus);
protected:
	void ConnectSignlas(ResListView *pList);
	void resizeEvent(QResizeEvent *event);
Q_SIGNALS:
	void signalUnload();
	void signalLoad(bool bPlay);
public Q_SLOTS:
	void slotImportBtnClicked();
	void slotRemoveBtnClicked();
	void slotToolBtnClicked(int id);
private:
	void SetupListView(int nWhichList);
	void ShowListView(int nWhichList);

	ResListView* CreateListCtrl(int nSeletionMode);
	void AddListItemWidget(int nWhichList, MatterDataBase *pData, ListItemType eListItemType);
	

	ListItemType MediaType2ListItemType(int nMediaType);


	QList<QListWidgetItem*> GetSelectedItems();
private:
	IconButton *m_btnRemove;
	QWidget *m_pTopToolView;
	QWidget *m_pBottomListView;

	QStackedLayout *m_pStackLayout;
	bool m_bLoaded;
};





#endif // MATTERVIEWPRIVATE_H
