#ifndef ImgButton_H
#define ImgButton_H

//#include <QPushButton>
class QPixmap;
class ImgButton : public QPushButton
{
	Q_OBJECT
	enum ImgButton_State
	{
		STATE_NOMAL = 0,
		STATE_HOVER,
		STATE_PRESS,
		STATE_DISABLE,
		STATE_FOCUS
	};

public:
	ImgButton(QWidget *parent = 0);
	~ImgButton();

	void SetImage(const QString& strImageUrl, const QSize& sigleImgSize);
	void SetEnabled(bool bEnable);
protected:

	virtual void enterEvent(QEvent * e);
	virtual void leaveEvent(QEvent * e);
	void mousePressEvent(QMouseEvent *e);
	void mouseReleaseEvent(QMouseEvent *e);
	void paintEvent(QPaintEvent * e);

	void DrawButton(QPaintEvent * e);

private:
	ImgButton_State m_state;

	QPixmap *m_pPixmap;
	int m_nW;
	int m_nH;
};


#endif // ImgButton_H
