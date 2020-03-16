#ifndef POINTS_TOWARDS_DIRECTION_H
#define POINTS_TOWARDS_DIRECTION_H

#include "component_base.h"
#include "../Entities/entity.h"

namespace Component
{

class Points_Towards_Direction  :   public Component_Base
{
    public:
        Points_Towards_Direction( Entity& entity );

        void
        update ( const float dt );

    protected:

    private:
        Entity&     m_entity;
};

}

#endif // POINTS_TOWARDS_DIRECTION_H
