#include "camion.h"

Camion::Camion(QWidget *parent):QWidget(parent)
{
    this->resize(1280,632);
    QFont customFont("Barlow Condensed", 16);
    this->setFont(customFont);
    QPixmap rech(":/image/inter/recherche.png");
    QPixmap back_ajout(":/image/inter/RectangleAjouter.png");
    QPixmap back_list(":/image/inter/RectangleListe.png");
    QPixmap back_cal(":/image/inter/RectangleCalendrier.png");
    QPixmap trash(":/image/inter/contenaire.png");
    QPixmap check(":/image/inter/check.png");
    QPixmap pdf(":/image/inter/pdf (1).png");
    QPixmap infor(":/image/inter/infos.png");
    tableau= new QFrame(this);
    tableau->setGeometry(10,50,back_list.width(),back_list.height());
    list=new QTableView(tableau);
    ajouter=new QFrame(this);
    ajouter->setGeometry(655,50,back_list.width(),back_list.height());
    calendrier=new QFrame(this);
    calendrier->setGeometry(10,342,back_cal.width(),back_cal.height());
    stat=new QFrame(this);
    stat->setGeometry(682,342,655,355);
    rechercher=new QFrame(this);

    /*tableau_lab=new QLabel(tableau);
    tableau_lab->setPixmap(back_list);*/
    ajouter_lab=new QLabel(ajouter);
    ajouter_lab->setPixmap(back_list);
    calendrier_lab=new QLabel(calendrier);
    calendrier_lab->setPixmap(back_cal);
    stat_lab=new QLabel(stat);


    /*QLabel *ajoutText= new QLabel("Ajouter",ajouter);
    ajoutText->setStyleSheet("color:black;font-size:20px;");
    ajoutText->setGeometry();*/

    mat_supp=new QComboBox(ajouter);
    mat_supp->setStyleSheet("QComboBox {background-color : rgba(251, 255, 255, 0.40);border-radius: 15px;padding-left:10px;background-image: url(:/image/inter/fleche droite.png); background-position: right;background-repeat: no-repeat;color:rgb(88, 88, 88);  font-size: 20px; }"
                            "QComboBox::drop-down {subcontrol-origin: padding;subcontrol-position:  right top;border:none;}"
                            "QComboBox:hover{border : 1.5px solid rgba(247, 173, 28, 1);}"
                            "QComboBox:focus{border : 1.5px solid rgba(251, 255, 255, 0.40);background-color : rgb(235, 244, 255);}");
    mat_supp->setGeometry(440,20,150,40);
    remplir_combo(mat_supp);
    supp_btn=new QPushButton(ajouter);
    supp_btn->setStyleSheet("background:#FFAE17;border-radius:20px;color:white;font-size:30px;");
    supp_btn->setGeometry(500,70,40,40);
    supp_btn->setIcon(QIcon(trash));

    for (int i=0; i<4 ; i++) {
        info_ajout1[i]=new QLineEdit(ajouter);
        info_ajout1[i]->setStyleSheet("background:rgba(251, 255, 255, 0.40);border-radius:20px;font-size:20px;border:1px solid lightgreen; padding-left:20px;");
        info_ajout1[i]->setGeometry(10,20+(i*60),246,40);
    }
    info_ajout1[0]->setPlaceholderText("Matricule");
    info_ajout1[1]->setPlaceholderText("Destination");
    info_ajout1[2]->setPlaceholderText("nombre d'entretien");
    info_ajout1[2]->setValidator(new QIntValidator(100,9999,this));
    info_ajout1[3]->setPlaceholderText("Note");
    info_ajout1[3]->resize(246,60);
    QRegExp regex4("[a-z]+", Qt::CaseInsensitive);
    QRegExpValidator* validator = new QRegExpValidator(regex4, this);
    info_ajout1[1]->setValidator(validator);

    for (int i=0; i< 2;i++) {
        info_ajout2[i]=new QComboBox(ajouter);
        info_ajout2[i]->setStyleSheet("QComboBox {background-color : rgba(251, 255, 255, 0.40);border-radius: 15px;padding-left:10px;background-image: url(:/image/inter/fleche droite.png); background-position: right;background-repeat: no-repeat;color:rgb(88, 88, 88);  font-size: 20px; }"
                                      "QComboBox::drop-down {subcontrol-origin: padding;subcontrol-position:  right top;border:none;}"
                                      "QComboBox:hover{border : 1.5px solid rgba(247, 173, 28, 1);}"
                                      "QComboBox:focus{border : 1.5px solid rgba(251, 255, 255, 0.40);background-color : rgb(235, 244, 255);}");
        info_ajout2[i]->setGeometry(276,50+(i*60),150,40);
    }
    info_ajout2[0]->addItem("Bonne Etat");
    info_ajout2[0]->addItem("En Cours");
    info_ajout2[0]->addItem("En Panne");
    info_ajout2[1]->addItem("Disponible");
    info_ajout2[1]->addItem("Indisponible");

    date_ajout=new QDateEdit(ajouter);
    date_ajout->setStyleSheet("QDateEdit {background-color : rgba(251, 255, 255, 0.40);border-radius: 15px;padding-left:10px;background-image: url(:/image/inter/fleche droite.png); background-position: right;background-repeat: no-repeat;color:rgb(88, 88, 88);  font-size: 20px; }"
                              "QDateEdit::drop-down {subcontrol-origin: padding;subcontrol-position:  right top;border:none;}"
                              "QDateEdit:hover{border : 1.5px solid rgba(247, 173, 28, 1);}"
                              "QDateEdit:focus{border : 1.5px solid rgba(251, 255, 255, 0.40);background-color : rgb(235, 244, 255);}");
    date_ajout->setGeometry(276,170,150,40);
    date_ajout->setDate(QDate::currentDate());


    ajout_btn=new QPushButton(ajouter);
    ajout_btn->setStyleSheet("background:#FFAE17;border:1px solid lightgreen;border-radius:20px;font-size:20px;color:white;");
    ajout_btn->setGeometry(440,200,150,50);
    ajout_btn->setText("Enregistrer");
    applyShadow(ajout_btn);


    modif_btn=new QPushButton(ajouter);
    modif_btn->setStyleSheet("background:#FFAE17;border:1px solid lightgreen;border-radius:20px;font-size:20px;color:white;");
    modif_btn->setGeometry(440,130,150,50);
    modif_btn->setText("Modifier");
    applyShadow(modif_btn);



    modif_lab=new QLabel(this);
    modif_lab->setStyleSheet("background:rgba(255,255,255,0.5);border-radius:20px;");
    modif_lab->setPixmap(back_list);
    modif_lab->setGeometry(350,300,back_list.width(),back_list.height());

    for (int i=0; i<3 ; i++) {
        info_modif1[i]=new QLineEdit(modif_lab);
        info_modif1[i]->setStyleSheet("background:rgba(251, 255, 255, 0.40);border-radius:20px;font-size:20px;border:1px solid lightgreen; padding-left:20px;");
        info_modif1[i]->setGeometry(10,20+(i*60),246,40);
    }
    info_modif1[0]->setPlaceholderText("Destination");
    info_modif1[1]->setPlaceholderText("nombre d'entretien");
    info_modif1[2]->setPlaceholderText("Note");
    info_modif1[2]->resize(246,100);
    for (int i=0; i< 3;i++) {
        info_modif2[i]=new QComboBox(modif_lab);
        info_modif2[i]->setStyleSheet("QComboBox {background-color : rgba(251, 255, 255, 0.40);border-radius: 15px;padding-left:10px;background-image: url(:/image/inter/fleche droite.png); background-position: right;background-repeat: no-repeat;color:rgb(88, 88, 88);  font-size: 20px; }"
                                      "QComboBox::drop-down {subcontrol-origin: padding;subcontrol-position:  right top;border:none;}"
                                      "QComboBox:hover{border : 1.5px solid rgba(247, 173, 28, 1);}"
                                      "QComboBox:focus{border : 1.5px solid rgba(251, 255, 255, 0.40);background-color : rgb(235, 244, 255);}");
        info_modif2[i]->setGeometry(276,20+(i*60),150,40);
    }

    info_modif2[1]->addItem("Bonne Etat");
    info_modif2[1]->addItem("En Cours");
    info_modif2[1]->addItem("En Panne");
    info_modif2[2]->addItem("Disponible");
    info_modif2[2]->addItem("Indisponible");

    date_modif=new QDateEdit(modif_lab);
    date_modif->setStyleSheet("QDateEdit {background-color : rgba(251, 255, 255, 0.40);border-radius: 15px;padding-left:10px;background-image: url(:/image/inter/fleche droite.png); background-position: right;background-repeat: no-repeat;color:rgb(88, 88, 88);  font-size: 20px; }"
                              "QDateEdit::drop-down {subcontrol-origin: padding;subcontrol-position:  right top;border:none;}"
                              "QDateEdit:hover{border : 1.5px solid rgba(247, 173, 28, 1);}"
                              "QDateEdit:focus{border : 1.5px solid rgba(251, 255, 255, 0.40);background-color : rgb(235, 244, 255);}");
    date_modif->setGeometry(276,190,150,40);

    modif_btnBox=new QPushButton(modif_lab);
    modif_btnBox->setStyleSheet("background:#FFAE17;border:1px solid lightgreen;border-radius:20px;font-size:20px;color:white;");
    modif_btnBox->setGeometry(440,130,150,50);
    modif_btnBox->setText("Modifier");
    applyShadow(modif_btnBox);

    exit_modif=new QPushButton(modif_lab);
    exit_modif->setStyleSheet("background:#FFAE17;border-radius:20px;color:white;font-size:30px;");
    exit_modif->setGeometry(550,20,40,40);
    exit_modif->setIcon(QIcon(check));



    rechercher->setGeometry(15,0,240,40);
    btn_search = new QPushButton(rechercher);
    btn_search->setStyleSheet("background:#54cdb7;border-top-left-radius:20px;border-bottom-left-radius:20px;color:white;font-size:30px;");
    btn_search->setIcon(QIcon(rech));
    btn_search->setGeometry(0,0,40,40);
    recherche=new QLineEdit(rechercher);
    recherche->setPlaceholderText("Rechercher");
    recherche->setStyleSheet("background:#54cdb7;border-top-right-radius:20px;border-bottom-right-radius:20px;font-size:20px;color:white;");
    recherche->setGeometry(40,0,200,40);
    trie = new QPushButton("Trier",this);
    trie->setStyleSheet("background:#54cdb7;border-radius:20px;font-size:20px;color:white;");
    trie->setGeometry(310,0,121,40);
    trie->setFont(customFont);
    pdf_btn=new QPushButton(this);
    pdf_btn->setStyleSheet("background:#FFAE17;border-radius:20px;color:white;font-size:30px;");
    pdf_btn->setGeometry(450,0,40,40);
    pdf_btn->setIcon(QIcon(pdf));
    refrech_btn=new QPushButton(this);
    refrech_btn->setStyleSheet("background:#FFAE17;border-radius:20px;color:white;font-size:30px;");
    refrech_btn->setGeometry(500,0,40,40);
    refrech_btn->setIcon(QIcon(infor));



    stat->setStyleSheet("background:transparent;");
    QPieSeries *series = new QPieSeries();
    series->setHoleSize(0.35);
    series->append("Bonne Etat 4.28%",4.28);
    QPieSlice *slice = series->append("En Cours 15.6%",15.6);
    slice->setExploded();
    slice->setLabelVisible();
    series->append("En Panne 23.8%",23.8);
    series->append("Others 56.4%",56.4);
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setAnimationOptions(QChart::SeriesAnimations);
    chart->setTheme(QChart::ChartThemeLight);
    chart->setTitle("DONUT");
    QBrush transparentBrush(Qt::transparent);
    chart->setBackgroundBrush(transparentBrush);
    QChartView *chartview = new QChartView(chart);
    chartview->setGeometry(0,0,500,300);
    chartview->setRenderHint(QPainter::Antialiasing);
    chartview->setParent(stat);


    list->setGeometry(0,0,back_list.width(),back_list.height());
    list->setStyleSheet("QTableView {border-radius: 36px;border: 3px solid #FCAE19;gridline-color:#FCAE19;background: rgba(123, 183, 189, 0.80);text-align: center;color:rgb(88, 88, 88); font-family: Arial, sans-serif; font-size: 14px;font-weight: bold; color: rgba(81, 81, 81,0.9);}"
                    "QHeaderView {background-color:rgba(123, 183, 189, 0);color: rgb(74, 74, 74);font-size: 20px;color: rgb(255, 170, 0);}"
                    "QHeaderView::section {background-color: transparent;border:0.5px solid transparent;border-radius: 36px;}"
                        "QTableView QTableCornerButton::section {background-color: transparent;border: none;}");
    list->setModel(afficher());

    modif_lab->hide();
    QHeaderView* headerView = list->horizontalHeader();
    headerView->setSectionResizeMode(QHeaderView::Stretch);

    connect(ajout_btn,&QPushButton::clicked,this,&Camion::enregistrer);
    connect(supp_btn,&QPushButton::clicked,this,&Camion::supp_cam);
    connect(modif_btnBox,&QPushButton::clicked,this,&Camion::modifier_cam);
    connect(modif_btn,&QPushButton::clicked,this,&Camion::affiche_modifpopup);
    connect(exit_modif,&QPushButton::clicked,this,&Camion::exit_modifpopup);
    connect(btn_search,&QPushButton::clicked,this,&Camion::Recherher);
    connect(trie,&QPushButton::clicked,this,&Camion::sortData);
    connect(refrech_btn,&QPushButton::clicked,this,&Camion::refreshTable);
    connect(pdf_btn,&QPushButton::clicked,this,&Camion::showpdf);
}
/*void Camion::init()
{
     connect(info_modif2[0], QOverload<int>::of(&QComboBox::currentIndexChanged), this, &Camion::on_mid_currentIndexChanged);
}*/
Camion::Camion(QString mat,QString etat,QString dispo,QString desti,int nb_ent,QDate d,QString note)
{
    this->matricule=mat;
    this->etat=etat;
    this->disponibilite=dispo;
    this->destination=desti;
    this->nbEntretien=nb_ent;
    this->dateEntretien=d;
    this->note=note;
}
void Camion::applyShadow(QWidget *widget)
{
    QGraphicsDropShadowEffect* shadow = new QGraphicsDropShadowEffect;
        shadow->setBlurRadius(10);
        shadow->setColor(QColor(0, 0, 0, 150));
        shadow->setOffset(5, 5);
        widget->setGraphicsEffect(shadow);
}
bool Camion::ajouter_cam()
{
    QString nb_string = QString::number(nbEntretien);
    QSqlQuery query;
         query.prepare("INSERT INTO camion (matricule, etat, disponibilite,DESTINATION,NB_ENTRETIEN,DATE_ENTRETIEN,NOTE) "
                       "VALUES (:matricule, :etat, :disponibilite , :dest, :nb, :date, :note)");
         query.bindValue(":matricule", matricule);
         query.bindValue(":etat", etat);
         query.bindValue(":disponibilite", disponibilite);
         query.bindValue(":dest", destination);
         query.bindValue(":nb", nb_string);
         query.bindValue(":date", dateEntretien);
         query.bindValue(":note", note);
        return query.exec();
}

