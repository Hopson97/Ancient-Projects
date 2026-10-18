#ifndef ENTITY_H
#define ENTITY_H

#include "component.h"

#include <vector>
#include <memory>

class Entity
{
    public:
        Entity();
        void logic(sf::RenderWindow& window);
    protected:
        virtual void uniqueLogic();

    protected:
        std::vector<std::unique_ptr<Component>> components;
        sf::Sprite sprite;
        sf::Texture texture;

};

#endif // ENTITY_H
