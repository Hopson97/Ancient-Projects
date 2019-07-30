#ifndef CLICKABLERECTANGLE_H_INCLUDED
#define CLICKABLERECTANGLE_H_INCLUDED

#include <SFML/Graphics.hpp>

#include <functional>

class ClickableRectangle : public sf::RectangleShape
{
    public:
        ClickableRectangle(std::function<void(void)> onClick,
                           std::function<void(void)> onRollover,
                           std::function<void(void)> onNoTouch);

        void testForInteration(const sf::RenderWindow& window, sf::Event e);

    private:
        bool isClick(sf::Event e);

        std::function<void(void)> m_onClick;
        std::function<void(void)> m_onRollover;
        std::function<void(void)> m_onNoTouch;
};

#endif // CLICKABLERECTANGLE_H_INCLUDED
