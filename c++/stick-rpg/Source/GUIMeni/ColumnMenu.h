#ifndef COLUMNMENU_H_INCLUDED
#define COLUMNMENU_H_INCLUDED

#include <vector>
#include <memory>

#include "Component.h"
#include "../Application.h"

namespace GUI
{
    constexpr static int    BASE_WIDTH  = WINDOW_WIDTH / 2,
                            BASE_HEIGHT = 64;

    class ColumnMenu
    {
        public:
            ColumnMenu(float startY);

            void update(const sf::RenderWindow& window, sf::Event e);
            void draw  (sf::RenderWindow& window);

            template<typename T, typename... Args>
            void addComponent(Args&&... args)
            {
                m_components.push_back(std::make_unique<T>(std::forward<Args>(args)...));

                initComponent(*m_components.back().get());

            }

        private:
            void initComponent(Component& comp);

            std::vector<std::unique_ptr<GUI::Component>> m_components;

            const float m_baseComponentX;
            float m_yPosition = 0;
    };
}

#endif // COLUMNMENU_H_INCLUDED
