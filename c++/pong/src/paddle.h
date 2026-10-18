#ifndef PADDLE_H
#define PADDLE_H

#include <SFML/Graphics.hpp>
#include "gameobject.h"

#include "ball.h"

enum pType
{
    PLAYER = 50,
    COMP = 725,
    PLAYER2 = 776,
};

class Paddle : public gameObject
{
    public:
        Paddle(pType _t);
        void logic(sf::RenderWindow &w, Ball &ball) override;
    protected:
    private:
        void input(Ball &ball);

        void p_input(Ball &ball);
        void c_input(Ball &ball);
        void p2_input(Ball &ball);
        void limits();

        bool ballInYBounds(Ball &ball);

        float vel;

        pType type;

        sf::RectangleShape paddleR;
};

#endif // PADDLE_H
