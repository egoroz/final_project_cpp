#include <SFML/Graphics.hpp>
//TODO audio
#include <iostream>
#include <string>
#include "../include/anim.hpp"
#include "../include/player.hpp"
#include "../include/Menu.hpp"
#include "../lib/level/TmxLevel.h"
#include "../include/background.hpp"
#include "../include/view.hpp"

int ground = 1080;


int main()
{
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "two Egors and one Artem");  // TODO name of project
    // window.setFramerateLimit(120);

    sf::Texture t;
    t.loadFromFile("../src/heroes/Brodell Walker.png");

    AnimationManager anim;
    anim.loadFromFile("../src/heroes/Brodell Walker.xml", t);
    // anim.create("walk", t, 10, 15, 32, 32, 4, 0.005, 32);
    // anim.create("stay", t, 10, 20 + 32*8, 32, 32, 28, 0.005, 32);


    TmxLevel lvl;
    lvl.LoadFromFile("../src/maps/map.tmx");

    Player hero(anim, lvl);

    // sf::Image fonimage; //создаем объект Image (изображение)
	// fonimage.loadFromFile("../src/maps/layers/Layer_0003_6.png");//загружаем в него файл
 
	// sf::Texture fontexture;//создаем объект Texture (текстура)
	// fontexture.loadFromImage(fonimage);//передаем в него объект Image (изображения)
 
	// sf::Sprite fonsprite;//создаем объект Sprite(спрайт)
	// fonsprite.setTexture(fontexture);//передаём в него объект Texture (текстуры)
	// fonsprite.setPosition(0, 150);//задаем начальные координаты появления спрайта


std::vector<std::string> texturePaths = {
        "../src/maps/layers/12.png",
        "../src/maps/layers/11.png",
        "../src/maps/layers/10.png",
        "../src/maps/layers/9.png",
        "../src/maps/layers/8.png",
        "../src/maps/layers/7.png",
        "../src/maps/layers/6.png",
        "../src/maps/layers/4.png",
        "../src/maps/layers/3.png",
        "../src/maps/layers/5.png",
        "../src/maps/layers/2.png",
        "../src/maps/layers/1.png"
    };

    ParallaxBackground background(texturePaths);
    Camera camera(800, 800);

    // sf::RectangleShape rectangle(sf::Vector2f(32,32));

    sf::Clock clock;

    while(window.isOpen()){
        // std::cout << "lox\n";
        // std::cout << "lox\n";
        // std::cout << "lox\n";
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
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){hero.key["Down"] = true;}
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)){hero.key["F"] = true;}
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::G)){hero.key["G"] = true;}


        hero.update(time);
        background.update(time);
        camera.update(sf::Vector2f(hero.x, hero.y + hero.h));

        window.clear(sf::Color::White);
        background.draw(window);

        // window.draw(fonsprite);
        std::cerr << time << "\n";
        lvl.Draw(window);
        hero.draw(window);
        camera.applyTo(window);

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

        window.display();
    }


    return 0;
}