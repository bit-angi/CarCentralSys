#include "homewindow.h"
#include "ui_homewindow.h"

HomeWindow::HomeWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::HomeWindow)
{
    ui->setupUi(this);
        setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);
}

HomeWindow::~HomeWindow()
{
    delete ui;
}
