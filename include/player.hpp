#ifndef PLAYER_H
#define PLAYER_H

#include<iostream>
#include"anim.hpp"
#include<string>
#include<vector>
#include "../lib/level/TmxLevel.h"
#include "entity.hpp"

class Player: public Entity{
public:
    bool canJump;

    Player(const AnimationManager &anim_, int x=550, int y=800):Entity(anim_, x, y){
        // obj = lvl.GetAllObjects("solid");  //Получаем все объекты для взаимодействия с персонажем
        // STATE = stay;
        canJump = false;
        //onGround = false;
        // dir = false;

        // w = anim.getW();
        // h = anim.getH();
    }

    void KeyCheck(){
        if(key["R"])   if(!(STATE == legspin || STATE == stabling)){dx = 0.09; dir = false; if(STATE == stay){STATE = run; } }
        if(key["L"])   if(!(STATE == legspin || STATE == stabling)){dx = -0.09; dir = true; if(STATE == stay){STATE = run; } }
        if(key["Up"])  if(!(STATE == legspin || STATE == stabling)){if ((STATE == stay) || (STATE == run)){if(canJump){STATE = jump; dy = -0.15; canJump = false;}}}
        if(key["Down"])if(!(STATE == legspin || STATE == stabling)){if(STATE == stay){STATE = sit;} if (STATE == run){STATE = sneak;}}
        if(key["G"])   if(!(STATE == legspin || STATE == stabling)){if ((STATE == run) || (STATE == jump) || (STATE == stay)){STATE = legspin;}}
        if(key["F"])   if(!(STATE == legspin || STATE == stabling)){if ((STATE == run) || (STATE == jump) || (STATE == stay)){STATE = stabling;}}

        if(!(key["R"] || key["L"])){dx = 0;} 
        if(!key["Up"])             {}
        if(!key["Down"])           {if (STATE == sit){STATE = stay;}    if(STATE == sneak){STATE = run;}}
        if(!key["G"])              if(STATE != stabling){if(STATE == legspin){STATE = run;} }
        if(!key["F"])              if(STATE != legspin){if(STATE == stabling){STATE = run;} }
    }

    void Animation(float time){
        if(STATE == stay){anim.set("стоит");} //stay, run, jump, sit, sneak, legspin, stabling
        if(STATE == run){anim.set("бег с оружием вперед");} //пока без оружия TODO
        if(STATE == jump){anim.set("прыжок");}
        if(STATE == sit){anim.set("сидит");}
        if(STATE == sneak){anim.set("крадется");}
        if(STATE == legspin){anim.set("вертушка1");}
        if(STATE == stabling){anim.set("поножовщина2");}
        if(STATE == falling){anim.set("неконтролируемое падение");}

        if(dir){anim.flip();}

        y -= anim.getH() - h;
        x -= anim.getW() - w;


        w = anim.getW();
        h = anim.getH();
        anim.tick(time);
    }

    sf::FloatRect getRect(){ return sf::FloatRect(x, y, w, h);}

    void Collision(int num, std::vector<TmxObject>& obj){
        for (int i = 0; i < obj.size(); ++i){
            if (getRect().intersects(obj[i].rect)){ // пересечение игрока с любым объектов
                if(obj[i].name == "solid"){  //встретились с "твердым" препятствием
                    canJump = false;
                    if (dy > 0 && num == 1) {y = obj[i].rect.top - h; dy  = 0; STATE = stay; canJump = true;}
                    if (dy < 0 && num == 1) {y = obj[i].rect.top + obj[i].rect.height; dy = 0; STATE = falling;}
                    if (dx > 0 && num == 0) {x = obj[i].rect.left - w;}
                    if (dx < 0 && num == 0) {x = obj[i].rect.left + obj[i].rect.width;}
                }
            }
        }
    }

    void update(float time, std::vector<TmxObject>& obj){
        KeyCheck();
        Animation(time);

        if(!canJump){dy += 0.002;}
        x += dx * time;
        Collision(0, obj);                           // CollitionX
        dy += 0.00005*time;
        y += dy * time;
        Collision(1, obj);                           // CollitionY


        key["R"] = key["L"] = key["Up"] = key["Down"] = key["F"] = key["G"] = false;
        // onGround = false;
    }

    void draw(sf::RenderWindow& window){
            anim.draw(window, x, y);
    }
};

#endif