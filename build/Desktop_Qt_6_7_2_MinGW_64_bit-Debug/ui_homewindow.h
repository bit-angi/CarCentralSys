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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HomeWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton_7;
    QFrame *frame;
    QLabel *label_4;
    QLabel *label_2;
    QLabel *label_9;
    QFrame *frame_3;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *time_label;
    QLabel *day_label;
    QLabel *label_14;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_10;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_8;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_9;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QWidget *pic_widget;

    void setupUi(QMainWindow *HomeWindow)
    {
        if (HomeWindow->objectName().isEmpty())
            HomeWindow->setObjectName("HomeWindow");
        HomeWindow->resize(960, 600);
        HomeWindow->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255,0);"));
        centralwidget = new QWidget(HomeWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setStyleSheet(QString::fromUtf8("background-color:rgba(0, 0, 226,0);"));
        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(930, 0, 30, 31));
        pushButton_7->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/tools.png);"));
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(30, 30, 311, 541));
        frame->setStyleSheet(QString::fromUtf8(""));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        label_4 = new QLabel(frame);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(0, 0, 311, 651));
        label_4->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0.505682, y1:0.426, x2:0.511, y2:1, stop:0 rgba(21\357\274\21425\357\274\21433\357\274\2141), stop:0.744318 rgba(32, 33, 44, 0));\n"
"border-radius: 15px;"));
        label_2 = new QLabel(frame);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 170, 291, 191));
        label_2->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/setting2.png);\n"
"background-color: rgba(255, 255, 255,0);"));
        label_9 = new QLabel(frame);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(10, 340, 291, 181));
        label_9->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/setting1.png);\n"
"background-color: rgba(255, 255, 255,0);"));
        frame_3 = new QFrame(frame);
        frame_3->setObjectName("frame_3");
        frame_3->setGeometry(QRect(30, 200, 251, 121));
        frame_3->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255,0);\n"
"color: rgb(255, 255, 255);"));
        frame_3->setFrameShape(QFrame::Shape::StyledPanel);
        frame_3->setFrameShadow(QFrame::Shadow::Raised);
        label_10 = new QLabel(frame_3);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(80, 0, 91, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("\351\232\266\344\271\246")});
        font.setPointSize(18);
        label_10->setFont(font);
        label_11 = new QLabel(frame_3);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(0, 50, 131, 21));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("\347\255\211\347\272\277 Light")});
        label_11->setFont(font1);
        label = new QLabel(frame_3);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 71, 41));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font2.setPointSize(20);
        font2.setBold(false);
        label->setFont(font2);
        label_12 = new QLabel(frame_3);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(0, 80, 101, 31));
        label_13 = new QLabel(frame);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(180, 380, 61, 61));
        label_13->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/image.png.png);\n"
"background-color: rgba(37, 34, 67,0.8);\n"
"border-radius: 10px;\n"
"box-shadow: -100px -100px 1px rgba(0, 0, 0, 1);\n"
"\n"
""));
        time_label = new QLabel(frame);
        time_label->setObjectName("time_label");
        time_label->setGeometry(QRect(10, 70, 291, 101));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Microsoft YaHei UI")});
        font3.setPointSize(24);
        font3.setBold(true);
        font3.setItalic(false);
        time_label->setFont(font3);
        time_label->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255,0);\n"
