#include "unitshower.h"

#include "../../Engine/constants.h"

namespace ui {

UnitShower::UnitShower(const sf::Texture& texture, const sf::Vector2f& position)
:   Entity   ( texture )
{
    _mSprite().setTextureRect   ( sf::IntRect( 0, 0, ship::TILE_SIZE, ship::TILE_SIZE ) );
    _mSprite().setPosition      ( position );

    centerOrigin();
    _mSprite().move         ( ship::TILE_SIZE / 2, ship::TILE_SIZE / 2);
    _mSprite().setRotation  ( 90.0f );

    mBox.setPosition            ( position );
    mBox.setFillColor           ( col::WATER );
    mBox.setOutlineColor        ( col::BLACK );
    mBox.setOutlineThickness    ( 2 );
}

void UnitShower::draw(sf::RenderWindow& window)
{
    window.draw ( mBox  );
    window.draw ( _mSprite() );
}

}
