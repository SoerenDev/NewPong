//
// Created by alex on 15.02.20.
//

#include <SFML/Graphics/CircleShape.hpp>
#include "Ball.h"
#include "Paddle.h"


void Ball::draw(sf::RenderWindow &window) {
    window.draw(*ball);
}

void Ball::update(sf::RenderWindow &window, long deltatime, Paddle &paddle) {

    if (window.getSize().x < ball->getPosition().x + size * 2 && velocity.x > 0 ||
        ball->getPosition().x < 0 && velocity.x < 0) {
        velocity.x *= -1 * acceleration;
    }
    if ((ball->getGlobalBounds().intersects(paddle.paddle->getGlobalBounds())) && velocity.y > 0 ||
        ball->getPosition().y < 0 && velocity.y < 0) {
        velocity.y *= -1 * acceleration;
    }
    double delta = deltatime / 100.;
    position.x += velocity.x * delta;
    position.y += velocity.y * delta;
    ball->setPosition(position.x, position.y);
}

Ball::Ball(int x, int y) {
    ball = new sf::CircleShape(size);
    ball->setFillColor(sf::Color(255, 255, 255));
    ball->setPosition(sf::Vector2f(x, y));
    this->position.x = x;
    this->position.y = y;
}

bool Ball::GameOver(sf::RenderWindow &window) {
    return window.getSize().y < ball->getPosition().y;
}

Ball::~Ball() {
    delete ball;
}
