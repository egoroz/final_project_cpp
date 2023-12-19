#include "../include/gameplay.hpp"


void GamePlay(sf::RenderWindow* window, sf::Clock* clock, Player* hero1, AnimationManager* anim, ParallaxBackground* background, Camera* camera, TmxLevel* lvl, std::vector<TmxObject>* obj, GameStatus* gs, sf::Clock* gclock, sf::UdpSocket* clientSocket, sf::IpAddress* serverAddress,unsigned short* serverPort, Target* target)
{
    Player* hero2 = new Player(*anim, 500, 50);
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
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        keyCode = 'W';
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        keyCode = 'S';
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
    {
        keyCode = 'G';
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
    {
        keyCode = 'F';
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        window->close();
    }


    // Отправляем код клавиши на сервер
    char message[2];
    message[0] = keyCode;
    message[1] = '\0';
    clientSocket->send(message, sizeof(message), *serverAddress, *serverPort);

    float time = clock->getElapsedTime().asMicroseconds();
    time = time / 500;
    clock->restart();
    sf::Event event;
    while(window->pollEvent(event)){
        if(event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape){window->close();}
    }


    window->clear(sf::Color::Black);

    sf::Packet packet;
    clientSocket->receive(packet, *serverAddress, *serverPort);
    packet >> *hero1>>*hero2;
    packet >> *hero1>>*hero2;
    std::cout<< "gameplay received: "<<hero1->STATE<<' '<<hero2->STATE<<std::endl;
    hero1->Animation(time);
    hero2->Animation(time);
    background->update(time);
    camera->update(sf::Vector2f(hero1->x, hero1->y + hero1->h));

    background->draw(*window);

    target->draw(*(window));
    lvl->Draw(*window);
    hero1->draw(*window);
    hero2->draw(*window);
    camera->applyTo(*window);


    window->display();
    bool goon = true;
    if((hero2->x-hero1->x)*(hero2->x-hero1->x)+(hero2->y-hero1->y)*(hero2->y-hero1->y)<100){
        if(hero2->STATE==Entity::stabling || hero1->STATE==Entity::stabling){
            goon = false;
        }
    } 
    if(gclock->getElapsedTime().asSeconds()>300.f || !goon){
        gs->ChangeGameStatus(status::Results);
    }
}