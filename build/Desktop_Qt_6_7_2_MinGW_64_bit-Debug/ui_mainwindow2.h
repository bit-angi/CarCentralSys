/********************************************************************************
** Form generated from reading UI file 'mainwindow2.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW2_H
#define UI_MAINWINDOW2_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow2
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QWidget *widget_4;
    QLabel *lblDate;
    QPushButton *btnSearch;
    QLineEdit *leCity;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QWidget *widget_10;
    QVBoxLayout *verticalLayout_9;
    QWidget *widget_2;
    QGridLayout *gridLayout;
    QLabel *lblPM25Title;
    QLabel *lblQuality;
    QLabel *lblQualityTitle;
    QLabel *lblShiDuTitle;
    QLabel *lblPM25;
    QLabel *lblWindFx;
    QLabel *lblWindFl;
    QLabel *lblShiDu;
    QLabel *lblGanMao;
    QWidget *widget_11;
    QWidget *widget_5;
    QGridLayout *gridLayout_2;
    QLabel *lblDate0;
    QLabel *lblWeek1;
    QLabel *lblWeek5;
    QLabel *lblDate5;
    QLabel *lblDate2;
    QLabel *lblWeek0;
    QLabel *lblWeek3;
    QLabel *lblWeek4;
    QLabel *lblDate4;
    QLabel *lblDate1;
    QLabel *lblWeek2;
    QLabel *lblDate3;
    QWidget *widget_6;
    QGridLayout *gridLayout_3;
    QLabel *lblType5;
    QLabel *lblTypeIcon3;
    QLabel *lblType1;
    QLabel *lblType2;
    QLabel *lblTypeIcon4;
    QLabel *lblType4;
    QLabel *lblType3;
    QLabel *lblTypeIcon0;
    QLabel *lblTypeIcon5;
    QLabel *lblTypeIcon1;
    QLabel *lblType0;
    QLabel *lblTypeIcon2;
    QWidget *widget_9;
    QHBoxLayout *horizontalLayout_11;
    QLabel *lblQuality0;
    QLabel *lblQuality1;
    QLabel *lblQuality2;
    QLabel *lblQuality3;
    QLabel *lblQuality4;
    QLabel *lblQuality5;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *lblFl0;
    QLabel *lblFl1;
    QLabel *lblFl2;
    QLabel *lblFl3;
    QLabel *lblFl4;
    QLabel *lblFl5;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout_4;
    QLabel *lblFx0;
    QLabel *lblFx1;
    QLabel *lblFx2;
    QLabel *lblFx3;
    QLabel *lblFx4;
    QLabel *lblFx5;
    QLabel *lblTypeIcon;
    QLabel *lblTemp;
    QLabel *lblCity;
    QLabel *lblType;
    QLabel *lblLowHigh;
    QLabel *lblHighCurve;
    QWidget *widget_7;
    QVBoxLayout *verticalLayout_5;
    QLabel *lblLowCurve;
    QGroupBox *groupBox;
    QPushButton *pushButton_3;

    void setupUi(QMainWindow *MainWindow2)
    {
        if (MainWindow2->objectName().isEmpty())
            MainWindow2->setObjectName("MainWindow2");
        MainWindow2->resize(960, 600);
        MainWindow2->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow2);
        centralwidget->setObjectName("centralwidget");
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 0, 960, 600));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        widget->setStyleSheet(QString::fromUtf8("background-color:qlineargradient(spread:reflect, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(85, 170, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
"QLabel {\n"
"	font: 25 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	border-radius: 4px;\n"
"	background-color: rgba(60, 60, 60, 100);\n"
"	color: rgb(255, 255, 255);\n"
"}\n"
"border-radius : 30px"));
        widget_4 = new QWidget(widget);
        widget_4->setObjectName("widget_4");
        widget_4->setGeometry(QRect(-20, 0, 991, 61));
        widget_4->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 170, 255, 255), stop:1 rgba(255, 255, 255, 255))"));
        lblDate = new QLabel(widget_4);
        lblDate->setObjectName("lblDate");
        lblDate->setGeometry(QRect(30, 20, 191, 21));
        lblDate->setStyleSheet(QString::fromUtf8("\n"
"font: 290 16pt \"\345\276\256\350\275\257\351\233\205\351\273\221 Light\";\n"
"color : white;\n"
"font-weight : bold;\n"
"background-color: rgba(255, 255, 255,0);"));
        lblDate->setAlignment(Qt::AlignmentFlag::AlignCenter);
        btnSearch = new QPushButton(widget_4);
        btnSearch->setObjectName("btnSearch");
        btnSearch->setGeometry(QRect(670, 10, 51, 41));
        btnSearch->setStyleSheet(QString::fromUtf8("background-color :rgb(255, 255, 255);\n"
"border-radius : 9px;"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/res/search.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnSearch->setIcon(icon);
        leCity = new QLineEdit(widget_4);
        leCity->setObjectName("leCity");
        leCity->setGeometry(QRect(380, 10, 261, 41));
        sizePolicy.setHeightForWidth(leCity->sizePolicy().hasHeightForWidth());
        leCity->setSizePolicy(sizePolicy);
        leCity->setMinimumSize(QSize(200, 0));
        leCity->setMaximumSize(QSize(300, 16777215));
        leCity->setStyleSheet(QString::fromUtf8("font: 14pt \"Microsoft YaHei UI\";\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius: 9px;\n"
"padding: 1px 5px"));
        pushButton = new QPushButton(widget_4);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(840, 10, 51, 41));
        pushButton->setStyleSheet(QString::fromUtf8("background-color :rgba(255,255,255);\n"
""));
        pushButton_2 = new QPushButton(widget_4);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(910, 10, 51, 41));
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color :rgba(255,255,255,1)\357\274\233\n"
""));
        widget_10 = new QWidget(widget);
        widget_10->setObjectName("widget_10");
        widget_10->setGeometry(QRect(630, 110, 321, 171));
        widget_10->setStyleSheet(QString::fromUtf8("background-color:rgba(138, 253, 255,0.6)"));
        verticalLayout_9 = new QVBoxLayout(widget_10);
        verticalLayout_9->setObjectName("verticalLayout_9");
        widget_2 = new QWidget(widget_10);
        widget_2->setObjectName("widget_2");
        widget_2->setStyleSheet(QString::fromUtf8("background-color: rgba(85, 255, 255, 66);\n"
"border-radius: 15px;"));
        gridLayout = new QGridLayout(widget_2);
        gridLayout->setObjectName("gridLayout");
        lblPM25Title = new QLabel(widget_2);
        lblPM25Title->setObjectName("lblPM25Title");
        sizePolicy.setHeightForWidth(lblPM25Title->sizePolicy().hasHeightForWidth());
        lblPM25Title->setSizePolicy(sizePolicy);
        lblPM25Title->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255,0);\n"
"color:white;\n"
"font: 16pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        lblPM25Title->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(lblPM25Title, 0, 3, 2, 1);

        lblQuality = new QLabel(widget_2);
        lblQuality->setObjectName("lblQuality");
        lblQuality->setAutoFillBackground(false);
        lblQuality->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255,0);\n"
"color:white;\n"
"font: 16pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        lblQuality->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(lblQuality, 1, 1, 2, 1);

        lblQualityTitle = new QLabel(widget_2);
        lblQualityTitle->setObjectName("lblQualityTitle");
        sizePolicy.setHeightForWidth(lblQualityTitle->sizePolicy().hasHeightForWidth());
        lblQualityTitle->setSizePolicy(sizePolicy);
        lblQualityTitle->setAutoFillBackground(false);
        lblQualityTitle->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255,0);\n"
"color:white;\n"
"font: 16pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        lblQualityTitle->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(lblQualityTitle, 0, 1, 1, 1);

        lblShiDuTitle = new QLabel(widget_2);
        lblShiDuTitle->setObjectName("lblShiDuTitle");
        sizePolicy.setHeightForWidth(lblShiDuTitle->sizePolicy().hasHeightForWidth());
        lblShiDuTitle->setSizePolicy(sizePolicy);
        lblShiDuTitle->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255,0);\n"
"color:white;\n"
"font: 16pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        lblShiDuTitle->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(lblShiDuTitle, 0, 2, 2, 1);

        lblPM25 = new QLabel(widget_2);
        lblPM25->setObjectName("lblPM25");
        lblPM25->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255,0);\n"
"color:white;\n"
"font: 16pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        lblPM25->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(lblPM25, 2, 3, 1, 1);

        lblWindFx = new QLabel(widget_2);
        lblWindFx->setObjectName("lblWindFx");
        sizePolicy.setHeightForWidth(lblWindFx->sizePolicy().hasHeightForWidth());
        lblWindFx->setSizePolicy(sizePolicy);
        lblWindFx->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255,0);\n"
"color:white;\n"
"font: 16pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        lblWindFx->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(lblWindFx, 0, 0, 1, 1);

        lblWindFl = new QLabel(widget_2);
        lblWindFl->setObjectName("lblWindFl");
        lblWindFl->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255,0);\n"
"color:white;\n"
"font: 16pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        lblWindFl->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(lblWindFl, 1, 0, 2, 1);

        lblShiDu = new QLabel(widget_2);
        lblShiDu->setObjectName("lblShiDu");
        lblShiDu->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255,0);\n"
"color:white;\n"
"font: 16pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        lblShiDu->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(lblShiDu, 2, 2, 1, 1);


        verticalLayout_9->addWidget(widget_2);

        lblGanMao = new QLabel(widget_10);
        lblGanMao->setObjectName("lblGanMao");
        lblGanMao->setStyleSheet(QString::fromUtf8("background-color: ;\n"
"color:rgba(0,0,0,1);\n"
"font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        lblGanMao->setWordWrap(true);

        verticalLayout_9->addWidget(lblGanMao);

        widget_11 = new QWidget(widget);
        widget_11->setObjectName("widget_11");
        widget_11->setGeometry(QRect(0, 310, 971, 301));
        widget_11->setStyleSheet(QString::fromUtf8("background-color: rgb(0,0,0,1)"));
        widget_5 = new QWidget(widget_11);
        widget_5->setObjectName("widget_5");
        widget_5->setGeometry(QRect(30, 0, 891, 71));
        widget_5->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	background-color: rgba(0, 200, 200, 200);\n"
"	border-radius: 4px;\n"
"}"));
        gridLayout_2 = new QGridLayout(widget_5);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setHorizontalSpacing(6);
        gridLayout_2->setVerticalSpacing(0);
        lblDate0 = new QLabel(widget_5);
        lblDate0->setObjectName("lblDate0");
        lblDate0->setStyleSheet(QString::fromUtf8("border-top-left-radius: 0px;\n"
"border-top-right-radius: 0px;\n"
"color: rgb(240, 240, 240);"));
        lblDate0->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_2->addWidget(lblDate0, 1, 0, 1, 1);

        lblWeek1 = new QLabel(widget_5);
        lblWeek1->setObjectName("lblWeek1");
        lblWeek1->setStyleSheet(QString::fromUtf8("border-bottom-left-radius: 0px;\n"
"border-bottom-right-radius: 0px;"));
        lblWeek1->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_2->addWidget(lblWeek1, 0, 1, 1, 1);

        lblWeek5 = new QLabel(widget_5);
        lblWeek5->setObjectName("lblWeek5");
        lblWeek5->setStyleSheet(QString::fromUtf8("border-bottom-left-radius: 0px;\n"
"border-bottom-right-radius: 0px;"));
        lblWeek5->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_2->addWidget(lblWeek5, 0, 5, 1, 1);

        lblDate5 = new QLabel(widget_5);
        lblDate5->setObjectName("lblDate5");
        lblDate5->setStyleSheet(QString::fromUtf8("border-top-left-radius: 0px;\n"
"border-top-right-radius: 0px;\n"
"color: rgb(240, 240, 240);"));
        lblDate5->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_2->addWidget(lblDate5, 1, 5, 1, 1);

        lblDate2 = new QLabel(widget_5);
        lblDate2->setObjectName("lblDate2");
        lblDate2->setStyleSheet(QString::fromUtf8("border-top-left-radius: 0px;\n"
"border-top-right-radius: 0px;\n"
"color: rgb(240, 240, 240);"));
        lblDate2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_2->addWidget(lblDate2, 1, 2, 1, 1);

        lblWeek0 = new QLabel(widget_5);
        lblWeek0->setObjectName("lblWeek0");
        lblWeek0->setStyleSheet(QString::fromUtf8("border-bottom-left-radius: 0px;\n"
"border-bottom-right-radius: 0px;"));
        lblWeek0->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_2->addWidget(lblWeek0, 0, 0, 1, 1);

        lblWeek3 = new QLabel(widget_5);
        lblWeek3->setObjectName("lblWeek3");
        lblWeek3->setStyleSheet(QString::fromUtf8("border-bottom-left-radius: 0px;\n"
"border-bottom-right-radius: 0px;"));
        lblWeek3->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_2->addWidget(lblWeek3, 0, 3, 1, 1);

        lblWeek4 = new QLabel(widget_5);
        lblWeek4->setObjectName("lblWeek4");
        lblWeek4->setStyleSheet(QString::fromUtf8("border-bottom-left-radius: 0px;\n"
"border-bottom-right-radius: 0px;"));
        lblWeek4->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_2->addWidget(lblWeek4, 0, 4, 1, 1);

        lblDate4 = new QLabel(widget_5);
        lblDate4->setObjectName("lblDate4");
        lblDate4->setStyleSheet(QString::fromUtf8("border-top-left-radius: 0px;\n"
"border-top-right-radius: 0px;\n"
"color: rgb(240, 240, 240);"));
        lblDate4->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_2->addWidget(lblDate4, 1, 4, 1, 1);

        lblDate1 = new QLabel(widget_5);
        lblDate1->setObjectName("lblDate1");
        lblDate1->setStyleSheet(QString::fromUtf8("border-top-left-radius: 0px;\n"
"border-top-right-radius: 0px;\n"
"color: rgb(240, 240, 240);"));
        lblDate1->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_2->addWidget(lblDate1, 1, 1, 1, 1);

        lblWeek2 = new QLabel(widget_5);
        lblWeek2->setObjectName("lblWeek2");
        lblWeek2->setStyleSheet(QString::fromUtf8("border-bottom-left-radius: 0px;\n"
"border-bottom-right-radius: 0px;"));
        lblWeek2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_2->addWidget(lblWeek2, 0, 2, 1, 1);

        lblDate3 = new QLabel(widget_5);
        lblDate3->setObjectName("lblDate3");
        lblDate3->setStyleSheet(QString::fromUtf8("border-top-left-radius: 0px;\n"
"border-top-right-radius: 0px;\n"
"color: rgb(240, 240, 240);"));
        lblDate3->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_2->addWidget(lblDate3, 1, 3, 1, 1);

        widget_6 = new QWidget(widget_11);
        widget_6->setObjectName("widget_6");
        widget_6->setGeometry(QRect(30, 70, 891, 57));
        widget_6->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	background-color: rgba(60, 60, 60, 100);\n"
"	border-radius: 4px;\n"
"}"));
        gridLayout_3 = new QGridLayout(widget_6);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_3->setVerticalSpacing(0);
        gridLayout_3->setContentsMargins(-1, 5, -1, 5);
        lblType5 = new QLabel(widget_6);
        lblType5->setObjectName("lblType5");
        lblType5->setStyleSheet(QString::fromUtf8("border-top-left-radius: 0px;\n"
"border-top-right-radius: 0px;"));
        lblType5->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_3->addWidget(lblType5, 1, 5, 1, 1);

        lblTypeIcon3 = new QLabel(widget_6);
        lblTypeIcon3->setObjectName("lblTypeIcon3");
        lblTypeIcon3->setStyleSheet(QString::fromUtf8("border-bottom-left-radius: 0px;\n"
"border-bottom-right-radius: 0px;"));
        lblTypeIcon3->setPixmap(QPixmap(QString::fromUtf8(":/res/type/DuoYun.png")));
        lblTypeIcon3->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_3->addWidget(lblTypeIcon3, 0, 3, 1, 1);

        lblType1 = new QLabel(widget_6);
        lblType1->setObjectName("lblType1");
        lblType1->setStyleSheet(QString::fromUtf8("border-top-left-radius: 0px;\n"
"border-top-right-radius: 0px;"));
        lblType1->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_3->addWidget(lblType1, 1, 1, 1, 1);

        lblType2 = new QLabel(widget_6);
        lblType2->setObjectName("lblType2");
        lblType2->setStyleSheet(QString::fromUtf8("border-top-left-radius: 0px;\n"
"border-top-right-radius: 0px;"));
        lblType2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_3->addWidget(lblType2, 1, 2, 1, 1);

        lblTypeIcon4 = new QLabel(widget_6);
        lblTypeIcon4->setObjectName("lblTypeIcon4");
        lblTypeIcon4->setStyleSheet(QString::fromUtf8("border-bottom-left-radius: 0px;\n"
"border-bottom-right-radius: 0px;"));
        lblTypeIcon4->setPixmap(QPixmap(QString::fromUtf8(":/res/type/ZhongYu.png")));
        lblTypeIcon4->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_3->addWidget(lblTypeIcon4, 0, 4, 1, 1);

        lblType4 = new QLabel(widget_6);
        lblType4->setObjectName("lblType4");
        lblType4->setStyleSheet(QString::fromUtf8("border-top-left-radius: 0px;\n"
"border-top-right-radius: 0px;"));
        lblType4->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_3->addWidget(lblType4, 1, 4, 1, 1);

        lblType3 = new QLabel(widget_6);
        lblType3->setObjectName("lblType3");
        lblType3->setStyleSheet(QString::fromUtf8("border-top-left-radius: 0px;\n"
"border-top-right-radius: 0px;"));
        lblType3->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_3->addWidget(lblType3, 1, 3, 1, 1);

        lblTypeIcon0 = new QLabel(widget_6);
        lblTypeIcon0->setObjectName("lblTypeIcon0");
        lblTypeIcon0->setMinimumSize(QSize(0, 0));
        lblTypeIcon0->setMaximumSize(QSize(1000, 1000));
        lblTypeIcon0->setStyleSheet(QString::fromUtf8("border-bottom-left-radius: 0px;\n"
"border-bottom-right-radius: 0px;"));
        lblTypeIcon0->setPixmap(QPixmap(QString::fromUtf8(":/res/type/Qing.png")));
        lblTypeIcon0->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_3->addWidget(lblTypeIcon0, 0, 0, 1, 1);

        lblTypeIcon5 = new QLabel(widget_6);
        lblTypeIcon5->setObjectName("lblTypeIcon5");
        lblTypeIcon5->setStyleSheet(QString::fromUtf8("border-bottom-left-radius: 0px;\n"
"border-bottom-right-radius: 0px;"));
        lblTypeIcon5->setPixmap(QPixmap(QString::fromUtf8(":/res/type/BaoYu.png")));
        lblTypeIcon5->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_3->addWidget(lblTypeIcon5, 0, 5, 1, 1);

        lblTypeIcon1 = new QLabel(widget_6);
        lblTypeIcon1->setObjectName("lblTypeIcon1");
        lblTypeIcon1->setStyleSheet(QString::fromUtf8("border-bottom-left-radius: 0px;\n"
"border-bottom-right-radius: 0px;"));
        lblTypeIcon1->setPixmap(QPixmap(QString::fromUtf8(":/res/type/XiaoYu.png")));
        lblTypeIcon1->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_3->addWidget(lblTypeIcon1, 0, 1, 1, 1);

        lblType0 = new QLabel(widget_6);
        lblType0->setObjectName("lblType0");
        lblType0->setStyleSheet(QString::fromUtf8("border-top-left-radius: 0px;\n"
"border-top-right-radius: 0px;"));
        lblType0->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_3->addWidget(lblType0, 1, 0, 1, 1);

        lblTypeIcon2 = new QLabel(widget_6);
        lblTypeIcon2->setObjectName("lblTypeIcon2");
        lblTypeIcon2->setStyleSheet(QString::fromUtf8("border-bottom-left-radius: 0px;\n"
"border-bottom-right-radius: 0px;"));
        lblTypeIcon2->setPixmap(QPixmap(QString::fromUtf8(":/res/type/DuoYun.png")));
        lblTypeIcon2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_3->addWidget(lblTypeIcon2, 0, 2, 1, 1);

        widget_9 = new QWidget(widget_11);
        widget_9->setObjectName("widget_9");
        widget_9->setGeometry(QRect(30, 130, 891, 51));
        horizontalLayout_11 = new QHBoxLayout(widget_9);
        horizontalLayout_11->setObjectName("horizontalLayout_11");
        horizontalLayout_11->setContentsMargins(-1, 5, -1, 5);
        lblQuality0 = new QLabel(widget_9);
        lblQuality0->setObjectName("lblQuality0");
        lblQuality0->setStyleSheet(QString::fromUtf8("background-color: rgb(121, 184, 0);\n"
"padding:8px;"));
        lblQuality0->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_11->addWidget(lblQuality0);

        lblQuality1 = new QLabel(widget_9);
        lblQuality1->setObjectName("lblQuality1");
        lblQuality1->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 187, 23);"));
        lblQuality1->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_11->addWidget(lblQuality1);

        lblQuality2 = new QLabel(widget_9);
        lblQuality2->setObjectName("lblQuality2");
        lblQuality2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 87, 97);"));
        lblQuality2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_11->addWidget(lblQuality2);

        lblQuality3 = new QLabel(widget_9);
        lblQuality3->setObjectName("lblQuality3");
        lblQuality3->setStyleSheet(QString::fromUtf8("background-color: rgb(235, 17, 27);"));
        lblQuality3->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_11->addWidget(lblQuality3);

        lblQuality4 = new QLabel(widget_9);
        lblQuality4->setObjectName("lblQuality4");
        lblQuality4->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 0, 0);"));
        lblQuality4->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_11->addWidget(lblQuality4);

        lblQuality5 = new QLabel(widget_9);
        lblQuality5->setObjectName("lblQuality5");
        lblQuality5->setStyleSheet(QString::fromUtf8("background-color: rgb(110, 0, 0);"));
        lblQuality5->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_11->addWidget(lblQuality5);

        layoutWidget = new QWidget(widget_11);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(40, 240, 881, 41));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        lblFl0 = new QLabel(layoutWidget);
        lblFl0->setObjectName("lblFl0");
        lblFl0->setStyleSheet(QString::fromUtf8("border-top-left-radius: 0px;\n"
"border-top-right-radius: 0px;\n"
"color: rgb(255, 255, 255);\n"
"font-weight:bold;\n"
"font-size:25px;\n"
"background-color:rgba(0, 0, 235,0.2)"));
        lblFl0->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(lblFl0);

        lblFl1 = new QLabel(layoutWidget);
        lblFl1->setObjectName("lblFl1");
        lblFl1->setStyleSheet(QString::fromUtf8("border-top-left-radius: 0px;\n"
"border-top-right-radius: 0px;\n"
"color: rgb(255, 255, 255);\n"
"font-weight:bold;\n"
"background-color:rgba(0, 0, 235,0.2);\n"
"font-size:25px;"));
        lblFl1->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(lblFl1);

        lblFl2 = new QLabel(layoutWidget);
        lblFl2->setObjectName("lblFl2");
        lblFl2->setStyleSheet(QString::fromUtf8("border-top-left-radius: 0px;\n"
"border-top-right-radius: 0px;\n"
"color: rgb(255, 255, 255);\n"
"font-weight:bold;\n"
"font-size:25px;\n"
"background-color:rgba(0, 0, 235,0.2)"));
        lblFl2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(lblFl2);

        lblFl3 = new QLabel(layoutWidget);
        lblFl3->setObjectName("lblFl3");
        lblFl3->setStyleSheet(QString::fromUtf8("border-top-left-radius: 0px;\n"
"border-top-right-radius: 0px;\n"
"color: rgb(255, 255, 255);\n"
"font-weight:bold;\n"
"font-size:25px;\n"
"background-color:rgba(0, 0, 235,0.2)"));
        lblFl3->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(lblFl3);

        lblFl4 = new QLabel(layoutWidget);
        lblFl4->setObjectName("lblFl4");
        lblFl4->setStyleSheet(QString::fromUtf8("border-top-left-radius: 0px;\n"
"border-top-right-radius: 0px;\n"
"color: rgb(255, 255, 255);\n"
"font-weight:bold;\n"
"font-size:25px;\n"
"background-color:rgba(0, 0, 235,0.2)"));
        lblFl4->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(lblFl4);

        lblFl5 = new QLabel(layoutWidget);
        lblFl5->setObjectName("lblFl5");
        lblFl5->setStyleSheet(QString::fromUtf8("border-top-left-radius: 0px;\n"
"border-top-right-radius: 0px;\n"
"color: rgb(255, 255, 255);\n"
"font-weight:bold;\n"
"font-size:25px;\n"
"background-color:rgba(0, 0, 235,0.2)"));
        lblFl5->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(lblFl5);

        layoutWidget1 = new QWidget(widget_11);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(40, 190, 881, 41));
        gridLayout_4 = new QGridLayout(layoutWidget1);
        gridLayout_4->setObjectName("gridLayout_4");
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        lblFx0 = new QLabel(layoutWidget1);
        lblFx0->setObjectName("lblFx0");
        lblFx0->setStyleSheet(QString::fromUtf8("border-bottom-left-radius: 0px;\n"
"border-bottom-right-radius: 0px;\n"
"background-color : rgba(0, 170, 255,0.2);\n"
"color:white;\n"
"font-weight:bold;\n"
"font-size:30px"));
        lblFx0->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_4->addWidget(lblFx0, 0, 0, 1, 1);

        lblFx1 = new QLabel(layoutWidget1);
        lblFx1->setObjectName("lblFx1");
        lblFx1->setStyleSheet(QString::fromUtf8("border-bottom-left-radius: 0px;\n"
"border-bottom-right-radius: 0px;\n"
"background-color : rgba(0, 170, 255,0.2);\n"
"color:white;\n"
"font-weight:bold;\n"
"font-size:30px"));
        lblFx1->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_4->addWidget(lblFx1, 0, 1, 1, 1);

        lblFx2 = new QLabel(layoutWidget1);
        lblFx2->setObjectName("lblFx2");
        lblFx2->setStyleSheet(QString::fromUtf8("border-bottom-left-radius: 0px;\n"
"border-bottom-right-radius: 0px;\n"
"background-color : rgba(0, 170, 255,0.2);\n"
"color:white;\n"
"font-weight:bold;\n"
"font-size:30px"));
        lblFx2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_4->addWidget(lblFx2, 0, 2, 1, 1);

        lblFx3 = new QLabel(layoutWidget1);
        lblFx3->setObjectName("lblFx3");
        lblFx3->setStyleSheet(QString::fromUtf8("border-bottom-left-radius: 0px;\n"
"border-bottom-right-radius: 0px;\n"
"background-color : rgba(0, 170, 255,0.2);\n"
"color:white;\n"
"font-weight:bold;\n"
"font-size:30px"));
        lblFx3->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_4->addWidget(lblFx3, 0, 3, 1, 1);

        lblFx4 = new QLabel(layoutWidget1);
        lblFx4->setObjectName("lblFx4");
        lblFx4->setStyleSheet(QString::fromUtf8("border-bottom-left-radius: 0px;\n"
"border-bottom-right-radius: 0px;\n"
"background-color : rgba(0, 170, 255,0.2);\n"
"color:white;\n"
"font-weight:bold;\n"
"font-size:30px"));
        lblFx4->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_4->addWidget(lblFx4, 0, 4, 1, 1);

        lblFx5 = new QLabel(layoutWidget1);
        lblFx5->setObjectName("lblFx5");
        lblFx5->setStyleSheet(QString::fromUtf8("border-bottom-left-radius: 0px;\n"
"border-bottom-right-radius: 0px;\n"
"background-color : rgba(0, 170, 255,0.2);\n"
"color:white;\n"
"font-weight:bold;\n"
"font-size:30px"));
        lblFx5->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_4->addWidget(lblFx5, 0, 5, 1, 1);

        lblTypeIcon = new QLabel(widget);
        lblTypeIcon->setObjectName("lblTypeIcon");
        lblTypeIcon->setGeometry(QRect(290, 130, 110, 110));
        lblTypeIcon->setMinimumSize(QSize(110, 110));
        lblTypeIcon->setMaximumSize(QSize(110, 110));
        lblTypeIcon->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        lblTypeIcon->setPixmap(QPixmap(QString::fromUtf8(":/res/type/DuoYun.png")));
        lblTypeIcon->setScaledContents(true);
        lblTypeIcon->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lblTemp = new QLabel(widget);
        lblTemp->setObjectName("lblTemp");
        lblTemp->setGeometry(QRect(350, 160, 331, 56));
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setPointSize(50);
        font.setBold(false);
        font.setItalic(false);
        lblTemp->setFont(font);
        lblTemp->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 50pt \"Arial\";\n"
"background-color: rgba(0, 255, 255, 0);"));
        lblTemp->setScaledContents(true);
        lblTemp->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lblCity = new QLabel(widget);
        lblCity->setObjectName("lblCity");
        lblCity->setGeometry(QRect(0, 160, 281, 91));
        lblCity->setStyleSheet(QString::fromUtf8("font: 50pt \"Microsoft YaHei UI\";\n"
"color:white;\n"
"font-weight : bold;\n"
"background-color: rgba(255, 255, 255,0);"));
        lblCity->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        lblType = new QLabel(widget);
        lblType->setObjectName("lblType");
        lblType->setGeometry(QRect(310, 240, 121, 41));
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lblType->sizePolicy().hasHeightForWidth());
        lblType->setSizePolicy(sizePolicy1);
        lblType->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255,0);\n"
"font: 18pt \"Microsoft YaHei UI\";\n"
"color:white;\n"
"font-weight : bold;"));
        lblType->setScaledContents(true);
        lblType->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        lblLowHigh = new QLabel(widget);
        lblLowHigh->setObjectName("lblLowHigh");
        lblLowHigh->setGeometry(QRect(470, 250, 151, 23));
        lblLowHigh->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255,0);\n"
"font: 18pt \"Microsoft YaHei UI\";\n"
"color:white;\n"
"font-weight : bold;"));
        lblLowHigh->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        lblHighCurve = new QLabel(widget);
        lblHighCurve->setObjectName("lblHighCurve");
        lblHighCurve->setGeometry(QRect(100, 500, 5, 80));
        lblHighCurve->setMinimumSize(QSize(0, 80));
        lblHighCurve->setMaximumSize(QSize(10000, 10000));
        lblHighCurve->setStyleSheet(QString::fromUtf8("background-color: rgb(0,0,0,1)"));
        lblHighCurve->setAlignment(Qt::AlignmentFlag::AlignCenter);
        widget_7 = new QWidget(widget);
        widget_7->setObjectName("widget_7");
        widget_7->setGeometry(QRect(550, 490, 17, 170));
        widget_7->setStyleSheet(QString::fromUtf8("background-color: rgb(0,0,0,1);"));
        verticalLayout_5 = new QVBoxLayout(widget_7);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(-1, 5, -1, 5);
        lblLowCurve = new QLabel(widget);
        lblLowCurve->setObjectName("lblLowCurve");
        lblLowCurve->setGeometry(QRect(120, 510, 16, 80));
        lblLowCurve->setMinimumSize(QSize(0, 80));
        lblLowCurve->setMaximumSize(QSize(10000, 10000));
        lblLowCurve->setStyleSheet(QString::fromUtf8("display : none;\n"
"background-color: rgb(0,0,0,1)"));
        lblLowCurve->setAlignment(Qt::AlignmentFlag::AlignCenter);
        groupBox = new QGroupBox(widget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(10, 290, 941, 341));
        groupBox->setStyleSheet(QString::fromUtf8("background-color: rgba(255,255,255,.5);\n"
"border-radius:30px;"));
        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(80, 90, 71, 61));
        pushButton_3->setStyleSheet(QString::fromUtf8("border-radius:30px;\n"
"background-color:rgba(255,255,255,0.8)"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/res/mic.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_3->setIcon(icon1);
        pushButton_3->setIconSize(QSize(25, 25));
        groupBox->raise();
        widget_4->raise();
        widget_10->raise();
        widget_11->raise();
        lblTypeIcon->raise();
        lblTemp->raise();
        lblCity->raise();
        lblType->raise();
        lblLowHigh->raise();
        lblHighCurve->raise();
        widget_7->raise();
        lblLowCurve->raise();
        pushButton_3->raise();
        MainWindow2->setCentralWidget(centralwidget);

        retranslateUi(MainWindow2);

        QMetaObject::connectSlotsByName(MainWindow2);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow2)
    {
        MainWindow2->setWindowTitle(QCoreApplication::translate("MainWindow2", "MainWindow", nullptr));
        lblDate->setText(QCoreApplication::translate("MainWindow2", "2022/08/15 \346\230\237\346\234\237\345\233\233", nullptr));
        btnSearch->setText(QString());
        leCity->setPlaceholderText(QCoreApplication::translate("MainWindow2", "\345\237\216\345\270\202", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow2", "\346\234\200\345\260\217\345\214\226", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow2", "\351\200\200\345\207\272", nullptr));
        lblPM25Title->setText(QCoreApplication::translate("MainWindow2", "PM2.5", nullptr));
        lblQuality->setText(QCoreApplication::translate("MainWindow2", "\344\274\230", nullptr));
        lblQualityTitle->setText(QCoreApplication::translate("MainWindow2", "\347\251\272\346\260\224\350\264\250\351\207\217", nullptr));
        lblShiDuTitle->setText(QCoreApplication::translate("MainWindow2", "\346\271\277\345\272\246", nullptr));
        lblPM25->setText(QCoreApplication::translate("MainWindow2", "10", nullptr));
        lblWindFx->setText(QCoreApplication::translate("MainWindow2", "\350\245\277\345\214\227\351\243\216", nullptr));
        lblWindFl->setText(QCoreApplication::translate("MainWindow2", "3\347\272\247", nullptr));
        lblShiDu->setText(QCoreApplication::translate("MainWindow2", "60%", nullptr));
        lblGanMao->setText(QCoreApplication::translate("MainWindow2", "\346\204\237\345\206\222\346\214\207\346\225\260\357\274\232\345\204\277\347\253\245\343\200\201\350\200\201\345\271\264\344\272\272\345\217\212\345\277\203\350\204\217\343\200\201\345\221\274\345\220\270\347\263\273\347\273\237\347\226\276\347\227\205\346\202\243\350\200\205\344\272\272\347\276\244\345\272\224\345\207\217\345\260\221\351\225\277\346\227\266\351\227\264\346\210\226\351\253\230\345\274\272\345\272\246\346\210\267\345\244\226\351\224\273\347\202\274", nullptr));
        lblDate0->setText(QCoreApplication::translate("MainWindow2", "01/01", nullptr));
        lblWeek1->setText(QCoreApplication::translate("MainWindow2", "\344\273\212\345\244\251", nullptr));
        lblWeek5->setText(QCoreApplication::translate("MainWindow2", "\345\221\250\345\205\255", nullptr));
        lblDate5->setText(QCoreApplication::translate("MainWindow2", "01/06", nullptr));
        lblDate2->setText(QCoreApplication::translate("MainWindow2", "01/03", nullptr));
        lblWeek0->setText(QCoreApplication::translate("MainWindow2", "\346\230\250\345\244\251", nullptr));
        lblWeek3->setText(QCoreApplication::translate("MainWindow2", "\345\221\250\345\233\233", nullptr));
        lblWeek4->setText(QCoreApplication::translate("MainWindow2", "\345\221\250\344\272\224", nullptr));
        lblDate4->setText(QCoreApplication::translate("MainWindow2", "01/05", nullptr));
        lblDate1->setText(QCoreApplication::translate("MainWindow2", "01/02", nullptr));
        lblWeek2->setText(QCoreApplication::translate("MainWindow2", "\346\230\216\345\244\251", nullptr));
        lblDate3->setText(QCoreApplication::translate("MainWindow2", "01/04", nullptr));
        lblType5->setText(QCoreApplication::translate("MainWindow2", "\346\232\264\351\233\250", nullptr));
        lblTypeIcon3->setText(QString());
        lblType1->setText(QCoreApplication::translate("MainWindow2", "\345\260\217\351\233\250", nullptr));
        lblType2->setText(QCoreApplication::translate("MainWindow2", "\345\244\232\344\272\221", nullptr));
        lblTypeIcon4->setText(QString());
        lblType4->setText(QCoreApplication::translate("MainWindow2", "\344\270\255\351\233\250", nullptr));
        lblType3->setText(QCoreApplication::translate("MainWindow2", "\345\244\232\344\272\221", nullptr));
        lblTypeIcon0->setText(QString());
        lblTypeIcon5->setText(QString());
        lblTypeIcon1->setText(QString());
        lblType0->setText(QCoreApplication::translate("MainWindow2", "\346\231\264", nullptr));
        lblTypeIcon2->setText(QString());
        lblQuality0->setText(QCoreApplication::translate("MainWindow2", "\344\274\230", nullptr));
        lblQuality1->setText(QCoreApplication::translate("MainWindow2", "\350\211\257", nullptr));
        lblQuality2->setText(QCoreApplication::translate("MainWindow2", "\350\275\273\345\272\246", nullptr));
        lblQuality3->setText(QCoreApplication::translate("MainWindow2", "\344\270\255\345\272\246", nullptr));
        lblQuality4->setText(QCoreApplication::translate("MainWindow2", "\351\207\215\345\272\246", nullptr));
        lblQuality5->setText(QCoreApplication::translate("MainWindow2", "\344\270\245\351\207\215", nullptr));
        lblFl0->setText(QCoreApplication::translate("MainWindow2", "2\347\272\247", nullptr));
        lblFl1->setText(QCoreApplication::translate("MainWindow2", "3\347\272\247", nullptr));
        lblFl2->setText(QCoreApplication::translate("MainWindow2", "2\347\272\247", nullptr));
        lblFl3->setText(QCoreApplication::translate("MainWindow2", "1\347\272\247", nullptr));
        lblFl4->setText(QCoreApplication::translate("MainWindow2", "2\347\272\247", nullptr));
        lblFl5->setText(QCoreApplication::translate("MainWindow2", "2\347\272\247", nullptr));
        lblFx0->setText(QCoreApplication::translate("MainWindow2", "\344\270\234\351\243\216", nullptr));
        lblFx1->setText(QCoreApplication::translate("MainWindow2", "\344\270\234\345\214\227\351\243\216", nullptr));
        lblFx2->setText(QCoreApplication::translate("MainWindow2", "\350\245\277\345\214\227\351\243\216", nullptr));
        lblFx3->setText(QCoreApplication::translate("MainWindow2", "\350\245\277\345\214\227\351\243\216", nullptr));
        lblFx4->setText(QCoreApplication::translate("MainWindow2", "\344\270\234\345\215\227\351\243\216", nullptr));
        lblFx5->setText(QCoreApplication::translate("MainWindow2", "\350\245\277\351\243\216", nullptr));
        lblTypeIcon->setText(QString());
        lblTemp->setText(QCoreApplication::translate("MainWindow2", "32\302\260", nullptr));
        lblCity->setText(QCoreApplication::translate("MainWindow2", "\345\214\227\344\272\254", nullptr));
        lblType->setText(QCoreApplication::translate("MainWindow2", "\346\231\264\350\275\254\345\244\232\344\272\221", nullptr));
        lblLowHigh->setText(QCoreApplication::translate("MainWindow2", "19\302\260~31\302\260", nullptr));
        lblHighCurve->setText(QString());
        lblLowCurve->setText(QString());
        groupBox->setTitle(QString());
        pushButton_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow2: public Ui_MainWindow2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW2_H