void Camion::enregistrer()
{
    QRegExp regex2("^[A-Za-z0-9]{1,4}$");
    QRegExp regex3("^[A-Za-z0-9]{1,12}$");
    QString matricule = info_ajout1[0]->text();
    QDate date= date_ajout->date();
    QString note= info_ajout1[3]->text();
    QString etat = info_ajout2[0]->currentText();
    QString dispon = info_ajout2[1]->currentText();
    QString dest = info_ajout1[1]->text();
    int nb =info_ajout1[2]->text().toInt();

    if(info_ajout1[0]->text().isEmpty() && info_ajout1[1]->text().isEmpty() && info_ajout1[2]->text().isEmpty() && info_ajout1[3]->text().isEmpty())

    {
        QMessageBox::critical(nullptr,QObject::tr("Not OK"),QObject::tr("Il faut remplir les Champs.\n""Click cancel to exit."),QMessageBox::Cancel);
    }
     else {
            if(info_ajout1[0]->text().isEmpty()){
                QMessageBox::critical(nullptr,QObject::tr("Not OK"),QObject::tr("Il faut remplir la matricule.\n""Click cancel to exit."),QMessageBox::Cancel);
            }
            else{
                    if(!(matricule.contains("C",Qt::CaseInsensitive) &&  matricule.contains(regex2)))
                    {
                           QMessageBox::critical(nullptr,QObject::tr("Not OK"),QObject::tr("La matricule doit etre avec C et trois chiffres.\n""Click cancel to exit."),QMessageBox::Cancel);
                    }
                    else{
                            if(info_ajout1[1]->text().isEmpty()){
                                QMessageBox::critical(nullptr,QObject::tr("Not OK"),QObject::tr("Il faut remplir la distination.\n""Click cancel to exit."),QMessageBox::Cancel);
                            }
                            else{
                                if(info_ajout1[2]->text().isEmpty()){
                                    QMessageBox::critical(nullptr,QObject::tr("Not OK"),QObject::tr("Il faut remplir le nombre d'entretien.\n""Click cancel to exit."),QMessageBox::Cancel);
                                }
                                else {
                                    if(info_ajout1[3]->text().isEmpty()){
                                        QMessageBox::critical(nullptr,QObject::tr("Not OK"),QObject::tr("Il faut remplir la Note.\n""Click cancel to exit."),QMessageBox::Cancel);
                                    }
                                    else
                                    {
                                        Camion c(matricule,etat,dispon,dest,nb,date,note);
                                        bool test=c.ajouter_cam();
                                            if(test)
                                            {
                                                 QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("Ajout successful.\n""Click cancel to exit."),QMessageBox::Cancel);
                                                 list->setModel(c.afficher());
                                                 info_ajout1[0]->clear();
                                                 info_ajout1[3]->clear();
                                                 info_ajout1[1]->clear();
                                                 info_ajout1[2]->clear();
                                                 remplir_combo(mat_supp);
                                            }
                                            else
                                            {
                                                QMessageBox::critical(nullptr,QObject::tr("Not OK"),QObject::tr("Ajout failed.\n""Click cancel to exit."),QMessageBox::Cancel);
                                            }
                                    }
                                }
                                }
                             }
                        }
        }
}
QSqlQueryModel *Camion::afficher()
{
    QSqlQueryModel *model = new QSqlQueryModel;
          model->setQuery("SELECT * FROM camion");

    return  model;
}
bool Camion::supprimer(QString mat)
{

    QSqlQuery query;
         query.prepare("DELETE FROM camion where matricule=:mat");
         query.bindValue(":mat", mat);

        return query.exec();
}
void Camion::supp_cam()
{
    Camion c1;
    c1.setMatricule(mat_supp->currentText());
    QRegExp regex2("^[A-Za-z0-9]{1,4}$");

        bool test = c1.supprimer(c1.getMatricule());
        if(test)
        {
             QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("Suppression successful.\n""Click cancel to exit."),QMessageBox::Cancel);
            list->setModel(c1.afficher());
            remplir_combo(mat_supp);
        }
        else
        {
            QMessageBox::critical(nullptr,QObject::tr("Not OK"),QObject::tr("Suppression failed.\n""Click cancel to exit."),QMessageBox::Cancel);
        }


}

