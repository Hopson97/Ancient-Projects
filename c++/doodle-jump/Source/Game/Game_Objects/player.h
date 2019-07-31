#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

class Player
{
    public:
        Player();

        void setTexture ( const sf::Texture& texture );

        void draw       ();

        bool isFalling  () const;

        const sf::Vector2f& getPosition() const;
        const sf::Vector2f& getVelocity() const;

        void bounce     ();
        void changeX    ( float x );

        void update     ( float dt);


        constexpr static float SIZE_X = 32;
        constexpr static float SIZE_Y = 64;
        constexpr static float BOUNCE_SPEED = 500;
        constexpr static float GRAVITY = 10;

    private:
        sf::RectangleShape m_sprite;

        sf::Vector2f m_velocity;

        constexpr static float MAX_FALL = 450;
        constexpr static float MAX_SPEED = 300;
};

#endif // PLAYER_H
