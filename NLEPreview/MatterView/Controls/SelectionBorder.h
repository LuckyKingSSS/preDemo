#ifndef SELECTIONBORDER_H
#define SELECTIONBORDER_H

//#include <QLabel>
class QPen;
class SelectionBorder : public QLabel
{
	Q_OBJECT

public:
	enum SelectionState
	{
		SelectionState_Normal,
		SelectionState_Hover,
		SelectionState_Seleted
	};

	SelectionBorder(QWidget *parent = 0);
	~SelectionBorder();

	void setSelectionState(SelectionState s);

protected:
	void paintEvent(QPaintEvent *e);

	QPen *m_pen;

};

#endif // SELECTIONBORDER_H
