#include "spritedancer.h"

#include "../Utilities/random.h"
#include "constants.h"

#include <cmath>

/*****************************************************************************************************************************************************************
*   newColour() based on certain variables, it sets the sprite to a different colour
*   param1  :   the sprite that will be "dancing"
**************************************************************************************************************************************************************/
sf::Color SpriteDancer::newColour(const sf::Sprite& _sprite)
{
    int r = _sprite.getColor().r;
    int g = _sprite.getColor().g;
    int b = _sprite.getColor().b;

    changeColour(r, isRedAdded);
    changeColour(g, isGreenAdded);
    changeColour(b, isBlueAdded);

    return sf::Color(r, g, b);
}

/*****************************************************************************************************************************************************************
*   changeColour () changes the colour of the Entity, primarily used by the Entity::dance method
*   param1  :   integer to represent 0 - 255 RGB value of either red, green or blue
*   param2   :   boolean to that shows if the R, G or B value is increasing (true) or decreasing (false)
**************************************************************************************************************************************************************/
void SpriteDancer::changeColour(int& colour, bool& isAdding)
{
    if( isAdding ) {
        colour++;
        if( colour >= col::MAX_COLOUR ) {
            isAdding = false;
            colour = col::MAX_COLOUR - 1;
        }
    } else {
        colour--;
        if( colour <= 0 ) {
            isAdding = true;
            colour = 1;
        }
    }
}

/*****************************************************************************************************************************************************************
*   dance()     makes the Entity's sprite "dance" in the form of scaling in and out while fading colours
*   param1  :   float that is the delta time of the game
*   param2  :   the sprite that will be "dancing"
***************************************************************************************************************************************************************/
void SpriteDancer::dance(const float& dt, sf::Sprite& _sprite)
{

    danceCount += dt;
    _sprite.setScale(sf::Vector2f   (
                                    ( 1.5 +  sin( danceCount ) )  ,
                                    ( 1.5 +  sin( danceCount ) )  ) );
    _sprite.setColor(newColour(_sprite));
}
