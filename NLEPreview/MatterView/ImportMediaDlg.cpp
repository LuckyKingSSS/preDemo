#include "stdafx.h"
#include "ImportMediaDlg.h"
#include "ImportHelper.h"
#include "inc_MatterView/MatterDataBase.h"
#include "FileOperation.h"
#include "MatterDataManager.h"
#include "MatterDataList.h"
#include "inc_CommonLib/TopLevelWindowTitleBar.h"

ImportMediaDlg::ImportMediaDlg(const QStringList &list,QWidget *parent)
: QDialog(parent)
{

	setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
	setMinimumSize(600, 150);
	m_titleBar = new TopLevelWindowTitleBar(this);
	m_titleBar->SetTitleName("Import");
	m_titleBar->SetResizeble(false);
	m_titleBar->SetDragMaximum(false);
	m_titleBar->SetButtons(TopLevelWindowTitleBar::Close);

	m_pHelper = new ImportHelper(list,this);
	m_pNamelabel = new QLabel(this);
	m_pNamelabel->setText(tr(""));

	m_pProgressLabel = new QLabel(this);
	m_pProgressLabel->setText(tr(""));

	m_pProgress = new QProgressBar(this);
	m_pProgress->setTextVisible(false);
	m_pProgress->setValue(0);

	m_pCancelBtn = new QPushButton(tr("Cancel"), this);
	connect(m_pCancelBtn, &QPushButton::clicked, this, &ImportMediaDlg::slotCancelBtnClicked);

	connect(m_pHelper, &ImportHelper::signalImported, this, &ImportMediaDlg::signalImported);
	connect(m_pHelper, &ImportHelper::finished, this, [&](){
		done(1);
	});
	connect(m_pHelper, &ImportHelper::signalImportBegin, this, [&](QString fileName){
		m_pNamelabel->setText(tr("Fly in and Fade ") + fileName + tr("."));
	});
	connect(m_pHelper, &ImportHelper::signalImportProgressText, this, [&](QString progressText){
		m_pProgressLabel->setText(progressText);
	});
	connect(m_pHelper, &ImportHelper::signalImportProgress, this, [&](int progress){
		m_pProgress->setValue(progress);
	});

	//resize(460, 70);	
}

ImportMediaDlg::~ImportMediaDlg()
{
	
}

void ImportMediaDlg::slotCancelBtnClicked()
{
	m_pHelper->UserCancel();
}

void ImportMediaDlg::resizeEvent(QResizeEvent *event)
{
	QRect rcAll = rect();
	const int margins = 3;
	
	int widthWidth = width() - 2 * margins;

	m_titleBar->setGeometry(margins, margins, widthWidth, 22);
	int top = m_titleBar->geometry().bottom() + 10;

	const int btnWidth = 70;
	const int space = 15;
	int left = space;

	m_pNamelabel->setGeometry(left, top, width() - btnWidth - 2 * space - 10, 15);
	left = m_pNamelabel->geometry().right() + 10;

	m_pProgressLabel->setGeometry(left, top, 30, 15);

	top = height() - 40;
	left = space;

	m_pProgress->setGeometry(space, top, width() - btnWidth - 2 * space - 10, 10);
	left = m_pProgress->geometry().right() + 10;
	m_pCancelBtn->setGeometry(left, top - 4, 70, 22);
}

void ImportMediaDlg::closeEvent(QCloseEvent *event)
{
	m_pHelper->UserCancel();
	QDialog::closeEvent(event);
}

int ImportMediaDlg::DoImport()
{
	m_pHelper->DoImportAsync();
	return exec();
}