void Camion::Recherher()
{
    QString matri=recherche->text();


             QSqlQueryModel* searchModel = new QSqlQueryModel();
             searchModel->setQuery("SELECT * FROM camion WHERE matricule LIKE '%" + matri + "%'");

             if (searchModel->rowCount() > 0) {

                 list->setModel(searchModel);


                 QHeaderView* headerView = list->horizontalHeader();
                 headerView->setSectionResizeMode(QHeaderView::Stretch);
             } else {

                 QMessageBox::information(this, "Search Result", "camion does not exist.");
             }
}

bool Camion :: update_cam(QString mat)

{
    QString nb_string = QString::number(nbEntretien);
    QSqlQuery query;
    query.prepare("UPDATE camion SET matricule=:mat , etat=:etat_i , disponibilite=:disp ,DESTINATION=:dest,NB_ENTRETIEN=:nb,DATE_ENTRETIEN=:date,NOTE=:note where matricule=:mat");
    query.bindValue(":mat", mat);
    query.bindValue(":etat_i", etat);
    query.bindValue(":disp", disponibilite);
    query.bindValue(":dest", destination);
    query.bindValue(":nb", nb_string);
    query.bindValue(":date", dateEntretien);
    query.bindValue(":note", note);
    return query.exec();
}
void Camion ::modifier_cam()
{
    Camion c;
        c.setMatricule(info_modif2[0]->currentText());
        c.setEtat(info_modif2[1]->currentText());
        c.setDisponibilite(info_modif2[2]->currentText());
        c.setDestination(info_modif1[0]->text());
        c.setNbEntretien(info_modif1[1]->text().toInt());
        c.setNote(info_modif1[2]->text());
        bool test= c.update_cam( c.getMatricule() );
        if(test)
        {
            QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("Modification successful.\n""Click cancel to exit."),QMessageBox::Cancel);
             list->setModel(c.afficher());
        }
        else {
             QMessageBox::critical(nullptr,QObject::tr("Not OK"),QObject::tr("Modification failed.\n""Click cancel to exit."),QMessageBox::Cancel);
        }



}

