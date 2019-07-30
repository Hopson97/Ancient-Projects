#include "ship.h"

void Ship::addUnit(const sf::Texture& texture, const UnitType _type, const sf::RectangleShape& rect)
{
    int xPos = rect.getPosition().x / 40;
    int yPos = rect.getPosition().y / 40;

    if ( unitPresent(rect)) {
        return;
    }
    else {
        addUnitToRoom(rect, std::make_shared<Unit>(texture, _type, xPos, yPos));
    }
}

void Ship::addUnitToRoom(const sf::RectangleShape& rect, std::shared_ptr<Unit> _unit)
{
    for (unsigned int tId = 0; tId < mRoomMap.size(); tId++){                  //Go through each room
        if (mRoomMap[tId].getSprite().getGlobalBounds().intersects(rect.getGlobalBounds())){
              mRoomMap[tId].addUnit(_unit);
        }
    }
}

void Ship::removeUnit(const sf::RectangleShape& rect)
{
    for ( auto& room : mRoomMap ) {
        for (unsigned int uId = 0; uId < room.getUnits().size(); uId++){
            if( (int) room.getUnits()[uId]->getPos().x == (int) rect.getPosition().x &&
                (int) room.getUnits()[uId]->getPos().y == (int) rect.getPosition().y) {

                room.getUnits().erase(room.getUnits().begin() + uId);
            }
        }
    }
}

bool Ship::unitPresent(const sf::RectangleShape& rect)
{
    for( auto& room : mRoomMap ) {
        for( auto& unit : room.getUnits() )
        {
            if( (int) unit->getPos().x == (int) rect.getPosition().x &&
                (int) unit->getPos().y == (int) rect.getPosition().y) {
                return true;
            }
        }
    }
    return false;
}

void Ship::setUnitDatabase(TextureManager& textures)
{
    unitTextures[UT_RECRUIT]            = &textures.getTexture(RES_TXR_UNITS_RECRUIT);
}

sf::Texture& Ship::getUnitTexture(const UnitType unitT)
{
    return *unitTextures[unitT];
}
