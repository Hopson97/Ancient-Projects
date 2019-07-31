#include "menu.h"

namespace State
{

Menu::Menu( Game & game )
:	State_Base ( game )
{
    m_game.changeSong( "euk" );
}

void Menu::input( float dt )
{

}

void Menu::update( float dt )
{

}

void Menu::draw( float dt )
{

}

}
