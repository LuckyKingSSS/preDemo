#pragma once
//#include <QPushButton>
class QPixmap;
class IconButton : public QPushButton
{
	Q_OBJECT
	enum IconButton_State
	{
		STATE_NOMAL = 0,
		STATE_HOVER,
		STATE_PRESS,
		STATE_DISABLE
	};

public:
	IconButton(const QString &text,QWidget *parent = 0);
	~IconButton();

	void SetIconImage(const QString& strImageUrl, const QSize& sigleIconSize);
	void SetEnabled(bool bEnable);
protected:

	virtual void enterEvent(QEvent * e);
	virtual void leaveEvent(QEvent * e);
	void mousePressEvent(QMouseEvent *e);
	void mouseReleaseEvent(QMouseEvent *e);
	void paintEvent(QPaintEvent * e);

	void DrawButton(QPaintEvent * e);

private:
	IconButton_State m_state;

	QPixmap *m_pPixmap;
	int m_nW;
	int m_nH;
};

