#ifndef DB_H
#define DB_H
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QMessageBox>
static bool createData()
{

    QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("supermarket");
    db.setUserName("root");
    db.setPassword("");


    if(!db.open())
    {
      return false;
    }else

    return true;

}
#endif // DB_H

