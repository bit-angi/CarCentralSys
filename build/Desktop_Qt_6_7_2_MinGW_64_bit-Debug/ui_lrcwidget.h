/********************************************************************************
** Form generated from reading UI file 'lrcwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LRCWIDGET_H
#define UI_LRCWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_lrcwidget
{
public:
    QPushButton *pushButton;
    QListWidget *lrc_list;
    QSlider *horizontalSlider;
    QLabel *labProcess;
    QSlider *soundSlider;
    QPushButton *pushButton_5;
    QPushButton *btnNext;
    QPushButton *btnPrev;
    QPushButton *btnPlay;
    QPushButton *btnMode;
    QDoubleSpinBox *spinBoxSpeed;

    void setupUi(QWidget *lrcwidget)
    {
        if (lrcwidget->objectName().isEmpty())
            lrcwidget->setObjectName("lrcwidget");
        lrcwidget->setWindowModality(Qt::NonModal);
        lrcwidget->resize(960, 600);
        pushButton = new QPushButton(lrcwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(9, 9, 80, 24));
        lrc_list = new QListWidget(lrcwidget);
        lrc_list->setObjectName("lrc_list");
        lrc_list->setGeometry(QRect(10, 160, 931, 281));
        lrc_list->setStyleSheet(QString::fromUtf8(""));
        horizontalSlider = new QSlider(lrcwidget);
        horizontalSlider->setObjectName("horizontalSlider");
        horizontalSlider->setGeometry(QRect(20, 490, 751, 16));
        horizontalSlider->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal {\n"
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
        horizontalSlider->setOrientation(Qt::Horizontal);
        labProcess = new QLabel(lrcwidget);
        labProcess->setObjectName("labProcess");
        labProcess->setGeometry(QRect(810, 480, 131, 41));
        QFont font;
        font.setPointSize(13);
        labProcess->setFont(font);
        labProcess->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color black;\n"
"}\n"
""));
        soundSlider = new QSlider(lrcwidget);
        soundSlider->setObjectName("soundSlider");
        soundSlider->setGeometry(QRect(70, 540, 131, 21));
        soundSlider->setMinimumSize(QSize(80, 15));
        soundSlider->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal {\n"
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
        soundSlider->setOrientation(Qt::Horizontal);
        soundSlider->setTickInterval(1);
        pushButton_5 = new QPushButton(lrcwidget);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(20, 540, 31, 20));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/images/volumn.bmp"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_5->setIcon(icon);
        btnNext = new QPushButton(lrcwidget);
        btnNext->setObjectName("btnNext");
        btnNext->setGeometry(QRect(490, 530, 40, 40));
        btnNext->setMinimumSize(QSize(40, 40));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/images/630.bmp"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnNext->setIcon(icon1);
        btnPrev = new QPushButton(lrcwidget);
        btnPrev->setObjectName("btnPrev");
        btnPrev->setGeometry(QRect(350, 530, 40, 40));
        btnPrev->setMinimumSize(QSize(40, 40));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/images/616.bmp"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnPrev->setIcon(icon2);
        btnPlay = new QPushButton(lrcwidget);
        btnPlay->setObjectName("btnPlay");
        btnPlay->setGeometry(QRect(420, 530, 40, 40));
        btnPlay->setMinimumSize(QSize(40, 40));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/images/620.bmp"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnPlay->setIcon(icon3);
        btnMode = new QPushButton(lrcwidget);
        btnMode->setObjectName("btnMode");
        btnMode->setGeometry(QRect(660, 530, 70, 41));
        btnMode->setMaximumSize(QSize(70, 50));
        btnMode->setStyleSheet(QString::fromUtf8("font: 14pt \"Microsoft YaHei UI\";"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/images/refresh16.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnMode->setIcon(icon4);
        spinBoxSpeed = new QDoubleSpinBox(lrcwidget);
        spinBoxSpeed->setObjectName("spinBoxSpeed");
        spinBoxSpeed->setGeometry(QRect(810, 530, 141, 41));
        spinBoxSpeed->setStyleSheet(QString::fromUtf8("font: 14pt \"Microsoft YaHei UI\";"));
        spinBoxSpeed->setValue(1.000000000000000);

        retranslateUi(lrcwidget);

        QMetaObject::connectSlotsByName(lrcwidget);
    } // setupUi

    void retranslateUi(QWidget *lrcwidget)
    {
        lrcwidget->setWindowTitle(QCoreApplication::translate("lrcwidget", "lrcWidget", nullptr));
        pushButton->setText(QCoreApplication::translate("lrcwidget", "\345\205\263\351\227\255\346\255\214\350\257\215", nullptr));
        labProcess->setText(QCoreApplication::translate("lrcwidget", "00:00/00:00", nullptr));
        pushButton_5->setText(QString());
        btnNext->setText(QString());
        btnPrev->setText(QString());
        btnPlay->setText(QString());
        btnMode->setText(QCoreApplication::translate("lrcwidget", "\345\276\252\347\216\257", nullptr));
        spinBoxSpeed->setSuffix(QCoreApplication::translate("lrcwidget", "\345\200\215\351\200\237", nullptr));
    } // retranslateUi

};

namespace Ui {
    class lrcwidget: public Ui_lrcwidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LRCWIDGET_H
