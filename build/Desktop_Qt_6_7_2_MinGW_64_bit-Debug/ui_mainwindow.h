/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFrame *frame_2;
    QPushButton *pushButton_13;
    QPushButton *pushButton;
    QPushButton *pushButton_16;
    QPushButton *pushButton_2;
    QPushButton *pushButton_44;
    QPushButton *pushButton_19;
    QLabel *label_5;
    QWidget *widget;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1061, 600);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color:rgba(32, 33, 44,1);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        frame_2 = new QFrame(centralwidget);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(0, 0, 101, 591));
        frame_2->setStyleSheet(QString::fromUtf8("background-color: rgb(21, 25, 33);"));
        frame_2->setFrameShape(QFrame::Shape::StyledPanel);
        frame_2->setFrameShadow(QFrame::Shadow::Raised);
        frame_2->setLineWidth(0);
        pushButton_13 = new QPushButton(frame_2);
        pushButton_13->setObjectName("pushButton_13");
        pushButton_13->setGeometry(QRect(0, 100, 101, 80));
        pushButton_13->setStyleSheet(QString::fromUtf8("\n"
"QPushButton {\n"
"image: url(:/new/prefix1/map.png);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color:rgb(0, 0, 58);\n"
"}"));
        pushButton = new QPushButton(frame_2);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(0, 300, 101, 80));
        pushButton->setStyleSheet(QString::fromUtf8("\n"
"\n"
"QPushButton {\n"
"image: url(:/new/prefix1/weather.png);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color:rgb(0, 0, 58);\n"
"}"));
        pushButton_16 = new QPushButton(frame_2);
        pushButton_16->setObjectName("pushButton_16");
        pushButton_16->setGeometry(QRect(0, 400, 101, 80));
        pushButton_16->setStyleSheet(QString::fromUtf8("\n"
"\n"
"QPushButton {\n"
"image: url(:/new/prefix1/media.png);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color:rgb(0, 0, 58);\n"
"}"));
        pushButton_2 = new QPushButton(frame_2);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(0, 500, 101, 80));
        pushButton_2->setStyleSheet(QString::fromUtf8("\n"
"\n"
"QPushButton {\n"
"image: url(:/new/prefix1/news.png);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color:rgb(0, 0, 58);\n"
"}"));
        pushButton_44 = new QPushButton(frame_2);
        pushButton_44->setObjectName("pushButton_44");
        pushButton_44->setEnabled(true);
        pushButton_44->setGeometry(QRect(0, 0, 101, 80));
        pushButton_44->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"image: url(:/new/prefix1/home.png);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color:rgb(0, 0, 58);\n"
"}"));
        pushButton_19 = new QPushButton(frame_2);
        pushButton_19->setObjectName("pushButton_19");
        pushButton_19->setGeometry(QRect(0, 200, 101, 80));
        pushButton_19->setStyleSheet(QString::fromUtf8("\n"
"\n"
"\n"
"\n"
"QPushButton:hover {\n"
"	background-color:rgb(0, 0, 58);\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/musicicon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_19->setIcon(icon);
        pushButton_19->setIconSize(QSize(75, 75));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(400, 10, 441, 341));
        label_5->setStyleSheet(QString::fromUtf8("background-color: rgba(21\357\274\21425\357\274\21433\357\274\2141);\n"
"border-radius: 15px;"));
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(101, 0, 960, 600));
        widget->setStyleSheet(QString::fromUtf8("background-color: rgb(240,240,240)"));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton_13->setText(QString());
        pushButton->setText(QString());
        pushButton_16->setText(QString());
        pushButton_2->setText(QString());
        pushButton_44->setText(QString());
        pushButton_19->setText(QString());
        label_5->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
