#include "Application.h"

#include "States/SMainMenu.h"

#include <cstdint>
#include <iostream>

Application::Application(std::string&& appName)
:   m_window    ({WINDOW_WIDTH, WINDOW_HEIGHT}, std::move(appName))
{
    m_window.setFramerateLimit(60);
    m_window.setPosition({0, 0});
    pushState<State::MainMenu>(*this);
}


void Application::runMainLoop()
{
    constexpr uint32_t  TICKS_PER_FRAME = 30;
    const sf::Time      MS_PER_TICK     = sf::seconds((float)1 / (float)TICKS_PER_FRAME);

    uint32_t tickCount = 0;

    sf::Clock timer;

    auto lastTime   = timer.getElapsedTime();
    auto tickLag    = sf::Time::Zero;

    while (m_window.isOpen())
    {
        if (m_states.empty())
        {
            break;
        }
        auto& state         = currentState();
        auto currentTime    = timer.getElapsedTime();
        auto elapsed        = currentTime - lastTime;
        lastTime            = currentTime;
        tickLag             += elapsed;

        state.handleInput();

        while (tickLag >= MS_PER_TICK)
        {
            tickCount++;
            state.fixedUpdate (elapsed.asSeconds());
            tickLag -= MS_PER_TICK;
        }
        state.update (elapsed.asSeconds());

        m_window.clear({45, 125, 200});
        currentState().draw (m_window);
        m_window.display();
        handleEvents();
    }
}


const sf::RenderWindow& Application::getWindow() const
{
    return m_window;
}

bool shouldPopState = false;

void Application::popState()
{
    shouldPopState = true;
}


void Application::handleEvents()
{
    sf::Event e;
    while (m_window.pollEvent(e))
    {
        currentState().handleEvent(e);
        switch (e.type)
        {
            case sf::Event::Closed:
                m_window.close();
                break;

            default:
                break;
        }
    }

    if (shouldPopState)
    {
        m_states.pop_back();
        shouldPopState = false;
    }
}


State::StateBase& Application::currentState()
{
    if (m_states.empty())
    {
        throw std::out_of_range("Tried to access game state, but there are none!");
    }
    return *m_states.back();
}
