#ifndef MAPWIDGET_H
#define MAPWIDGET_H

#include <QWidget>
#include <QVector>
#include <QPointF>
#include <QSet>
#include <QPair>
#include <queue>  // 用于 std::priority_queue

// 定义坐标结构体，包含经纬度和屏幕坐标
struct Coordinates {
    qint64 id;
    double lat;
    double lon;
    double screenX;  // 屏幕X坐标
    double screenY;  // 屏幕Y坐标
    bool isValid;    // 标识坐标是否有效

    Coordinates() : id(0), lat(0.0), lon(0.0), screenX(0.0), screenY(0.0), isValid(false) {}

    bool isEmpty() const {
        return !isValid;
    }
};


// 更新 Way 结构体，包含路径信息和标签信息
struct Way {
    QVector<Coordinates> nodes;  // 路径中的节点
    QString tagInfo;             // 存储所有 tag 信息的字符串
};

class MapWidget : public QWidget {
    Q_OBJECT

public:
    explicit MapWidget(QWidget *parent = nullptr);

    // 设置路线点
    void setRoutePoints(const QVector<Coordinates> &points);

    // 设置地图边界
    void setBounds(double minLat, double maxLat, double minLon, double maxLon);

    // 设置所有 Way 标签信息
    void setWays(const QVector<Way> &ways);

    // 设置并绘制过滤后的 Way 标签信息
    void setFilteredWays(const QVector<Way> &filteredWays);

    // 查找最近Way和计算最短路径的功能
    QVector<qint64> findShortestPath(const QString &startPlace, const QString &endPlace);
    qint64 findNodeIdByPlaceName(const QString &placeName);
    QVector<qint64> dijkstraShortestPath(qint64 startId, qint64 endId);
    Coordinates clickPos;
    Coordinates oringnal_clickpos;

    void setMapPixmap(const QPixmap &pixmap);
    QPointF mapOffset;
    QPixmap m_originalPixmap;
    QPixmap m_mapPixmap;
    void updateAndSetMapPixmap();
    int cropX;
    int cropY;
    int cropWidth;
    int cropHeight;
    void setCropParameters(int x, int y, int width, int height);
    void setZoomIndex(int zoomIndex);
    // 定义信号
    signals:
        void informationRequested(const QString &info);





protected:
    // 重写绘制事件，用于绘制地图和路线
    void paintEvent(QPaintEvent *event) override;

    // 重写鼠标移动事件，用于显示路网信息
    void mouseMoveEvent(QMouseEvent *event) override;

    // 重写鼠标点击事件，用于记录点击位置和显示最近的 Way 信息
    void mousePressEvent(QMouseEvent *event) override;

private:
    QVector<Coordinates> routePoints;  // 用于存储路线上的点
    QVector<Way> ways;                 // 用于存储所有 Way 标签中的信息
    QVector<QPair<QPointF, QString>> wayMarkers;  // 存储标记的位置和地址信息
    QVector<Way> filteredWays;         // 保存搜索结果              // 用户点击的位置
    Way closestWay;                    // 最近的 Way
    bool panMode;  // 用于标记是否处于平移模式

    QMap<qint64, QMap<qint64, double>> graph;  // 图的邻接表表示
    QVector<qint64> path;  // 用于存储最短路径上的点

    QPointF lastMousePos;   // 记录上一次鼠标的位置


    void findClosestWay(const Coordinates &clickPos);  // 找到点击位置最近的Way
    void buildGraph();  // 确保这行存在
    double minLat, maxLat, minLon, maxLon;
    double calculateDistance(const Coordinates &a, const Coordinates &b);

    // 替代 QPriorityQueue
    typedef std::priority_queue<
        std::pair<double, qint64>,  // 存储优先级（距离）和节点ID
        std::vector<std::pair<double, qint64>>,  // 内部容器
        std::greater<std::pair<double, qint64>>  // 小到大的优先级队列
        > PriorityQueue;
    // 成员变量用于存储路径长度和起点终点坐标
    QVector<QPointF> pathPoints; // 用于存储最短路径上的点
    double pathLength=0;           // 用于存储路径长度

    double calculatePathLength(const QVector<qint64> &path);
    QString generateTravelInfo(double length);


    int currentZoomIndex;  // 用于存储 zoomIndex 的成员变量




public slots:
    void setPanMode(bool enabled) {
        panMode = enabled;
    }

    // 清空地图数据
    void clear();
    void calculateAndDisplayShortestPath(const QString &startPlace, const QString &endPlace);
};

#endif // MAPWIDGET_H
