/********************************************************************************
** Form generated from reading UI file 'register.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTER_H
#define UI_REGISTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Register
{
public:
    QPushButton *registerCheckButton;
    QLabel *labelPasswordCheck;
    QLabel *labelName;
    QLineEdit *lineEditName;
    QLabel *labelPassword;
    QLineEdit *lineEditPasswordCheck;
    QLineEdit *lineEditPassword;
    QLabel *labelPasswordCheck_2;
    QLineEdit *lineEditPasswordCheck_2;

    void setupUi(QWidget *Register)
    {
        if (Register->objectName().isEmpty())
            Register->setObjectName("Register");
        Register->resize(236, 309);
        registerCheckButton = new QPushButton(Register);
        registerCheckButton->setObjectName("registerCheckButton");
        registerCheckButton->setGeometry(QRect(70, 200, 81, 41));
        registerCheckButton->setStyleSheet(QString::fromUtf8("background-image: url(:/images/backw.png);"));
        labelPasswordCheck = new QLabel(Register);
        labelPasswordCheck->setObjectName("labelPasswordCheck");
        labelPasswordCheck->setGeometry(QRect(30, 130, 72, 20));
        labelName = new QLabel(Register);
        labelName->setObjectName("labelName");
        labelName->setGeometry(QRect(30, 40, 72, 20));
        lineEditName = new QLineEdit(Register);
        lineEditName->setObjectName("lineEditName");
        lineEditName->setGeometry(QRect(120, 40, 91, 20));
        lineEditName->setStyleSheet(QString::fromUtf8("background-image: url(:/images/backw.png);"));
        labelPassword = new QLabel(Register);
        labelPassword->setObjectName("labelPassword");
        labelPassword->setGeometry(QRect(30, 80, 72, 20));
        lineEditPasswordCheck = new QLineEdit(Register);
        lineEditPasswordCheck->setObjectName("lineEditPasswordCheck");
        lineEditPasswordCheck->setGeometry(QRect(120, 130, 91, 20));
        lineEditPasswordCheck->setStyleSheet(QString::fromUtf8("background-image: url(:/images/backw.png);"));
        lineEditPassword = new QLineEdit(Register);
        lineEditPassword->setObjectName("lineEditPassword");
        lineEditPassword->setGeometry(QRect(120, 80, 91, 20));
        lineEditPassword->setStyleSheet(QString::fromUtf8("background-image: url(:/images/backw.png);"));
        labelPasswordCheck_2 = new QLabel(Register);
        labelPasswordCheck_2->setObjectName("labelPasswordCheck_2");
        labelPasswordCheck_2->setGeometry(QRect(30, 170, 72, 20));
        lineEditPasswordCheck_2 = new QLineEdit(Register);
        lineEditPasswordCheck_2->setObjectName("lineEditPasswordCheck_2");
        lineEditPasswordCheck_2->setGeometry(QRect(120, 170, 91, 20));
        lineEditPasswordCheck_2->setStyleSheet(QString::fromUtf8("background-image: url(:/images/backw.png);"));

        retranslateUi(Register);

        QMetaObject::connectSlotsByName(Register);
    } // setupUi

    void retranslateUi(QWidget *Register)
    {
        Register->setWindowTitle(QCoreApplication::translate("Register", "Form", nullptr));
        registerCheckButton->setText(QCoreApplication::translate("Register", "\346\263\250\345\206\214", nullptr));
        labelPasswordCheck->setText(QCoreApplication::translate("Register", "\347\241\256\350\256\244\345\257\206\347\240\201", nullptr));
        labelName->setText(QCoreApplication::translate("Register", "\347\224\250\346\210\267\345\220\215", nullptr));
        labelPassword->setText(QCoreApplication::translate("Register", "\345\257\206\347\240\201", nullptr));
        labelPasswordCheck_2->setText(QCoreApplication::translate("Register", "\351\202\256\347\256\261", nullptr));
        lineEditPasswordCheck_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Register: public Ui_Register {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER_H
