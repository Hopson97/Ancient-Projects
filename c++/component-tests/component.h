#ifndef COMPONENT_H
#define COMPONENT_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

class Entity;

class Component
{
    public:
        Component();
        virtual void logic() = 0;
};

#endif // COMPONENT_H
