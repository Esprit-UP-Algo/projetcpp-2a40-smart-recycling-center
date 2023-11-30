 #include "mainwindow.h"
#include "ui_mainwindow.h"
#include "conteneur.h"
#include "mail.h"
#include <QNetworkRequest>
#include <QNetworkReply>

#include <QtWidgets>
#include <QtLocation>
#include <QtPositioning>

#include <QtGui>
#include <QtSql>
#include <QtPrintSupport>

#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>

#include <QPieSeries>
#include <QtCharts>
#include <QChartView>

#include <QTextDocumentWriter>
#include <QFileDialog>
#include <QTextDocument>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
      mediaPlayer(new QMediaPlayer(this)),
      isMuted(false),
      previousVolume(100)
{

    ui->setupUi(this);
//arduino
    int ret=A.connect_arduino();
    switch(ret)
    {
    case (0):qDebug()<<"arduino is avilble and connected to :"<<A.getarduino_port_name();
        break;
    case (1):qDebug()<<"arduino is avilble but not connected to :"<<A.getarduino_port_name();
        break;
    case (-1):qDebug()<<"arduino is not avilble ";
    }
    QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label()));






    ui->radioButton_4->setChecked(true);
    ui->radioButton_2->setChecked(true);
//
    connect(ui->radioButton, &QPushButton::clicked, this, &MainWindow::on_radioButton_clicked);
        connect(ui->pushButton_7, &QPushButton::clicked, this, &MainWindow::on_pushButton_7_clicked);
        connect(ui->pushButton_6, &QPushButton::clicked, this, &MainWindow::on_pushButton_6_clicked);
        connect(ui->radioButton_2, &QPushButton::clicked, this, &MainWindow::on_radioButton_2_clicked);

    // Initialiser le temps à 00:00:00
       currentTime = QTime(0, 0, 0);

       // Créer un QTimer pour mettre à jour le temps toutes les secondes
       timer = new QTimer(this);
       connect(timer, &QTimer::timeout, this, &MainWindow::updateTimeSlot);
       timer->start(1000); // Mise à jour toutes les 1000 millisecondes (1 seconde)

       // Appeler la mise à jour initiale
       updateTimeSlot();
    //
    ui->groupBox_14->hide();
//

    connect(ui->a_code, SIGNAL(textChanged(const QString&)), this, SLOT(limitInputLength(const QString&)));
    connect(ui->rechercher, SIGNAL(textChanged(const QString&)), this, SLOT(limitInputLength2(const QString&)));

//
    ui->groupBox_15->hide();
//statistique


    ui->label_32->hide();
        float s0, s1;
        s0 = countType("Sature");
        s1 = countType("Non sature");


        float stat = s0 + s1 ;
        float x = (stat != 0) ? (s0 * 100) / stat : 0.0;
        float y = (stat != 0) ? (s1 * 100) / stat : 0.0;

        QString ch1 = QString("Sature %1%").arg(x);
        QString ch2 = QString("Non sature %1%").arg(y);



        QPieSeries *series = new QPieSeries();
        QPieSlice *slice = series->append(ch1, x);
        slice->setLabelVisible();
        slice->setLabelColor(QColor("#FFFFFF"));
        slice->setBrush(QColor(165, 255, 113));



        QPieSlice *slice1 = series->append(ch2, y);
        slice1->setLabelVisible();
        slice1->setLabelColor(QColor("#FFFFFF"));
        slice1->setBrush(QColor(252, 174, 25));

        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setAnimationOptions(QChart::SeriesAnimations);
        QBrush backgroundBrush(QColor(187, 93, 87, 0));
        chart->setBackgroundBrush(backgroundBrush);


        QChartView *chartview = new QChartView(chart);

        // Set a custom size for the chart view (e.g., 600x400)
        chartview->setFixedSize(400, 280);

        chartview->setRenderHint(QPainter::Antialiasing);
        chartview->setParent(ui->label_32);

        ui->label_32->setStyleSheet("background: transparent; color: white; ");
        ui->label_32->show();


