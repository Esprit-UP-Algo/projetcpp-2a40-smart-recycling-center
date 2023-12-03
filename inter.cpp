#include "inter.h"

Inter::Inter( QMainWindow *loginlab,QWidget *parent):QMainWindow(parent),loginlab(loginlab)
{
    this->resize(1280,832);
    QFont customFont("Barlow Condensed", 16);
    this->setFont(customFont);
    QPixmap back(":/image/inter/camions2.png");
    QPixmap logout(":/image/inter/logout.png");

    QPixmap icon(":/image/inter/fleche gauche.png");
    content = new QLabel(this);
    content->setPixmap(back);
    content->setGeometry(0,0,back.width(),back.height());
    box = new QLabel (this);
    box->setStyleSheet("background:#1890a1;border-top-left-radius:20px;border-top-right-radius:20px;color:white;font-size:20px;");
    box->setGeometry(150,30,200,45);
    animation = new QPropertyAnimation(box, "pos");
    animation->setDuration(500);
    animation->setEasingCurve(QEasingCurve::InOutQuad);
    for (int i=0;i<5;i++) {
        gestBtn[i]=new QPushButton(this);
        gestBtn[i]->setStyleSheet("background:transparent;border-top-left-radius:20px;border-top-right-radius:20px;color:#1890a1;font-size:20px;");
        gestBtn[i]->setGeometry(150+(i*200),30,200,45);
    }
    gestBtn[0]->setText("Gest Camions");
    gestBtn[1]->setText("Gest Conteneures");
    gestBtn[2]->setText("Gest Personelle");
    gestBtn[3]->setText("Gest Machines");
    gestBtn[4]->setText("Gest Matrielles");

    leave=new QPushButton(this);
    leave->setStyleSheet("background:#54cdb7;border-radius:20px;color:white;font-size:30px;");
    leave->setIcon(QIcon(logout));
    leave->setGeometry(1220,15,50,50);



    label0 = new QLabel("Gest Camions", this);
    label0->setStyleSheet("background:transparent;border-top-left-radius:20px;border-top-right-radius:20px;color:white;font-size:20px;border:none;");
    label0->setAlignment(Qt::AlignCenter);
      label1 = new QLabel("Gest Conteneures", this);
      label1->setStyleSheet("background:transparent;border-top-left-radius:20px;border-top-right-radius:20px;color:white;font-size:20px;border:none;");
      label1->setAlignment(Qt::AlignCenter);
      label2 = new QLabel("Gest Personelle", this);
      label2->setStyleSheet("background:transparent;border-top-left-radius:20px;border-top-right-radius:20px;color:white;font-size:20px;border:none;");
      label2->setAlignment(Qt::AlignCenter);
      label3 = new QLabel("Gest Machines", this);
      label3->setStyleSheet("background:transparent;border-top-left-radius:20px;border-top-right-radius:20px;color:white;font-size:20px;border:none;");
      label3->setAlignment(Qt::AlignCenter);
      label4 = new QLabel("Gest Matrielles", this);
      label4->setStyleSheet("background:transparent;border-top-left-radius:20px;border-top-right-radius:20px;color:white;font-size:20px;border:none;");
      label4->setAlignment(Qt::AlignCenter);

      label0->setGeometry(150, 30, 200, 45);
      label1->setGeometry(350, 30, 200, 45);
      label2->setGeometry(550, 30, 200, 45);
      label3->setGeometry(750, 30, 200, 45);
      label4->setGeometry(950, 30, 200, 45);

      label0->show();
      label1->hide();
      label2->hide();
      label3->hide();
      label4->hide();

    connect(gestBtn[0],&QPushButton::clicked,this,&Inter::move_camion);
    connect(gestBtn[1],&QPushButton::clicked,this,&Inter::move_conteneures);
    connect(gestBtn[2],&QPushButton::clicked,this,&Inter::move_perso);
    connect(gestBtn[3],&QPushButton::clicked,this,&Inter::move_machines);
    connect(gestBtn[4],&QPushButton::clicked,this,&Inter::move_matrielle);
    connect(leave,&QPushButton::clicked,this,&Inter::leave_sign);
    cam = new Camion(this);
    cam->move(0,102);




}
void Inter::applyShadow(QWidget *widget)
{
    QGraphicsDropShadowEffect* shadow = new QGraphicsDropShadowEffect;
        shadow->setBlurRadius(10);
        shadow->setColor(QColor(0, 0, 0, 150));
        shadow->setOffset(5, 5);
        widget->setGraphicsEffect(shadow);
}
void Inter::leave_sign()
{
    this->hide();
    loginlab->show();
}
void Inter::move_camion()
{
    animation->setEndValue(gestBtn[0]->pos());
    animation->start();
    cam->show();
        label0->hide();
        label1->hide();
        label2->hide();
        label3->hide();
        label4->hide();

        label0->show();

}
void Inter::move_conteneures()
{
    animation->setEndValue(gestBtn[1]->pos());
       animation->start();
       cam->hide();
       label0->hide();
       label1->hide();
       label2->hide();
       label3->hide();
       label4->hide();

       label1->show();

}
void Inter::move_perso()
{

    animation->setEndValue(gestBtn[2]->pos());
       animation->start();
        cam->hide();
        label0->hide();
        label1->hide();
        label2->hide();
        label3->hide();
        label4->hide();

        label2->show();

}
void Inter::move_machines()
{
    animation->setEndValue(gestBtn[3]->pos());
       animation->start();
        cam->hide();
        label0->hide();
        label1->hide();
        label2->hide();
        label3->hide();
        label4->hide();

        label3->show();


}
void Inter::move_matrielle()
{
    animation->setEndValue(gestBtn[4]->pos());
       animation->start();
        cam->hide();
        label0->hide();
        label1->hide();
        label2->hide();
        label3->hide();
        label4->hide();

        label4->show();

}
Inter::~Inter()
{
    delete this;
}