void Camion::remplir_combo(QComboBox *mat_supp)
{
    QSqlQuery query;
                  mat_supp->clear();
                      query.exec("SELECT matricule FROM camion");
                      while (query.next()) {
                          QString mat = query.value(0).toString();
                          mat_supp->addItem(mat);}
}

void Camion::updateUI(int selectedMat)
{

    QSqlQuery query;
    QString matr=info_modif2[0]->itemText(selectedMat);

    query.prepare("SELECT  etat, disponibilite,DESTINATION,NB_ENTRETIEN,DATE_ENTRETIEN,NOTE FROM camion WHERE matricule = :mat");
    query.bindValue(":mat", matr);

    if (query.exec() && query.next()) {
        QString etat = query.value(0).toString();
        QString dispo = query.value(1).toString();
        QString dest = query.value(2).toString();
        QString nb = query.value(3).toString();
        QDate date = query.value(4).toDate();
        QString note = query.value(5).toString();


        info_modif1[0]->setText(dest);
        info_modif1[1]->setText(nb);
        info_modif1[2]->setText(note);


        int index = info_modif2[1]->findText(etat);
        if (index != -1) {
            info_modif2[1]->setCurrentIndex(index);
        }
         index = info_modif2[2]->findText(dispo);
        if (index != -1) {
            info_modif2[2]->setCurrentIndex(index);
        }

        date_modif->setDate(date);

    }
}

