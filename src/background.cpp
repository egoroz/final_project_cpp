#include "../include/background.hpp"

ParallaxBackground::ParallaxBackground(const std::vector<std::string>& texturePaths) {
    int i = 0;
    for (const auto& path : texturePaths) {
        sf::Texture texture;
        if (!texture.loadFromFile(path)) {
            // Обработка ошибки
        }
        textures.push_back(texture);

        sf::Sprite sprite;
        sprite.setTexture(textures.back());
        sprites.push_back(sprite);

        parallaxFactors.push_back(1.0 + i++); // Можно изменить на нужное значение
    }
}

void ParallaxBackground::draw(sf::RenderWindow& window) {
    for (const auto& sprite : sprites) {
        window.draw(sprite);
    }
}

void ParallaxBackground::update(float dt) {
    for (size_t i = 0; i < sprites.size(); ++i) {
        // Обновление позиции спрайта для эффекта параллакса
        sprites[i].move(-dt*0.01 * parallaxFactors[i], 0);

        // Если спрайт вышел за пределы экрана, перемещаем его обратно
        if (sprites[i].getPosition().x + sprites[i].getGlobalBounds().width < 0) {
            sprites[i].setPosition(0, sprites[i].getPosition().y);
        }
    }
}