#ifndef BULLET_H
#define BULLET_H

#include "entity.hpp"


class Bullet: public Entity
{
public:

	Bullet(AnimationManager &anim_, int x, int y, bool dir_):Entity(anim_, x, y)
	{	
		dir = dir_;
		std::cerr << "ctor\n";
		option("Bullet", 0.3, 10, "Bullet");
		std::cerr << "ctor\n";
		// if (dir) dx=-0.3;
	}
	
 
	void update(float time, std::vector<TmxObject>& obj)
	{
		//TODO
	}

};

#endif //BULLET_H