#include "MapWidget.h"
#include <QPainter>
#include <QToolTip>
#include <QMouseEvent>
#include <QDebug>
#include <cmath>

MapWidget::MapWidget(QWidget *parent)
    : QWidget(parent), minLat(0), maxLat(0), minLon(0), maxLon(0),panMode(false) {
    setMouseTracking(true);  // 启用鼠标跟踪
    clickPos = Coordinates();
}

void MapWidget::clear() {
    filteredWays.clear();
    routePoints.clear();
    ways.clear();
    wayMarkers.clear();
    update();  // 触发重绘事件
}
void MapWidget::setMapPixmap(const QPixmap &pixmap) {
    m_originalPixmap = pixmap;
    update();  // 触发重绘
}
void MapWidget::setCropParameters(int x, int y, int width, int height) {
    cropX = x;
    cropY = y;
    cropWidth = width;
    cropHeight = height;
    update();  // Ensure the widget is updated with the new parameters
}

void MapWidget::updateAndSetMapPixmap() {
    // Ensure the original map image is available
    if (m_originalPixmap.isNull()) {
        qDebug() << "Original map image is not set.";
        return;
    }

    // Define source rectangle (cropping area)
    QRect srcRect(cropX - mapOffset.x()/1.8, cropY - mapOffset.y()/1.8, cropWidth, cropHeight);

    // Ensure source rectangle is within the bounds of the original image
    srcRect.setX(qMax(0, srcRect.x()));
    srcRect.setY(qMax(0, srcRect.y()));
    srcRect.setWidth(qMin(m_originalPixmap.width() - srcRect.x(), srcRect.width()));
    srcRect.setHeight(qMin(m_originalPixmap.height() - srcRect.y(), srcRect.height()));

    // Define destination rectangle (drawing area in the widget)
    QRect dstRect(0, 0, width(), height());

    // Create a new QPixmap for the scaled image
    QPixmap scaledPixmap(dstRect.size());
    QPainter painter(&scaledPixmap);

    // Fill the background with a color (optional, e.g., white)
    painter.fillRect(scaledPixmap.rect(), Qt::white);

    // Draw the cropped part of the original map image onto the new QPixmap
    painter.drawPixmap(dstRect, m_originalPixmap, srcRect);

    // Set the scaled image as the map pixmap
    m_mapPixmap = scaledPixmap;

}


void MapWidget::setRoutePoints(const QVector<Coordinates> &points) {
    routePoints = points;
    update();  // 请求重新绘制
}

void MapWidget::setWays(const QVector<Way> &ways) {
    this->ways = ways;
    if(graph.isEmpty())
    {
         buildGraph();  // 在设置新路径时重新构建图
    }
    update();  // 请求重新绘制
}

void MapWidget::setFilteredWays(const QVector<Way> &filteredWays) {
    this->filteredWays = filteredWays;
    wayMarkers.clear();  // 清空之前的标记
    update();  // 触发重绘
}

void MapWidget::setBounds(double minLat, double maxLat, double minLon, double maxLon) {
    this->minLat = minLat;
    this->maxLat = maxLat;
    this->minLon = minLon;
    this->maxLon = maxLon;
    update();  // 请求重新绘制
}

