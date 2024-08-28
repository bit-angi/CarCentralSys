#ifndef WEATHERTOOL_H
#define WEATHERTOOL_H

#include <QCoreApplication>
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonValue>
#include <QMap>
#include <QDebug>
class WeatherTool {
private:
  static void initCityMap() {
    //        QString filePath = "E:/citycode-2019-08-23.json";
    QString filePath = ":/res/citycode-2019-08-23.json";

    QFile file(filePath);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QByteArray json = file.readAll();
    file.close();

    QJsonParseError err;
    QJsonDocument doc = QJsonDocument::fromJson(json, &err);
    if (err.error != QJsonParseError::NoError) {
      qDebug("%s(%d) parse json failed: %s", __FUNCTION__, __LINE__,
             err.errorString().toStdString().data());
      return;
    }

    // 文件应该是一个 JSON 数组
    if (!doc.isArray()) {
      qDebug("%s(%d) parse json failed: not an array", __FUNCTION__, __LINE__);
      return;
    }

    QJsonArray citys = doc.array();
    for (int i = 0; i < citys.size(); i++) {
      QString code = citys[i].toObject().value("city_code").toString();
      QString city = citys[i].toObject().value("city_name").toString();
      // 省份没有 city_code
      if (code.size() > 0) {
        mCityMap.insert(city, code);
      }
    }
  }

public:
  static QString hasACity(QString sentence) {
      qDebug() << "6666" ;
      if (mCityMap.isEmpty()) {
        initCityMap();
      }
      QList<QString> list = mCityMap.keys();
      for (QString s : list) {
          if (sentence.contains(s)) {
              return s ;
          }
      }
      return NULL;
  }
  static QString getCityCode(QString cityName) {
    if (mCityMap.isEmpty()) {
      initCityMap();
    }

    // 有的城市没有加 “市”，比如 “北京”
    // 县，都是加了 “县”的
    QMap<QString, QString>::const_iterator it = mCityMap.find(cityName);

    if (it == mCityMap.end()) {
      it = mCityMap.find(cityName + "市");
    }

    if (it != mCityMap.end()) {
      return it.value();
    }

    return "";
  }

private:
  // 声明一个静态成员变量
  static QMap<QString, QString> mCityMap;
};

// 初始化静态成员变量
QMap<QString, QString> WeatherTool::mCityMap = {};

#endif // WEATHERTOOL_H
