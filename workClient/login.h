#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QSqlTableModel>
#include <QWidget>
#include <QMovie>
#include <QVBoxLayout>
#include <QLabel>
#include <QMouseEvent>
#include <QTcpSocket>
#include "socket.h"
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
protected:
    void mousePressEvent(QMouseEvent *);

    void mouseMoveEvent(QMouseEvent *);

    void  mouseReleaseEvent(QMouseEvent *);
private slots://私有槽函数

    void on_minWindow();

    void on_pswButton_clicked();

    void on_loginButton_clicked();

    //void newConnect();

    void readMessage();

    void displayError(QAbstractSocket::SocketError socketError);
private:
    Ui::Dialog *ui;
    QPoint mousePoint;//鼠标拖动时的坐标
    bool mousePressed;//是否按下
    int userNum;
    //QTcpSocket *tcpSocket;
    Socket socketClient;
    QString name;
    QString password;
};

#endif // DIALOG_H
