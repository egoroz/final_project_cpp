#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "anim.hpp"
#include "../lib/level/TmxLevel.h"

class Entity
{
public:
    //std::vector<TmxObject> obj;//вектор объектов карты
    float x, y, dx, dy, w, h;
    AnimationManager anim;
    bool life, dir;
    
    

    enum State {stay, run, jump, sit, sneak, legspin, stabling, falling} STATE; //sneak - крадется legspin - вертушка stabling - поножовщина
    std::map<std::string, bool> key;
	float timer, timer_end;
	std::string name;
	int health;


	friend sf::Packet& operator<<(sf::Packet& packet, const Entity& ent)
	{
		std::string state;
		if (ent.STATE == stay) {
			state = "stay";
		} else if (ent.STATE == run) {
			state = "run";
		} else if (ent.STATE == jump) {
			state = "jump";
		} else if (ent.STATE == sit) {
			state = "sit";
		} else if (ent.STATE == sneak) {
			state = "sneak";
		} else if (ent.STATE == legspin) {
			state = "legspin";
		} else if (ent.STATE == stabling) {
			state = "stabling";
		} else if (ent.STATE == falling) {
			state = "falling";
		}
		std::cout<<"send: "<<ent.STATE<<std::endl;
		return packet << ent.x << ent.y << ent.w << ent.h << ent.life << ent.dir << state;
	}

	friend sf::Packet& operator>>(sf::Packet& packet, Entity& ent)
	{
		std::string state;
		packet >> ent.x >> ent.y >> ent.w >> ent.h >> ent.life >> ent.dir >> state;
		std::cout<<state<<std::endl;
		if (state == "stay") {
			ent.STATE = stay;
		} else if (state == "run") {
			ent.STATE = run;
		} else if (state == "jump") {
			ent.STATE = jump;
		} else if (state == "sit") {
			ent.STATE = sit;
		} else if (state == "sneak") {
			ent.STATE = sneak;
		} else if (state == "legspin") {
			ent.STATE = legspin;
		} else if (state == "stabling") {
			ent.STATE = stabling;
		} else if (state == "falling") {
			ent.STATE = falling;
		}
		std::cout<<"received: "<<ent.STATE<<' '<<state<<std::endl;
		return packet;
	}


	Entity(const AnimationManager &anim, int x=550, int y=800): anim(anim), x(x), y(y)
	{
        //obj = lvl.GetAllObjects("solid");
		dir = 0;

		life = true;
		timer = 0;
		timer_end = 0;
		dx = dy = 0;
	}

	virtual void update(float time, std::vector<TmxObject>& obj) = 0;

	void draw(sf::RenderWindow &window)
	{
		anim.draw(window,x,y);
	}

	sf::FloatRect getRect()
	{
		return sf::FloatRect(x,y,w,h);
	}

	void option(std::string name_, float speed=0, int health_=1, std::string first_anim="")
	{
		name = name_;
		if (first_anim!="") anim.set(first_anim);
		w = anim.getW();
		h = anim.getH();
		//dx = speed;
		health = health_;
	}

};


#endif //ENTITY_H
