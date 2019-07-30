#include "BasicButton.h"

#include "ColumnMenu.h"

#include "../ResourceManager/ResourceHolder.h"

namespace GUI
{
    BasicButton::BasicButton(std::string&& label, std::function<void(void)> onClick)
    :   m_button    (onClick,
                     std::bind(&BasicButton::onTouch,   this),
                     std::bind(&BasicButton::onNoTouch, this))
    {
        m_button.setSize({BASE_WIDTH,
                          BASE_HEIGHT});
        m_button.setTexture(&ResourceHolder::get().getTexure("gui1"));

        m_button.setOutlineThickness(5);
        m_button.setOutlineColor(sf::Color::Black);

        m_label.setFont(ResourceHolder::get().getFont("arial"));
        m_label.setString(std::move(label));
    }

    void BasicButton::setPosition(const sf::Vector2f& position)
    {
        m_button.setPosition(position);
        m_label.setPosition(position);

        m_label.move(m_button.getGlobalBounds().width / 2 - m_label.getGlobalBounds().width / 2,
                     m_label.getGlobalBounds().height / 2);
    }

    void BasicButton::onUpdate(const sf::RenderWindow& window, sf::Event e)
    {
        m_button.testForInteration(window, e);
    }

    void BasicButton::onDraw(sf::RenderWindow& window)
    {
        window.draw(m_button);
        window.draw(m_label);
    }

    void BasicButton::onTouch()
    {
        m_button.setFillColor({200, 200, 200});
    }

    void BasicButton::onNoTouch()
    {
        m_button.setFillColor(sf::Color::White);
    }

    sf::FloatRect BasicButton::getBounds() const
    {
        return m_button.getGlobalBounds();
    }



}
