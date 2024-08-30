/********************************************************************************
** Form generated from reading UI file 'gpswindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GPSWINDOW_H
#define UI_GPSWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <mapwidget.h>

QT_BEGIN_NAMESPACE

class Ui_GPSWindow
{
public:
    QWidget *centralwidget;
    MapWidget *widget;
    QWidget *widget_2;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label;
    QPushButton *clearbn;
    QSpacerItem *horizontalSpacer_3;
    QWidget *widget_3;
    QListView *listView;
    QPushButton *pushButton_3;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QFrame *frame_2;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *startlabel;
    QLineEdit *startedit;
    QLabel *endlabel;
    QLineEdit *endedit;
    QPushButton *jisuan;
    QFrame *frame;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_2;
    QLineEdit *searchLineEdit;
    QSpacerItem *horizontalSpacer;
    QPushButton *zoomOutButton;
    QPushButton *zoomInButton;
    QCheckBox *panCheckBox;

    void setupUi(QMainWindow *GPSWindow)
    {
        if (GPSWindow->objectName().isEmpty())
            GPSWindow->setObjectName("GPSWindow");
        GPSWindow->resize(960, 600);
        centralwidget = new QWidget(GPSWindow);
        centralwidget->setObjectName("centralwidget");
        widget = new MapWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 80, 961, 561));
        QFont font;
        font.setPointSize(16);
        widget->setFont(font);
        widget->setStyleSheet(QString::fromUtf8(""));
        widget_2 = new QWidget(widget);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(0, 0, 301, 211));
        widget_2->setStyleSheet(QString::fromUtf8("    background-color: #D0E8F2;\n"
"    border-radius: 10px;"));
        horizontalLayoutWidget_3 = new QWidget(widget_2);
        horizontalLayoutWidget_3->setObjectName("horizontalLayoutWidget_3");
        horizontalLayoutWidget_3->setGeometry(QRect(70, 170, 152, 31));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        label = new QLabel(horizontalLayoutWidget_3);
        label->setObjectName("label");
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("color: black"));

        horizontalLayout_3->addWidget(label);

        clearbn = new QPushButton(horizontalLayoutWidget_3);
        clearbn->setObjectName("clearbn");
        QFont font2;
        font2.setPointSize(15);
        clearbn->setFont(font2);
        clearbn->setStyleSheet(QString::fromUtf8("image: url(:/delete.png);"));

        horizontalLayout_3->addWidget(clearbn);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        widget_3 = new QWidget(widget_2);
        widget_3->setObjectName("widget_3");
        widget_3->setGeometry(QRect(10, 10, 281, 151));
        widget_3->setStyleSheet(QString::fromUtf8(" background-color: white;"));
        listView = new QListView(widget_3);
        listView->setObjectName("listView");
        listView->setGeometry(QRect(10, 10, 261, 131));
        listView->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"color: black;\n"
"font-size: 12pt;"));
        pushButton_3 = new QPushButton(widget_2);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(0, 170, 71, 31));
        pushButton_3->setStyleSheet(QString::fromUtf8("border-radius:30px;\n"
"background-color:rgba(255,255,255,0.8)"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/res/mic.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_3->setIcon(icon);
        pushButton_3->setIconSize(QSize(25, 25));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(1, 0, 961, 81));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        frame_2 = new QFrame(verticalLayoutWidget);
        frame_2->setObjectName("frame_2");
        frame_2->setFrameShape(QFrame::Shape::StyledPanel);
        frame_2->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayoutWidget_2 = new QWidget(frame_2);
        horizontalLayoutWidget_2->setObjectName("horizontalLayoutWidget_2");
        horizontalLayoutWidget_2->setGeometry(QRect(0, 0, 951, 41));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        startlabel = new QLabel(horizontalLayoutWidget_2);
        startlabel->setObjectName("startlabel");
        QFont font3;
        font3.setPointSize(12);
        startlabel->setFont(font3);

        horizontalLayout_2->addWidget(startlabel);

        startedit = new QLineEdit(horizontalLayoutWidget_2);
        startedit->setObjectName("startedit");

        horizontalLayout_2->addWidget(startedit);

        endlabel = new QLabel(horizontalLayoutWidget_2);
        endlabel->setObjectName("endlabel");
        endlabel->setFont(font3);

        horizontalLayout_2->addWidget(endlabel);

        endedit = new QLineEdit(horizontalLayoutWidget_2);
        endedit->setObjectName("endedit");

        horizontalLayout_2->addWidget(endedit);

        jisuan = new QPushButton(horizontalLayoutWidget_2);
        jisuan->setObjectName("jisuan");
        jisuan->setFont(font3);

        horizontalLayout_2->addWidget(jisuan);


        verticalLayout->addWidget(frame_2);

        frame = new QFrame(verticalLayoutWidget);
        frame->setObjectName("frame");
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayoutWidget = new QWidget(frame);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(8, -3, 941, 41));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        label_2 = new QLabel(horizontalLayoutWidget);
        label_2->setObjectName("label_2");
        label_2->setFont(font3);

        horizontalLayout->addWidget(label_2);

        searchLineEdit = new QLineEdit(horizontalLayoutWidget);
        searchLineEdit->setObjectName("searchLineEdit");

        horizontalLayout->addWidget(searchLineEdit);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        zoomOutButton = new QPushButton(horizontalLayoutWidget);
        zoomOutButton->setObjectName("zoomOutButton");
        zoomOutButton->setFont(font3);
        zoomOutButton->setStyleSheet(QString::fromUtf8("image: url(:/small.png);"));

        horizontalLayout->addWidget(zoomOutButton);

        zoomInButton = new QPushButton(horizontalLayoutWidget);
        zoomInButton->setObjectName("zoomInButton");
        zoomInButton->setFont(font3);
        zoomInButton->setStyleSheet(QString::fromUtf8("image: url(:/big.png);"));

        horizontalLayout->addWidget(zoomInButton);

        panCheckBox = new QCheckBox(horizontalLayoutWidget);
        panCheckBox->setObjectName("panCheckBox");
        panCheckBox->setFont(font3);

        horizontalLayout->addWidget(panCheckBox);


        verticalLayout->addWidget(frame);

        GPSWindow->setCentralWidget(centralwidget);

        retranslateUi(GPSWindow);

        QMetaObject::connectSlotsByName(GPSWindow);
    } // setupUi

    void retranslateUi(QMainWindow *GPSWindow)
    {
        GPSWindow->setWindowTitle(QCoreApplication::translate("GPSWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("GPSWindow", "\347\202\271\345\207\273\346\270\205\351\231\244\357\274\232", nullptr));
        clearbn->setText(QString());
        pushButton_3->setText(QString());
        startlabel->setText(QCoreApplication::translate("GPSWindow", " \350\256\276\347\275\256\350\265\267\347\202\271\357\274\232", nullptr));
        endlabel->setText(QCoreApplication::translate("GPSWindow", " \350\256\276\347\275\256\347\273\210\347\202\271\357\274\232", nullptr));
        jisuan->setText(QCoreApplication::translate("GPSWindow", "\350\256\241\347\256\227\347\273\230\345\210\266\350\267\257\345\276\204", nullptr));
        label_2->setText(QCoreApplication::translate("GPSWindow", "\346\220\234\347\264\242\344\275\215\347\275\256", nullptr));
        zoomOutButton->setText(QString());
        zoomInButton->setText(QString());
        panCheckBox->setText(QCoreApplication::translate("GPSWindow", "\347\247\273\345\212\250\346\250\241\345\274\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GPSWindow: public Ui_GPSWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GPSWINDOW_H
