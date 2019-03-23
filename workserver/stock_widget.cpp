#include "stock_widget.h"
#include "ui_stock_widget.h"
#include <qDebug>
#include <QSqlRecord>
StockWidget::StockWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StockWidget)
{
    ui->setupUi(this);
    model=new QSqlTableModel(this);

    socketServer.setTcpServer(new QTcpServer(this));
    socketServer.getTcpServer()->listen(QHostAddress::Any,1234);

    connect(socketServer.getTcpServer(),SIGNAL(newConnection()),this,SLOT(acceptConnection()));
}

StockWidget::~StockWidget()
{
    delete ui;
}
void StockWidget::acceptConnection()
{
    socketServer.setTcpSocket(socketServer.getTcpServer()->nextPendingConnection());
    connect(socketServer.getTcpSocket(), SIGNAL(readyRead()),this, SLOT(readMessage()));

//    connect( tcpServerConnection,SIGNAL(disconnected()), tcpServerConnection,
//                SLOT(deleteLater()));
//    connect(tcpServerConnection, SIGNAL(error(QAbstractSocket::SocketError)),
//            this, SLOT(displayError(QAbstractSocket::SocketError)));

}
void StockWidget::readMessage()
{
       socketServer.readMessage();
        // 显示接收到的数据
        model->setTable("stock");
        model->setFilter(tr("ComName = '%1'").arg(socketServer.message));
        model->select();

        //qDebug()<<"model-rowcount"<<QString::number(model->rowCount());
       sendMessage();
}
void StockWidget::sendMessage()
{
    //数据包 ：数据的大小信息+实际数据
    QString id;
    QString comCode;
    QString comName;
    QString remainingNum;
//    QString queryline ="select * from stock where ComName='%1'";
//    qDebug()<<queryline;
    //qDebug() << socketServer.message;
    query.exec(tr("select * from stock where ComName='%1'").arg(socketServer.message));
    //qDebug()<<QString::number(query.record().count());
    //socketServer.sendMessage(QString::number(model->rowCount()));
    while(query.next())
    {
     qDebug()<<"数据库查询开始.....";
     id=id.append("/").append(query.value(0).toString());
     comCode=comCode.append("/").append(query.value(1).toString());
     remainingNum=remainingNum.append("/").append(query.value(2).toString());
     comName=comName.append("/").append(query.value(3).toString());
    }
    QString sendmessage = id.append("~").append(comCode).append("~").append(remainingNum)
                .append("~").append(comName);
    socketServer.sendMessage(sendmessage);
}
