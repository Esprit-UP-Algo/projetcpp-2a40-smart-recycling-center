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
    calendar=new QFrame(this);
    calendar->setGeometry(10,342,back_cal.width(),back_cal.height());
    stat=new QFrame(this);
    stat->setGeometry(682,342,655,355);
    rechercher=new QFrame(this);

    /*tableau_lab=new QLabel(tableau);
    tableau_lab->setPixmap(back_list);*/
    ajouter_lab=new QLabel(ajouter);
    ajouter_lab->setPixmap(back_list);
    calendrier_lab=new QLabel(calendar);
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



    stat->hide();
    float s0, s1,s2;
            s0 = countType("Bonne Etat");
            s1 = countType("En Cours");
            s2 = countType("En Panne");


            float status = s0 + s1 +s2 ;
            float x = (status != 0) ? (s0 * 100) / status : 0.0;
            float y = (status != 0) ? (s1 * 100) / status : 0.0;
            float z = (status != 0) ? (s2 * 100) / status : 0.0;
            QString ch1 = QString("Bonne Etat %1%").arg(x);
            QString ch2 = QString("En Cours %1%").arg(y);
            QString ch3 = QString("En Panne %1%").arg(z);


            QPieSeries *series = new QPieSeries();
            QPieSlice *slice = series->append(ch1, x);
            slice->setLabelVisible();
            slice->setLabelColor(QColor("#FFFFFF"));
            slice->setBrush(QColor(165, 255, 113));



            QPieSlice *slice1 = series->append(ch2, y);
            slice1->setLabelVisible();
            slice1->setLabelColor(QColor("#FFFFFF"));
            slice1->setBrush(QColor(252, 174, 25));

            QPieSlice *slice2 = series->append(ch3, z);
            slice2->setLabelVisible();
            slice2->setLabelColor(QColor("#FFFFFF"));
            slice2->setBrush(QColor(55, 174, 25));

            QChart *chart = new QChart();
            chart->addSeries(series);
            chart->setAnimationOptions(QChart::SeriesAnimations);
            QBrush backgroundBrush(QColor(187, 93, 87, 0));
            chart->setBackgroundBrush(backgroundBrush);


            QChartView *chartview = new QChartView(chart);
            chartview->setGeometry(0,0,500,300);
            chartview->setRenderHint(QPainter::Antialiasing);
            chartview->setParent(stat);
            stat->setStyleSheet("background:transparent;");
            stat->show();



    list->setGeometry(0,0,back_list.width(),back_list.height());
    list->setStyleSheet("QTableView {border-radius: 36px;border: 3px solid #FCAE19;gridline-color:#FCAE19;background: rgba(123, 183, 189, 0.80);text-align: center;color:rgb(88, 88, 88); font-family: Arial, sans-serif; font-size: 14px;font-weight: bold; color: rgba(81, 81, 81,0.9);}"
                    "QHeaderView {background-color:rgba(123, 183, 189, 0);color: rgb(74, 74, 74);font-size: 20px;color: rgb(255, 170, 0);}"
                    "QHeaderView::section {background-color: transparent;border:0.5px solid transparent;border-radius: 36px;}"
                        "QTableView QTableCornerButton::section {background-color: transparent;border: none;}");
    list->setModel(afficher());

    modif_lab->hide();
    QHeaderView* headerView = list->horizontalHeader();
    headerView->setSectionResizeMode(QHeaderView::Stretch);




    histo_btn=new QPushButton(this);
    histo_btn->setStyleSheet("background:#54cdb7;border-radius:20px;font-size:20px;color:white;");
    histo_btn->setGeometry(550,0,121,40);
    histo_btn->setText("Historique");
    applyShadow(histo_btn);

    histolab=new QLabel(this);
    histolab->setStyleSheet("background:rgba(255,255,255,0.5);border-radius:20px;");
    histolab->setPixmap(back_list);
    histolab->setGeometry(350,300,back_list.width(),back_list.height());

    leave_histo=new QPushButton(histolab);
    leave_histo->setStyleSheet("background:#FFAE17;border-radius:20px;color:white;font-size:30px;");
    leave_histo->setGeometry(550,20,40,40);
    leave_histo->setIcon(QIcon(check));

    historique = new QTableView(histolab);
    historique->setGeometry(20,20,400,230);
    historique->setStyleSheet("QTableView {border-radius: 36px;border: 3px solid #FCAE19;gridline-color:#FCAE19;background: rgba(123, 183, 189, 0.80);text-align: center;color:rgb(88, 88, 88); font-family: Arial, sans-serif; font-size: 14px;font-weight: bold; color: rgba(81, 81, 81,0.9);}"
                    "QHeaderView {background-color:rgba(123, 183, 189, 0);color: rgb(74, 74, 74);font-size: 20px;color: rgb(255, 170, 0);}"
                    "QHeaderView::section {background-color: transparent;border:0.5px solid transparent;border-radius: 36px;}"
                        "QTableView QTableCornerButton::section {background-color: transparent;border: none;}");
    //historique->setModel(afficherHISTO());
    afficherHISTO();
    QHeaderView* headerView2 = historique->horizontalHeader();
    headerView2->setSectionResizeMode(QHeaderView::Stretch);
    histolab->hide();


