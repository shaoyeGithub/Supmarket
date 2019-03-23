#include "add_stock.h"
#include "ui_add_stock.h"
#include <QMessageBox>
AddStock::AddStock(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::add_stock)
{
    ui->setupUi(this);
    socketClient.setTcpSocket(new QTcpSocket(this));
    connect(socketClient.getTcpSocket(), SIGNAL(readyRead()), this, SLOT(readMessage()));
}

AddStock::~AddStock()
{
    delete ui;
}

void AddStock::on_pushButton_clicked()
{
     QString comCode=ui->lineEdit->text();
     QString number=ui->lineEdit_2->text();

     QString msg=comCode.append("/").append(number);

     socketClient.newConnect();

     socketClient.sendMessage(msg);
}

void AddStock::on_pushButton_2_clicked()
{
    this->close();
}
void AddStock::readMessage()
{
  socketClient.readMessage();
  if(socketClient.message.toInt()==1)
  {
      QMessageBox::information(this,tr("添加库存"),tr("添加成功"),QMessageBox::Yes);
  }else{
      QMessageBox::information(this,tr("添加库存"),tr("添加失败"),QMessageBox::Yes);
  }
}
