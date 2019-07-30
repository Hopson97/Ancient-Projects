#ifndef GAME_H
#define GAME_H

#include "ResourceManagers/texture_m.h"
#include "ResourceManagers/sound_m.h"
#include "ResourceManagers/font_m.h"
#include "../States/statehandler.h"

#include <string>

#include "constants.h"

typedef std::shared_ptr<State> statePtr;

class State;
class Game
{
    public:
                                        Game            ();
                void                    runGame         ();
                void                    windowEvents    ();

                void                    changeSong      (const std::string& filePath);


        const   sf::Texture&            getTexture      ( const TextureName name );
                TextureManager&         getTexture_m    ( );

                sf::Sound&              getSound        ( const SoundName name);
                SoundManager&           getSounds       () ;

        const   sf::Font&               getFont         ( const FontName name);


                sf::RenderWindow&       window          ();

                StateHandler&           getStates       (const bool clearResources);

        inline void                     setClearColour  (const sf::Color& c)    { mClearColour = c;}

                sf::Music&              getMusic        () { return mMusic; }

    private:
                float                   deltaTime       (sf::Clock& clock);

    private:
        sf::RenderWindow    mWindow     { sf::VideoMode(win::WIDTH, win::HEIGHT), "Faster Than Wind", sf::Style::Close };

        TextureManager      mTextures;
        SoundManager        mSounds;
        FontManager         mFonts;

        StateHandler        mStates;

        sf::Color           mClearColour;

        sf::Music           mMusic;

        void quickload();
        void usualload();
};

#endif // GAME_H
