/********************************************************************************
** Form generated from reading UI file 'nlepreviewmain.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NLEPREVIEWMAIN_H
#define UI_NLEPREVIEWMAIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NLEPreviewMainClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *NLEPreviewMainClass)
    {
        if (NLEPreviewMainClass->objectName().isEmpty())
            NLEPreviewMainClass->setObjectName(QStringLiteral("NLEPreviewMainClass"));
        NLEPreviewMainClass->resize(600, 400);
        menuBar = new QMenuBar(NLEPreviewMainClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        NLEPreviewMainClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(NLEPreviewMainClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        NLEPreviewMainClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(NLEPreviewMainClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        NLEPreviewMainClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(NLEPreviewMainClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        NLEPreviewMainClass->setStatusBar(statusBar);

        retranslateUi(NLEPreviewMainClass);

        QMetaObject::connectSlotsByName(NLEPreviewMainClass);
    } // setupUi

    void retranslateUi(QMainWindow *NLEPreviewMainClass)
    {
        NLEPreviewMainClass->setWindowTitle(QApplication::translate("NLEPreviewMainClass", "MediaPlayerViewPrivate", 0));
    } // retranslateUi

};

namespace Ui {
    class NLEPreviewMainClass: public Ui_NLEPreviewMainClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NLEPREVIEWMAIN_H
