#pragma once

#include <SFML/Graphics.hpp>
#include<iostream>
#include "gamestatus.hpp"
#include "player.hpp"

void InitText(sf::Text& mtext, float xpos, float ypos, const sf::String str, int size_font, sf::Color menu_text_color = sf::Color::White, int bord = 0, sf::Color menu_border_color = sf::Color::Black);



class GMenu{
private:
    float menu_X;                                     
    float menu_Y;				                      
    int menu_Step;                                    
    int max_menu;                                     
    int size_font;                                    
    int mainMenuSelected;                             
    std::vector<sf::Text> mainMenu;
    std::vector<sf::Text> arrows;                   
    sf::Color menu_text_color = sf::Color::White;      
    sf::Color chose_text_color = sf::Color::Yellow;    
    sf::Color border_color = sf::Color::Black;         

    void setInitText(sf::Text& text, const sf::String& str, float xpos, float ypos);

    sf::Texture texture_window;
    sf::Font menu_font;
    
protected:
    sf::Text Titul;
    sf::RenderWindow* window_;
    sf::RectangleShape* bck_ptr;
public:
    
    GMenu(float menux, float menuy, int sizeFont, int step, std::vector<sf::String>& name, sf::RenderWindow* win, sf::String arr);
    
        
        
    ~GMenu(){
        delete bck_ptr;
    }

    void AlignMenu(int posx);     


    void draw();                                     

    void MoveUp();                                   

    void MoveDown();                                 

    
    void setColorTextMenu(sf::Color menColor, sf::Color ChoColor, sf::Color BordColor);
    
    void setColorArrowMenu();
    
    int getSelectedMenuNumber() const     
    {
        return mainMenuSelected;
    }



    virtual void execute(GameStatus* status, sf::Clock* GlobalClock, Player* hero);
};

class GResults: public GMenu{
private:
    int* winner;
public:
    GResults(float menux, float menuy, int sizeFont, int step, std::vector<sf::String>& name, sf::RenderWindow* win, sf::String arr, int*win_): GMenu(menux, menuy, sizeFont, step, name, win, arr), winner(win_)
    {
        InitText(Titul, 380, 50, L"GoodGame!", 150, sf::Color::White, 3);
    }

    void execute(GameStatus* status, sf::Clock* GlobalClock, Player* hero) override;
};



