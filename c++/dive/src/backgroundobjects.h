#ifndef BACKGROUNDOBJECTS_H
#define BACKGROUNDOBJECTS_H

#include "HopEngine/HopsonEngine.h"


class BackgroundObjects : public Entity
{
    public:
        BackgroundObjects();
        void logic(sf::RenderWindow &window, bool flying, float speed);
    protected:
        void reset(bool flying);
        void setSpeed(float s);

        void checkForReset(bool flying);

    protected:
        int direction;
        float xSpeed;
        int minHeight, maxHeight;
};

#endif // BACKGROUNDOBJECTS_H
