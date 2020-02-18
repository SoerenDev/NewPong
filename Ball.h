//
// Created by alex on 15.02.20.
//

#ifndef PONG_BALL_H
#define PONG_BALL_H


#include <SFML/Graphics/RenderWindow.hpp>
#include "Paddle.h"

class Ball {
public:
    Ball(int x, int y);
    void draw(sf::RenderWindow &window);
    void update(sf::RenderWindow &window, long deltatime, Paddle &paddle);
    bool GameOver(sf::RenderWindow &window);

private:
    sf::Vector2<float> position = sf::Vector2f(10.f,10.f);
    sf::Vector2<float> velocity = sf::Vector2f(30.f, 30.f);
    double size = 20.0;
    sf::CircleShape *ball;

};


#endif //PONG_BALL_H
