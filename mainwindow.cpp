#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "conteneur.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->comboBox->addItem("Trier");
    ui->comboBox->addItem("Etat");
    ui->comboBox->addItem("Taille");



    ui->a_etat->addItem("Etat");
    ui->a_etat->addItem("Sature");
    ui->a_etat->addItem("Non sature");

    ui->a_taille->addItem("Taille");
    ui->a_taille->addItem("Petite");
    ui->a_taille->addItem("Moyenne");
    ui->a_taille->addItem("Grande");

    ui->table->setModel(C.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_bt_ajout_clicked()
{
    QString code=ui->a_code->text();
    QString etat=ui->a_etat->currentText();
    QString taille=ui->a_taille->currentText();
    QString location=ui->a_localisation->text();
    Conteneur C(code,etat,taille,location);
    bool test=C.ajouter();
    if(test)
    {
        QMessageBox::information(nullptr , QObject::tr("OK"),QObject::tr("Ajout effectué\nClick Cancel to exit."),QMessageBox::Cancel);
    }
    else {
        QMessageBox::critical(nullptr,QObject::tr("NOT OK"),QObject::tr("Ajout non effectué\nClick Cancel to exit."),QMessageBox::Cancel);
    }
     ui->table->setModel(C.afficher());
}

void MainWindow::on_bt_supprimer_clicked()
{
    Conteneur C1;
    C1.setcode(ui->m_code->text());
    bool test=C1.supprimer(C1.getcode());
    if(test){
        QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("Suppression effectuée\nClick Cancel to exit."),QMessageBox::Cancel);
    }
    else {
        QMessageBox::critical(nullptr,QObject::tr("Not OK"),QObject::tr("Suppression non effectuée.\nClick Cancel to exit."),QMessageBox::Cancel);
    }
    ui->table->setModel(C.afficher());
}



