#ifndef SOCKET_H
#define SOCKET_H

#include <QWidget>
#include <QtNetwork>
#include <QTcpSocket>
#include<QNetworkAccessManager>
#include<QNetworkReply>
#include<QNetworkRequest>
#include <qDebug>
class Socket :public QTcpSocket
{

public:
    Socket();
    void readMessage();
    void sendMessage(QString msg);
    QTcpSocket *tcpServerConnection;
    quint16 bufSize;
    QString message;
};

#endif // SOCKET_H
