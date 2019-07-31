#ifndef PLAYING_H
#define PLAYING_H

#include "state_base.h"
#include "../game.h"

#include "../Game_Objects/platform.h"
#include "../Game_Objects/player.h"

#include "e_play_themes.h"



namespace State
{

class Playing : public State_Base
{
    public:
        Playing( Game& game, Play_Theme theme = Play_Theme::Normal );

        void input	( float dt ) override;
        void update	( float dt ) override;
        void draw	( float dt ) override;

    private:
        void initPlatforms  ();
        void initSprites    ();

        bool platformIntersects ( const sf::Vector2f& position );

        void addPlatform ( const sf::Vector2f& position );

        bool isPlayerTouchingPlatform ();

        void bounce ( float dt ); //Bounce the player/ move the world around player

        bool bouncePlatforms() const;

        void checkPlatforms ();

        /* DATA */

        std::vector<Platform> m_platforms;

        //The sprites for the different platform types
        sf::RectangleShape m_platformSprite;
        sf::RectangleShape m_brokenPlatformSprite;

        Player  m_player;

        bool    m_isPlaying = false;

        sf::Text m_introText;


};

}

#endif // PLAYING_H
