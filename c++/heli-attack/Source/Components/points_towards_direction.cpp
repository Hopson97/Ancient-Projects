#include "points_towards_direction.h"

#include "../Util/math_funcs.h"

namespace Component
{

Points_Towards_Direction::Points_Towards_Direction( Entity& entity )
:   m_entity    ( entity )
{ }

void
Points_Towards_Direction :: update ( const float dt )
{
    sf::Vector2f vel = m_entity.getVelocity();

    float angle = Math::getRotInDeg( vel.x, vel.y );

    m_entity.setRotation( angle + 180 );
}

}