//add items code combobox
    ui->ccode->clear();
    QSqlQuery query;
    query.exec("SELECT code FROM conteneur");
                            while (query.next()) {
                                QString mcode = query.value(0).toString(); // Assuming the value from the query is a QString

                                ui->ccode->addItem(mcode);

                            }
//add items emails combobox
  ui->ccode_2->clear();
  query.exec("SELECT EMAIL FROM PERSONNEL");
   while (query.next()) {
        QString email = query.value(0).toString(); // Assuming the value from the query is a QString
        ui->ccode_2->addItem(email);
    }
//
    ui->table->verticalHeader()->setStyleSheet("QHeaderView::section { color:transparent; background-color:transparent; }");

    ui->groupBox_10->hide();
    ui->comboBox->addItem("Trier");
    ui->comboBox->addItem("Code");
    ui->comboBox->addItem("Etat");
    ui->comboBox->addItem("Taille");


    ui->m_etat->addItem("Sature");
    ui->m_etat->addItem("Non sature");
    ui->m_taille->addItem("Petite");
    ui->m_taille->addItem("Moyenne");
    ui->m_taille->addItem("Grande");

    ui->a_etat->addItem("Etat");
    ui->a_etat->addItem("Sature");
    ui->a_etat->addItem("Non sature");

    ui->a_taille->addItem("Taille");
    ui->a_taille->addItem("Petite");
    ui->a_taille->addItem("Moyenne");
    ui->a_taille->addItem("Grande");

    ui->table->setModel(C.afficher());

  QString lc=ui->ccode->currentText();
    query.prepare("SELECT * FROM conteneur WHERE code = :code");
    query.bindValue(":code", lc);

    if (query.exec() && query.next()) {

          QString mlocalisation = query.value("localisation").toString();




      }




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
    QString location =ui->a_localisation->text();
    QRegExp regex2("^[A-Za-z0-9]{1,4}$");
    if(code.contains("C",Qt::CaseInsensitive) &&  code.contains(regex2)){
        if( etat!="Etat" && taille!="Taille" && location!="")
        {

            Conteneur C(code,etat,taille,location);
            bool test=C.ajouter();
            if(test)
            {
                QSqlQuery query;
                ui->ccode->clear();
                query.exec("SELECT code FROM conteneur");
                                        while (query.next()) {
                                            QString mcode = query.value(0).toString(); // Assuming the value from the query is a QString

                                            ui->ccode->addItem(mcode);

                                        }
                                        ui->label_32->hide();
                                       QList<QWidget*> childWidgets = ui->label_32->findChildren<QWidget*>();
                                               for (QWidget* childWidget : childWidgets) {
                                                   childWidget->deleteLater();

                                               }
                                               //the clear didnt work, but my goal is when i second click this button it deleted old chart and renders a new one
                                               ui->label_32->clear();
                                               ui->label_32->hide();

                                           float s0, s1;
                                           s0 = countType("Sature");
                                           s1 = countType("Non sature");


                                           float stat = s0 + s1 ;
                                           float x = (stat != 0) ? (s0 * 100) / stat : 0.0;
                                           float y = (stat != 0) ? (s1 * 100) / stat : 0.0;

                                           QString ch1 = QString("Sature %1%").arg(x);
                                           QString ch2 = QString("Non sature %1%").arg(y);


                                           QPieSeries *series = new QPieSeries();
                                                   QPieSlice *slice = series->append(ch1, x);
                                                   slice->setLabelVisible();
                                                   slice->setLabelColor(QColor("#FFFFFF"));
                                                   slice->setBrush(QColor(165, 255, 113));



                                                   QPieSlice *slice1 = series->append(ch2, y);
                                                   slice1->setLabelVisible();
                                                   slice1->setLabelColor(QColor("#FFFFFF"));
                                                   slice1->setBrush(QColor(252, 174, 25));

                                                   QChart *chart = new QChart();
                                                   chart->addSeries(series);
                                                   chart->setAnimationOptions(QChart::SeriesAnimations);
                                                   QBrush backgroundBrush(QColor(187, 93, 87, 0));
                                                   chart->setBackgroundBrush(backgroundBrush);

                                                   QChartView *chartview = new QChartView(chart);

                                                   // Set a custom size for the chart view (e.g., 600x400)
                                                   chartview->setFixedSize(400, 280);

                                                   chartview->setRenderHint(QPainter::Antialiasing);
                                                   chartview->setParent(ui->label_32);

                                                   ui->label_32->setStyleSheet("background: transparent; color: white; ");
                                               ui->label_32->show();
                QMessageBox::information(nullptr , QObject::tr("OK"),QObject::tr("Ajout effectué."),QMessageBox::Cancel);

            }
            else {
                QMessageBox::critical(nullptr,QObject::tr("Erreur"),QObject::tr("Conteneur deja existe ! \n*Le code de conteneur doit etre unique"), QMessageBox::Cancel);
            }
             ui->table->setModel(C.afficher());
        }
        else{
            if(etat=="Etat"){QMessageBox::critical(nullptr,QObject::tr("Erreur"),QObject::tr("Selectionner une etat\n."), QMessageBox::Cancel);}
            else{
                if(taille=="Taille"){QMessageBox::critical(nullptr,QObject::tr("Erreur"),QObject::tr("Selectionner le taille\n."), QMessageBox::Cancel);}
                else{
                    if(location==""){QMessageBox::critical(nullptr,QObject::tr("Erreur"),QObject::tr("Localisation ne doit pas etre vide\n."), QMessageBox::Cancel);}
                }
            }
        }

    }

     else{ QMessageBox::critical(nullptr,QObject::tr("Erreur"),QObject::tr("Le code doit commence par 'C' suit de 3 chiffres\n."), QMessageBox::Cancel);}
}

