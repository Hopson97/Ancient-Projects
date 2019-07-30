#ifndef BUBBLES_H_INCLUDED
#define BUBBLES_H_INCLUDED

#include <SFML/Graphics.hpp>

class Bubble
{
    public:
        Bubble      ();
        void update (float dt);
        void draw   (sf::RenderWindow& window);

    private:
        void reset();

        void doFade();

        sf::CircleShape m_sprite;


        sf::Clock   m_lifeTime;
        sf::Time    m_deathTime;

        float m_speed;
};

#endif // BUBBLES_H_INCLUDED
