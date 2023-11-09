#include "gestionmachine.h"
#include<QSqlQuery>
#include <QtDebug>
#include<QObject>

Gestionmachine::Gestionmachine()
{
id=0 ; type=" " ; etat=" " ; da=" ";
}
Gestionmachine::Gestionmachine(int id , QString type , QString etat , QString da)
{this->id=id; this->type=type ;this->etat=etat;this->da=da;}

int Gestionmachine::getid(){return id;}
QString Gestionmachine::gettype(){return type;}
QString Gestionmachine::getetat(){return etat;}
QString Gestionmachine::getda(){return da;}

void Gestionmachine::setid(int id){this->id=id;}
void Gestionmachine::settype(QString type){this->type=type;}
void Gestionmachine::setetat(QString etat){this->etat=etat;}
void Gestionmachine::setda(QString da){this->da=da;}

bool Gestionmachine::ajouter()

{
    QSqlQuery query;
    QString id_string= QString::number(id);
          query.prepare("INSERT INTO MACHINE (ID, ETAT,DATE_ACHAT ) "
                        "VALUES (:ID, :ETAT, :DATE_ACHAT)");
          query.bindValue(":ID", id_string);
          query.bindValue(":ETAT", etat);
          query.bindValue(":DATE_ACHAT", da);
          return query.exec();

}
bool Gestionmachine::supprimer(int id)
{


    QSqlQuery query;
          query.prepare("Delete from MACHINE where id=:id");
          query.bindValue(0,id);
          return query.exec();

}
QSqlQueryModel* Gestionmachine::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();


    model->setQuery("SELECT*  FROM MACHINE");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("etat"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("date_achat"));




    return model;
}

bool Gestionmachine::modifier(int id , QString etat , QString da)
{
    QSqlQuery query ;
    QString id_string= QString::number(id);
          query.prepare("UPDATE MACHINES SET id= :ID, etat= :ETAT,da= :DATE_ACHAT ");
          query.bindValue(":ID", id_string);
          query.bindValue(":ETAT", etat);
          query.bindValue(":DATE_ACHAT", da);
          return query.exec();
}