/*void Camion::on_mid_currentIndexChanged(int index)
{
    // Get the selected ID from the combo box
   // int selectedId = info_modif2[0]->itemText(index).toInt();

    // Call the function to update the UI with the selected ID's data
    updateUI(index);

    // Show the appropriate UI elements
    affiche_modifpopup();
}*/
void Camion::affiche_modifpopup() {
    if (modif_lab->isHidden()) {
        modif_lab->show();
        remplir_combo(info_modif2[0]);
        int  mtr=info_modif2[0]->currentIndex();
        updateUI(mtr);
    } else {
        modif_lab->hide();
    }
}

void Camion::exit_modifpopup() {
    if (modif_lab->isVisible()) {
        modif_lab->hide();
    } else {
        modif_lab->show();
    }
}


void Camion::sortData() {
    QSqlQueryModel* sortedModel = new QSqlQueryModel();
    sortedModel->setQuery("SELECT * FROM camion ORDER BY CASE WHEN disponibilite = 'dispo' THEN 1 ELSE 2 END, disponibilite");

    list->setModel(sortedModel);

    QHeaderView* headerView = list->horizontalHeader();
    headerView->setSectionResizeMode(QHeaderView::Stretch);
}
void Camion::refreshTable() {
    // Fetch the updated data from the database
    QSqlQueryModel* updatedModel = new QSqlQueryModel();
    updatedModel->setQuery("SELECT * FROM camion");

    // Set the updated model to the list QTableView
    list->setModel(updatedModel);

    // Adjust column widths if necessary
    QHeaderView* headerView = list->horizontalHeader();
    headerView->setSectionResizeMode(QHeaderView::Stretch);
}




