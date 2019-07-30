#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "Stats.h"
#include "Health.h"
#include "HealthBar.h"

#include <SFML/Graphics.hpp>

class LevelRenderer;

class Player
{
    public:
        Player(const Levels& levels);

        void addForce(const sf::Vector2f& force);
        void update();

        const sf::Vector2f& getVelocity() const noexcept;

        void draw(LevelRenderer& window);

    private:
        sf::Vector2f m_velocity;

        Health m_health;
        HealthBar m_healthBar;

};

#endif // PLAYER_H_INCLUDED