void MainWindow::on_bt_supprimer_clicked()
{

  Conteneur C1;
    C1.setcode(ui->ccode->currentText());

    bool test=C1.supprimer(C1.getcode());
    if(test){
        QSqlQuery query;
        ui->ccode->clear();
        query.exec("SELECT code FROM conteneur");
                                while (query.next()) {
                                    QString mcode = query.value(0).toString(); // Assuming the value from the query is a QString

                                    ui->ccode->addItem(mcode);

                                }
                                 ui->label_32->hide();
                                QList<QWidget*> childWidgets = ui->label_32->findChildren<QWidget*>();
                                        for (QWidget* childWidget : childWidgets) {
                                            childWidget->deleteLater();

                                        }
                                        //the clear didnt work, but my goal is when i second click this button it deleted old chart and renders a new one
                                        ui->label_32->clear();
                                        ui->label_32->hide();

                                    float s0, s1;
                                    s0 = countType("Sature");
                                    s1 = countType("Non sature");


                                    float stat = s0 + s1 ;
                                    float x = (stat != 0) ? (s0 * 100) / stat : 0.0;
                                    float y = (stat != 0) ? (s1 * 100) / stat : 0.0;

                                    QString ch1 = QString("Sature %1%").arg(x);
                                    QString ch2 = QString("Non sature %1%").arg(y);


                                    QPieSeries *series = new QPieSeries();
                                            QPieSlice *slice = series->append(ch1, x);
                                            slice->setLabelVisible();
                                            slice->setLabelColor(QColor("#FFFFFF"));
                                            slice->setBrush(QColor(165, 255, 113));



                                            QPieSlice *slice1 = series->append(ch2, y);
                                            slice1->setLabelVisible();
                                            slice1->setLabelColor(QColor("#FFFFFF"));
                                            slice1->setBrush(QColor(252, 174, 25));

                                            QChart *chart = new QChart();
                                            chart->addSeries(series);
                                            chart->setAnimationOptions(QChart::SeriesAnimations);
                                            QBrush backgroundBrush(QColor(187, 93, 87, 0));
                                            chart->setBackgroundBrush(backgroundBrush);

                                            QChartView *chartview = new QChartView(chart);

                                            // Set a custom size for the chart view (e.g., 600x400)
                                            chartview->setFixedSize(400, 280);

                                            chartview->setRenderHint(QPainter::Antialiasing);
                                            chartview->setParent(ui->label_32);

                                            ui->label_32->setStyleSheet("background: transparent; color: white; ");
                                        ui->label_32->show();
        QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("Suppression effectuée"),QMessageBox::Cancel);
    }
    else {
        QMessageBox::critical(nullptr,QObject::tr("Erreur"),QObject::tr("Suppression non effectuée."),QMessageBox::Cancel);
    }
    ui->table->setModel(C.afficher());


}



