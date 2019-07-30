#include "ship_component.h"

ShipComponent::ShipComponent(const sf::Vector2f, const sf::Texture& symbol)
{
    mSymbol.setTexture(symbol);
}

void ShipComponent::draw(sf::RenderWindow& window)
{

}
