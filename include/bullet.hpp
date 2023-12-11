#ifndef BULLET_H
#define BULLET_H

#include "Entity.hpp"


class Bullet: public Entity
{
public:

	Bullet(AnimationManager &anim_, Level &lvl,int x,int y,bool dir):Entity(anim_, lvl, x, y)
	{
		option("Bullet", 0.3, 10, "move");
		if (dir) dx=-0.3;
	}

	void update(float time)
	{
		x+=dx*time;

		for (int i=0;i<obj.size();i++)
			if (getRect().intersects(obj[i].rect))
		        {Health=0;}

		if (Health<=0) {anim.set("explode");dx=0;
		                if (anim.isPlaying()==false) life=false;
		                }

		anim.tick(time);
	}

};

#ifndef //BULLET_H