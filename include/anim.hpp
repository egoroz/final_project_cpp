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

  Animation()
  {
    currentFrame = 0;
    isPlaying=true;
    flip=false;
    loop=true;
  }

  void tick(float time)
  {
    if (!isPlaying) return;

    currentFrame += speed * time;

    if (currentFrame > frames.size()) { currentFrame -= frames.size();
                                        if (!loop) {isPlaying=false; return;}
                                      }

    int i = currentFrame;
    sprite.setTextureRect( frames[i] );
    if (flip) sprite.setTextureRect( frames_flip[i] );
  }

};



class AnimationManager
{

public:
    std::string currentAnim;
  std::map<std::string, Animation> animList;

  AnimationManager()
  {}

  ~AnimationManager()
  { animList.clear();
  }


  void create(std::string name, sf::Texture &texture, int x, int y, int w, int h, int count, float speed, int step=0, bool Loop=true)
  {
    Animation a;
    a.speed = speed;
    a.loop = Loop;
    a.sprite.setTexture(texture);
    a.sprite.setOrigin(0,0);

    for (int i=0;i<count;i++)
    {
      a.frames.push_back( sf::IntRect(x+i*step, y, w, h)  );
      a.frames_flip.push_back( sf::IntRect(x+i*step+w, y, -w, h)  );
    }
    animList[name] = a;
    currentAnim = name;
  }


  void set(std::string name)
  {
    currentAnim = name;
    animList[currentAnim].flip=0;
  }

  void draw(sf::RenderWindow &window,int x=0, int y=0)
  {
    animList[currentAnim].sprite.setPosition(x,y);
    window.draw( animList[currentAnim].sprite );
  }

  void flip(bool b=1) {animList[currentAnim].flip = b;}

  void tick(float time)   {animList[currentAnim].tick(time);}

  void pause() {animList[currentAnim].isPlaying=false;}

  void play()  {animList[currentAnim].isPlaying=true;}

  void play(std::string name)  {animList[name].isPlaying=true;}

  bool isPlaying()  {return animList[currentAnim].isPlaying;}

  float getH()  {return animList[currentAnim].frames[0].height;}

  float getW() {return animList[currentAnim].frames[0].width;}

  void loadFromFile(std::string fileName, sf::Texture &t){ // Приминает путь к файлу формата XML
    using namespace tinyxml2;
    XMLDocument animFile;
    animFile.LoadFile(fileName.c_str());

    XMLElement *head;
    head = animFile.FirstChildElement("sprites");

    XMLElement *animElement;
    animElement = head->FirstChildElement("animation");
    while(animElement){
      Animation anim;
      currentAnim = animElement->Attribute("title");
      int delay = atoi(animElement->Attribute("delay"));
      anim.speed = 1.0/delay; anim.sprite.setTexture(t);

      XMLElement *cut;
      cut = animElement->FirstChildElement("cut");
      while(cut){
        int x = atoi(cut->Attribute("x"));
        int y = atoi(cut->Attribute("y"));
        int w = atoi(cut->Attribute("w"));
        int h = atoi(cut->Attribute("h"));

        anim.frames.push_back(sf::IntRect(x, y, w, h));
        anim.frames_flip.push_back(sf::IntRect(x + w, y, -w, h));
        cut = cut->NextSiblingElement("cut");
      }

      // anim.sprite.setOrigin(0,anim.frames[0].height);
    animList[currentAnim] = anim;
    animElement = animElement->NextSiblingElement("animation");
    }
    

  }
};

#endif