void MapWidget::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setPen(Qt::white);
    painter.setBrush(Qt::white);

    updateAndSetMapPixmap();
    painter.drawPixmap(0, 0, m_mapPixmap);  // 绘制整个 QPixmap

    // 设置系数来调整移动速度
    const double moveSpeedFactor = 0.85;  // 根据需要调整此系数

    // 绘制所有路线上的点，添加偏移量
    for (const Coordinates &point : routePoints) {
        painter.drawEllipse(QPointF(point.screenX + mapOffset.x() * moveSpeedFactor,
                                    point.screenY + mapOffset.y() * moveSpeedFactor), 2, 2);
    }

    // 绘制所有道路，添加偏移量
    painter.setPen(Qt::blue);
    for (const auto &way : ways) {
        for (int i = 0; i < way.nodes.size() - 1; i++) {
            const Coordinates &start = way.nodes[i];
            const Coordinates &end = way.nodes[i + 1];
            painter.drawLine(QPointF(start.screenX + mapOffset.x() * moveSpeedFactor,
                                     start.screenY + mapOffset.y() * moveSpeedFactor),
                             QPointF(end.screenX + mapOffset.x() * moveSpeedFactor,
                                     end.screenY + mapOffset.y() * moveSpeedFactor));
        }
    }

    // 绘制用户点击的位置，添加偏移量
    if (clickPos.isValid)  {
        painter.setBrush(Qt::red);
        painter.drawEllipse(QPointF(clickPos.screenX + mapOffset.x() * moveSpeedFactor,
                                    clickPos.screenY + mapOffset.y() * moveSpeedFactor), 5, 5);

        // 获取 tagInfo 中第一个逗号前的内容
        QString firstPartOfTagInfo = closestWay.tagInfo.section(',', 0, 0);
    }

    // 只绘制搜索结果中的第一个点，添加偏移量
    painter.setBrush(Qt::red);
    for (const auto &way : filteredWays) {
        if (!way.nodes.isEmpty() && !way.tagInfo.isEmpty()) {
            const Coordinates &firstNode = way.nodes.first();
            double x = firstNode.screenX + mapOffset.x() * moveSpeedFactor;
            double y = firstNode.screenY + mapOffset.y() * moveSpeedFactor;
            painter.drawEllipse(QPointF(x, y), 4, 4);

            // 组合地址信息
            QString firstPartOfTagInfo = way.tagInfo.section(',', 0, 0);
            wayMarkers.append(qMakePair(QPointF(x, y), firstPartOfTagInfo));
        }
    }

    // 绘制最短路径，添加偏移量
    if (!path.isEmpty()) {
        painter.setPen(QPen(Qt::green, 4));  // 使用绿色线条绘制路径
        for (int i = 0; i < path.size() - 1; ++i) {
            qint64 startId = path[i];
            qint64 endId = path[i + 1];

            // 找到起点和终点的屏幕坐标
            const Coordinates *startCoord = nullptr;
            const Coordinates *endCoord = nullptr;
            for (const auto &way : ways) {
                for (int j = 0; j < way.nodes.size(); ++j) {
                    if (way.nodes[j].id == startId) startCoord = &way.nodes[j];
                    if (way.nodes[j].id == endId) endCoord = &way.nodes[j];
                }
            }

            if (startCoord && endCoord) {
                painter.drawLine(QPointF(startCoord->screenX + mapOffset.x() * moveSpeedFactor,
                                         startCoord->screenY + mapOffset.y() * moveSpeedFactor),
                                 QPointF(endCoord->screenX + mapOffset.x() * moveSpeedFactor,
                                         endCoord->screenY + mapOffset.y() * moveSpeedFactor));
            }
        }

        // 绘制路径的起点和终点，添加偏移量
        if (path.size() > 0) {
            painter.setBrush(Qt::yellow);
            const Coordinates *startCoord = nullptr;
            const Coordinates *endCoord = nullptr;
            for (const auto &way : ways) {
                for (int j = 0; j < way.nodes.size(); ++j) {
                    if (way.nodes[j].id == path.first()) startCoord = &way.nodes[j];
                    if (way.nodes[j].id == path.last()) endCoord = &way.nodes[j];
                }
            }

            if (startCoord) {
                painter.drawEllipse(QPointF(startCoord->screenX + mapOffset.x() * moveSpeedFactor,
                                            startCoord->screenY + mapOffset.y() * moveSpeedFactor), 8, 8);
            }
            if (endCoord) {
                painter.drawEllipse(QPointF(endCoord->screenX + mapOffset.x() * moveSpeedFactor,
                                            endCoord->screenY + mapOffset.y() * moveSpeedFactor), 5, 5);
            }
        }
    }
}


