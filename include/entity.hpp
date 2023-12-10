#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "anim.hpp"
#include "../lib/level/TmxLevel.h"

class Entity
{
public:
	float x,y,dx,dy,w,h;
	AnimationManager anim;
	std::vector<TmxObject> obj;
	bool life, dir;
	float timer, timer_end;
	std::string name;
	int health;

	Entity(AnimationManager &anim,int x, int y): anim(anim), x(x), y(y)
	{
		dir = 0;

		life=true;
		timer=0;
		timer_end=0;
		dx=dy=0;
	}

	virtual void update(float time) = 0;

	void draw(RenderWindow &window)
	{
		anim.draw(window,x,y+h);
	}

	FloatRect getRect()
	{
		return FloatRect(x,y,w,h);
	}

	void option(std::string name_, float speed=0, int health_=1, std::string first_anim="")
	{
		name = name_;
		if (first_anim!="") anim.set(first_anim);
		w = anim.getW();
		h = anim.getH();
		dx = speed;
		health = health;
	}

};


#endif //ENTITY_H
