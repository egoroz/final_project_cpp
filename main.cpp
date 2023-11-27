#include <SFML/Graphics.hpp>
//TODO audio
#include <iostream>
#include <string>
#include "include/anim.hpp"
#include "include/player.hpp"
#include "lib/level/TmxLevel.h"

int ground = 1080;


int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "two Egors and one Artem");  // TODO name of project

    sf::Texture t;
    t.loadFromFile("src/heroes/images/Brodell Walker.png");

    AnimationManager anim;
    anim.create("walk", t, 10, 15, 32, 32, 4, 0.005, 32);
    anim.create("stay", t, 10, 20+ 32*8, 32, 32, 28, 0.005, 32);


    TmxLevel lvl;
    lvl.LoadFromFile("src/maps/map.tmx");

    Player hero(anim, lvl);


    // sf::RectangleShape rectangle(sf::Vector2f(32,32));

    sf::Clock clock;

    while(window.isOpen()){
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time / 500;

        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){window.close();}
        }
        

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){hero.key["R"] = true;}
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){hero.key["L"] = true;}
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){hero.key["Up"] = true;}

        hero.update(time);

        window.clear(sf::Color::White);

        lvl.Draw(window);
        hero.draw(window);
        window.display();
    }


    return 0;
}