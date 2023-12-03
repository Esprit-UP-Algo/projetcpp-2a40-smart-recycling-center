#include "login.h"
#include "inter.h"

Login::Login(QWidget *parent):QMainWindow(parent)
{
    this->resize(1280,832);
    QFont customFont("Barlow Condensed", 20);
    this->setFont(customFont);

    QPixmap back(":/image/login/login (1).png");
    QPixmap close(":/image/login/CLOSE.png");
    QPixmap open(":/image/login/open.png");
    QPixmap oeil(":/image/login/oeil (1).png");
    content = new QLabel(this);
    content->setPixmap(back);
    content->setGeometry(0,0,back.width(),back.height());
    for (int i=0;i<2;i++) {
        closeopen[i]=new QLabel(this);
        closeopen[i]->setGeometry(532 ,203 ,close.width(),close.height());
    }
    closeopen[0]->setPixmap(open);
    closeopen[1]->setPixmap(close);
    for (int i=0;i<2;i++) {
        info[i]=new QLineEdit(this);
        info[i]->setStyleSheet("background:white;border-radius:20px;font-size:20px;border:1px solid lightgreen; padding:20px;");
        info[i]->setGeometry(84, 408+(i*98), 420, 64);
        applyShadow(info[i]);
    }
    info[0]->setPlaceholderText("Username");
    info[1]->setPlaceholderText("Password");
    info[1]->setEchoMode(QLineEdit::Password);
    confirm=new QPushButton("se connecter",this);
    confirm->setStyleSheet("background:#FFAE17;border:1px solid lightgreen;border-radius:10px;font-size:40px;color:white;cursor:pointer;border-radius:30px;");
    confirm->setGeometry(182,635,223,78);
    applyShadow(confirm);
    see=new QPushButton(this);
    see->setStyleSheet("background:transparent; font-size:20px;");
    see->setIcon(QIcon(oeil));
    see->setGeometry(450,513,50,50);
    connect(confirm,&QPushButton::clicked,this,&Login::showPopUp);
    connect(see,&QPushButton::clicked,this,&Login::showPassWord);

}
void Login::applyShadow(QWidget *widget)
{
    QGraphicsDropShadowEffect* shadow = new QGraphicsDropShadowEffect;
        shadow->setBlurRadius(10);
        shadow->setColor(QColor(0, 0, 0, 150));
        shadow->setOffset(5, 5);
        widget->setGraphicsEffect(shadow);
}
void Login::showPopUp()
{
    if(info[0]->text().isEmpty() && info[1]->text().isEmpty())
    {
        QMessageBox::warning(this, "Error", "Please fill the Password or Username");
    }
    else if(info[0]->text()=="admin" && info[1]->text()=="1234")
    {
        Inter *interWindow = new Inter(this);
        this->hide();
        interWindow->show();
    }
    else
    {
         QMessageBox::warning(this, "Error", "Wrong Password or Username");
    }
}
void Login::showPassWord()
{
    if(info[1]->echoMode() == QLineEdit::Password)
    {
        closeopen[1]->hide();
        info[1]->setEchoMode(QLineEdit::Normal);
    }
    else
    {
        closeopen[1]->show();
        info[1]->setEchoMode(QLineEdit::Password);
    }
}
Login::~Login()
{
    delete this;
}
