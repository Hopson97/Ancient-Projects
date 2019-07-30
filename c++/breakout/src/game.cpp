#include "game.h"

Game::Game()
{
    window.create(sf::VideoMode(730, 600), "Name");
    window.setFramerateLimit(60);

    addBricks();

    this->loop();
}//

void Game::loop()
{
    while(window.isOpen())
    {
        handleEvents();

        for(auto &obj: objs) obj->logic(window);
        ball.logic(window);
        paddle.logic(window);

        window.display();
    }
}

void Game::collisions()
{

}

void Game::addBricks()
{
    for(int i = 0; i < 12; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            int x = i * 60 + 10;
            int y = j * 30 + 10;


            this->objs.emplace_back(new Brick(x, y));
        }
    }
}


void Game::handleEvents()
{
    window.clear();

    while(window.pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
        {
            window.close();
        }
    }
}















