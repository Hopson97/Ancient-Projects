#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SFML/Graphics.hpp>


class GameObject
{
    public:
        GameObject();
        virtual void logic(sf::RenderWindow &window) = 0;
    protected:
        sf::RectangleShape rect;
};

#endif // GAMEOBJECT_H
