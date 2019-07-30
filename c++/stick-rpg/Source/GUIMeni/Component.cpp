#include "Component.h"

namespace GUI
{
    void Component::update(const sf::RenderWindow& window, sf::Event e)
    {
        onUpdate(window, e);
    }

    void Component::draw(sf::RenderWindow& window)
    {
        onDraw(window);
    }

}
