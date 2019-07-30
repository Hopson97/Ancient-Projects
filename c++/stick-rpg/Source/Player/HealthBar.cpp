#include "HealthBar.h"
#include "Health.h"

#include "../ResourceManager/ResourceHolder.h"
#include "../LevelRenderer.h"

HealthBar::HealthBar(const Health& health)
:   m_p_health  (&health)
{
    m_sprite.setTexture(&ResourceHolder::get().getTexure("hearts"));
    m_sprite.setSize   ({440, 44});

    for (int i = 10 ; i >= 0 ; i--)
    {
        m_stages.addFrame({0, i * 22, 220, 22}, sf::seconds(0.5));
    }
    m_sprite.setTextureRect(m_stages.getFrame());
}

void HealthBar::update()
{
    float h  = m_p_health->getValue();
    float mh = m_p_health->getMaxValue();
    float fr = 11;

    auto val = h / (mh / fr) - 1;
    if (val < 0) val = 0;

    m_sprite.setTextureRect(m_stages.getFrame(val));

    if (m_isPopped &&
        m_popTimer.getElapsedTime().asSeconds() > 0.3)
    {
        m_isPopped = false;
        m_sprite.setScale(1, 1);
        m_sprite.setFillColor(sf::Color::White);
    }
}

void HealthBar::draw(LevelRenderer& window)
{
    window.drawGUI(m_sprite);
}

void HealthBar::pop()
{
    if (!m_isPopped)
    {
        m_popTimer.restart();
        m_isPopped = true;

        m_sprite.setScale(2, 2);
        m_sprite.setFillColor(sf::Color::Yellow);
    }
}

