#ifndef ADD_STOCK_H
#define ADD_STOCK_H

#include <QWidget>
#include "socket.h"
namespace Ui {
class add_stock;
}

class AddStock : public QWidget
{
    Q_OBJECT

public:
    explicit AddStock(QWidget *parent = 0);
    ~AddStock();

private slots:
    void on_pushButton_clicked();
    void readMessage();
    void on_pushButton_2_clicked();

private:
      Ui::add_stock *ui;
     Socket socketClient;
};

#endif // ADD_STOCK_H