void MapWidget::mouseMoveEvent(QMouseEvent *event) {
    if (panMode && event->buttons() & Qt::LeftButton&&currentZoomIndex>=2) {
        if(currentZoomIndex<=1){
            emit informationRequested("提示：请放大后尝试。");
            return;
        }
        QPointF delta = event->pos() - lastMousePos;  // 计算移动的距离
        mapOffset += delta;  // 更新地图的偏移量
        lastMousePos = event->pos();  // 更新最后一次鼠标位置
        update();  // 重新绘制地图
    }else{
        QPointF mousePos = event->pos();

        for (const auto &marker : wayMarkers) {
            QPointF markerPos = marker.first;
            QString addressInfo = marker.second;

            if (QLineF(mousePos, markerPos).length() < 5) {  // 增加距离阈值
                QToolTip::showText(event->globalPos(), addressInfo, this);
                return;
            }
        }

        QToolTip::hideText();
    }

}

void MapWidget::mousePressEvent(QMouseEvent *event) {
    if (panMode) {
        if(currentZoomIndex<=1){
            emit informationRequested("提示：请放大后尝试。");
            return;
        }
        lastMousePos = event->pos();  // 记录鼠标按下时的位置
    } else {
        // 原有点击事件处理代码
        clickPos.screenX = event->pos().x();
        clickPos.screenY = event->pos().y();
        oringnal_clickpos.screenX=event->pos().x();
        oringnal_clickpos.screenY=event->pos().y();
        oringnal_clickpos.isValid=true;
        clickPos.isValid = true;  // 设置点击位置为有效
        findClosestWay(oringnal_clickpos);
        update();
    }
}

void MapWidget::findClosestWay(const Coordinates &clickPos) {
    double minDistance = std::numeric_limits<double>::max();
    closestWay = Way();

    for (const Way &way : ways) {
        if (way.tagInfo.isEmpty()) {
            continue;
        }
        for (int i = 0; i < way.nodes.size() - 1; ++i) {
            const Coordinates &start = way.nodes[i];
            const Coordinates &end = way.nodes[i + 1];

            QPointF startPoint(start.screenX, start.screenY);
            QPointF endPoint(end.screenX, end.screenY);
            QPointF closestPoint;
            double distance;

            double lengthSquared = std::pow(endPoint.x() - startPoint.x(), 2) + std::pow(endPoint.y() - startPoint.y(), 2);
            if (lengthSquared != 0) {
                double t = ((clickPos.screenX - startPoint.x()) * (endPoint.x() - startPoint.x()) +
                            (clickPos.screenY - startPoint.y()) * (endPoint.y() - startPoint.y())) / lengthSquared;
                t = std::clamp(t, 0.0, 1.0);
                closestPoint = startPoint + t * (endPoint - startPoint);
            } else {
                closestPoint = startPoint;
            }

            distance = std::sqrt(std::pow(closestPoint.x() - clickPos.screenX, 2) + std::pow(closestPoint.y() - clickPos.screenY, 2));
            if (distance < minDistance) {
                minDistance = distance;
                closestWay = way;
            }
        }
    }
    QString firstPartOfTagInfo = closestWay.tagInfo.section(',', 0, 0);
    QString s = QString("点击位置：%1").arg(firstPartOfTagInfo);
    emit informationRequested(s);

}


void MapWidget::buildGraph() {
    for (const Way &way : ways) {
        for (int i = 0; i < way.nodes.size() - 1; ++i) {
            qint64 startId = way.nodes[i].id;
            qint64 endId = way.nodes[i + 1].id;

            double distance = calculateDistance(way.nodes[i], way.nodes[i + 1]);

            graph[startId][endId] = distance;
            graph[endId][startId] = distance;  // 假设图是无向的

            qDebug() << QString("边(%1 -> %2) 的距离: %3").arg(startId).arg(endId).arg(distance);
        }
    }
    qDebug() << "图构建完成。";
}

