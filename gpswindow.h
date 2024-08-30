#ifndef GPSWINDOW_H
#define GPSWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <qcompleter.h>
#include <qstringlistmodel.h>
#include "MapWidget.h"  // 引入自定义的MapWidget组件
#include "audio.h"

namespace Ui {
class GPSWindow;
}

class QDomElement;

class GPSWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit GPSWindow(QWidget *parent = nullptr);
    ~GPSWindow();

    void loadOSMFile(const QString &fileName);  // 加载OSM文件
    void parseNodeElement(const QDomElement &element);  // 解析节点元素
    QStringListModel *model;  // 声明 QStringListModel 成员变量
    void updateSuggestions(const QString &text, QStringListModel *model);
    Audio* audio;
public:
    Ui::GPSWindow *ui;
    QVector<Way> allWays;
    QVector<Way> filteredWays;
    QVector<Coordinates> main_routePoints;
    double minLat, maxLat, minLon, maxLon;  // 地图的边界值
    void fetchAndSaveMap(const QString &filePath);

    QString filePath;  // Member variable to store the path of the saved map image
    QPixmap m_mapPixmap;  // 存储地图图片的 QPixmap 对象
    double currentZoomFactor = 1.0; // 当前缩放因子
    static constexpr double zoomLevels[] = {1.0,1.1,1.2,1.3,1.5,1.7,1.9,2.1,2.3,2.5};  // 缩放档位
    int currentZoomIndex = 0;  // 默认为中间档位（1.0）
    QCompleter *searchCompleter;  // 独立的 QCompleter
    QCompleter *startCompleter;   // 独立的 QCompleter
    QCompleter *endCompleter;     // 独立的 QCompleter

    QStringListModel *searchModel;  // 独立的 QStringListModel
    QStringListModel *startModel;   // 独立的 QStringListModel
    QStringListModel *endModel;     // 独立的 QStringListModel

    void setupSearchCompleter();



private slots:
    void onSearchTextChanged(const QString &text);  // 已存在的槽函数
    void onStartEditTextChanged(const QString &text);  // 新增的槽函数
    void onEndEditTextChanged(const QString &text);  // 新增的槽函数
    void on_zoomInButton_clicked();    // 缩放放大按钮点击槽函数
    void on_zoomOutButton_clicked();   // 缩放缩小按钮点击槽函数
    void updateMap();
    void clearListView();
    void addInformation(const QString &info);

    void on_pushButton_3_pressed();
    void on_pushButton_3_released();
};


#endif // GPSWindow_H
