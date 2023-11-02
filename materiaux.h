#ifndef ETUDIANT_H
#define ETUDIANT_H
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QObject>


class Etudiant
{
public:
    Etudiant();
    Etudiant(int,QString,QString);
    int getid();
    QString getnom();
    QString getprenom();
    void setid(int);
    void setnom(QString);
    void setprenom(QString);
    bool ajouter();
    QSqlQueryModel *afficher();
    bool supprimer(int id);
    bool modifier(int id, QString nouveauNom, QString nouveauPrenom);


private:
    int id;
    QString nom,prenom;
};

#endif // ETUDIANT_H
