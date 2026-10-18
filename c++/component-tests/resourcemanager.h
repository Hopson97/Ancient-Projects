#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <SFML/Graphics.hpp>

#include <vector>
#include <memory>
#include <string>
#include <iostream>

class ResourceManager
{
    public:
        ResourceManager();
        sf::Texture getTexture(std::string name);
    private:
        void addTexture(std::string path,
                        std::string name,
                        sf::Texture &texture);
    private:
        std::map<std::string, sf::Texture> textures;

        sf::Texture zombieTx;
        sf::Texture playerTx;

};

#endif // RESOURCEMANAGER_H
