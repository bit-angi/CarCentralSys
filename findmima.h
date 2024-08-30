#ifndef FINDMIMA_H
#define FINDMIMA_H

#include <QDialog>
#include <QSqlDatabase>
namespace Ui {
class FindMima;
}

class FindMima : public QDialog
{
    Q_OBJECT

public:
    explicit FindMima(QWidget *parent = nullptr);
    ~FindMima();
    QSqlDatabase* database;
private slots:
    void on_registerCheckButton_clicked();

private:
    Ui::FindMima *ui;
};

#endif // FINDMIMA_H
