#pragma once

#include "NormalItemView.h"

class QLabel;
class ListItemData;
class EffectItemView : public NormalItemView
{
	Q_OBJECT

public:
	EffectItemView(ListItemData *pListItem, QWidget *parent = 0);
	~EffectItemView();

protected:
	QLabel* m_pVideoImg;
};

