#ifndef CAMION_H
#define CAMION_H

#include"arduino.h"
#include"inter.h"
#include"login.h"
#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include<QVBoxLayout>
#include<QFrame>
#include<QLabel>
#include<QPushButton>
#include<QLineEdit>
#include<QPixmap>
#include<QFont>
#include<QComboBox>
#include<QGraphicsDropShadowEffect>
#include<QPropertyAnimation>
#include <QStylePainter>
#include <QStyleOptionComboBox>
#include<QtCharts>
#include<QChartView>
#include<QPieSeries>
#include<QPieSlice>
#include<QString>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include<QtDebug>
#include<QSqlQueryModel>
#include<QString>
#include<QDate>
#include<QIntValidator>
#include<QRegExpValidator>
#include<QCalendarWidget>
#include <QPrinter>
#include"calendrier.h"
class Camion : public QWidget
{
    Q_OBJECT
public:
    Camion(QWidget *parent=nullptr);
    Camion(QString,QString,QString,QString,int,QDate,QString);
   //Camion(QString,QString,QString);

       void setMatricule( QString val) { matricule = val;}
       void setNbEntretien(int val) {nbEntretien = val;}
       void setDateEntretien( QDate val) {dateEntretien = val;}
       void setDisponibilite( QString val) {disponibilite = val;}
       void setEtat( QString val) {etat = val;}
       void setDestination( QString val) {destination = val;}
       void setNote( QString val) {note = val;}

       QString getMatricule()  {return matricule;}
       int getNbEntretien()  {return nbEntretien;}
       QDate getDateEntretien()  {return dateEntretien;}
       QString getDisponibilite()  {return disponibilite;}
       QString getEtat()  {return etat;}
       QString getDestination()  {return destination;}
       QString getNote()  {return note;}

public:



    bool ajouter_cam();
    QSqlQueryModel *afficher();
    bool supprimer(QString);
    bool update_cam(QString);

    void applyShadow(QWidget *widget);
    int countType(const QString& etat);
    void remplir_combo(QComboBox *mat_supp);
    void updateUI(int selectedMat);
    QSqlQueryModel* tri();
    //void on_mid_currentIndexChanged(int index);
    //void init();
public slots:
    void updatdispo_arduino();
    void refreshTable();
    void sortData();
    //void trier();
    void Recherher();
    void enregistrer();
    void supp_cam();
    void modifier_cam();
    void affiche_modifpopup();
    void exit_modifpopup();
    void afficherHISTO();
    void ecrireDansFichier2(const QString& matricule, const QString& tempsDeMiseAjour);
    void ecrireDansFichier1(const QString& matricule, const QString& tempsAjout);
    void ecrireDansFichier(const QString& matricule, const QString& tempsSuppression);
    //void  load_fromfile();
    void affiche_histopopup();
    void exit_histapopup();
    void showpdf();
    void showpdf2();
private:

    Arduino A;
    QByteArray data;

    QVector<QLabel*> labelWidgets;
        QString matricule;
        QString etat;
        QString disponibilite;
        QString destination;
        int nbEntretien;
        QDate dateEntretien;
        QString note;

        QFrame *rechercher;
        QLineEdit *recherche;
        QPushButton *btn_search;
        QPushButton *trie;

        QLabel *tableau_lab;
        QLabel *ajouter_lab;
        QLabel *calendrier_lab;
        QLabel *stat_lab;
        QFrame *tableau;
        QFrame *ajouter;
        QFrame *calendar;
        QFrame *stat;
        QTableView *list;

        QPushButton *pdf_btn;
        QPushButton *refrech_btn;

QLineEdit *info_ajout1[4];
QComboBox *info_ajout2[2];
QDateEdit *date_ajout;

QComboBox *mat_supp;

QPushButton *ajout_btn;
QPushButton *supp_btn;
QPushButton *modif_btn;


QLabel *modif_lab;
QLineEdit *info_modif1[3];
QComboBox *info_modif2[3];
QDateEdit *date_modif;
QPushButton *modif_btnBox;
QPushButton *exit_modif;



QPushButton *histo_btn;
QLabel *histolab;
QTableView *historique;
QPushButton *leave_histo;

QCalendarWidget *calen;
};

#endif // CAMION_H
