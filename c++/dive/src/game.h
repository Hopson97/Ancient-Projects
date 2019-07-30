#ifndef GAME_H
#define GAME_H

#include "HopEngine/HopsonEngine.h"

#include <string>
#include <memory>

#include "backgroundobjects.h"
#include "cloud.h"
#include "player.h"

class Game
{
    public:
        Game();
    protected:
    private:

        void initLoop();

        void startPlay(sf::Sprite &s);

        void loop();

        void handleEvents();

        void setBg(std::string path);

        void addClouds(int amount);

    private:
        sf::RenderWindow window;
        sf::Event event;

        sf::Sprite bg;
        sf::Texture bgT;
        sf::Color bgColor;

        sf::View camera;

        Player player;

        std::vector<std::unique_ptr<BackgroundObjects>> bgObjs;
};

#endif // GAME_H
