#include <SFML/Network.hpp>
#include <iostream>

class Client
{
public:
    Client(sf::IpAddress address, unsigned short port) : address(address), port(port) {}

    sf::IpAddress address;
    unsigned short port;
};

int main()
{
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

        // Определяем код клавиши
        int keyCode = 0;
        if (buffer[0] == 'D')
        {
            keyCode = 1;
        }
        else if (buffer[0] == 'A')
        {
            keyCode = -1;
        }
        else if (buffer[0] != '\0')
        {
            keyCode = 2;
        }

        // Отправляем код клавиши клиенту
        char reply[2];
        reply[0] = keyCode;
        reply[1] = '\0';
        serverSocket.send(reply, sizeof(reply), clientAddress, clientPort);

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
