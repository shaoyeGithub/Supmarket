#ifndef SERVERMAINWINDOW_H
#define SERVERMAINWINDOW_H
#include <QtNetwork>
#include <QMainWindow>
#include "server.h"
namespace Ui {
class ServerMainWindow;
}

class ServerMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ServerMainWindow(QWidget *parent = 0);
    ~ServerMainWindow();

private:
    Ui::ServerMainWindow *ui;
    Server myServer;
};

#endif // SERVERMAINWINDOW_H
