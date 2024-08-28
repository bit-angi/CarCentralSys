#include "chatwindow.h"
#include "ui_chatwindow.h"
#include <QTcpSocket>
#include <QMessageBox>
#include <QTcpServer>
#include <qdatetime.h>
#include <qsqldatabase.h>
#include <QMenu>
#include<QGridLayout>
#include "login.h"
#include <QFile>
#include <QKeyEvent>
ChatWindow::ChatWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ChatWindow)
{
    this->setWindowFlags(Qt::FramelessWindowHint);
    ui->setupUi(this);
    // 连接数据库
    this->initSql();

    this->login = new Login(this);
    this->login->show();
    qDebug() << this->username ;
    this->socket = new QTcpSocket();
    // 本地测试，选择本机地址和8888端口
    QString ip = "127.0.0.1";
    ui->lineEdit->setText("127.0.0.1");
    ui->lineEdit_2->setText("8888");
    int port = 8888;

    server = new QTcpServer() ;
    if (server->listen(QHostAddress::Any,this->serverport)) {
        connect(server,&QTcpServer::newConnection,this,[=]() {
            // 获得客户端的socket套接字
            QTcpSocket *clientSocket = server->nextPendingConnection();
            this->clientSockets.push_back(clientSocket);
            if (clientSocket) {
                connect(clientSocket,&QTcpSocket::readyRead,this,[=]() {
                    char buffer[1024] = {0};
                    clientSocket->read(buffer,1024);
                    qDebug() <<"bb"<< buffer;
                    QString str = QString(buffer);
                    if (str.endsWith("已上线\n")) {
                        userList.push_back(str.left(str.indexOf("已上线\n")));
                        char buffer1[1024] = {0};
                        QString msg = QString("newuser"+ (QString::number(this->userList.size()) + this->username) + QString(buffer));
                        msg += "|";
                        for (QString username : userList) {
                            msg += " " + username;
                        }
                        strcpy(buffer1 ,msg.toStdString().c_str());
                        for (QTcpSocket *socket : clientSockets) {
                            socket->write(buffer1,1024);
                        }
                    }
                    else {
                        for (QTcpSocket *socket : clientSockets) {
                            socket->write(buffer,1024);
                        }
                    }
                });
            }
        });

    }
    this->socket->connectToHost(ip,port);
    if (!this->socket->waitForConnected(30000)) {
        QMessageBox::information(this,"info","连接失败");
    }
    else {
        connect(this->socket,&QTcpSocket::readyRead,this,[=]() {
            qDebug() <<"readyread";
            char buffer[1024] = {0};
            this->socket->read(buffer,1024);
            qDebug() << buffer;
            if (QString(buffer).startsWith("newuser")) {

                this->ui->label_3->setText(QString("在线人数：") + QString(buffer)[7]);
                this->addMeg(QString(buffer).split("|")[0].right(8));
                ui->listWidget->clear();
                qDebug() << "zheli " << buffer;
                QStringList s = QString(buffer).split("|")[1].split("\n");
                for (QString str : s) {
                    if (str.trimmed().length() == 0) continue;
                    ui->listWidget->addItem(str);
                }
            }
            else this->addMeg(QString(buffer));
        });
    }
    connect(this->login,&Login::newSignal,this,[=]() {
        this->username = this->login->user_info.username ;
        char buffer[1024] = {0};
        qDebug() << "888";
        strcpy(buffer,QString("\n" + this->username+"已上线\n").toStdString().c_str());
        qint64 i = this->socket->write(buffer,1024);
        qDebug() << "i"<< i ;
    });

    // 表情
    emojiMenu = new QMenu(this);
    QVector<QString> emojis = loadEmojis(":/emoji");

    //    for (const auto& emoji : emojis) {
    //        QAction* action = new QAction(emoji, this);
    //        connect(action, &QAction::triggered, [=]() {
    //            ui->lineEdit_3->insert(emoji);
    //        });
    //        emojiMenu->addAction(action);
    //    }
    QGridLayout *grid = new QGridLayout(emojiMenu);

    int rows = 7;  // Number of rows
    int columns = 8;  // Number of columns
    int emojiIndex = 0;

    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < columns; ++col) {
            if (emojiIndex < emojis.size()) {
                QPushButton *emojiButton = new QPushButton();
                emojiButton->setFixedWidth(30);
                emojiButton->setText(emojis[emojiIndex]);
                connect(emojiButton, &QPushButton::clicked, [=]() {
                    ui->lineEdit_3->insert(emojis[emojiIndex]);
                    emojiMenu->close();
                });
                emojiButton->setIconSize(QSize(32, 32));  // Set icon size as per your need
                grid->addWidget(emojiButton, row, col);
                emojiIndex++;
            }
        }
    }

    emojiMenu->setLayout(grid);
}

