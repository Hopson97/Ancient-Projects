#include "VariableButton.h"
#include "ColumnMenu.h"

#include "../ResourceManager/ResourceHolder.h"

namespace GUI
{
    VariableButton::VariableButton(std::string&& label,
                             std::function<void(void)> increase,
                             std::function<void(void)> decrease)
    :   m_increase  (   increase,
                        std::bind(&VariableButton::onTouch,   this),
                        std::bind(&VariableButton::onNoTouch, this))
    ,   m_decrease  (   decrease,
                        std::bind(&VariableButton::onTouch,   this),
                        std::bind(&VariableButton::onNoTouch, this))
    {
        m_increase.setTexture(&ResourceHolder::get().getTexure("rarrow"));
        m_decrease.setTexture(&ResourceHolder::get().getTexure("larrow"));
        m_labelRect.setTexture(&ResourceHolder::get().getTexure("gui1"));

        m_increase.setSize({BASE_HEIGHT, BASE_HEIGHT});
        m_decrease.setSize({BASE_HEIGHT, BASE_HEIGHT});


        m_labelRect.setSize({BASE_WIDTH,
                          BASE_HEIGHT});


        m_labelRect.setOutlineThickness(5);
        m_labelRect.setOutlineColor(sf::Color::Black);

        m_label.setFont(ResourceHolder::get().getFont("arial"));
        m_label.setString(std::move(label));
    }

    void VariableButton::setPosition(const sf::Vector2f& position)
    {
        m_labelRect.setPosition(position);
        m_label.setPosition(position);

        m_label.move(m_labelRect.getGlobalBounds().width / 2 - m_label.getGlobalBounds().width / 2,
                     m_label.getGlobalBounds().height / 2);

        m_increase.setPosition({position.x + m_labelRect.getGlobalBounds().width + 10,
                                position.y});

        m_decrease.setPosition({position.x - m_decrease.getGlobalBounds().width - 10,
                                position.y});
    }

    void VariableButton::onUpdate(const sf::RenderWindow& window, sf::Event e)
    {
        m_increase.testForInteration(window, e);
        m_decrease.testForInteration(window, e);
    }

    void VariableButton::onDraw(sf::RenderWindow& window)
    {
        window.draw(m_increase);
        window.draw(m_decrease);

        window.draw(m_labelRect);
        window.draw(m_label);
    }

    sf::FloatRect VariableButton::getBounds() const
    {
        return m_labelRect.getGlobalBounds();
    }


    void VariableButton::onTouch()
    { }

    void VariableButton::onNoTouch()
    { }
}
