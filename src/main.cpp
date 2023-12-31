#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>

//TODO audio
#include <iostream>
#include <string>
#include "../include/anim.hpp"
#include "../include/player.hpp"
#include "../include/Menu.hpp"
#include "../lib/level/TmxLevel.h"
#include "../include/background.hpp"
#include "../include/view.hpp"
#include "../include/gameplay.hpp"
#include "../include/target.hpp"

int ground = 1080;

int main()
{
    std::srand( std::time(0) );
    // Создаем UDP сокет на клиенте
    sf::UdpSocket clientSocket;
    unsigned short clientPort = 55004;
    clientSocket.bind(clientPort);

    // Определяем IP-адрес и порт сервера
    sf::IpAddress serverAddress = "192.168.29.86";
    unsigned short serverPort = 55001;

    GameStatus GlobalStatus;
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "two Egors and one Artem", sf::Style::Fullscreen);  // TODO name of project
    window.setFramerateLimit(30);

    sf::Texture t;
    t.loadFromFile("../src/heroes/Brodell Walker.png");

    AnimationManager anim;
    anim.loadFromFile("../src/heroes/Brodell Walker.xml", t);
    // anim.create("walk", t, 10, 15, 32, 32, 4, 0.005, 32);
    // anim.create("stay", t, 10, 20 + 32*8, 32, 32, 28, 0.005, 32);


    TmxLevel lvl;
    lvl.LoadFromFile("../src/maps/map.tmx");
    std::vector<TmxObject> obj;
    obj = lvl.GetAllObjects("solid");


    Player hero(anim);

    Target target;

    // sf::Image fonimage; //создаем объект Image (изображение)
	// fonimage.loadFromFile("../src/maps/layers/Layer_0003_6.png");//загружаем в него файл
 
	// sf::Texture fontexture;//создаем объект Texture (текстура)
	// fontexture.loadFromImage(fonimage);//передаем в него объект Image (изображения)
 
	// sf::Sprite fonsprite;//создаем объект Sprite(спрайт)
	// fonsprite.setTexture(fontexture);//передаём в него объект Texture (текстуры)
	// fonsprite.setPosition(0, 150);//задаем начальные координаты появления спрайта


std::vector<std::string> texturePaths = {
        "../src/maps/layers/9.png",
        "../src/maps/layers/8.png",
        "../src/maps/layers/7.png",
        "../src/maps/layers/6.png",
        "../src/maps/layers/5.png",
        "../src/maps/layers/4.png",
        "../src/maps/layers/2.png",
        "../src/maps/layers/1.png",
        "../src/maps/layers/3.png",
        "../src/maps/layers/11.png",
        "../src/maps/layers/12.png",
    };

    ParallaxBackground background(texturePaths);
    Camera camera(1920,1080);

    // sf::RectangleShape rectangle(sf::Vector2f(32,32));

    sf::Clock clock;
    sf::Clock GlobClock;

    sf::String start = L"Start";
    sf::String exit = L"EXIT";
    
    std::vector<sf::String> name_menu = {start, exit};
    std::vector<sf::String> name_results = {L"EXIT", L"EXIT"};
    sf::String arrow_ = L">";
    int winner = 0;
    GMenu menu(600.f,420.f,80,120, name_menu, &window, arrow_);
    GResults result (600.f, 420.f, 80, 120, name_results, &window, arrow_, &winner);
    menu.setColorTextMenu(sf::Color::White, sf::Color::Red, sf::Color::Black);
    menu.setColorArrowMenu();
    result.setColorTextMenu(sf::Color::White, sf::Color::Red, sf::Color::Black);
    result.setColorArrowMenu();
    menu.AlignMenu(0);
    window.setFramerateLimit(60);
    int a = std::rand() % 2 + 49;
    while(window.isOpen()){
    switch (GlobalStatus.GetGameStatus()){
        case Play:
            GamePlay(&window, &clock, &hero, &anim,  &background, &camera, &lvl, &obj, &GlobalStatus, &GlobClock, &clientSocket, &serverAddress,&serverPort, &target);
            break;
        case Menu:
            menu.execute(&GlobalStatus, &GlobClock, &hero);
            clock.restart();
            break;

        case Results:
            result.execute(&GlobalStatus, &GlobClock, &hero, a);
            break;
        }
    }

    return 0;
}

