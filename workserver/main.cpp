#include "login_widget.h"
#include "stock_widget.h"
#include "socket.h"
#include "servermainwindow.h"
#include <QApplication>
#include "db.h"
#include "addstock.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    if(createData())
    {
    ServerMainWindow w;
    w.show();
    return a.exec();
    }
    else
    {
        return 0;
    }
}