void MainWindow::on_bt_modifier_clicked()
{

    ui->comboBox->hide();
    ui->groupBox_10->show();
    QString mcode = ui->ccode->currentText();
                QSqlQuery query;
                query.prepare("SELECT * FROM conteneur WHERE code = :code");
                query.bindValue(":code", mcode);

                if (query.exec() && query.next()) {

                      QString metat=query.value("etat").toString();
                      QString mtaille = query.value("taille").toString();
                      QString mlocalisation = query.value("localisation").toString();


                      ui->m_etat->setCurrentText(metat);
                      ui->m_taille->setCurrentText(mtaille);
                      ui->m_localisation->setText(mlocalisation);

                  }


}

void MainWindow::on_pushButton_clicked()
{
    ui->comboBox->show();
    ui->groupBox_10->hide();
}

void MainWindow::on_bt_modifier_2_clicked()
{

    Conteneur c;
              c.setcode(ui->ccode->currentText());
                c.setetat(ui->m_etat->currentText());
                c.settaille(ui->m_taille->currentText());
                c.setlocation(ui->m_localisation->text());


    bool test=c.modifier(c.getcode());
    if(test)
    {
        ui->label_32->hide();
       QList<QWidget*> childWidgets = ui->label_32->findChildren<QWidget*>();
               for (QWidget* childWidget : childWidgets) {
                   childWidget->deleteLater();

               }
               //the clear didnt work, but my goal is when i second click this button it deleted old chart and renders a new one
               ui->label_32->clear();
               ui->label_32->hide();

           float s0, s1;
           s0 = countType("Sature");
           s1 = countType("Non sature");


           float stat = s0 + s1 ;
           float x = (stat != 0) ? (s0 * 100) / stat : 0.0;
           float y = (stat != 0) ? (s1 * 100) / stat : 0.0;

           QString ch1 = QString("Sature %1%").arg(x);
           QString ch2 = QString("Non sature %1%").arg(y);


           QPieSeries *series = new QPieSeries();
                   QPieSlice *slice = series->append(ch1, x);
                   slice->setLabelVisible();
                   slice->setLabelColor(QColor("#FFFFFF"));
                   slice->setBrush(QColor(165, 255, 113));



                   QPieSlice *slice1 = series->append(ch2, y);
                   slice1->setLabelVisible();
                   slice1->setLabelColor(QColor("#FFFFFF"));
                   slice1->setBrush(QColor(252, 174, 25));

                   QChart *chart = new QChart();
                   chart->addSeries(series);
                   chart->setAnimationOptions(QChart::SeriesAnimations);
                   QBrush backgroundBrush(QColor(187, 93, 87, 0));
                   chart->setBackgroundBrush(backgroundBrush);

                   QChartView *chartview = new QChartView(chart);

                   // Set a custom size for the chart view (e.g., 600x400)
                   chartview->setFixedSize(400, 280);

                   chartview->setRenderHint(QPainter::Antialiasing);
                   chartview->setParent(ui->label_32);

                   ui->label_32->setStyleSheet("background: transparent; color: white; ");
               ui->label_32->show();
        QMessageBox::information(nullptr , QObject::tr("OK"),QObject::tr("modification effectué."),QMessageBox::Cancel);
    }
    else {
        QMessageBox::critical(nullptr,QObject::tr("ERREUR"),QObject::tr("modification non effectué."), QMessageBox::Cancel);
    }
     ui->table->setModel(c.afficher());
     ui->comboBox->show();
     ui->groupBox_10->hide();

}



