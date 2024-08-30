#include "mainwindow.h"
#include "mainwindow2.h"
#include "ui_mainwindow.h"
#include "ui_homewindow.h"
#include "ui_musicwindow.h"
#include "videowindow.h"
#include "chatwindow.h"
#include "musicwindow.h"
#include "gpswindow.h"
#include "picplayerwidget.h"

#include "HomeWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    this->setWindowFlags(Qt::FramelessWindowHint);
    ui->setupUi(this);
    this->videowindow = NULL;
    this->musicwindow = NULL;

    homewindow = new HomeWindow(this->ui->widget);
    connect(homewindow,&HomeWindow::daohang,this,[=]() {
        on_pushButton_13_clicked();
    });
    connect(homewindow,&HomeWindow::chat,this,[=]() {
        on_pushButton_2_clicked();
    });
    connect(homewindow,&HomeWindow::yinyue,this,[=]() {
        on_pushButton_19_clicked();
    });
    homewindow->show();
    homewindow->raise();
    this->on_pushButton_44_clicked();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    closeOtherWindows();
    this->ui->widget->show();
    this->weatherwindow = new MainWindow2(this->ui->widget);
    this->weatherwindow->show();
    this->weatherwindow->raise();
}


void MainWindow::on_pushButton_2_clicked()
{
    closeOtherWindows();
    this->ui->widget->show();
    this->chatwindow = new ChatWindow(this->ui->widget);
    this->chatwindow->show();
        this->chatwindow->raise();
}


void MainWindow::on_pushButton_44_clicked()
{
    closeOtherWindows();
    homewindow->raise();
    if (this->musicwindow) {
        this->homewindow->ui->label_14->setText(this->musicwindow->ui->labCurMedia->text());
    }
}


void MainWindow::on_pushButton_16_clicked()
{
    this->ui->widget->show();
    this->videowindow = new VideoWindow(this->ui->widget);
    this->videowindow->show();
    this->videowindow->raise();
}

void MainWindow::closeOtherWindows()
{
    if (this->videowindow) {
        this->videowindow->close();
        this->videowindow->pVideoWidget->close();
    }
}


void MainWindow::on_pushButton_13_clicked()
{
    closeOtherWindows();
    this->ui->widget->show();
    this->gpswindow = new GPSWindow(this->ui->widget);
    this->gpswindow->show();
}


void MainWindow::on_pushButton_18_clicked()
{
    closeOtherWindows();
    this->ui->widget->show();
    this->picwindow = new PicPlayerWidget();
    this->picwindow->setParent(this->ui->widget);
    this->picwindow->show();
}


void MainWindow::on_pushButton_19_clicked()
{
    closeOtherWindows();
    this->ui->widget->show();
    if (!this->musicwindow) {
        this->musicwindow = new MusicWindow(this->ui->widget);
        connect(homewindow, &HomeWindow::playRequested, this, [=]() {
            if (this->musicwindow->player->isPlaying()) {
                this->musicwindow->player->pause();
                this->homewindow->ui->pushButton_8->setStyleSheet("image: url(:/new/prefix1/run.png);");
            }
            else {
                this->musicwindow->player->play();
                this->homewindow->ui->pushButton_8->setStyleSheet("image: url(:/cont)");
            }
        });

        connect(homewindow, &HomeWindow::nextRequested, musicwindow, [=]() {
            musicwindow->on_btnNext_clicked();
            if (this->musicwindow) {
                this->homewindow->ui->label_14->setText(this->musicwindow->ui->labCurMedia->text());
            }
        });
        connect(homewindow, &HomeWindow::previousRequested, musicwindow,[=]() {
            musicwindow->on_btnPrevious_clicked();
            if (this->musicwindow) {
                this->homewindow->ui->label_14->setText(this->musicwindow->ui->labCurMedia->text());
            }
        });


    }

    this->musicwindow->raise();

    this->musicwindow->setParent(this->ui->widget);
    this->musicwindow->show();
}

