#include "friction.h"

namespace Component
{

Friction :: Friction( Entity& entity, const Level& level )
:   m_entity    ( entity )
,   m_level     ( level )
{
    //ctor
}

void
Friction :: update ( const float dt )
{

    m_entity.setVelocity ( m_entity.getVelocity().x * 0.8,
                            m_entity.getVelocity().y );
}


}
