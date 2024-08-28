#include "mainwindow2.h"
#include <QContextMenuEvent>
#include <QDebug>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMenu>
#include <QMessageBox>
#include <QNetworkReply>
#include <QPainter>
//#include "widget.h"
#include "ui_mainwindow2.h"
#include "weathertool.h"

// 温度曲线相关的宏
#define INCREMENT     3   // 温度曲线像素增量
#define POINT_RADIUS  3   // 曲线描点的大小
#define TEXT_OFFSET_X 12  // 温度文本相对于点的偏移
#define TEXT_OFFSET_Y 10  // 温度文本相对于点的偏移

MainWindow2::MainWindow2(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow2)
{
    ui->setupUi(this);
    this->wid = new Widget();
//    wid->show();
//    audio = new Audio;
//    connect(this->wid,&Widget::newSignal,this,[=] (QString str) {
//        qDebug() << "9999";
//        QString s = WeatherTool::hasACity(str);
//        if (s != NULL)
//            this->getWeatherInfo(s);
//    });
    setAttribute(Qt::WA_TranslucentBackground);
    setWindowFlags(Qt::FramelessWindowHint);
    // 1. 设置窗口属性
    setWindowFlag(Qt::FramelessWindowHint);  // 无边框
    setFixedSize(width(), height());         // 固定窗口大小

    // 2. 右键菜单：退出程序
    mExitMenu = new QMenu(this);
    mExitAct = new QAction();
    mExitAct->setText(tr("退出"));
    mExitAct->setIcon(QIcon(":/res/close.png"));
    mExitMenu->addAction(mExitAct);

    connect(mExitAct, &QAction::triggered, this, [=]() { qApp->exit(0); });

    // 3. UI初始化
    // 将控件放到数组里面，方便使用循环进行处理
    // 星期和日期
    mWeekList << ui->lblWeek0 << ui->lblWeek1 << ui->lblWeek2 << ui->lblWeek3 << ui->lblWeek4 << ui->lblWeek5;
    mDateList << ui->lblDate0 << ui->lblDate1 << ui->lblDate2 << ui->lblDate3 << ui->lblDate4 << ui->lblDate5;

    // 天气和天气图标
    mTypeList << ui->lblType0 << ui->lblType1 << ui->lblType2 << ui->lblType3 << ui->lblType4 << ui->lblType5;
    mTypeIconList << ui->lblTypeIcon0 << ui->lblTypeIcon1 << ui->lblTypeIcon2 << ui->lblTypeIcon3 << ui->lblTypeIcon4 << ui->lblTypeIcon5;

    // 天气指数
    mAqiList << ui->lblQuality0 << ui->lblQuality1 << ui->lblQuality2 << ui->lblQuality3 << ui->lblQuality4 << ui->lblQuality5;

    // 风向和风力
    mFxList << ui->lblFx0 << ui->lblFx1 << ui->lblFx2 << ui->lblFx3 << ui->lblFx4 << ui->lblFx5;
    mFlList << ui->lblFl0 << ui->lblFl1 << ui->lblFl2 << ui->lblFl3 << ui->lblFl4 << ui->lblFl5;

    mTypeMap.insert("暴雪", ":/res/type/BaoXue.png");
    mTypeMap.insert("暴雨", ":/res/type/BaoYu.png");
    mTypeMap.insert("暴雨到大暴雨", ":/res/type/BaoYuDaoDaBaoYu.png");
    mTypeMap.insert("大暴雨", ":/res/type/DaBaoYu.png");
    mTypeMap.insert("大暴雨到特大暴雨", ":/res/type/DaBaoYuDaoTeDaBaoYu.png");
    mTypeMap.insert("大到暴雪", ":/res/type/DaDaoBaoXue.png");
    mTypeMap.insert("大雪", ":/res/type/DaXue.png");
    mTypeMap.insert("大雨", ":/res/type/DaYu.png");
    mTypeMap.insert("冻雨", ":/res/type/DongYu.png");
    mTypeMap.insert("多云", ":/res/type/DuoYun.png");
    mTypeMap.insert("浮沉", ":/res/type/FuChen.png");
    mTypeMap.insert("雷阵雨", ":/res/type/LeiZhenYu.png");
    mTypeMap.insert("雷阵雨伴有冰雹", ":/res/type/LeiZhenYuBanYouBingBao.png");
    mTypeMap.insert("霾", ":/res/type/Mai.png");
    mTypeMap.insert("强沙尘暴", ":/res/type/QiangShaChenBao.png");
    mTypeMap.insert("晴", ":/res/type/Qing.png");
    mTypeMap.insert("沙尘暴", ":/res/type/ShaChenBao.png");
    mTypeMap.insert("特大暴雨", ":/res/type/TeDaBaoYu.png");
    mTypeMap.insert("undefined", ":/res/type/undefined.png");
    mTypeMap.insert("雾", ":/res/type/Wu.png");
    mTypeMap.insert("小到中雪", ":/res/type/XiaoDaoZhongXue.png");
    mTypeMap.insert("小到中雨", ":/res/type/XiaoDaoZhongYu.png");
    mTypeMap.insert("小雪", ":/res/type/XiaoXue.png");
    mTypeMap.insert("小雨", ":/res/type/XiaoYu.png");
    mTypeMap.insert("雪", ":/res/type/Xue.png");
    mTypeMap.insert("扬沙", ":/res/type/YangSha.png");
    mTypeMap.insert("阴", ":/res/type/Yin.png");
    mTypeMap.insert("雨", ":/res/type/Yu.png");
    mTypeMap.insert("雨夹雪", ":/res/type/YuJiaXue.png");
    mTypeMap.insert("阵雪", ":/res/type/ZhenXue.png");
    mTypeMap.insert("阵雨", ":/res/type/ZhenYu.png");
    mTypeMap.insert("中到大雪", ":/res/type/ZhongDaoDaXue.png");
    mTypeMap.insert("中到大雨", ":/res/type/ZhongDaoDaYu.png");
    mTypeMap.insert("中雪", ":/res/type/ZhongXue.png");
    mTypeMap.insert("中雨", ":/res/type/ZhongYu.png");

    // 4. 网络请求
    mNetAccessManager = new QNetworkAccessManager(this);
    connect(mNetAccessManager, &QNetworkAccessManager::finished, this, &MainWindow2::onReplied);
    //    getWeatherInfo("101010100");    // 101010100 是北京的城市编码
    getWeatherInfo("广州");  // 101280101 是广州的城市编码

    // 5. 安装事件过滤器
    ui->lblHighCurve->installEventFilter(this);
    ui->lblLowCurve->installEventFilter(this);
}

