#include <SFML/Graphics.hpp>
#include "Game.h"
int main()
{
    Game *game = new Game();
    game->loadContent();
    while(game->isRunning) {
        game->update();
        game->draw();
    }
    delete game;
    return 0;
}

