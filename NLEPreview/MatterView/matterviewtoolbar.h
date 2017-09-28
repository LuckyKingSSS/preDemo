#ifndef MATTERVIEWTOOLBAR_H
#define MATTERVIEWTOOLBAR_H

class MatterViewToolBarButton : public QPushButton
{
	Q_OBJECT
public:
	MatterViewToolBarButton(int id, QWidget *parent = nullptr, const QString &strObjName = "", const QString &strText = "");
	~MatterViewToolBarButton();

	void SetPixmap(const QPixmap &image);
Q_SIGNALS:
	void Clicked(int id);

protected:
	void resizeEvent(QResizeEvent *event);
	void paintEvent(QPaintEvent *event);
private:

	int m_nId;
	QString m_strText;
	QPixmap m_Image;

	QRect m_rcClient;
	QRect m_rcImg;
	QRect m_rcText;
};

class QButtonGroup;
class MatterViewToolBar : public QWidget
{
	Q_OBJECT

public:
	MatterViewToolBar(QWidget *parent = nullptr,const QString &strObjName = "");
	~MatterViewToolBar();
	
	void AddToolButton(int id, const QString &strObjName, const QString &strText);
	void RemoveToolButton(int id);
Q_SIGNALS:
	void Clicked(int id);
protected:
	void resizeEvent(QResizeEvent *event);
private:
	QButtonGroup *m_pButtonGroup;
};

#endif // MATTERVIEWTOOLBAR_H
