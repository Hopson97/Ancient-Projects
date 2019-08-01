#ifndef COMPONENT_BASE_H
#define COMPONENT_BASE_H

namespace Component
{

class Component_Base
{
    public:
        virtual void
        update ( const float dt ) = 0;
};

} //Namespace Component

#endif // COMPONENT_BASE_H
