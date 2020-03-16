#include "tile.h"

namespace Tile
{

Tile_Base :: Tile_Base( const int xPos, const int yPos )
:   m_tilePosition ( {xPos, yPos } )
{

}

Tile_Base :: Tile_Base( const int xPos, const int yPos, Tile_Model* model )
:   m_tilePosition  ( {xPos, yPos } )
,   m_model         ( model )
{

}

void
Tile_Base :: update  ( const float dt )
{

}

void
Tile_Base :: draw ( sf::RenderWindow& window )
{
    if ( m_model ) //If the model is not null
    {
        m_model->setPosition ( m_tilePosition.x * Tile::TILE_SIZE, m_tilePosition.y  * Tile::TILE_SIZE);
        m_model->draw( window );
    }
}

const sf::Vector2i
Tile_Base :: getTileMapPosition  () const
{
    return m_tilePosition;
}

bool
Tile_Base :: isSolid ()
{
    return m_model->m_data.isSolid;
}



}
