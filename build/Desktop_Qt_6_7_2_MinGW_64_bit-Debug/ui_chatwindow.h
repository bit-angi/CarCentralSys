/********************************************************************************
** Form generated from reading UI file 'chatwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATWINDOW_H
#define UI_CHATWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatWindow
{
public:
    QWidget *centralwidget;
    QListWidget *listWidget;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QWidget *widget;
    QLabel *label_5;
    QFrame *line_2;
    QLabel *label;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton_4;
    QLabel *label_3;
    QPushButton *pushButton_5;
    QPushButton *pushButton_3;
    QWidget *widget_2;
    QLabel *label_2;
    QTextEdit *textEdit;

    void setupUi(QMainWindow *ChatWindow)
    {
        if (ChatWindow->objectName().isEmpty())
            ChatWindow->setObjectName("ChatWindow");
        ChatWindow->resize(960, 600);
        ChatWindow->setMinimumSize(QSize(811, 0));
        centralwidget = new QWidget(ChatWindow);
        centralwidget->setObjectName("centralwidget");
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(770, 220, 181, 331));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(560, 510, 141, 31));
        pushButton_2->setStyleSheet(QString::fromUtf8("color:rgb(26, 173, 25);\n"
"font: 12pt \"\351\273\221\344\275\223\" ;\n"
"font-weight:20px;"));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(863, 77, 91, 22));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(790, 140, 131, 31));
        pushButton->setStyleSheet(QString::fromUtf8("color:rgb(26, 173, 25);\n"
"font: 12pt \"\351\273\221\344\275\223\" ;\n"
"font-weight:20px;\n"
"border-radius:20px;\n"
"background-color:rgb(220,220,220);"));
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 0, 961, 61));
        widget->setStyleSheet(QString::fromUtf8("background-color:rgb(241,241,241)"));
        label_5 = new QLabel(widget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(40, 0, 211, 61));
        label_5->setStyleSheet(QString::fromUtf8("color:black;\n"
"font: 20pt \"\351\273\221\344\275\223\";\n"
"font-weight:3px"));
        line_2 = new QFrame(widget);
        line_2->setObjectName("line_2");
        line_2->setGeometry(QRect(0, 50, 961, 16));
        line_2->setStyleSheet(QString::fromUtf8("size:20px"));
        line_2->setFrameShape(QFrame::Shape::HLine);
        line_2->setFrameShadow(QFrame::Shadow::Sunken);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(765, 77, 63, 21));
        label->setStyleSheet(QString::fromUtf8("color:white;\n"
"font: 16pt \"\351\273\221\344\275\223\";\n"
"font-weight:3px"));
        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(863, 111, 91, 22));
        lineEdit_3 = new QLineEdit(centralwidget);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(30, 390, 701, 161));
        lineEdit_3->setStyleSheet(QString::fromUtf8("background-color:rgb(245,245,245);\n"
"font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(40, 400, 25, 25));
        pushButton_4->setStyleSheet(QString::fromUtf8("background-color:white;\n"
"border-radius:2px;\n"
"cusor:pointer;"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("C:/Users/wangxi/Desktop/biaoq.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_4->setIcon(icon);
        pushButton_4->setIconSize(QSize(30, 30));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(770, 180, 291, 31));
        label_3->setStyleSheet(QString::fromUtf8("color:white;\n"
"font: 14pt \"\351\273\221\344\275\223\";"));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(80, 400, 28, 25));
        pushButton_5->setStyleSheet(QString::fromUtf8("background-color:white;\n"
"border-radius:2px;\n"
"cusor:pointer;"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("C:/Users/wangxi/Desktop/his.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_5->setIcon(icon1);
        pushButton_5->setIconSize(QSize(30, 30));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(410, 510, 141, 31));
        pushButton_3->setStyleSheet(QString::fromUtf8("color:rgb(26, 173, 25);\n"
"font: 12pt \"\351\273\221\344\275\223\" ;\n"
"font-weight:20px;"));
        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(740, 0, 221, 611));
        widget_2->setStyleSheet(QString::fromUtf8("background-color:rgb(70,70,70)"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(765, 111, 63, 21));
        label_2->setStyleSheet(QString::fromUtf8("color:white;\n"
"font: 16pt \"\351\273\221\344\275\223\";\n"
"font-weight:3px"));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(30, 70, 701, 291));
        textEdit->setStyleSheet(QString::fromUtf8("background-color:rgb(245,245,245);\n"
"\n"
"font: 12pt \"\351\273\221\344\275\223\";"));
        ChatWindow->setCentralWidget(centralwidget);
        lineEdit_3->raise();
        widget->raise();
        widget_2->raise();
        listWidget->raise();
        pushButton_2->raise();
        lineEdit->raise();
        pushButton->raise();
        label->raise();
        lineEdit_2->raise();
        pushButton_4->raise();
        label_3->raise();
        pushButton_5->raise();
        pushButton_3->raise();
        label_2->raise();
        textEdit->raise();

        retranslateUi(ChatWindow);

        QMetaObject::connectSlotsByName(ChatWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ChatWindow)
    {
        ChatWindow->setWindowTitle(QCoreApplication::translate("ChatWindow", "MainWindow", nullptr));
        pushButton_2->setText(QCoreApplication::translate("ChatWindow", "\345\217\221\351\200\201", nullptr));
        pushButton->setText(QCoreApplication::translate("ChatWindow", "\351\207\215\346\226\260\350\277\236\346\216\245\346\234\215\345\212\241\345\231\250", nullptr));
        label_5->setText(QCoreApplication::translate("ChatWindow", "\350\275\246\350\275\275\350\201\212\345\244\251\345\256\244", nullptr));
        label->setText(QCoreApplication::translate("ChatWindow", "ip\345\234\260\345\235\200", nullptr));
        pushButton_4->setText(QString());
        label_3->setText(QCoreApplication::translate("ChatWindow", "\345\234\250\347\272\277\344\272\272\346\225\260: ", nullptr));
        pushButton_5->setText(QString());
        pushButton_3->setText(QCoreApplication::translate("ChatWindow", "\350\257\255\351\237\263\350\275\254\346\226\207\345\255\227", nullptr));
        label_2->setText(QCoreApplication::translate("ChatWindow", "\347\253\257\345\217\243\345\217\267", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChatWindow: public Ui_ChatWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATWINDOW_H
