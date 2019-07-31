#include "player.h"

#include "platform.h"
#include "../Util/window.h"

#include <iostream>

Player::Player()
{
    m_sprite.setSize ( { SIZE_X, SIZE_Y } );
    m_sprite.setPosition( Window::WIDTH / 2 - SIZE_X  / 2,
                          Window::HEIGHT    - Platform::HEIGHT - SIZE_Y * 2 );
}

void Player :: setTexture ( const sf::Texture& texture )
{
    m_sprite.setTexture( &texture );
}

void Player :: draw()
{
    Window::draw( m_sprite );
}

bool Player :: isFalling() const
{
    return m_velocity.y < 0;
}

const sf::Vector2f& Player :: getPosition() const
{
    return m_sprite.getPosition();
}

const sf::Vector2f& Player :: getVelocity() const
{
    return m_velocity;
}



void Player :: bounce()
{
    m_velocity.y = BOUNCE_SPEED;
}

void Player :: changeX ( float x )
{
    m_velocity.x += x;
}


void Player :: update ( float dt )
{
    float xMove = m_velocity.x * dt;
    float yMove = m_velocity.y * dt;

    if ( m_velocity.x > MAX_SPEED  ) m_velocity.x = MAX_SPEED  - 1;
    if ( m_velocity.x < -MAX_SPEED ) m_velocity.x = -MAX_SPEED + 1;

    if ( m_velocity.y < -MAX_FALL ) m_velocity.y = -MAX_FALL + 1;

    m_velocity.y -= GRAVITY;

    m_sprite.move( xMove, -yMove );
    std::cout << m_sprite.getPosition().y << std::endl;

    //Test for window bounds
    if ( ( m_sprite.getPosition().x + SIZE_X / 2 ) < 0 )
    {
        m_sprite.setPosition( Window::WIDTH - SIZE_X, m_sprite.getPosition().y  );
    }
    else if ( ( m_sprite.getPosition().x + SIZE_X / 2 )  > Window::WIDTH )
    {
        m_sprite.setPosition( 0, m_sprite.getPosition().y  );
    }
}
