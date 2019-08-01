#ifndef TEST_H
#define TEST_H

#include "../world.h"
#include "../Util/soundeffect.h"

namespace State
{

class Test : public State_Base
{
    public:
        Test    ( Game& game);

        ~Test   () {}

        void
        input   ( const double dt ) override;

        void
        update  ( const double dt ) override;

        void
        draw  ( const double dt ) override;

    private:
        World           m_world;
        SoundEffect     m_gunSound;


};

}

#endif // TEST_H