"color: rgb(32, 59, 237);\n"
"font: 700 24pt \"Microsoft YaHei UI\";\n"
""));
        day_label = new QLabel(frame);
        day_label->setObjectName("day_label");
        day_label->setGeometry(QRect(20, 20, 131, 16));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Microsoft YaHei UI")});
        font4.setPointSize(9);
        font4.setBold(false);
        font4.setItalic(false);
        day_label->setFont(font4);
        day_label->setStyleSheet(QString::fromUtf8("background-color: rgba(21,25,33,0);\n"
"font: 9pt \"Microsoft YaHei UI\";\n"
"color: rgb(32, 59, 237);"));
        label_14 = new QLabel(frame);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(30, 370, 151, 51));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("System")});
        font5.setPointSize(9);
        font5.setBold(true);
        label_14->setFont(font5);
        label_14->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        horizontalLayoutWidget = new QWidget(frame);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(30, 430, 111, 41));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_10 = new QPushButton(horizontalLayoutWidget);
        pushButton_10->setObjectName("pushButton_10");
        pushButton_10->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/last.png);"));

        horizontalLayout->addWidget(pushButton_10);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        pushButton_8 = new QPushButton(horizontalLayoutWidget);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/run.png);"));

        horizontalLayout->addWidget(pushButton_8);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_9 = new QPushButton(horizontalLayoutWidget);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/next.png);"));

        horizontalLayout->addWidget(pushButton_9);

        label_4->raise();
        label_9->raise();
        label_2->raise();
        frame_3->raise();
        label_13->raise();
        time_label->raise();
        day_label->raise();
        label_14->raise();
        horizontalLayoutWidget->raise();
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(390, 30, 541, 381));
        label_5->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0.505682, y1:0.426, x2:0.511, y2:1, stop:0 rgba(21\357\274\21425\357\274\21433\357\274\2141), stop:0.744318 rgba(32, 33, 44, 0));\n"
"border-radius: 15px;"));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(10, 10, 40, 12));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(-160, -100, 1200, 700));
        label_7->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/images/star.jpg);"));
        pic_widget = new QWidget(centralwidget);
        pic_widget->setObjectName("pic_widget");
        pic_widget->setGeometry(QRect(410, 50, 501, 400));
        pic_widget->setStyleSheet(QString::fromUtf8("background-color: transparent"));
        HomeWindow->setCentralWidget(centralwidget);
        label_7->raise();
        pushButton_7->raise();
        frame->raise();
        label_5->raise();
        label_6->raise();
        pic_widget->raise();

        retranslateUi(HomeWindow);

        QMetaObject::connectSlotsByName(HomeWindow);
    } // setupUi

    void retranslateUi(QMainWindow *HomeWindow)
    {
        HomeWindow->setWindowTitle(QCoreApplication::translate("HomeWindow", "MainWindow", nullptr));
        pushButton_7->setText(QString());
        label_4->setText(QString());
        label_2->setText(QString());
        label_9->setText(QString());
        label_10->setText(QCoreApplication::translate("HomeWindow", "<html><head/><body><p><span style=\" font-size:22pt;\">\345\214\227\344\272\254\345\270\202</span></p></body></html>", nullptr));
        label_11->setText(QCoreApplication::translate("HomeWindow", "<html><head/><body><p><span style=\" font-size:10pt;\">\344\273\212\346\227\245\345\244\251\346\260\224\346\231\264\346\234\227</span></p></body></html>", nullptr));
        label->setText(QCoreApplication::translate("HomeWindow", "<html><head/><body><p><span style=\" font-size:24pt; color:#ffffff;\">21\342\204\203</span></p></body></html>", nullptr));
        label_12->setText(QCoreApplication::translate("HomeWindow", "<html><head/><body><p>\346\271\277\345\272\246\342\200\246\342\200\246</p></body></html>", nullptr));
        label_13->setText(QString());
        time_label->setText(QCoreApplication::translate("HomeWindow", "<html><head/><body><p><span style=\" font-size:48pt;\">00:00</span></p></body></html>", nullptr));
        day_label->setText(QCoreApplication::translate("HomeWindow", "<html><head/><body><p><span style=\" font-size:14pt;\">2024-08-20</span></p></body></html>", nullptr));
        label_14->setText(QCoreApplication::translate("HomeWindow", "<html><head/><body><p><span style=\" font-size:18pt;\">Fallin' love</span></p></body></html>", nullptr));
        pushButton_10->setText(QString());
        pushButton_8->setText(QString());
        pushButton_9->setText(QString());
        label_5->setText(QString());
        label_6->setText(QCoreApplication::translate("HomeWindow", "TextLabel", nullptr));
        label_7->setText(QCoreApplication::translate("HomeWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HomeWindow: public Ui_HomeWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOMEWINDOW_H
