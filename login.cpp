#include "login.h"
#include "ui_login.h"
#include <QSqlQuery>
#include <qmessagebox.h>
#include "register.h"
Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    this->ui->lineEdit_passwd->setEchoMode(QLineEdit::Password);

}

Login::~Login()
{
    delete ui;
}


/**
 * 登录功能，检查数据库是否有对应的用户名和密码
 * @brief Login::on_btn_login_clicked
 */
void Login::on_btn_login_clicked()
{
    QSqlQuery query ;
    query.exec("select * from userinfo");
    while (query.next()) {
        if (query.value(0) == ui->line_ac->text() && query.value(1) == ui->lineEdit_passwd->text()) {
            this->user_info.username = ui->line_ac->text();
            qDebug() << ui->line_ac->text();
            this->close();
            emit newSignal();
            return;
        }
    }
    QMessageBox::information(this,"info","用户名或密码错误");
}


void Login::on_btn_regist_clicked()
{
    Register r;
    r.setParent(this);      //设置父对象
   //transmitdb(database);
    r.exec();    //注册页面r，仅仅获取信息.

//    get_user_info();
    if(user_info.username.isEmpty() || user_info.password.isEmpty()){
        QMessageBox::information(this,tr("提示"),tr("请输入用户名和密码！"));
    }
    else
    {
        bool exitFlag = false;       //判断用户是否存在

        if(!db->open())
        {
            qDebug() << "database open fail regist!";
        }
        else
        {
            QSqlQuery query;
            qDebug() << "database open success regist!";
            query.exec("select * from userInfo");
            while (query.next())
            {
                QString username = query.value(0).toString();
                QString passwd = query.value(1).toString();
                qDebug() << "regist userName:::"<< username << "passwd:::" << passwd;

                if(username == user_info.username){
                    exitFlag = true;              //用户存在
                }
            }

            if(exitFlag == false){
                qDebug()<<"regist:::"<<query.lastQuery();
                QMessageBox::information(this,tr("提示"),tr("注册成功！"));

                query.exec("select * from userInfo");
                while (query.next())
                {
                    QString username = query.value(0).toString();
                    QString passwd = query.value(1).toString();
                    qDebug() << "regist username:::"<< username << "passwd:::" << passwd;
                }
            }else{
                QMessageBox::warning(this,tr("警告"),tr("用户已存在！"));
            }
        }
        db->close();
    }
}


void Login::on_pushButton_clicked()
{
    if (ui->lineEdit_passwd->echoMode() == QLineEdit::Password) {
        ui->lineEdit_passwd->setEchoMode(QLineEdit::Normal);
    }
    else {
        ui->lineEdit_passwd->setEchoMode(QLineEdit::Password);
    }
}

