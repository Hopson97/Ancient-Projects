#include "game.h"

#include "Entites/Player/player.h"
#include "globals.h"

Game::Game()
{
    gameLoop();
}

void Game::gameLoop()
{
    sf::RenderWindow window(
        sf::VideoMode({(unsigned)gbl::screenWidth, (unsigned)gbl::screenHeight}), // Create window
                            "Rotation Test",    //Title of the window
                            sf::Style::Close);  //Window is not resizeable
    window.setFramerateLimit(60);               //Limit frame rate to 60
//=================================================================================
    sf::Texture bg;
    if(!bg.loadFromFile("bg.png"));
    sf::Sprite bG(bg);
        //=================================================================================
    Player player;                  //Create player instance


    while(window.isOpen())          //While window is open
    {
        while(auto event = window.pollEvent())  //Poll window events
            if(event->is<sf::Event::Closed>()) //If the X is pressed
                window.close();             //Close the window

        window.clear();         //Clear the game screen
//=================================================================================
        window.draw(bG);
//=================================================================================
        player.logic(window);   //Activate "player logic"


        window.display();       //Display window stuff
    }
}














