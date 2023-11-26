#ifndef ANIM_H
#define ANIM_H

#include<SFML/Graphics.hpp>
#include<iostream>
#include<string>

class Animation{
    public:
    std::vector<sf::IntRect> frames, frames_flip;
    float currentFrame, speed;
    bool flip, isPlaying;
    sf::Sprite sprite;

    Animation(){
        currentFrame = 0;
        isPlaying = true;
        flip = false;

    }

    Animation(sf::Texture & t, int x, int y, int w, int h, int count, float speed, int step):speed(speed){
        
        sprite.setTexture(t);

        currentFrame = 0;
        isPlaying = true;
        flip = false;

        for (int i = 0; i < count; ++i){
            frames.push_back(sf::IntRect(x + i*step, y, w, h));
            frames_flip.push_back(sf::IntRect(x+i*step + w, y, -w, h));
        }
    }

    void tick(float time){
        if(!isPlaying) {return;}

        currentFrame += speed * time;
        if(currentFrame > frames.size()){currentFrame -= frames.size();}

        int i = currentFrame;
        sprite.setTextureRect(frames[i]);
        if(flip){sprite.setTextureRect(frames_flip[i]);}

    }
};

class AnimationManager{
    public:
    std::string currentAnim;
    std::map<std::string, Animation> animList;

    AnimationManager(){}

    void create(std::string name, sf::Texture & t, int x, int y, int w, int h, int count, float speed, int step){
        animList[name] = Animation(t, x, y, w, h, count, speed, step);
        currentAnim = name;
    }

    void draw(sf::RenderWindow& window, int x = 0, int y = 0){
        animList[currentAnim].sprite.setPosition(x, y);
        window.draw(animList[currentAnim].sprite);
    }

    void set(std::string name) {currentAnim = name;}

    void flip(bool b)          {animList[currentAnim].flip = b;}

    void tick(float time)      {animList[currentAnim].tick(time);}

    void pause()               {animList[currentAnim].isPlaying = false;}

    void play()                {animList[currentAnim].isPlaying = true;}
};


#endif