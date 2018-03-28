#include "mylistwidgetitem.h"

MyListWidgetItem::MyListWidgetItem(QWidget *parent) : QWidget(parent)
{
    //---------控件
    lb_head = new QLabel;
    lb_name = new QLabel("user");
    lb_msg = new QLabel("msg");
    lb_num = new QLabel("0");
    vbox = new QVBoxLayout;
    mainlayout = new QHBoxLayout;
    //控件---------

    //------控件设置
    head.load(":/icon/icon/head.png");
    lb_head->setPixmap(head);
    lb_head->setScaledContents(true);
    lb_head->setFixedSize(60,60);
    //控件设置------

    //--------布局
    vbox->addWidget(lb_name);
    vbox->addWidget(lb_msg);
    mainlayout->addWidget(lb_head);
    mainlayout->setStretchFactor(lb_head,2);
    mainlayout->addLayout(vbox);
    mainlayout->setStretchFactor(vbox,7);
    mainlayout->addWidget(lb_num);
    mainlayout->setStretchFactor(lb_num,1);
    this->setLayout(mainlayout);
    //布局--------

    this->setFixedHeight(65);
}
void MyListWidgetItem::mousePressEvent(QMouseEvent *event)
{
    qDebug()<<"user:"<<id;
    emit select_user(id);
}

int MyListWidgetItem::setHead(QPixmap head_pix)
{
    lb_head->setPixmap(head_pix);
    return 0;
}

int MyListWidgetItem::setId(QString weigit_id)
{
    id = weigit_id;
    return 0;
}

int MyListWidgetItem::setMsgNum(int msg_num)
{
    msgnum = msg_num;
    return 0;
}

int MyListWidgetItem::setName(QString username)
{
    lb_name->setText(username);
    return 0;
}

int MyListWidgetItem::setNewMsg(QString new_msg)
{
    lb_msg->setText(new_msg);
    return 0;
}
