/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QTextEdit *textEdit;
    QPushButton *pushButton;
    QLabel *label;
    QPushButton *pushButton_2;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(711, 551);
        textEdit = new QTextEdit(Widget);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(10, 150, 621, 131));
        pushButton = new QPushButton(Widget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(110, 350, 171, 71));
        label = new QLabel(Widget);
        label->setObjectName("label");
        label->setGeometry(QRect(50, 30, 531, 91));
        label->setStyleSheet(QString::fromUtf8("font-size: 50px\n"
""));
        pushButton_2 = new QPushButton(Widget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(380, 350, 191, 61));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget", "\350\257\206\345\210\253", nullptr));
        label->setText(QCoreApplication::translate("Widget", "\350\257\255\351\237\263\350\257\206\345\210\253demo", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Widget", "\346\270\205\351\231\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
