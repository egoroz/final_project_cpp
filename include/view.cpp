#include "Camera.hpp"

Camera::Camera(float width, float height) {
    view.setSize(width, height);
}

void Camera::update(const sf::Vector2f& target) {
    view.setCenter(target);
}

void Camera::applyTo(sf::RenderWindow& window) {
    window.setView(view);
}