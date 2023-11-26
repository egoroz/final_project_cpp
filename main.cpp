#include <SFML/Graphics.hpp>
//TODO audio
#include <iostream>
#include <string>
#include "anim.hpp"

int ground = 1080;

const int H = 30;
const int W = 40;

std::string TileMap[H] = {
    "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
    "B                                      B",
    "B                                      B",
    "B        0000                          B",
    "B                            B         B",
    "B                            B         B",
    "B                         BBBB         B",
    "B BBB                        B         B",
    "B                            B         B",
    "B               B                      B",
    "B               BB                     B",
    "B                                      B",
    "B        0000                          B",
    "B                            B         B",
    "B                            B         B",
    "B                         BBBB         B",
    "B BBB                                  B",
    "B                                      B",
    "B               B                      B",
    "B                                      B",
    "B                                      B",
    "B        0000                          B",
    "B                            BBBB      B",
    "B                                      B",
    "B                                      B",
    "B BBB                                  B",
    "B                                      B",
    "B               B                      B",
    "B               BB                     B",
    "BBBBBBBBBB   BBBBBBBBBBBBBBBBBBBBBBBBBBB"
};






int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "two Egors and one Artem");  // TODO name of project

    sf::Texture t;
    t.loadFromFile("images/heroes/soviet_man.png");

    AnimationManager anim;
    anim.create("run", t, 0, 40, 150, 170, 6, 0.005, 150);
    anim.create("jump", t, 0, 320, 150, 170, 6, 0.0045, 150);
    anim.create("stay", t, 0, 320, 150, 170, 1, 0.005, 150);

    sf::RectangleShape rectangle(sf::Vector2f(32,32));

    sf::Clock clock;

    while(window.isOpen()){
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time / 500;

        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){window.close();}
        }
        
        anim.set("stay");

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
            std::cerr << "push right\n";
            anim.set("run");
            std::cerr << "enter push right right\n";
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
            anim.set("run");
            anim.flip(true);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
            anim.set("jump");
        }

        

        anim.tick(time);

        window.clear(sf::Color::White);

        // for (int i = 0; i<H; ++i){
        //     for(int j = 0; j<W; ++j){
        //         if(TileMap[i][j] == 'B'){rectangle.setFillColor(sf::Color::Black);}
        //         if(TileMap[i][j] == '0'){rectangle.setFillColor(sf::Color::Green);}
        //         if(TileMap[i][j] == ' ') {continue;}

        //         rectangle.setPosition(j*32, i*32);
        //         window.draw(rectangle);
        //     }

        // }

        anim.draw(window, 700, 700);
        window.display();
    }


    return 0;
}