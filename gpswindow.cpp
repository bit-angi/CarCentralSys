#include "gpsWindow.h"
#include "ui_gpswindow.h"
#include <QPainter>
#include <QFile>
#include <QDomDocument>
#include <QDebug>
#include <QRegularExpression>
#include <QNetworkAccessManager> // 用于网络请求
#include <QNetworkReply> // 用于处理网络响应
#include <QFile> // 用于文件操作
#include <QDir> // 用于目录操作
#include <QFileInfo> // 用于文件信息
#include <QDebug> // 用于调试输出
#include <QUrl> // 用于URL操作
#include <QNetworkRequest> // 用于设置网络请求


GPSWindow::GPSWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GPSWindow),
    model(new QStringListModel(this))
{
    ui->setupUi(this);

    // 初始化时加载OSM文件
    connect(ui->searchLineEdit, &QLineEdit::textChanged, this, &GPSWindow::onSearchTextChanged);
    connect(ui->jisuan, &QPushButton::clicked, [this]() {
        QString startPlace = ui->startedit->text();
        QString endPlace = ui->endedit->text();
        ui->widget->calculateAndDisplayShortestPath(startPlace, endPlace);
    });
    connect(ui->panCheckBox, &QCheckBox::toggled, ui->widget, &MapWidget::setPanMode);
    setWindowFlags(Qt::FramelessWindowHint);
    ui->listView->setModel(model);

    connect(ui->widget, &MapWidget::informationRequested, this, &GPSWindow::addInformation);
    connect(ui->clearbn, &QPushButton::clicked, this, &GPSWindow::clearListView);

    ui->widget->setZoomIndex(currentZoomIndex);
    addInformation("消息盒子：===============");

    // 初始化 completer
    setupSearchCompleter();

    loadOSMFile(":/map");  // 这里替换为实际的OSM文件路径
    QString fileName = QDir::currentPath() + "/map_image.png";
    fetchAndSaveMap(fileName);

}

void GPSWindow::addInformation(const QString &info)
{
    QStringList list = model->stringList();
    list << info;  // 添加信息
    model->setStringList(list);  // 更新模型
}
void GPSWindow::clearListView() {
    model->removeRows(0, model->rowCount());
}
void GPSWindow::fetchAndSaveMap(const QString &fileName) {
    // 创建网络管理器
    QNetworkAccessManager *mapManager = new QNetworkAccessManager(this);  // 确保被妥善管理

    // 手动设置经度、纬度和缩放级别
    double m_lng = 116.17;
    double m_lat = 39.7332;
    int m_zoom = 14;
    QString ak = "yYSnHDIgAbSRlyktehYXmvlzA0s3eEhX";

    // 开始新请求
    QString host = "http://api.map.baidu.com/staticimage/v2";
    QString query_str = QString("ak=%1&width=1024&height=516&center=%2,%3&zoom=%4")
                            .arg(ak).arg(m_lng).arg(m_lat).arg(m_zoom);
    QUrl url(host + "?" + query_str);
    QNetworkRequest request(url);

    // 发送请求
    QNetworkReply *mapReply = mapManager->get(request);

    // 处理响应
    QObject::connect(mapReply, &QNetworkReply::finished, [mapReply, fileName, this]() {
        // 确保文件未被其他进程占用
        QFile mapFile(fileName);
        if (mapFile.isOpen()) {
            mapFile.close();
        }

        // 确保目标目录存在，如不存在则创建
        QFileInfo fileInfo(fileName);
        QDir dir(fileInfo.absolutePath());
        if (!dir.exists()) {
            dir.mkpath(fileInfo.absolutePath());  // 创建目录路径
        }

        // 移除已存在的地图图像，确保没有残留
        if (QFile::exists(fileName)) {
            QFile::remove(fileName);
        }

        // 读取文件流并将文件保存到指定目录
        if (mapFile.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
            mapFile.write(mapReply->readAll());
            mapFile.close();
            qDebug() << "Map image saved to" << fileName;

            // 将图像路径存储到成员变量中
            this->filePath = fileName;

            // 加载地图图像并设置到 MapWidget
            QPixmap mapPixmap(fileName);
            double zoomFactor = zoomLevels[currentZoomIndex];
            qDebug() << "Current zoom factor:" << zoomFactor;
            QPointF center(476, 239);
            if (!mapPixmap.isNull()) {
                ui->widget->setMapPixmap(mapPixmap);  // 设置到 MapWidget
                int srcX = qRound(center.x() - (center.x()) / zoomFactor);
                int srcY = qRound(center.y() - (center.y()) / zoomFactor);
                int srcWidth = mapPixmap.width() / zoomFactor;
                int srcHeight = mapPixmap.height() / zoomFactor;


                // 确保裁剪区域在图像范围内
                srcX = qMax(0, srcX);
                srcY = qMax(0, srcY);
                srcWidth = qMin(mapPixmap.width() - srcX, srcWidth);
                srcHeight = qMin(mapPixmap.height() - srcY, srcHeight);

                qDebug() << "Cropping map image with srcRect:" << QRect(srcX, srcY, srcWidth, srcHeight);

                ui->widget->setCropParameters(srcX, srcY, srcWidth, srcHeight);
                ui->widget->updateAndSetMapPixmap();

            } else {
                qDebug() << "Failed to load map image from file.";
            }
        } else {
            qDebug() << "Failed to open map file for writing.";
        }

        mapReply->deleteLater();
    });
}





