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
    db.setDatabaseName("user");
    db.setUserName("root");
    db.setPassword("");


    if(!db.open())
    {
      //QMessageBox::critical(this,tr("数据库"),tr("连接不成功"));
    }
    //QSqlDatabase query(db);

//    query.exec("create table student(id int primary key,"
//               "name varchar(20))");
//    query.exec("insert into  student values(1,'abcd')");
//    query.exec("insert into  student values(3,'ab')");
//    query.exec("insert into  student values(2,'abc')");
//    query.exec("select id,name from student where id>=2");

}
#endif // DB_H