QLabel *date=new QLabel("13 nov 2023 -> 19 nov 2023",this);
date->setGeometry(10,696,500,100);


    connect(ajout_btn,&QPushButton::clicked,this,&Camion::enregistrer);
    connect(supp_btn,&QPushButton::clicked,this,&Camion::supp_cam);
    connect(modif_btnBox,&QPushButton::clicked,this,&Camion::modifier_cam);
    connect(modif_btn,&QPushButton::clicked,this,&Camion::affiche_modifpopup);
    connect(exit_modif,&QPushButton::clicked,this,&Camion::exit_modifpopup);

    connect(histo_btn,&QPushButton::clicked,this,&Camion::affiche_histopopup);
    connect(leave_histo,&QPushButton::clicked,this,&Camion::exit_histapopup);


    connect(btn_search,&QPushButton::clicked,this,&Camion::Recherher);
    connect(trie,&QPushButton::clicked,this,&Camion::sortData);
    connect(refrech_btn,&QPushButton::clicked,this,&Camion::refreshTable);
    connect(pdf_btn,&QPushButton::clicked,this,&Camion::showpdf2);

    Calendrier *reg = new Calendrier(calendar);
    reg->move(0,0);

    int ret= A.connect_arduino();
    switch (ret) {
    case (0):qDebug()<<"arduino is available and connected to:"<<A.getArduino_port_name();
        break;
    case (1):qDebug()<<"arduino is available and not connected to:"<<A.getArduino_port_name();
        break;
    case(-1):qDebug()<<"arduino is not available:";
        break;
    }

    QObject::connect(A.get_serial(),SIGNAL(readyRead()),this,SLOT(updatdispo_arduino()) );
}

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
                                                QDateTime tempsActuel = QDateTime::currentDateTime(); // Récupérer le temps actuel
                                                   QString tempsAjout = tempsActuel.toString("dd/MM/yyyy hh:mm:ss"); // Formatage du temps
                                                   c.ecrireDansFichier1(matricule, tempsAjout);
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
            QDateTime tempsActuel = QDateTime::currentDateTime(); // Récupérer le temps actuel
               QString tempsSuppression = tempsActuel.toString("dd/MM/yyyy hh:mm:ss"); // Formatage du temps
               c1.ecrireDansFichier(c1.getMatricule(), tempsSuppression);
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
        c.setMatricule(mat_supp->currentText());
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
             QDateTime tempsActuel = QDateTime::currentDateTime(); // Récupérer le temps actuel
                QString tempsDeMiseAjour = tempsActuel.toString("dd/MM/yyyy hh:mm:ss"); // Formatage du temps
                c.ecrireDansFichier2(c.getMatricule(), tempsDeMiseAjour);
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




void Camion::affiche_modifpopup() {
    if (modif_lab->isHidden()) {
        modif_lab->show();

        QSqlQuery query;
        QString matr = mat_supp->currentText();

        query.prepare("SELECT  etat, disponibilite, DESTINATION, NB_ENTRETIEN, DATE_ENTRETIEN, NOTE FROM camion WHERE matricule = :mat");
        query.bindValue(":mat", matr);

        if (query.exec() && query.next()) {
            QString etat = query.value("etat").toString();
            QString dispo = query.value("disponibilite").toString();
            QString dest = query.value("DESTINATION").toString();
            QString nb = query.value("NB_ENTRETIEN").toString();
            QDate date = query.value("DATE_ENTRETIEN").toDate();
            QString note = query.value("NOTE").toString();

            info_modif1[0]->setText(dest);
            info_modif1[1]->setText(nb);
            info_modif1[2]->setText(note);
            info_modif2[1]->setCurrentText(etat);
            info_modif2[2]->setCurrentText(dispo);
            date_modif->setDate(date);
        }
    } else {
        modif_lab->hide();
    }
}

