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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MediaPlayerFFMepegClass
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QPushButton *btn_getProtocol;
    QPushButton *btn_getAVFormat;
    QPushButton *btn_getAVCodeInfo;
    QPushButton *btn_getAVFilterInfo;
    QPushButton *btn_getConfiguration;
    QWidget *tab_2;
    QWidget *wid_mediaplayer;
    QHBoxLayout *horizontalLayout_3;
    QLabel *lab_mediaPlayer;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btn_chooseMeadia;
    QPushButton *btn_play;
    QPushButton *btn_VideoClose;
    QSlider *horizontalSlider;
    QPlainTextEdit *plainTextEdit;

    void setupUi(QMainWindow *MediaPlayerFFMepegClass)
    {
        if (MediaPlayerFFMepegClass->objectName().isEmpty())
            MediaPlayerFFMepegClass->setObjectName(QString::fromUtf8("MediaPlayerFFMepegClass"));
        MediaPlayerFFMepegClass->resize(1245, 650);
        centralWidget = new QWidget(MediaPlayerFFMepegClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        btn_getProtocol = new QPushButton(tab);
        btn_getProtocol->setObjectName(QString::fromUtf8("btn_getProtocol"));
        btn_getProtocol->setGeometry(QRect(10, 10, 141, 23));
        btn_getAVFormat = new QPushButton(tab);
        btn_getAVFormat->setObjectName(QString::fromUtf8("btn_getAVFormat"));
        btn_getAVFormat->setGeometry(QRect(10, 40, 141, 23));
        btn_getAVCodeInfo = new QPushButton(tab);
        btn_getAVCodeInfo->setObjectName(QString::fromUtf8("btn_getAVCodeInfo"));
        btn_getAVCodeInfo->setGeometry(QRect(10, 70, 141, 23));
        btn_getAVFilterInfo = new QPushButton(tab);
        btn_getAVFilterInfo->setObjectName(QString::fromUtf8("btn_getAVFilterInfo"));
        btn_getAVFilterInfo->setGeometry(QRect(10, 100, 141, 23));
        btn_getConfiguration = new QPushButton(tab);
        btn_getConfiguration->setObjectName(QString::fromUtf8("btn_getConfiguration"));
        btn_getConfiguration->setGeometry(QRect(10, 130, 141, 23));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        wid_mediaplayer = new QWidget(tab_2);
        wid_mediaplayer->setObjectName(QString::fromUtf8("wid_mediaplayer"));
        wid_mediaplayer->setGeometry(QRect(10, 60, 591, 531));
        horizontalLayout_3 = new QHBoxLayout(wid_mediaplayer);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        lab_mediaPlayer = new QLabel(wid_mediaplayer);
        lab_mediaPlayer->setObjectName(QString::fromUtf8("lab_mediaPlayer"));

        horizontalLayout_3->addWidget(lab_mediaPlayer);

        layoutWidget = new QWidget(tab_2);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 20, 581, 25));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        btn_chooseMeadia = new QPushButton(layoutWidget);
        btn_chooseMeadia->setObjectName(QString::fromUtf8("btn_chooseMeadia"));

        horizontalLayout_2->addWidget(btn_chooseMeadia);

        btn_play = new QPushButton(layoutWidget);
        btn_play->setObjectName(QString::fromUtf8("btn_play"));
        btn_play->setCheckable(true);

        horizontalLayout_2->addWidget(btn_play);

        btn_VideoClose = new QPushButton(layoutWidget);
        btn_VideoClose->setObjectName(QString::fromUtf8("btn_VideoClose"));

        horizontalLayout_2->addWidget(btn_VideoClose);

        horizontalSlider = new QSlider(layoutWidget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(horizontalSlider);

        tabWidget->addTab(tab_2, QString());

        horizontalLayout->addWidget(tabWidget);

        plainTextEdit = new QPlainTextEdit(centralWidget);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));

        horizontalLayout->addWidget(plainTextEdit);

        MediaPlayerFFMepegClass->setCentralWidget(centralWidget);

        retranslateUi(MediaPlayerFFMepegClass);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MediaPlayerFFMepegClass);
    } // setupUi

    void retranslateUi(QMainWindow *MediaPlayerFFMepegClass)
    {
        MediaPlayerFFMepegClass->setWindowTitle(QCoreApplication::translate("MediaPlayerFFMepegClass", "MediaPlayerFFMepeg", nullptr));
        btn_getProtocol->setText(QCoreApplication::translate("MediaPlayerFFMepegClass", "\350\216\267\345\276\227\345\215\217\350\256\256\346\224\257\346\214\201\344\277\241\346\201\257", nullptr));
        btn_getAVFormat->setText(QCoreApplication::translate("MediaPlayerFFMepegClass", "\350\216\267\345\276\227AVFormat\344\277\241\346\201\257", nullptr));
        btn_getAVCodeInfo->setText(QCoreApplication::translate("MediaPlayerFFMepegClass", "\350\216\267\345\276\227AVCodeInfo", nullptr));
        btn_getAVFilterInfo->setText(QCoreApplication::translate("MediaPlayerFFMepegClass", "\350\216\267\345\276\227AVFilterInfo\344\277\241\346\201\257", nullptr));
        btn_getConfiguration->setText(QCoreApplication::translate("MediaPlayerFFMepegClass", "\350\216\267\345\276\227\351\205\215\347\275\256\344\277\241\346\201\257", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MediaPlayerFFMepegClass", "BaseInfo", nullptr));
        lab_mediaPlayer->setText(QString());
        btn_chooseMeadia->setText(QCoreApplication::translate("MediaPlayerFFMepegClass", "\351\200\211\346\213\251...", nullptr));
        btn_play->setText(QCoreApplication::translate("MediaPlayerFFMepegClass", "\346\222\255\346\224\276", nullptr));
        btn_VideoClose->setText(QCoreApplication::translate("MediaPlayerFFMepegClass", "\345\205\263\351\227\255\350\247\206\351\242\221", nullptr));
#if QT_CONFIG(whatsthis)
        horizontalSlider->setWhatsThis(QCoreApplication::translate("MediaPlayerFFMepegClass", "<html><head/><body><p>\351\237\263\351\207\217</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MediaPlayerFFMepegClass", "MediaCore", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MediaPlayerFFMepegClass: public Ui_MediaPlayerFFMepegClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEDIAPLAYERFFMEPEG_H
