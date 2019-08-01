#ifndef GRAVITY_PARTICLES_H
#define GRAVITY_PARTICLES_H

#include <SFML/Graphics.hpp>
#include <vector>

#include "../level.h"
#include "../Util/rand.h"


class Gravity_Particles  :   public sf::Drawable, public sf::Transformable
{
    public:
        Gravity_Particles( const sf::Color& colour, const Level& level );

        void
        addParticles        ( const int count, const sf::Vector2f& location, const sf::Vector2f& direction );

        void
        update              ( const float dt );

        void
        draw                ( sf::RenderTarget& window, sf::RenderStates states = sf::RenderStates::Default ) const override;

        std::size_t
        size                () const;


    private:
        void
        checkOutOfBounds        ( sf::Vertex& vertex );

        void
        checkOOBUp              ( sf::Vertex& vertex );

        void
        checkOOBDown            ( sf::Vertex& vertex );

        void
        checkOOBLeft            ( sf::Vertex& vertex );

        void
        checkOOBRight           ( sf::Vertex& vertex );

        const sf::Vector2i
        vertexTilePosition      ( sf::Vertex& vertex );

        void
        checkForResize          ();

    private:
        //Particle class
        class Particle
        {
        public:
            Particle        ( const Level& level, const sf::Vector2f& direction);

            const bool
            onGround        ( const sf::Vertex& vertex, const float dt );

            const sf::Vector2f&
            getVelocity     () const;

        private:
            const bool
            isOnSolidTile   ( const sf::Vertex& vertex );

            const Level*    m_level;
            sf::Vector2f    m_velocity;
        };
        std::vector<sf::Vertex> m_vertices;
        sf::Color               m_colour;
        std::vector<Particle>   m_particles;

        const Level&            m_level;
};

#endif // GRAVITY_PARTICLES_H
