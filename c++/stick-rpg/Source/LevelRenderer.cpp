#include "LevelRenderer.h"

void LevelRenderer::drawGUI(const sf::Drawable& drawable)
{
    m_guiDraws.push_back(&drawable);
}

void LevelRenderer::drawReg(const sf::Drawable& drawable)
{
    m_regDraws.push_back(&drawable);
}

void LevelRenderer::update(const sf::View& levelView, sf::RenderWindow& window)
{
    window.setView(levelView);
    for (auto& obj : m_regDraws)
    {
        window.draw(*obj);
    }

    window.setView(window.getDefaultView());
    for (auto& obj : m_guiDraws)
    {
        window.draw(*obj);
    }

    m_regDraws.clear();
    m_guiDraws.clear();
}
