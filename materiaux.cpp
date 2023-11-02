#include "etudiant.h"
#include <QString>
#include <QSqlQuery>
#include <QtDebug>
#include <QSqlQueryModel>
#include <QObject>

Etudiant::Etudiant()
{
  id=0; nom=""; prenom="";
}

Etudiant::Etudiant(int id,QString nom,QString prenom)
{this->id=id;this->nom=nom;this->prenom=prenom;}
int Etudiant::getid(){return id;}
QString Etudiant::getnom(){return nom;}
QString Etudiant::getprenom(){return prenom;}
void Etudiant::setid(int id){this->id=id;}
void Etudiant::setnom(QString nom ){this->nom=nom;}
void Etudiant::setprenom(QString prenom){this->prenom=prenom;}
bool Etudiant::ajouter()
{

    QSqlQuery query;
    QString id_string= QString::number(id);
     query.prepare("INSERT INTO ETUDIANT (id, nom, prenom) "
                  "VALUES (:id, :nom, :prenom)");
     query.bindValue(":id", id_string);
     query.bindValue(":nom", nom);
     query.bindValue(":prenom", prenom);
     return query.exec();

}

QSqlQueryModel* Etudiant::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();

    model->setQuery("SELECT* FROM etudiant");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));

    /*QSqlQueryModel *model = new QSqlQueryModel;
         model->setQuery("SELECT name, salary FROM employee");
         model->setHeaderData(0, Qt::Horizontal, tr("Name"));
         model->setHeaderData(1, Qt::Horizontal, tr("Salary"));*/
    return model;
}
bool Etudiant::supprimer(int id)
{
    QSqlQuery query;
     query.prepare("DELETE FROM etudiant WHERE id= :id");
     query.bindValue(":id", id);
    /*query.bindValue(":IdRapp",IdRapp); */

     return query.exec();
}
bool Etudiant::modifier(int id, QString nouveauNom, QString nouveauPrenom)
{
    QSqlQuery query;
    query.prepare("UPDATE etudiant SET nom = :nom, prenom = :prenom WHERE id = :id");
    query.bindValue(":id", id);
    query.bindValue(":nom", nouveauNom);
    query.bindValue(":prenom", nouveauPrenom);

    return query.exec();
}
