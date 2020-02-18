//
// Created by alex on 18.02.20.
//

#ifndef PONG_PADDLE_H
#define PONG_PADDLE_H


#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

class Paddle {
public:
    Paddle(int x, int y);
    void draw(sf::RenderWindow &window);
    void update(sf::RenderWindow &window, long deltatime);
    sf::RectangleShape *paddle;
private:
    sf::Vector2<float> position = sf::Vector2f(10.f,10.f);
    float velocity = 0;
    int height = 20;
    int width = 80;


};


#endif //PONG_PADDLE_H
