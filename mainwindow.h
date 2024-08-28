#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>

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
    QMainWindow *videowindow;
    QMainWindow *gpswindow;
    QWidget *picwindow;
    QMainWindow *musicwindow;
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_44_clicked();

    void on_pushButton_16_clicked();

    void closeOtherWindows();
    void on_pushButton_13_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_19_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
