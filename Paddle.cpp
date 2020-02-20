//
// Created by alex on 18.02.20.
//

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "Paddle.h"

Paddle::Paddle(int x, int y) {
    this->position.x = x;
    this->position.y = y;
    paddle = new sf::RectangleShape(sf::Vector2f(width, height));
    paddle->setFillColor(sf::Color(255, 255, 255));
    paddle->setPosition(sf::Vector2f(x, y));
}

void Paddle::draw(sf::RenderWindow &window) {
    window.draw(*paddle);
}

void Paddle::update(sf::RenderWindow &window, long deltatime) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && 0 < paddle->getPosition().x) {
        velocity = -100;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) &&
               window.getSize().x > paddle->getPosition().x + width) {
        velocity = 100;
    } else {
        velocity = 0;
    }

    double delta = deltatime / 100.;
    position.x += velocity * delta;
    paddle->setPosition(position);
}

Paddle::~Paddle() {
    delete paddle;
}
