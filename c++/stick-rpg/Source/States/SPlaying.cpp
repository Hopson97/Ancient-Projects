#include "SPlaying.h"

#include "../ResourceManager/ResourceHolder.h"

#include "../Animation.h"

#include <fstream>
#include <iostream>

#include "../Level/LevelLoader.h"

Animation animation;

namespace State
{
    StatePlaying::StatePlaying(Application& application, const Levels& stats)
    :   StateBase   (application)
    ,   m_player    (stats)
    {
        m_viewingArea.setCenter({(float)BASE_LEVEL_OB_SIZE.x * 4.5f, 0});
        m_viewingArea.setViewport({{0, 0}, {1, 1}});

        loadLevel();
    }

    void StatePlaying::handleInput()
    {
        auto pressed = [](sf::Keyboard::Key key)
        {
            return sf::Keyboard::isKeyPressed(key);
        };

        float speed = 3;

        if (pressed(sf::Keyboard::Key::W))
        {
            m_player.addForce({0, -speed});
        }
        if (pressed(sf::Keyboard::Key::S))
        {
            m_player.addForce({0, speed});
        }
        if (pressed(sf::Keyboard::Key::A))
        {
            m_player.addForce({-speed, 0});
        }
        if (pressed(sf::Keyboard::Key::D))
        {
            m_player.addForce({speed, 0});
        }
    }

    void StatePlaying::handleEvent(sf::Event e)
    {

    }

    void StatePlaying::update(float dt)
    {
        m_viewingArea.move(m_player.getVelocity() * dt);
        m_player.update();
    }

    void StatePlaying::fixedUpdate(float dt)
    {

    }

    void StatePlaying::draw(sf::RenderWindow& window)
    {
        for (auto& road : m_road)
        {
            m_levelRenderer.drawReg(road);
        }
        m_player.draw(m_levelRenderer);

        m_levelRenderer.update(m_viewingArea, window);
    }

    void StatePlaying::loadLevel()
    {
        LevelLoader loader;
        m_road = std::move(loader.loadLevel());
    }
}   //Boo!












































