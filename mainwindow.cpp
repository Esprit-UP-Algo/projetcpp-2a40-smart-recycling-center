#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"gestionmachine.h"
#include<QMessageBox>
#include<QIntValidator>
#include <QDate>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->le_id->setValidator( new QIntValidator(0, 99999999, this));
    ui->le_idmod->setValidator( new QIntValidator(0, 99999999, this));

ui->tab_machine->setModel(G.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{
    int id = ui->le_id->text().toInt();
    QString type=ui->le_type->text();
    QString etat=ui->le_etat->text();
    QString da=ui->le_da->text();

    // Contrôle de saisie pour le type
       if (type.toLower() != "tri" && type.toLower() != "compactage") {
           QMessageBox::warning(this, "Erreur", "Le type doit être 'tri' ou 'compactage'");
           return;
       }

       // Contrôle de saisie pour la date d'achat
       QDate dateAchat = QDate::fromString(da, "yyyy-MM-dd");
       if (!dateAchat.isValid()) {
           QMessageBox::warning(this, "Erreur", "Format de date d'achat invalide. Utilisez le format 'yyyy-MM-dd'");
           return;
       }

    Gestionmachine G(id,type,etat,da);
    bool test= G.ajouter();

    if(test)
    {
        QMessageBox::information(nullptr , QObject::tr("done"), QObject::tr("ajout avec succes. cliquer annuler pour quitter"));
        ui->tab_machine->setModel(G.afficher());
    }
}

void MainWindow::on_pb_supprimer_clicked()
{
    Gestionmachine G1; G1.setid(ui->le_id_supp_2->text().toInt());
    bool test=G1.supprimer(G1.getid());
    QMessageBox msgBox;
    if (test)
    {msgBox.setText("suppression avec succes.");
        ui->tab_machine->setModel(G1.afficher());
    }
    else
        msgBox.setText("echec de suppression");
        msgBox.exec();
}



void MainWindow::on_pb_modifier_clicked()
{
    int id = ui->le_idmod->text().toInt();
    QString etat=ui->le_etatmod->text();
    QString da=ui->le_damod->text();
    bool test= G.modifier(id,etat,da);


       // Contrôle de saisie pour la date d'achat
       QDate dateAchat = QDate::fromString(da, "yyyy-MM-dd");
       if (!dateAchat.isValid()) {
           QMessageBox::warning(this, "Erreur", "Format de date d'achat invalide. Utilisez le format 'yyyy-MM-dd'");
           return;
       }

    QMessageBox msgBox;
    if (test)
    {msgBox.setText("modification avec succes.");
        ui->tab_machine->setModel(G.afficher());
    }
    else
        msgBox.setText("echec de modification");
        msgBox.exec();
}
