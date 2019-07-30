#ifndef UNITSHOWER_H
#define UNITSHOWER_H

#include <SFML/Graphics.hpp>

#include "../../Engine/Entity/entity.h"

namespace ui {

class UnitShower : public Entity
{
    public:
        UnitShower(const sf::Texture& texture, const sf::Vector2f& position);
        void    draw(sf::RenderWindow& window) override;

    private:
        sf::RectangleShape  mBox { { 40, 40 } };
};

}

#endif // UNITSHOWER_H
