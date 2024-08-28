#ifndef ChatWindow_H
#define ChatWindow_H
#include <QTcpSocket>
#include <QMainWindow>
#include <QTcpServer>
#include "login.h"
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

    QString username ;
    Login *login;
    QTcpSocket *socket;
    int serverport = 8888;
    QTcpServer *server ;
    QVector<QString> userList ;
    QVector<QTcpSocket*>clientSockets;
    QMenu *emojiMenu;
    QVector<QString> loadEmojis(QString filename) ;

private slots:
    void on_pushButton_clicked();
    void keyPressEvent(QKeyEvent *ev);
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_3_pressed();

    void on_pushButton_4_clicked();

private:
    Ui::ChatWindow *ui;
};
#endif // ChatWindow_H
