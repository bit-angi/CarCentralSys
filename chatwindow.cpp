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
#include "speech.h"
#include <QFile>
#include <QFileDialog>
#include <QKeyEvent>

/**
 * 初始化聊天客户端和服务端
 * @brief ChatWindow::ChatWindow
 * @param parent
 */
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

    // 本地测试，选择本机地址和8888端口
    QString ip = "127.0.0.1";
    int port = 8888;
    ui->lineEdit->setText("127.0.0.1");
    ui->lineEdit_2->setText("8888");
    threadPool = new QThreadPool();
    threadPool->setMaxThreadCount(10);
    server = new ChatServer();
    if (server->listen(QHostAddress::Any,this->serverport)) {
        // connect(server, &QTcpServer::newConnection, this, &ChatWindow::onNewConnection);
    }
    // 创建一个新的socket
    this->socket = new QTcpSocket();
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
            if (QString(buffer).contains("已上线")) {
                // 清空用户列表，防止重复
                this->ui->listWidget->clear();
                QStringList s = QString(buffer).split("|")[1].split(" ");
                this->ui->label_3->setText(QString("在线人数：") + QString::number(s.length()-1));
                for (QString str : s) {
                    if (str.trimmed().length() == 0) continue;
                    ui->listWidget->addItem(str.trimmed());
                }
                this->addMeg(QString(buffer).split("|")[0]);
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

bool ChatWindow::saveFile(const QString &filename){
    QFile file(filename);
    if(!file.open(QFile::WriteOnly|QFile::Text)){
        QMessageBox::warning(this,tr("保存文件"),tr("无法保存文件%1:\n%2").arg(filename).arg(file.errorString()));

        return false;

    }
    QTextStream out(&file);
    out<<ui->textEdit->toPlainText();
    return true;

}

// void ChatWindow::broadcastMessage(const QByteArray &message) {
//     for (QTcpSocket* socket : clientSockets) {
//         socket->write(message);
//     }
// }
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

void ChatWindow::processNewConnection()
{
    QTcpSocket* clientSocket = server->nextPendingConnection();
    if (!clientSocket) {
        qWarning() << "Failed to get client socket";
        return;
    }

    // clientSockets.push_back(clientSocket);

    connect(clientSocket, &QTcpSocket::readyRead, this, [=]() {
        // QByteArray data = clientSocket->readAll();
        // QString str = QString(data);
        char buffer[1024] = {0};
        clientSocket->read(buffer,1024);
        QString str = QString(buffer);
        qDebug() << "sss:" << str;
        if (str.contains("已上线")) {
            userList.push_back(str.left(str.indexOf("已上线\n")));
            QString msg = QString("newuser" + QString::number(userList.size()) + username + str);
            msg += "|";
            for (const QString& username : userList) {
                msg += " " + username;
            }
            char buffer[1024] = {0};
            strcpy(buffer,msg.toStdString().c_str());
            // for (QTcpSocket* socket : clientSockets) {
            //     socket->write(buffer);
            // }
        } else {
            QByteArray response = str.toUtf8();
            // broadcastMessage(response);
        }
    });

    connect(clientSocket, &QTcpSocket::disconnected, this, [=]() {
        clientSocket->deleteLater();
    });

}

/**
 * 语音命令功能，按住开始录音
 * @brief MainWindow::on_pushButton_3_pressed
 */
void ChatWindow::on_pushButton_3_pressed()
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
void ChatWindow::on_pushButton_3_released()
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
    ui->lineEdit_3->setText(text);
}


void ChatWindow::on_pushButton_4_clicked()
{
    int x = QCursor::pos().x();
    int y = QCursor::pos().y();
    emojiMenu->exec(QPoint(x,y - emojiMenu->height()));
}


void ChatWindow::on_pushButton_3_clicked()
{

}


void ChatWindow::on_pushButton_5_clicked()
{
    if (ui->textEdit->document()->isEmpty()){
        QMessageBox::warning(0,tr("警告"),tr("聊天记录为空，无法保存！"),QMessageBox::Ok);
    }else {
        QString fname=QFileDialog::getSaveFileName(this,tr("保存聊天记录"),tr("聊天记录"),tr("文本(*.txt);;所有文件(*.*)"));
        if(!fname.isEmpty()) saveFile(fname);
    }
}

void ChatWindow::onNewConnection() {

}


