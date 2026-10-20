#include "game.h"

Game::Game()
{
    window.create(sf::VideoMode(800,600), "Test", sf::Style::Close);
    window.setFramerateLimit(60);
    drawingWall = false;
    frame = 0;
    this->loop();
}

void Game::loop()
{
    while(window.isOpen())
    {
        frame++;
        events();
        if(!drawingWall)
        {
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                drawingWall = true;
                Wall wall(window);
                walls.push_back(wall);
            }
        }
        if(drawingWall)
            if(!sf::Mouse::isButtonPressed(sf::Mouse::Left))
                drawingWall = false;

        for(auto a: walls) a.logic(window);
        std::cout << walls.size();


        window.display();
    }
}

void Game::events()
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
