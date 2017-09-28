#ifndef NORMALITEMVIEW_H
#define NORMALITEMVIEW_H

#include "ItemBaseView.h"

class ResProgressBar;
class ImgButton;
class QLabel;
class ListItemData;
class NormalItemView : public ItemBaseView
{
	Q_OBJECT

public:
	NormalItemView(ListItemData *pListItem, QWidget *parent = 0);
	~NormalItemView();
Q_SIGNALS:
	void signalAddBtnClicked(ListItemData *);
protected:
	virtual void enterEvent(QEvent *e) Q_DECL_OVERRIDE;
	virtual void leaveEvent(QEvent *e) Q_DECL_OVERRIDE;
	virtual void resizeEvent(QResizeEvent *e) Q_DECL_OVERRIDE;
protected:
	ImgButton *m_pAddButton;
};

class TextItemView : public NormalItemView
{
	Q_OBJECT

public:
	TextItemView(ListItemData *pListItem, QWidget *parent = 0);
	~TextItemView();
};

class AudioFilterItemView : public NormalItemView
{
	Q_OBJECT

public:
	AudioFilterItemView(ListItemData *pListItem, QWidget *parent = 0);
	~AudioFilterItemView();
};

class MontageItemView : public NormalItemView
{
	Q_OBJECT

public:
	MontageItemView(ListItemData *pListItem, QWidget *parent = 0);
	~MontageItemView();
};


#endif // RESITEMVIEW_H
