#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "materiau.h"
#include <QMessageBox>
#include <QString>
#include <QIntValidator>
#include <QPdfWriter>
#include <QFileDialog>
#include <QPrinter>
#include <QPainter>
#include <QTextDocument>
#include <QTimer>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->le_id->setValidator(new QIntValidator(100, 9999, this));
    ui->tab_materiau->setModel(M.afficher());
    ui->tab_materiau->show();
     //connect(ui->pushButton_imprimer, &QPushButton::clicked, this, &MainWindow::imprimerTable);
}
/*void MainWindow::imprimerTable()
{
    // Appelle la fonction imprimerTable de la classe Materiau
    Materiau M;
    M.imprimerTable();
}*/

MainWindow::~MainWindow()
{
    delete ui;
}

/*void MainWindow::on_pb_ajouter_clicked()
{
    int id=ui->le_id->text().toInt();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    Etudiant E(id,nom,prenom);

    bool test=E.ajouter();

    if (test)
    {

        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Ajouter effectuée avec succes.\nClick Cancel to exit."), QMessageBox::Cancel);
        ui->tab_etudiant->setModel(E.afficher());
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                               QObject::tr("L'ajout non effectuée.\nClick Cancel to exit."), QMessageBox::Cancel);
    }




}*/
void MainWindow::on_pb_ajouter_clicked()
{
    int id = ui->le_id->text().toInt();
    QString type = ui->le_type->currentText();
    int quantite = ui->le_quantite->text().toInt();
    QString destination = ui->le_destination->text();
    int pointdesuivi = ui->le_pointdesuivi->text().toInt();

    Materiau M;
    // Vérification de la validité des données saisies
       /* if (M.validerSaisie(id, pointdesuivi))
        {
            return;
        }*/
    if (QString::number(id).length() < 4)
        {
            QMessageBox::warning(nullptr, QObject::tr("Erreur d'ajout"), QObject::tr("L'ID doit comporter au moins 4 chiffres."), QMessageBox::Cancel);
            return;
        }
    if (pointdesuivi < 0 || pointdesuivi > 5)
        {
            QMessageBox::warning(nullptr, QObject::tr("Erreur de saisie"), QObject::tr("Le point de suivi doit être un entier entre 0 et 5."), QMessageBox::Cancel);
            return;
        }
    // Vérifie si la quantité contient uniquement des entiers
        /*bool quantiteIsInt;
        int quantiteValue = ui->le_quantite->text().toInt(&quantiteIsInt);
        if (!quantiteIsInt)
        {
            QMessageBox::warning(nullptr, QObject::tr("Erreur de saisie"), QObject::tr("La quantité doit contenir uniquement des entiers."), QMessageBox::Cancel);
            return;
        }*/

    // Vérifie si l'ID existe déjà
    if (M.rechercherParId(id))
    {
        QMessageBox::warning(nullptr, QObject::tr("Erreur d'ajout"), QObject::tr("L'ID existe déjà dans la base de données. Veuillez choisir un autre ID."), QMessageBox::Cancel);
        return;
    }
    // Vérifie si tous les champs obligatoires sont remplis
        if (ui->le_id->text().isEmpty() || type.isEmpty() || destination.isEmpty() || ui->le_pointdesuivi->text().isEmpty())
        {
            QMessageBox::warning(nullptr, QObject::tr("Erreur de saisie"), QObject::tr("Tous les champs obligatoires doivent être remplis."), QMessageBox::Cancel);
            return;
        }

    // Ajoute un nouvel étudiant si l'ID n'existe pas
    M.setid(id);
    M.settype(type);
    M.setquantite(quantite);
    M.setdestination(destination);
    M.setpointsuivi(pointdesuivi);

    bool test = M.ajouter();

    if (test)
    {
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Ajout effectué avec succès.\nClick Cancel to exit."), QMessageBox::Cancel);
        ui->tab_materiau->setModel(M.afficher());
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                               QObject::tr("L'ajout non effectué.\nClick Cancel to exit."), QMessageBox::Cancel);
    }
}


