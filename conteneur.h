#ifndef CONTENEUR_H
#define CONTENEUR_H
#include <QString>
#include<qsqlquerymodel.h>
class Conteneur
{
public:
    Conteneur();
    Conteneur(QString,QString,QString,QString);
    QString getcode();
    QString getetat();
    QString gettaille();
    QString getlocation();
    void setcode(QString);
    void setetat(QString);
    void settaille(QString);
    void setlocation(QString);

    bool ajouter();
    bool supprimer(QString);
    QSqlQueryModel* afficher();
private:
    QString code , etat , taille , location ;
};

#endif // CONTENEUR_H
