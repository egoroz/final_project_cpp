#include <SFML/Network.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <vector>
#include <map>
#include "../../include/player.hpp"
#include "../../include/entity.hpp"
#include "../../include/anim.hpp"
#include "../../include/gamestatus.hpp"
#include "../../include/Menu.hpp"
#include "../../include/view.hpp"
#include "../../lib/level/TmxLevel.h"
#include "../../lib/tinyxml2/tinyxml2.h"

// Структура для идентификации клиента
struct ClientID {
    sf::IpAddress ip;
    unsigned short port;
    bool operator<(const ClientID& other) const {
        if (ip.toInteger() != other.ip.toInteger()) return ip.toInteger() < other.ip.toInteger();
        return port < other.port;
    }
};

int main()
{
    sf::Clock clock;
    sf::Texture t;
    // Проверь пути к файлам! Если сервер запускается из другой папки, пути могут отличаться
    t.loadFromFile("../src/heroes/Brodell Walker.png");
    
    AnimationManager anim;
    anim.loadFromFile("../src/heroes/Brodell Walker.xml", t);
    
    TmxLevel lvl;
    lvl.LoadFromFile("../src/maps/map.tmx");
    std::vector<TmxObject> obj = lvl.GetAllObjects("solid");
    
    Player Player1(anim);
    Player Player2(anim);
    sf::Clock gclock;

    // Создаем UDP сокет на сервере
    sf::UdpSocket serverSocket;
    unsigned short serverPort = 55001;
    serverSocket.bind(serverPort);
    
    // ВАЖНО: Делаем сокет неблокирующим!
    serverSocket.setBlocking(false);

    // Словарь для привязки IP+Порт к номеру игрока (1 или 2)
    std::map<ClientID, int> connectedClients;

    std::cout << "Server is running on port " << serverPort << std::endl;

    while (true)
    {
        // 1. Сбрасываем нажатия клавиш перед новым кадром
        Player1.key["R"] = Player1.key["L"] = Player1.key["Up"] = Player1.key["Down"] = Player1.key["G"] = Player1.key["F"] = false;
        Player2.key["R"] = Player2.key["L"] = Player2.key["Up"] = Player2.key["Down"] = Player2.key["G"] = Player2.key["F"] = false;

        // 2. Читаем ВСЕ пришедшие пакеты
        char buffer[1024];
        std::size_t received;
        sf::IpAddress sender;
        unsigned short port;

        while (serverSocket.receive(buffer, sizeof(buffer), received, sender, port) == sf::Socket::Done)
        {
            ClientID clientKey = {sender, port};

            // Регистрируем нового игрока
            if (connectedClients.find(clientKey) == connectedClients.end()) {
                if (connectedClients.size() == 0) {
                    connectedClients[clientKey] = 1;
                    std::cout << "Player 1 connected: " << sender << ":" << port << std::endl;
                }
                else if (connectedClients.size() == 1) {
                    connectedClients[clientKey] = 2;
                    std::cout << "Player 2 connected: " << sender << ":" << port << std::endl;
                }
            }

            // Применяем управление к нужному игроку
            int playerId = connectedClients[clientKey];
            Player* p = (playerId == 1) ? &Player1 : &Player2;

            if (buffer[0] == 'D') p->key["R"] = true;
            else if (buffer[0] == 'A') p->key["L"] = true;
            else if (buffer[0] == 'W') p->key["Up"] = true;
            else if (buffer[0] == 'S') p->key["Down"] = true;
            else if (buffer[0] == 'G') p->key["G"] = true;
            else if (buffer[0] == 'F') p->key["F"] = true;
        }

        // 3. Обновляем физику
        float time = clock.getElapsedTime().asMicroseconds();
        time = time / 500;
        clock.restart();

        if (gclock.getElapsedTime().asSeconds() < 10){
            Player1.x = 550;  Player1.y = 840;
            Player2.x = 1250; Player2.y = 840;
        }

        Player1.update(time, obj);
        Player2.update(time, obj);

        // 4. Отправляем новые координаты всем подключенным клиентам
        if (!connectedClients.empty()) {
            sf::Packet packet;
            packet << Player1 << Player2;
            
            for (auto const& [client, id] : connectedClients) {
                serverSocket.send(packet, client.ip, client.port);
            }
        }

        // 5. Немного спим, чтобы сервер не сжег процессор (ограничиваем до ~60 тиков в секунду)
        sf::sleep(sf::milliseconds(15));
    }

    return 0;
}