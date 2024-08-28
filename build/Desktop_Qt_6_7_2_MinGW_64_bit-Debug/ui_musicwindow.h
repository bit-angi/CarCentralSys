/********************************************************************************
** Form generated from reading UI file 'musicwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MUSICWINDOW_H
#define UI_MUSICWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MusicWindow
{
public:
    QWidget *centralwidget;
    QPushButton *btnAdd;
    QPushButton *love_button;
    QGroupBox *groupBox_5;
    QHBoxLayout *horizontalLayout;
    QSlider *sliderPosition;
    QLabel *labRatio;
    QGroupBox *groupBox;
    QLabel *label;
    QListWidget *listWidget;
    QPushButton *btnRemove;
    QListWidget *listWidget_2;
    QPushButton *btnClear;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QLabel *labPic;
    QFrame *frame;
    QGroupBox *groupBoxCover;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *btnCover;
    QLabel *labCurMedia;
    QGroupBox *groupBox_2;
    QPushButton *btnPlay;
    QPushButton *btnPause;
    QPushButton *btnStop;
    QPushButton *btnPrevious;
    QPushButton *btnNext;
    QGroupBox *groupBox_3;
    QDoubleSpinBox *doubleSpinBox;
    QPushButton *btnLoop;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btnSound;
    QSlider *sliderVolumn;

    void setupUi(QMainWindow *MusicWindow)
    {
        if (MusicWindow->objectName().isEmpty())
            MusicWindow->setObjectName("MusicWindow");
        MusicWindow->resize(960, 600);
        centralwidget = new QWidget(MusicWindow);
        centralwidget->setObjectName("centralwidget");
        btnAdd = new QPushButton(centralwidget);
        btnAdd->setObjectName("btnAdd");
        btnAdd->setGeometry(QRect(11, 78, 71, 41));
        btnAdd->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"font-size: 16px;\n"
"color:rgb(43, 43, 43)\n"
"}\n"
"\n"
""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/images/316.bmp"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnAdd->setIcon(icon);
        love_button = new QPushButton(centralwidget);
        love_button->setObjectName("love_button");
        love_button->setGeometry(QRect(830, 80, 80, 31));
        love_button->setStyleSheet(QString::fromUtf8("font: 290 14pt \"Microsoft YaHei UI Light\";"));
        groupBox_5 = new QGroupBox(centralwidget);
        groupBox_5->setObjectName("groupBox_5");
        groupBox_5->setGeometry(QRect(10, 440, 941, 51));
        groupBox_5->setMaximumSize(QSize(16777215, 60));
        groupBox_5->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal {\n"
"    border: 1px solid #999999;\n"
"    height: 8px;\n"
"    background: #B0E0E6; /* \350\275\250\351\201\223\350\203\214\346\231\257\351\242\234\350\211\262\357\274\214\346\267\241\350\223\235\350\211\262 */\n"
"    margin: 2px 0;\n"
"}\n"
"\n"
"QSlider::handle:horizontal {\n"
"    background: #FFFFFF; /* \346\273\221\345\235\227\351\242\234\350\211\262\357\274\214\347\231\275\350\211\262 */\n"
"    border: 1px solid #5c5c5c;\n"
"    width: 18px;\n"
"    margin: -2px 0;\n"
"    border-radius: 3px;\n"
"}\n"
"\n"
"QSlider::add-page:horizontal {\n"
"    background: #E0FFFF; /* \346\273\221\345\235\227\345\217\263\344\276\247\351\242\234\350\211\262\357\274\214\346\233\264\346\267\241\347\232\204\350\223\235\350\211\262 */\n"
"}\n"
"\n"
"QSlider::sub-page:horizontal {\n"
"    background: #87CEFA; /* \346\273\221\345\235\227\345\267\246\344\276\247\351\242\234\350\211\262\357\274\214\346\265\205\345\244\251\350\223\235\350\211\262 */\n"
"}\n"
""));
        horizontalLayout = new QHBoxLayout(groupBox_5);
        horizontalLayout->setObjectName("horizontalLayout");
        sliderPosition = new QSlider(groupBox_5);
        sliderPosition->setObjectName("sliderPosition");
        sliderPosition->setTracking(false);
        sliderPosition->setOrientation(Qt::Orientation::Horizontal);

        horizontalLayout->addWidget(sliderPosition);

        labRatio = new QLabel(groupBox_5);
        labRatio->setObjectName("labRatio");
        labRatio->setMinimumSize(QSize(80, 0));
        labRatio->setStyleSheet(QString::fromUtf8(" font-family: \"Courier New\";\n"
"    font-size: 10pt;\n"
"    font-weight: bold;\n"
"font: 18pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
" text-align: center;"));

        horizontalLayout->addWidget(labRatio);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(0, 0, 961, 61));
        groupBox->setMaximumSize(QSize(16777215, 70));
        groupBox->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 170, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
