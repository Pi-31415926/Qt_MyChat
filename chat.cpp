#include "chat.h"

Chat::Chat(QWidget *parent) : QWidget(parent)
{
    //--------部件
    head = new QLabel;
    user = new QLabel("chat room name");
    tip = new QLabel("hello world!");

    tab_win = new QTabWidget();

    user_list = new QListWidget;

    pb_send = new QPushButton("发送");
    pb_clear = new QPushButton("清空");

    echo_msg = new QTextEdit;
    edit_msg = new QTextEdit;

    hbox_1 = new QHBoxLayout;
    hbox_2 = new QHBoxLayout;
    hbox_3 = new QHBoxLayout;

    vbox_1 = new QVBoxLayout;
    vbox_2 = new QVBoxLayout;

    //部件-------

    //---------部件设置
    head->setPixmap(QPixmap(":/icon/icon/head.png"));
    head->setFixedSize(90,90);
    head->setScaledContents(true);
    head->setFrameShape(QFrame::StyledPanel);

    user->setMaximumHeight(30);
    tip->setMaximumHeight(30);

    tab_win->addTab(user_list,"成员列表");

    echo_msg->setReadOnly(true);

    //部件设置---------

    //-----------布局
    hbox_3->addStretch();
    hbox_3->addWidget(head);
    hbox_3->addStretch();

    vbox_1->addLayout(hbox_3);
    vbox_1->addWidget(user);
    vbox_1->addWidget(tip);
    vbox_1->addWidget(tab_win);
    //vbox_1->addWidget(user_list);

    vbox_2->addWidget(echo_msg);
    vbox_2->addWidget(edit_msg);
    hbox_1->addWidget(pb_send);
    hbox_1->addWidget(pb_clear);
    vbox_2->addLayout(hbox_1);
    hbox_2->addLayout(vbox_1);
    hbox_2->addLayout(vbox_2);

    vbox_1->setStretchFactor(head,3);
    vbox_1->setStretchFactor(user,1);
    vbox_1->setStretchFactor(tip,1);
    //vbox_1->setStretchFactor(tab_win,1);
    vbox_1->setStretchFactor(tab_win,10);

    vbox_2->setStretchFactor(echo_msg,7);
    vbox_2->setStretchFactor(edit_msg,3);
    vbox_2->setStretchFactor(hbox_1,1);

    hbox_2->setStretchFactor(vbox_1,3);
    hbox_2->setStretchFactor(vbox_2,7);
    this->setLayout(hbox_2);
    //布局-----------

    connect(pb_clear,SIGNAL(clicked(bool)),echo_msg,SLOT(clear()));
    connect(pb_send,SIGNAL(clicked(bool)),this,SLOT(sendMsg(void)));
}

void Chat::sendMsg(void)
{
    if(!edit_msg->document()->isEmpty())
    {
        QDateTime current_date_time =QDateTime::currentDateTime();
        QString current_date = current_date_time.toString("yyyy.MM.dd hh:mm:ss ddd");
        QString text = edit_msg->toPlainText();
        QString tip = "ME ：" + current_date;
        edit_msg->clear();
        QString tip_col("red");
        QString strContent = QString("<p><font color=\"%1\">%2</font></p>").arg(tip_col).arg(tip);
        echo_msg->append(strContent);
        echo_msg->append(text);

        emit send_msg(id,text.toLatin1());
        qDebug()<<"send msg to central process module!" << text;
    }
}

void Chat::addUserToList(QString id,QString name,QPixmap head)
{
    QListWidgetItem user;
    user.setIcon(QIcon(head));
    user.setText(name);
    user_list->addItem(&user);
    item_pos_list.append(id);
    item_list.append(&user);
}

void Chat::deleteUserFromList(QString id)
{
    int pos = item_pos_list.indexOf(id,0);
    QListWidgetItem *select;
    select = item_list.at(pos);
    user_list->removeItemWidget(select);
    item_pos_list.removeAt(pos);
    item_list.removeAt(pos);
}

void Chat::recvMsg(QString name,QString msg = "",QPixmap *pix = NULL)
{

    QDateTime current_date_time =QDateTime::currentDateTime();
    QString current_date = current_date_time.toString("yyyy.MM.dd hh:mm:ss ddd");
    QString tip = name + " : " +current_date;
    QString tip_col("blue");
    QString strContent = QString("<p><font color=\"%1\">%2</font></p>").arg(tip_col).arg(tip);
    echo_msg->append(strContent);
    echo_msg->append(msg);
#if 0
    pix->save("temp.gif");
    echo_msg->append("<img src=\"temp.gif\" width=\"320\">");
    }
#endif

}

int Chat::setHead(QPixmap head_pix)
{
    head->setPixmap(head_pix);
    return 0;
}

int Chat::setId(QString chat_id)
{
    id = chat_id;
    return 0;
}

int Chat::setTip(QString chat_tip)
{
    tip->setText(chat_tip);
    tip->setFont(QFont("楷体",10,QFont::Bold));
}

int Chat::setName(QString name)
{
    user->setText(name);
    user->setFont(QFont("隶书",14,QFont::Bold));
}
