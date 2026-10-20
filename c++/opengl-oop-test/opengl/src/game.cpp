#include "game.h"

#include <GL/glew.h>

#include "rawmodel.h"
#include "sprite.h"

Game::Game()
:   mWindow     (sf::VideoMode(1280, 700), "Test", sf::Style::Default, sf::ContextSettings(8))
,   initGlew    ()
{

}

void Game::runGame()
{

    sf::Clock c;

    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);

    while (mWindow.isOpen()) {
        glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);



        myCube.draw();




        mWindow.display();
        pollEvents();
    }
}

void Game::pollEvents()
{
    sf::Event e;
    while ( mWindow.pollEvent( e ) ) {
        if (e.type == sf::Event::Closed) {
            mWindow.close();
        }
    }
}