/**
 * 更新用户列表
 * @brief ChatWindow::updateList
 */
void ChatWindow::updateList()
{
    qDebug() << "updatelist";
    this->ui->listWidget->clear();
    for (QString username : this->userList) {
        qDebug() << "usrlist:" << username;
        QListWidgetItem item(username,this->ui->listWidget) ;
        ui->listWidget->addItem(username);
    }
}

ChatWindow::~ChatWindow()
{
    delete ui;
}

/**
 * 向聊天框添加一条消息，附带时间
 * @brief ChatWindow::addMeg
 * @param msg
 */
void ChatWindow::addMeg(QString msg)
{
    QString m = QDateTime::currentDateTime().toString() + "<br>"+ msg + "<br/>";
    this->ui->textEdit->setHtml(ui->textEdit->toHtml() +"<br/>" + m );
}

QVector<QString> ChatWindow::loadEmojis(QString filename)
{
    QVector<QString> emojis;
    QFile file(filename);
    QString line;
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << ("打开文件失败");
    }
    QTextStream textinput(&file);
    textinput.setEncoding(QStringConverter::Utf8);
    QString linestr = textinput.readLine(1024);
    QStringList list = linestr.split("|");
    for (QString s : list) {
        emojis.push_back(s);
    }
    file.close();

    return emojis;
}

/**
 * 初始化服务器Postgresql数据库
 * @brief ChatWindow::initSql
 */
void ChatWindow::initSql()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("127.0.0.1");
    db.setPort(5432);

    db.setUserName("postgres");
    db.setPassword("123456");
    if (db.open()) {
        qDebug() << "success";
    } else {
        qDebug() << "fail";
    }
}
void ChatWindow::on_pushButton_clicked()
{

    this->socket = new QTcpSocket();
    QString ip = ui->lineEdit->text();
    int port = ui->lineEdit_2->text().toInt();

    this->socket->connectToHost(ip,port);
    if (!this->socket->waitForConnected(30000)) {
        QMessageBox::information(this,"info","连接失败");
    }
    else {
        QMessageBox::information(this,"info","连接成功");
        connect(this->socket,&QTcpSocket::readyRead,this,[=]() {
            char buffer[1024] = {0};
            this->socket->read(buffer,1024);
            this->addMeg(QString(buffer));
        });
    }
}

void ChatWindow::keyPressEvent(QKeyEvent *ev)
{
    if (ev->key() == Qt::Key_Return) {
        this->on_pushButton_2_clicked();
    }
}


void ChatWindow::on_pushButton_2_clicked()
{
    this->username = this->login->user_info.username ;
    QString msg = "\n" + this->username + ":" + ui->lineEdit_3->text();
    ui->lineEdit_3->clear();
    char arr[1024] = {0};
    strcpy(arr,msg.toStdString().c_str());
    int s = this->socket->write(arr,1024);
    qDebug() << s ;
}

void ChatWindow::on_pushButton_3_pressed()
{

}

void ChatWindow::on_pushButton_3_clicked()
{

}


void ChatWindow::on_pushButton_4_clicked()
{
    int x = QCursor::pos().x();
    int y = QCursor::pos().y();
    emojiMenu->exec(QPoint(x,y - emojiMenu->height()));
}




