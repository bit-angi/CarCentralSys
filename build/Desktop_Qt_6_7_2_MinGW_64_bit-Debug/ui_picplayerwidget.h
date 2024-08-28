/********************************************************************************
** Form generated from reading UI file 'picplayerwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PICPLAYERWIDGET_H
#define UI_PICPLAYERWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PicPlayerWidget
{
public:

    void setupUi(QWidget *PicPlayerWidget)
    {
        if (PicPlayerWidget->objectName().isEmpty())
            PicPlayerWidget->setObjectName("PicPlayerWidget");
        PicPlayerWidget->resize(960, 600);

        retranslateUi(PicPlayerWidget);

        QMetaObject::connectSlotsByName(PicPlayerWidget);
    } // setupUi

    void retranslateUi(QWidget *PicPlayerWidget)
    {
        PicPlayerWidget->setWindowTitle(QCoreApplication::translate("PicPlayerWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PicPlayerWidget: public Ui_PicPlayerWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PICPLAYERWIDGET_H
