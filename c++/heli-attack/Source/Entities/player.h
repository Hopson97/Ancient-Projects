#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

#include "../game.h"
#include "entity.h"
#include "../level.h"
#include "Util/animation.h"
#include "../Util/window.h"
#include "../Particles/gravity_particles.h"

class Player : public Entity
{
    public:
        Player          ( const Level& level, const Game& game, Window& window, Gravity_Particles& bloodParticles );

        void
        input           ();

    private:
        void
        uniqueUpdate    ( const float dt ) override;

        void
        checkGravity    ();

        const bool
        tileSolid       ( const sf::Vector2f& newPos  ) const;

    private:
        constexpr static double m_walkSpeed    = 75;

        constexpr static double m_jumpSpeed    = 700;

        const Level&    m_level;

        Animation       m_walkAnim;

        Window&         m_window;
};

#endif // PLAYER_H
