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