#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"personnel.h"
#include"server.h"
#include<QString>
#include "QStandardItemModel"
#include "QSqlQueryModel"
#include <QFont>
#include <QPalette>
#include <QStandardItemModel>
#include <QFileDialog>
#include <QPrinter>
#include <QTextDocument>
#include <QTextStream>
#include <QPdfWriter>
#include <QtCharts>
#include <QDesktopServices>
#include <QtCharts/QAreaSeries>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QPieSlice>
#include <QPieSeries>
#include <QChartView>
#include <QDebug>
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
    Personnel P(nom ,prenom ,cin ,age ,email,role,statut,telephone,sexe,salaire);
    bool test=P.ajouter();
    if (test) {
        // L'ajout a réussi, vous pouvez afficher un message de succès
        QMessageBox::information(this, "Succès", "Les informations du Personnel ont été ajoutées avec succès.");
        ui->tab_etudiant->setModel(P.afficher());
    } else {
        // L'ajout a échoué, vous pouvez afficher un message d'erreur
        QMessageBox::critical(this, "Erreur", "Échec de l'ajout des informations du fournisseur.");
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
            msgBox.setText("Le fournisseur avec l'ID " + P1.getcin() + " n'existe pas.");
            msgBox.exec();

}
void MainWindow::on_pb_modifier_clicked()
{
    QString id = ui->le_cin_2->text();
    QString nouveauNom = ui->le_nom_2->text();
    QString nouveauPrenom = ui->le_prenom_2->text();
    QString nouveauAge = ui->le_age_2->text();

    bool test=P.modifier(id, nouveauNom, nouveauPrenom ,nouveauAge);
    if(test)
    {
        QMessageBox::information(this, "Modification réussie", "Le fournisseur a été modifié avec succès.");

        // Mettez à jour le modèle de votre QTableView
        ui->tab_etudiant->setModel(P.afficher());
    }
    else
    {
        QMessageBox::warning(this, "Erreur de modification", "Erreur lors de la modification du fournisseur.");
    }
}


void MainWindow::on_pb_PDF_clicked()
{
    QString strStream;
                        QTextStream out(&strStream);

                        const int rowCount = ui->tab_etudiant->model()->rowCount();
                        const int columnCount = ui->tab_etudiant->model()->columnCount();

                        out <<  "<html>\n"
                            "<head>\n"
                            "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                            <<  QString("<title>%1</title>\n").arg("strTitle")
                            <<  "</head>\n"
                            "<body bgcolor=#ffffff link=#5000A0>\n"

                           //     "<align='right'> " << datefich << "</align>"
                            "<center> <H1>Liste des Personnel </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                        // headers
                        out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                        for (int column = 0; column < columnCount; column++)
                            if (!ui->tab_etudiant->isColumnHidden(column))
                                out << QString("<th>%1</th>").arg(ui->tab_etudiant->model()->headerData(column, Qt::Horizontal).toString());
                        out << "</tr></thead>\n";

                        // data table
                        for (int row = 0; row < rowCount; row++) {
                            out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                            for (int column = 0; column < columnCount; column++) {
                                if (!ui->tab_etudiant->isColumnHidden(column)) {
                                    QString data = ui->tab_etudiant->model()->data(ui->tab_etudiant->model()->index(row, column)).toString().simplified();
                                    out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                                }
                            }
                            out << "</tr>\n";
                        }
                        out <<  "</table> </center>\n"
                            "</body>\n"
                            "</html>\n";

                  QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
                    if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

                   QPrinter printer (QPrinter::PrinterResolution);
                    printer.setOutputFormat(QPrinter::PdfFormat);
                   printer.setPaperSize(QPrinter::A4);
                  printer.setOutputFileName(fileName);

                   QTextDocument doc;
                    doc.setHtml(strStream);
                    doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
                    doc.print(&printer);

}

void MainWindow::on_pb_tri_clicked()
{
    QAbstractItemModel *existingModel = ui->tab_etudiant->model();

          if (existingModel)
          {

              delete existingModel;

          }


    ui->tab_etudiant->setModel(P.trisalaire());

}

void MainWindow::on_pb_stat_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
                   model->setQuery("select * from PERSONNEL where AGE = '50'");
                   float dispo1=model->rowCount();

                   model->setQuery("select * from PERSONNEL where AGE = '30'");
                   float dispo=model->rowCount();

                   model->setQuery("select * from PERSONNEL where AGE = '20'");
                   float dispo3=model->rowCount();

                   float total=dispo1+dispo+dispo3;
                       QString a=QString("=50 " +QString::number((dispo1*100)/total,'f',2)+"%" );
                       QString b=QString("=30  " +QString::number((dispo*100)/total,'f',2)+"%" );
                       QString c=QString("=20  " +QString::number((dispo3*100)/total,'f',2)+"%" );
                       QPieSeries *series = new QPieSeries();
                       series->append(a,dispo1);
                       series->append(b,dispo);
                       series->append(c,dispo3);
                   if (dispo1!=0)
                   {QPieSlice *slice = series->slices().at(0);
                       slice->setLabelVisible();
                       slice->setPen(QPen());}
                   if ( dispo!=0)
                   {
                       QPieSlice *slice1 = series->slices().at(1);
                       slice1->setLabelVisible();
                       slice1->setPen(QPen());
                   }
                   if (dispo3!=0)
                   {QPieSlice *slice = series->slices().at(2);
                       slice->setLabelVisible();
                       slice->setPen(QPen());}

                   QChart *chart = new QChart();


                   chart->addSeries(series);
                   chart->setTitle("Nombre: "+ QString::number(total));



                   QChartView *chartView = new QChartView(chart);
                   chartView->setRenderHint(QPainter::Antialiasing);
                   chartView->resize(1300,800);
                   chartView->showMaximized();
}



void MainWindow::on_pb_chercher_clicked()
{
    QString CIN=ui->le_cherche->text();
    ui->tab_etudiant->setModel(P.chercher_Personnel(CIN));
}



void MainWindow::on_startButton_clicked()
{
    if(ui->port->text().toInt()/1000>1)
    {
        server.Connect(ui->port->text().toInt());
        text=QString("PORT:"+ui->port->text()+"\n discussion créé avec succès...\n");
        ui->textEdit->setText(text);}
    else{
        text=QString("Le numéro de port est incorrect\n");
        ui->textEdit->setText(text);}
    ui->nameEdit->setFocus();
}

void MainWindow::playerConnected()
{

    text.append("Un canard rejoint le salon de discussion Un canard rejoint le salon de discussion...\n");
    ui->textEdit->setText(text);
}


void MainWindow::getMessage()
{
    text.append(server.getContent()+"\n");
    ui->textEdit->setText(text);
}

void MainWindow::next()
{
    ui->envoyer->setFocus();
}

void MainWindow::on_pushButton_4_clicked()
{
    text.append(ui->nameEdit->text()+": "+ui->envoyer->text()+"\n");
    ui->textEdit->setText(text);
    server.sendData(ui->nameEdit->text()+": "+ui->envoyer->text());
    ui->envoyer->clear();
}
