#include "conteneur.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
Conteneur::Conteneur()
{
code=""; etat=""; taille=""; location="";
}

Conteneur::Conteneur(QString code,QString etat,QString taille,QString location)
{
    this->code=code ; this->etat=etat ;this->taille=taille ; this->location=location ;
}
QString Conteneur::getcode()
{
    return code;
}
QString Conteneur::getetat()
{
    return etat;
}
QString Conteneur::gettaille()
{
    return taille;
}
QString Conteneur::getlocation()
{
    return location;
}
void Conteneur::setcode(QString code)
{
    this->code=code ;
}
void Conteneur::setetat(QString etat)
{
    this->etat=etat ;
}
void Conteneur::settaille(QString taille)
{
    this->taille=taille ;
}
void Conteneur::setlocation(QString location)
{
    this->location=location ;
}
bool Conteneur::ajouter()
{

    QSqlQuery query;
    query.prepare("INSERT INTO CONTENEUR(CODE, ETAT, TAILLE, LOCALISATION) "
                        "VALUES (:code, :etat, :taille, :localisation)");
    query.bindValue(":code",code);
    query.bindValue(":etat",etat);
    query.bindValue(":taille",taille);
    query.bindValue(":localisation",location);
    return query.exec();


}
bool Conteneur::supprimer(QString code)
{

    QSqlQuery query;
    query.prepare("Delete from conteneur where code=:code" );
    query.bindValue(":code",code);
    return query.exec();


}

QSqlQueryModel* Conteneur::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();
        model->setQuery("SELECT code, etat,taille FROM conteneur");
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("Code"));
        model->setHeaderData(1, Qt::Horizontal,QObject::tr("Etat"));
        model->setHeaderData(2, Qt::Horizontal,QObject::tr("Taille"));
    return model;
}
