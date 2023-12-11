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
		return packet << ent.x << ent.y << ent.w << ent.h << ent.life << ent.dir << static_cast<int>(ent.STATE);;
	}

	friend sf::Packet& operator>>(sf::Packet& packet, Entity& ent)
	{
		int state;
		return packet >> ent.x >> ent.y >> ent.w >> ent.h >> ent.life >> ent.dir >> state;
		ent.STATE = static_cast<Entity::State>(state);
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
		health = health;
	}

};


#endif //ENTITY_H
