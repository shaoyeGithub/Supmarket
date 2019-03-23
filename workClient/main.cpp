#include "stock_widget.h"
#include <QApplication>
#include "login.h"
#include "mainwindow.h"
#include "stock_widget.h"
#include "add_stock.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Dialog dlg;
    StockWidget wid;
    AddStock ads;
   if(dlg.exec()== QDialog::Accepted )
     {
        ads.show();
        return a.exec();
     }
      else
         return 0;
}
