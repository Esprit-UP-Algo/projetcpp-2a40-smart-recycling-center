#ifndef PERSONNEL_H
#define PERSONNEL_H
#include <QString>
#include <QSqlQueryModel>
class Personnel
{

public:
    Personnel();
    Personnel(QString ,QString ,QString ,QString ,QString ,QString ,QString ,QString ,QString ,QString );
    QString getnom();
    QString getprenom();
    QString getcin();
    QString getage();
    QString getemail();
    QString getrole();
    QString getstatut();
    QString gettelephone();
    QString getsexe();
    QString getsalaire();
    void setnom(QString a);
    void setprenom(QString b);
    void setcin(QString c);
    void setage(QString d);
    void setemail(QString e);
    void setrole(QString f);
    void setstatut(QString g);
    void settelephone(QString h);
    void setsexe(QString i);
    void setsalaire(QString j);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(QString);
    bool rechercherParId(QString cin);
    bool modifier(QString cin, QString nouveauNom, QString nouveauPrenom, QString nouveauAge);
    QSqlQueryModel* trisalaire();
    QSqlQueryModel* chercher_Personnel(QString CIN);
private:
    QString nom;
    QString prenom;
    QString cin;
    QString age;
    QString email;
    QString role;
    QString statut;
    QString telephone;
    QString sexe;
    QString salaire;

};

#endif // PERSONNEL_H
