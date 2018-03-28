#ifndef CHAT_H
#define CHAT_H

#include <QWidget>

#include <QDebug>

#include <QTextEdit>
#include <QLabel>
#include <QPushButton>
#include <QListWidget>
#include <QListWidgetItem>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTabWidget>
#include <QTime>
#include <QList>
#include <QEvent>
#include <QFont>
#include <QCloseEvent>

class Chat : public QWidget
{
    Q_OBJECT
public:
    explicit Chat(QWidget *parent = 0);
private:
    QString id;

    QLabel *head;
    QLabel *user;
    QLabel *tip;

    QTabWidget *tab_win;

    QPushButton *pb_send;
    QPushButton *pb_clear;

    QTextEdit *echo_msg;
    QTextEdit *edit_msg;

    QListWidget *user_list;

    QHBoxLayout *hbox_1;
    QHBoxLayout *hbox_2;
    QHBoxLayout *hbox_3;

    QVBoxLayout *vbox_1;
    QVBoxLayout *vbox_2;

    QList<QString> item_pos_list;
    QList<QListWidgetItem *> item_list;
protected:
    void closeEvent(QCloseEvent *event)
    {
        emit close_chat(id);
        this->close();
    }
signals:
    void send_msg(QString id,QByteArray msg);
    void close_chat(QString id);
public slots:
    int setHead(QPixmap head_pix);
    int setId(QString chat_id);
    int setTip(QString chat_tip);
    int setName(QString name);
    void sendMsg(void);
    void recvMsg(int type,QString name,QString msg,QPixmap *pix);
    void addUserToList(QString id,QString name,QPixmap head);
    void deleteUserFromList(QString id);
};

#endif // CHAT_H
