#include <SFML/Network.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "../../include/player.hpp"
#include "../../include/entity.hpp"
#include "../../include/anim.hpp"
#include "../../include/gamestatus.hpp"
#include "../../include/Menu.hpp"
#include "../../include/view.hpp"
#include "../../lib/level/TmxLevel.h"
#include "../../lib/tinyxml2/tinyxml2.h"

class Client
{
public:
    Client(sf::IpAddress address, unsigned short port) : address(address), port(port) {}

    sf::IpAddress address;
    unsigned short port;
};

int main()
{

    sf::Clock clock;
    sf::Texture t;
    t.loadFromFile("../heroes/Brodell Walker.png");

    AnimationManager anim;
    anim.loadFromFile("../heroes/Brodell Walker.xml", t);

    TmxLevel lvl;
    lvl.LoadFromFile("../maps/map.tmx");
    std::vector<TmxObject> obj;
    obj = lvl.GetAllObjects("solid");
    Player Player1(anim);
    Player Player2(anim);
    sf::Clock gclock;

    // Создаем UDP сокет на сервере
    sf::UdpSocket serverSocket;
    unsigned short serverPort = 55001;
    serverSocket.bind(serverPort);

    // Создаем список клиентов
    std::vector<Client> clients;

    while (true)
    {
        // Получаем сообщение от клиента 1
        char buffer1[1024];
        std::size_t received1;
        sf::IpAddress clientAddress1;
        unsigned short clientPort1;
        serverSocket.receive(buffer1, sizeof(buffer1), received1, clientAddress1, clientPort1);

        // Определяем код клавиши
        if (buffer1[0] == 'D')
        {
            Player1.key["R"] = true;
        }
        else if (buffer1[0] == 'A')
        {
            Player1.key["L"] = true;
        }
        else if (buffer1[0] == 'W')
        {
            Player1.key["Up"] = true;
        }
        else if (buffer1[0] == 'S')
        {
            Player1.key["Down"] = true;
        }
        else if (buffer1[0] == 'G')
        {
            Player1.key["G"] = true;
        }
        else if (buffer1[0] == 'F')
        {
            Player1.key["F"] = true;
        }


        // получение сообщения от клиента 2
        char buffer2[1024];
        std::size_t received2;
        sf::IpAddress clientAddress2;
        unsigned short clientPort2;
        serverSocket.receive(buffer2, sizeof(buffer2), received2, clientAddress2, clientPort2);
        // Определяем код клавиши
        if (buffer2[0] == 'D')
        {
            Player2.key["R"] = true;
        }
        else if (buffer2[0] == 'A')
        {
            Player2.key["L"] = true;
        }
        else if (buffer2[0] == 'W')
        {
            Player2.key["Up"] = true;
        }
        else if (buffer2[0] == 'S')
        {
            Player2.key["Down"] = true;
        }
        else if (buffer2[0] == 'G')
        {
            Player2.key["G"] = true;
        }
        else if (buffer2[0] == 'F')
        {
            Player2.key["F"] = true;
        }

        float time = clock.getElapsedTime().asMicroseconds();
        time = time / 500;
        clock.restart();
        if (gclock.getElapsedTime().asSeconds()<10){
            Player1.x= 550;
            Player1.y = 840;
            Player2.x= 550;
            Player2.y = 840;
        }
        Player1.update(time, obj);
        std::cout<<Player1.x<< ' '<< Player1.y<<" "<<gclock.getElapsedTime().asSeconds()<<' '<< Player1.STATE <<std::endl;

        Player2.update(time, obj);
        std::cout<<Player2.x<< ' '<< Player2.y<<" "<<gclock.getElapsedTime().asSeconds()<<' '<< Player2.STATE <<std::endl;

        // Отправляем обновленный Player1 клиенту
        sf::Packet packet;
        packet << Player1<<Player2;
        serverSocket.send(packet.getData(), packet.getDataSize(), clientAddress1, clientPort1);
        serverSocket.send(packet.getData(), packet.getDataSize(), clientAddress2, clientPort2);

        // Добавляем клиента в список, если его там нет
        auto client = clients.end();
        for (auto it = clients.begin(); it != clients.end(); ++it)
        {
            if ((it->address == clientAddress1 && it->port == clientPort1) || (it->address == clientAddress2 && it->port == clientPort2))
            {
                client = it;
                break;
            }
        }

        if (client == clients.end())
        {
            clients.emplace_back(clientAddress1, clientPort1);
        }
    }

    return 0;
}
