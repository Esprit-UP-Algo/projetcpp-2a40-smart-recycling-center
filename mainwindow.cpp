#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "materiaux.h"
#include <QMessageBox>
#include <QString>
#include <QIntValidator>
#include <QPdfWriter>
#include <QFileDialog>
#include <QPainter>
#include <QTextDocument>
#include <QTimer>
#include <QPrinter>
#include <QSqlQuery>
#include <QSqlError>
#include <QBarSeries>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QChart>
#include <QListWidget>
#include <QSlider>
#include <QVBoxLayout>
#include<QPieSlice>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QChart>
#include <QIntValidator>
#include <QPainter>
#include <QtCharts>
#include <QAxObject>
#include <QSqlRecord>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->le_id->setValidator(new QIntValidator(100, 9999, this));
    ui->tab_materiau->show();
    QString css="border: 2px solid #8f8f91;"
                "border-radius: 10px;"  // Coins arrondis
                "padding: 2px 4px;"  // Rembourrage pour éviter le texte collé au bord
                "background: #F8F8F8;"  // Couleur de fond
                "color: #4A4A4A;"  // Couleur du texte
                "font-family: 'Barlow Condensed';"  // Style de texte
                "}"
                "QLineEdit:hover {"
                "border: 2px solid #4a90e2;";  // Bordure lorsque survolé
    QString css2="QLineEdit {"
                 "background-color: rgba(128, 128, 128, 50);"
                 "border: 2px solid #8f8f91;"
                 "border-radius: 10px;"
                 "padding: 2px 4px;"
                 "color: #4A4A4A;"
                 "font-family: 'Barlow Condensed';"
                 "}"
                 "QLineEdit:hover {"
                 "border: 2px solid #4a90e2;"
                 "}";
    //#FCAE19
    //#fff
    QString cssbtn="QPushButton"
        "{background:none;"
        "text-align: center;"
        /*"padding-left:10px;"*/
        "border-radius: 10px;"

        "background-color : rgb(255, 170, 0);"
    "color:rgb(88, 88, 88);"
        "font-family: Barlow Condensed; "
        "font-size: 15px;"
        "font-weight: lighter; } "

    "QPushButton:hover"
    "{"
        "border: 2px solid #4A4A4A;"
        /*"background-color: rgba(84, 16, 149, 1);"*/

    "}";
    QString nouha="QPushButton" "{text-align: center;""border-radius: 15px;""background-color : rgb(255, 170, 0);""color:rgb(88, 88, 88);"
            "font-family: Barlow Condensed;""sans-serif;""font-size: 19px;""font-weight: lighter; }" "QPushButton:hover"
                  "{"
                      "border : 2px solid rgba(247, 173, 28, 1);"
                      "background-color: rgba(174, 230, 141, 1);"

                  "}";
    /*ui->tab_materiau->setStyleSheet("QTableView{color: white; border-radius: 20px; border: 1px solid rgba(51, 66, 255, 0.00);"
                                       "background: qlineargradient(spread: pad, x1: 0, y1: 1, x2: 0, y2: 0, stop: 0.5 rgba(17, 16, 24, 0.00), stop: 0.5 rgba(17, 16, 24, 0.51));"

                                       "display: flex;"
                                       "width: 484px;"
                                       "height: 60px;"
                                       "padding: 20px 16px;"
                                       "align-items: center;"
                                       "spacing: 24px;"
                                       "flex: 0;}"
                                        " color: white; background-color: rgba(0, 0, 0, 0.5); ");*/
    ui->tab_materiau->setStyleSheet("QTableView {border-radius: 30px;border: 3px solid #FCAE19;gridline-color:#FCAE19;background: rgba(123, 183, 189, 0.80);text-align: center;color:rgb(88, 88, 88); font-family: Arial, sans-serif; font-size: 14px;font-weight: bold; color: rgba(81, 81, 81,0.9);}"
                                    "QHeaderView {background-color:rgba(123, 183, 189, 0);color: rgb(74, 74, 74);font-size: 20px;color: rgb(255, 170, 0);}"
                                    "QHeaderView::section {background-color: transparent;border:0.5px solid transparent;border-radius: 30px;}"
                                        "QTableView QTableCornerButton::section {background-color: transparent;border: none;}");

    ui->le_id->setPlaceholderText("ID");
    ui->le_type->setPlaceholderText("Type");
    ui->le_quantite->setPlaceholderText("Quantite");
    ui->le_destination->setPlaceholderText("Destination");
    ui->le_pointdesuivi->setPlaceholderText("Pointdesuivi");
    ui->le_chercher->setPlaceholderText("   Chercher");

    ui->le_id_m->setPlaceholderText("ID");
    ui->le_type_m->setPlaceholderText("Type");
    ui->le_quantite_m->setPlaceholderText("Quantite");
    ui->le_destination_m->setPlaceholderText("Destination");
    ui->le_pointdesuivi_m->setPlaceholderText("Pointdesuivi");
    ui->le_id_s->setPlaceholderText("ID");

    ui->le_id->setStyleSheet(css);
    ui->le_type->setStyleSheet(css);
    ui->le_quantite->setStyleSheet(css);
    ui->le_destination->setStyleSheet(css);
    ui->le_pointdesuivi->setStyleSheet(css);
    ui->le_id_m->setStyleSheet(css);
    ui->le_type_m->setStyleSheet(css);
    ui->le_quantite_m->setStyleSheet(css);
    ui->le_destination_m->setStyleSheet(css);
    ui->le_pointdesuivi_m->setStyleSheet(css);
     ui->le_id_s->setStyleSheet(css);
    ui->le_chercher->setStyleSheet(css2);
    ui->pb_ajouter->setStyleSheet(cssbtn);
    ui->pb_modifier->setStyleSheet(cssbtn);
    ui->pb_chercher->setStyleSheet(cssbtn);
    ui->pb_pdf->setStyleSheet(cssbtn);
    ui->pb_trier->setStyleSheet(cssbtn);
    ui->pb_supprimer->setStyleSheet(cssbtn);
    ui->pb_imprimer->setStyleSheet(cssbtn);
    ui->pb_inserer->setStyleSheet(cssbtn);
    ui->le_stat->setStyleSheet(cssbtn);
    ui->pb_word->setStyleSheet(cssbtn);
    ui->tab_materiau->setModel(M.afficher());
    ui->tab_materiau->resizeColumnsToContents();


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_ajouter_clicked()
{
    int id = ui->le_id->text().toInt();
    QString type = ui->le_type->text();
    int quantite = ui->le_quantite->text().toInt();
    QString destination = ui->le_destination->text();
    int pointdesuivi = ui->le_pointdesuivi->text().toInt();

    Materiaux M;
    QStringList typesAutorises = {"plastique", "verre", "organique", "electronique", "papier", "metale"};

      // Vérifier si le type de matériau est autorisé
      if (!typesAutorises.contains(type.toLower())) {
          QMessageBox::warning(nullptr, QObject::tr("Erreur de saisie"), QObject::tr("Le type de matériau n'est pas valide."), QMessageBox::Cancel);
          return;
      }
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
    M.setpointdesuivi(pointdesuivi);

    bool test = M.ajouter();

    if (test)
    {
        ui->tab_materiau->resizeColumnsToContents();
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Ajout effectué avec succès.\nClick Cancel to exit."), QMessageBox::Cancel);
        ui->tab_materiau->setModel(M.afficher());
        ui->le_id->clear();
        ui->le_type->clear();
        ui->le_quantite->clear();
        ui->le_destination->clear();
        ui->le_pointdesuivi->clear();
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                               QObject::tr("L'ajout non effectué.\nClick Cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_pb_modifier_clicked()
{
    Materiaux M;
       int id =ui->le_id_m->text().toInt(); // Remplace 1 par l'ID de l'étudiant que tu veux modifier
       QString nouveauType =ui->le_type_m->text(); // Utilise le champ ou l'élément d'interface approprié
       int nouveauQuantite =ui->le_quantite_m->text().toInt();
       QString nouveauDestination =ui->le_destination_m->text();
       int nouveauPointdesuivi = ui->le_pointdesuivi_m->text().toInt();
       QStringList typesAutorises = {"plastique", "verre", "organique", "electronique", "papier", "metale"};

         // Vérifier si le type de matériau est autorisé
         if (!typesAutorises.contains(nouveauType.toLower())) {
             QMessageBox::warning(nullptr, QObject::tr("Erreur de saisie"), QObject::tr("Le type de matériau n'est pas valide."), QMessageBox::Cancel);
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
            ui->tab_materiau->resizeColumnsToContents();
            QMessageBox::information(this, "Modification réussie", "Le materiau a été modifié avec succès.");
            ui->tab_materiau->setModel(M.afficher());
            ui->le_id_m->clear();
            ui->le_type_m->clear();
            ui->le_quantite_m->clear();
            ui->le_destination_m->clear();
            ui->le_pointdesuivi_m->clear();
        }
        else
        {
            QMessageBox::warning(this, "Erreur de modification", "Erreur lors de la modification de materiau.");
        }
        /*ui->table_materiau->setModel(M.afficher());*/
}

void MainWindow::on_pb_chercher_clicked()
{
    int id=ui->le_chercher->text().toInt();
    ui->tab_materiau->setModel(M.chercher_Materiaux(id));
}
void MainWindow::exportToPDF()
{
    QString filePath = QFileDialog::getSaveFileName(nullptr, "Exporter en PDF", "", "Fichiers PDF (*.pdf)");

        if (filePath.isEmpty()) {
            // L'utilisateur a annulé la sélection du fichier
            return;
        }

        // Créer un objet QPrinter
        QPrinter printer;
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOutputFileName(filePath);

        // Créer un objet QPainter qui dessinera sur le QPrinter
        QPainter painter(&printer);

        // Commencer le dessin sur la page
        painter.begin(&printer);

        // Définir la taille de la page
        printer.setPageSize(QPrinter::A4);

        // Définir la police et la taille du texte
        painter.setFont(QFont("Arial", 12));

        // Dessiner le titre
        painter.drawText(100, 100, "Liste des employés");

        // Dessiner l'en-tête du tableau
        painter.drawText(100, 120, "iD");
        painter.drawText(200, 120, "quantite");
        painter.drawText(300, 120, "destination");
        painter.drawText(400, 120, "pointdesuivi");
        // Ajouter d'autres en-têtes selon vos besoins

        // Récupérer les données depuis la base de données
        QSqlQuery query;
        query.prepare("SELECT * FROM materiau");
        if (query.exec()) {
            int row = 140;
            int rowCount = 0;
            while (query.next()) {
                QString type = query.value("type").toString();
                QString destination = query.value("destination").toString();
                int id = query.value("id").toInt();
                int quantite = query.value("quantite").toInt();
                int pointdesuivi = query.value("pointdesuivi").toInt();
                // Ajouter d'autres colonnes selon vos besoins

                // Dessiner les données des employés
                painter.drawText(200, row, type);
                painter.drawText(400, row, destination);
                painter.drawText(100, row, QString::number(id));
                painter.drawText(300, row, QString::number(quantite));
                 painter.drawText(500, row, QString::number(pointdesuivi));
                // Ajouter d'autres colonnes selon vos besoins

                row += 20; // Augmenter la position Y pour la prochaine ligne
                rowCount++;

                // Passer à une nouvelle page après un certain nombre de lignes (par exemple, 20 lignes)
                if (rowCount % 20 == 0) {
                    printer.newPage();
                    row = 100; // Réinitialiser la position Y pour la nouvelle page
                }
            }
        } else {
            // Gestion de l'erreur de la requête
            QMessageBox::warning(this, "Erreur", "Erreur lors de l'exécution de la requête SQL : " + query.lastError().text());
        }

        // Terminer le dessin sur la page
        painter.end();

        // Afficher un message de succès
        QMessageBox::information(this, "Export PDF", "Les données des materiaux ont été exportées avec succès vers un fichier PDF.");
}

void MainWindow::on_pb_pdf_clicked()
{
    exportToPDF();
}

void MainWindow::on_le_stat_clicked()
{
    Materiaux materiaux;
            QMap<QString, int> statistiques = materiaux.getStatistiquesParType();

            // Créer une série de diagramme circulaire
            QPieSeries *pieSeries = new QPieSeries();

            // Ajouter des tranches pour chaque type de matériau
            for (auto it = statistiques.begin(); it != statistiques.end(); ++it) {
                QPieSlice *slice = pieSeries->append(it.key(), it.value());
                slice->setLabelVisible();
            }

            // Créer un graphique circulaire
            QChart *chart = new QChart();
            chart->addSeries(pieSeries);
            chart->setTitle("Statistiques par type de matériau");

            // Utiliser les paramètres choisis par l'utilisateur
            chart->setBackgroundBrush(QBrush(Qt::white));
            chart->setTheme(QChart::ChartThemeLight);
            // Utilisez les valeurs des contrôles choisis par l'utilisateur
            chart->legend()->setVisible(true);
            chart->legend()->setAlignment(Qt::AlignRight);

            // Créer une vue de graphique
            QChartView chartView(chart);
            chartView.setRenderHint(QPainter::Antialiasing);

            // Créer une fenêtre modale
            QDialog *dialog = new QDialog(this);
            dialog->resize(600, 400);  // Réglez la taille de la fenêtre ici
            QVBoxLayout *layout = new QVBoxLayout(dialog);
            layout->addWidget(&chartView);

            // Afficher la fenêtre modale
            dialog->exec();
    /*QChartView *chartView = new QChartView(this);
    QChart *chart = new QChart();

    double  quantite,type;

    QSqlQuery query;
    query.prepare("SELECT quantite,type FROM materiau");
    if (query.exec()) {
        while (query.next())
{
quantite = query.value("quantite").toDouble();
type = query.value("type").toDouble();



            QBarSeries *series = new QBarSeries();

            QBarSet *setquantite = new QBarSet("quantite");
                        *setquantite << quantite;
                        series->append(setquantite);

            QBarSet *settype = new QBarSet("type");
            *settype << type;
            series->append(settype);

            chart->addSeries(series);
        }
    } else {
        qDebug() << "Failed to execute query or retrieve data.";
        return;
    }


    QStringList categories;
    categories << "quantite" << "type";
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->createDefaultAxes();
    chart->setAxisX(axisX, chart->series().at(0));


    chartView->setChart(chart);

    QMainWindow *chartWindow = new QMainWindow(this);
    chartWindow->setCentralWidget(chartView);
    chartWindow->resize(800, 600);
    chartWindow->show();*/
}

void MainWindow::on_pb_trier_clicked()
{
    ui->tab_materiau->setModel(M.tri());
}

void MainWindow::on_pb_supprimer_clicked()
{
    int id=ui->le_id_s->text().toInt();
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
        ui->le_id_s->clear();
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                               QObject::tr("Erreur de suppression.\nClick Cancel to exit."), QMessageBox::Cancel);
    }

    /*Materiaux M;
    QList<int> ids = M.getIds();

    bool ok;
    QString item = QInputDialog::getItem(this, "Choisir un identifiant", "Identifiant :", ids, 0, false, &ok);

    if (ok) {
        // Conversion de la chaîne en entier
        int idASupprimer = item.toInt();

        if (M.supprimer(idASupprimer)) {
            QMessageBox::information(nullptr, QObject::tr("OK"),
                                     QObject::tr("Supprimer effectué.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);
            ui->tab_materiau->setModel(M.afficher());
        } else {
            QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                                   QObject::tr("Supprimer non effectué.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);
        }
    }*/

}



void MainWindow::on_pb_imprimer_clicked()
{
     M.imprimerTableau(ui->tab_materiau);
}

void MainWindow::exportToWord()
{
    QString filePath = QFileDialog::getSaveFileName(nullptr, "Exporter en Word", "", "Documents Word (*.docx)");

    if (filePath.isEmpty()) {
        // L'utilisateur a annulé la sélection du fichier
        return;
    }

    // Initialisation de l'application Word
    QAxObject* wordApplication = new QAxObject("Word.Application", this);
    wordApplication->setProperty("Visible", true);

    // Création d'un nouveau document Word
    QAxObject* wordDocuments = wordApplication->querySubObject("Documents");
    QAxObject* wordDocument = wordDocuments->querySubObject("Add()");

    // Sélection du contenu actif du document
    QAxObject* selection = wordApplication->querySubObject("Selection");

    // Écriture du titre
    selection->querySubObject("TypeText(QString)", "Liste des matériaux");

    // Insertion d'un tableau
    QAxObject* tables = selection->querySubObject("Tables");
    QAxObject* table = tables->querySubObject("Add(Range, NumRows, NumColumns, DefaultTableBehavior, AutoFitBehavior)", selection->asVariant(), 2, 5, 1, 1);

    // Écriture de l'en-tête du tableau
    QStringList headers = {"ID", "Type", "Quantité", "Destination", "Point de suivi"};
    for (int col = 1; col <= 5; ++col) {
        table->querySubObject("Cell(Row, Column)", 1, col)->querySubObject("Range")->dynamicCall("InsertAfter(const QString&)", headers[col - 1]);
    }

    // Récupération des données depuis la base de données
    QSqlQueryModel model;
    model.setQuery("SELECT * FROM materiau");

    if (model.lastError().isValid()) {
        // Gestion de l'erreur de la requête
        QMessageBox::warning(this, "Erreur", "Erreur lors de l'exécution de la requête SQL : " + model.lastError().text());
        return;
    }

    // Écriture des données dans le tableau
    for (int row = 0; row < model.rowCount(); ++row) {
        for (int col = 1; col <= 5; ++col) {
            QVariant value = model.record(row).value(col - 1);
            table->querySubObject("Cell(Row, Column)", row + 2, col)->querySubObject("Range")->dynamicCall("InsertAfter(const QString&)", value.toString());
        }
    }

    // Enregistrement du document Word
    wordDocument->querySubObject("SaveAs(const QString&)", filePath);
    wordDocument->querySubObject("Close()");
    wordApplication->setProperty("Visible", false);

    // Libération des ressources
    delete wordApplication;
}



void MainWindow::on_pb_word_clicked()
{
   exportToWord();
}


void MainWindow::on_pb_inserer_clicked()
{
    QString cheminImage = QFileDialog::getOpenFileName(this, "Sélectionner une image", "", "Images (*.png *.jpg *.bmp *.gif)");

       // Vérifier si l'utilisateur a annulé la sélection
       if (cheminImage.isEmpty()) {
           return;
       }

       // Charger l'image
       QPixmap image(cheminImage);

       // Afficher l'image dans le QLabel ou autre widget que vous utilisez pour afficher l'image
       ui->labelimage->setPixmap(image);
       ui->labelimage->setScaledContents(true);
}
