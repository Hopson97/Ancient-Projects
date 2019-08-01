#include "tile_model.h"

namespace Tile
{

void
Tile_Model :: setUp ( const sf::Texture& texture, const bool solid )
{
    m_tile = std::make_unique<sf::RectangleShape>();

    m_tile->setTexture   ( &texture );
    m_tile->setSize      (  Tile::TILE_RECT );

    m_data.isSolid = solid;
}

void
Tile_Model :: setUp ( const bool solid )
{
    m_data.isSolid = solid;
}

void
Tile_Model :: setPosition ( const int x, const int y )
{
    if ( m_tile )
        m_tile->setPosition( x, y );
}

void
Tile_Model :: draw ( sf::RenderWindow& window )
{
    if ( m_tile )
        window.draw ( *m_tile );
}

}
