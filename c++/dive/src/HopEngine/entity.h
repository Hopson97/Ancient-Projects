#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>

class Entity
{
    public:
        Entity();
        virtual void logic(sf::RenderWindow &window);
        void draw(sf::RenderWindow &w);
    protected:
        sf::Sprite sprite;
        sf::Texture texture;
    private:

};

#endif // ENTITY_H
