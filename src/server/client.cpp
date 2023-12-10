#include <SFML/Network.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <iostream>

int main()
{
    // Создаем UDP сокет на клиенте
    sf::UdpSocket clientSocket;
    unsigned short clientPort = 55002;
    clientSocket.bind(clientPort);

    // Определяем IP-адрес и порт сервера
    sf::IpAddress serverAddress = "192.168.33.76";
    unsigned short serverPortNumber = 55001;

    while (true)
    {
        // Определяем код клавиши
        int keyCode = 0;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            keyCode = 'D';
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            keyCode = 'A';
        }

        // Отправляем код клавиши на сервер
        char message[2];
        message[0] = keyCode;
        message[1] = '\0';
        clientSocket.send(message, sizeof(message), serverAddress, serverPortNumber);

        // Получаем код клавиши от сервера
        char buffer[1024];
        std::size_t received;
        clientSocket.receive(buffer, sizeof(buffer), received, serverAddress, serverPortNumber);
        std::cout << "Key code received from server: " << static_cast<int>(buffer[0]) << std::endl;

        // Проверяем, нажата ли клавиша Escape
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            break;
        }
    }

    return 0;
}
