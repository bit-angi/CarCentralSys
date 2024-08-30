#include "findmima.h"
#include "ui_findmima.h"

#include <QMessageBox>
#include <QSqlQuery>

FindMima::FindMima(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::FindMima)
{
    ui->setupUi(this);
}

FindMima::~FindMima()
{
    delete ui;
}

void FindMima::on_registerCheckButton_clicked()
{
    QSqlQuery query ;
    query.prepare("select* from userinfo where username = :name and email = :yx");
    query.bindValue(":name",ui->lineEditName->text());
    query.bindValue(":yx",ui->lineEditPasswordCheck_2->text());
    if (query.exec()) {
        qDebug() << "chengg";
    }
    if (query.next()) {
        QMessageBox::information(this,"info","更改成功");
        query.prepare("update userinfo set password = :pwd where username = :username");
        query.bindValue(":pwd",ui->lineEditPassword->text());
        query.bindValue(":username" ,ui->lineEditName->text());
        query.exec();
    }
    else{
        QMessageBox::information(this,"info","更改失败，请检查用户名或邮箱是否正确");
    }
    this->close();
}

