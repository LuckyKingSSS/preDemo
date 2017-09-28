#ifndef VIDEAITEMVIEW_H
#define VIDEAITEMVIEW_H

#include "NormalItemView.h"

class QLabel;
class ListItemData;
class VideoItemView : public NormalItemView
{
	Q_OBJECT

public:
	VideoItemView(ListItemData *pListItem, QWidget *parent = 0);
	~VideoItemView();
protected:
	virtual void resizeEvent(QResizeEvent *e) Q_DECL_OVERRIDE;
protected:
	QLabel* m_pVideoImg;
	QRect m_rcVideoImg;
};

#endif // RESITEMVIEW_H
