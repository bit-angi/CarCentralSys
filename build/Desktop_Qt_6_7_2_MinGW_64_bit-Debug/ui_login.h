/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QWidget *widget;
    QPushButton *btn_edit_pwd;
    QLabel *label_2;
    QCheckBox *checkBox_rPasswd;
    QLineEdit *lineEdit_passwd;
    QLabel *label;
    QCheckBox *checkBox_autoLogin;
    QPushButton *btn_regist;
    QPushButton *btn_login;
    QLineEdit *line_ac;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label_3;

    void setupUi(QWidget *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName("Login");
        Login->resize(960, 600);
        widget = new QWidget(Login);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 0, 960, 600));
        widget->setStyleSheet(QString::fromUtf8("background-color : rgb(241, 241, 241)"));
        btn_edit_pwd = new QPushButton(widget);
        btn_edit_pwd->setObjectName("btn_edit_pwd");
        btn_edit_pwd->setGeometry(QRect(630, 370, 91, 23));
        QFont font;
        font.setFamilies({QString::fromUtf8("\351\273\221\344\275\223")});
        font.setPointSize(12);
        font.setBold(false);
        font.setItalic(false);
        btn_edit_pwd->setFont(font);
        btn_edit_pwd->setStyleSheet(QString::fromUtf8("color:rgb(26, 173, 25);\n"
"font: 12pt \"\351\273\221\344\275\223\" ;\n"
"font-weight:20px;"));
        btn_edit_pwd->setFlat(true);
        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(499, 410, 75, 16));
        checkBox_rPasswd = new QCheckBox(widget);
        checkBox_rPasswd->setObjectName("checkBox_rPasswd");
        checkBox_rPasswd->setGeometry(QRect(354, 410, 16, 16));
        lineEdit_passwd = new QLineEdit(widget);
        lineEdit_passwd->setObjectName("lineEdit_passwd");
        lineEdit_passwd->setGeometry(QRect(290, 370, 331, 31));
        lineEdit_passwd->setMinimumSize(QSize(170, 22));
        QFont font1;
        font1.setPointSize(12);
        lineEdit_passwd->setFont(font1);
        lineEdit_passwd->setStyleSheet(QString::fromUtf8("border-radius:10px;\n"
"background-color:white;"));
        label = new QLabel(widget);
        label->setObjectName("label");
        label->setGeometry(QRect(373, 410, 75, 16));
        checkBox_autoLogin = new QCheckBox(widget);
        checkBox_autoLogin->setObjectName("checkBox_autoLogin");
        checkBox_autoLogin->setGeometry(QRect(480, 410, 16, 16));
        btn_regist = new QPushButton(widget);
        btn_regist->setObjectName("btn_regist");
        btn_regist->setGeometry(QRect(630, 320, 91, 23));
        btn_regist->setFont(font);
        btn_regist->setStyleSheet(QString::fromUtf8("color:rgb(26, 173, 25);\n"
"font: 12pt \"\351\273\221\344\275\223\" ;\n"
"font-weight:20px;"));
        btn_regist->setFlat(true);
        btn_login = new QPushButton(widget);
        btn_login->setObjectName("btn_login");
        btn_login->setGeometry(QRect(390, 440, 141, 31));
        btn_login->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"color:rgb(255, 255, 255);\n"
"font: 12pt \"\351\273\221\344\275\223\" ;\n"
"font-weight:20px;\n"
"border-radius:10px;\n"
"background-color:rgb(170,170,170);\n"
"}\n"
"QPushButton:hover{\n"
"	background-color :rgb(200,200,200) ;\n"
"	color:white;\n"
"}\n"
"\n"
""));
        line_ac = new QLineEdit(widget);
        line_ac->setObjectName("line_ac");
        line_ac->setGeometry(QRect(290, 320, 331, 31));
        line_ac->setMinimumSize(QSize(170, 22));
        line_ac->setFont(font1);
        line_ac->setStyleSheet(QString::fromUtf8("border-radius:10px;\n"
"background-color:white;"));
        pushButton = new QPushButton(widget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(580, 375, 31, 21));
        pushButton->setStyleSheet(QString::fromUtf8("background-color:white;\n"
"border-radius:2px\n"
""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/eye"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton->setIcon(icon);
        pushButton->setIconSize(QSize(25, 25));
        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(340, 160, 241, 131));
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color:rgb(240,240,240);\n"
"border-radius:2px;"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/wx"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_2->setIcon(icon1);
        pushButton_2->setIconSize(QSize(155, 155));
        label_3 = new QLabel(widget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(320, 80, 331, 81));
        label_3->setMinimumSize(QSize(331, 0));
        label_3->setStyleSheet(QString::fromUtf8("color:rgb(26, 173, 25);\n"
"font: 30pt \"\351\273\221\344\275\223\" ;\n"
"font-weight:20px;"));

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QWidget *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "Form", nullptr));
        btn_edit_pwd->setText(QCoreApplication::translate("Login", "\346\211\276\345\233\236\345\257\206\347\240\201", nullptr));
        label_2->setText(QCoreApplication::translate("Login", "\350\207\252\345\212\250\347\231\273\345\275\225", nullptr));
        checkBox_rPasswd->setText(QString());
        label->setText(QCoreApplication::translate("Login", "\350\256\260\344\275\217\345\257\206\347\240\201", nullptr));
        checkBox_autoLogin->setText(QString());
        btn_regist->setText(QCoreApplication::translate("Login", "\346\263\250\345\206\214\345\270\220\345\217\267", nullptr));
        btn_login->setText(QCoreApplication::translate("Login", "\347\231\273\345\275\225", nullptr));
        pushButton->setText(QString());
        pushButton_2->setText(QString());
        label_3->setText(QCoreApplication::translate("Login", "\350\275\246\350\275\275\350\201\212\345\244\251\345\256\244\347\263\273\347\273\237", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
