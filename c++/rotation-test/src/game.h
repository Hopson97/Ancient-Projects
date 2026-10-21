#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "Entites/Player/player.h"


class Game
{
    public:
        Game();
    protected:
    private:
        void gameLoop();    //The main game loop
};

#endif // GAME_H
