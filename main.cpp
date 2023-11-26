#include <SFML/Graphics.hpp>
//TODO audio
#include <iostream>
#include <string>
#include "include/anim.hpp"
#include "include/player.hpp"

int ground = 1080;

// class Player{
// public:
// float x, y, dx, dy, w, h;
// bool dir;
// AnimationManager anim;
// bool onLadder, shoot, hit;

// enum {stay, walk} STATE;
// std::map<std::string, bool> key;

// Player(AnimationManager & anim){
//     anim = anim;
//     STATE = stay;
//     dir = 0;
// }

// void KeyCheck(){
//     if (key["L"]){
//         dir = 1;
//         dx =  -0.1;
//         if (STATE == stay) {STATE = walk;}
//     }

//     if (key["R"]){
//         dir = 0;
//         dx = 0.1;
//         if (STATE == stay) {STATE = walk;}
//     }

//     if (key["Up"]){
//         dy = -0.27;
//     }

// //-------------------------
//     if(!(key["R"] || key["L"])){
//         dx = 0;
//         if (STATE == walk) {STATE = stay;}
//     }

// }

// void update(float time){
//     KeyCheck();

//     if(STATE == stay)  {anim.set("stay"); std::cerr << "HERE0\n";}
//     std::cerr << "HERE1\n";
//     if(STATE == walk)  {anim.set("walk");}
//     std::cerr << "HERE2\n";

//     if(dir){anim.flip();}
//     std::cerr << "HERE3\n";

//     x += dx *time;
//     // Collision(0);
//     dy += 0.0005*time;
//     y += y*time;
//     // Collision(1);
//     std::cerr << "HERE4\n";
//     anim.tick(time);
//     std::cerr << "HERE5\n";
//     key["R"] = key["L"] = key["Up"] = false;
// }

// void draw(sf::RenderWindow& window){
//     anim.draw(window, x, y);
// }

// };




int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "two Egors and one Artem");  // TODO name of project

    sf::Texture t;
    t.loadFromFile("src/images/heroes/Brodell Walker.png");

    AnimationManager anim;
    anim.create("walk", t, 10, 15, 32, 32, 4, 0.005, 32);
    anim.create("stay", t, 10, 20+ 32*8, 32, 32, 28, 0.005, 32);

    Player hero(anim);

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

        hero.draw(window);
        window.display();
    }


    return 0;
}