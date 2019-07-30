#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H


#include <SFML/Graphics.hpp>

#include "../Engine/Entity/entity.h"
#include "state.h"
#include "../Engine/game.h"
#include "../Engine/constants.h"


namespace state
{

class SplashScreen : public State
{
    public:
        explicit    SplashScreen  ( Game* game );

        void        input           ( const float dt )      override {} //no input for splash screen!
        void        update          ( const float dt )      override;
        void        draw            ( const float dt )      override;

    private:
        void        ssInitial       ();
        void        ssDuring        (const float dt);
        void        ssOut           ();

    private:
        enum SplashState
        {
                SPSH_ST_INITIAL
            ,   SPSH_ST_DURING
            ,   SPSH_ST_OUT
        };

        Entity                      logoSprite      { _mGame().getTexture( RES_TXR_SPLASH_SCREEN_MH) };

        SplashState                 mSplashState    { SPSH_ST_INITIAL };

        sf::RectangleShape          blackness       { { (float) win::WIDTH, (float) win::HEIGHT } };
};

}//Namespace state

#endif // SPLASHSCREEN_H
