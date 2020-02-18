//
// Created by alex on 15.02.20.
//

#include "Game.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Game::Game() {
    window.create(sf::VideoMode(800, 600), "Pong");
    window.setFramerateLimit(60);
}

void Game::loadContent() {}

void Game::update() {
    delta = clock.getElapsedTime();
    deltatime = delta.asMilliseconds();
    clock.restart();
    close();
    switch(gamestate) {
        case menu: break;
        case gameplay: gameplayUpdate(); break;
        case gameover: gameOverUpdate(); break;
    }

}

void Game::draw() {
    window.clear();
    switch(gamestate) {
        case menu: break;
        case gameplay: gameplayDraw(); break;
        case gameover: gameOverDraw(); break;
    }
    window.display();
}

void Game::close() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            isRunning = false;
        }
    }
}

void Game::menuUpdate() {

}

void Game::menuDraw() {

}

void Game::gameplayUpdate() {
    ball->update(window, deltatime,*paddle);
    paddle->update(window,deltatime);
    if(ball->GameOver(window)) {
        gamestate = gameover;
        delete ball;
    }
}

void Game::gameplayDraw() {
    ball->draw(window);
    paddle->draw(window);
}

void Game::gameOverUpdate() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        gamestate = gameplay;
        ball = new Ball(50,50);
    }
}

void Game::gameOverDraw() {
    window.clear(sf::Color::White);
}
