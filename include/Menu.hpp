#pragma once

#include <SFML/Graphics.hpp>

enum status {Menu, Play, Results};

void InitText(sf::Text& mtext, float xpos, float ypos, const sf::String, int size_font, sf::Color menu_text_color = sf::Color::White, int bord = 0, sf::Color menu_border_color = sf::Color::Black);

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

class Menu{
public:
    Menu(){
        sf::RenderWindow window_;
        window_.create(sf::VideoMode::getDesktopMode(), "Menu screen", sf::Style::Fullscreen);
        window_.setMouseCursorVisible(false);
        auto width = static_cast<float>(sf::VideoMode::getDesktopMode().width);
        auto height = static_cast<float>(sf::VideoMode::getDesktopMode().height);
        sf::RectangleShape background (sf::Vector2f(width, height));
        sf::Texture texture_window;
        texture_window.loadFromFile("../src/menu/black-brick-wall-textured-background.jpg");
        background.setTexture(&texture_window);
        sf::Font menu_font;
        menu_font.loadFromFile("../src/menu/Karma Future.otf");
        sf::Text Titul;
        Titul.setFont(menu_font);
        InitText(Titul, 480, 50, L"CheloFight", 150, sf::Color::White, 3);
    }
    void execute();
};