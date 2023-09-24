#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QtNetwork/QTcpServer>
#include <QtNetwork/QTcpSocket>

class server : public QObject
{
    Q_OBJECT
    QTcpSocket* bridge;
    QTcpServer* host;
public:
    explicit server(QObject *parent = nullptr);
    void start(QString);
public slots:
    void onConnection();
    void onRecive();
};

#endif // SERVER_H
