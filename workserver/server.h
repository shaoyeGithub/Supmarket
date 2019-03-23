#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include <QWidget>
#include "socketthread.h"
class Server :public QTcpServer
{

public:
    Server(QObject *parent =0);
    QTcpServer* getTcpServer();
    void setTcpServer(QTcpServer *tcp);
protected:
    void incomingConnection(int socketDescriptor);
private:
    QTcpServer * tcpServer;
};

#endif // SERVER_H
