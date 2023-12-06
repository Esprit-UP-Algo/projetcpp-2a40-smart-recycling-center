#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>
#include "connection.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
      arduino(new QSerialPort(this))
{
    ui->setupUi(this);
    connect(arduino, &QSerialPort::readyRead, this, &MainWindow::serialReceived1);
    //connect(ui->pb_seconnecter,&QPushButton::clicked(),this,&MainWindow::on_pb_seconnecter_clicked());

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonConnect_clicked()
{
    arduino->setPortName("COM4"); // Remplacez "COM3" par le port de votre Arduino
    arduino->setBaudRate(QSerialPort::Baud9600);

    if (arduino->open(QIODevice::ReadWrite)) {
        statusBar()->showMessage("Arduino connected");
    } else {
        statusBar()->showMessage("Failed to connect to Arduino");
    }
}
void MainWindow::write_to_arduino(QByteArray d)
{
    if (arduino->isWritable()) {
        arduino->write(d);  // Envoyer des données vers Arduino
    } else {
        qDebug() << "Couldn't write to serial!";
    }
}

void MainWindow::on_pushButtonReadRFID_clicked()
{
    if (arduino->isOpen()) {
        arduino->write("R"); // Envoyer une commande pour lire la carte RFID
    } else {
        statusBar()->showMessage("Arduino not connected");
    }
}

QString MainWindow::serialReceived1()
{
    QString result;

        serialData += arduino->readAll();

        if (serialData.contains('\n')) {
            QString cardData = QString(serialData).trimmed();

            // Extraction de différentes parties de cardData
            QString nomPart = cardData.left(4);      // Les 4 premiers caractères
            QString loginPart = cardData.mid(4, 2);   // De la position 4 jusqu'à 2 caractères après

            // Utilisation de nomPart et loginPart selon vos besoins
            qDebug() << "Nom: " << nomPart;
            qDebug() << "Login: " << loginPart;

            result = nomPart + loginPart;


            // Nettoyer serialData après avoir utilisé ses données
            serialData.clear();

            // Afficher cardData dans ui->lineEditRFID après avoir extrait les parties
            ui->lineEditRFID->setText(cardData);
            ui->password->setText(cardData);
        }

        return result;

}
void MainWindow::on_pb_seconnecter_clicked()
{

    // menu m(nullptr);
     Connection  c;
     QString l="invalide";
     QString rest = "raed15";
     qDebug() << "Received: " << rest;
     QString nom = rest.mid(0, 4);
     QString loginn = rest.mid(4);
     qDebug() << "Nom_clik: " << nom;
     qDebug() << "Login_clik: " << loginn;


     if(c.Authentification(loginn,nom)==1)
     {

             QString cardData = QString(serialData).trimmed();
          serialData += arduino->readAll();
          serialData.clear();
          ui->nom->setText(nom);
          // ui->password->setText(cardData);



        QMessageBox::information(this,"Connexion","login et mdp correcte");
      qDebug()<< "Mot de passe et login correct";
      this->hide();


      // Allumer la LED (supposons que "1" est le message pour allumer la LED)
      write_to_arduino("1");


 }
     if(c.Authentification(loginn,nom)==0)
     {
         ui->nom->setText(l);
         ui->password->setText(l);
       QMessageBox::critical(this,"Connexion","login et mdp incorrecte");
       qDebug()<< "Mot de passe et login incorrect";
     }
}


