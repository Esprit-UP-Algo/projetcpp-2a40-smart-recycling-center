#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include"inter.h"
class QLabel;
class QPushButton;
class QLineEdit;
class QPixmap;
class PopupWindow;
class Login : public QMainWindow
{
    Q_OBJECT
public:
    Login(QWidget *parent = nullptr);
    void applyShadow(QWidget *widget);
public slots:
    void showPopup();
    void type_password();
private:
    //Inter *inWindow;
    QLabel *openlab;
    QLabel *closelab;
    QLabel *login;
    QLineEdit *userEdit;
    QLineEdit *passEdit;
    QPushButton *confirmbtn;
};

#endif // LOGIN_H
