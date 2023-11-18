#include <SFML/Graphics.hpp>
//TODO audio

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "name project"); 
    sf::Image heroimage;
    heroimage.loadFromFile("images/heroes/soviet_man.png");

    sf::Texture herotexture;
    herotexture.loadFromImage(heroimage);

    sf::Sprite herosprite;
    herosprite.setTexture(herotexture);
    herosprite.setTextureRect(sf::IntRect(150, 30, -150, 170)); //first way unfold the charecter - to use negative coords
    herosprite.setPosition(0, 0);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))  {herosprite.move(-1.1, 0); herosprite.setTextureRect(sf::IntRect(150, 30, -150, 170)); }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {herosprite.move(1.1, 0);  herosprite.setTextureRect(sf::IntRect(0, 30, 150, 170));}
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))    {herosprite.move(0, -1.1); herosprite.setTextureRect(sf::IntRect(150, 30, -150, 170));}
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))  {herosprite.move(0, 1.1);  herosprite.setTextureRect(sf::IntRect(0, 30, 150, 170));}


        window.clear();
        window.draw(herosprite);
        window.display();
    }

    return 0;
}