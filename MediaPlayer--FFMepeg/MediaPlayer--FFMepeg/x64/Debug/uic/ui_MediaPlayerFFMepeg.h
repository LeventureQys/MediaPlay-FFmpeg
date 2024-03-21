/********************************************************************************
** Form generated from reading UI file 'MediaPlayerFFMepeg.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MEDIAPLAYERFFMEPEG_H
#define UI_MEDIAPLAYERFFMEPEG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MediaPlayerFFMepegClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MediaPlayerFFMepegClass)
    {
        if (MediaPlayerFFMepegClass->objectName().isEmpty())
            MediaPlayerFFMepegClass->setObjectName(QString::fromUtf8("MediaPlayerFFMepegClass"));
        MediaPlayerFFMepegClass->resize(600, 400);
        menuBar = new QMenuBar(MediaPlayerFFMepegClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        MediaPlayerFFMepegClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MediaPlayerFFMepegClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MediaPlayerFFMepegClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(MediaPlayerFFMepegClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        MediaPlayerFFMepegClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MediaPlayerFFMepegClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MediaPlayerFFMepegClass->setStatusBar(statusBar);

        retranslateUi(MediaPlayerFFMepegClass);

        QMetaObject::connectSlotsByName(MediaPlayerFFMepegClass);
    } // setupUi

    void retranslateUi(QMainWindow *MediaPlayerFFMepegClass)
    {
        MediaPlayerFFMepegClass->setWindowTitle(QCoreApplication::translate("MediaPlayerFFMepegClass", "MediaPlayerFFMepeg", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MediaPlayerFFMepegClass: public Ui_MediaPlayerFFMepegClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEDIAPLAYERFFMEPEG_H
