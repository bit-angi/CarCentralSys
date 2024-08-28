#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <QWidget>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->pushButton->setText("按住说话");

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_pressed()
{
    ui->pushButton->setText("松开识别");

    //开始录音
    audio = new Audio;
    audio->startAudio(".\\file");
}

void Widget::on_pushButton_released()
{
    //停止录音
    audio->stopAudio();
    //修改按钮文字
    ui->pushButton->setText("开始识别");

    //开始识别
    Speech m_speech;
    QString text = m_speech.speechIdentify("./file");

    ui->textEdit->setText(text);

    ui->pushButton->setText("按住说话");
    QMessageBox::information(this,"info",text);
    emit this->newSignal(text);
}

void Widget::on_pushButton_2_clicked()
{
    ui->textEdit->clear();
}
