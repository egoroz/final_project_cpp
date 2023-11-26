#ifndef PLAYER_H
#define PLAYER_H

#include<iostream>
#include"anim.hpp"
#include<string>

class Player{
public:
    float x, y, dx, dy, w, h;
    AnimationManager anim;
    bool life, dir;

    enum {stay, walk} STATE;
    std::map<std::string, bool> key;

    Player(const AnimationManager &anim_){
        STATE = stay;
        anim = anim_;
        dir = false;
        x = 100;
        y = 100;
    }

    void KeyCheck(){
        if(key["R"]){dx = 0.1; STATE = walk; dir = false;}
        if(key["L"]){dx = -0.1; STATE = walk; dir = true;}

        if(!(key["R"] || key["L"])){dx = 0; STATE = stay; } 
    }

    void Collision(int dir_){
        //TODO
    }

    void update(float time){
        KeyCheck();

        if(STATE == stay){anim.set("stay");}
        if(STATE == walk){anim.set("walk");}

        if(dir){anim.flip();}

        x += dx * time;
        Collision(0);                           // CollitionX
        dy += 0.00005*time;
        y += dy * time;
        Collision(1);                           // CollitionY
        anim.tick(time);
        // x = 100; y = 100;
        // std::cerr << "x = " << x << " y = " << y <<'\n';

        key["R"] = key["L"] = key["Up"] = false;
    }

    void draw(sf::RenderWindow & window){
            anim.draw(window, x, y);
    }
};

#endif