#include "mainwindow.h"
#include "mainwindow2.h"
#include "ui_mainwindow.h"
#include "videowindow.h"
#include "chatwindow.h"
#include "musicwindow.h"
#include "gpswindow.h"
#include "picplayerwidget.h"
#include "homewindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->videowindow = NULL;
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
}


void MainWindow::on_pushButton_2_clicked()
{
    closeOtherWindows();
    this->ui->widget->show();
    this->chatwindow = new ChatWindow(this->ui->widget);
    this->chatwindow->show();
}


void MainWindow::on_pushButton_44_clicked()
{
    QMainWindow* home = new HomeWindow(this->ui->widget);
    home->show();
}


void MainWindow::on_pushButton_16_clicked()
{
    this->ui->widget->show();
    this->videowindow = new VideoWindow(this->ui->widget);
    this->videowindow->show();
}

void MainWindow::closeOtherWindows()
{
    if (this->videowindow) this->videowindow->hide();
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
    this->musicwindow = new MusicWindow(this->ui->widget);
    this->musicwindow->setParent(this->ui->widget);
    this->musicwindow->show();
}

