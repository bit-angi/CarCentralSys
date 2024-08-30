#ifndef CHATSERVER_H
#define CHATSERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QThreadPool>
#include <QRunnable>
#include <QMutex>
class ClientHandler : public QObject ,public QRunnable {
    Q_OBJECT
public:
    ClientHandler(QTcpSocket *socket);
    void run() override;
    void broadcastMessage(QString msg);
    QStringList userlist;
signals :
    void broadcast(QString);
private:
    QTcpSocket *m_socket;
};

class ChatServer : public QTcpServer {
    Q_OBJECT
public:
    explicit ChatServer(QObject *parent = nullptr);
    QVector<QTcpSocket*> clientSockets;
    QStringList userlist;

public slots:
    void broadcastMessage(QString msg);
protected:
    void incomingConnection(qintptr socketDescriptor) override;

private:
    QMutex m_mutex; // 用于保护共享资源
    QThreadPool m_threadPool;
};

#endif // CHATSERVER_H
