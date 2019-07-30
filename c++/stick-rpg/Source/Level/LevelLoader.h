#ifndef LEVELLOADER_INCLUDED
#define LEVELLOADER_INCLUDED

#include <SFML/Graphics.hpp>
#include <vector>

const sf::Vector2f BASE_LEVEL_OB_SIZE (256, 256);

class LevelLoader
{
    public:
        std::vector<sf::RectangleShape> loadLevel();

    private:
        std::vector<sf::RectangleShape> m_level;
};

#endif // LEVELLOADER_INCLUDED
