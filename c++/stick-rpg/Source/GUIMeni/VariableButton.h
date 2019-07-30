#ifndef VARIABLEBUTTON_INCLUDED
#define VARIABLEBUTTON_INCLUDED


#include "Component.h"
#include "../SpecialSprite/ClickableRectangle.h"

namespace GUI
{
    class VariableButton : public Component
    {
        public:
            VariableButton(std::string&& label,
                           std::function<void(void)> increase,
                           std::function<void(void)> decrease);

            void setPosition(const sf::Vector2f& position) override;

            void onUpdate   (const sf::RenderWindow& window, sf::Event e) override;
            void onDraw     (sf::RenderWindow& window) override;

            sf::FloatRect getBounds() const override;

        private:
            void onTouch();
            void onNoTouch();


            sf::RectangleShape m_labelRect;
            ClickableRectangle m_increase;
            ClickableRectangle m_decrease;
            sf::Text m_label;

    };
}

#endif // VARIABLEBUTTON_INCLUDED
