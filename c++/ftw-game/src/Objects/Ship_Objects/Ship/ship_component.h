#ifndef COMPONENTLEVEL_H
#define COMPONENTLEVEL_H

#include <SFML/Graphics.hpp>

#include "../../../Utilities/rangednum.h"

class ShipComponent
{
    public:
        ShipComponent(const sf::Vector2f, const sf::Texture& symbol);

        void    draw    (sf::RenderWindow& window);


    private:
        util::RangedNum<int> level { 0, 2, 0};
        sf::Sprite mSymbol;
};

#endif // COMPONENTLEVEL_H
