#include "game.h"

Game::Game()
{
    window.create(sf::VideoMode(gbl::WIN_WIDTH, gbl::WIN_HEIGHT), "Flappy Bug");
    window.setFramerateLimit(60);

    this->prePlayState();
}

void Game::mainLoop(/* bird clock*/)
{





}


void Game::prePlayState()
{
    Bird bird;

    while(window.isOpen())
    {
        handleWinEvents();


        bird.preLogic(window);


        window.display();
    }
}

void Game::handleWinEvents()
{
    window.clear();
    while(window.pollEvent(eventHandler))
    {
        if(eventHandler.type == sf::Event::Closed)
        {
            window.close();
        }
    }
}
