#ifndef INTER_H
#define INTER_H
#include"login.h"
#include <QMainWindow>
#include <QMainWindow>
#include <QObject>
#include <QWidget>
class QPushButton;
class QLabel;
class QLineEdit;
class Inter : public QMainWindow
{
    Q_OBJECT
public:
    Inter(QMainWindow  *loginlab,QWidget *parent = nullptr);
private:
    QMainWindow *loginlab;
    QPushButton *gest_camions;
    QPushButton *gest_contenaire;
    QPushButton *gest_personelle;/* el patron*/
    QPushButton *gest_dons;
    QPushButton *gest_matrielle;
public slots:
    void leave_sign();
    void change_cont();
    void change_cami();
    void change_perso();
    void change_dons();
    void change_mat();
};

#endif // INTER_H
