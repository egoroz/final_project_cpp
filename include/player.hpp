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
    bool life, dir;

    enum {stay, run, jump, sit, sneak, legspin, stabling} STATE; //sneak - крадется legspin - вертушка stabling - поножовщина
    std::map<std::string, bool> key;

    Player(const AnimationManager &anim_, TmxLevel & lvl){
        obj = lvl.GetAllObjects("solid");  //Получаем все объекты для взаимодействия с персонажем
        STATE = stay;
        anim = anim_;
        //onGround = false;
        dir = false;
        x = 550;
        y = 500; 
        w = anim.getW();
        h = anim.getH();
    }

    void KeyCheck(){
        if(key["R"])   {dx = 0.1; if(STATE == stay){STATE = run; dir = false;} }
        if(key["L"])   {dx = -0.1; if(STATE == stay){STATE = run; dir = true;} }
        if(key["Up"])  {if ((STATE == stay) || (STATE == run)){STATE = jump; dy = -0.15;}}
        if(key["Down"]){if(STATE == stay){STATE = sit;} if (STATE == run){STATE = sneak;}}
        if(key["G"])   {if ((STATE == run) || (STATE == jump) || (STATE == stay)){STATE = legspin;}}
        if(key["F"])   {if ((STATE == run) || (STATE == jump) || (STATE == stay)){STATE = stabling;}}

        if(!(key["R"] || key["L"])){dx = 0;} 
        if(!key["Up"])             {if(STATE == jump){dy = 0;}}
        if(!key["Down"])           {if (STATE == sit){STATE = stay;}    if(STATE == sneak){STATE = run;}}
        if(!key["G"])              {if(STATE == legspin){STATE = run;}  if(dx == 0){STATE = stay;}}
        if(!key["F"])              {if(STATE == stabling){STATE = run;} if(dx == 0){STATE = stay;}}
    }

    void Animation(float time){
        if(STATE == stay){anim.set("стоит");} //stay, run, jump, sit, sneak, legspin, stabling
        if(STATE == run){anim.set("бег с оружием вперед");} //пока без оружия
        if(STATE == jump){anim.set("бег с оружием вперед");}
        if(STATE == sit){anim.set("сидит");}
        if(STATE == sneak){anim.set("крадется");}
        if(STATE == legspin){anim.set("вертушка1");}
        if(STATE == stabling){anim.set("поножовщина2");}

        if(dir){anim.flip();}

        y -= anim.getH() - h;
        x -= anim.getW() - w;


        w = anim.getW();
        h = anim.getH();
        anim.tick(time);
    }

    sf::FloatRect getRect(){ return sf::FloatRect(x, y, w, h);}

    void Collision(int num){
        for (int i = 0; i < obj.size(); ++i){
            if (getRect().intersects(obj[i].rect)){ // пересечение игрока с любым объектов
                if(obj[i].name == "solid"){  //встретились с "твердым" препятствием
                    if (dy > 0 && num == 1) {y = obj[i].rect.top - h; dy  = 0; STATE = stay;}
                    if (dy < 0 && num == 1) {y = obj[i].rect.top + obj[i].rect.height; dy = 0;}
                    if (dx > 0 && num == 0) {x = obj[i].rect.left - w;}
                    if (dx < 0 && num == 0) {x = obj[i].rect.left + obj[i].rect.width;}
                }
            }
        }
    }

    void update(float time){
        KeyCheck();
        Animation(time);

        x += dx * time;
        Collision(0);                           // CollitionX
        dy += 0.00005*time;
        y += dy * time;
        Collision(1);                           // CollitionY


        key["R"] = key["L"] = key["Up"] = key["Down"] = key["F"] = key["G"] = false;
        // onGround = false;
    }

    void draw(sf::RenderWindow & window){
            anim.draw(window, x, y);
    }
};

#endif