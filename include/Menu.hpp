#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

enum status {Menu, Play, Results};

void InitText(sf::Text& mtext, float xpos, float ypos, const sf::String str, int size_font, sf::Color menu_text_color = sf::Color::White, int bord = 0, sf::Color menu_border_color = sf::Color::Black);

class GameStatus{
private:
    status stat;
public:
    GameStatus(){
        stat = Menu;
    }

    status GetGameStatus(){
        return stat;
    }

    void ChangeGameStatus(status st_){
        stat = st_;
    }
};

class GMenu{
private:
    float menu_X;                                     
    float menu_Y;				                      
    int menu_Step;                                    
    int max_menu;                                     
    int size_font;                                    
    int mainMenuSelected;                             
    std::vector<sf::Text> mainMenu;                   
    sf::RenderWindow window_;
    sf::Color menu_text_color = sf::Color::White;      
    sf::Color chose_text_color = sf::Color::Yellow;    
    sf::Color border_color = sf::Color::Black;         

    void setInitText(sf::Text& text, const sf::String& str, float xpos, float ypos);

    sf::Texture texture_window;
    sf::Font menu_font;
    sf::Text Titul;
    sf::RectangleShape* bck_ptr;
public:

    GMenu(){
        
        window_.create(sf::VideoMode::getDesktopMode(), "Menu screen", sf::Style::Fullscreen);
        window_.setMouseCursorVisible(false);
        auto width = static_cast<float>(sf::VideoMode::getDesktopMode().width);
        auto height = static_cast<float>(sf::VideoMode::getDesktopMode().height);
        bck_ptr = new sf::RectangleShape {sf::Vector2f(width, height)};
        
        if(!texture_window.loadFromFile("../src/menu/1.jpg")) std::terminate();
        (*bck_ptr).setTexture(&texture_window);
        
        if(!menu_font.loadFromFile("../src/menu/2.otf"))std::terminate();
        
        Titul.setFont(menu_font);
        InitText(Titul, 480, 50, L"CheloFight", 150, sf::Color::White, 3);
    }

    ~GMenu(){
        delete bck_ptr;
    }

    void draw();                                     

    void MoveUp();                                   

    void MoveDown();                                 

    
    void setColorTextMenu(sf::Color menColor, sf::Color ChoColor, sf::Color BordColor);

    void AlignMenu(int posx);       

    int getSelectedMenuNumber() const     
    {
        return mainMenuSelected;
    }

    void execute(){
        while(window_.isOpen()){
            sf::Event event;
            while(window_.pollEvent(event)){
                if(event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape) window_.close();
            }
            window_.clear();
            window_.draw(*(bck_ptr));
            window_.draw(Titul);
            
            window_.display();
        }
    }
};

void InitText(sf::Text& mtext, float xpos, float ypos, const sf::String str, int size_font, sf::Color menu_text_color, int bord , sf::Color menu_border_color){
    mtext.setCharacterSize(size_font);
    mtext.setPosition(xpos, ypos);
    mtext.setString(str);
    mtext.setFillColor(menu_text_color);
    mtext.setOutlineThickness(bord);
    mtext.setOutlineColor(menu_border_color);
}

void GMenu::setInitText(sf::Text& text, const sf::String& str, float xpos, float ypos){
    text.setFont(menu_font);
	text.setFillColor(menu_text_color);
	text.setString(str);
	text.setCharacterSize(size_font);
	text.setPosition(xpos, ypos);
	text.setOutlineThickness(3);
	text.setOutlineColor(border_color);
}

void GMenu::AlignMenu(int posx){
    float nullx = 0;

	for (int i = 0; i < max_menu; i++) {

		switch (posx)
		{
		case 0:
			nullx = 0;
			break;
		case 1:
			nullx = mainMenu[i].getLocalBounds().width;
			break;
		case 2:
			nullx = mainMenu[i].getLocalBounds().width / 2;
			break;
		default:break;
		}

		mainMenu[i].setPosition(mainMenu[i].getPosition().x - nullx, mainMenu[i].getPosition().y);
	}

}