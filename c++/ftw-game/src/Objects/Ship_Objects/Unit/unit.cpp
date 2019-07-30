#include "unit.h"
#include "../../../Engine/constants.h"

#include <iostream>

Unit::Unit(const sf::Texture& texture, const UnitType _type, const sf::Vector2f& pos, const sf::Vector2f& shipPos)
:   ui::Button  (texture)
,   mUnitType   (_type)
,   mXPos       ( pos.x   )
,   mYPos       ( pos.y   )
{
    _mSprite().setTextureRect(ship::UNIT_SIZE);

    setToShipPos(shipPos);

    setLevels();
    setUpAnimation();

    healthRect.setFillColor     ( sf::Color::Green  );
    noHealthRect.setFillColor   ( sf::Color::Red    );
}

/*****************************************************************************************************************************************************************
*   update()    update the unit
***************************************************************************************************************************************************************/
void Unit::update(const float dt)
{
    _mSprite().setTextureRect( walkingAnim.currentFrame(dt) );
}

void Unit::draw( sf::RenderWindow& window )
{
    window.draw ( _mSprite() );
    if ( isSelected ) {
        drawHealthBar( window );
    }
}

void Unit::drawHealthBar( sf::RenderWindow& window )
{
    float health = (float)mHealth.getValue() / ((float)mHealth.getMax() / (float)ship::TILE_SIZE);
    float damage = ship::TILE_SIZE - health;

    healthRect.setSize      ( { health, 2.0f  } );
    noHealthRect.setSize    ( { damage, 2.0f  } );

    healthRect.setPosition      ( _mSprite().getPosition().x, _mSprite().getPosition().y - 2 );

    float healthWidth = healthRect.getLocalBounds().width;

    noHealthRect.setPosition    ( healthRect.getPosition().x + healthWidth, _mSprite().getPosition().y - 2 );

    window.draw ( healthRect    );
    window.draw ( noHealthRect  );
}


/*****************************************************************************************************************************************************************
*   setToShipPos()  sets the position of the sprite relative to the ships position
*   param1  :   The position of the ship
***************************************************************************************************************************************************************/
void Unit::setToShipPos(const sf::Vector2f& shipPos)
{
    _mSprite().setPosition     ( (mXPos * ship::TILE_SIZE) + shipPos.x,
                                 (mYPos * ship::TILE_SIZE)  + shipPos.y );
}

const UnitType Unit::getType() const
{
    return mUnitType;
}

void Unit::setSelectedState( const bool isSelected)
{
    this->isSelected = isSelected;
}

const bool Unit::getSelectedState() const
{
    return isSelected;
}

/*****************************************************************************************************************************************************************
*   setUpAnimation() adds all needed frames to allow the unit to look alive
***************************************************************************************************************************************************************/
void Unit::setUpAnimation()
{
    const float WALK_FRAME_TIME = 0.2f;

    walkingAnim.addFrame({
                          sf::IntRect( 0 * ship::TILE_SIZE, 0, ship::TILE_SIZE, ship::TILE_SIZE),
                          WALK_FRAME_TIME
                         }
                        );

    walkingAnim.addFrame({
                          sf::IntRect( 1 * ship::TILE_SIZE, 0, ship::TILE_SIZE, ship::TILE_SIZE),
                          WALK_FRAME_TIME
                         }
                        );

    walkingAnim.addFrame({
                          sf::IntRect( 0 * ship::TILE_SIZE, 0, ship::TILE_SIZE, ship::TILE_SIZE),
                          WALK_FRAME_TIME
                         }
                        );

    walkingAnim.addFrame({
                          sf::IntRect( 2 * ship::TILE_SIZE, 0, ship::TILE_SIZE, ship::TILE_SIZE),
                          WALK_FRAME_TIME
                         }
                        );

}

