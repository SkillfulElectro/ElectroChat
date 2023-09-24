#include <QCoreApplication>

#include "socket.h"
#include "server.h"

#include <QtNetwork/QUdpSocket>




int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    QUdpSocket socket;
    socket.connectToHost("8.8.8.8", 80); // google DNS, or something else reliable for getting local IPv4
    auto IPv4 = socket.localAddress().toString();
    socket.close();
    server Host;

    std::cout << "starting to check for users";
    class socket client;

    std::string user_name;
    std::cout << "\ninsert your username:\n";
    std::cin >> user_name;

    client.user_name = user_name;
    Host.user_name = user_name;

    if (!client.start(IPv4)){
        std::cout << "\nThere was no one :( , wait for users to join you";
        Host.start(IPv4);
    }

    return a.exec();
}
