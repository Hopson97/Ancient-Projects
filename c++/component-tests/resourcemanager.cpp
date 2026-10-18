#include "resourcemanager.h"

ResourceManager::ResourceManager()
{
    std::string filePath;

    addTexture("res/zombie.png", "zombie", zombieTx);
    addTexture("res/player.png", "player", playerTx);
}

sf::Texture ResourceManager::getTexture(std::string name)
{
    return textures[name];
}

 void ResourceManager::addTexture(std::string path,
                                  std::string name,
                                  sf::Texture &texture)
{
    if(!texture.loadFromFile(path))
    {
        std::cerr   << "Could not load texture: "
                    << name << "."
                    << std::endl;
        return;
    }
    textures[name] = texture;
    texture.setSmooth(true);
}
