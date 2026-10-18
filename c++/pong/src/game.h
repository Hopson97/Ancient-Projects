#ifndef GAME_H
#define GAME_H

#include <vector>
#include <memory>

#include "button.h"
#include "gameobject.h"
#include "paddle.h"
#include "ball.h"

class Game
{
    public:
        Game();
    protected:
    private:
//Game States
        void menuState();
        void playLoop();


//End states
        void pollEvents();

    private:
        sf::RenderWindow window;
        sf::Event event;

        sf::Texture bgT;
        sf::Sprite bgS;

        void setBG(std::string path);
        void resetScreen();
};

#endif // GAME_H
