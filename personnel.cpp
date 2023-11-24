#include "personnel.h"
#include<QSqlQuery>
#include<QtDebug>
#include<QString>
#include<QSqlDatabase>
#include<QSqlError>
#include <QSqlQueryModel>
#include <QObject>
Personnel::Personnel()
{
    nom="";
    prenom="";
    cin="";
    age="";
    email="";
    role="";
    statut="";
    telephone="";
    sexe="";
    salaire="";
}
Personnel::Personnel(QString a,QString b,QString c,QString d,QString e,QString f,QString g,QString h,QString i,QString j)
{
    nom=a;
    prenom=b;
    cin=c;
    age=d;
    email=e;
    role=f;
    statut=g;
    telephone=h;
    sexe=i;
    salaire=j;
}
QString Personnel::getnom(){return nom;}
QString Personnel::getprenom(){return  prenom;}
QString Personnel::getcin(){return  cin;}
QString Personnel::getage(){return age;}
QString Personnel::getemail(){return email;}
QString Personnel::getrole(){return role;}
QString Personnel::getstatut(){return statut;}
QString Personnel::gettelephone(){return  telephone;}
QString Personnel::getsexe(){return  sexe;}
QString Personnel::getsalaire(){return salaire;}
void Personnel::setnom(QString a){nom=a;}
void Personnel::setprenom(QString b){prenom=b;}
void Personnel::setcin(QString c){cin=c;}
void Personnel::setage(QString d){age=d;}
void Personnel::setemail(QString e){email=e;}
void Personnel::setrole(QString f){role=f;}
void Personnel::setstatut(QString g){statut=g;}
void Personnel::settelephone(QString h){telephone=h;}
void Personnel::setsexe(QString i){sexe=i;}
void Personnel::setsalaire(QString j){salaire=j;}
bool Personnel::ajouter()
{
    QSqlQuery query;
          query.prepare("INSERT INTO PERSONNEL (NOM,PRENOM,CIN,AGE,EMAIL,ROLE,STATUT,TELEPHONE,SEXE,SALAIRE ) "
                        "VALUES (:nom,:prenom,:cin,:age,:email,:role,:statut,:telephone,:sexe,:salaire)");

          query.bindValue(":nom", nom);
          query.bindValue(":prenom", prenom);
          query.bindValue(":cin", cin );
          query.bindValue(":age", age);
          query.bindValue(":email", email);
          query.bindValue(":role", role);
          query.bindValue(":statut", statut );
          query.bindValue(":telephone", telephone);
          query.bindValue(":sexe", sexe);
          query.bindValue(":salaire", salaire );


          /*if (!query.exec()) {
              qDebug() << "Erreur de requête : " << query.lastError().text();
          }*/
       return query.exec();


}
QSqlQueryModel* Personnel::afficher()
{


    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT* FROM personnel");
    model->setHeaderData(0, Qt::Vertical, QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Vertical, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Vertical, QObject::tr("Prenom"));
    model->setHeaderData(3, Qt::Vertical, QObject::tr("AGE"));
    model->setHeaderData(4, Qt::Vertical, QObject::tr("EMAIL"));
    model->setHeaderData(5, Qt::Vertical, QObject::tr("ROLE"));
    model->setHeaderData(6, Qt::Vertical, QObject::tr("STATUT"));
    model->setHeaderData(7, Qt::Vertical, QObject::tr("TELEPHONE"));
    model->setHeaderData(8, Qt::Vertical, QObject::tr("SEXE"));
    model->setHeaderData(9, Qt::Vertical, QObject::tr("SALAIRE"));
    return model;

}
bool Personnel::supprimer(QString cin)
{

    if (rechercherParId(cin))
    {
        QSqlQuery query;
        query.prepare("DELETE FROM personnel WHERE CIN = :cin");
        query.bindValue(":cin", cin);

        if (query.exec())
        {
            return true; // La suppression a réussi
        }

    }
    return false;

}
bool Personnel::rechercherParId(QString cin)
{

    QSqlQuery query;
    query.prepare("SELECT * FROM PERSONNEL WHERE CIN = :cin");
    query.bindValue(":cin", cin);

    if (query.exec() && query.next()) {

        return true;
    } else {

        return false;
    }

}
bool Personnel::modifier(QString cin, QString nouveauNom, QString nouveauPrenom, QString nouveauAge)
{

    QSqlQuery query;

    query.prepare("UPDATE PERSONNEL SET NOM = :nouveauNom, PRENOM = :nouveauPrenom, AGE = :nouveauAge WHERE CIN =:cin");
    if (!nouveauNom.isEmpty() && !nouveauPrenom.isEmpty()) {
                query.bindValue(":cin", cin);
                query.bindValue(":nouveauNom", nouveauNom);
                query.bindValue(":nouveauPrenom", nouveauPrenom);
                query.bindValue(":nouveauAge", nouveauAge);

                if (query.exec())
                {
                    return true; // La modification a réussi
                }
                else
                {
                    qDebug() << "Erreur lors de la modification : " << query.lastError().text();
                }
            }

return false;

}
QSqlQueryModel* Personnel::trisalaire()
{
    QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("SELECT * from PERSONNEL ORDER BY NOM ");
        return model;
}
QSqlQueryModel* Personnel::chercher_Personnel(QString CIN)
{
    QSqlQueryModel *model = new QSqlQueryModel();
       QSqlQuery query;
       query.prepare("SELECT * FROM PERSONNEL WHERE CIN = :CIN");
       query.bindValue(":CIN", CIN);
       query.exec();

       model->setQuery(query);

        return model;
}
