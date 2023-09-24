#include "socket.h"
#include <QTcpSocket>

QString network_(QString IPv4){
    QString networkers{""};
    for (int i{0} , j{0};j!=3;++i){
        if (IPv4[i] == '.'){
            ++j;
        }
        networkers += IPv4[i];
    }

    return networkers;
}

socket::socket(){
    client = new QTcpSocket;
}

socket::~socket(){
    if (client != nullptr){
        delete client;
    }
}

void socket::ReadyRead(){
    std::cout << QString(client->readAll()).toStdString();
    std::string your_word;
    std::getline(std::cin , your_word);
    client->write((user_name + " : " + your_word+'\n').c_str());
}

void socket::onConnected(){
    std::cout << "\nYou are connected!type END to terminate!\n";
    QObject::connect(client , &QTcpSocket::readyRead , this , &socket::ReadyRead);
    std::string your_word;
    std::getline(std::cin , your_word);
    client->write((user_name + " : " + your_word+'\n').c_str());
}

bool socket::start(QString IPv4){

    IPv4 = network_(IPv4);

    QObject::connect(client , &QTcpSocket::connected , this , &socket::onConnected);

    for (int i{0};i<=255;++i){
        client->connectToHost(IPv4 + QString::number(i) , 10100);
        std::cout << "\ntesting : " << (IPv4 + QString::number(i)).toStdString();
        client->waitForConnected(100);
        if (QAbstractSocket::ConnectedState == client->state()){
            return true;
        }
    }

    return false;
}

