#ifndef PARALLAX_BACKGROUND_HPP
#define PARALLAX_BACKGROUND_HPP

#include <SFML/Graphics.hpp>
#include <vector>

class ParallaxBackground {
public:
    ParallaxBackground(const std::vector<std::string>& texturePaths);
    void draw(sf::RenderWindow& window);
    void update(float dt);

private:
    std::vector<sf::Texture> textures;
    std::vector<sf::Sprite> sprites;
    std::vector<float> parallaxFactors;
};

#endif // PARALLAX_BACKGROUND_HPP
