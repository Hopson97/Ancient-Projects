#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>

#include <string>
#include <vector>
#include <memory>
#include <iostream>

#include "brick.h"
#include "gameobject.h"
#include "ball.h"
#include "paddle.h"

class Game
{
    public:
        Game();
    private:
        void loop();
        void handleEvents();

        void addBricks();
        void collisions();

    private:
        sf::RenderWindow window;
        sf::Event event;

        std::vector<std::unique_ptr<GameObject>> objs;
        Paddle paddle;
        Ball ball;
};

#endif // GAME_H
