#include "ChatServer.h"
#include <QDebug>
#include <QDataStream>

ClientHandler::ClientHandler(QTcpSocket *socket)
    : m_socket(socket) {}

void ClientHandler::run() {
    qDebug() << "Socket" << m_socket->socketDescriptor() << "在该线程中处理:" << QThread::currentThreadId();
    char buffer[1024] = {0};
    m_socket->read(buffer,1024);
    QString str = QString(buffer);
    qDebug() << "str:" << str;
    if (str.contains("已上线")) {
        this->userlist.push_back(str.split("已上线")[0]);
        str += "|";
        for (const QString& username : userlist) {
            str += " " + username;
        }
    }
    emit broadcast(str);
}

ChatServer::ChatServer(QObject *parent)
    : QTcpServer(parent) {
    m_threadPool.setMaxThreadCount(10);
}

void ChatServer::incomingConnection(qintptr socketDescriptor) {
    QTcpSocket *socket = new QTcpSocket();
    socket->setSocketDescriptor(socketDescriptor);
    clientSockets.push_back(socket);
    // 一旦客户端要进行操作，则分配一个新的线程
    connect(socket, &QTcpSocket::readyRead, this, [=]() {
        // 从线程池分配一个线程
        ClientHandler *handler = new ClientHandler(socket);
        handler->userlist = this->userlist;
        connect(handler,&ClientHandler::broadcast,this,&ChatServer::broadcastMessage);
        m_threadPool.start(handler);
    });

}

void ChatServer::broadcastMessage(QString msg)
{
    QMutexLocker locker(&m_mutex);
    if (msg.contains("已上线")) {
        this->userlist.push_back(msg.split("\n")[1].split("已上线")[0]);
    }
    char buffer[1024] = {0};
    qDebug() << clientSockets.length();
    std::strcpy(buffer,msg.toStdString().c_str());
    for (QTcpSocket* socket : clientSockets) {
        socket->write(buffer);
    }
}
