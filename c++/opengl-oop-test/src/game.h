#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>

#include "cube.h"
#include "glewinitiliser.h"

#include "cube.h"

class Game
{
    public:
        Game();
        void    runGame();

    private:
        sf::Window mWindow;
        glewInitiliser initGlew;

        void    pollEvents  ();
        void    addCubes    (SquareShader& s);
        std::vector<Cube> mCubes;
};

#endif // GAME_H
