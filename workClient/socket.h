#ifndef SOCKET_H
#define SOCKET_H
#include <QWidget>
#include <QDialog>
#include <QTcpSocket>
class Socket
{
public:
    Socket();
    void readMessage();
    void sendMessage(QString msg);
    void newConnect();
    QTcpSocket* getTcpSocket();
    void setTcpSocket(QTcpSocket *tcp);
private:
    QTcpSocket *tcpSocket;
public:
    QString message;
    quint16 bufSize;
};

#endif // SOCKET_H
