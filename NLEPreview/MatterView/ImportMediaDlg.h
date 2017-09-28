#pragma once
#include <QtWidgets/QDialog>
class ImportHelper;
class MatterDataBase;
class QProgressBar;
class QLabel;
class TopLevelWindowTitleBar;
class ImportMediaDlg : public QDialog
{
	Q_OBJECT

public:
	ImportMediaDlg(const QStringList &list, QWidget *parent = 0);
	~ImportMediaDlg();

	int DoImport();
Q_SIGNALS:
	void signalImported(MatterDataBase*);
public Q_SLOTS:
	void slotCancelBtnClicked();
protected:
	void resizeEvent(QResizeEvent *event);
	void closeEvent(QCloseEvent *event);
private:
	TopLevelWindowTitleBar *m_titleBar;

	ImportHelper *m_pHelper;

	QPushButton *m_pCancelBtn;
	QProgressBar *m_pProgress;
	QLabel *m_pNamelabel;
	QLabel *m_pProgressLabel;
};


