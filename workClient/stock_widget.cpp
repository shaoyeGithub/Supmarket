#include "stock_widget.h"
#include "ui_stock_widget.h"

StockWidget::StockWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    first =new QHBoxLayout;
    second =new QHBoxLayout;
    third =new QHBoxLayout;
    forth =new QVBoxLayout;
    mainlayout = new QVBoxLayout;

    //设置布局
    this->setWindowTitle(tr("库存管理"));
    first->addWidget(ui->pushButton_2);
    first->addWidget(ui->pushButton_3);
    first->addWidget(ui->pushButton_4);
    first->addWidget(ui->pushButton_5);
    first->setSpacing(5);
    first->addStretch();

    second->addStretch();
    second->addWidget(ui->pushButton_6);
    second->addWidget(ui->pushButton_7);
    second->addWidget(ui->pushButton_8);

    third->addStretch();
    third ->addWidget(ui->label);
    //ui->comboBox->lineEdit()->setText(tr("饮料"));
    //ui->comboBox->lineEdit()->setText(tr("零食"));

    third->addWidget(ui->comboBox);
    third->addWidget(ui->label_2);
    third->addWidget(ui->lineEdit);
    third->addWidget(ui->pushButton);
    third->addStretch();

    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    forth->addWidget(ui->tableWidget);

    mainlayout->addLayout(first);
    mainlayout->addLayout(second);
    mainlayout->addLayout(third);
    mainlayout->addLayout(forth);

    this->setLayout(mainlayout);

    socketClient.setTcpSocket(new QTcpSocket(this));
    connect(socketClient.getTcpSocket(), SIGNAL(readyRead()), this, SLOT(readMessage()));
}

StockWidget::~StockWidget()
{
    delete ui;
}

void StockWidget::on_pushButton_clicked()
{
    socketClient.newConnect();
    QString msg;
    msg=ui->lineEdit->text();

   if(msg.isEmpty())
       socketClient.sendMessage("点击为空");
   else
       socketClient.sendMessage(msg);
    //ui->message->setText(message);
}
void StockWidget::divide(){

    //分离出message中的各个类型信息
    QStringList strlist1=socketClient.message.split("~");
    id = strlist1.at(0);
    comCode = strlist1.at(1);
    remainingNum= strlist1.at(2);
    comName= strlist1.at(3);
    //setTable();
}
void StockWidget::readMessage()
{
        int rowCount;
        socketClient.readMessage();
        divide();
        QStringList id_list = id.split("/");
        QStringList comCode_list = comCode.split("/");
        QStringList remainingNum_list=remainingNum.split("/");
        QStringList comName_list=comName.split("/");

        rowCount = id_list.count();

        ui->tableWidget->setRowCount(rowCount-1);

        for(int i=1;i<rowCount;i++){
                QTableWidgetItem *item1 = new QTableWidgetItem;
                QTableWidgetItem *item2 = new QTableWidgetItem;
                QTableWidgetItem *item3 = new QTableWidgetItem;
                QTableWidgetItem *item4 = new QTableWidgetItem;
                item1->setText(id_list.at(i));
                item2->setText(comCode_list.at(i));
                item3->setText(comName_list.at(i));
                item4->setText(remainingNum_list.at(i));
                ui->tableWidget->setItem(i-1,0,item1);
                ui->tableWidget->setItem(i-1,1,item2);
                ui->tableWidget->setItem(i-1,2,item3);
                ui->tableWidget->setItem(i-1,3,item4);
           qDebug()<<"asdasdada"<<id_list.at(i);
            }

}

void StockWidget::on_pushButton_3_clicked()
{

}
