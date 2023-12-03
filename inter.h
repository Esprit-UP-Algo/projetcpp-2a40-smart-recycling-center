#ifndef INTER_H
#define INTER_H
#include"camion.h"
#include"login.h"
#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include<QFrame>
#include<QLabel>
#include<QPushButton>
#include<QLineEdit>
#include<QPixmap>
#include<QFont>
#include<QComboBox>
#include<QGraphicsDropShadowEffect>
#include<QPropertyAnimation>
#include <QStylePainter>
#include <QStyleOptionComboBox>
class Inter : public QMainWindow
{
    Q_OBJECT
public:
    Inter(QMainWindow *loginlab,QWidget *parent=nullptr);
    ~Inter();
    void leave_sign();
    void applyShadow(QWidget* widget);
public slots:
    void move_camion();
    void move_conteneures();
    void move_perso();
    void move_machines();
    void move_matrielle();
private:
    int i=0;
  QWidget *cam;
    QMainWindow *loginlab;
    QPropertyAnimation *animation;

    QLabel *content;
    QLabel *box;

    QPushButton *gestBtn[5];
    QPushButton *leave;
    QLabel *label0 ;
     QLabel *label1;
     QLabel *label2;
     QLabel *label3;
     QLabel *label4;

};

#endif // INTER_H
