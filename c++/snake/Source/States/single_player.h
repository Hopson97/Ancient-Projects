#ifndef SINGLE_PLAYER_H
#define SINGLE_PLAYER_H
#include "game.h"

#include "snake.h"
#include "apple.h"

namespace State
{

class Single_Player : public State_Base
{
    public:
        Single_Player            ( Game& game);

        ~Single_Player           () {}

        void input      ( const double dt ) override;
        void update     ( const double dt ) override;
        void draw       ( const double dt ) override;

    private:
        void testAppleCollide ();

        Snake snake;
        Apple m_apple;
};

}

#endif // SINGLE_PLAYER_H
