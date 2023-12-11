#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include <iostream>
#include <string>
#include "../include/anim.hpp"
#include "../include/player.hpp"
#include "../lib/level/TmxLevel.h"
#include "../include/background.hpp"
#include "../include/view.hpp"
#include "../include/gamestatus.hpp"

void GamePlay(sf::RenderWindow* window, sf::Clock* clock, Player* hero, ParallaxBackground* background, Camera* camera, TmxLevel* lvl, std::vector<TmxObject>* obj, GameStatus* gs, sf::Clock* gclock);


#endif //GAMEPLAY_H