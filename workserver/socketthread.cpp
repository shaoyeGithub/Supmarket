#include "socketthread.h"
#include <qDebug>
SocketThread::SocketThread(QObject *parent ,int socketDescriptor):QThread(parent),socketDescriptor(socketDescriptor)
{

   model =new QSqlTableModel(parent);
}

void SocketThread::run(){
    qDebug()<<"服务器运行到这里了";
    dataSocket.tcpServerConnection = new QTcpSocket;
    if (!dataSocket.tcpServerConnection->setSocketDescriptor(socketDescriptor))
    {
        return;
    }
    //Qt::AutoConnection表示系统自动选择相应的连接方式，
    //如果信号与槽在同一线程，就采用Qt::DirectConnection,一旦信号产生，立即执行槽函数。
    connect(dataSocket.tcpServerConnection, SIGNAL(readyRead()), this,
        SLOT(readMessage()), Qt::DirectConnection);
    exec();
}
void SocketThread::readMessage()
{
   dataSocket.readMessage();
   QStringList strList =dataSocket.message.split("/");
   QString flag = strList.at(0);
   switch(flag.toInt())
   {
      case 51:
      {
       QString name = strList.at(1);
       QString password = strList.at(2);
       dataSocket.sendMessage(QString::number(login(name,password)));
       break;
      }
   }
}
void SocketThread::sendMessage()
{

}
//判断用户名和密码
int SocketThread::login(QString name,QString password)
{
    int flag =0;
    model->setTable("user");
    model->setFilter(tr("username = '%1' and password = '%2'").arg(name).arg(password));
    model->select();
    flag=model->rowCount();
    return flag;
}