GPSWindow::~GPSWindow() {
    delete ui;
}

void GPSWindow::loadOSMFile(const QString &fileName) {
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Cannot open file for reading:" << file.errorString();
        return;
    }

    QDomDocument doc;
    if (!doc.setContent(&file)) {
        qDebug() << "Error parsing XML file.";
        file.close();
        return;
    }
    file.close();

    QDomElement root = doc.documentElement();  // 获取根元素

    QVector<Coordinates> routePoints;
    QDomNodeList nodes = root.elementsByTagName("node");

    QMap<int, Coordinates> nodeMap;  // 使用节点ID作为键，存储所有节点

    // 初始化边界值为合理的极端值
    this->minLat = std::numeric_limits<double>::max();
    this->maxLat = -std::numeric_limits<double>::max();
    this->minLon = std::numeric_limits<double>::max();
    this->maxLon = -std::numeric_limits<double>::max();

    // 遍历所有节点，更新边界值
    for (int i = 0; i < nodes.count(); i++) {
        QDomElement element = nodes.at(i).toElement();
        Coordinates coord;
        coord.id = element.attribute("id").toLongLong();
        coord.lat = element.attribute("lat").toDouble();
        coord.lon = element.attribute("lon").toDouble();
        // 更新边界值
        if (coord.lat < minLat) minLat = coord.lat;
        if (coord.lat > maxLat) maxLat = coord.lat;
        if (coord.lon < minLon) minLon = coord.lon;
        if (coord.lon > maxLon) maxLon = coord.lon;

        nodeMap[coord.id] = coord;
    }

    int widgetWidth = ui->widget->width()-400;
    int widgetHeight = ui->widget->height()-150;

    // 计算屏幕上的坐标
    for (auto &coord : nodeMap) {
        double x = (coord.lon - minLon) / (maxLon - minLon) * widgetWidth+180;
        double y = widgetHeight - (coord.lat - minLat) / (maxLat - minLat) * widgetHeight+20;
        coord.screenX = x;  // 将计算的屏幕X坐标存储到 Coordinates 结构体中
        coord.screenY = y;  // 将计算的屏幕Y坐标存储到 Coordinates 结构体中

        routePoints.append(coord);
    }
    main_routePoints=routePoints;
    // 解析路信息
    QVector<Way> ways;
    QDomNodeList wayElements = root.elementsByTagName("way");

    for (int i = 0; i < wayElements.count(); i++) {
        QDomElement wayElement = wayElements.at(i).toElement();
        Way way;

        // 解析 nd 元素
        QDomNodeList ndElements = wayElement.elementsByTagName("nd");
        for (int j = 0; j < ndElements.count(); j++) {
            QDomElement ndElement = ndElements.at(j).toElement();
            qint64 refId = ndElement.attribute("ref").toLongLong();
            if (nodeMap.contains(refId)) {
                way.nodes.append(nodeMap[refId]);
            }
        }

        // 解析所有 tag 标签
        QDomNodeList tagElements = wayElement.elementsByTagName("tag");
        QStringList tagInfoList;
        if (tagElements.count() > 2) {
            for (int k = 0; k < tagElements.count(); k++) {
                QDomElement tagElement = tagElements.at(k).toElement();
                QString key = tagElement.attribute("k");
                QString value = tagElement.attribute("v");
                bool containsChinese = false;
                for (QChar c : value) {
                    if (c.unicode() >= 0x4E00 && c.unicode() <= 0x9FFF) {
                        containsChinese = true;
                        break;
                    }
                }
                if (containsChinese) {
                    tagInfoList.append(value);
                }
            }
            way.tagInfo = tagInfoList.join(", ");
            qDebug() << way.tagInfo;
        }

        if (!way.nodes.isEmpty()) {
            ways.append(way);
        }
    }

    allWays = ways;  // 将解析后的路信息保存到成员变量中

    // 设置地图边界，初始化但不绘制
    ui->widget->setBounds(minLat, maxLat, minLon, maxLon);

    // ui->widget->setRoutePoints(routePoints);
    ui->widget->setWays(ways);  // 设置路径信息
}


