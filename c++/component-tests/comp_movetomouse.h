#ifndef COMP_MOVETOMOUSE_H
#define COMP_MOVETOMOUSE_H

#include "component.h"

#include <cmath>

class Comp_MoveToMouse : public Component
{
    public:
        Comp_MoveToMouse(sf::Sprite& _sprite, sf::RenderWindow& _window);
        void logic() override;
    private:
        void getMouseVector(float& dx, float& dy);
        void lookAtMouse(float dx, float dy);
        void moveToMouse(float dx, float dy);
    private:
        sf::Sprite &sprite;
        sf::RenderWindow &window;
};

#endif // COMP_MOVETOMOUSE_H
