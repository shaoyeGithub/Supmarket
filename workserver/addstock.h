#ifndef ADDSTOCK_H
#define ADDSTOCK_H

#include <QWidget>
#include "socket.h"
#include <QSqlQuery>
namespace Ui {
class addStock;
}

class addStock : public QWidget
{
    Q_OBJECT

public:
    explicit addStock(QWidget *parent = 0);
    ~addStock();
private slots:
    void readMessage();
    void acceptConnection();
    //void sendMessage();
private:
    Ui::addStock *ui;
    Socket socketServer;
    QSqlQuery query;
};

#endif // ADDSTOCK_H
