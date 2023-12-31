#ifndef GAMEPLAY_H
#define GAMEPLAY_H
#include <SFML/Network.hpp>
#include <iostream>
#include <string>
#include "../include/anim.hpp"
#include "../include/player.hpp"
#include "../lib/level/TmxLevel.h"
#include "../include/background.hpp"
#include "../include/view.hpp"
#include "../include/gamestatus.hpp"
#include "../include/target.hpp"

void GamePlay(sf::RenderWindow* window, sf::Clock* clock, Player* hero1, AnimationManager* anim, ParallaxBackground* background, Camera* camera, TmxLevel* lvl, std::vector<TmxObject>* obj, GameStatus* gs, sf::Clock* gclock, sf::UdpSocket* clientSocket, sf::IpAddress* serverAddress,unsigned short* serverPort, Target* target);


#endif //GAMEPLAY_H