"\n"
"\n"
"\n"
"\n"
"border:none;\n"
"\n"
""));
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(39, 13, 41, 41));
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(10, 130, 231, 291));
        listWidget->setStyleSheet(QString::fromUtf8("font-size: 16px;"));
        listWidget->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);
        listWidget->setDragEnabled(true);
        listWidget->setDragDropMode(QAbstractItemView::DragDropMode::InternalMove);
        btnRemove = new QPushButton(centralwidget);
        btnRemove->setObjectName("btnRemove");
        btnRemove->setGeometry(QRect(95, 78, 61, 41));
        btnRemove->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"\n"
"font-size: 16px;\n"
"color:rgb(43, 43, 43)\n"
"}\n"
""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/images/318.bmp"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnRemove->setIcon(icon1);
        listWidget_2 = new QListWidget(centralwidget);
        listWidget_2->setObjectName("listWidget_2");
        listWidget_2->setGeometry(QRect(770, 130, 181, 291));
        btnClear = new QPushButton(centralwidget);
        btnClear->setObjectName("btnClear");
        btnClear->setGeometry(QRect(174, 78, 71, 41));
        btnClear->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"\n"
"font-size: 16px;\n"
"color:rgb(43, 43, 43)\n"
"}\n"
""));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/images/214.bmp"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnClear->setIcon(icon2);
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(259, 69, 491, 351));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 489, 349));
        labPic = new QLabel(scrollAreaWidgetContents);
        labPic->setObjectName("labPic");
        labPic->setGeometry(QRect(0, 0, 721, 351));
        scrollArea->setWidget(scrollAreaWidgetContents);
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(20, 500, 931, 81));
        frame->setMaximumSize(QSize(16777215, 90));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        groupBoxCover = new QGroupBox(frame);
        groupBoxCover->setObjectName("groupBoxCover");
        groupBoxCover->setGeometry(QRect(10, 10, 181, 61));
        horizontalLayout_6 = new QHBoxLayout(groupBoxCover);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        btnCover = new QPushButton(groupBoxCover);
        btnCover->setObjectName("btnCover");
        btnCover->setMinimumSize(QSize(40, 40));
        btnCover->setMaximumSize(QSize(50, 50));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/images/music24.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnCover->setIcon(icon3);

        horizontalLayout_6->addWidget(btnCover);

        labCurMedia = new QLabel(groupBoxCover);
        labCurMedia->setObjectName("labCurMedia");
        labCurMedia->setMinimumSize(QSize(100, 0));
        labCurMedia->setStyleSheet(QString::fromUtf8("\n"
"font-size: 16px;\n"
"color:rgb(43, 43, 43)"));

        horizontalLayout_6->addWidget(labCurMedia);

        groupBox_2 = new QGroupBox(frame);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(200, 10, 351, 61));
        btnPlay = new QPushButton(groupBox_2);
        btnPlay->setObjectName("btnPlay");
        btnPlay->setGeometry(QRect(80, 10, 40, 40));
        btnPlay->setMinimumSize(QSize(40, 40));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/images/620.bmp"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnPlay->setIcon(icon4);
        btnPause = new QPushButton(groupBox_2);
        btnPause->setObjectName("btnPause");
        btnPause->setGeometry(QRect(160, 10, 40, 40));
        btnPause->setMinimumSize(QSize(40, 40));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/images/622.bmp"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnPause->setIcon(icon5);
        btnStop = new QPushButton(groupBox_2);
        btnStop->setObjectName("btnStop");
        btnStop->setGeometry(QRect(240, 10, 40, 40));
        btnStop->setMinimumSize(QSize(40, 40));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/images/624.bmp"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnStop->setIcon(icon6);
        btnPrevious = new QPushButton(groupBox_2);
        btnPrevious->setObjectName("btnPrevious");
        btnPrevious->setGeometry(QRect(19, 20, 31, 30));
        btnPrevious->setMinimumSize(QSize(30, 30));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/images/images/616.bmp"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnPrevious->setIcon(icon7);
        btnNext = new QPushButton(groupBox_2);
        btnNext->setObjectName("btnNext");
        btnNext->setGeometry(QRect(300, 20, 31, 31));
        btnNext->setMinimumSize(QSize(30, 30));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/images/images/630.bmp"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnNext->setIcon(icon8);
        groupBox_3 = new QGroupBox(frame);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(570, 10, 351, 61));
        doubleSpinBox = new QDoubleSpinBox(groupBox_3);
        doubleSpinBox->setObjectName("doubleSpinBox");
        doubleSpinBox->setGeometry(QRect(170, 10, 101, 41));
        doubleSpinBox->setMinimumSize(QSize(0, 24));
        doubleSpinBox->setStyleSheet(QString::fromUtf8("font-size:16px;"));
        doubleSpinBox->setFrame(true);
        doubleSpinBox->setDecimals(1);
        doubleSpinBox->setMinimum(0.500000000000000);
        doubleSpinBox->setMaximum(1.500000000000000);
        doubleSpinBox->setSingleStep(0.100000000000000);
        doubleSpinBox->setValue(1.000000000000000);
        btnLoop = new QPushButton(groupBox_3);
        btnLoop->setObjectName("btnLoop");
        btnLoop->setGeometry(QRect(290, 17, 52, 31));
        btnLoop->setMaximumSize(QSize(52, 16777215));
        btnLoop->setStyleSheet(QString::fromUtf8("font-size:12px;"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/images/images/refresh16.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnLoop->setIcon(icon9);
        btnLoop->setCheckable(true);
        btnLoop->setChecked(true);
        layoutWidget = new QWidget(groupBox_3);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(9, 12, 141, 41));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        btnSound = new QPushButton(layoutWidget);
        btnSound->setObjectName("btnSound");
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/images/images/volumn.bmp"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnSound->setIcon(icon10);
        btnSound->setIconSize(QSize(24, 24));
        btnSound->setFlat(true);

        horizontalLayout_2->addWidget(btnSound);

        sliderVolumn = new QSlider(layoutWidget);
        sliderVolumn->setObjectName("sliderVolumn");
        sliderVolumn->setMinimumSize(QSize(80, 0));
        sliderVolumn->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal {\n"
"    border: 1px solid #999999;\n"
"    height: 8px;\n"
"    background: #B0E0E6; /* \350\275\250\351\201\223\350\203\214\346\231\257\351\242\234\350\211\262\357\274\214\346\267\241\350\223\235\350\211\262 */\n"
"    margin: 2px 0;\n"
"}\n"
"\n"
"QSlider::handle:horizontal {\n"
"    background: #FFFFFF; /* \346\273\221\345\235\227\351\242\234\350\211\262\357\274\214\347\231\275\350\211\262 */\n"
"    border: 1px solid #5c5c5c;\n"
"    width: 18px;\n"
"    margin: -2px 0;\n"
"    border-radius: 3px;\n"
"}\n"
"\n"
"QSlider::add-page:horizontal {\n"
"    background: #E0FFFF; /* \346\273\221\345\235\227\345\217\263\344\276\247\351\242\234\350\211\262\357\274\214\346\233\264\346\267\241\347\232\204\350\223\235\350\211\262 */\n"
"}\n"
"\n"
"QSlider::sub-page:horizontal {\n"
"    background: #87CEFA; /* \346\273\221\345\235\227\345\267\246\344\276\247\351\242\234\350\211\262\357\274\214\346\265\205\345\244\251\350\223\235\350\211\262 */\n"
"}\n"
""));
        sliderVolumn->setMaximum(100);
        sliderVolumn->setValue(100);
        sliderVolumn->setOrientation(Qt::Orientation::Horizontal);

        horizontalLayout_2->addWidget(sliderVolumn);

        MusicWindow->setCentralWidget(centralwidget);

        retranslateUi(MusicWindow);

        QMetaObject::connectSlotsByName(MusicWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MusicWindow)
    {
        MusicWindow->setWindowTitle(QCoreApplication::translate("MusicWindow", "MainWindow", nullptr));
        btnAdd->setText(QCoreApplication::translate("MusicWindow", "\346\267\273\345\212\240", nullptr));
        love_button->setText(QCoreApplication::translate("MusicWindow", "\346\224\266\350\227\217\342\235\244", nullptr));
        groupBox_5->setTitle(QString());
        labRatio->setText(QCoreApplication::translate("MusicWindow", "  \350\277\233\345\272\246", nullptr));
        groupBox->setTitle(QString());
        label->setText(QString());
        btnRemove->setText(QCoreApplication::translate("MusicWindow", "\347\247\273\351\231\244", nullptr));
        btnClear->setText(QCoreApplication::translate("MusicWindow", "\346\270\205\347\251\272", nullptr));
        labPic->setText(QString());
        groupBoxCover->setTitle(QString());
        btnCover->setText(QString());
        labCurMedia->setText(QCoreApplication::translate("MusicWindow", "\346\227\240\346\233\262\347\233\256", nullptr));
        groupBox_2->setTitle(QString());
#if QT_CONFIG(tooltip)
        btnPlay->setToolTip(QCoreApplication::translate("MusicWindow", "\346\222\255\346\224\276", nullptr));
#endif // QT_CONFIG(tooltip)
        btnPlay->setText(QString());
#if QT_CONFIG(tooltip)
        btnPause->setToolTip(QCoreApplication::translate("MusicWindow", "\346\232\202\345\201\234", nullptr));
#endif // QT_CONFIG(tooltip)
        btnPause->setText(QString());
#if QT_CONFIG(tooltip)
        btnStop->setToolTip(QCoreApplication::translate("MusicWindow", "\345\201\234\346\255\242", nullptr));
#endif // QT_CONFIG(tooltip)
        btnStop->setText(QString());
#if QT_CONFIG(tooltip)
        btnPrevious->setToolTip(QCoreApplication::translate("MusicWindow", "\345\211\215\344\270\200\346\233\262", nullptr));
#endif // QT_CONFIG(tooltip)
        btnPrevious->setText(QString());
#if QT_CONFIG(tooltip)
        btnNext->setToolTip(QCoreApplication::translate("MusicWindow", "\345\220\216\344\270\200\346\233\262", nullptr));
#endif // QT_CONFIG(tooltip)
        btnNext->setText(QString());
        groupBox_3->setTitle(QString());
        doubleSpinBox->setPrefix(QString());
        doubleSpinBox->setSuffix(QCoreApplication::translate("MusicWindow", " \345\200\215\351\200\237 ", nullptr));
        btnLoop->setText(QCoreApplication::translate("MusicWindow", "\345\276\252\347\216\257", nullptr));
        btnSound->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MusicWindow: public Ui_MusicWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MUSICWINDOW_H
