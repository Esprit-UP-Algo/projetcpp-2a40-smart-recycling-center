#include "inter.h"
#include"login.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsWidget>
#include <QGraphicsRotation>
#include <QPropertyAnimation>
#include<QParallelAnimationGroup>
#include<QSequentialAnimationGroup>
#include<QObject>
#include <QWidget>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QApplication>
#include<QPixmap>
#include<QLabel>
#include<QLineEdit>
#include<QPushButton>
#include <QGraphicsDropShadowEffect>
#include<QList>
#include<QDebug>
Inter::Inter(QMainWindow  *loginlab , QWidget *parent)
    :QMainWindow(parent),loginlab(loginlab)
{
    this->resize(1280,832);
    this->setStyleSheet("background:white;");

    QFrame *box = new QFrame(this);
    box->setStyleSheet("background:qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:1 #1890a1, stop:0.5 #54cdb7);");
    box->setGeometry(0,110,1280,682);
    gest_camions = new QPushButton("Gest des camions",this);
    gest_camions->setStyleSheet("background:#1890a1;border-radius:10px;color:white;font-size:20px;font-family:Arial;");
    gest_camions->setGeometry(100,85,200,30);
    gest_contenaire = new QPushButton("Gest de conteneurs",this);
    gest_contenaire->setStyleSheet("background:transparent;color:#1890a1;font-size:20px;font-family:Arial;");
    gest_contenaire->setGeometry(310,85,200,30);
    gest_personelle = new QPushButton("Gest du personnel",this);
    gest_personelle->setStyleSheet("background:transparent;color:#1890a1;font-size:20px;font-family:Arial;");
    gest_personelle->setGeometry(520,85,200,30);
    gest_dons = new QPushButton("Gest des dons",this);
    gest_dons->setStyleSheet("background:transparent;color:#1890a1;font-size:20px;font-family:Arial;");
    gest_dons->setGeometry(730,85,200,30);
    gest_matrielle = new QPushButton("Gest des matériaux recyclés",this);
    gest_matrielle->setStyleSheet("background:transparent;color:#1890a1;font-size:20px;font-family:Arial;");
    gest_matrielle->setGeometry(940,85,270,30);

    /*QFrame *boxx = new QFrame(box);
    QHBoxLayout *layout = new QHBoxLayout(boxx);*/


    QLineEdit *recherche=new QLineEdit(this);
    recherche->setPlaceholderText("Rechercher");
    recherche->setStyleSheet("background:#54cdb7;border-top-right-radius:20px;border-bottom-right-radius:20px;");
    recherche->setGeometry(100,170,240,50);

    QPixmap icon(":/symbole-de-linterface-de-recherche.png");

    QPushButton *bow=new QPushButton(this);
    bow->setStyleSheet("background:#54cdb7;border-top-left-radius:20px;border-bottom-left-radius:20px;color:white;font-size:30px;font-family:Arial;");
    bow->setIcon(QIcon(icon));
    bow->setGeometry(50,170,50,50);

    QPushButton *ajout = new QPushButton("Trier",this);
    ajout->setStyleSheet("background:#54cdb7;border-radius:20px;");
    ajout->setGeometry(380,170,100,50);

    QPushButton *pdf=new QPushButton(this);
    pdf->setStyleSheet("background:#54cdb7;border-top-left-radius:20px;border-radius:20px;color:white;font-size:30px;font-family:Arial;");
    pdf->setIcon(QIcon(icon));
    pdf->setGeometry(520,170,50,50);
   /* layout->addWidget(bow);
    layout->addWidget(recherche);
    boxx->setLayout(layout);*/

    QPixmap leave(":/se-deconnecter.png");

    QPushButton *btn_leave=new QPushButton(this);
    btn_leave->setStyleSheet("background:#54cdb7;border-radius:20px;color:white;font-size:30px;font-family:Arial;");
    btn_leave->setIcon(QIcon(leave));
    btn_leave->setGeometry(1220,15,50,50);

     connect(btn_leave, &QPushButton::clicked, this, &Inter::leave_sign);
     connect(gest_contenaire,&QPushButton::clicked,this,&Inter::change_cont);
     connect(gest_camions,&QPushButton::clicked,this,&Inter::change_cami);
     connect(gest_personelle,&QPushButton::clicked,this,&Inter::change_perso);
     connect(gest_dons,&QPushButton::clicked,this,&Inter::change_dons);
     connect(gest_matrielle,&QPushButton::clicked,this,&Inter::change_mat);
}
void Inter::leave_sign()
{
    this->hide();
    loginlab->show();
}
void Inter::change_cont()
{
    gest_camions->setStyleSheet("background:transparent;color:#1890a1;font-size:20px;font-family:Arial;");
    gest_personelle->setStyleSheet("background:transparent;color:#1890a1;font-size:20px;font-family:Arial;");
    gest_dons->setStyleSheet("background:transparent;color:#1890a1;font-size:20px;font-family:Arial;");
    gest_matrielle->setStyleSheet("background:transparent;color:#1890a1;font-size:20px;font-family:Arial;");
    gest_contenaire->setStyleSheet("background:#1890a1;border-radius:10px;color:white;font-size:20px;font-family:Arial;");
}
void Inter::change_cami()
{
    gest_personelle->setStyleSheet("background:transparent;color:#1890a1;font-size:20px;font-family:Arial;");
    gest_contenaire->setStyleSheet("background:transparent;color:#1890a1;font-size:20px;font-family:Arial;");
    gest_dons->setStyleSheet("background:transparent;color:#1890a1;font-size:20px;font-family:Arial;");
    gest_matrielle->setStyleSheet("background:transparent;color:#1890a1;font-size:20px;font-family:Arial;");
    gest_camions->setStyleSheet("background:#1890a1;border-radius:10px;color:white;font-size:20px;font-family:Arial;");
}
void Inter::change_perso()
{
    gest_contenaire->setStyleSheet("background:transparent;color:#1890a1;font-size:20px;font-family:Arial;");
    gest_camions->setStyleSheet("background:transparent;color:#1890a1;font-size:20px;font-family:Arial;");
    gest_dons->setStyleSheet("background:transparent;color:#1890a1;font-size:20px;font-family:Arial;");
    gest_matrielle->setStyleSheet("background:transparent;color:#1890a1;font-size:20px;font-family:Arial;");
    gest_personelle->setStyleSheet("background:#1890a1;border-radius:10px;color:white;font-size:20px;font-family:Arial;");

}
void Inter::change_dons()
{
    gest_contenaire->setStyleSheet("background:transparent;color:#1890a1;font-size:20px;font-family:Arial;");
    gest_camions->setStyleSheet("background:transparent;color:#1890a1;font-size:20px;font-family:Arial;");
    gest_personelle->setStyleSheet("background:transparent;color:#1890a1;font-size:20px;font-family:Arial;");
    gest_matrielle->setStyleSheet("background:transparent;color:#1890a1;font-size:20px;font-family:Arial;");
    gest_dons->setStyleSheet("background:#1890a1;border-radius:10px;color:white;font-size:20px;font-family:Arial;");
}
void Inter::change_mat()
{
    gest_contenaire->setStyleSheet("background:transparent;color:#1890a1;font-size:20px;font-family:Arial;");
    gest_camions->setStyleSheet("background:transparent;color:#1890a1;font-size:20px;font-family:Arial;");
    gest_personelle->setStyleSheet("background:transparent;color:#1890a1;font-size:20px;font-family:Arial;");
    gest_dons->setStyleSheet("background:transparent;color:#1890a1;font-size:20px;font-family:Arial;");
    gest_matrielle->setStyleSheet("background:#1890a1;border-radius:10px;color:white;font-size:20px;font-family:Arial;");
}















