#include "../include/Menu.hpp"
#include <random>

void InitText(sf::Text& mtext, float xpos, float ypos, const sf::String str, int size_font, sf::Color menu_text_color, int bord , sf::Color menu_border_color){
    mtext.setCharacterSize(size_font);
    mtext.setPosition(xpos, ypos);
    mtext.setString(str);
    mtext.setFillColor(menu_text_color);
    mtext.setOutlineThickness(bord);
    mtext.setOutlineColor(menu_border_color);
}

GMenu::GMenu(float menux, float menuy, int sizeFont, int step, std::vector<sf::String>& name, sf::RenderWindow* win, sf::String arr):menu_X(menux), menu_Y(menuy), menu_Step(step), max_menu(static_cast<int>(name.size())), size_font(sizeFont), mainMenu(name.size()), window_(win), arrows(name.size())
    {
        
        window_->create(sf::VideoMode::getDesktopMode(), "Menu screen", sf::Style::Fullscreen);
        window_->setMouseCursorVisible(false);
        auto width = static_cast<float>(sf::VideoMode::getDesktopMode().width);
        auto height = static_cast<float>(sf::VideoMode::getDesktopMode().height);
        bck_ptr = new sf::RectangleShape {sf::Vector2f(width, height)};
        
        if(!texture_window.loadFromFile("../src/menu/1.jpg")) std::terminate();
        (*bck_ptr).setTexture(&texture_window);
        
        if(!menu_font.loadFromFile("../src/menu/2.otf"))std::terminate();
        
        Titul.setFont(menu_font);
        InitText(Titul, 380, 50, L"CheloFight", 150, sf::Color::White, 3);

        for (int i = 0, ypos = static_cast<int>(menu_Y); i < max_menu; i++, ypos += menu_Step)
		setInitText(mainMenu[i], name[i], menu_X, static_cast<float>(ypos));
        mainMenuSelected = 0;
        mainMenu[mainMenuSelected].setFillColor(chose_text_color);
        
        for (int i = 0, ypos = static_cast<int>(menu_Y); i < max_menu; i++, ypos += menu_Step)
        setInitText(arrows[i], arr, menu_X-60, static_cast<float>(ypos));
        arrows[mainMenuSelected].setFillColor(sf::Color::White);
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

void GMenu::MoveUp()
{
	mainMenuSelected--;

	if (mainMenuSelected >= 0) {
		mainMenu[mainMenuSelected].setFillColor(chose_text_color);
		mainMenu[mainMenuSelected + 1].setFillColor(menu_text_color);
        arrows[mainMenuSelected].setFillColor(sf::Color::White);
        arrows[mainMenuSelected+1].setFillColor(sf::Color(255, 255, 255, 0));
	}
	else
	{
		mainMenu[0].setFillColor(menu_text_color);
		mainMenuSelected = max_menu - 1;
		mainMenu[mainMenuSelected].setFillColor(chose_text_color);
        arrows[0].setFillColor(sf::Color(255, 255, 255, 0));
        arrows[mainMenuSelected].setFillColor(sf::Color::White);
	}
}

void GMenu::MoveDown()
{
	mainMenuSelected++;

	if (mainMenuSelected < max_menu) {
		mainMenu[mainMenuSelected - 1].setFillColor(menu_text_color);
		mainMenu[mainMenuSelected].setFillColor(chose_text_color);
        arrows[mainMenuSelected].setFillColor(sf::Color::White);
        arrows[mainMenuSelected-1].setFillColor(sf::Color(255, 255, 255, 0));
	}
	else
	{
		mainMenu[max_menu - 1].setFillColor(menu_text_color);
		mainMenuSelected = 0;
		mainMenu[mainMenuSelected].setFillColor(chose_text_color);
        arrows[max_menu-1].setFillColor(sf::Color(255, 255, 255, 0));
        arrows[mainMenuSelected].setFillColor(sf::Color::White);
	}

}

void GMenu::draw()
{
	for (int i = 0; i < max_menu; i++) window_->draw(mainMenu[i]);
    for (int i = 0; i < max_menu; i++) window_->draw(arrows[i]);
}

void GMenu::setColorTextMenu(sf::Color menColor, sf::Color ChoColor, sf::Color BordColor)
{
	menu_text_color = menColor;
	chose_text_color = ChoColor;
	border_color = BordColor;

	for (int i = 0; i < max_menu; i++) {
		mainMenu[i].setFillColor(menu_text_color);
		mainMenu[i].setOutlineColor(border_color);
	}

	mainMenu[mainMenuSelected].setFillColor(chose_text_color);
}

void GMenu::setColorArrowMenu(){
    for (int i = 0; i < max_menu; i++) {
		arrows[i].setFillColor(sf::Color(255, 255, 255, 0));
		arrows[i].setOutlineColor(sf::Color::Black);
	}

	arrows[mainMenuSelected].setFillColor(sf::Color::White);
}

void GameStart(GameStatus* stat, sf::Clock* GlobalClock){
    stat->ChangeGameStatus(Play);
    GlobalClock->restart();
}


void GMenu::execute(GameStatus* status, sf::Clock* GlobalClock, Player* hero){
        
            sf::Event event;
            while(window_->pollEvent(event)){
                if(event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape) window_->close();
                if (event.type == sf::Event::KeyReleased)
                {
                    
                    if (event.key.code == sf::Keyboard::W) { MoveUp(); }       
                    if (event.key.code == sf::Keyboard::S) { MoveDown(); }  
                    if (event.key.code == sf::Keyboard::Return)                                     
                    {
                        
                        
                        switch (getSelectedMenuNumber())
                        {
                        case 0:GameStart(status, GlobalClock);  break;
                        case 1:window_->close(); break;
                        default:break;
                        }
                        
                    }
                }
            
            window_->clear();
            window_->draw(*(bck_ptr));
            window_->draw(Titul);
            draw();
            window_->display();
        }
    }

void GResults::execute(GameStatus* status, sf::Clock* GlobalClock, Player* hero, int a_){
            
            sf::Event event;
            while(window_->pollEvent(event)){
                if(event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape) window_->close();
                if (event.type == sf::Event::KeyReleased)
                {
                    
                    if (event.key.code == sf::Keyboard::W) { MoveUp(); }       
                    if (event.key.code == sf::Keyboard::S) { MoveDown(); }  
                    if (event.key.code == sf::Keyboard::Return)                                     
                    {
                        
                        
                        switch (getSelectedMenuNumber())
                        {
                        case 0:window_->close(); break;
                        case 1:window_->close(); break;
                        default:break;
                        }
                        
                    }
                }
            
            Titul.setFont(menu_font);
            std::string str = "Winner is: ";
            str.push_back(a_);
            InitText(Titul, 380, 1000, str, 150, sf::Color::White, 3);
            window_->clear();
            window_->draw(*(bck_ptr));
            window_->draw(Titul);
            draw();
            window_->display();
        }
    }