void MainWindow::on_rechercher_editingFinished()
{

}

void MainWindow::on_comboBox_currentTextChanged(const QString &arg1)
{

    QSqlQuery query;
    QSqlQueryModel* model = new QSqlQueryModel();
    if(arg1=="Etat"){
        query.prepare("SELECT code,etat,taille FROM conteneur ORDER BY etat ASC ");
    }
    else{
        if(arg1=="Taille"){
            query.prepare("SELECT code,etat,taille FROM conteneur ORDER BY taille ASC ");

        }
        else {
            if(arg1=="Code"){
                query.prepare("SELECT code,etat,taille FROM conteneur ORDER BY Code ASC ");
            }
        }

    }

    if (query.exec()) {
        model->setQuery(query);
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("Code"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Etat"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Taille"));
        ui->table->setModel(model);
    }

}

void MainWindow::on_pdf_clicked()
{
    /*QSqlQuery query;
        query.exec("SELECT * FROM conteneur");

        // Create a QPdfWriter to write to a PDF file
        QPdfWriter pdfWriter("conteneur.pdf");
        pdfWriter.setPageSize(QPageSize(QPageSize::A4));
        pdfWriter.setPageOrientation(QPageLayout::Portrait);
        pdfWriter.setPageMargins(QMarginsF(100, 100, 100, 100));

        // Create a QPainter to draw on the PDF
        QPainter painter(&pdfWriter);

        // Create a QTextDocument to format the data
        QTextDocument doc;

        // Create a QTextCursor to write to the QTextDocument
        QTextCursor cursor(&doc);

        // Create a table format with 3 columns and adjust the table and text size
        QTextTableFormat tableFormat;
        tableFormat.setAlignment(Qt::AlignLeft);
        tableFormat.setBorderStyle(QTextFrameFormat::BorderStyle_Solid);
        tableFormat.setCellSpacing(0);
        tableFormat.setCellPadding(5); // Adjust cell padding for more space

        // Define the table
        QTextTable* table = cursor.insertTable(1, 3, tableFormat);

        // Set column widths and make the table larger
        table->format().setColumnWidthConstraints(QVector<QTextLength>{
            QTextLength(QTextLength::PercentageLength, 550), // Adjust the column widths
            QTextLength(QTextLength::PercentageLength, 550),
            QTextLength(QTextLength::PercentageLength, 650)
        });

        // Create a QFont with a larger size
        QFont font = doc.defaultFont();
        font.setPointSize(140); // Adjust the font size
        doc.setDefaultFont(font);

        // Populate the table with column headers
        QTextTableCell headerCell = table->cellAt(0, 0);
        headerCell.firstCursorPosition().insertText("Code");
        QTextTableCell headerCell2 = table->cellAt(0, 1);
        headerCell2.firstCursorPosition().insertText("Etat");
        QTextTableCell headerCell3 = table->cellAt(0, 2);
        headerCell3.firstCursorPosition().insertText("Taille");

        // Iterate over the database table rows and write them to the PDF
        int row = 1;
        while (query.next()) {
            QString code = query.value(0).toString();
            QString etat = query.value(1).toString();
            QString taille = query.value(2).toString();

            // Add a new row to the table and populate it with data
            table->appendRows(1);
            QTextTableCell dataCell = table->cellAt(row, 0);
            dataCell.firstCursorPosition().insertText(code);
            QTextTableCell dataCell2 = table->cellAt(row, 1);
            dataCell2.firstCursorPosition().insertText(etat);
            QTextTableCell dataCell3 = table->cellAt(row, 2);
            dataCell3.firstCursorPosition().insertText(taille);

            row++;
        }
              doc.drawContents(&painter);
       painter.end();

       QMessageBox::information(this, "PDF Exported", "PDF file has been created.");*/

    QString strStream;

                                 QTextStream out(&strStream);



                                 const int rowCount = ui->table->model()->rowCount();

                                 const int columnCount = ui->table->model()->columnCount();



                                 out <<  "<html>\n"

                                     "<head>\n"

                                     "<meta Content=\"Text/html; charset=Windows-1251\">\n"

                                     <<  QString("<title>%1</title>\n").arg("strTitle")

                                     <<  "</head>\n"

                                     "<body bgcolor=#ffffff link=#5000A0>\n"



                                    //     "<align='right'> " << datefich << "</align>"

                                     "<center> <H1>Liste des conteneurs </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";



                                 // headers

                                 out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";

                                 for (int column = 0; column < columnCount; column++)

                                     if (!ui->table->isColumnHidden(column))

                                         out << QString("<th>%1</th>").arg(ui->table->model()->headerData(column, Qt::Horizontal).toString());

                                 out << "</tr></thead>\n";



                                 // data table

                                 for (int row = 0; row < rowCount; row++) {

                                     out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";

                                     for (int column = 0; column < columnCount; column++) {

                                         if (!ui->table->isColumnHidden(column)) {

                                             QString data = ui->table->model()->data(ui->table->model()->index(row, column)).toString().simplified();

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
int MainWindow::countType(const QString& etat)
{
    int count = 0;

    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM conteneur WHERE etat = :etat");
    query.bindValue(":etat", etat);

    if (query.exec() && query.next()) {
        count = query.value(0).toInt();
    }

    return count;
}


void MainWindow::on_pushButton_4_clicked()
{
     QSqlQuery query;
    QString lc=ui->ccode->currentText();
      query.prepare("SELECT * FROM conteneur WHERE code = :code");
      query.bindValue(":code", lc);

      if (query.exec() && query.next()) {

            QString mlocalisation = query.value("localisation").toString();




        }
}

void MainWindow::on_rechercher_returnPressed()
{
    QString chercher = ui->rechercher->text();
    QSqlQuery query;
    QSqlQueryModel* model = new QSqlQueryModel();

    query.prepare("SELECT code, etat, taille FROM conteneur WHERE code = :chercher");
    query.bindValue(":chercher", chercher);

    if (query.exec() && query.next()) {
        model->setQuery(query);
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("Code"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Etat"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Taille"));
        ui->table->setModel(model);
    }
    else
    {
        QMessageBox::critical(this, "Introuvale", "Le conteneur n'existe pas");
    }
}
void MainWindow::limitInputLength(const QString &text) {
    if (text.length() > 4) {
        // Si la longueur du texte dépasse 4 caractères, supprimez les caractères excédents
        ui->a_code->setText(text.left(4));


    }
}
void MainWindow::limitInputLength2(const QString &text) {
    if (text.length() > 4) {
        // Si la longueur du texte dépasse 4 caractères, supprimez les caractères excédents

        ui->rechercher->setText(text.left(4));

    }
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->comboBox->show();
    ui->groupBox_14->hide();
}

void MainWindow::on_pdf_2_clicked()
{
    ui->table->setModel(C.afficher());
}


void MainWindow::on_evoyer_mail_clicked()
{
    mailer::sendEmail("nouhahbhbn@gmail.com", "hi", "Localisation");
    QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("Message envoyé"),QMessageBox::Cancel);

}
void MainWindow::updateTimeSlot()
{
    // Mettre à jour le temps actuel et l'afficher dans l'étiquette
    currentTime = currentTime.addSecs(1);
    ui->temp->setText(currentTime.toString("hh:mm:ss"));
}

void MainWindow::on_pushButton_5_clicked()
{
    ui->comboBox->show();
    ui->groupBox_15->hide();
}

void MainWindow::on_pdf_3_clicked()
{
    ui->groupBox_15->show();


}



void MainWindow::on_pdf_4_clicked()
{
    QSqlQueryModel *model = qobject_cast<QSqlQueryModel*>(ui->table->model());

            if (model) {
                QString content;
                //header
                for (int col = 0; col < model->columnCount(); ++col) {
                    content += model->headerData(col, Qt::Horizontal).toString() + "\t ";
                }
                content += "\n";
                // Iterate through the data in the model and add it to the content
                for (int row = 0; row < model->rowCount(); ++row) {
                    for (int col = 0; col < model->columnCount(); ++col) {
                        content += model->data(model->index(row, col)).toString() + "\t";
                    }
                    content += "\n";
                }

                // Create a QTextDocument and set its content
                QTextDocument document;
                document.setPlainText(content);

                // Create a dialog to select the save location for the Word document
                QString fileName = QFileDialog::getSaveFileName(this, "Exporter en Word", "C:/Users/talel/Desktop/New folder/interfaci", "Fichiers Word (*.docx)");

                if (!fileName.isEmpty()) {
                    // Create a QTextDocumentWriter to generate the Word document
                    QTextDocumentWriter writer(fileName);
                    writer.setFormat("docx");
                    QMessageBox::information(this, "Export Word", "Le document Word a été créé avec succès.");
                    // Write the document to the Word file
                   /* if (writer.write(&document)) {
                        // Display a message to the user to confirm successful export
                        QMessageBox::information(this, "Export Word", "Le document Word a été créé avec succès.");
                    } else {
                        // Display an error message if the export fails
                        QMessageBox::critical(this, "Export Word", "Erreur lors de la création du document Word.");
                    } */
                }
            }
}
void MainWindow::on_pushButton_3_clicked()
{
    QString fileName = "C:/Users/Lenovo/Desktop/projet c++/conteneures/sons.mp3";
        if (!fileName.isEmpty())
        {
            mediaPlayer->setMedia(QUrl::fromLocalFile(fileName));
            mediaPlayer->play();
            isMuted = false;
            previousVolume = 100;
             mediaPlayer->setVolume(100);
        }
}

void MainWindow::on_pushButton_7_clicked()
{
    if (isMuted)
            toggleMute();
        int volume = mediaPlayer->volume();
        if (volume < 100)
        {
            volume += 10;
            mediaPlayer->setVolume(volume);
        }
}

void MainWindow::on_pushButton_6_clicked()
{
    if (isMuted)
           toggleMute();
       int volume = mediaPlayer->volume();
       if (volume > 0)
       {
           volume -= 10;
           mediaPlayer->setVolume(volume);
       }
}
void MainWindow::on_pushButton_8_clicked()
{
    toggleMute();
}
void MainWindow::toggleMute()
{
        mediaPlayer->setVolume(0);


}

void MainWindow::on_radioButton_clicked()
{
    QString fileName = "C:/Users/Lenovo/Desktop/projet c++/conteneures/sons.mp3";
        if (!fileName.isEmpty())
        {
            mediaPlayer->setMedia(QUrl::fromLocalFile(fileName));
            mediaPlayer->play();
            isMuted = false;
            previousVolume = 100;
             mediaPlayer->setVolume(100);
        }
}

void MainWindow::on_radioButton_2_clicked()
{
     toggleMute();
}

void MainWindow::on_radioButton_3_clicked()
{
    showFullScreen();
}

void MainWindow::on_radioButton_4_clicked()
{
    showNormal();
}

void MainWindow::on_pdf_5_clicked()
{
    mailer mail;
    QString host=ui->ccode_2->currentText();
    QString objet=ui->objet->text();
    QString body=ui->textEdit->toPlainText();
    int i=mail.sendEmail(host, objet, body);
    if(i!=-1)
    {
        QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("Message envoyé"),QMessageBox::Cancel);

    }
}



void MainWindow::on_pdf_6_clicked()
{
    ui->objet->clear();
    ui->textEdit->clear();
}
void MainWindow::update_label()
{
    QSqlQuery query;

    data=A.read_from_arduino();
    QString code=ui->ccode->currentText();
    qDebug() << "data="<<data;
    if(data=="1"){

        query.prepare("UPDATE CONTENEUR SET ETAT='Sature' WHERE CODE=:code ");
        query.bindValue(":code",code);
        query.exec();

    }
    else{
        query.prepare("UPDATE CONTENEUR SET ETAT='Non sature' WHERE CODE=:code ");
        query.bindValue(":code",code);
        query.exec();

    }
}
