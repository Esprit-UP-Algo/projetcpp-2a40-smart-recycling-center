#ifndef GESTIONMACHINE_H
#define GESTIONMACHINE_H
#include <QString>
#include<QSqlQueryModel>
#include<QSqlQuery>
class Gestionmachine
{
public:
    Gestionmachine();
    Gestionmachine(int,QString,QString,QString);
    int getid();
    QString gettype();
    QString getetat();
    QString getda();
    void setid(int);
    void settype(QString);
    void setetat(QString);
    void setda(QString);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier(int id , QString etat , QString da);



private:
    int id ;
    QString type, etat , da ;
};

#endif // GESTIONMACHINE_H
