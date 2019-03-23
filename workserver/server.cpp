#include "server.h"
#include <QMessageBox>
#include<QDebug>
Server::Server(QObject *parent):QTcpServer(parent)
{

}
QTcpServer* Server::getTcpServer()
{
    return this->tcpServer;
}
void Server::setTcpServer(QTcpServer *tcp)
{
    this->tcpServer=tcp;
}
void Server::incomingConnection(int socketDescriptor)
{
    qDebug()<<"sadas";
    //QMessageBox::about(0,tr("提示"),tr("有新连接"));
    SocketThread * thread=new SocketThread(this,socketDescriptor);
    thread->start();

}
