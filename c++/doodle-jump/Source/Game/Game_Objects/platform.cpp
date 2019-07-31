#include "platform.h"

#include "../Util/window.h"
#include "../Util/random.h"

#include "player.h"

Platform :: Platform ( const sf::Vector2f& position, Platform_Type type )
:   m_position      ( position )
,   m_platformType  ( type )
{

}

void Platform :: update ( bool canMove, float dt )
{

}

bool Platform :: belowWindow ( float playerPositionY ) const
{
    return m_position.y - playerPositionY > Window::HEIGHT / 2;
}


const sf::Vector2f& Platform :: getPosition() const
{
    return m_position;
}

Platform_Type Platform :: getType () const
{
    return m_platformType;
}

sf::FloatRect Platform :: getBounds ( const sf::Vector2f& position )
{
    sf::FloatRect rect;
    rect.left   = position.x;
    rect.top    = position.y;
    rect.width  = WIDTH;
    rect.height = HEIGHT;

    return rect;
}
