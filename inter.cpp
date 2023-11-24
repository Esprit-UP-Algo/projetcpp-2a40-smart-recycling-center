#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"personnel.h"
#include<QString>
#include "QStandardItemModel"
#include "QSqlQueryModel"
#include <QFont>
#include <QPalette>
#include <QStandardItemModel>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tab_etudiant->setModel(P.afficher());

        Personnel P; // Créez une instance de la classe Fournisseur
        QSqlQueryModel* model = P.afficher(); // Appelez la méthode sur l'instance créée

        QStandardItemModel* styledModel = new QStandardItemModel(model->rowCount(), model->columnCount(), this);

        for (int row = 0; row < model->rowCount(); ++row) {
            for (int col = 0; col < model->columnCount(); ++col) {
                QModelIndex index = model->index(row, col);
                QStandardItem* item = new QStandardItem(model->data(index).toString());
                styledModel->setItem(row, col, item);

                if (col == 0) { // Colonne "Id_FOURNISSEUR"
                    QFont font("Arial");
                    font.setPointSize(10);
                    font.setWeight(QFont::Bold); // Utiliser Bold pour la police en gras
                    font.setStyle(QFont::StyleItalic);
                    item->setFont(font);

                    QPalette palette;
                    palette.setColor(QPalette::Text, QColor("#07bdff")); // Couleur du texte
                    item->setForeground(palette.color(QPalette::Text));
                }



                if (col == 1) {
                    QFont font("Arial");
                    font.setPointSize(10);
                    font.setWeight(QFont::Bold); // Utiliser Bold pour la police en gras
                    font.setStyle(QFont::StyleItalic);
                    item->setFont(font);

                    QPalette palette;
                    palette.setColor(QPalette::Text, QColor("#07bdff")); // Couleur du texte
                    item->setForeground(palette.color(QPalette::Text));
                }

                if (col == 2) {
                    QFont font("Arial");
                    font.setPointSize(10);
                    font.setWeight(QFont::Bold); // Utiliser Bold pour la police en gras
                    font.setStyle(QFont::StyleItalic);
                    item->setFont(font);

                    QPalette palette;
                    palette.setColor(QPalette::Text, QColor("#07bdff")); // Couleur du texte
                    item->setForeground(palette.color(QPalette::Text));
                }


                if (col == 3) { // Colonne "Id_FOURNISSEUR"
                    QFont font("Arial");
                    font.setPointSize(10);
                    font.setWeight(QFont::Bold); // Utiliser Bold pour la police en gras
                    font.setStyle(QFont::StyleItalic);
                    item->setFont(font);

                    QPalette palette;
                    palette.setColor(QPalette::Text, QColor("#07bdff")); // Couleur du texte
                    item->setForeground(palette.color(QPalette::Text));
                }

                if (col == 4) { // Colonne "Id_FOURNISSEUR"
                    QFont font("Arial");
                    font.setPointSize(10);
                    font.setWeight(QFont::Bold); // Utiliser Bold pour la police en gras
                    font.setStyle(QFont::StyleItalic);
                    item->setFont(font);

                    QPalette palette;
                    palette.setColor(QPalette::Text, QColor("#07bdff")); // Couleur du texte
                    item->setForeground(palette.color(QPalette::Text));
                }

                if (col == 5) { // Colonne "Id_FOURNISSEUR"
                    QFont font("Arial");
                    font.setPointSize(10);
                    font.setWeight(QFont::Bold); // Utiliser Bold pour la police en gras
                    font.setStyle(QFont::StyleItalic);
                    item->setFont(font);

                    QPalette palette;
                    palette.setColor(QPalette::Text, QColor("#07bdff")); // Couleur du texte
                    item->setForeground(palette.color(QPalette::Text));
                }


                if (col == 6) { // Colonne "Id_FOURNISSEUR"
                    QFont font("Arial");
                    font.setPointSize(10);
                    font.setWeight(QFont::Bold); // Utiliser Bold pour la police en gras
                    font.setStyle(QFont::StyleItalic);
                    item->setFont(font);

                    QPalette palette;
                    palette.setColor(QPalette::Text, QColor("#07bdff")); // Couleur du texte
                    item->setForeground(palette.color(QPalette::Text));
                }


                if (col == 7) { // Colonne "Id_FOURNISSEUR"
                    QFont font("Arial");
                    font.setPointSize(10);
                    font.setWeight(QFont::Bold); // Utiliser Bold pour la police en gras
                    font.setStyle(QFont::StyleItalic);
                    item->setFont(font);

                    QPalette palette;
                    palette.setColor(QPalette::Text, QColor("#07bdff")); // Couleur du texte
                    item->setForeground(palette.color(QPalette::Text));
                }


                if (col == 8) { // Colonne "Id_FOURNISSEUR"
                    QFont font("Arial");
                    font.setPointSize(10);
                    font.setWeight(QFont::Bold); // Utiliser Bold pour la police en gras
                    font.setStyle(QFont::StyleItalic);
                    item->setFont(font);

                    QPalette palette;
                    palette.setColor(QPalette::Text, QColor("#07bdff")); // Couleur du texte
                    item->setForeground(palette.color(QPalette::Text));
                }


                if (col == 9) { // Colonne "Id_FOURNISSEUR"
                    QFont font("Arial");
                    font.setPointSize(10);
                    font.setWeight(QFont::Bold); // Utiliser Bold pour la police en gras
                    font.setStyle(QFont::StyleItalic);
                    item->setFont(font);

                    QPalette palette;
                    palette.setColor(QPalette::Text, QColor("#07bdff")); // Couleur du texte
                    item->setForeground(palette.color(QPalette::Text));
                }
            }
        }

        // Appliquer le modèle personnalisé à votre QTableView
        ui->tab_etudiant->setModel(styledModel);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pb_ajouter_clicked()
{
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    QString cin=ui->le_cin->text();
    QString age=ui->le_age->text();
    QString email=ui->le_email->text();
    QString role=ui->le_role->text();
    QString statut=ui->le_statut->text();
    QString telephone=ui->le_telephone->text();
    QString sexe=ui->le_sexe->text();
    QString salaire=ui->le_salaire->text();
    // Vérifier que les champs NOM et PRENOM ne contiennent pas de chiffres
        QRegExp regex(".*\\d+.*"); // Expression régulière pour rechercher des chiffres
        if (nom.contains(regex) || prenom.contains(regex)) {
            QMessageBox::critical(this, "Erreur de saisie", "Les champs Nom et Prénom ne doivent pas contenir de chiffres.");
            return;
        }
    Personnel P(nom ,prenom ,cin ,age ,email,role,statut,telephone,sexe,salaire);
    /*if (QString::number(age).length() < 2)
            {
                QMessageBox::warning(nullptr, QObject::tr("Erreur d'ajout"), QObject::tr("L'ID doit comporter au moins 4 chiffres."), QMessageBox::Cancel);
                return;
            }
        if (age < 18 || age >62)
            {
                QMessageBox::warning(nullptr, QObject::tr("Erreur de saisie"), QObject::tr("Le point de suivi doit être un entier entre 0 et 5."), QMessageBox::Cancel);
                return;
            }*/

    bool test=P.ajouter();
    if (test) {
        // L'ajout a réussi, vous pouvez afficher un message de succès
        QMessageBox::information(this, "Succès", "Les informations du personnel ont été ajoutées avec succès.");
        ui->tab_etudiant->setModel(P.afficher());
    } else {
        // L'ajout a échoué, vous pouvez afficher un message d'erreur
        QMessageBox::critical(this, "Erreur", "Échec de l'ajout des informations du personnel.");
    }
}

void MainWindow::on_pushButton_clicked()
{

        Personnel P1;
        P1.setcin(ui->le_id_sup->text());
        bool test=P1.supprimer(P1.getcin());
        QMessageBox msgBox;

        if(test)
             {msgBox.setText("suppression avec succes.");
        ui->tab_etudiant->setModel(P.afficher());
        }
        else
            msgBox.setText("Le personnel avec l'ID " + P1.getcin() + " n'existe pas.");
            msgBox.exec();

}
void MainWindow::on_pb_modifier_clicked()
{
    QString id = ui->le_cin_2->text();
    QString nouveauNom = ui->le_nom_2->text();
    QString nouveauPrenom = ui->le_prenom_2->text();
    QString nouveauAge = ui->le_age->text();
    Personnel P1;

    bool test=P1.modifier(id, nouveauNom, nouveauPrenom ,nouveauAge);
    if(test)
    {
        QMessageBox::information(this, "Modification réussie", "Le personnel a été modifié avec succès.");

        // Mettez à jour le modèle de votre QTableView
        ui->tab_etudiant->setModel(P.afficher());
    }
    else
    {
        QMessageBox::warning(this, "Erreur de modification", "Erreur lors de la modification du personnel.");
    }
}

