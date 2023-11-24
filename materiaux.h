#ifndef MATERIAUX_H
#define MATERIAUX_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QString>
#include <QMainWindow>
#include <QInputDialog>
#include <QStringList>
#include <QDebug>
#include <QPdfWriter>
#include <QFileDialog>
#include <QPainter>
#include <QTextDocument>
#include <QTimer>
#include<QSqlQueryModel>
#include <QPrintDialog>
#include <QTableView>
#include <QMap>
#include <QTimer>

class Materiaux
{
public:
    Materiaux();
    Materiaux(int,QString,int,QString,int);
    int getid();
    QString gettype();
    int getquantite();
    QString getdestination();
    int getpointdesuivi();
    QString getreception_de_la_demande();
    QString getetat();
    void setid(int);
    void settype(QString);
    void setquantite(int);
    void setdestination(QString);
    void setpointdesuivi(int);
    bool ajouter();
    bool rechercherParId(int id);
    QSqlQueryModel* afficher();
    bool modifier(int id, QString nouveauType, int nouveauQuantite, QString nouveauDestination, int nouveauPointdesuivi);
    QSqlQueryModel* chercher_Materiaux(int id);
    QSqlQueryModel* tri();
    bool supprimer(int id);
    QList<int> getIds();
    bool choisirIdASupprimer();
    void imprimerTableau(QTableView *tableView);
    QMap<QString, int> getStatistiquesParType();


private:
    QString type,destination;
    int id, quantite,pointdesuivi;

};

#endif // MATERIAUX_H
