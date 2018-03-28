#include "login.h"

Login::Login(QWidget *parent) : QWidget(parent)
{
    //---------控件
    logo = new QLabel;
    title = new QLabel;
    tip = new QLabel;
    return_code = new QLabel;
    lb_user = new QLabel;
    lb_passwd = new QLabel;

    user = new QLineEdit;
    passwd = new QLineEdit;

    login = new QPushButton("login");
    regist = new QPushButton("regis");

    //userbox = new QCheckBox("记住用户");
    passwdbox = new QCheckBox("记住密码");

    vbox_1 = new QVBoxLayout;
    vbox_2 = new QVBoxLayout;


    hbox_1 = new QHBoxLayout;
    hbox_2 = new QHBoxLayout;
    hbox_3 = new QHBoxLayout;
    hbox_4 = new QHBoxLayout;
    hbox_5 = new QHBoxLayout;
    //控件-------

    //-------部件设置
    logo->setPixmap(QPixmap(":/icon/icon/logo.png"));
    //logo->setFixedSize(90,90);
    logo->setMaximumSize(120,120);
    logo->setScaledContents(true);

    title->setText("Pi CR");

    tip->setText("this is tip!");

    lb_user->setText("user  :");

    lb_passwd->setText("passwd:");

    passwd->setEchoMode(QLineEdit::Password);
    //部件设置-------

    //-------布局
    vbox_1->addWidget(title);
    vbox_1->addWidget(tip);

    hbox_1->addWidget(logo);
    hbox_1->addLayout(vbox_1);

    hbox_2->addWidget(lb_user);
    hbox_2->addWidget(user);

    hbox_3->addWidget(lb_passwd);
    hbox_3->addWidget(passwd);

    //hbox_4->addWidget(userbox);
    hbox_4->addWidget(passwdbox);

    hbox_5->addWidget(regist);
    hbox_5->addWidget(login);

    vbox_2->addLayout(hbox_1);
    vbox_2->addLayout(hbox_2);
    vbox_2->addLayout(hbox_3);
    vbox_2->addWidget(return_code);
    vbox_2->addLayout(hbox_4);
    vbox_2->addLayout(hbox_5);

    hbox_1->setStretchFactor(logo,1);
    hbox_1->setStretchFactor(vbox_1,2);

    hbox_2->setStretchFactor(lb_user,1);
    hbox_2->setStretchFactor(user,3);

    hbox_3->setStretchFactor(lb_passwd,1);
    hbox_3->setStretchFactor(passwd,3);

    vbox_2->setStretchFactor(hbox_1,3);
    vbox_2->setStretchFactor(hbox_2,2);
    vbox_2->setStretchFactor(hbox_3,2);
    vbox_2->setStretchFactor(return_code,1);
    vbox_2->setStretchFactor(hbox_4,1);
    vbox_2->setStretchFactor(hbox_5,1);

    this->setLayout(vbox_2);
    //布局-------

    connect(login,SIGNAL(clicked(bool)),this,SLOT(login_clicked(bool)));
    connect(regist,SIGNAL(clicked(bool)),this,SLOT(regist_clicked(bool)));
}

void Login::login_clicked(bool)
{
    QString key;
    key = user->text() + ";" + passwd->text();
    qDebug()<<key;
    emit login_check(key);
    return;
}

void Login::regist_clicked(bool)
{
    QString key;
    key = user->text() + ";" + passwd->text();
    qDebug()<<key;
    emit regist_check(key);
    return;
}

void Login::login_success(void)
{
    tip->setText("登录成功");
    emit loginId(user->text());
    this->close();
}
