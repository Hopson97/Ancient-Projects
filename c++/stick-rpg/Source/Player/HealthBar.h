#ifndef HealthBar_H_INCLUDED
#define HealthBar_H_INCLUDED


#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "../Animation.h"

class Health;
class LevelRenderer;

class HealthBar
{
    public:
        HealthBar(const Health& health);

        void update     ();
        void draw       (LevelRenderer& window);

        void pop        ();

    private:
        const Health*   m_p_health;
        Animation       m_stages;
        sf::RectangleShape m_sprite;

        bool m_isPopped;
        sf::Clock m_popTimer;
};

#endif // HealthBar_H_INCLUDED
