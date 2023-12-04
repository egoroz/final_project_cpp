#pragma once

#include <SFML/Graphics.hpp>

enum status {Menu, Play, Results};

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
    sf::RenderWindow window;
    window.create(sf::VideoMode::getDesktopMode(), "Menu screen", Style::Fullscreen);
    window.setMouseCursorVisible(false);
    void execute();
};