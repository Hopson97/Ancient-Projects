#ifndef BANNER_H_INCLUDED
#define BANNER_H_INCLUDED

#include "Component.h"

namespace GUI
{
    class Banner : public GUI::Component
    {
        public:
            Banner(const sf::Texture& texture, const sf::Vector2f& size);

            void setPosition(const sf::Vector2f& position) override;

            void onDraw     (sf::RenderWindow& window) override;

            sf::FloatRect getBounds() const override;

        private:
            sf::RectangleShape m_bannerSprite;
    };
}

#endif // BANNER_H_INCLUDED