MainWindow2::~MainWindow2()
{
    delete ui;
}

bool MainWindow2::eventFilter(QObject* watched, QEvent* event)
{
    if ( watched == ui->lblHighCurve && event->type() == QEvent::Paint ) {
        paintHighCurve();
    }
    if ( watched == ui->lblLowCurve && event->type() == QEvent::Paint ) {
        paintLowCurve();
    }
    return QWidget::eventFilter(watched, event);
}

void MainWindow2::paintHighCurve()
{
    QPainter painter(ui->lblHighCurve);

    // 抗锯齿
    painter.setRenderHint(QPainter::Antialiasing, true);

    // 1. 获取 x 轴坐标
    int pointX[6] = {0};
    for ( int i = 0; i < 6; i++ ) {
        pointX[i] = mWeekList[i]->pos().x() + mWeekList[i]->width() / 2;
    }

    // 2. 获取 y 轴坐标

    //  int temp[6]   = {0};
    int tempSum = 0;
    int tempAverage = 0;

    // 2.1 计算平均值
    for ( int i = 0; i < 6; i++ ) {
        tempSum += mDay[i].high;
    }

    tempAverage = tempSum / 6;  // 最高温平均值

    qDebug() << "paintHighCurve" << tempAverage;

    // 2.2 计算 y 轴坐标
    int pointY[6] = {0};
    int yCenter = ui->lblHighCurve->height() / 2;
    for ( int i = 0; i < 6; i++ ) {
        pointY[i] = yCenter - ((mDay[i].high - tempAverage) * INCREMENT);
    }

    // 3. 开始绘制
    // 3.1 初始化画笔
    QPen pen = painter.pen();
    pen.setWidth(1);                    //设置画笔宽度为1
    pen.setColor(QColor(255, 170, 0));  //设置颜色
    painter.save();

    painter.setPen(pen);
    painter.setBrush(QColor(255, 170, 0));  //设置画刷颜色

    // 3.2 画点、写文本
    for ( int i = 0; i < 6; i++ ) {
        painter.drawEllipse(QPoint(pointX[i], pointY[i]), POINT_RADIUS, POINT_RADIUS);
        painter.drawText(QPoint(pointX[i] - TEXT_OFFSET_X, pointY[i] - TEXT_OFFSET_Y), QString::number(mDay[i].high) + "°");
    }

    // 3.3 绘制曲线
    for ( int i = 0; i < 5; i++ ) {
        if ( i == 0 ) {
            pen.setStyle(Qt::DotLine);  //虚线
            painter.setPen(pen);
        } else {
            pen.setStyle(Qt::SolidLine);  // 实线
            painter.setPen(pen);
        }
        painter.drawLine(pointX[i], pointY[i], pointX[i + 1], pointY[i + 1]);
    }

    painter.restore();
}

