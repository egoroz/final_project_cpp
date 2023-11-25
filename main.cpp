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

class Player{
    public:

    float dx, dy;
    sf::FloatRect rect;
    bool onGround;
    sf::Sprite sprite;
    float currentFrame;

    Player(sf::Texture &image){
        sprite.setTexture(image);
        rect = sf::FloatRect(0, 40, 150, 170);
        sprite.setTextureRect(sf::IntRect(0, 40, 150, 170));
        rect.left = 1000;
        rect.top = 700;
        dx = dy = 0;
        currentFrame = 0;
    }

    void update(const float& time){
        rect.left += dx * time;

        Collision(0);

        if (!onGround) {dy = dy + 0.00009*time;}
        rect.top += dy * time;
        onGround = false;

        Collision(1);


        currentFrame += 0.001*time;
        if ( currentFrame > 6 ) currentFrame -= 6;

        if (dx > 0) {sprite.setTextureRect(sf::IntRect(150*((int)currentFrame),40,150,170));}
        if (dx < 0) {sprite.setTextureRect(sf::IntRect(150*((int)currentFrame) + 150,40, -150,170));}

        sprite.setPosition(rect.left, rect.top);
        
        dx = 0;
    }

    void Collision(int dir){
        for(int i = rect.top/32; i < (rect.top + rect.height)/32; ++i){
            for(int j = rect.left/32; j < (rect.left + rect.width)/32; ++j){
                if (TileMap[i][j] == 'B'){
                    if((dx > 0) && (dir == 0)){rect.left = j*32 - rect.width;}
                    if((dx < 0) && (dir == 0)){rect.left = j*32 + 32 ;}
                    if((dy > 0) && (dir == 1)){rect.top = i*32 - rect.height; dy = 0; onGround = true;}
                    if((dy < 0) && (dir == 1)){rect.top = i*32 + 32 ; dy = 0;}
                }
            }
        }
    }
};



int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "two Egors and one Artem");  // TODO name of project

    sf::Texture t;
    t.loadFromFile("images/heroes/soviet_man.png");

    AnimationManager anim;
    anim.create("run", t, 0, 40, 150, 170, 6, 0.005, 40);
    anim.create("jump", t, 0, 240, 150, 170, 6, 0.0045, 40);
    anim.create("stay", t, 0, 240, 150, 170, 1, 0.005, 40);

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
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
            p.dx = 0.1;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
            p.dx = -0.1;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
            if (p.onGround) {p.dy = -0.2; p.onGround = false;}
        }

        p.update(time);

        window.clear(sf::Color::White);

        for (int i = 0; i<H; ++i){
            for(int j = 0; j<W; ++j){
                if(TileMap[i][j] == 'B'){rectangle.setFillColor(sf::Color::Black);}
                if(TileMap[i][j] == '0'){rectangle.setFillColor(sf::Color::Green);}
                if(TileMap[i][j] == ' ') {continue;}

                rectangle.setPosition(j*32, i*32);
                window.draw(rectangle);
            }

        }

        window.draw(p.sprite);
        window.display();
    }


    return 0;
}