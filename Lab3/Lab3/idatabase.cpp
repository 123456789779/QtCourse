#include "idatabase.h"
#include <QDebug>
void IDatabase::ininDatabase()
{
    database = QSqlDatabase::addDatabase("QSQLITE");
    QString aFile = "E:/navicat/DB/Lab4a.db";
    database.setDatabaseName(aFile);

    if (!database.open()) {
        qDebug() << "failed to open database";
    } else
        qDebug() << "open databse is ok" << database.connectionName();
}

QString IDatabase::userLogin(QString userName, QString password)
{
//    return "loginOK";
    QSqlQuery query;
    query.prepare("select username,password from user where username=:USER");
    query.bindValue(":USER", userName);
    query.exec();
    if (query.first() && query.value("username").isValid()) {
        QString passwd = query.value("password").toString();
        if (passwd == password) {
            return "loginOK";
        } else {
            return "wrongPassword";
        }
    } else {
        qDebug() << "no such user";
        return "wrongUsername";
    }


}

IDatabase::IDatabase(QObject *parent) : QObject(parent)
{
    ininDatabase();
}
