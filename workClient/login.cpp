#include "login.h"
#include "ui_login.h"
#include <QMessageBox>
#include <QSqlTableModel>
#include <QToolButton>
//#include "db.h"
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    socketClient.setTcpSocket(new QTcpSocket(this));
      // gif 图片背景
    QLabel *pBack = new  QLabel(this);
    QMovie *movie = new QMovie();

    movie->setFileName(":/back1.gif");
    movie->start();//动画开始
    movie->stop();//动画结束

    pBack->setMovie(movie);

    movie->start();
    pBack->move(0,0);
    //top->addItem(pBack);

    ui->accountComboBox->setEditable(true);
    QLineEdit* lineEdit = ui->accountComboBox->lineEdit();
    lineEdit->setPlaceholderText(QStringLiteral("手机/邮箱"));
    ui->passwordEdit->setPlaceholderText(QStringLiteral("密码"));

    //隐藏边框
    this->setWindowFlags(Qt::FramelessWindowHint);

    //自定义最小化和关闭
    // 获取页面宽度
    int width =this->width();

    //构建最小化和关闭按钮
    QToolButton *minButton = new QToolButton(this);
    QToolButton *closeButton = new QToolButton(this);

    //获取最小化、关闭图标
    QPixmap minPix = style()->standardPixmap(QStyle::SP_TitleBarMinButton);
    QPixmap closePix = style()->standardPixmap(QStyle::SP_TitleBarCloseButton);


    //设置按钮图标
    minButton->setIcon(minPix);
    closeButton->setIcon(closePix);

    //设置按钮在界面的位置
    minButton ->setGeometry(width-46,5,20,20);
    closeButton ->setGeometry(width-25,5,20,20);

    //设置鼠标移至的按钮提示信息
    minButton ->setToolTip(tr("最小化"));
    closeButton ->setToolTip(tr("关闭"));

    minButton ->setStyleSheet("background-color:transparent");
    closeButton ->setStyleSheet("background-color:transparent");


    connect(minButton,SIGNAL(clicked()),this,SLOT(on_minWindow()));
    connect(closeButton,SIGNAL(clicked()),this,SLOT(close()));

    ui->loginButton->setStyleSheet("background-color:transparent");
    ui->pswButton->setStyleSheet("background-color:transparent");



    connect(socketClient.getTcpSocket(), SIGNAL(readyRead()), this, SLOT(readMessage()));
    connect(socketClient.getTcpSocket(), SIGNAL(error(QAbstractSocket::SocketError)),
               this, SLOT(displayError(QAbstractSocket::SocketError)));


}
void Dialog::readMessage()
{

    socketClient.readMessage();
    QString msg=socketClient.message;
    userNum=msg.toInt();
    ui->label->setText(msg);
    if(userNum==1)
    {

        this->accept();
    }else
    {
      QMessageBox::warning(this,name,password,QMessageBox::Yes);
      ui->passwordEdit->clear();
      ui->accountComboBox->lineEdit()->clear();
      ui->accountComboBox->lineEdit()->setFocus();
    }
}
void Dialog::on_minWindow()
{
    this->showMinimized();

}
Dialog::~Dialog()
{
    delete ui;
}

void Dialog::mouseMoveEvent(QMouseEvent *e)
{
    //globalPos是相对于屏幕的坐标 全局坐标
    //Pos()是窗体 左上角相对于屏幕左上角的坐标
    //button() 返回产生事件的按钮
    //buttons()  返回产生事件的按钮 的状态  发生时间时那些按钮处于按下状态
    if(mousePressed&&(e->buttons() &&Qt::LeftButton))
    {

    this->move(e->globalPos()-mousePoint);

    e->accept();
    }

}

void Dialog::mousePressEvent(QMouseEvent *e)
{
    if(e->button()==Qt::LeftButton)
    {
        mousePressed=true;
        mousePoint =e->globalPos()-this->pos();
        e->accept();
    }


}
void Dialog::mouseReleaseEvent(QMouseEvent *)
{

    mousePressed=false;
}

void Dialog::on_pswButton_clicked()
{

}


void Dialog::on_loginButton_clicked()
{
  socketClient.newConnect();
  name = ui->accountComboBox->lineEdit()->text();
  password = ui->passwordEdit->text();
  QString msg=tr("51").append("/").append(name).append("/").append(password);
  socketClient.sendMessage(msg);
}

void Dialog::displayError(QAbstractSocket::SocketError socketError)
{
    switch (socketError) {
    case QAbstractSocket::RemoteHostClosedError:
        break;
    case QAbstractSocket::HostNotFoundError:
        QMessageBox::information(this, tr(" Client"),
            tr("The host was not found. Please check the "
            "host name and port settings."));
        break;
    case QAbstractSocket::ConnectionRefusedError:
        QMessageBox::information(this, tr(" Client"),
            tr("The connection was refused by the peer. "
            "Make sure the fortune server is running, "
            "and check that the host name and port "
            "settings are correct."));
        break;
    default:
        QMessageBox::information(this, tr(" Client"),
            tr("The following error occurred: %1.")
            .arg(socketClient.getTcpSocket()->errorString()));
    }
}
