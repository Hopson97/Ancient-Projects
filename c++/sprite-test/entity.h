#ifndef ENTITY_H
#define ENTITY_H

#include "drawable.h"

class Entity : public Drawable
{
    public:
        Entity();
        virtual ~Entity();
    protected:

        float xVelocity;
        float yVelocity;

        float   getXVel();
        void    setXVel(float x);

        float   getYVel();
        void    setYVel(float y);
    private:
};

#endif // ENTITY_H
