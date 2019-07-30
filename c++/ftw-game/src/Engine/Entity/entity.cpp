#include "entity.h"

#include <iostream>
#include <cmath>

#include "../../Utilities/random.h"
#include "../constants.h"

Entity::Entity()
{

}

Entity::Entity      (const sf::Texture& t)
: mSprite(t)
{

}

/*****************************************************************************************************************************************************************
*   draw()      draws the sprite to the screen
*   param1  :   the game window
**************************************************************************************************************************************************************/
void  Entity::draw (sf::RenderWindow& window)
{
    window.draw(mSprite);
    window.draw(mText);
}

/*****************************************************************************************************************************************************************
*   _mSprite() returns the sprite for the derived classes
***************************************************************************************************************************************************************/
sf::Sprite& Entity::_mSprite()
{
    return mSprite;
}

/*****************************************************************************************************************************************************************
*   setToRandColour () sets the sprite's colour to a rng  colour for each RGB value, using functions in rng .h, use primary by this->dance method
***************************************************************************************************************************************************************/
void Entity::setToRandColour()
{
    mSprite.setColor(rng ::colour());
}

/*****************************************************************************************************************************************************************
*   centerOrigin() simply centers the origin of the sprite, and of course doing so might move the sprite a by half its width and height
*   param 1 :   an SFML vector2f to define the new position of the sprite, because centring the origin causes an offset
***************************************************************************************************************************************************************/
void Entity::centerOrigin( const sf::Vector2f& newPos )
{
    sf::FloatRect f = mSprite.getLocalBounds();

    mSprite.setOrigin       ( { f.width/ 2.0f, f.height/ 2.0f  } );
    mSprite.setPosition(newPos);
}

/*****************************************************************************************************************************************************************
*   setTextureRect() sets the area of the sprite sheet which is visible to the player
*   param1  :   the rectangle within the sprite's texture to be visible
***************************************************************************************************************************************************************/
void Entity::setTextureRect(const sf::IntRect& rect)
{
    mSprite.setTextureRect(rect);
}

/**************************************************************************************************************************************************************
*   centerOrigin()  will centre the origin of the sprite
**************************************************************************************************************************************************************/
void Entity::centerOrigin()
{
    sf::FloatRect r = mSprite.getLocalBounds();

    mSprite.setOrigin(  r.width     / 2,
                        r.height    / 2);
}

void Entity::dance(const float dt)
{
    dancer.dance(dt, mSprite);
}

void Entity::setPos             ( const sf::Vector2f& pos       )   { mSprite.setPosition(pos);         }   //Sets the position of the sprite

void Entity::setRot             ( const int rot                 )   { mSprite.setRotation(rot);         }   //Sets the rotation of the sprite

void Entity::setColour          ( const sf::Color& c            )   { mSprite.setColor(c);              }   //Sets the colour of the sprite

void Entity::setOrigin          ( const sf::Vector2f& org       )   { mSprite.setOrigin(org);           }   //Sets the origin of the sprite

const sf::Vector2f Entity::getPos     () const                            { return mSprite.getPosition();     }   //Returns position of the sprite

const sf::Sprite Entity::getSprite    () const                            { return mSprite;                   }   //Returns the sprite itself
