#ifndef MAINUI_H
#define MAINUI_H

#include <QWidget>
#include <QDebug>

#include <QTabWidget>
#include <QLabel>
#include <QPushButton>
#include <QListWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QList>

#include "mylistwidgetitem.h"
#include "mylistwidget.h"

class MainUi : public QWidget
{
    Q_OBJECT
public:
    explicit MainUi(QWidget *parent = 0);

signals:
    void select_chat(QString);
public slots:
    void selectChat(QString);

private:
    QLabel *head;
    QLabel *user;
    QLabel *tip;

    QListWidget *opt;
    MyListWidget *msg_list;
    MyListWidget *user_list;

    QTabWidget *tab_win;

    QHBoxLayout *hbox_1;
    QHBoxLayout *hbox_2;
    QHBoxLayout *hbox_3;

    QVBoxLayout *vbox_1;
    QVBoxLayout *vbox_2;
    QVBoxLayout *vbox_3;


};

#endif // MAINUI_H
