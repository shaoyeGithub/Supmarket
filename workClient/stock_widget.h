#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QTableWidget>
#include "socket.h"
namespace Ui {
class Widget;
}

class StockWidget : public QWidget
{
    Q_OBJECT

public:
    explicit StockWidget(QWidget *parent = 0);
    ~StockWidget();
    void divide();
private slots:
    void on_pushButton_clicked();
    void readMessage();
    //void newConnect();
    void on_pushButton_3_clicked();

private:
    Ui::Widget *ui;
    Socket socketClient;
    QVBoxLayout *mainlayout;
    QHBoxLayout *second;
    QHBoxLayout *third;
    QHBoxLayout *first;
    QVBoxLayout *forth;
    int queryNum;
    QString id;
    QString comCode;
    QString comName;
    QString remainingNum;
};

#endif // WIDGET_H
