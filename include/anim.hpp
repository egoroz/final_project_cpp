#ifndef ANIM_H
#define ANIM_H

#include <SFML/Graphics.hpp>
#include "../lib/tinyxml2/tinyxml2.h"


class Animation
{
public:
  std::vector<sf::IntRect> frames, frames_flip;
  float currentFrame, speed;
  bool loop, flip, isPlaying;
  sf::Sprite sprite;

  Animation();
  

  void tick(float time);

};



class AnimationManager
{

public:
  std::string currentAnim;
  std::map<std::string, Animation> animList;

  AnimationManager(){}
  

  ~AnimationManager()
  { animList.clear();
  }


  void create(std::string name, sf::Texture &texture, int x, int y, int w, int h, int count, float speed, int step=0, bool Loop=true);



  void set(std::string name);
  

  void draw(sf::RenderWindow& window,int x=0, int y=0);
  

  void flip(bool b=1) {animList[currentAnim].flip = b;}

  void tick(float time)   {animList[currentAnim].tick(time);}

  void pause() {animList[currentAnim].isPlaying=false;}

  void play()  {animList[currentAnim].isPlaying=true;}

  void play(std::string name)  {animList[name].isPlaying=true;}

  bool isPlaying()  {return animList[currentAnim].isPlaying;}

  float getH()  {return animList[currentAnim].frames[0].height;}

  float getW() {return animList[currentAnim].frames[0].width;}

  void loadFromFile(std::string fileName, sf::Texture &t); // Приминает путь к файлу формата XML
};

#endif