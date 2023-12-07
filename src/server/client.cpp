#include <SFML/Network.hpp>
#include <iostream>

int main()
{
    // Создание сокета
    sf::TcpSocket socket;

    // Получение имени хоста
    sf::IpAddress host = "10.55.129.117";
    std::cout<<host<<std::endl;
    // Определение порта
    unsigned short port = 12345;
    std::cout<<"ping"<<std::endl;
    // Подключение к серверу
    if (socket.connect(host, port) != sf::Socket::Done) {
        std::cout<< "ERROR"<<std::endl;
        return -1;
    }
    std::cout << "Connected to server " << host << std::endl;

    // Отправка сообщения серверу
    std::string message;
    while (true)
    {
        std::cout << "Enter message: ";
        std::getline(std::cin, message);

        if (message == "exit")
            break;

        if (socket.send(message.c_str(), message.size() + 1) != sf::Socket::Done)
            return -1;

        // Получение ответа от сервера
        char buffer[1024];
        std::size_t received;
        if (socket.receive(buffer, sizeof(buffer), received) != sf::Socket::Done)
            return -1;

        std::cout << "Message received from server: \"" << buffer << "\"" << std::endl;
    }

    // Закрытие соединения с сервером
    socket.disconnect();

    return 0;
}