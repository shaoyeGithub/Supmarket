#ifndef SOCKETTHREAD_H
#define SOCKETTHREAD_H
#include "socket.h"
#include<QWidget>
#include<QThread>
#include <QSqlTableModel>
class SocketThread : public QThread
{    

public:
    SocketThread(QObject *parent ,int socketDescriptor);
    int login(QString name,QString password);
    int socketDescriptor;
    Socket dataSocket;
    QSqlTableModel *model ;
protected:
   void run();
public slots:
   void readMessage();
   void sendMessage();


};

#endif // SOCKETTHREAD_H
