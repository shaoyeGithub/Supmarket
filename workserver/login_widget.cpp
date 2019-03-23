#include "login_widget.h"
#include "ui_login_widget.h"
#include <qDebug>
LoginWidget::LoginWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    model=new QSqlTableModel(this);


    socketServer.setTcpServer(new QTcpServer(this));
    socketServer.getTcpServer()->listen(QHostAddress::Any,1234);
//    socketServer.tcpServer=new QTcpServer(this);
//    socketServer.tcpServer->listen(QHostAddress::Any,1234);
    connect(socketServer.getTcpServer(),SIGNAL(newConnection()),this,SLOT(acceptConnection()));

}

LoginWidget::~LoginWidget()
{
    delete ui;
}
void LoginWidget::acceptConnection()
{
    socketServer.setTcpSocket(socketServer.getTcpServer()->nextPendingConnection());
    connect(socketServer.getTcpSocket(), SIGNAL(readyRead()),this, SLOT(readMessage()));
//   connect( socketServer.tcpServerConnection,SIGNAL(disconnected()), tcpServerConnection,
//                SLOT(deleteLater()));
//    connect(socketServer.tcpServerConnection, SIGNAL(error(QAbstractSocket::SocketError)),
//            this, SLOT(displayError(QAbstractSocket::SocketError)));
}
void LoginWidget::readMessage()
{

    socketServer.readMessage();
    QStringList strlist=socketServer.message.split("/");
    QString name=strlist.at(0);
    QString password=strlist.at(1);
    model->setTable("user");
    model->setFilter(tr("username = '%1' and password = '%2'").arg(name).arg(password));
    model->select();
    flag=model->rowCount();
    //ui->label_2->setText(name.append(password));
    sendMessage();
}
void LoginWidget::sendMessage()
{
    socketServer.sendMessage(QString::number(flag));

    //ui->label->setText("发送成功...");
}
