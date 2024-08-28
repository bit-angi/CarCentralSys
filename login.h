#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <qsqldatabase.h>

namespace Ui {
class Login;
}
struct userInfo {
    QString username ;
    QString password ;
};
class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();
    userInfo user_info ;
    QSqlDatabase *db;
private slots:
    void on_btn_login_clicked();

    void on_btn_regist_clicked();
    void on_pushButton_clicked();

signals :
    void newSignal();
private:
    Ui::Login *ui;
};

#endif // LOGIN_H
