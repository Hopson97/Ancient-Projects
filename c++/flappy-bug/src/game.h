#ifndef GAME_H
#define GAME_H


#include <SFML/Graphics.hpp>

#include "global.h"
#include "bird.h"

class Game
{
    public:
        Game();
    protected:
    private:
        void mainLoop();
        void prePlayState();

        void handleWinEvents();

    private:
        sf::RenderWindow window;
        sf::Event eventHandler;

};

#endif // GAME_H
