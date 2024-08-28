#ifndef MAINWINDOW2_H
#define MAINWINDOW2_H

#include <weatherdata.h>
//#include "widget.h"
#include <QLabel>
#include <QMainWindow>
#include <QMap>
#include <QMouseEvent>
#include <Widget.h>
//#include "widget.h"
#include <QNetworkAccessManager>


namespace Ui {
class MainWindow2;
}


class MainWindow2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow2(QWidget* parent = nullptr);
    ~MainWindow2();
    Widget *wid ;
    Audio *audio;
    bool eventFilter(QObject* watched, QEvent* event);
protected:
    // 重写父类的方法
    void contextMenuEvent(QContextMenuEvent* event);
    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);

    // 获取天气数据、解析JSON、更新UI
    void getWeatherInfo(QString cityCode);
    void parseJson(QByteArray& byteArray);
    void updateUI();

    // 绘制高低温曲线
    void paintHighCurve();
    void paintLowCurve();
    void paintEvent(QPaintEvent *event);
private slots:
    void onReplied(QNetworkReply* reply);

    void on_btnSearch_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_3_pressed();

    void on_pushButton_3_released();

private:
    Ui::MainWindow2* ui;

    // 右键退出和窗口移动
    QMenu* mExitMenu;   // 右键退出的菜单
    QAction* mExitAct;  // 退出的行为
    QPoint mOffset;     // 窗口移动时, 鼠标与窗口左上角的偏移

    // Http 请求
    QNetworkAccessManager* mNetAccessManager;

    // 今天和6天的天气
    Today mToday;
    Day mDay[6];

    // 星期和日期
    QList<QLabel*> mWeekList;
    QList<QLabel*> mDateList;

    // 天气和天气图标
    QList<QLabel*> mTypeList;
    QList<QLabel*> mTypeIconList;

    // 天气指数
    QList<QLabel*> mAqiList;

    // 风向和风力
    QList<QLabel*> mFxList;
    QList<QLabel*> mFlList;

    QMap<QString, QString> mTypeMap;
};
#endif  // MAINWINDOW_H
