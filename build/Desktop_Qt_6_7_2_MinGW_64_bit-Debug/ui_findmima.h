/********************************************************************************
** Form generated from reading UI file 'findmima.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINDMIMA_H
#define UI_FINDMIMA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_FindMima
{
public:
    QLineEdit *lineEditPasswordCheck_2;
    QLabel *labelName;
    QLineEdit *lineEditName;
    QLabel *labelPasswordCheck_2;
    QPushButton *registerCheckButton;
    QLineEdit *lineEditPassword;
    QLabel *labelPassword;

    void setupUi(QDialog *FindMima)
    {
        if (FindMima->objectName().isEmpty())
            FindMima->setObjectName("FindMima");
        FindMima->resize(246, 306);
        lineEditPasswordCheck_2 = new QLineEdit(FindMima);
        lineEditPasswordCheck_2->setObjectName("lineEditPasswordCheck_2");
        lineEditPasswordCheck_2->setGeometry(QRect(130, 100, 91, 20));
        lineEditPasswordCheck_2->setStyleSheet(QString::fromUtf8("background-image: url(:/images/backw.png);"));
        labelName = new QLabel(FindMima);
        labelName->setObjectName("labelName");
        labelName->setGeometry(QRect(40, 50, 72, 20));
        lineEditName = new QLineEdit(FindMima);
        lineEditName->setObjectName("lineEditName");
        lineEditName->setGeometry(QRect(130, 50, 91, 20));
        lineEditName->setStyleSheet(QString::fromUtf8("background-image: url(:/images/backw.png);"));
        labelPasswordCheck_2 = new QLabel(FindMima);
        labelPasswordCheck_2->setObjectName("labelPasswordCheck_2");
        labelPasswordCheck_2->setGeometry(QRect(40, 100, 72, 20));
        registerCheckButton = new QPushButton(FindMima);
        registerCheckButton->setObjectName("registerCheckButton");
        registerCheckButton->setGeometry(QRect(80, 210, 81, 41));
        registerCheckButton->setStyleSheet(QString::fromUtf8("background-image: url(:/images/backw.png);"));
        lineEditPassword = new QLineEdit(FindMima);
        lineEditPassword->setObjectName("lineEditPassword");
        lineEditPassword->setGeometry(QRect(130, 140, 91, 20));
        lineEditPassword->setStyleSheet(QString::fromUtf8("background-image: url(:/images/backw.png);"));
        labelPassword = new QLabel(FindMima);
        labelPassword->setObjectName("labelPassword");
        labelPassword->setGeometry(QRect(40, 140, 72, 20));

        retranslateUi(FindMima);

        QMetaObject::connectSlotsByName(FindMima);
    } // setupUi

    void retranslateUi(QDialog *FindMima)
    {
        FindMima->setWindowTitle(QCoreApplication::translate("FindMima", "Dialog", nullptr));
        lineEditPasswordCheck_2->setText(QString());
        labelName->setText(QCoreApplication::translate("FindMima", "\347\224\250\346\210\267\345\220\215", nullptr));
        labelPasswordCheck_2->setText(QCoreApplication::translate("FindMima", "\351\202\256\347\256\261", nullptr));
        registerCheckButton->setText(QCoreApplication::translate("FindMima", "\346\233\264\346\224\271\345\257\206\347\240\201", nullptr));
        labelPassword->setText(QCoreApplication::translate("FindMima", "\346\226\260\345\257\206\347\240\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FindMima: public Ui_FindMima {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINDMIMA_H
