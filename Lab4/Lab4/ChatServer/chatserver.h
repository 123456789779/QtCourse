#ifndef CHATSERVER_H
#define CHATSERVER_H

#include <QTcpServer>
#include <QObject>

class ChatServer : public QTcpServer
{
    Q_OBJECT
public:
    ChatServer();
};

#endif // CHATSERVER_H
