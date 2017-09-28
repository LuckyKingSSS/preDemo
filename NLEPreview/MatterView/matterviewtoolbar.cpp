#include "stdafx.h"
#include "matterviewtoolbar.h"
#include "MatterDataDefine.h"
//#include <QButtonGroup>
#include <QPainter>

//MatterViewToolBarButton
/////////////////////////////////////////////////////
MatterViewToolBarButton::MatterViewToolBarButton(int id, QWidget *parent, const QString &strObjName, const QString &strText)
:QPushButton(parent)
{
	m_nId = id;
	m_strText = strText;
	setObjectName(strObjName);
	setCheckable(true);
	setFocusPolicy(Qt::NoFocus);
	setStyleSheet("background-color:rgba(0,0,0,0);");
	connect(this, &QPushButton::clicked, [&](){
		emit Clicked(m_nId);
	});
}

MatterViewToolBarButton::~MatterViewToolBarButton()
{

}

void MatterViewToolBarButton::SetPixmap(const QPixmap &image)
{
	m_Image = image;
	update();
}

void MatterViewToolBarButton::resizeEvent(QResizeEvent *event)
{
	m_rcClient = rect();
	m_rcImg = QRect(0, 0, m_rcClient.width(), m_rcClient.height() * 2 / 3);
	m_rcText = QRect(0, m_rcClient.height() *2/3, m_rcClient.width(), m_rcClient.height() * 1/3);
}

void MatterViewToolBarButton::paintEvent(QPaintEvent *event)
{
	int ImageW = m_Image.width() / 3;
	int ImageH = m_Image.height();
	int nPadding = 6;

	QPainter painter(this);
	//»­Í¼ºÍÎÄ×Ö
	int nLeft = m_rcImg.left() + (m_rcImg.width() - ImageW) * 0.5;
	int nTop = m_rcImg.top() + (m_rcImg.height() - ImageH) - nPadding;
	QRect rcTagImg(nLeft, nTop, ImageW, ImageH);
	
	QPen pen;
	if (isChecked())
	{
		painter.drawPixmap(rcTagImg, m_Image, QRect(ImageW, 0, ImageW, ImageH));
		pen.setColor(QColor(17,138,149));
	}
	else if (underMouse())
	{
		painter.drawPixmap(rcTagImg, m_Image, QRect(ImageW, 0, ImageW, ImageH));
		pen.setColor(QColor(17, 138, 149));
	}
	else
	{
		painter.drawPixmap(rcTagImg, m_Image, QRect(0, 0, ImageW, ImageH));
		pen.setColor(QColor(0, 0, 0));
	}
	//ÎÄ×Ö
	painter.setPen(pen);
	QTextOption textOp(Qt::AlignHCenter);
	QFont fnt;
	fnt.setPointSize(11);
	fnt.setBold(true);
	painter.setFont(fnt);
	painter.drawText(m_rcText, m_strText, textOp);
}

//MatterViewToolBar
/////////////////////////////////////////////////////
struct ButtonId_ObjName
{
	int id;
	QString objName;
};
static const ButtonId_ObjName arrIdObjname[] = {
	{ MatterDataType_Media, "MEDIA" },
	{ MatterDataType_Effect, "EFFECT" },
	{ MatterDataType_Audio_Effect, "AUDIO" },
	{ MatterDataType_Text, "TEXT" },
	{ MatterDataType_Montage, "MONTAGE" }
};

MatterViewToolBar::MatterViewToolBar(QWidget *parent, const QString &strObjName)
: QWidget(parent)
{
	setObjectName(strObjName);
	setAttribute(Qt::WA_StyledBackground);

	m_pButtonGroup = new QButtonGroup(this);
	
	int id;
	QString objName;
	for (int i = 0; i < sizeof(arrIdObjname) / sizeof(arrIdObjname[0]); ++i)
	{
		id = arrIdObjname[i].id;
		objName = arrIdObjname[i].objName;
		AddToolButton(id, objName, objName);
	}
}

MatterViewToolBar::~MatterViewToolBar()
{

}

void MatterViewToolBar::resizeEvent(QResizeEvent *event)
{
	int nBtnCnt = m_pButtonGroup->buttons().size();
	if (nBtnCnt <= 0) return;

	static const int nLeftMargin = 20;
	static const int nRightMargin = 20;
	static const int nTopMargin = 0;
	static const int nBottomMargin = 0;

	int nBtnW = 80;
	

	QRect rcReal = rect().adjusted(nLeftMargin, nTopMargin, -nRightMargin, -nBottomMargin);

	int nBtnH = rect().height() - nTopMargin - nBottomMargin;
	nBtnH = 60;

	for (int i = 0; i < sizeof(arrIdObjname) / sizeof(arrIdObjname[0]); ++i)
	{
		int id = arrIdObjname[i].id;
		
		auto *pbtn = m_pButtonGroup->button(id);
		if (pbtn)
		{
			pbtn->setGeometry(rcReal.left(), rcReal.top(), nBtnW, nBtnH);
			rcReal.setLeft(rcReal.left() + nBtnW);
		}
	}

	//auto *pbtn = m_pButtonGroup->button(MatterDataType_Media);
	//if (pbtn)
	//{
	//	pbtn->setGeometry(rcReal.left(), rcReal.top(), nBtnW, nBtnH);
	//	rcReal.setLeft(rcReal.left() + nBtnW);
	//}
	//pbtn = m_pButtonGroup->button(MatterDataType_Effect);
	//if (pbtn)
	//{
	//	pbtn->setGeometry(rcReal.left(), rcReal.top(), nBtnW, nBtnH);
	//	rcReal.setLeft(rcReal.left() + nBtnW);
	//}
	//pbtn = m_pButtonGroup->button(MatterDataType_Audio_Effect);
	//if (pbtn)
	//{
	//	pbtn->setGeometry(rcReal.left(), rcReal.top(), nBtnW, nBtnH);
	//	rcReal.setLeft(rcReal.left() + nBtnW);
	//}
	//pbtn = m_pButtonGroup->button(MatterDataType_Text);
	//if (pbtn)
	//{
	//	pbtn->setGeometry(rcReal.left(), rcReal.top(), nBtnW, nBtnH);
	//	rcReal.setLeft(rcReal.left() + nBtnW);
	//}
}

void MatterViewToolBar::AddToolButton(int id, const QString &strObjName, const QString &strText)
{
	MatterViewToolBarButton *pButton = new MatterViewToolBarButton(id, this, strObjName,strText);
	connect(pButton, &MatterViewToolBarButton::Clicked, this, &MatterViewToolBar::Clicked);
	m_pButtonGroup->addButton(pButton, id);

	if (id == MatterDataType_Media)
	{
		pButton->SetPixmap(QPixmap(":/Image/Resources/media2222.png"));
		pButton->setChecked(true);
	}
	else if (id == MatterDataType_Effect)
	{
		pButton->SetPixmap(QPixmap(":/Image/Resources/filter2222.png"));
	}
	else if (id == MatterDataType_Audio_Effect)
	{
		pButton->SetPixmap(QPixmap(":/Image/Resources/filter2222.png"));
	}
	else if (id == MatterDataType_Text)
	{
		pButton->SetPixmap(QPixmap(":/Image/Resources/filter2222.png"));
	}
	else if (id == MatterDataType_Montage)
	{
		pButton->SetPixmap(QPixmap(":/Image/Resources/filter2222.png"));
	}
}

void MatterViewToolBar::RemoveToolButton(int id)
{
	
}
