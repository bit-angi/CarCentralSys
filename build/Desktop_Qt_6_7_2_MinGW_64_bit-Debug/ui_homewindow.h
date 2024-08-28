/********************************************************************************
** Form generated from reading UI file 'homewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOMEWINDOW_H
#define UI_HOMEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HomeWindow
{
public:
    QWidget *centralwidget;
    QFrame *frame;
    QLabel *label_3;
    QLabel *label_15;
    QFrame *frame_5;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_6;
    QFrame *frame_6;
    QLabel *label_19;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    QPushButton *pushButton_13;
    QLabel *label_20;
    QLabel *time_label_2;
    QLabel *day_label_2;
    QLabel *label_7;
    QLabel *label_5;

    void setupUi(QMainWindow *HomeWindow)
    {
        if (HomeWindow->objectName().isEmpty())
            HomeWindow->setObjectName("HomeWindow");
        HomeWindow->resize(960, 600);
        HomeWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 226);"));
        centralwidget = new QWidget(HomeWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setStyleSheet(QString::fromUtf8("background-color:rgb(0, 0, 226);"));
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(0, 20, 221, 491));
        frame->setStyleSheet(QString::fromUtf8("background-color:transparent"));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        label_3 = new QLabel(frame);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 120, 201, 131));
        label_3->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/setting2.png);\n"
"background-color: rgba(255, 255, 255,0);"));
        label_15 = new QLabel(frame);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(10, 230, 201, 131));
        label_15->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/setting1.png);\n"
"background-color: rgba(255, 255, 255,0);"));
        frame_5 = new QFrame(frame);
        frame_5->setObjectName("frame_5");
        frame_5->setGeometry(QRect(30, 140, 211, 62));
        frame_5->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255,0);\n"
"color: rgb(255, 255, 255);"));
        frame_5->setFrameShape(QFrame::Shape::StyledPanel);
        frame_5->setFrameShadow(QFrame::Shadow::Raised);
        label_16 = new QLabel(frame_5);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(50, 0, 61, 31));
        QFont font;
        font.setFamilies({QString::fromUtf8("\351\232\266\344\271\246")});
        font.setPointSize(18);
        label_16->setFont(font);
        label_17 = new QLabel(frame_5);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(0, 30, 54, 10));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("\347\255\211\347\272\277 Light")});
        label_17->setFont(font1);
        label_18 = new QLabel(frame_5);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(0, 50, 33, 12));
        label_6 = new QLabel(frame_5);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(0, 0, 44, 27));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font2.setPointSize(20);
        font2.setBold(false);
        label_6->setFont(font2);
        frame_6 = new QFrame(frame);
        frame_6->setObjectName("frame_6");
        frame_6->setGeometry(QRect(30, 260, 91, 71));
        frame_6->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255,0);\n"
"color: rgb(255, 255, 255);"));
        frame_6->setFrameShape(QFrame::Shape::StyledPanel);
        frame_6->setFrameShadow(QFrame::Shadow::Raised);
        label_19 = new QLabel(frame_6);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(0, 0, 108, 18));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("System")});
        font3.setPointSize(9);
        font3.setBold(true);
        label_19->setFont(font3);
        pushButton_11 = new QPushButton(frame_6);
        pushButton_11->setObjectName("pushButton_11");
        pushButton_11->setGeometry(QRect(30, 40, 21, 20));
        pushButton_11->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/run.png);"));
        pushButton_12 = new QPushButton(frame_6);
        pushButton_12->setObjectName("pushButton_12");
        pushButton_12->setGeometry(QRect(60, 40, 21, 20));
        pushButton_12->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/next.png);"));
        pushButton_13 = new QPushButton(frame_6);
        pushButton_13->setObjectName("pushButton_13");
        pushButton_13->setGeometry(QRect(0, 40, 21, 20));
        pushButton_13->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/last.png);"));
        label_20 = new QLabel(frame);
        label_20->setObjectName("label_20");
        label_20->setGeometry(QRect(120, 260, 50, 50));
        label_20->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/image.png.png);\n"
"background-color: rgba(37, 34, 67,0.8);\n"
"border-radius: 10px;\n"
"box-shadow: -100px -100px 1px rgba(0, 0, 0, 1);\n"
"\n"
""));
        time_label_2 = new QLabel(frame);
        time_label_2->setObjectName("time_label_2");
        time_label_2->setGeometry(QRect(10, 60, 241, 61));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Microsoft YaHei UI")});
        font4.setPointSize(24);
        font4.setBold(true);
        font4.setItalic(false);
        time_label_2->setFont(font4);
        time_label_2->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255,0);\n"
"color: rgb(32, 59, 237);\n"
"font: 700 24pt \"Microsoft YaHei UI\";\n"
""));
        day_label_2 = new QLabel(frame);
        day_label_2->setObjectName("day_label_2");
        day_label_2->setGeometry(QRect(10, 40, 131, 16));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Microsoft YaHei UI")});
        font5.setPointSize(9);
        font5.setBold(false);
        font5.setItalic(false);
        day_label_2->setFont(font5);
        day_label_2->setStyleSheet(QString::fromUtf8("background-color: rgba(21,25,33,0);\n"
"font: 9pt \"Microsoft YaHei UI\";\n"
"color: rgb(32, 59, 237);"));
        label_3->raise();
        label_15->raise();
        frame_5->raise();
        frame_6->raise();
        label_20->raise();
        day_label_2->raise();
        time_label_2->raise();
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(240, 0, 721, 611));
        label_7->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0.505682, y1:0.426, x2:0.511, y2:1, stop:0 rgba(21\357\274\21425\357\274\21433\357\274\2141), stop:1 rgba(32, 33, 44, 0));\n"
"border-radius: 15px;"));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(5, 0, 231, 651));
        label_5->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0.505682, y1:0.426, x2:0.511, y2:1, stop:0 rgba(21\357\274\21425\357\274\21433\357\274\2141), stop:1 rgba(32, 33, 44, 0));\n"
"border-radius: 15px;"));
        HomeWindow->setCentralWidget(centralwidget);
        label_5->raise();
        frame->raise();
        label_7->raise();

        retranslateUi(HomeWindow);

        QMetaObject::connectSlotsByName(HomeWindow);
    } // setupUi

    void retranslateUi(QMainWindow *HomeWindow)
    {
        HomeWindow->setWindowTitle(QCoreApplication::translate("HomeWindow", "MainWindow", nullptr));
        label_3->setText(QString());
        label_15->setText(QString());
        label_16->setText(QCoreApplication::translate("HomeWindow", "<html><head/><body><p><span style=\" font-size:14pt;\">\345\214\227\344\272\254\345\270\202</span></p></body></html>", nullptr));
        label_17->setText(QCoreApplication::translate("HomeWindow", "<html><head/><body><p><span style=\" font-size:6pt;\">\344\273\212\346\227\245\345\244\251\346\260\224\346\231\264\346\234\227</span></p></body></html>", nullptr));
        label_18->setText(QCoreApplication::translate("HomeWindow", "<html><head/><body><p><span style=\" font-size:6pt;\">\346\271\277\345\272\246\342\200\246\342\200\246</span></p></body></html>", nullptr));
        label_6->setText(QCoreApplication::translate("HomeWindow", "<html><head/><body><p><span style=\" font-size:14pt; color:#ffffff;\">21\342\204\203</span></p></body></html>", nullptr));
        label_19->setText(QCoreApplication::translate("HomeWindow", "Fallin' love", nullptr));
        pushButton_11->setText(QString());
        pushButton_12->setText(QString());
        pushButton_13->setText(QString());
        label_20->setText(QString());
        time_label_2->setText(QCoreApplication::translate("HomeWindow", "<html><head/><body><p><span style=\" font-size:36pt; font-weight:700;\">00:00</span></p></body></html>", nullptr));
        day_label_2->setText(QCoreApplication::translate("HomeWindow", "<html><head/><body><p><span style=\" font-size:11pt\">2024-08-20</span></p></body></html>", nullptr));
        label_7->setText(QCoreApplication::translate("HomeWindow", "TextLabel", nullptr));
        label_5->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class HomeWindow: public Ui_HomeWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOMEWINDOW_H
