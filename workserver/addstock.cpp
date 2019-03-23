#include "addstock.h"
#include "ui_addstock.h"

addStock::addStock(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addStock)
{
    ui->setupUi(this);

    socketServer.setTcpServer(new QTcpServer(this));
    socketServer.getTcpServer()->listen(QHostAddress::Any,1234);
//    socketServer.tcpServer=new QTcpServer(this);
//    socketServer.tcpServer->listen(QHostAddress::Any,1234);
    connect(socketServer.getTcpServer(),SIGNAL(newConnection()),this,SLOT(acceptConnection()));
}

addStock::~addStock()
{
    delete ui;
}
void addStock::acceptConnection()
{
    socketServer.setTcpSocket(socketServer.getTcpServer()->nextPendingConnection());
    connect(socketServer.getTcpSocket(), SIGNAL(readyRead()),this, SLOT(readMessage()));
}
void addStock::readMessage()
{
     socketServer.readMessage();
     QStringList strlist=socketServer.message.split("/");
     QString comCode = strlist.at(0);
     QString number=strlist.at(1);
     int nowNumber;
     int changedNum;
     query.exec(tr("select RemainingNum from stock where ComCode ='%1'").arg(comCode));
     while(query.next())
     {
      nowNumber= query.value(0).toInt();
     }
     nowNumber+=number.toInt();
     ui->label->setText(QString::number(nowNumber));

     query.exec(tr("UPDATE stock SET RemainingNum ='%1' WHERE  ComCode = '%2'").arg(nowNumber).arg(comCode));

     query.exec(tr("select RemainingNum from stock where ComCode ='%1'").arg(comCode));
     while(query.next())
     {
      changedNum =query.value(0).toInt();
      }
     ui->label_2->setText(QString::number(changedNum));
     if(nowNumber==changedNum)
     {
     socketServer.sendMessage(QString::number(1));
     }else{
         socketServer.sendMessage(QString::number(0));
     }

}
