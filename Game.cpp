//
// Created by alex on 15.02.20.
//

#include "Game.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Game::Game() {
    window.create(sf::VideoMode(800, 600), "Pong");
    window.setFramerateLimit(60);
    ball = new Ball(50,50);
    paddle = new Paddle(500,500);
}

void Game::loadContent() {
    font.loadFromFile("/home/alex/CLionProjects/Pong/devgothic.TTF");
    text.setFont(font);
    text.setCharacterSize(40);
    text.setFillColor(sf::Color::Yellow);
    text.setPosition(window.getSize().x/2-text.getCharacterSize()*2,window.getSize().y/2);
    text.setStyle(sf::Text::Bold);
}

void Game::update() {
    delta = clock.getElapsedTime();
    deltatime = delta.asMilliseconds();
    clock.restart();
    close();
    switch(gamestate) {
        case menu: menuUpdate(); break;
        case gameplay: gameplayUpdate(); break;
        case gameover: gameOverUpdate(); break;
    }
}

void Game::draw() {
    window.clear();
    switch(gamestate) {
        case menu: menuDraw(); break;
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
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        gamestate = gameplay;
    }
}

void Game::menuDraw() {
    text.setString("Press Enter");
    window.draw(text);
}

void Game::gameplayUpdate() {
    ball->update(window, deltatime,*paddle);
    paddle->update(window,deltatime);
    if(ball->GameOver(window)) {
        gamestate = gameover;
        delete ball;
        delete paddle;
    }
}

void Game::gameplayDraw() {
    ball->draw(window);
    paddle->draw(window);
}

void Game::gameOverUpdate() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        gamestate = gameplay;
        ball = new Ball(50,50);
        paddle = new Paddle(500,500);
    }
}

void Game::gameOverDraw() {
    text.setString("Game Over");
    window.draw(text);
}

Game::~Game() {
    delete ball;
    delete paddle;
}
