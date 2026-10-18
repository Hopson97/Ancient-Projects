#include "game.h"

Game::Game()
{
    window.create(sf::VideoMode(800,600), "test");
    window.setFramerateLimit(60);

    this->mainLoop();
}

void Game::mainLoop()
{
    ResourceManager tex;

    std::unique_ptr<Player> p(new Player(tex.getTexture("player"), window));
    entities.push_back(std::move(p));
    entities.emplace_back(new Zombie(tex.getTexture("zombie"), window));

    while(window.isOpen())
    {
        this->events();
        this->update();
    }
}

void Game::update()
{
    window.clear(sf::Color::Blue);

    for(auto &ent: entities) ent->logic(window);

    window.display();
}

void Game::events()
{
    sf::Event event;
    while(window.pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
        {
            window.close();
        }
    }
}
