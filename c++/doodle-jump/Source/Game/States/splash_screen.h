#ifndef SPLASH_SCREEN_H
#define SPLASH_SCREEN_H

#include <vector>

#include "../game.h"
#include "state_base.h"

#include "../Util/window.h"

namespace State
{

class Splash_Screen : public State_Base
{
    public:
        Splash_Screen ( Game& game );

        void input	( float dt ) override;
        void update	( float dt ) override;
        void draw	( float dt ) override;

    private:
        class Splash
        {
            public:
                Splash ( const sf::Texture& texture, const sf::SoundBuffer& sound, sf::Time seconds, bool stretch = false );

                Splash ( const sf::Texture& texture, sf::Time seconds, bool stretch = false );

                void update();
                bool hasFinished();

                void addText ( const sf::Font& font, const std::string& text);

            private:
                void setUp ( const sf::Texture& texture, bool stretch );


                sf::RectangleShape  m_sprite;
                sf::Sound           m_sound;
                sf::Time            m_time;
                sf::Clock           m_timer;
                bool                m_hasBegun = false;
                bool                m_hasSound = false;
                sf::Text            m_text;

        };

        std::vector<Splash> m_splashes;
};

}

#endif // SPLASH_SCREEN_H
