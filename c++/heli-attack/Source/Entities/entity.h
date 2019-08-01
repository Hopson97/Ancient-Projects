#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>

#include <vector>
#include <memory>

#include "../level.h"
#include "../Components/component_base.h"

typedef std::unique_ptr<Component::Component_Base> ComponentPtr ;

class Entity
{
    public:
        Entity( const sf::Vector2f& size, const sf::Vector2f& position, const sf::Texture& texture, const Level& level );
        Entity( const sf::Vector2f& size, const sf::Texture& texture, const Level& level );

        void
        update                  ( const float dt );

        virtual void
        uniqueUpdate            ( const float dt ) = 0;

        virtual void
        draw                    ( sf::RenderWindow& window );

        const double
        getGravity              () const;

        const sf::Vector2f&
        getVelocity             () const;

        const sf::Vector2i&
        getTilePosition         ();

        const sf::Vector2f&
        getSpritePosition       () const;

        const sf::Vector2f&
        getSpriteSize           () const;

        void
        changeVelocity          ( const float x, const float y);

        void
        setVelocity             ( const float x, const float y);

        void
        setRotation             ( const float rotation );

        const float
        getRotation             () const;

        void
        resetXVelocity          ();

        void
        resetYVelocity          ();

        const bool
        isOnGround              () const;

        void
        setIfOnGround           ( const bool onGround );

        void
        addComponent            ( ComponentPtr comp );

        bool
        isAlive                 () const;

        bool
        intersects              ( const Entity& other ) const;

        void
        setAlive                ( const bool alive );

        bool
        isCenteredOrigin        () const;

    protected:
        void
        updateTilePosition      ();

        void
        moveSprite              ( const float dt );

        void
        checkVelocityForZero    ();

        const bool
        isMoving                ();

        void
        setTextureRect          ( const sf::IntRect& txrRect );

        void
        centerSpriteOrigin      ();

        void
        checkOutOfBounds        ();

        void
        spawnInrngAirTile    ();

        bool
        inWindowBounds          (const sf::RenderWindow& window ) const;

    private:
        void
        checkOOBUp              ();

        void
        checkOOBDown            ();

        void
        checkOOBLeft            ();

        void
        checkOOBRight           ();

    private:
        sf::RectangleShape  m_sprite;
        sf::Vector2i        m_tilePostion;
        sf::Vector2f        m_velocity;

        const Level&        m_level;

        bool                m_isOnGround;
        bool                m_isMoving;
        bool                m_isAlive           =   true;
        bool                m_isCenterOrigin    =   false;

        std::vector<ComponentPtr>    m_components;
};

#endif // ENTITY_H
