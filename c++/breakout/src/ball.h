#ifndef BALL_H
#define BALL_H

#include "gameobject.h"

class Ball : public GameObject
{
    public:
        Ball();
        void logic(sf::RenderWindow &window) override;
    protected:
    private:
        float velX;
        float velY;
};

#endif // BALL_H