void MainWindow2::paintLowCurve()
{
    QPainter painter(ui->lblLowCurve);

    // 抗锯齿
    painter.setRenderHint(QPainter::Antialiasing, true);

    // 1. 获取 x 轴坐标
    int pointX[6] = {0};
    for ( int i = 0; i < 6; i++ ) {
        pointX[i] = mWeekList[i]->pos().x() + mWeekList[i]->width() / 2;
    }

    // 2. 获取 y 轴坐标

    //  int temp[6]   = {0};
    int tempSum = 0;
    int tempAverage = 0;

    // 2.1 计算平均值
    for ( int i = 0; i < 6; i++ ) {
        tempSum += mDay[i].low;
    }

    tempAverage = tempSum / 6;  // 最高温平均值

    qDebug() << "paintLowCurve" << tempAverage;

    // 2.2 计算 y 轴坐标
    int pointY[6] = {0};
    int yCenter = ui->lblLowCurve->height() / 2;
    for ( int i = 0; i < 6; i++ ) {
        pointY[i] = yCenter - ((mDay[i].low - tempAverage) * INCREMENT);
    }

    // 3. 开始绘制
    // 3.1 初始化画笔
    QPen pen = painter.pen();
    pen.setWidth(1);                    //设置画笔宽度为1
    pen.setColor(QColor(0, 255, 255));  //设置颜色
    painter.save();

    painter.setPen(pen);
    painter.setBrush(QColor(0, 255, 255));  //设置画刷颜色

    // 3.2 画点、写文本
    for ( int i = 0; i < 6; i++ ) {
        painter.drawEllipse(QPoint(pointX[i], pointY[i]), POINT_RADIUS, POINT_RADIUS);
        painter.drawText(QPoint(pointX[i] - TEXT_OFFSET_X, pointY[i] - TEXT_OFFSET_Y), QString::number(mDay[i].low) + "°");
    }

    // 3.3 绘制曲线
    for ( int i = 0; i < 5; i++ ) {
        if ( i == 0 ) {
            pen.setStyle(Qt::DotLine);  //虚线
            painter.setPen(pen);
        } else {
            pen.setStyle(Qt::SolidLine);  // 实线
            painter.setPen(pen);
        }
        painter.drawLine(pointX[i], pointY[i], pointX[i + 1], pointY[i + 1]);
    }

    painter.restore();
}

void MainWindow2::contextMenuEvent(QContextMenuEvent* event)
{
    mExitMenu->exec(QCursor::pos());
    event->accept();
}

void MainWindow2::mousePressEvent(QMouseEvent* event)
{
    qDebug() << "窗口左上角：" << this->pos() << ", 鼠标坐标点：" << event->globalPos();
    mOffset = event->globalPos() - this->pos();
}

void MainWindow2::mouseMoveEvent(QMouseEvent* event)
{
    this->move(event->globalPos() - mOffset);
}
/**
 * 发送网络请求，获取天气信息。
 * @brief MainWindow::getWeatherInfo
 * @param cityName
 */
void MainWindow2::getWeatherInfo(QString cityName)
{
    // 从json文件中读取城市编号
    QString cityCode = WeatherTool::getCityCode(cityName);
    // 判断编号是否存在，若不存在，警告
    if ( cityCode.isEmpty() ) {
        // QMessageBox::warning(this, "天气", "请检查输入是否正确！", QMessageBox::Ok);
        return;
    }

    QString base = "http://t.weather.itboy.net/api/weather/city/";
    QUrl url(base + cityCode);
    // 发送网络请求
    mNetAccessManager->get(QNetworkRequest(url));
}
/**
 * 响应函数，处理返回的数据。
 * @brief MainWindow::onReplied
 * @param reply
 */
