#include "CentralProcessModule.h"

#define SERVER_ADDR ("192.168.1.1")
#define SERVER_PORT (3141)

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    //this->hide();
    Login *login = new Login;
    login->show();
    MainUi *mainui = new MainUi;
    mainui->show();

    socket.connectToHost(SERVER_ADDR,SERVER_PORT);

    connect(&socket,SIGNAL(readyRead()),this,SLOT(readMsg()));
    connect(login,SIGNAL(regist_check(QString)),this,SLOT(sendMsg(QString,QByteArray)));
    connect(login,SIGNAL(login_check(QString)),this,SLOT(sendMsg(QString,QByteArray)));
    connect(login,SIGNAL(loginId(QString)),this,SLOT(getNowId(QString)));

    connect(this,SIGNAL(toCR(QList<QByteArray>)),mainui,SLOT()
}

Widget::~Widget()
{

}

void Widget::openChatWin(QString id)
{
    Chat *chat;
    chat = new Chat();
    chat->setId(id);
    chat->setName();

    connect(this,SIGNAL(toCR(QList<QByteArray>)),chat,SLOT());
    connect(chat,SIGNAL(send_msg(QString,QByteArray)),this,SLOT(sendStrProcess(QString,QByteArray));
}

void Widget::readMsg()
{
    QByteArray msg;
    msg = socket.readAll();
    if(msg.count() > 0)
    {
        emit recvMsgToStrProcess(msg);
    }
    return;
}

void Widget::sendMsg(QByteArray msg)
{
    socket.write(msg.toLatin1());
    return;
}

void Widget::sendStrProcess(QString id,QByteArray msg)
{
   sendMsg(id.toLatin1()+msg);
   return;
}

void Widget::recvStrProcess(QByteArray msg)
{
    msg_list.clear();
    msg_list = msg.split(QRegExp("[:;]")); //把每一个块装进一个QList<QByteArray>中
    if(!msg_list.isEmpty())
    {
        int num = msg_list.length();
        if(num > 1)
        {
            QByteArray msg_type = msg_list.at(0);
            switch (msg_type.toStdString().c_str()) {
            case "login":
            case "regist":
                emit toLR(msg_list);
                break;
            case "msg":
                emit toCR(msg_list);
                break;
            case "addCR":
                emit toCRL(msg_list);
                break;
            case "addUser":
                emit toUL(msg_list);
                break;
            case "chatroom":
                emit toCRL(msg_list);
                break;
            case "user":
                emit toUL(msg_list);
                break;
            case "change":
                emit toMU(msg_list);
                break;
            case "file":
                emit toFL(msg_list);
                break;
            case "picture":
                emit toPT(msg_list);
                break;
            default:
                break;
            }
        }
    }

}


void Widget::getNowId(QString now_id)
{
    id = now_id;
}
