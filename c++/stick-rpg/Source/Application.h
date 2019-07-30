#ifndef APPLICATION_H
#define APPLICATION_H

#include <string>
#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>

#include "States/SBase.h"

constexpr static int    WINDOW_WIDTH = 1280,
                        WINDOW_HEIGHT = 720;

class Application
{
    public:
        Application(std::string&& appName);

        void runMainLoop();

        template<typename T, typename... Args>
        void pushState(Args&&... args)
        {
            m_states.push_back(std::make_unique<T>(std::forward<Args>(args)...));
        }

        void popState();

        const sf::RenderWindow& getWindow() const;

    private:
        void handleEvents();
        State::StateBase& currentState();


        std::vector<std::unique_ptr<State::StateBase>> m_states;

        sf::RenderWindow m_window;
};

#endif // APPLICATION_H
