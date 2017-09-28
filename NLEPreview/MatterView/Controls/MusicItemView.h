#pragma once
#include "NormalItemView.h"

class QLabel;
class ListItemData;
class MusicItemView : public NormalItemView
{
	Q_OBJECT

public:
	MusicItemView(ListItemData *pListItem, QWidget *parent = 0);
	~MusicItemView();

protected:
	virtual void resizeEvent(QResizeEvent *e) Q_DECL_OVERRIDE;

protected:
	QLabel* m_pMusicImg;
	QRect m_rcMusicImg;
};


