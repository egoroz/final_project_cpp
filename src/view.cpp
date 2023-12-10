#include "../include/view.hpp"

Camera::Camera(float width, float height) {
    view.setSize(width, height);
}


void Camera::update(const sf::Vector2f& target) {
    sf::Vector2f currentPosition = view.getCenter();
    float interpolationFactor = 0.15f;
    sf::Vector2f newPosition = currentPosition + interpolationFactor * (target - currentPosition);
    view.setCenter(newPosition);
}

void Camera::applyTo(sf::RenderWindow&window) {
    window.setView(view);
}