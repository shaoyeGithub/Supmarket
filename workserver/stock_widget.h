#ifndef STOCKWIDGET_H
#define STOCKWIDGET_H

#include <QWidget>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QtNetwork>
#include<QNetworkAccessManager>
#include<QNetworkReply>
#include<QNetworkRequest>
#include "socket.h"
namespace Ui {
class StockWidget;
}

class StockWidget : public QWidget
{
    Q_OBJECT

public:
    explicit StockWidget(QWidget *parent = 0);
    ~StockWidget();
private slots:
     void acceptConnection();
     void readMessage();
     void sendMessage();
private:
    Ui::StockWidget *ui;
    Socket socketServer;
    QSqlQuery query;
    QSqlTableModel *model;

//        //数据包 ：数据的大小信息+实际数据
//        QString id;
//        QString comCode;
//        QString comName;
//        QString remainingNum;
};

#endif // WIDGET_H
