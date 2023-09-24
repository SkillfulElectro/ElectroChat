#ifndef SOCKET_H
#define SOCKET_H
#include <QtNetwork/QTcpSocket>
#include <iostream>
#include <QObject>

class socket : public QObject
{
    Q_OBJECT
    QTcpSocket* client;

public:
    std::string user_name;
    socket();
    ~socket();
    bool start(QString);
public slots:
    void ReadyRead();
    void onConnected();
};

#endif // SOCKET_H
