#include "login.h"
#include"inter.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsWidget>
#include <QGraphicsRotation>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>
#include <QSequentialAnimationGroup>
#include <QObject>
#include <QWidget>
#include <QHBoxLayout>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QApplication>
#include <QPixmap>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGraphicsDropShadowEffect>
#include <QList>
#include <QDebug>
Login::Login(QWidget *parent)
    :QMainWindow(parent)
{

    QPixmap image(":/login (1).png");
    QLabel *imageLabel=new QLabel(this);
    imageLabel->setPixmap(image);
    imageLabel->setGeometry(0,0,image.width(),image.height());
    this->resize(image.width(),image.height());

    QPixmap open(":/open.png");
    openlab = new QLabel(this);
    openlab->setPixmap(open);
    openlab->setGeometry(532 ,203 ,open.width(),open.height());

    QPixmap close(":/CLOSE.png");
    closelab = new QLabel(this);
    closelab->setPixmap(close);
    closelab->setGeometry(532 ,203 ,close.width(),close.height());

   /* QLabel *text = new QLabel("LOGIN",this);
    text->setStyleSheet("QLabel { color:#FFAE17;opacity:0.5; font-size: 60px; top:100px;padding-top:50px;font-family:Arial;}");
    text->setGeometry(241,250,214,100);

    QFrame *box = new QFrame(this);
    box->setStyleSheet("background:rgba(144, 238, 144,0.3);border-radius:20px; ");
    box->setGeometry(640,416,900,900);*/

    userEdit = new QLineEdit(this);
    userEdit->setStyleSheet("background:white;border-radius:30px;font-size:20px;border:3px solid gray; padding:15px;");
    userEdit->setPlaceholderText("Email");
    userEdit->setGeometry(84, 408, 420, 64);
    applyShadow(userEdit);


    passEdit = new QLineEdit(this);
    passEdit->setStyleSheet("background:white;border-radius:30px;font-size:20px;border:3px solid gray; padding:15px;");
    passEdit->setEchoMode(QLineEdit::Password);
    passEdit->setPlaceholderText("Password");
    passEdit->setGeometry(84, 506, 420, 64);
    applyShadow(passEdit);

    QPixmap oeil(":/oeil (1).png");
    QPushButton *bow=new QPushButton(this);
    bow->setStyleSheet("background:transparent; font-size:20px;");
    bow->setIcon(QIcon(oeil));
    bow->setGeometry(450,513,50,50);


    confirmbtn = new QPushButton("Login",this);
    confirmbtn->setStyleSheet("background:#FFAE17;border:3px solid gray;border-radius:10px;font-size:40px;color:white;cursor:pointer;border-radius:30px;");
    confirmbtn->setGeometry(182,635,223,78);
    confirmbtn->setCursor(Qt::PointingHandCursor);
    applyShadow(confirmbtn);


    /*QPropertyAnimation *animation = new QPropertyAnimation(box, "geometry");
       animation->setDuration(2000);
       animation->setStartValue(QRect(-box->width(), 416, box->width(), box->height()));
       animation->setEndValue(QRect(width(), 416, box->width(), box->height()));
       animation->setEasingCurve(QEasingCurve::Linear);
       animation->setLoopCount(-1);


    QPropertyAnimation *animation2 = new QPropertyAnimation(box, "geometry");
       animation2->setDuration(2000);
       animation2->setStartValue(QRect(width()/2-450, -box->height(), box->width(), box->height()));
       animation2->setEndValue(QRect(width()/2-450, height(), box->width(), box->height()));
       animation2->setEasingCurve(QEasingCurve::Linear);
       animation2->setLoopCount(-1);

      animation->start();
       animation2->start();

    QSequentialAnimationGroup  *animationGroup = new QSequentialAnimationGroup (this);
       animationGroup->addAnimation(animation2);
       animationGroup->addAnimation(animation);
       animationGroup->setLoopCount(-1);
       animationGroup->start();*/

       connect(confirmbtn, &QPushButton::clicked, this, &Login::showPopup);
       connect(bow, &QPushButton::clicked, this, &Login::type_password);

}
void Login::applyShadow(QWidget *widget)
{
    QGraphicsDropShadowEffect* shadow = new QGraphicsDropShadowEffect;
        shadow->setBlurRadius(10);
        shadow->setColor(QColor(0, 0, 0, 150));
        shadow->setOffset(5, 5);
        widget->setGraphicsEffect(shadow);
}
void Login::showPopup()
{
    Inter *inWindow = new Inter(this);
    this->hide();
    inWindow->show();

}
void Login::type_password()
{
    if (passEdit->echoMode() == QLineEdit::Password)
    {
        closelab->hide();
        passEdit->setEchoMode(QLineEdit::Normal);
    }
    else
        {
        closelab->show();
        passEdit->setEchoMode(QLineEdit::Password);
        }
}
