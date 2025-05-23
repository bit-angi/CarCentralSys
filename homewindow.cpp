#include "homewindow.h"
#include "ui_homewindow.h"
#include "ui_mainwindow2.h"
#include "mainwindow2.h"
#include "littlepicwidget.h"
#include <QDateTime>
#include <QTimer>

HomeWindow::HomeWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::HomeWindow)
{
    ui->setupUi(this);
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &HomeWindow::updateTime);
    timer->start(1000); // 每秒更新时间
    setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);
    this->weatherWindow = new MainWindow2(this);
    qDebug() << "labelcuty" <<this->weatherWindow->ui->lblCity->text();
    this->ui->label_10->setText(this->weatherWindow->ui->lblCity->text());
    this->ui->label->setText(this->weatherWindow->ui->lblTemp->text());
    this->weatherWindow->hide();

    // 小的图片展示器
    LittlePicWidget* wid = new LittlePicWidget();
    wid->setParent(this->ui->pic_widget);

}

HomeWindow::~HomeWindow()
{
    delete ui;
}

void HomeWindow::updateTime() {
    // 对时间进行设定
    QDateTime currentDateTime = QDateTime::currentDateTime();
    QString timeString = currentDateTime.time().toString("HH:mm");
    QString dayString = currentDateTime.date().toString("yyyy-MM-dd");

    // 对文本样式进行设定
    ui->time_label->setText(timeString);
    ui->day_label->setText(dayString);
    ui->time_label->setStyleSheet("QLabel {"
                                  "  font-weight: bold;" // 加粗
                                  "  font-size: 48pt;" // 设置字体大小
                                  "  color: rgb(32, 59, 237);"
                                  " background-color: rgba(255, 255, 255,0);"

                                  "}");
    ui->day_label->setStyleSheet("QLabel {"
                                 "  font-size: 11pt;" // 设置字体大小
                                 "  color: rgb(32, 59, 237);"
                                 " background-color: rgba(255, 255, 255,0);"
                                 " font-style:italic;"
                                 "}");
}

void HomeWindow::on_pushButton_8_clicked()
{
    emit this->playRequested();
}


void HomeWindow::on_pushButton_10_clicked()
{
    emit this->previousRequested();
}


void HomeWindow::on_pushButton_9_clicked()
{
    emit this->nextRequested();
}


void HomeWindow::on_pushButton_3_clicked()
{

}

void HomeWindow::on_pushButton_3_pressed()
{
    ui->pushButton_3->setText("松开识别");
    //开始录音
    audio = new Audio;
    audio->startAudio(".\\file");
}



void HomeWindow::on_pushButton_3_released()
{
    audio->stopAudio();
    //修改按钮文字
    ui->pushButton_3->setText("开始识别");
    //开始识别
    Speech m_speech;
    QString text = m_speech.speechIdentify("./file");
    ui->pushButton_3->setText("按住说话");
    qDebug() <<"hh"<< text;
    if (text.contains("歌")) {
        this->on_pushButton_9_clicked();
    }
    else if (text.contains("导航")) {
        emit daohang();
    }
    else if (text.contains("音乐")) {
        emit yinyue();
    }
    else if (text.contains("聊天") || text.contains("通讯")) {
        emit chat();
    }
}
