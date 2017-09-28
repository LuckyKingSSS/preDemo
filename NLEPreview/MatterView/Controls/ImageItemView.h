#pragma once

#include "NormalItemView.h"

class QLabel;
class ListItemData;
class ImageItemView : public NormalItemView
{
	Q_OBJECT

public:
	ImageItemView(ListItemData *pListItem, QWidget *parent = 0);
	~ImageItemView();

protected:
};

