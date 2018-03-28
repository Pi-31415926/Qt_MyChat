#ifndef CENTRALPROCESSMODULE_H
#define CENTRALPROCESSMODULE_H

#include <QWidget>
#include <QTcpSocket>

#include "login.h"
#include "mainui.h"
#include "chat.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

    QList<QByteArray> msg_list;
private:
    QString id;
    QTcpSocket socket;
signals:
    void recvMsgToStrProcess(QByteArray);

    void toLR(QList<QByteArray>);
    void toCR(QList<QByteArray>);
    void toCRL(QList<QByteArray>);
    void toUL(QList<QByteArray>);
    void toMU(QList<QByteArray>);
    void toFL(QList<QByteArray>);
    void toPT(QList<QByteArray>);
public slots:
    void openChatWin(QString id);
    void sendMsg(QByteArray msg);
    void readMsg();
    void sendStrProcess(QString id,QByteArray);
    void recvStrProcess(QByteArray);
protected slots:
    void getNowId(QString);
};

#endif // CENTRALPROCESSMODULE_H
