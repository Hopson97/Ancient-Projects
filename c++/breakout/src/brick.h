#ifndef BRICK_H
#define BRICK_H

#include "gameobject.h"
#include "random.h"

class Brick : public GameObject
{
    public:
        Brick(int x, int y);

        void logic(sf::RenderWindow& window) override;

    private:
        sf::Color randomColour();
};

#endif // BRICK_H
