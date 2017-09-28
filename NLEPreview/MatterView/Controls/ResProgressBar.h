#ifndef RESPROGRESSBAR_H
#define RESPROGRESSBAR_H

//#include <QWidget>
#include <QColor>
class ResProgressBar : public QWidget
{
	Q_OBJECT

public:
	ResProgressBar(QWidget *parent = 0);
	~ResProgressBar();

	void SetValue(int nValue); //0 - 100
protected:
	void paintEvent(QPaintEvent *e);
private:
	int m_nValue;
	QColor m_clrClientBg;
	QColor m_clrBodyBg;
	QColor m_clrChunk;


};

#endif // RESPROGRESSBAR_H
