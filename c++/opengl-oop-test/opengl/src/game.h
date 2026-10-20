#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>

#include "cube.h"
#include "glewinitiliser.h"

class Game
{
    public:
        Game();
        void    runGame();

    private:
        sf::Window mWindow;
        glewInitiliser initGlew;

        void    pollEvents();
        Cube myCube;
};

#endif // GAME_H
