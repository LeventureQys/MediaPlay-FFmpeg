/********************************************************************************
** Form generated from reading UI file 'MediaPlayerFFMepeg.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MEDIAPLAYERFFMEPEG_H
#define UI_MEDIAPLAYERFFMEPEG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
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
    QPlainTextEdit *plainTextEdit;

    void setupUi(QMainWindow *MediaPlayerFFMepegClass)
    {
        if (MediaPlayerFFMepegClass->objectName().isEmpty())
            MediaPlayerFFMepegClass->setObjectName(QString::fromUtf8("MediaPlayerFFMepegClass"));
        MediaPlayerFFMepegClass->resize(793, 454);
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
        tabWidget->addTab(tab_2, QString());

        horizontalLayout->addWidget(tabWidget);

        plainTextEdit = new QPlainTextEdit(centralWidget);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));

        horizontalLayout->addWidget(plainTextEdit);

        MediaPlayerFFMepegClass->setCentralWidget(centralWidget);

        retranslateUi(MediaPlayerFFMepegClass);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MediaPlayerFFMepegClass);
    } // setupUi

    void retranslateUi(QMainWindow *MediaPlayerFFMepegClass)
    {
        MediaPlayerFFMepegClass->setWindowTitle(QApplication::translate("MediaPlayerFFMepegClass", "MediaPlayerFFMepeg", nullptr));
        btn_getProtocol->setText(QApplication::translate("MediaPlayerFFMepegClass", "\350\216\267\345\276\227\345\215\217\350\256\256\346\224\257\346\214\201\344\277\241\346\201\257", nullptr));
        btn_getAVFormat->setText(QApplication::translate("MediaPlayerFFMepegClass", "\350\216\267\345\276\227AVFormat\344\277\241\346\201\257", nullptr));
        btn_getAVCodeInfo->setText(QApplication::translate("MediaPlayerFFMepegClass", "\350\216\267\345\276\227AVCodeInfo", nullptr));
        btn_getAVFilterInfo->setText(QApplication::translate("MediaPlayerFFMepegClass", "\350\216\267\345\276\227AVFilterInfo\344\277\241\346\201\257", nullptr));
        btn_getConfiguration->setText(QApplication::translate("MediaPlayerFFMepegClass", "\350\216\267\345\276\227\351\205\215\347\275\256\344\277\241\346\201\257", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MediaPlayerFFMepegClass", "BaseInfo", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MediaPlayerFFMepegClass", "Tab 2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MediaPlayerFFMepegClass: public Ui_MediaPlayerFFMepegClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEDIAPLAYERFFMEPEG_H
