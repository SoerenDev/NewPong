//
// Created by alex on 15.02.20.
//

#ifndef PONG_GAME_H
#define PONG_GAME_H
#include <SFML/Graphics.hpp>
#include "Ball.h"
#include "Paddle.h"


class Game {
public:
    sf::RenderWindow window;
    bool isRunning = true;
    void loadContent();
    void draw();
    void close();
    void update();
    void menuUpdate();
    void menuDraw();
    void gameplayUpdate();
    void gameplayDraw();
    void gameOverUpdate();
    void gameOverDraw();
    Game();
private:
    Ball *ball = new Ball(50,50);
    Paddle *paddle = new Paddle(500,500);
    sf::Clock clock;
    long deltatime;
    sf::Time delta;
    enum Gamestate {menu,gameplay,gameover};
    Gamestate gamestate = gameplay;
};


#endif //PONG_GAME_H
