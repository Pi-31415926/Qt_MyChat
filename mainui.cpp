#include "mainui.h"

MainUi::MainUi(QWidget *parent) : QWidget(parent)
{
    //--------部件
    head = new QLabel;
    user = new QLabel("user name");
    tip = new QLabel("hello world!");

    opt = new QListWidget;
    msg_list = new MyListWidget;
    user_list = new MyListWidget;

    tab_win = new QTabWidget;

    hbox_1 = new QHBoxLayout;
    hbox_2 = new QHBoxLayout;
    hbox_3 = new QHBoxLayout;

    vbox_1 = new QVBoxLayout;
    vbox_2 = new QVBoxLayout;
    vbox_3 = new QVBoxLayout;
    //部件-------

    //---------部件设置
    head->setPixmap(QPixmap(":/icon/icon/head.png"));
    head->setFixedSize(90,90);
    head->setScaledContents(true);

    //部件设置---------

    //-----------布局
    vbox_1->addWidget(user);
    vbox_1->addWidget(tip);
    hbox_1->addWidget(head);
    hbox_1->addLayout(vbox_1);
    hbox_2->addWidget(opt);
    tab_win->addTab(msg_list,"消息");
    tab_win->addTab(user_list,"群聊");
    hbox_2->addWidget(tab_win);
    hbox_2->setStretchFactor(opt,1);
    hbox_2->setStretchFactor(tab_win,3);
    vbox_2->addLayout(hbox_1);
    vbox_2->addLayout(hbox_2);

    this->setLayout(vbox_2);
    //布局-----------
    connect(msg_list,SIGNAL(select_user(QString)),this,SLOT(selectChat(QString)));
}

void MainUi::selectChat(QString)
{
    emit select_chat(QString);
}
