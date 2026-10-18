#ifndef GAME_H
#define GAME_H

#include "entity.h"
#include "zombie.h"
#include "player.h"

#include "resourcemanager.h"

#include <vector>
#include <memory>

class Game
{
    public:
        Game();
    private:
        void mainLoop();

        void events();

        void update();
    private:
        sf::RenderWindow window;
        std::vector<std::unique_ptr<Entity>> entities;
};

#endif // GAME_H
