#ifndef GAME_H
#define GAME_H
#include "wall.h"

#include <vector>

class Game
{
    public:
        Game();
    protected:
    private:
        void loop();
        void events();

        sf::RenderWindow window;
        sf::Event event;

        std::vector<Wall>walls;

        bool drawingWall;

        int frame;
};

#endif // GAME_H
