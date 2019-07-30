#ifndef BUTTON_H
#define BUTTON_H

#include "../object.h"

class Button : public Object
{
    public:
        Button(const sf::Texture& texture, const sf::Vector2f pos);

        bool    clicked(sf::RenderWindow& window);          //Returns true if button clicked

    private:
        bool    touchingMouse(sf::RenderWindow& window);    //Returns true if touching mouse
};

#endif // BUTTON_H
