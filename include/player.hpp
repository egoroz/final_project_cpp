#ifndef PLAYER_H
#define PLAYER_H

#include<iostream>
#include"anim.hpp"
#include<string>
#include<vector>
#include "../lib/level/TmxLevel.h"

class Player{
public:
   std::vector<TmxObject> obj;//вектор объектов карты
    float x, y, dx, dy, w, h;
    AnimationManager anim;
    bool life, dir, onGround;

    enum {stay, walk} STATE;
    std::map<std::string, bool> key;

    Player(const AnimationManager &anim_, TmxLevel & lvl){
        obj = lvl.GetAllObjects("solid");  //Получаем все объекты для взаимодействия с персонажем
        STATE = stay;
        anim = anim_;
        onGround = false;
        dir = false;
        x = 550;
        y = 500; 
        w = anim.getW();
        h = anim.getH();
    }

    void KeyCheck(){
        if(key["R"]){dx = 0.1; STATE = walk; dir = false;}
        if(key["L"]){dx = -0.1; STATE = walk; dir = true;}
        if(key["Up"]){dy = -0.1;}

        if(!(key["R"] || key["L"])){dx = 0; STATE = stay; } 
        if(!key["Up"]){dy = 0.005;}
    }

    sf::FloatRect getRect(){ return sf::FloatRect(x, y, w, h);}

    void Collision(int num){
        for (int i = 0; i < obj.size(); ++i){
            std::cerr << "obj_top_i  =  " << obj[i].rect.top << "     obj_left_i  =  " << obj[i].rect.left <<"\n";
            if (getRect().intersects(obj[i].rect)){ // пересечение игрока с любым объектом
                std::cerr << "obj size: " << obj.size() << "\n";
                if(obj[i].name == "solid"){  //встретились с "твердым" препятствием
                    if (dy > 0 && num == 1) {y = obj[i].rect.top - h; dy  = 0; STATE = stay; std::cerr << "SOLID1\n" << h << '\n' << "y = "<< y << " obj_y ="<< obj[i].rect.top << '\n'; }
                    if (dy < 0 && num == 1) {y = obj[i].rect.top + obj[i].rect.height; dy = 0; std::cerr << "SOLID2\n";}
                    if (dx > 0 && num == 0) {x = obj[i].rect.left - w; std::cerr << "SOLID3\n";}
                    if (dx < 0 && num == 0) {x = obj[i].rect.left + obj[i].rect.width; std::cerr << "SOLID4\n";}
                }
            }
        }
    }

    void update(float time){
        KeyCheck();

        if(STATE == stay){anim.set("stay");}
        if(STATE == walk){anim.set("walk");}

        if(dir){anim.flip();}
        w = anim.getW();
        h = anim.getH();
        anim.tick(time);


        x += dx * time;
        Collision(0);                           // CollitionX
        dy += 0.00005*time;
        y += dy * time;
        Collision(1);                           // CollitionY
        // x = 100; y = 100;
        // std::cerr << "x = " << x << " y = " << y <<'\n';

        key["R"] = key["L"] = key["Up"] = false;
        onGround = false;
    }

    void draw(sf::RenderWindow & window){
            anim.draw(window, x, y);
    }
};

#endif