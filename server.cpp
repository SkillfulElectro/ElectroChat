#include "server.h"
#include <QtNetwork/QTcpServer>
#include <QtNetwork/QTcpSocket>
#include <iostream>

server::server(QObject *parent)
    : QObject{parent}
{
    host = new QTcpServer(this);
}

void server::onRecive(){
    std::cout << "user : " << QString(bridge->readAll()).toStdString();
    std::string your_word;
    std::getline(std::cin , your_word);
    bridge->write((your_word+'\n').c_str());
}

void server::onConnection(){
    std::cout << "\nUser connected!\n";
    bridge = host->nextPendingConnection();
    QObject::connect(bridge , &QTcpSocket::readyRead , this , &server::onRecive);
}

void server::start(QString IPv4){
    host->listen(QHostAddress(IPv4) , 10100);
    QObject::connect(host , &QTcpServer::newConnection , this , &server::onConnection);

}