double MapWidget::calculateDistance(const Coordinates &start, const Coordinates &end) {
    // 地球半径（单位为米）
    const double earthRadius = 6371000;  // 地球半径，单位为米

    // 经纬度转换为弧度
    double lat1Rad = qDegreesToRadians(start.lat);
    double lon1Rad = qDegreesToRadians(start.lon);
    double lat2Rad = qDegreesToRadians(end.lat);
    double lon2Rad = qDegreesToRadians(end.lon);

    // Haversine 公式计算球面距离
    double dLat = lat2Rad - lat1Rad;
    double dLon = lon2Rad - lon1Rad;
    double a = std::sin(dLat / 2) * std::sin(dLat / 2) +
               std::cos(lat1Rad) * std::cos(lat2Rad) *
                   std::sin(dLon / 2) * std::sin(dLon / 2);
    double c = 2 * std::atan2(std::sqrt(a), std::sqrt(1 - a));

    double distance = earthRadius * c;  // 计算距离，单位为米

    qDebug() << QString("计算距离: 起点(%1, %2), 终点(%3, %4), 距离: %5 米")
                    .arg(start.lat).arg(start.lon)
                    .arg(end.lat).arg(end.lon)
                    .arg(distance);

    return distance;
}


QVector<qint64> MapWidget::findShortestPath(const QString &startPlace, const QString &endPlace) {
    qDebug() << QString("查找最短路径: 起点: %1, 终点: %2").arg(startPlace).arg(endPlace);
    qint64 startId = findNodeIdByPlaceName(startPlace);
    qint64 endId = findNodeIdByPlaceName(endPlace);

    if (startId == -1 || endId == -1) {
        qDebug() << "无法找到地名：" << (startId == -1 ? startPlace : endPlace);
        return {};  // 如果无法找到地名，返回空路径
    }

    QVector<qint64> path = dijkstraShortestPath(startId, endId);
    // qDebug() << QString("最短路径计算完成, 路径节点: %1").arg(path.join(", "));

    return path;
}

qint64 MapWidget::findNodeIdByPlaceName(const QString &placeName) {
    qDebug() << QString("查找地名: %1").arg(placeName);

    for (const Way &way : ways) {
        if (way.tagInfo.contains(placeName)) {
            if (!way.nodes.isEmpty()) {
                qint64 nodeId = way.nodes.first().id;
                qDebug() << QString("找到地名 '%1' 对应的节点 ID: %2").arg(placeName).arg(nodeId);
                return nodeId;  // 返回第一个节点的ID
            }
        }
    }

    qDebug() << QString("未找到地名 '%1'").arg(placeName);
    return -1;  // 返回 -1 表示没有找到对应的地名
}

QVector<qint64> MapWidget::dijkstraShortestPath(qint64 startId, qint64 endId) {
    qDebug() << QString("使用 Dijkstra 算法计算最短路径: 起点 ID: %1, 终点 ID: %2").arg(startId).arg(endId);

    QMap<qint64, double> distances;
    QMap<qint64, qint64> previousNodes;
    QSet<qint64> unvisitedNodes;
    PriorityQueue queue;  // 使用 std::priority_queue

    // 初始化距离
    for (const auto &node : graph.keys()) {
        distances[node] = std::numeric_limits<double>::infinity();
        previousNodes[node] = -1;
        unvisitedNodes.insert(node);
    }
    distances[startId] = 0;
    queue.push({0, startId});  // 初始节点入队

    while (!queue.empty()) {
        qint64 currentId = queue.top().second;
        queue.pop();

        qDebug() << QString("处理节点 ID: %1").arg(currentId);

        if (currentId == endId) {
            qDebug() << "到达终点 ID: " << endId;
            break;
        }

        if (!unvisitedNodes.contains(currentId)) continue;
        unvisitedNodes.remove(currentId);

        for (const auto &neighbor : graph[currentId].keys()) {
            double alt = distances[currentId] + graph[currentId][neighbor];
            if (alt < distances[neighbor]) {
                distances[neighbor] = alt;
                previousNodes[neighbor] = currentId;
                queue.push({alt, neighbor});

                qDebug() << QString("更新邻居节点 ID: %1, 距离: %2").arg(neighbor).arg(alt);
            }
        }
    }

    QVector<qint64> path;
    for (qint64 at = endId; at != -1; at = previousNodes[at]) {
        path.prepend(at);
        qDebug() << QString("路径节点: %1").arg(at);
    }

    if (path.isEmpty()) {
        qDebug() << "未找到路径。";
    } else {
        qDebug() << "路径计算完成。";
    }
    calculatePathLength(path);

    return path;
}

