#include "LevelLoader.h"

#include <fstream>

#include "../ResourceManager/ResourceHolder.h"

std::vector<sf::RectangleShape> LevelLoader::loadLevel()
{
    sf::Vector2f size = BASE_LEVEL_OB_SIZE;

    auto getRoad = [&](float tx, float ty)
    {
        sf::RectangleShape road(size);
        road.setPosition(tx * size.x, ty * size.y);
        return road;
    };

    auto makeHori = [&](float tx, float ty)
    {
        auto road = getRoad(tx, ty);
        road.setTexture(&ResourceHolder::get().getTexure("roadh"));
        return road;
    };

    auto makeVertical = [&](float tx, float ty)
    {
        auto road = getRoad(tx, ty);
        road.setTexture(&ResourceHolder::get().getTexure("roadv"));
        return road;
    };

    auto makeCenter = [&](float tx, float ty)
    {
        auto road = getRoad(tx, ty);
        road.setTexture(&ResourceHolder::get().getTexure("roadm"));
        return road;
    };

    sf::Vector2i currLocation;

    std::ifstream inFile("res/layout.txt");
    if (!inFile.is_open())
    {
        throw std::runtime_error ("Unable to load level");
    }

    std::string line;
    while (std::getline(inFile, line))
    {
        for (int i = 0; i < line.length(); i++)
        {
            currLocation.x = i;
            switch (line[i])
            {
                case '.':
                    break;

                case 'h':
                    m_level.push_back(makeHori(currLocation.x, currLocation.y));
                    break;

                case 'v':
                    m_level.push_back(makeVertical(currLocation.x, currLocation.y));
                    break;

                case 'm':
                    m_level.push_back(makeCenter(currLocation.x, currLocation.y));
                    break;
            }
        }
        currLocation.y++;
    }

    return m_level;
}

