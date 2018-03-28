#ifndef MYLISTWIDGETITEM_H
#define MYLISTWIDGETITEM_H

#include <QWidget>
#include <QListWidgetItem>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPixmap>
#include <QLabel>
#include <QLineEdit>
#include <QEvent>
#include <QMouseEvent>
#include <QDebug>



class MyListWidgetItem : public QWidget
{
    Q_OBJECT
public:
    explicit MyListWidgetItem(QWidget *parent = 0);

    QString id;
    QString name;
    QPixmap head;
    int msgnum;
    QString msg;
    QLabel *lb_head;
    QLabel *lb_name;
    QLabel *lb_msg;
    QLabel *lb_num;
    QVBoxLayout *vbox;
    QHBoxLayout *mainlayout;
signals:
    void select_user(QString);
public slots:
    int setHead(QPixmap);
    int setId(QString);
    int setMsgNum(int);
    int setName(QString);
    int setNewMsg(QString);

protected:
    void mousePressEvent(QMouseEvent *event);
};

#endif // MYLISTWIDGETITEM_H