void Camion::affiche_histopopup() {
    if (histolab->isHidden()) {
        histolab->show();


    } else {
        histolab->hide();
    }
}

void Camion::exit_modifpopup() {
    if (modif_lab->isVisible()) {
        modif_lab->hide();
    } else {
        modif_lab->show();
    }
}
void Camion::exit_histapopup() {
    if (histolab->isVisible()) {
        histolab->hide();
    } else {
        histolab->show();
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


    // Associez le mod�le � votre QTableView

    QSqlQueryModel *model = qobject_cast<QSqlQueryModel*>(list->model());

    if (model) {
        QString content;
        //header
        for (int col = 0; col < model->columnCount(); ++col) {

             content += model->headerData(col, Qt::Horizontal).toString() + "\t ";

                }
        content += "\n";
        // Parcourez les donn�es du mod�le et ajoutez-les au contenu
        for (int row = 0; row < model->rowCount(); ++row) {
            for (int col = 0; col < model->columnCount(); ++col) {
                content += model->data(model->index(row, col)).toString() + "\t";
            }
            content += "\n";
        }

        // Cr�ez un objet QTextDocument et d�finissez son contenu
        QTextDocument document;
        document.setPlainText(content);

        // Cr�ez un dialogue pour s�lectionner l'emplacement de sauvegarde du PDF.
        QString fileName = QFileDialog::getSaveFileName(this, "Exporter en PDF", "C:/Users/benam/OneDrive/Documents/ESPRIT 2A40/Projet C++", "Fichiers PDF (*.pdf)");

        if (!fileName.isEmpty()) {
            // Cr�ez un objet QPrinter pour g�n�rer le PDF.
            QPrinter printer;
            printer.setOutputFormat(QPrinter::PdfFormat);
            printer.setOutputFileName(fileName);

            // Imprimez le document sur le PDF.
            document.print(&printer);

            // Affichez un message � l'utilisateur pour confirmer l'exportation r�ussie.
            QMessageBox::information(this, "Export PDF", "Le PDF a �t� cr�� avec succ�s.");
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




void Camion ::ecrireDansFichier(const QString& matricule, const QString& tempsSuppression)
{
    QString nomFichier = "C:/Users/benam/OneDrive/Documents/ESPRIT 2A40/Projet C++/QT/interface22/HISTORIQUE.txt";
    QFile file(nomFichier);

    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream stream(&file);
        stream <<"SUPPRESSION:"<< "matricule : " << matricule << ", Temps de suppression : " << tempsSuppression << "\n";
        file.close();
    } else {
        // Gérer les erreurs d'ouverture de fichier
    }
}
void Camion ::ecrireDansFichier1(const QString& matricule, const QString& tempsAjout)
{
    QString nomFichier = "C:/Users/benam/OneDrive/Documents/ESPRIT 2A40/Projet C++/QT/interface22/HISTORIQUE.txt";
    QFile file(nomFichier);

    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream stream(&file);
        stream <<"AJOUT :"<< "matricule : " << matricule << ", Temps de l'ajout : " << tempsAjout << "\n";
        file.close();
    } else {
        // Gérer les erreurs d'ouverture de fichier
    }
}
void Camion ::ecrireDansFichier2(const QString& matricule, const QString& tempsDeMiseAjour)
{
    QString nomFichier = "C:/Users/benam/OneDrive/Documents/ESPRIT 2A40/Projet C++/QT/interface22/HISTORIQUE.txt";
    QFile file(nomFichier);

    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream stream(&file);
        stream <<"MISE A JOUR  :"<< "matricule : " << matricule << ", Temps de l'ajout : " << tempsDeMiseAjour << "\n";
        file.close();
    } else {
        // Gérer les erreurs d'ouverture de fichier
    }
}
void Camion::afficherHISTO()
{
    QString modelHeader;
    modelHeader = "Historique";
    QFile file("C:/Users/benam/OneDrive/Documents/ESPRIT 2A40/Projet C++/QT/interface22/HISTORIQUE.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream stream(&file);
        QString fileContent = stream.readAll();
        file.close();

        if (fileContent.isEmpty()) {
            QMessageBox::information(this, "Empty", "The file is empty.");
        } else {
            QStringList rows = fileContent.split("\n");
            QStandardItemModel *model = new QStandardItemModel(this);
            model->setColumnCount(1);

            for (const QString &row : rows) {
                QStandardItem *item = new QStandardItem(row);
                model->appendRow(item);
            }

            model->setHeaderData(0, Qt::Horizontal, QObject::tr(modelHeader.toUtf8().constData()));

            historique->setModel(model);
            historique->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
            historique->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
        }
    } else {
        QMessageBox::warning(this, "Error", "Failed to open the file.");
    }
}
/*void MainWindow::onComboBoxhistorique(int index)
{
    QString selectedOption = ui->afficher_historique->itemText(index);
    QString filePath;
QString modelHeader;
    if (selectedOption == "ajout") {
        filePath = "/Users/Msi/OneDrive/Bureau/ajout.txt";
        modelHeader = "AJOUT";
    } else if (selectedOption == "modification") {
        filePath = "/Users/Msi/OneDrive/Bureau/modification.txt";
        modelHeader = "MODIFICATION";
    } else if (selectedOption == "suppression") {
        filePath = "/Users/Msi/OneDrive/Bureau/suppression.txt";
        modelHeader = "SUPPRESSION";
    }

    QFile file(filePath);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream stream(&file);
        QString fileContent = stream.readAll();
        file.close();

        if (fileContent.isEmpty()) {
            QMessageBox::information(this, "Empty", "The file is empty.");
        } else {
            QStringList rows = fileContent.split("\n");
            QStandardItemModel *model = new QStandardItemModel(this);
            model->setColumnCount(1);

            for (const QString &row : rows) {
                QStandardItem *item = new QStandardItem(row);
                model->appendRow(item);
            }

            model->setHeaderData(0, Qt::Horizontal, QObject::tr(modelHeader.toUtf8().constData()));

            ui->tableView_historique->setModel(model);
            ui->tableView_historique->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
            ui->tableView_historique->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
        }
    } else {
        QMessageBox::warning(this, "Error", "Failed to open the file.");
    }
}*/


void Camion::showpdf2()
{



QString strStream;

                         QTextStream out(&strStream);

                         const int rowCount = list->model()->rowCount();

                         const int columnCount = list->model()->columnCount();



                         out <<  "<html>\n"

                             "<head>\n"

                             "<meta Content=\"Text/html; charset=Windows-1251\">\n"

                             <<  QString("<title>%1</title>\n").arg("strTitle")

                             <<  "</head>\n"

                             "<body bgcolor=#ffffff link=#5000A0>\n"



                            //     "<align='right'> " << datefich << "</align>"

                             "<center> <H1>Liste des Camions </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";



                         // headers

                         out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";

                         for (int column = 0; column < columnCount; column++)

                             if (!list->isColumnHidden(column))

                                 out << QString("<th>%1</th>").arg(list->model()->headerData(column, Qt::Horizontal).toString());

                         out << "</tr></thead>\n";



                         // data table

                         for (int row = 0; row < rowCount; row++) {

                             out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";

                             for (int column = 0; column < columnCount; column++) {

                                 if (!list->isColumnHidden(column)) {

                                     QString data = list->model()->data(list->model()->index(row, column)).toString().simplified();

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
void Camion::updatdispo_arduino()
{
    QSqlQuery query;
    Camion  c;
    data=A.read_from_arduino();
    qDebug()<<"data="<<data;
    if(data=="1")
    {
        query.prepare("UPDATE camion SET disponibilite='Disponible' where matricule='C003'");
        query.exec();
        list->setModel(c.afficher());
    }
    else
    {
        query.prepare("UPDATE camion SET disponibilite='Indisponible' where matricule='C003'");
        query.exec();
        list->setModel(c.afficher());
    }
}
