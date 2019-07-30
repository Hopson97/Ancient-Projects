#ifndef SPLAYING_INCLUDED
#define SPLAYING_INCLUDED

#include "../Application.h"

#include "SBase.h"

#include "../Player/Player.h"

#include "../LevelRenderer.h"

namespace State
{
    class StatePlaying : public StateBase
    {
        public:
            StatePlaying(Application& application, Levels& stats);

            void handleInput    ();
            void handleEvent    (sf::Event e);
            void update         (float dt);
            void fixedUpdate    (float dt);
            void draw           (sf::RenderWindow& window);

        private:
            void loadLevel      ();

            std::vector<sf::RectangleShape> m_road;

            Player m_player;

            sf::View m_viewingArea;
            LevelRenderer m_levelRenderer;
    };
}

#endif // SPLAYING_INCLUDED