void MainWindow::on_pb_supprimer_clicked()
{
    Materiau M;
    int id=ui->le_id_supp->text().toInt();
    /*E.setid(ui->le_id_supp->text().toInt());*/
    // Vérifie si l'ID existe avant de tenter la suppression
     if (!M.rechercherParId(id))
     {
            QMessageBox::warning(nullptr, QObject::tr("Erreur de suppression"), QObject::tr("L'ID n'existe pas dans la base de données."), QMessageBox::Cancel);
            return;
     }
     // Affiche une boîte de dialogue de confirmation
       QMessageBox::StandardButton reply;
       reply = QMessageBox::question(this, QObject::tr("Confirmation de suppression"), QObject::tr("Voulez-vous vraiment supprimer cet élément ?"), QMessageBox::Yes | QMessageBox::No);

       if (reply == QMessageBox::Yes)
       {
           bool test = M.supprimer(id);
           if (test)
           {
               QMessageBox::information(nullptr, QObject::tr("OK"),
                                        QObject::tr("Suppression effectuée avec succès.\nClick Cancel to exit."), QMessageBox::Cancel);
               ui->tab_materiau->setModel(M.afficher());
           }
           else
           {
               QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                                      QObject::tr("Erreur de suppression.\nClick Cancel to exit."), QMessageBox::Cancel);
           }
       }
        // Affiche une boîte de dialogue avec une liste déroulante (combobox) pour sélectionner l'ID à supprimer
       // Obtient la liste des IDs existants
           /*QSqlQueryModel* model = M.afficher();
           QStringList ids;
           for (int i = 0; i < model->rowCount(); ++i) {
               ids << model->data(model->index(i, 0)).toString();
           }
           qDebug() << "IDs disponibles : " << ids;

           bool ok;
           QString selectedId = QInputDialog::getItem(this, QObject::tr("Sélectionner l'ID"), QObject::tr("Choisissez l'ID à supprimer:"), ids, 0, false, &ok);*/
           // ...
    bool test=M.supprimer(id);
    if (test)
    {

        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Suppression effectuée avec succes.\nClick Cancel to exit."), QMessageBox::Cancel);
        ui->tab_materiau->setModel(M.afficher());
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                               QObject::tr("Erreur de suppression.\nClick Cancel to exit."), QMessageBox::Cancel);
    }

}

void MainWindow::on_pb_modifier_clicked()
{
    Materiau M;
        int id=ui->le_id_m->text().toInt(); // Remplace 1 par l'ID de l'étudiant que tu veux modifier
        QString nouveauType =ui->le_type_m->currentText(); // Utilise le champ ou l'élément d'interface approprié
       int nouveauQuantite =ui->le_quantite_m->text().toInt();
       QString nouveauDestination =ui->le_destination_m->text();
        int nouveauPointdesuivi = ui->le_pointdesuivi_m->text().toInt();
        if (QString::number(id).length() < 4)
            {
                QMessageBox::warning(nullptr, QObject::tr("Erreur d'ajout"), QObject::tr("L'ID doit comporter au moins 4 chiffres."), QMessageBox::Cancel);
                return;
            }
        if (nouveauPointdesuivi < 0 || nouveauPointdesuivi > 5)
            {
                QMessageBox::warning(nullptr, QObject::tr("Erreur de saisie"), QObject::tr("Le point de suivi doit être un entier entre 0 et 5."), QMessageBox::Cancel);
                return;
            }

        // Utilise le champ ou l'élément d'interface approprié
        if (!M.rechercherParId(id))
        {
               QMessageBox::warning(nullptr, QObject::tr("Erreur de suppression"), QObject::tr("L'ID n'existe pas dans la base de données."), QMessageBox::Cancel);
               return;
        }

        if(M.modifier(id, nouveauType, nouveauQuantite, nouveauDestination, nouveauPointdesuivi))
        {
            QMessageBox::information(this, "Modification réussie", "Le materiau a été modifié avec succès.");
            ui->tab_materiau->setModel(M.afficher());
        }
        else
        {
            QMessageBox::warning(this, "Erreur de modification", "Erreur lors de la modification de materiau.");
        }
        /*ui->table_materiau->setModel(M.afficher());*/
}



void MainWindow::on_pushButton_clicked()
{

}

void MainWindow::on_pb_pdf_clicked()
{
QString pdfFileName = "output.pdf";
M.generatePdf(pdfFileName);
}
