#include "../include/gameplay.hpp"


void GamePlay(sf::RenderWindow* window, sf::Clock* clock, Player* hero, std::vector<Bullet*> bullets, ParallaxBackground* background, Camera* camera, TmxLevel* lvl, std::vector<TmxObject>* obj, GameStatus* gs, sf::Clock* gclock)
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
    clientSocket->send(message, sizeof(message), *serverAddress, *serverPortNumber);



    //window->setFramerateLimit(60);
    // menu.execute();
    // std::cout << "lox\n";
    // std::cout << "lox\n";
    // std::cout << "lox\n";
    float time = clock->getElapsedTime().asMicroseconds();
    time = time / 500;
    clock->restart();
    sf::Event event;
    while(window->pollEvent(event)){
        if(event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape){window->close();}
    }


    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){hero->key["R"] = true;}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){hero->key["L"] = true;}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){hero->key["Up"] = true;}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){hero->key["Down"] = true;}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)){hero->key["F"] = true;}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::G)){hero->key["G"] = true;}


    hero->update(time, *obj);
    background->update(time);
    camera->update(sf::Vector2f(hero->x, hero->y + hero->h));

    window->clear(sf::Color::Black);
    background->draw(*window);

        // window.draw(fonsprite);
        std::cerr << time << "\n";
        for (unsigned i = 0; i< bullets.size(); ++i){
            bullets[i]->draw(*window);
        }
        lvl->Draw(*window);
        hero->draw(*window);
        camera->applyTo(*window);

    //     sf::RectangleShape rectangle(sf::Vector2f(hero.w,hero.h));
    //     rectangle.setPosition(hero.x, hero.y);
    //     rectangle.setFillColor(sf::Color(0, 150, 50));
    //     window.draw(rectangle);    //рисуем модельку перса

    // for (int i = 0; i < hero.obj.size(); ++i){
    //     sf::RectangleShape rectangle(sf::Vector2f(hero.obj[i].rect.width,hero.obj[i].rect.height));
    //     rectangle.setPosition(hero.obj[i].rect.left, hero.obj[i].rect.top);
    //     rectangle.setFillColor(sf::Color(150, 50, 250));
    //     window.draw(rectangle);
    // } //Рисуем объекты с которыми колизируем

    window->display();
    std::cout << gclock->getElapsedTime().asSeconds() << "\n";
    if(gclock->getElapsedTime().asSeconds()>30.f){
        gs->ChangeGameStatus(status::Results);
    }
}