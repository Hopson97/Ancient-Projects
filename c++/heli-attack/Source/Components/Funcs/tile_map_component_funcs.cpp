#include "tile_map_component_funcs.h"

#include "../../Tiles/Util/tile_info.h"

#include <iostream>

namespace Component
{

//Tells where the tile position in the area given is solid or not
const bool
tileSolid ( const Level& level, const sf::Vector2f& newPos )
{
    return level.getTileAt( newPos.x / Tile::TILE_SIZE,
                            newPos.y / Tile::TILE_SIZE
                          ) ->isSolid();
}

//Predicts the next position of the entity
const sf::Vector2f
getNextPosition ( const Entity& entity, const float dt )
{
    sf::Vector2f newPos;    // The new tile map position of the player

    if ( !entity.isCenteredOrigin() )
    {
        newPos.x = (entity.getSpritePosition().x ) + entity.getVelocity().x * dt;
        newPos.y = (entity.getSpritePosition().y ) + entity.getVelocity().y * dt;
    }
    else
    {
        newPos.x = (entity.getSpritePosition().x - ( entity.getSpriteSize().x / 2 ) ) + entity.getVelocity().x * dt;
        newPos.y = (entity.getSpritePosition().y - ( entity.getSpriteSize().x / 2 ) ) + entity.getVelocity().y * dt;
    }

    return newPos;
}

} //Namespace Component
