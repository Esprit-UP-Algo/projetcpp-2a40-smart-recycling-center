#include "connexion.h"

Connexion::Connexion()
{

}

bool Connexion::createconnect()
{
    bool test=false;
        db = QSqlDatabase::addDatabase("QODBC");
        db.setDatabaseName("source_projet2A");
        db.setUserName("aziz");//inserer nom de l'utilisateur
        db.setPassword("esprit18");//inserer mot de passe de cet utilisateur

        if (db.open())
            test=true;
    return  test;
}
void Connexion::closeConnect(){db.close();}
