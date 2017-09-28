#ifndef RESLISTVIEW_H
#define RESLISTVIEW_H

#include <QMouseEvent>
#include <QTimer>
#include <QTime>
#include "NormalItemView.h"
#include "ListItemData.h"
class QListWidget;
class ListItemData;
class QListWidgetItem;

class ResListWidget : public QListWidget
{
	Q_OBJECT
public:
	ResListWidget(QWidget *parent = 0);
	~ResListWidget();
	
Q_SIGNALS:
	void signalBlankAreaLClick();
	void signalBlankAreaRClick();

	void signalLBtnMultiSelected(QList<QListWidgetItem*>);
	void signalLBtnSingleSelected(QListWidgetItem*);
	void signalLBtnDClickedSelected(QListWidgetItem*);
	void signalLBtnSingleSelectedDown(QListWidgetItem*);


	void signalShowSelectionRect(bool,const QRect &rc);

protected:
	friend class ResListView;
	virtual void mousePressEvent(QMouseEvent *e);
	virtual void mouseMoveEvent(QMouseEvent *e);
	void mouseReleaseEvent(QMouseEvent *e);
	void UnselectAllItems();

	void resizeEvent(QResizeEvent *e) Q_DECL_OVERRIDE;

private:
	void lBtnDClicked();
	void lBtnClicked();
private:
	QTimer m_timer;
	QTime m_interval;

	QListWidgetItem* m_pPreClickItem;

	QPoint dragStartPosition;


};

class SelectionWidget;
class ResListView : public QWidget
{
	Q_OBJECT

public:
	ResListView(QWidget *parent = 0,int selectMode = 3);
	~ResListView();
	void InitListWidget(int nSelectMode);
	QListWidget* GetListWidget() { return m_pListWidget; }
	QWidget* GetItemWidget(ListItemData* pItemData);

	void UnselectAllItems();

	void AddItemWidget(ListItemData* pItemData);
	void RemoveItemWidget(ListItemData* pItemData);
	void SetSpacing(int nSpacing);

protected:
	ItemBaseView* CreateItemViewByItemData(ListItemData* pItemData);

	void resizeEvent(QResizeEvent *e);

Q_SIGNALS:
	void signalItemAddBtnClicked(ListItemData *);

	void signalLBtnMultiSelected(QList<QListWidgetItem*>);
	void signalLBtnSingleSelected(QListWidgetItem*);
	void signalLBtnDClickedSelected(QListWidgetItem*);
	void signalLBtnSingleSelectedDown(QListWidgetItem*);

	void signalBlankAreaLClick();
	void signalBlankAreaRClick();
private:
	ResListWidget *m_pListWidget;
	SelectionWidget *m_pSelectionWidget;
};

class SelectionWidget : public QWidget
{
	Q_OBJECT

public:
	SelectionWidget(QWidget *parent = 0);
	~SelectionWidget();

	void SetSelectedRect(const QRect &rcSelected);

protected:
	void paintEvent(QPaintEvent *e);
private:
	QRect m_rcSelected;
};

#endif // RESLISTVIEW_H
