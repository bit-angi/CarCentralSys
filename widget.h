#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "audio.h"
#include "speech.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_pressed();

    void on_pushButton_released();

    void on_pushButton_2_clicked();
signals :
    void newSignal(QString sentence) ;
private:
    Ui::Widget *ui;
    Audio *audio;

};
#endif // WIDGET_H
