#ifndef CONNECTION_H
#define CONNECTION_H
#include "QtSql/QSqlDatabase"
#include "QtSql/qsqlquery.h"
#include "QtSql/QSqlError"

class Connection
{
    QSqlDatabase db;
public:
    Connection();
    bool createConnection();
    int Authentification(QString loginn,QString nom);


    void closeConnection();
};

#endif // CONNECTION_H
