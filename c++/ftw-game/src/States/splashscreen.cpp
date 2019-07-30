#include "splashscreen.h"

#include <iostream>
#include "mainmenu.h"

namespace state
{

SplashScreen::SplashScreen( Game* game )
:   State         ( game )
{
    blackness   .setFillColor   ( col::BLACK  );

    logoSprite  .centerOrigin   ();
    logoSprite  .setPos({
                            float (win::WIDTH / 2),
                            float (win::HEIGHT / 2)
                        });
}

/*****************************************************************************************************************************************************************
*   update()    update this states objects
*   param1  :   games's delta time
***************************************************************************************************************************************************************/
void SplashScreen::update ( const float dt )
{
    if ( mSplashState == SPSH_ST_INITIAL ) {
        ssInitial();
    }
    else if ( mSplashState == SPSH_ST_DURING ) {
        ssDuring(dt);
    }
    else if ( mSplashState == SPSH_ST_OUT ) {
        ssOut();
    }
}

/*****************************************************************************************************************************************************************
*   draw()  draw this states sprites
*   param1  :   games's delta time
**************************************************************************************************************************************************************/
void SplashScreen::draw ( const float dt )
{
    logoSprite.draw( _mGame().window() );

    _mGame().window().draw( blackness  );
}

/*****************************************************************************************************************************************************************
*  ssInitial()  what to do during the initial stages of the splash screen
***************************************************************************************************************************************************************/
void SplashScreen::ssInitial()
{
    int opacity = blackness.getFillColor().a;
    blackness.setFillColor( sf::Color(0, 0, 0, --opacity  ) );

    if ( opacity <= 0 ) {
        mSplashState = SPSH_ST_DURING;
    }
}

/*****************************************************************************************************************************************************************
*  ssDuring()  what to do during the yeah
***************************************************************************************************************************************************************/
void  SplashScreen::ssDuring(const float dt)
{
    sf::Clock clock;

    float timeToGetTo = 2.0; //lmao don't judge the magic number friend
    while ( true ) {
        draw(dt);
        _mGame().windowEvents();
        if ( clock.getElapsedTime().asSeconds() > timeToGetTo )
            break;
    }
    mSplashState = SPSH_ST_OUT;

}


/*****************************************************************************************************************************************************************
*  ssOut() what to do during the out stages of the splash screen
***************************************************************************************************************************************************************/
void SplashScreen::ssOut()
{
    int opacity = blackness.getFillColor().a;
    blackness.setFillColor( sf::Color(0, 0, 0, ++opacity  ) );

    if ( opacity >= col::MAX_COLOUR ) {
        _mGame().getStates(true).changeState( std::make_shared<state::MainMenu>(  &_mGame() ) );
    }
}

}//namespace state
