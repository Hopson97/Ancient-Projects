#ifndef COMPONENT_H_INCLUDED
#define COMPONENT_H_INCLUDED

#include <SFML/Graphics.hpp>

namespace GUI
{
    class Component
    {
        public:
            virtual ~Component() = default;

            void update(const sf::RenderWindow& window, sf::Event e);
            void draw  (sf::RenderWindow& window);

            virtual void setPosition(const sf::Vector2f& position) = 0;

            virtual sf::FloatRect getBounds() const = 0;

        private:
            virtual void onUpdate(const sf::RenderWindow& window, sf::Event e){}
            virtual void onDraw  (sf::RenderWindow& window){}
    };
}

#endif // COMPONENT_H_INCLUDED
