#ifndef TEST_H
#define TEST_H

#include "game.h"

#include "Snake.h"
#include "apple.h"

namespace State
{

class Test : public State_Base
{
    public:
        Test            ( Game& game);

        ~Test           () {}

        void input      ( const double dt ) override;
        void update     ( const double dt ) override;
        void draw       ( const double dt ) override;
};

}

#endif // TEST_H
