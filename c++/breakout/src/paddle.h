#ifndef PADDLE_H
#define PADDLE_H

#include "paddle.h"
#include "gameobject.h"

class Paddle : public GameObject
{
    public:
        Paddle();
        void logic(sf::RenderWindow &window) override;
    protected:
    private:
};

#endif // PADDLE_H
