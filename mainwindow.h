#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include "musicwindow.h"
#include "homewindow.h"
#include "videowindow.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QMainWindow *weatherwindow;
    QMainWindow *chatwindow;
    VideoWindow *videowindow;
    QMainWindow *gpswindow;
    HomeWindow* homewindow;
    QWidget *picwindow;
    MusicWindow *musicwindow;
public slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_44_clicked();

    void on_pushButton_16_clicked();

    void closeOtherWindows();
    void on_pushButton_13_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_19_clicked();

public:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
