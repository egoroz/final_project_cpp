#include <SFML/Network.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>
#include "../../include/player.hpp"
#include "../../include/anim.hpp"
#include "../../lib/level/TmxLevel.h"

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
    // anim.create("walk", t, 10, 15, 32, 32, 4, 0.005, 32);
    // anim.create("stay", t, 10, 20 + 32*8, 32, 32, 28, 0.005, 32);


    TmxLevel lvl;
    lvl.LoadFromFile("../maps/map.tmx");
    std::vector<TmxObject> obj;
    obj = lvl.GetAllObjects("solid");
    Player hero(anim);


    // Создаем UDP сокет на сервере
    sf::UdpSocket serverSocket;
    unsigned short serverPort = 55001;
    serverSocket.bind(serverPort);

    // Создаем список клиентов
    std::vector<Client> clients;

    while (true)
    {
        // Получаем сообщение от клиента
        char buffer[1024];
        std::size_t received;
        sf::IpAddress clientAddress;
        unsigned short clientPort;
        serverSocket.receive(buffer, sizeof(buffer), received, clientAddress, clientPort);
        std::cout << "Message received from client: " << buffer << std::endl;
        float time = clock.getElapsedTime().asMicroseconds();
        time = time / 500;
        clock.restart();

        // Определяем код клавиши
        char keyCode = '0';
        if (buffer[0] == 'D')
        {
            hero.key["R"] = true;
        }
        else if (buffer[0] == 'A')
        {
            hero.key["L"] = true;
        }
        else if (buffer[0] == 'W')
        {
            hero.key["Up"] = true;
        }
        else if (buffer[0] == 'S')
        {
            hero.key["Down"] = true;
        }
        else if (buffer[0] == 'G')
        {
            hero.key["G"] = true;
        }
        else if (buffer[0] == 'F')
        {
            hero.key["F"] = true;
        }
        else if (buffer[0] == 'Z')
        {
            keyCode = 'Z';
        }

        hero.update(time, obj);
        // Отправляем обновленный hero клиенту


        /*sf::Packet packet;
        packet << hero;*/


        // Добавляем клиента в список, если его там нет
        auto client = clients.end();
        for (auto it = clients.begin(); it != clients.end(); ++it)
        {
            if (it->address == clientAddress && it->port == clientPort)
            {
                client = it;
                break;
            }
        }

        if (client == clients.end())
        {
            clients.emplace_back(clientAddress, clientPort);
        }

        if (client == clients.end())
        {
            clients.emplace_back(clientAddress, clientPort);
        }
    }

    return 0;
}
