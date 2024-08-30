#ifndef ChatWindow_H
#define ChatWindow_H
#include <QTcpSocket>
#include <QMainWindow>
#include <QTcpServer>
#include <QThreadPool>
#include <QAudio>
#include "login.h"
#include "qaudiodevice.h"
#include "audio.h"
#include "chatserver.h"
QT_BEGIN_NAMESPACE
namespace Ui { class ChatWindow; }
QT_END_NAMESPACE

class ChatWindow : public QMainWindow
{
    Q_OBJECT

public:
    ChatWindow(QWidget *parent = nullptr);
    ~ChatWindow();
    void updateList() ;
    void initSql() ;
    void addMeg(QString msg);
    QVector<QString> loadEmojis(QString filename) ;
    bool saveFile(const QString &filename);


    QString username ;
    Login *login;
    QTcpSocket *socket;
    int serverport = 8888;
    // QTcpServer *server ;
    ChatServer *server;
    QVector<QString> userList ;
    // QVector<QTcpSocket*> clientSockets;
    QMenu *emojiMenu;
    QThreadPool* threadPool;
    Audio *audio;
    // void broadcastMessage(const QByteArray &message);
public slots:
    void on_pushButton_clicked();
    void keyPressEvent(QKeyEvent *ev);
    void on_pushButton_2_clicked();
    void processNewConnection();
    void on_pushButton_3_clicked();

    void on_pushButton_3_pressed();

    void on_pushButton_4_clicked();

    void on_pushButton_3_released();

    void on_pushButton_5_clicked();
    void onNewConnection();


private:
    Ui::ChatWindow *ui;
};
#endif // ChatWindow_H
