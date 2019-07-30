#include "SMainMenu.h"

#include <iostream>

#include "../Application.h"

#include "../Util/Random.h"
#include "../ResourceManager/ResourceHolder.h"

#include "../GUIMeni/BasicButton.h"
#include "../GUIMeni/VariableButton.h"
#include "../GUIMeni/Banner.h"

#include "SPlaying.h"


namespace State
{
    MainMenu::MainMenu(Application& app)
    :   StateBase   (app)
    ,   m_frontMenu         (0.0f)
    ,   m_statSelectionMenu (0.0f)
    {
        m_menuMusic.openFromFile("res/music/menu.ogg");
        m_menuMusic.play();
        m_menuMusic.setLoop(true);

        initMenu();

        m_skillPointsDisplay.move(0, 220);
        m_skillPointsDisplay.setFont(ResourceHolder::getFont("arial"));
        m_skillPointsDisplay.setCharacterSize(20);
    }

    MainMenu::~MainMenu()
    {
        m_menuMusic.stop();
    }

    void MainMenu::handleInput()
    {

    }

    void MainMenu::handleEvent(sf::Event e)
    {
        m_activeMenu->update(m_pApplication->getWindow(), e);
    }

    void MainMenu::update(float dt)
    {
        for (auto& bubble : m_bubbles)
        {
            bubble.update(dt);
        }

        m_skillPointsDisplay.setString("Stats: \n\
         Intelligence:  " + std::to_string(m_stats.intelligence)    + "\n\
         Charm:         " + std::to_string(m_stats.charm)           + "\n\
         Strenth:       " + std::to_string(m_stats.strength)        + "\n\
         \nSkill Points Remaining: " + std::to_string(m_skillPoints));
    }

    void MainMenu::fixedUpdate(float dt)
    { }

    void MainMenu::draw(sf::RenderWindow& window)
    {
        if (m_menuState == Menu_State::Attribute)
        {
            window.draw(m_skillPointsDisplay);
        }


        for (auto& bubble : m_bubbles)
        {
            bubble.draw(window);
        }
        m_activeMenu->draw(window);
    }

    void MainMenu::initMenu()
    {
        m_frontMenu.addComponent<GUI::Banner>(ResourceHolder::getTexure("logo"),
                                              sf::Vector2f((float)WINDOW_WIDTH, GUI::BASE_HEIGHT * 2));

        m_frontMenu.addComponent<GUI::BasicButton>("Play",
        [&]()
        {
            m_menuState     = Menu_State::Attribute;
            m_activeMenu    = &m_statSelectionMenu;
            m_skillPoints   = 10;
            m_stats.reset();
        });

        m_frontMenu.addComponent<GUI::BasicButton>("Exit",
        [&]()
        {
            m_pApplication->popState();
        });

        m_statSelectionMenu.addComponent<GUI::Banner>(ResourceHolder::getTexure("stat_ban"),
                                              sf::Vector2f((float)WINDOW_WIDTH, GUI::BASE_HEIGHT * 2));

        m_statSelectionMenu.addComponent<GUI::BasicButton>("Confirm",
        [&]()
        {
            ///@TODO Uncomment this line
            //if (m_skillPoints == 0)
            {
                m_menuMusic.stop();
                m_menuState = Menu_State::Front;
                m_activeMenu = &m_frontMenu;
                m_pApplication->pushState<State::StatePlaying>(*m_pApplication, m_stats);
            }

        });

        addAttribute("Intelligence",    m_stats.intelligence);
        addAttribute("Charm",           m_stats.charm);
        addAttribute("Strength",        m_stats.strength);

        m_statSelectionMenu.addComponent<GUI::BasicButton>("Back",
        [&]()
        {
            m_menuState = Menu_State::Front;
            m_activeMenu = &m_frontMenu;
        });
    }

    void MainMenu::addAttribute(std::string&& name, int& stat)
    {
        m_statSelectionMenu.addComponent<GUI::VariableButton>(std::move(name),
        [&]()
        {
            if (m_skillPoints > 0)
            {
                stat++;
                m_skillPoints--;
            }
        },
        [&]()
        {
            if (stat > 0)
            {
                stat--;
                m_skillPoints++;
            }
        });
    }



}
