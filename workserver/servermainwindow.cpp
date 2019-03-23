#include "servermainwindow.h"
#include "ui_servermainwindow.h"
#include <qDebug>
ServerMainWindow::ServerMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ServerMainWindow)
{
    ui->setupUi(this);
    myServer.setTcpServer(new QTcpServer(this));
//    myServer.getTcpServer()->listen(QHostAddress::Any,1234);
    if (!myServer.getTcpServer()->listen(QHostAddress::Any,1234))
    {
        qDebug()<<"我在这";
        //QMessageBox::critical 提示对话框
        close();
        return;
    }
    qDebug()<<"wei";
}

ServerMainWindow::~ServerMainWindow()
{
    delete ui;
}
