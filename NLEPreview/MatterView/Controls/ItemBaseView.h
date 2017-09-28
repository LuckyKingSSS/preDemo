#ifndef RESITEMVIEW_H
#define RESITEMVIEW_H

//#include <QWidget>
class QPixmap;
class QLabel;
class QListWidget;
class ListItemData;
class SelectionBorder;
class ColorBlock;

class ItemBaseView : public QWidget
{
	Q_OBJECT
	enum ViewState
	{
		ViewState_Normal,
		ViewState_MouseMove,
		ViewState_Selected,
	};
public:
	ItemBaseView(ListItemData *pListItem, QWidget *parent = 0);
	~ItemBaseView();

	void SetThumbnail(const QString &strImageUrl);

protected:
	virtual void RaiseSubControls(); //给个机会调整子控件的层叠顺序

	virtual void showEvent(QShowEvent *) Q_DECL_OVERRIDE;
	virtual void enterEvent(QEvent *e) Q_DECL_OVERRIDE;
	virtual void leaveEvent(QEvent *e) Q_DECL_OVERRIDE;
	virtual void paintEvent(QPaintEvent *e) Q_DECL_OVERRIDE;
	virtual void mousePressEvent(QMouseEvent *) Q_DECL_OVERRIDE;
	virtual void mouseMoveEvent(QMouseEvent *e) Q_DECL_OVERRIDE;
	virtual void resizeEvent(QResizeEvent *e) Q_DECL_OVERRIDE;

protected:
	QLabel *m_plabel;
	QLabel *m_pThumbImg;
	SelectionBorder *m_pSelectionBorder;

	ListItemData *m_pListItemData;
	ViewState m_viewState;
	QListWidget *m_pParentList;

	QFont m_textFont;

	bool m_mousePress;
	QPoint m_pressPoint;
};

#endif // RESITEMVIEW_H
