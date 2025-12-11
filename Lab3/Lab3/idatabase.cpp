#include "idatabase.h"

void IDatabase::ininDatabase()
{
    database = QSqlDatabase::addDatabase("QSQLITE");
    QString aFile = "E:/navicat/DB/Lab4a.db";
    database.setDatabaseName(aFile);

    if (!database.open()) {
        qDebug() << "failed to open database";
    } else
        qDebug() << "open databse is ok";
}

IDatabase::IDatabase(QObject *parent) : QObject(parent)
{
    ininDatabase();
}
