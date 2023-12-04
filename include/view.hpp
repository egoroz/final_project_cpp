
#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <SFML/Graphics.hpp>

class Camera {
public:
    Camera(float width, float height);
    void update(const sf::Vector2f& target);
    void applyTo(sf::RenderWindow& window);

private:
    sf::View view;
};

#endif // CAMERA_HPP