void MapWidget::calculateAndDisplayShortestPath(const QString &startPlace, const QString &endPlace) {
    if(startPlace.isEmpty()||endPlace.isEmpty())
    {
        return;
    }
    QString s1=QString("从起点: %1,\n").arg(startPlace);
    QString s2=QString("到终点: %2。").arg(endPlace);
    emit informationRequested(s1+s2);
    qint64 startId = findNodeIdByPlaceName(startPlace);
    qint64 endId = findNodeIdByPlaceName(endPlace);

    if (startId == -1 || endId == -1) {
        qDebug() << "Invalid place name.";
        return;
    }

    path = dijkstraShortestPath(startId, endId);

    if (path.isEmpty()) {
        qDebug() << "No path found.";
        return;
    }

    qDebug() << "Path found:" << path;
    update();  // 触发重绘，以显示路径
}


double MapWidget::calculatePathLength(const QVector<qint64> &path) {
    double length = 0.0;
    for (int i = 0; i < path.size() - 1; ++i) {
        qint64 startId = path[i];
        qint64 endId = path[i + 1];
        for (const Way &way : ways) {
            for (int j = 0; j < way.nodes.size() - 1; ++j) {
                if ((way.nodes[j].id == startId && way.nodes[j + 1].id == endId) ||
                    (way.nodes[j].id == endId && way.nodes[j + 1].id == startId)) {
                    length += calculateDistance(way.nodes[j], way.nodes[j + 1]);
                    break;
                }
            }
        }
    }
    if(length==0){
        emit informationRequested("当前输入无法规划路线");
    }else{
        emit informationRequested("预计：\n");
        QString s=generateTravelInfo(length);
        emit informationRequested(s);
    }
    return length;
}
QString MapWidget::generateTravelInfo(double length) {
    // 将长度转换为公里
    double lengthKm = length / 1000.0;

    // 计算步行预计时间（假设步行速度为每小时 5 公里）
    double walkingSpeedKph = 5.0;
    double walkingTimeHours = lengthKm / walkingSpeedKph;
    double walkingTimeMinutes = walkingTimeHours * 60;
    QString walkingTime = QString("步行预计时间: %1 分钟").arg(walkingTimeMinutes, 0, 'f', 0);

    // 计算打车预计费用（假设打车速度为每小时 40 公里，费用为每公里 2 元，起步价为 10 元）
    double taxiFarePerKm = 2.0;
    double baseFare = 10.0;
    double taxiCost = baseFare + (lengthKm * taxiFarePerKm);
    QString taxiCostInfo = QString("打车预计费用: %1 元").arg(taxiCost, 0, 'f', 2);

    // 构建信息字符串
    QString lengthInfo = QString("路程长度: %1 公里").arg(lengthKm, 0, 'f', 2);
    QString newInfo = lengthInfo + "\n" + walkingTime + "\n" + taxiCostInfo;

    return newInfo;
}
void MapWidget::setZoomIndex(int zoomIndex) {
    currentZoomIndex = zoomIndex;
}

