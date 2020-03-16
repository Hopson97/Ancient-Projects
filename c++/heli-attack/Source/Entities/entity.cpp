#include "entity.h"

#include <iostream>

#include "../Tiles/Util/tile_info.h"
#include "../Util/math_funcs.h"
#include "../Util/rand.h"

Entity :: Entity( const sf::Vector2f& size, const sf::Vector2f& position, const sf::Texture& texture, const Level& level  )
:   m_sprite    ( size )
,   m_level     ( level )
{
    m_sprite.setPosition( position );
    m_sprite.setTexture ( &texture );
}

Entity :: Entity( const sf::Vector2f& size, const sf::Texture& texture, const Level& level  )
:   m_sprite    ( size )
,   m_level     ( level )
{
    m_sprite.setTexture ( &texture );
}

void
Entity :: update ( const float dt )
{
    if ( !m_isAlive ) return;

    updateTilePosition();

    for ( auto& component : m_components )
    {
        checkOutOfBounds();
        component->update ( dt );
    }
    checkOutOfBounds();

    uniqueUpdate ( dt );
    moveSprite   ( dt );

    checkVelocityForZero();

    if ( !getVelocity().x == 0 )
        m_isMoving = true;
    else
        m_isMoving = false;
}

void
Entity :: draw ( sf::RenderWindow& window )
{
    if ( m_isAlive && inWindowBounds( window ) )
    {
        window.draw( m_sprite );
    }
}

void
Entity :: updateTilePosition ()
{
    int x = m_sprite.getPosition().x  / Tile::TILE_SIZE;;
    int y = m_sprite.getPosition().y  / Tile::TILE_SIZE;

    m_tilePostion = { x, y };
}

void
Entity :: moveSprite ( const float dt )
{
    m_sprite.move( m_velocity * dt );
}

const double
Entity :: getGravity () const
{
    return m_level.getGravity();
}

const sf::Vector2f&
Entity :: getVelocity () const
{
    return m_velocity;
}

const sf::Vector2i&
Entity :: getTilePosition ()
{
    updateTilePosition();
    return m_tilePostion;
}

const sf::Vector2f&
Entity :: getSpritePosition () const
{
    return m_sprite.getPosition();
}

const sf::Vector2f&
Entity :: getSpriteSize       () const
{
    return m_sprite.getSize();
}

void
Entity :: changeVelocity ( const float x, const float y)
{
    m_velocity.x += x;
    m_velocity.y += y;
}

void
Entity :: setVelocity ( const float x, const float y)
{
    m_velocity = { x, y };
}

void
Entity :: setRotation ( const float rotation )
{
    m_sprite.setRotation( rotation );
}

const float
Entity :: getRotation () const
{
    return m_sprite.getRotation();
}

void
Entity :: resetXVelocity ()
{
    m_velocity.x = 0;
}

void
Entity :: resetYVelocity ()
{
    m_velocity.y = 0;
}

const bool
Entity :: isOnGround () const
{
    return m_isOnGround;
}

bool
Entity :: intersects ( const Entity& other ) const
{
    return  (   Math::getDistance<float>(getSpritePosition(), other.getSpritePosition()) <= other.getSpriteSize().x ||
                Math::getDistance<float>(getSpritePosition(), other.getSpritePosition()) <= other.getSpriteSize().y // ||
               // Math::getDistance<float>(getSpritePosition(), other.getSpritePosition()) <= getSpriteSize().x ||
               // Math::getDistance<float>(getSpritePosition(), other.getSpritePosition()) <= getSpriteSize().y
             );
}

void
Entity :: setIfOnGround ( const bool onGround )
{
    m_isOnGround = onGround;
}

void
Entity :: addComponent  ( ComponentPtr comp )
{
    m_components.push_back( std::move( comp ) );
}

void
Entity :: checkVelocityForZero ()
{
    const float bound = 0.01;

    if ( getVelocity().x < bound &&  getVelocity().x > -bound ) setVelocity(  0, getVelocity().y );
    if ( getVelocity().y < bound &&  getVelocity().y > -bound ) setVelocity(  getVelocity().x, 0 );
}

