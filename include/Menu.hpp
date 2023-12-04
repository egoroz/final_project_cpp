#pragma once

#include <SFML/Graphics.hpp>

enum status {Menu, Play, Results};

void InitText(sf::Text& mtext, float xpos, float ypos, const sf::String str, int size_font, sf::Color menu_text_color = sf::Color::White, int bord = 0, sf::Color menu_border_color = sf::Color::Black);

class GameStatus{
private:
    status stat;
public:
    GameStatus(){
        stat = Menu;
    }

    status GetGameStatus(){
        return stat;
    }

    void ChangeGameStatus(status st_){
        stat = st_;
    }
};

class GMenu{
private:
    sf::RenderWindow window_;
    sf::Texture texture_window;
    sf::Font menu_font;
    sf::Text Titul;
    sf::RectangleShape* bck_ptr;
public:
    GMenu(){
        
        window_.create(sf::VideoMode::getDesktopMode(), "Menu screen", sf::Style::Fullscreen);
        window_.setMouseCursorVisible(false);
        auto width = static_cast<float>(sf::VideoMode::getDesktopMode().width);
        auto height = static_cast<float>(sf::VideoMode::getDesktopMode().height);
        sf::RectangleShape background (sf::Vector2f(width, height));
        bck_ptr = &background;
        if(!texture_window.loadFromFile("1.jpg")) std::terminate();
        background.setTexture(&texture_window);
        
        
        if(!menu_font.loadFromFile("menu/2.otf"))std::terminate();
        
        Titul.setFont(menu_font);
        InitText(Titul, 480, 50, L"CheloFight", 150, sf::Color::White, 3);
    }
    void execute(){
        while(window_.isOpen()){
            sf::Event event;
            while(window_.pollEvent(event)){
                if(event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape) window_.close();
            }
            window_.clear();
            window_.draw(*(bck_ptr));
            std::cout << "ahahah\n";
            window_.draw(Titul);
            window_.display();
        }
    }
};

void InitText(sf::Text& mtext, float xpos, float ypos, const sf::String str, int size_font, sf::Color menu_text_color, int bord , sf::Color menu_border_color){
    mtext.setCharacterSize(size_font);
    mtext.setPosition(xpos, ypos);
    mtext.setString(str);
    mtext.setFillColor(menu_text_color);
    mtext.setOutlineThickness(bord);
    mtext.setOutlineColor(menu_border_color);
}