void Camion::showpdf()
{


    // Associez le modèle à votre QTableView

    QSqlQueryModel *model = qobject_cast<QSqlQueryModel*>(list->model());

    if (model) {
        QString content;
        //header
        for (int col = 0; col < model->columnCount(); ++col) {

             content += model->headerData(col, Qt::Horizontal).toString() + "\t ";

                }
        content += "\n";
        // Parcourez les données du modèle et ajoutez-les au contenu
        for (int row = 0; row < model->rowCount(); ++row) {
            for (int col = 0; col < model->columnCount(); ++col) {
                content += model->data(model->index(row, col)).toString() + "\t";
            }
            content += "\n";
        }

        // Créez un objet QTextDocument et définissez son contenu
        QTextDocument document;
        document.setPlainText(content);

        // Créez un dialogue pour sélectionner l'emplacement de sauvegarde du PDF.
        QString fileName = QFileDialog::getSaveFileName(this, "Exporter en PDF", "C:/Users/benam/OneDrive/Documents/ESPRIT 2A40/Projet C++", "Fichiers PDF (*.pdf)");

        if (!fileName.isEmpty()) {
            // Créez un objet QPrinter pour générer le PDF.
            QPrinter printer;
            printer.setOutputFormat(QPrinter::PdfFormat);
            printer.setOutputFileName(fileName);

            // Imprimez le document sur le PDF.
            document.print(&printer);

            // Affichez un message à l'utilisateur pour confirmer l'exportation réussie.
            QMessageBox::information(this, "Export PDF", "Le PDF a été créé avec succès.");
        }
    }
}

int Camion::countType(const QString& etat)
{
    int count = 0;

    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM camion WHERE etat = :etat");
    query.bindValue(":etat", etat);

    if (query.exec() && query.next()) {
        count = query.value(0).toInt();
    }

    return count;
}