void MainWindow2::onReplied(QNetworkReply* reply)
{

    int status_code = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
    qDebug() << "status code:" << status_code;            // 状态码
    qDebug() << "url:" << reply->url();                   // url
    // 判断响应码是否为200 以及 返回是否正常
    if ( reply->error() != QNetworkReply::NoError || status_code != 200 ) {
        QMessageBox::warning(this, "天气", "请求数据失败！", QMessageBox::Ok);
    } else {
        QByteArray bytearr = reply->readAll();
        parseJson(bytearr);
    }

    reply->deleteLater();
}

void MainWindow2::parseJson(QByteArray& byteArray)
{
    QJsonParseError err;
    QJsonDocument doc = QJsonDocument::fromJson(byteArray, &err);
    if ( err.error != QJsonParseError::NoError ) {
        qDebug("%s(%d): %s", __FUNCTION__, __LINE__, err.errorString().toLatin1().data());
        return;
    }

    QJsonObject rootObj = doc.object();
    qDebug() << rootObj.value("message").toString();
    QString message = rootObj.value("message").toString();
    if ( !message.contains("success") ) {
        QMessageBox::warning(this, "天气", "请求数据失败！", QMessageBox::Ok);
        return;
    }

    // 1. 解析日期和城市
    mToday.date = rootObj.value("date").toString();
    mToday.city = rootObj.value("cityInfo").toObject().value("city").toString();

    QJsonObject objData = rootObj.value("data").toObject();

    // 2. 解析 yesterday
    QJsonObject objYestody = objData.value("yesterday").toObject();
    mDay[0].week = objYestody.value("week").toString();
    mDay[0].date = objYestody.value("ymd").toString();

    mDay[0].type = objYestody.value("type").toString();

    QString s = "";
    s = objYestody.value("high").toString().split(" ").at(1);
    s = s.left(s.length() - 1);
    mDay[0].high = s.toInt();

    s = objYestody.value("low").toString().split(" ").at(1);
    s = s.left(s.length() - 1);
    mDay[0].low = s.toInt();

    mDay[0].fx = objYestody.value("fx").toString();
    mDay[0].fl = objYestody.value("fl").toString();

    mDay[0].aqi = objYestody.value("aqi").toDouble();

    // 3. 解析 forecast 中5天的数据
    QJsonArray forecastArr = objData.value("forecast").toArray();
    for ( int i = 0; i < 5; i++ ) {
        QJsonObject objForcast = forecastArr[i].toObject();
        mDay[i + 1].week = objForcast.value("week").toString();
        mDay[i + 1].date = objForcast.value("ymd").toString();

        mDay[i + 1].type = objForcast.value("type").toString();

        QString s = "";
        s = objForcast.value("high").toString().split(" ").at(1);
        s = s.left(s.length() - 1);
        mDay[i + 1].high = s.toInt();

        s = objForcast.value("low").toString().split(" ").at(1);
        s = s.left(s.length() - 1);
        mDay[i + 1].low = s.toInt();

        mDay[i + 1].fx = objForcast.value("fx").toString();
        mDay[i + 1].fl = objForcast.value("fl").toString();

        mDay[i + 1].aqi = objForcast.value("aqi").toDouble();
    }

    // 4. 解析今天的数据
    mToday.ganmao = objData.value("ganmao").toString();

    mToday.high = mDay[1].high;
    mToday.low = mDay[1].low;
    mToday.wendu = QString("%1").arg((mToday.high + mToday.low) * 1.0 / 2);
    mToday.shidu = objData.value("shidu").toString();
    mToday.pm25 = objData.value("pm25").toDouble();
    mToday.quality = objData.value("quality").toString();

    // 5. forecast中的第一个数组, 也是今天的数据
    mToday.type = mDay[1].type;

    mToday.fx = mDay[1].fx;
    mToday.fl = mDay[1].fl;


    // 6. 更新 UI

    // 6.1 显示文本和图标
    updateUI();

    // 6.2 绘制温度曲线
    ui->lblHighCurve->update();
    ui->lblLowCurve->update();
}
void MainWindow2::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setBrush(QBrush(Qt::green));
    painter.setPen(Qt::transparent);
    QRect rect = this->rect();
    rect.setWidth(rect.width() - 1);
    rect.setHeight(rect.height() - 1);
    // rect: 绘制区域  15：圆角弧度
    painter.drawRoundedRect(rect, 15, 15);

    QWidget::paintEvent(event);
}

