#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include <QWidget>
#include <QSqlTableModel>
#include "socket.h"
#include <QtNetwork>
#include<QNetworkAccessManager>
#include<QNetworkReply>
#include<QNetworkRequest>
namespace Ui {
class Widget;
}

class LoginWidget : public QWidget
{
    Q_OBJECT

public:
    explicit LoginWidget(QWidget *parent = 0);
    ~LoginWidget();
private slots:
    void readMessage();
    void acceptConnection();
    void sendMessage();
private:
    Ui::Widget *ui;
    Socket socketServer;

    QSqlTableModel *model ;
    int flag=0;
};

#endif // WIDGET_H
