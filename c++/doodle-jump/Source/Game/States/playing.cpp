#include "playing.h"

#include "../Util/random.h"
#include "../Util/window.h"

#include "../Managers/resource_identifier.h"

#include <iostream>
#include <cmath>

namespace State
{

Playing :: Playing ( Game& game, Play_Theme theme )
:   State_Base ( game )
{
    if ( theme == Play_Theme::Normal )
    {
        m_game.loadTexture( Res::getTexture( "Platform_Normal" ),           Texture_Name::Platform_Normal );
        m_game.loadTexture( Res::getTexture( "Platform_Normal_Broken" ),    Texture_Name::Platform_Broken );
        m_game.loadTexture( Res::getTexture( "Player_Normal" ),             Texture_Name::Player_Normal );

        m_game.loadFont     ( Res::getFont( "arial" ), Font_Name::Arial );

        m_player.setTexture ( m_game.getTexture( Texture_Name::Player_Normal ) );
    }

    m_introText.setString( "Press SPACE to start! \n\n Control using\n MOUSE MOVEMENTS"
                         );

    m_introText.setCharacterSize( 30 );
    m_introText.setColor( sf::Color::Green );
    m_introText.setFont( m_game.getFont( Font_Name::Arial ) );

    initPlatforms   ();
    initSprites     ();
}

void Playing :: input ( float dt )
{
    if ( !m_isPlaying )
    {
        if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Space ) ) m_isPlaying = true;
    }
    else
    {
        if ( sf::Keyboard::isKeyPressed( sf::Keyboard::A ) )
        {
            m_player.changeX( -5 );

        }
        if ( sf::Keyboard::isKeyPressed( sf::Keyboard::D ) )
        {
            m_player.changeX( 5 );
        }

    }
}

void Playing:: update ( float dt )
{

    m_player.update( dt );

    if ( isPlayerTouchingPlatform() )
    {
        bounce( dt );
    }

    if ( bouncePlatforms() )
    {
        Window::setView( m_player.getPosition().y );
    }

    checkPlatforms();
}

void Playing :: draw ( float dt )
{
    for ( const auto& platform : m_platforms )
    {
        if ( platform.getType() == Platform_Type::Normal )
        {
            m_platformSprite.setPosition( platform.getPosition() );
            Window::draw( m_platformSprite );
        }
        else
        {
            m_brokenPlatformSprite.setPosition( platform.getPosition() );
            Window::draw( m_brokenPlatformSprite );
        }
    }

    m_player.draw();

    if ( !m_isPlaying ) Window::draw( m_introText, false );
}


void Playing :: initPlatforms ()
{
    int numPlatforms = 10;

    //To ensure that the platforms don't all end up in a single place, the screen is split into sections
    int sections = Window::HEIGHT / numPlatforms;

    //Place the first platform
    m_platforms.emplace_back( sf::Vector2f( Window::WIDTH / 2 - Platform::WIDTH  / 2,
                                            Window::HEIGHT    - Platform::HEIGHT * 2 ),
                              Platform_Type::Normal
                            );

    //Random height change for initial platform positions
    float randomChanger = 25;
    //bool wasLastBroken;

    for ( int i = numPlatforms ; i > 0 ; i-- )
    {
        float section = sections * i - sections;

        float y = section + Random::decimalF( -randomChanger, randomChanger );
        float x = Random::decimalF( 0, Window::WIDTH - Platform::WIDTH );

        if( y > 380 ) x = Random::decimalF( 0 , Window::WIDTH / 2 - Platform::WIDTH );

        while ( platformIntersects( { x, y } ) )
        {
            x = Random::decimalF ( 0, Window::WIDTH  - Platform::WIDTH  );
            y = Random::decimalF ( 0, Window::HEIGHT - Platform::HEIGHT );
            if( y > 380 ) x = Random::decimalF( 0 , Window::WIDTH / 2 - Platform::WIDTH );
        }
        addPlatform(  { x, y } );
    }
}

void Playing :: initSprites ()
{
    sf::Vector2f size (  Platform::WIDTH, Platform::HEIGHT  );

    m_platformSprite.       setSize( size );
    m_brokenPlatformSprite. setSize( size );

    m_platformSprite.       setTexture( &m_game.getTexture( Texture_Name::Platform_Normal ) );
    m_brokenPlatformSprite. setTexture( &m_game.getTexture( Texture_Name::Platform_Broken ) );
}


bool Playing :: platformIntersects ( const sf::Vector2f& position )
{
    sf::FloatRect rect = Platform::getBounds( position );

    //Look at each platform and check if they intersect the platform to be placed
    for ( const auto& platform : m_platforms )
    {
        sf::FloatRect otherRect = Platform::getBounds( platform.getPosition() );

        if ( rect.intersects( otherRect ) ) return true;
    }
    return false;
}

void Playing :: addPlatform ( const sf::Vector2f& position )
{
    //Randomly decide if a platform will be broken
    int brokenRand = Random::integer( 0, 20 );
    int chance = 3;

    Platform_Type type;

    type = ( brokenRand <= chance ) ? Platform_Type::Broken : Platform_Type::Normal;

    m_platforms.emplace_back( position, type );
}

bool Playing :: isPlayerTouchingPlatform ()
{
    float yBottom = m_player.getPosition().y + Player::SIZE_Y;
    float xLeft = m_player.getPosition().x;
    float xRight = m_player.getPosition().x + Player::SIZE_X;

    for ( const Platform& platform : m_platforms )
    {
        float platTop       = platform.getPosition().y;
        float xPlatLeft     = platform.getPosition().x;
        float xPlatRight    = platform.getPosition().x + Platform::WIDTH;

        if ( abs ( yBottom - platTop ) < 5 &&
             xLeft > xPlatLeft &&
             xRight < xPlatRight &&
             m_player.isFalling() )
        {
            return true;
        }
    }
    return false;
}

void Playing :: bounce( float dt )
{
    m_player.bounce();
}

bool Playing :: bouncePlatforms() const
{
    return m_player.getPosition().y + Player::SIZE_Y < Window::HEIGHT / 2 + Window::getViewBottom();
}

void Playing :: checkPlatforms ()
{
    for ( size_t i = 0 ; i < m_platforms.size() ; i++ )
    {
        if ( m_platforms.at( i ).belowWindow( m_player.getPosition().y ) )
        {
            m_platforms.erase( m_platforms.begin() + i );

            float x = Random::decimalF( 0, Window::WIDTH - Platform::WIDTH );
            float y = Random::decimalF( -200, Platform::HEIGHT );

            y -= Window::getViewBottom();

            addPlatform( { x, y } );
        }
    }
}

}

