void MainWindow2::updateUI()
{
    // 1. 更新日期和城市
    ui->lblDate->setText(QDateTime::fromString(mToday.date, "yyyyMMdd").toString("yyyy/MM/dd") + " " + mDay[1].week);
    ui->lblCity->setText(mToday.city);

    // 2. 更新今天
    ui->lblTypeIcon->setPixmap(mTypeMap[mToday.type]);
    ui->lblTemp->setText((mToday.wendu) + "°");
    qDebug() << mToday.wendu << "\n";
    ui->lblType->setText(mToday.type);
    ui->lblLowHigh->setText(QString::number(mToday.low) + "~" + QString::number(mToday.high) + "°C");

    ui->lblGanMao->setText("感冒指数：" + mToday.ganmao);

    ui->lblWindFx->setText(mToday.fx);
    ui->lblWindFl->setText(mToday.fl);

    ui->lblPM25->setText(QString::number(mToday.pm25));

    ui->lblShiDu->setText(mToday.shidu);

    ui->lblQuality->setText(mToday.quality);

    // 3. 更新六天
    for ( int i = 0; i < 6; i++ ) {
        // 3.1 更新星期和日期
        mWeekList[i]->setText("周" + mDay[i].week.right(1));

        //设置 昨天/今天/明天 的星期显示 - 不显示星期几，而是显示
        //“昨天”、“今天”、“明天”
        ui->lblWeek0->setText("昨天");
        ui->lblWeek1->setText("今天");
        ui->lblWeek2->setText("明天");

        QStringList ymdList = mDay[i].date.split("-");
        mDateList[i]->setText(ymdList[1] + "/" + ymdList[2]);

        // 3.2 更新天气类型
        mTypeIconList[i]->setPixmap(mTypeMap[mDay[i].type]);
        mTypeList[i]->setText(mDay[i].type);

        // 3.3 更新空气质量
        if ( mDay[i].aqi >= 0 && mDay[i].aqi <= 50 ) {
            mAqiList[i]->setText("优");
            mAqiList[i]->setStyleSheet("background-color: rgb(121, 184, 0);");
        } else if ( mDay[i].aqi > 50 && mDay[i].aqi <= 100 ) {
            mAqiList[i]->setText("良");
            mAqiList[i]->setStyleSheet("background-color: rgb(255, 187, 23);");
        } else if ( mDay[i].aqi > 100 && mDay[i].aqi <= 150 ) {
            mAqiList[i]->setText("轻度");
            mAqiList[i]->setStyleSheet("background-color: rgb(255, 87, 97);");
        } else if ( mDay[i].aqi > 150 && mDay[i].aqi <= 200 ) {
            mAqiList[i]->setText("中度");
            mAqiList[i]->setStyleSheet("background-color: rgb(235, 17, 27);");
        } else if ( mDay[i].aqi > 200 && mDay[i].aqi <= 300 ) {
            mAqiList[i]->setText("重度");
            mAqiList[i]->setStyleSheet("background-color: rgb(170, 0, 0);");
        } else {
            mAqiList[i]->setText("严重");
            mAqiList[i]->setStyleSheet("background-color: rgb(110, 0, 0);");
        }

        // 3.4 更新风力/风向
        mFxList[i]->setText(mDay[i].fx);
        mFlList[i]->setText(mDay[i].fl);
    }
}

void MainWindow2::on_btnSearch_clicked()
{
    qDebug() << "searched";
    QString cityName = ui->leCity->text();
    getWeatherInfo(cityName);
}




void MainWindow2::on_pushButton_clicked()
{
    this->setWindowState(Qt::WindowMinimized);
}


void MainWindow2::on_pushButton_2_clicked()
{
    this->close();
}

/**
 * 语音命令功能，按住开始录音
 * @brief MainWindow::on_pushButton_3_pressed
 */
void MainWindow2::on_pushButton_3_pressed()
{
    ui->pushButton_3->setText("松开识别");
    //开始录音
    audio = new Audio;
    audio->startAudio(".\\file");
}

/**
 * 语音命令功能，松开开始调用百度云智能接口进行识别
 * @brief MainWindow::on_pushButton_3_released
 */
void MainWindow2::on_pushButton_3_released()
{
    //停止录音
    audio->stopAudio();
    //修改按钮文字
    ui->pushButton_3->setText("开始识别");
    //开始识别
    Speech m_speech;
    QString text = m_speech.speechIdentify("./file");
    ui->pushButton_3->setText("按住说话");
    qDebug() <<"hh"<< text;
    QString s = WeatherTool::hasACity(text);
    if (!s.isEmpty() && s.length() > 0)
        this->getWeatherInfo(s);
}


void MainWindow2::on_pushButton_3_clicked()
{

}