void GPSWindow::on_zoomInButton_clicked() {
    qDebug() << "Zoom In Button Clicked";
    if (currentZoomIndex <9) {
        currentZoomIndex++;
        ui->widget->setZoomIndex(currentZoomIndex);
        updateMap();
    }
}

void GPSWindow::on_zoomOutButton_clicked() {
    qDebug() << "Zoom In Button Clicked";
    if (currentZoomIndex > 0) {
        currentZoomIndex--;
        ui->widget->setZoomIndex(currentZoomIndex);
        updateMap();
    }
}

void GPSWindow::setupSearchCompleter() {
    // 创建独立的 QStringListModel
    QStringListModel *searchModel = new QStringListModel(this);
    QStringListModel *startModel = new QStringListModel(this);
    QStringListModel *endModel = new QStringListModel(this);

    // 创建独立的 QCompleter 并设置模型
    QCompleter *searchCompleter = new QCompleter(this);
    searchCompleter->setCaseSensitivity(Qt::CaseInsensitive);
    searchCompleter->setCompletionMode(QCompleter::PopupCompletion);
    searchCompleter->setFilterMode(Qt::MatchContains);
    searchCompleter->setModel(searchModel);

    QCompleter *startCompleter = new QCompleter(this);
    startCompleter->setCaseSensitivity(Qt::CaseInsensitive);
    startCompleter->setCompletionMode(QCompleter::PopupCompletion);
    startCompleter->setFilterMode(Qt::MatchContains);
    startCompleter->setModel(startModel);

    QCompleter *endCompleter = new QCompleter(this);
    endCompleter->setCaseSensitivity(Qt::CaseInsensitive);
    endCompleter->setCompletionMode(QCompleter::PopupCompletion);
    endCompleter->setFilterMode(Qt::MatchContains);
    endCompleter->setModel(endModel);

    // 将 QCompleter 关联到 QLineEdit
    ui->searchLineEdit->setCompleter(searchCompleter);
    ui->startedit->setCompleter(startCompleter);
    ui->endedit->setCompleter(endCompleter);

    // 连接每个输入框的 textChanged 信号到对应的槽函数
    connect(ui->searchLineEdit, &QLineEdit::textChanged, this, &GPSWindow::onSearchTextChanged);
    connect(ui->startedit, &QLineEdit::textChanged, this, &GPSWindow::onStartEditTextChanged);
    connect(ui->endedit, &QLineEdit::textChanged, this, &GPSWindow::onEndEditTextChanged);
}

void GPSWindow::onSearchTextChanged(const QString &text) {
    updateSuggestions(text, qobject_cast<QStringListModel *>(ui->searchLineEdit->completer()->model()));
    ui->widget->setFilteredWays(filteredWays);
}

void GPSWindow::onStartEditTextChanged(const QString &text) {
    updateSuggestions(text, qobject_cast<QStringListModel *>(ui->startedit->completer()->model()));
}

