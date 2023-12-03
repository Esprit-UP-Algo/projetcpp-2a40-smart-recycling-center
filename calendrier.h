#ifndef CALENDRIER_H
#define CALENDRIER_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QFile>
#include <QTextStream>
#include <QVector>
#include <QLineEdit>
#include <QPushButton>
#include<QLabel>
#include <QMessageBox>

class Calendrier :public QWidget
{
    Q_OBJECT
public:
    Calendrier(QWidget *parent=nullptr);
public slots:
    void saveData();
    void loadData();
    void setReadOnly(bool readOnly);
    void toggleEdit();
private:
    QLabel *days[10];
    QLabel *times[10];
    QVector<QLineEdit *> lineEdits;
    QPushButton *save;
    QPushButton *modif;
};

#endif // CALENDRIER_H
