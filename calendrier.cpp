#include "calendrier.h"

Calendrier::Calendrier(QWidget *parent) : QWidget(parent)
{


    this->resize(613, 270);
    QPixmap check(":/image/inter/check.png");
    QPixmap edit(":/image/inter/modification.png");
    // Create QLabel widgets for days
    for (int i = 1; i < 8; i++) {
        days[i] = new QLabel(this);
        days[i]->setStyleSheet("background:#FFAE17;border:1px solid lightgreen;font-size:20px;color:white;");
        days[i]->setGeometry((65 * i), 5, 88, 40);
    }
    days[1]->setText("Lundi");
    days[2]->setText("Mardi");
    days[3]->setText("Mercredi");
    days[4]->setText("Jeudi");
    days[5]->setText("Vendredi");
    days[6]->setText("Samedi");
    days[7]->setText("Dimanche");

    // Create QLabel widgets for times
    for (int i = 1; i < 6; i++) {
        times[i] = new QLabel(this);
        times[i]->setStyleSheet("background:transparent;border:none;font-size:20px;color:black;");
        times[i]->setGeometry(10, (i * 40), 55, 45);
    }
    times[1]->setText("17:30");
    times[2]->setText("19:00");
    times[3]->setText("20:30");
    times[4]->setText("22:00");
    times[5]->setText("23:30");

    // Create QLineEdit widgets for each day and time combination
    for (int i = 1; i < 8; i++) {
        for (int j = 1; j < 6; j++) {
            lineEdits.append(new QLineEdit(this));
            lineEdits.last()->setStyleSheet("background:#54cdb7;border:1px solid lightgreen;font-size:16px;color:black;");
            lineEdits.last()->setGeometry((65 * i), (j * 40), 88, 45);
        }
    }

    save=new QPushButton(this);
    save->setStyleSheet("background:#FFAE17;border-radius:20px;color:white;font-size:30px;");
    save->setGeometry(560,80,40,40);
    save->setIcon(QIcon(check));


    modif=new QPushButton(this);
    modif->setStyleSheet("background:#FFAE17;border-radius:20px;color:white;font-size:30px;");
    modif->setGeometry(560,150,40,40);
    modif->setIcon(QIcon(edit));

    connect(modif, &QPushButton::clicked, this, &Calendrier::toggleEdit);
    connect(save, &QPushButton::clicked, this, &Calendrier::saveData);

    loadData();
}

void Calendrier:: saveData() {
    QFile file("C:/Users/benam/OneDrive/Documents/ESPRIT 2A40/Projet C++/QT/interface22/DATA.txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        for (QLineEdit *lineEdit : lineEdits) {
            out << lineEdit->text() << "\n";
        }
        file.close();
        setReadOnly(true);
        QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("Saved successfuly.\n""Click cancel to exit."),QMessageBox::Cancel);
    } else {
        QMessageBox::warning(this, "Error", "Could not open file for writing");
    }
}

void Calendrier::loadData() {
    QFile file("C:/Users/benam/OneDrive/Documents/ESPRIT 2A40/Projet C++/QT/interface22/DATA.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        for (QLineEdit *lineEdit : lineEdits) {
            QString line = in.readLine();
            lineEdit->setText(line);
        }
        file.close();
    } else {
        QMessageBox::warning(this, "Error", "Could not open file for reading");
    }
}
void Calendrier::setReadOnly(bool readOnly) {
    for (QLineEdit *lineEdit : lineEdits) {
        lineEdit->setReadOnly(readOnly);
    }
}

void Calendrier::toggleEdit() {
    setReadOnly(!lineEdits[0]->isReadOnly());
}
