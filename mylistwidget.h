#ifndef MYLISTWIDGET_H
#define MYLISTWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QList>

#include "mylistwidgetitem.h"

class MyListWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MyListWidget(QWidget *parent = 0);

    int row;
    int id;
    int sum;

private:
        QVBoxLayout *layout;
        QList<QString> w_pos_list;
        QList<MyListWidgetItem *> w_list;

        void addItem(MyListWidgetItem *item);
        void addStretch(void);
signals:
    void select_user(QString);
public slots:
    int getUserSum();
    int addListItem(QString id,QString name,QPixmap head);
    int addListItem(QString id,QString name);
    int addListItem(QString id,QString name,QPixmap head,QString msg,int msg_num);

    int setItemMsg(QString id,QString msg);
    int setItemHead(QString id,QPixmap head);
    int setItemName(QString id,QString name);
    int setItemMsgNum(QString id,int msg_num);
    int deleteItem(QString id);

    int selectUser(QString id);
};

#endif // MYLISTWIDGET_H
