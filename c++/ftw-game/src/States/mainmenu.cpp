#include "mainmenu.h"

#include <iostream>

#include "newgameshipselector.h"
#include "../Engine/constants.h"

namespace state {

MainMenu::MainMenu( Game* game )
:   State               ( game )
{
    mLogo.centerOrigin(sf::Vector2f( win::WIDTH  / 2,
                                     win::HEIGHT / 2 ) );
    mLogo.setToRandColour();

    blackFade.setSize({ (float) win::WIDTH,
                        (float) win::HEIGHT
                      });
    blackFade.setFillColor(col::BLACK);
}

/***************************************************************************************************************************************************************
*   input() handle input of this class
*   param1  :   games's delta time
***************************************************************************************************************************************************************/
void MainMenu::input(const float dt)
{
    if ( mNewGameButton.clicked( _mGame().window(), true ) ) {
        _mGame().getStates(true).pushState( std::make_shared<state::NewGameShipSelector>( &_mGame(), _mGame().getTexture_m() ) );
    }
    if ( mContinueButton.clicked( _mGame().window(), true ) ) {
        //continue game
    }
}

/***************************************************************************************************************************************************************
*   update()    update this states objects
*   param1  :   games's delta time
***************************************************************************************************************************************************************/
void MainMenu::update(const float dt)
{
    _mGame().setClearColour(col::YELLOWY);    //Colour value for a old paper look
    mLogo.dance(dt);
    fadeIn();
}

/***************************************************************************************************************************************************************
*   draw()  draw this states sprites
*   param1  :   games's delta time
***************************************************************************************************************************************************************/
void MainMenu::draw(const float dt)
{
    mBackground     .draw( _mGame().window() );
    mNewGameButton  .draw( _mGame().window() );
    mContinueButton .draw( _mGame().window() );
    mLogo           .draw( _mGame().window() );
    if( blackFading ) _mGame().window().draw( blackFade );
}

void MainMenu::fadeIn()
{
    if( blackFading ) {
        int a = blackFade.getFillColor().a;
        blackFade.setFillColor( sf::Color( 0, 0, 0, --a));
        if ( a <= 0 ) blackFading = false;
    }
}

} //name space state
