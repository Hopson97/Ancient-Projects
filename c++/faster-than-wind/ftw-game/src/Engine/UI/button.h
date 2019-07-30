#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Audio.hpp>
#include "../Entity/entity.h"

namespace ui{
class Button : public Entity
{
    public:
                Button          (const sf::Texture& texture);
                Button          (const sf::Texture& texture, const sf::Vector2f& pos, sf::Sound& clickSound);
                Button          (const sf::Texture& texture, const sf::Vector2f& pos, const std::string& buttonText, const int textSize, const sf::Font& font, sf::Sound& clickSound);

        bool    clicked         (sf::RenderWindow& window, const bool changeColour);          //Returns true if button clicked

    private:
        bool    touchingMouse   (sf::RenderWindow& window);    //Returns true if touching mouse
        void    changeButtonColour    (const sf::Color& col);

        sf::Sound* mClickSound;

        bool beenClicked { false };

};
}
#endif // BUTTON_H
