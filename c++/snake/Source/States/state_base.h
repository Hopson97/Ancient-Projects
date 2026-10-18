#ifndef STATE_BASE_H
#define STATE_BASE_H

/**
    The base class for all the games states, such as menus, roaming, battles etc
*/

#include <SFML/Graphics.hpp>

class Game;

namespace State
{

class State_Base
{
    public:
        State_Base          ( Game& game );

        virtual ~State_Base ();

        virtual void input  ( const double dt ) = 0;

        virtual void update ( const double dt ) = 0;

        virtual void draw   ( const double dt ) = 0;

    protected:
        sf::RenderWindow& getWindow ();

        Game& getGame       ();

    private:
        Game& m_game;
};

} //Namespace state

#endif // STATE_BASE_H
