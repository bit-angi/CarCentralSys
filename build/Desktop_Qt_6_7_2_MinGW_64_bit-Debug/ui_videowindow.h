/********************************************************************************
** Form generated from reading UI file 'videowindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIDEOWINDOW_H
#define UI_VIDEOWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VideoWindow
{
public:
    QWidget *centralwidget;
    QPushButton *forwardButton;
    QSlider *voiceSlider;
    QDoubleSpinBox *speedOptionBox;
    QLabel *label;
    QSlider *progressBar;
    QPushButton *backwardButton;
    QLabel *seperate;
    QPushButton *voiceButton;
    QPushButton *stopButton;
    QLabel *time_total;
    QPushButton *playButton;
    QLabel *time_now;
    QPushButton *openButton;

    void setupUi(QMainWindow *VideoWindow)
    {
        if (VideoWindow->objectName().isEmpty())
            VideoWindow->setObjectName("VideoWindow");
        VideoWindow->resize(960, 600);
        centralwidget = new QWidget(VideoWindow);
        centralwidget->setObjectName("centralwidget");
        forwardButton = new QPushButton(centralwidget);
        forwardButton->setObjectName("forwardButton");
        forwardButton->setGeometry(QRect(525, 500, 55, 55));
        forwardButton->setStyleSheet(QString::fromUtf8("border-image: url(:/cannotforward.png);"));
        voiceSlider = new QSlider(centralwidget);
        voiceSlider->setObjectName("voiceSlider");
        voiceSlider->setGeometry(QRect(730, 522, 181, 16));
        voiceSlider->setValue(50);
        voiceSlider->setOrientation(Qt::Orientation::Horizontal);
        speedOptionBox = new QDoubleSpinBox(centralwidget);
        speedOptionBox->setObjectName("speedOptionBox");
        speedOptionBox->setGeometry(QRect(250, 515, 91, 31));
        speedOptionBox->setMouseTracking(false);
        speedOptionBox->setTabletTracking(false);
        speedOptionBox->setAlignment(Qt::AlignmentFlag::AlignCenter);
        speedOptionBox->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::PlusMinus);
        speedOptionBox->setDecimals(1);
        speedOptionBox->setMinimum(0.500000000000000);
        speedOptionBox->setMaximum(3.000000000000000);
        speedOptionBox->setSingleStep(0.500000000000000);
        speedOptionBox->setStepType(QAbstractSpinBox::StepType::DefaultStepType);
        speedOptionBox->setValue(1.000000000000000);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 10, 900, 450));
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        progressBar = new QSlider(centralwidget);
        progressBar->setObjectName("progressBar");
        progressBar->setGeometry(QRect(30, 470, 781, 16));
        progressBar->setOrientation(Qt::Orientation::Horizontal);
        backwardButton = new QPushButton(centralwidget);
        backwardButton->setObjectName("backwardButton");
        backwardButton->setGeometry(QRect(375, 500, 55, 55));
        backwardButton->setStyleSheet(QString::fromUtf8("border-image: url(:/cannotbackward.png);"));
        seperate = new QLabel(centralwidget);
        seperate->setObjectName("seperate");
        seperate->setGeometry(QRect(850, 470, 40, 12));
        seperate->setAlignment(Qt::AlignmentFlag::AlignCenter);
        voiceButton = new QPushButton(centralwidget);
        voiceButton->setObjectName("voiceButton");
        voiceButton->setGeometry(QRect(690, 515, 31, 31));
        voiceButton->setStyleSheet(QString::fromUtf8("border-image: url(:/notmuted.png);"));
        stopButton = new QPushButton(centralwidget);
        stopButton->setObjectName("stopButton");
        stopButton->setGeometry(QRect(610, 505, 51, 51));
        stopButton->setStyleSheet(QString::fromUtf8("border-image: url(:/stop.png);"));
        time_total = new QLabel(centralwidget);
        time_total->setObjectName("time_total");
        time_total->setGeometry(QRect(875, 465, 51, 21));
        time_total->setAlignment(Qt::AlignmentFlag::AlignCenter);
        playButton = new QPushButton(centralwidget);
        playButton->setObjectName("playButton");
        playButton->setGeometry(QRect(440, 485, 80, 80));
        playButton->setStyleSheet(QString::fromUtf8("border-image: url(:/cannotplay.png);"));
        time_now = new QLabel(centralwidget);
        time_now->setObjectName("time_now");
        time_now->setGeometry(QRect(815, 465, 51, 21));
        time_now->setAlignment(Qt::AlignmentFlag::AlignCenter);
        openButton = new QPushButton(centralwidget);
        openButton->setObjectName("openButton");
        openButton->setGeometry(QRect(170, 505, 61, 51));
        openButton->setStyleSheet(QString::fromUtf8("border-image: url(:/open.png);"));
        VideoWindow->setCentralWidget(centralwidget);

        retranslateUi(VideoWindow);

        QMetaObject::connectSlotsByName(VideoWindow);
    } // setupUi

    void retranslateUi(QMainWindow *VideoWindow)
    {
        VideoWindow->setWindowTitle(QCoreApplication::translate("VideoWindow", "MainWindow", nullptr));
        forwardButton->setText(QString());
        speedOptionBox->setSuffix(QString());
        label->setText(QCoreApplication::translate("VideoWindow", "\345\252\222\344\275\223\346\222\255\346\224\276\345\231\250", nullptr));
        backwardButton->setText(QString());
        seperate->setText(QCoreApplication::translate("VideoWindow", "/", nullptr));
        voiceButton->setText(QString());
        stopButton->setText(QString());
        time_total->setText(QCoreApplication::translate("VideoWindow", "00:00:00", nullptr));
        playButton->setText(QString());
        time_now->setText(QCoreApplication::translate("VideoWindow", "00:00:00", nullptr));
        openButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class VideoWindow: public Ui_VideoWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEOWINDOW_H
