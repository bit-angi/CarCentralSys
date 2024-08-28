#ifndef HOMEWINDOW_H
#define HOMEWINDOW_H

#include <QMainWindow>
#include "mainwindow2.h"
namespace Ui {
class HomeWindow;
}

class HomeWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit HomeWindow(QWidget *parent = nullptr);
    ~HomeWindow();
    void updateTime();
    MainWindow2 *weatherWindow ;
public:
    Ui::HomeWindow *ui;
signals:
    void playRequested();
    void pauseRequested();
    void nextRequested();
    void previousRequested();
    void setSongRequested(const QString &songPath);
private slots:
    void on_pushButton_8_clicked();
    void on_pushButton_10_clicked();
    void on_pushButton_9_clicked();
};

#endif // HOMEWINDOW_H
