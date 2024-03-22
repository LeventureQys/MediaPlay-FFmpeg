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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
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
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QComboBox *comboBox;
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
        wid_mediaplayer->setGeometry(QRect(10, 60, 587, 535));
        pushButton = new QPushButton(tab_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 20, 71, 23));
        pushButton_2 = new QPushButton(tab_2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(90, 20, 75, 23));
        pushButton_3 = new QPushButton(tab_2);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(170, 20, 75, 23));
        comboBox = new QComboBox(tab_2);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(260, 20, 69, 22));
        horizontalSlider = new QSlider(tab_2);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(350, 20, 160, 22));
        horizontalSlider->setOrientation(Qt::Horizontal);
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
        pushButton->setText(QCoreApplication::translate("MediaPlayerFFMepegClass", "\351\200\211\346\213\251...", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MediaPlayerFFMepegClass", "\346\222\255\346\224\276", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MediaPlayerFFMepegClass", "\345\205\263\351\227\255\350\247\206\351\242\221", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MediaPlayerFFMepegClass", "1x", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MediaPlayerFFMepegClass", "1.5x", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MediaPlayerFFMepegClass", "2x", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("MediaPlayerFFMepegClass", "2.5x", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("MediaPlayerFFMepegClass", "3x", nullptr));

#if QT_CONFIG(whatsthis)
        comboBox->setWhatsThis(QCoreApplication::translate("MediaPlayerFFMepegClass", "<html><head/><body><p>\346\222\255\346\224\276\351\200\237\345\272\246</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
#if QT_CONFIG(whatsthis)
        horizontalSlider->setWhatsThis(QCoreApplication::translate("MediaPlayerFFMepegClass", "<html><head/><body><p>\351\237\263\351\207\217</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MediaPlayerFFMepegClass", "Tab 2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MediaPlayerFFMepegClass: public Ui_MediaPlayerFFMepegClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEDIAPLAYERFFMEPEG_H
