#include "mylistwidget.h"

MyListWidget::MyListWidget(QWidget *parent) : QWidget(parent)
{
    sum = 0;
    layout = new QVBoxLayout(this);
    setLayout(layout);
    layout->setContentsMargins(0,0,0,0);
    layout->setSpacing(0);
    layout->addStretch();
}
void MyListWidget::addItem(MyListWidgetItem *item)
{
    sum = layout->count();
    layout->insertWidget(0,item);
    connect(item,SIGNAL(select_user(QString)),this,SLOT(selectUser(QString)));
    return 0;
}

void MyListWidget::addStretch(void)
{
    layout->addStretch();
}

int MyListWidget::getUserSum()
{
    return sum;
}


int MyListWidget::addListItem(QString id,QString name,QPixmap head)
{
    MyListWidgetItem *item;
    item = new MyListWidgetItem();
    item->setHead(head);
    item->setName(name);
    item->setId(id);
    addItem(item);
    w_pos_list.insert(0,id);
    w_list.insert(0,item);
    return 0;
}
int MyListWidget::addListItem(QString id,QString name)
{
    MyListWidgetItem *item;
    item = new MyListWidgetItem();
    item->setName(name);
    item->setId(id);
    addItem(item);
    w_pos_list.insert(0,id);
    w_list.insert(0,item);
    return 0;
}
int MyListWidget::addListItem(QString id,QString name,QPixmap head,QString msg,int msg_num)
{
    MyListWidgetItem *item;
    item = new MyListWidgetItem();
    item->setHead(head);
    item->setName(name);
    item->setMsgNum(msg_num);
    item->setNewMsg(msg);
    item->setId(id);
    addItem(item);
    w_pos_list.insert(0,id);
    w_list.insert(0,item);
    return 0;
}
int MyListWidget::deleteItem(QString id)
{
    int pos = w_pos_list.indexOf(id,0);
    MyListWidgetItem *select;
    select = w_list.at(pos);
    layout->removeWidget(select);
    select->close();
    w_pos_list.removeAt(pos);
    w_list.removeAt(pos);

    if(sum>0)
    {
        sum--;
        return 0;
    }
    else
        return -1;
}
int MyListWidget::setItemMsg(QString id,QString msg)
{
    int pos = w_pos_list.indexOf(id,0);
    MyListWidgetItem *select;
    select = w_list.at(pos);
    select->setNewMsg(msg);
    select = NULL;
    return 0;
}
int MyListWidget::setItemHead(QString id,QPixmap head)
{
    int pos = w_pos_list.indexOf(id,0);
    MyListWidgetItem *select;
    select = w_list.at(pos);
    select->setHead(head);
    select = NULL;
    return 0;
}
int MyListWidget::setItemName(QString id,QString name)
{
    int pos = w_pos_list.indexOf(id,0);
    MyListWidgetItem *select;
    select = w_list.at(pos);
    select->setName(name);
    select = NULL;
    return 0;
}
int MyListWidget::setItemMsgNum(QString id,int msg_num)
{
    int pos = w_pos_list.indexOf(id,0);
    MyListWidgetItem *select;
    select = w_list.at(pos);
    select->setMsgNum(msg_num);
    select = NULL;
    return 0;
}
int MyListWidget::selectUser(QString id)
{
    emit select_user(id);
    return 0;
}
