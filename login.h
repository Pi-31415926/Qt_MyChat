#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QDebug>

#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QCheckBox>
#include <QHBoxLayout>
#include <QVBoxLayout>

class Login : public QWidget
{
    Q_OBJECT
public:
    explicit Login(QWidget *parent = 0);

signals:
    void login_check(QString);
    void regist_check(QString);
    void loginId(QString);
public slots:
    void login_success(void);
private slots:
    void login_clicked(bool);
    void regist_clicked(bool);

private:
    QLabel *logo;
    QLabel *title;
    QLabel *tip;
    QLabel *return_code;
    QLabel *lb_user;
    QLabel *lb_passwd;

    QLineEdit *user;
    QLineEdit *passwd;

    QPushButton *login;
    QPushButton *regist;

    //QCheckBox *userbox;
    QCheckBox *passwdbox;

    QHBoxLayout *hbox_1;
    QHBoxLayout *hbox_2;
    QHBoxLayout *hbox_3;
    QHBoxLayout *hbox_4;
    QHBoxLayout *hbox_5;

    QVBoxLayout *vbox_1;
    QVBoxLayout *vbox_2;

};

#endif // LOGIN_H