const bool
Entity :: isMoving ()
{
    return m_isMoving;
}

void
Entity :: setTextureRect ( const sf::IntRect& txrRect )
{
    m_sprite.setTextureRect( txrRect );
}

bool
Entity :: isAlive () const
{
    return m_isAlive;
}

void
Entity :: setAlive ( const bool alive )
{
    m_isAlive = alive;
}


void
Entity :: centerSpriteOrigin ()
{
    sf::FloatRect r = m_sprite.getLocalBounds();

    m_sprite.setOrigin( r.width / 2, r.height / 2 );

    m_isCenterOrigin = true;
}

bool
Entity :: isCenteredOrigin () const
{
    return m_isCenterOrigin;
}

void
Entity :: spawnInrngAirTile    ()
{
    unsigned trials = rng::num( 10, 20 );

    for ( unsigned i = 0 ; i < trials ; i ++ )
    {
        int x = rng::num(0, m_level.getWidth  () );
        int y = rng::num(0, m_level.getHeight () );

        if ( !m_level.getTileAt( x, y )->isSolid() )
        {
           if ( m_level.getTileAt( x - 1, y        )->isSolid() ) continue;
           if ( m_level.getTileAt( x + 1, y        )->isSolid() ) continue;
           if ( m_level.getTileAt( x,     y + 1    )->isSolid() ) continue;
           if ( m_level.getTileAt( x,     y - 1    )->isSolid() ) continue;

           if ( m_level.getTileAt( x - 1, y - 1    )->isSolid() ) continue;
           if ( m_level.getTileAt( x + 1, y + 1    )->isSolid() ) continue;
           if ( m_level.getTileAt( x - 1, y + 1    )->isSolid() ) continue;
           if ( m_level.getTileAt( x + 1, y - 1    )->isSolid() ) continue;

            m_sprite.setPosition( x * Tile::TILE_SIZE, y * Tile::TILE_SIZE );
            return;
        }
    }

    setAlive( false );
}

bool
Entity :: inWindowBounds (const sf::RenderWindow& window ) const
{
    sf::Vector2f winPos = window.getView().getCenter();

    if      ( m_sprite.getPosition().x  < winPos.x - Win_Info::WIDTH  / 2 - m_sprite.getLocalBounds().width )       return false ;
    else if ( m_sprite.getPosition().y  < winPos.y - Win_Info::HEIGHT / 2 - m_sprite.getLocalBounds().height )      return false  ;
    else if ( m_sprite.getPosition().x  > winPos.x + Win_Info::WIDTH  / 2 ) return false ;
    else if ( m_sprite.getPosition().y  > winPos.y + Win_Info::WIDTH  / 2 ) return false ;

    return true;
}


void
Entity :: checkOutOfBounds ()
{
    updateTilePosition();

    //We don't check for up because bullets falling is cool
    checkOOBDown();
    checkOOBLeft();
    checkOOBRight();

    updateTilePosition();
}

//Check if the entity is at the bottom of the map
void
Entity :: checkOOBDown ()
{
    if ( m_tilePostion.y >= m_level.getHeight() )
    {
        m_velocity.y = -1;
        m_sprite.setPosition( m_sprite.getPosition().x, Tile::TILE_SIZE * m_level.getHeight() - 1 );
    }
}

//Check if the entity is at the left of the map
void
Entity :: checkOOBLeft ()
{
    if ( m_tilePostion.x <= 0 )
    {
        m_velocity.x = 1;
        m_sprite.setPosition( Tile::TILE_SIZE, m_sprite.getPosition().y );
    }
}

//Check if the entity is at the right of the map
void
Entity :: checkOOBRight ()
{
    if ( m_tilePostion.x >= m_level.getWidth() )
    {
        m_velocity.x = -1;
        m_sprite.setPosition( Tile::TILE_SIZE * m_level.getWidth() - 1, m_sprite.getPosition().y );
    }
}
