#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Source_Projet2A");
db.setUserName("Anas");//inserer nom de l'utilisateur
db.setPassword("esprit18");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;

    return  test;
}
int Connection::Authentification(int loginn,QString nom)
{
    QSqlDatabase bd = QSqlDatabase::database();

        QSqlQuery query;
        QString log=QString::number(loginn);
        query.prepare("SELECT * FROM ETUDIANT where CIN_FOUR=\'"+log+"\' AND NOM_FOUR=\'"+nom+"\'");

        query.exec();
        if (query.next())
        {
             return 1;
        }

        else {
            return 0;
        }



}
