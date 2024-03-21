/********************************************************************************
** Form generated from reading UI file 'test_ffmpeg.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEST_FFMPEG_H
#define UI_TEST_FFMPEG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_test_ffmpegClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *test_ffmpegClass)
    {
        if (test_ffmpegClass->objectName().isEmpty())
            test_ffmpegClass->setObjectName(QString::fromUtf8("test_ffmpegClass"));
        test_ffmpegClass->resize(600, 400);
        menuBar = new QMenuBar(test_ffmpegClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        test_ffmpegClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(test_ffmpegClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        test_ffmpegClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(test_ffmpegClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        test_ffmpegClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(test_ffmpegClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        test_ffmpegClass->setStatusBar(statusBar);

        retranslateUi(test_ffmpegClass);

        QMetaObject::connectSlotsByName(test_ffmpegClass);
    } // setupUi

    void retranslateUi(QMainWindow *test_ffmpegClass)
    {
        test_ffmpegClass->setWindowTitle(QCoreApplication::translate("test_ffmpegClass", "test_ffmpeg", nullptr));
    } // retranslateUi

};

namespace Ui {
    class test_ffmpegClass: public Ui_test_ffmpegClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEST_FFMPEG_H
