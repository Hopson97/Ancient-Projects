#include "game.h"

Game::Game()
{
    window.create(sf::VideoMode(800,600), "Pong by Matthew Hopson");
    window.setFramerateLimit(60);

    this->menuState();
}

void Game::menuState()
{
    Button play(400,100, 100, 300, "Play!");
    Button help(400,100, 100, 450, "Help!");

    setBG("res/menuBG.png");


    while(window.isOpen())
    {
        resetScreen();

        if(play.buttonClicked(window))
            playLoop();

        if(help.buttonClicked(window));


        window.display();
    }
}

void Game::playLoop()
{
    setBG("res/playBG.png");
    Paddle player(PLAYER);
    Paddle computer(COMP);
    Ball ball;

    while(window.isOpen())
    {
        resetScreen();


        player.logic(window, ball);
        computer.logic(window, ball);
        ball.logic(window);

        window.display();
    }
}




void Game::pollEvents()
{
    while(window.pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
        {
            window.close();
        }
    }

}

void Game::setBG(std::string path)
{
    if(!bgT.loadFromFile(path));
    bgS.setTexture(bgT);
}

void Game::resetScreen()
{
    pollEvents();
    window.clear();
    window.draw(bgS);
}








