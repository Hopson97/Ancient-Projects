#ifndef SBASE_H_INCLUDED
#define SBASE_H_INCLUDED

#include <SFML/Graphics.hpp>

class Application;

namespace State
{
    class StateBase
    {
        public:
            StateBase(Application& application);
            virtual ~StateBase() = default;

            virtual void handleInput    () = 0;
            virtual void handleEvent    (sf::Event e) = 0;
            virtual void update         (float dt) = 0;
            virtual void fixedUpdate    (float dt) = 0;
            virtual void draw           (sf::RenderWindow& window) = 0;

        protected:
            Application* m_pApplication = nullptr;
    };
}

#endif // SBASE_H_INCLUDED
