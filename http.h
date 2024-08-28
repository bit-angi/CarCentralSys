#ifndef HTTP_H
#define HTTP_H

#include <QObject>
#include <QMap>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QEventLoop>
#include <QDebug>

class http : public QObject
{
    Q_OBJECT
public:
    explicit http(QObject *parent = nullptr);

    bool post_sync(QString Url, QMap<QString, QString> head, QByteArray request, QByteArray &relyData);

signals:

};

#endif // HTTP_H
