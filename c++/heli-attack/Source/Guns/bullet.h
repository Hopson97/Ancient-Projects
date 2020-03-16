#ifndef BULLET_H
#define BULLET_H

#include "../game.h"
#include "../Entities/entity.h"
#include "../level.h"
#include "../Entities/player.h"
#include "../Util/window.h"

#include "../Particles/gravity_particles.h"

class Bullet    :   public Entity
{
    public:
        Bullet      ( const Level& level, const Game& game, const Player& player, Window& window, const sf::Vector2f& targetLocation, Gravity_Particles& particles );

    private:
        void
        uniqueUpdate ( const float dt ) override;

        bool
        isFallen    () const;

    private:

        constexpr static int m_speed = 1900;

        bool        m_isFallen = false;
        sf::Clock   m_eraseClock; //Clock to determine when the bullet should be deleted
};

#endif // BULLET_H
