#include <SFML/Network.hpp>
#include <iostream>
#include <vector>

int main()
{
    // Создание сокета
    sf::TcpListener listener;

    // Определение порта
    unsigned short port = 12345;

    // Привязка сокета к порту
    if (listener.listen(port) != sf::Socket::Done) {
        std::cout<<"ERROR"<<std::endl;
        return -1;
    }
    std::cout << "Server is listening to port " << port << ", waiting for connections..." << std::endl;

    // Ожидание клиентов
    std::vector<sf::TcpSocket*> clients;
    while (true)
    {
        // Создание нового сокета для клиента
        sf::TcpSocket* socket = new sf::TcpSocket;

        // Ожидание подключения клиента
        if (listener.accept(*socket) == sf::Socket::Done)
        {
            std::cout << "Client connected: " << socket->getRemoteAddress() << std::endl;

            // Добавление нового клиента в список клиентов
            clients.push_back(socket);
        }
        else
        {
            // Ошибка при подключении клиента
            delete socket;
        }

        // Обработка сообщений от клиентов
        for (auto it = clients.begin(); it != clients.end(); ++it)
        {
            sf::TcpSocket& socket = **it;

            // Проверка, есть ли сообщение от клиента
            char buffer[1024];
            std::size_t received;
            if (socket.receive(buffer, sizeof(buffer), received) == sf::Socket::Done)
            {
                std::cout << "Message received from client " << socket.getRemoteAddress() << ": \"" << buffer << "\"" << std::endl;

                // Отправка сообщения обратно клиенту
                if (socket.send(buffer, received) != sf::Socket::Done)
                {
                    std::cout << "Error sending message to client " << socket.getRemoteAddress() << std::endl;
                }
            }
        }
    }

    // Закрытие соединений с клиентами
    for (auto it = clients.begin(); it != clients.end(); ++it)
    {
        sf::TcpSocket& socket = **it;
        socket.disconnect();
        delete &socket;
    }

    return 0;
}