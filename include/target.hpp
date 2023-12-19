#ifndef TARGET_H
#define TARGET_H



class Target {
private:
    float x, y, w, h;
    sf::RectangleShape rectangle;

public:
    Target(){
        int x=1050; int y=1040; int w=100; int h=100;
        sf::RectangleShape rectangle(sf::Vector2f(w, h));
        rectangle.setFillColor(sf::Color::Red);
        rectangle.setPosition(x, y);
    }

    sf::FloatRect getRect(){ return sf::FloatRect(x, y, w, h);}

    void draw(sf::RenderWindow& window){
        window.draw(rectangle);
    }
};

#endif //TARGET_H
