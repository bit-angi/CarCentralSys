/********************************************************************************
** Form generated from reading UI file 'littlepicwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LITTLEPICWIDGET_H
#define UI_LITTLEPICWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LittlePicWidget
{
public:
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;

    void setupUi(QWidget *LittlePicWidget)
    {
        if (LittlePicWidget->objectName().isEmpty())
            LittlePicWidget->setObjectName("LittlePicWidget");
        LittlePicWidget->resize(500, 400);
        pushButton_2 = new QPushButton(LittlePicWidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(60, 370, 30, 30));
        pushButton_3 = new QPushButton(LittlePicWidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(130, 370, 30, 30));
        pushButton_4 = new QPushButton(LittlePicWidget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(200, 370, 30, 30));
        pushButton_5 = new QPushButton(LittlePicWidget);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(270, 370, 30, 30));
        pushButton_6 = new QPushButton(LittlePicWidget);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(340, 370, 30, 30));
        pushButton_7 = new QPushButton(LittlePicWidget);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(410, 370, 30, 30));

        retranslateUi(LittlePicWidget);

        QMetaObject::connectSlotsByName(LittlePicWidget);
    } // setupUi

    void retranslateUi(QWidget *LittlePicWidget)
    {
        LittlePicWidget->setWindowTitle(QCoreApplication::translate("LittlePicWidget", "Form", nullptr));
        pushButton_2->setText(QCoreApplication::translate("LittlePicWidget", "PushButton", nullptr));
        pushButton_3->setText(QCoreApplication::translate("LittlePicWidget", "PushButton", nullptr));
        pushButton_4->setText(QCoreApplication::translate("LittlePicWidget", "PushButton", nullptr));
        pushButton_5->setText(QCoreApplication::translate("LittlePicWidget", "PushButton", nullptr));
        pushButton_6->setText(QCoreApplication::translate("LittlePicWidget", "PushButton", nullptr));
        pushButton_7->setText(QCoreApplication::translate("LittlePicWidget", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LittlePicWidget: public Ui_LittlePicWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LITTLEPICWIDGET_H
