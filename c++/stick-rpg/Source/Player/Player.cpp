#include "Player.h"

Player::Player(const Levels& levels)
:   m_health    (levels.strength + 5)
,   m_healthBar (m_health)
{
    m_health.setHealthToMax();
    m_healthBar.update();
}

void Player::addForce(const sf::Vector2f& force)
{
    m_velocity += force;
}

void Player::update()
{
    m_healthBar.update();
    m_velocity *= 0.98f;
}

const sf::Vector2f& Player::getVelocity() const noexcept
{
    return m_velocity;
}

void Player::draw(LevelRenderer& window)
{
    m_healthBar.draw(window);
}
