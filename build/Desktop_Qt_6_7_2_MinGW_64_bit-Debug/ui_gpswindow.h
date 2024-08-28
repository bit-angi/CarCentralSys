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
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
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
    QLineEdit *searchLineEdit;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *zoomOutButton;
    QPushButton *zoomInButton;
    QCheckBox *panCheckBox;
    MapWidget *widget;

    void setupUi(QMainWindow *GPSWindow)
    {
        if (GPSWindow->objectName().isEmpty())
            GPSWindow->setObjectName("GPSWindow");
        GPSWindow->resize(960, 600);
        centralwidget = new QWidget(GPSWindow);
        centralwidget->setObjectName("centralwidget");
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
        horizontalLayoutWidget_2->setGeometry(QRect(9, 0, 941, 41));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        startlabel = new QLabel(horizontalLayoutWidget_2);
        startlabel->setObjectName("startlabel");
        QFont font;
        font.setPointSize(15);
        startlabel->setFont(font);

        horizontalLayout_2->addWidget(startlabel);

        startedit = new QLineEdit(horizontalLayoutWidget_2);
        startedit->setObjectName("startedit");

        horizontalLayout_2->addWidget(startedit);

        endlabel = new QLabel(horizontalLayoutWidget_2);
        endlabel->setObjectName("endlabel");
        endlabel->setFont(font);

        horizontalLayout_2->addWidget(endlabel);

        endedit = new QLineEdit(horizontalLayoutWidget_2);
        endedit->setObjectName("endedit");

        horizontalLayout_2->addWidget(endedit);

        jisuan = new QPushButton(horizontalLayoutWidget_2);
        jisuan->setObjectName("jisuan");

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
        searchLineEdit = new QLineEdit(horizontalLayoutWidget);
        searchLineEdit->setObjectName("searchLineEdit");

        horizontalLayout->addWidget(searchLineEdit);

        pushButton = new QPushButton(horizontalLayoutWidget);
        pushButton->setObjectName("pushButton");

        horizontalLayout->addWidget(pushButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        zoomOutButton = new QPushButton(horizontalLayoutWidget);
        zoomOutButton->setObjectName("zoomOutButton");

        horizontalLayout->addWidget(zoomOutButton);

        zoomInButton = new QPushButton(horizontalLayoutWidget);
        zoomInButton->setObjectName("zoomInButton");

        horizontalLayout->addWidget(zoomInButton);

        panCheckBox = new QCheckBox(horizontalLayoutWidget);
        panCheckBox->setObjectName("panCheckBox");

        horizontalLayout->addWidget(panCheckBox);


        verticalLayout->addWidget(frame);

        widget = new MapWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 80, 961, 561));
        QFont font1;
        font1.setPointSize(16);
        widget->setFont(font1);
        GPSWindow->setCentralWidget(centralwidget);

        retranslateUi(GPSWindow);

        QMetaObject::connectSlotsByName(GPSWindow);
    } // setupUi

    void retranslateUi(QMainWindow *GPSWindow)
    {
        GPSWindow->setWindowTitle(QCoreApplication::translate("GPSWindow", "MainWindow", nullptr));
        startlabel->setText(QCoreApplication::translate("GPSWindow", " \350\256\276\347\275\256\350\265\267\347\202\271\357\274\232", nullptr));
        endlabel->setText(QCoreApplication::translate("GPSWindow", " \350\256\276\347\275\256\347\273\210\347\202\271\357\274\232", nullptr));
        jisuan->setText(QCoreApplication::translate("GPSWindow", "\350\256\241\347\256\227\347\273\230\345\210\266\350\267\257\345\276\204", nullptr));
        pushButton->setText(QCoreApplication::translate("GPSWindow", "\346\220\234\347\264\242\345\234\260\347\202\271", nullptr));
        zoomOutButton->setText(QCoreApplication::translate("GPSWindow", "\347\274\251\345\260\217\345\234\260\345\233\276", nullptr));
        zoomInButton->setText(QCoreApplication::translate("GPSWindow", "\346\224\276\345\244\247\345\234\260\345\233\276", nullptr));
        panCheckBox->setText(QCoreApplication::translate("GPSWindow", "\347\247\273\345\212\250\346\250\241\345\274\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GPSWindow: public Ui_GPSWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GPSWINDOW_H
