#ifndef LEVELRENDERER_INCLUDED
#define LEVELRENDERER_INCLUDED

#include <SFML/Graphics.hpp>
#include <vector>

class LevelRenderer
{
    public:
        void drawGUI (const sf::Drawable& drawable);
        void drawReg (const sf::Drawable& drawable);

        void update (const sf::View& levelView, sf::RenderWindow& window);

    private:
        std::vector<const sf::Drawable*> m_guiDraws;
        std::vector<const sf::Drawable*> m_regDraws;
};

#endif // LEVELRENDERER_INCLUDED
