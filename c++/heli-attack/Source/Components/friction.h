#ifndef FRICTION_H
#define FRICTION_H

#include "../Entities/entity.h"
#include "../level.h"
#include "component_base.h"

namespace Component
{

class Friction : public Component_Base
{
    public:
        Friction( Entity& entity, const Level& level );

        void
        update  ( const float dt ) override;

    private:
        Entity&         m_entity;

        const Level&    m_level;
};

}

#endif // FRICTION_H
