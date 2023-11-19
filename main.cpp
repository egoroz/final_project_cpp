#include <SFML/Graphics.hpp>
//TODO audio

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "name project"); 
    sf::Image heroimage;
    heroimage.loadFromFile("images/heroes/soviet_man.png");

    sf::Image mapimage;
    mapimage.loadFromFile("images/objects/map.png");

    sf::Texture herotexture;
    herotexture.loadFromImage(heroimage);

    sf::Texture maptexture;
    maptexture.loadFromImage(mapimage);

    sf::Sprite herosprite;
    herosprite.setTexture(herotexture);
    herosprite.setTextureRect(sf::IntRect(150, 30, -150, 170)); //first way unfold the charecter - to use negative coords
    herosprite.setPosition(0, 0);

    sf::Sprite mapsprite;
    mapsprite.setTexture(maptexture);
    mapsprite.setPosition(0, 0);

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

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {mapsprite.move(-1.1, 0);}
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {mapsprite.move(1.1, 0);}
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {mapsprite.move(0, -1.1);}
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {mapsprite.move(0, 1.1);}


        window.clear();
        window.draw(mapsprite);
        window.draw(herosprite);
        window.display();
    }

    return 0;
}