#include "connection.h"
#include "ui_mainwindow.h"

Connection::Connection()
{

}

bool Connection::createConnection()
{
db = QSqlDatabase ::addDatabase("QODBC");
bool test=false;
db.setDatabaseName("Source_Projet2A");
db.setUserName("Anas");//inserer nom de l'utilisateur
db.setPassword("esprit18");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;




    return  test;
}
int Connection::Authentification(QString loginn,QString nom)
{
   // QSqlDatabase bd = QSqlDatabase::database();

        QSqlQuery query;
        query.prepare("SELECT * FROM ETUDIANT where CIN_FOUR=\'"+loginn+"\' AND NOM_FOUR=\'"+nom+"\'");
        query.next();
        if (query.exec())
        {
             return 1;
        }

        else {
            return 0;
        }



}




void Connection ::closeConnection() {db.close();}
