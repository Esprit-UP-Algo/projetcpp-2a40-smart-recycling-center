#include "materiaux.h"
#include <QString>
#include <QSqlQuery>
#include <QtDebug>
#include <QSqlQueryModel>
#include <QObject>
#include <QPdfWriter>
#include <QFileDialog>
#include <QPainter>
#include <QTextDocument>
#include <QTimer>
#include <QPrinter>


Materiaux::Materiaux()
{
    id=0;
    type="";
    quantite=0;
    destination="";
    pointdesuivi=0;
}
Materiaux::Materiaux(int id,QString type,int quantite,QString destination,int pointdesuivi)
{
    this->id=id;
    this->type=type;
    this->quantite=quantite;
    this->destination=destination;
    this->pointdesuivi=pointdesuivi;

}
int Materiaux::getid()
{
    return id;
}
QString Materiaux::gettype()
{
    return type;
}
int Materiaux::getquantite()
{
    return quantite;
}
QString Materiaux::getdestination()
{
    return destination;
}
int Materiaux::getpointdesuivi()
{
    return pointdesuivi;
}

void Materiaux::setid(int id)
{
    this->id=id;
}
void Materiaux::settype(QString type)
{
    this->type=type;
}
void Materiaux::setquantite(int quantite)
{
    this->quantite=quantite;
}
void Materiaux::setdestination(QString destination)
{
    this->destination=destination;
}
void Materiaux::setpointdesuivi(int pointdesuivi)
{
    this->pointdesuivi=pointdesuivi;
}
bool Materiaux::ajouter()
{

    QSqlQuery query;
    QString id_string= QString::number(id);
     query.prepare("INSERT INTO Materiau (id, type, quantite,destination, pointdesuivi) "
                  "VALUES (:id, :type, :quantite,:destination, :pointdesuivi)");
     query.bindValue(":id", id_string);
     query.bindValue(":type", type);
     query.bindValue(":quantite", quantite);
     query.bindValue(":destination", destination);
     query.bindValue(":pointdesuivi", pointdesuivi);
     return query.exec();

}
bool Materiaux::rechercherParId(int id)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM materiau WHERE id = :id");
    query.bindValue(":id", id);

    if (query.exec() && query.next()) {
        // Si la requête s'exécute avec succès et au moins une ligne est renvoyée, l'ID existe
        return true;
    } else {
        // Sinon, l'ID n'existe pas ou il y a une erreur dans la requête
        return false;
    }
}
QSqlQueryModel* Materiaux::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();

    model->setQuery("SELECT* FROM materiau");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Type"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Quantite"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Destination"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Pointdesuivi"));

    /*QSqlQueryModel *model = new QSqlQueryModel;
         model->setQuery("SELECT name, salary FROM employee");
         model->setHeaderData(0, Qt::Horizontal, tr("Name"));
         model->setHeaderData(1, Qt::Horizontal, tr("Salary"));*/
    return model;

}
bool Materiaux::modifier(int id, QString nouveauType, int nouveauQuantite, QString nouveauDestination, int nouveauPointdesuivi)
{
    QSqlQuery query;
    query.prepare("UPDATE materiau SET type = :type, quantite = :quantite, destination= :destination, pointdesuivi= :pointdesuivi WHERE id = :id");
    query.bindValue(":id", id);
    query.bindValue(":type", nouveauType);
    query.bindValue(":quantite", nouveauQuantite);
    query.bindValue(":destination", nouveauDestination);
    query.bindValue(":pointdesuivi", nouveauPointdesuivi);

    return query.exec();
}
QSqlQueryModel* Materiaux::chercher_Materiaux(int id)
{
    QSqlQueryModel *model = new QSqlQueryModel();
       QSqlQuery query;
       query.prepare("SELECT * FROM materiau WHERE id = :id");
       query.bindValue(":id", id);
       query.exec();

       model->setQuery(query);

        return model;

}
QSqlQueryModel * Materiaux::tri()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * from materiau ORDER BY quantite DESC");

    model->setHeaderData(0,Qt::Horizontal,QObject::tr("quantite"));

    return model;
}
bool Materiaux::supprimer(int id)
{
    QSqlQuery query;
    QString res = QString::number(id);
    query.prepare("DELETE FROM materiau WHERE id = :id");
    query.bindValue(":id",id);
    return query.exec();
}
void Materiaux::imprimerTableau(QTableView *tableView)
{
    QPrinter printer(QPrinter::PrinterResolution);
    QPrintDialog printDialog(&printer, nullptr);

    if (printDialog.exec() == QDialog::Accepted) {
        QPainter painter(&printer);
        painter.setWindow(0, 0, printer.pageRect().width(), printer.pageRect().height());
        tableView->render(&painter);
    }
}
QMap<QString, int> Materiaux::getStatistiquesParType()
{
    QMap<QString, int> statistiques;

    QSqlQuery query;
    query.prepare("SELECT type, COUNT(*) FROM materiau GROUP BY type");
    if (query.exec()) {
        while (query.next()) {
            QString type = query.value(0).toString();
            int count = query.value(1).toInt();
            statistiques[type] = count;
        }
    }

    return statistiques;
}


