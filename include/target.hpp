#ifndef TARGET_H
#define TARGET_H



class Target {
public:
    float x, y, w, h;
    sf::RectangleShape* rectangle = new sf::RectangleShape (sf::Vector2f(100, 100));

public:
    Target(){
        x=1350; y=500; w=100; h=100;
        //rectangle->setSize(w, h);
        rectangle->setFillColor(sf::Color::Red);
        rectangle->setPosition(x, y);
    }


    sf::FloatRect getRect(){ return sf::FloatRect(x, y, w, h);}

    void draw(sf::RenderWindow& window){
        window.draw(*rectangle);
    }
};

#endif //TARGET_H
