#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include<QLabel>
#include<QPushButton>
#include<QLineEdit>
#include<QPixmap>
#include<QFont>
#include<QComboBox>
#include<QGraphicsDropShadowEffect>
#include<QPropertyAnimation>

#include "connexion.h"
//#include "inter.h"
#include "camion.h"

class Login : public QMainWindow
{
    Q_OBJECT
public:
    Login(QWidget *parent=nullptr);
    ~Login();
    void applyShadow(QWidget *widget);
public slots:
    void showPopUp();
    void showPassWord();
private:
    QWidget *cam;
    QLabel *content;
    QLabel *closeopen[2];
    QLineEdit *info[2];
    QPushButton *confirm;
    QPushButton *see;
};

#endif // LOGIN_H
