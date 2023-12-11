#ifndef BULLET_H
#define BULLET_H

#include "entity.hpp"


class Bullet: public Entity
{
public:

	Bullet(AnimationManager &anim_, int x, int y):Entity(anim_, x, y)
	{	
		std::cerr << "ctor\n";
		//option("Bullet", 0.3, 10, "move");
		std::cerr << "ctor\n";
		// if (dir) dx=-0.3;
	}
 
	void update(float time, std::vector<TmxObject>& obj)
	{
		x+=dx*time;

		for (int i=0;i<obj.size();i++)
			if (getRect().intersects(obj[i].rect))
		        {
					//Health=0;
				}

		// if (Health<=0) {anim.set("explode");dx=0;
		//                 if (anim.isPlaying()==false) life=false;
		//                 }

		anim.tick(time);
	}

};

#endif //BULLET_H