void GPSWindow::onEndEditTextChanged(const QString &text) {
    updateSuggestions(text, qobject_cast<QStringListModel *>(ui->endedit->completer()->model()));
}

void GPSWindow::updateSuggestions(const QString &text, QStringListModel *model) {
    filteredWays.clear();
    QStringList suggestions;
    QSet<QString> uniqueSuggestions;  // 使用 QSet 来自动去重

    for (const auto &way : allWays) {
        if (way.tagInfo.contains(text, Qt::CaseInsensitive) && !text.isEmpty()) {
            filteredWays.append(way);

            // 只取第一个逗号前面的内容
            QString firstPartOfTagInfo = way.tagInfo.section(',', 0, 0);

            // 如果这个内容是新的（不重复），则添加到建议列表中
            if (!uniqueSuggestions.contains(firstPartOfTagInfo)) {
                uniqueSuggestions.insert(firstPartOfTagInfo);
                suggestions.append(firstPartOfTagInfo);
            }
        }
    }

    // 更新 completer 的模型
    if (model) {
        model->setStringList(suggestions);
    }
}
void GPSWindow::updateMap() {
    double zoomFactor = zoomLevels[currentZoomIndex];
    qDebug() << "Current zoom factor:" << zoomFactor;

    // 获取窗口的中心点
    QPointF center(476, 239);

    QVector<Coordinates> tempRoutePoints = main_routePoints;
    QVector<Way> tempAllWays = allWays;
    QVector<Way> tempFilteredWays = filteredWays;
    Coordinates pos=ui->widget->clickPos;


    // 缩放主路线点并直接赋值到临时变量中
    for (auto &coord : tempRoutePoints) {
        coord.screenX = (coord.screenX - center.x()) * zoomFactor + center.x();
        coord.screenY = (coord.screenY - center.y()) * zoomFactor + center.y();
    }

    // 缩放allWays中的每个Way的点并直接赋值到临时变量中
    for (auto &way : tempAllWays) {
        for (auto &coord : way.nodes) {
            coord.screenX = (coord.screenX - center.x()) * zoomFactor + center.x();
            coord.screenY = (coord.screenY - center.y()) * zoomFactor + center.y();
        }
    }

    // 缩放filteredWays中的每个Way的点并直接赋值到临时变量中
    for (auto &way : tempFilteredWays) {
        for (auto &coord : way.nodes) {
            coord.screenX = (coord.screenX - center.x()) * zoomFactor + center.x();
            coord.screenY = (coord.screenY - center.y()) * zoomFactor + center.y();
        }
    }

    // 缩放点击点
    if (!ui->widget->clickPos.isEmpty()) {
        ui->widget->clickPos.screenX = (ui->widget->oringnal_clickpos.screenX - center.x()) * zoomFactor + center.x();
        ui->widget->clickPos.screenY = (ui->widget->oringnal_clickpos.screenY - center.y()) * zoomFactor + center.y();
    }

    // 加载地图图片
    QPixmap mapPixmap(filePath);
    if (mapPixmap.isNull()) {
        qDebug() << "Failed to load map image from file:" << filePath;
        return;
    }
    qDebug() << "Map image loaded successfully.";

    int srcX = qRound(center.x() - (center.x()) / zoomFactor);
    int srcY = qRound(center.y() - (center.y()) / zoomFactor);
    int srcWidth = mapPixmap.width() / zoomFactor;
    int srcHeight = mapPixmap.height() / zoomFactor;


    // 确保裁剪区域在图像范围内
    srcX = qMax(0, srcX);
    srcY = qMax(0, srcY);
    srcWidth = qMin(mapPixmap.width() - srcX, srcWidth);
    srcHeight = qMin(mapPixmap.height() - srcY, srcHeight);

    qDebug() << "Cropping map image with srcRect:" << QRect(srcX, srcY, srcWidth, srcHeight);

    ui->widget->setCropParameters(srcX, srcY, srcWidth, srcHeight);
    ui->widget->updateAndSetMapPixmap();
    ui->widget->clear();
    ui->widget->setWays(tempAllWays);        // 更新缩放后的路线
    ui->widget->setFilteredWays(tempFilteredWays);
}






