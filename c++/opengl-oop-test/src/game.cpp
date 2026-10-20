#include "game.h"

#include <GL/glew.h>
#include <iostream>

#include "rawmodel.h"


Game::Game()
:   mWindow     (sf::VideoMode(1280, 700), "Test", sf::Style::Default, sf::ContextSettings(8))
,   initGlew    ()
{
    mWindow.setFramerateLimit(60);
    glEnable(GL_DEPTH_TEST);
}

void Game::addCubes(SquareShader& shader)
{
    float size = 20;
    for(float x = -size; x < size; x++)
    {
        for(float z = 0; z > -size * 3; z--)
        {
            mCubes.push_back(Cube(x, 7, z, shader));
        }

    }
}


void Game::runGame()
{
    sf::Clock c;
    SquareShader shader("shaders/squareVert.glsl", "shaders/squareFrag.glsl");

    addCubes(shader);

    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);

    glViewport(0, 0, 1280, 700);

    std::cout << mCubes.size() << std::endl;

    while (mWindow.isOpen()) {
        glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

        for(auto& cube : mCubes) {
            cube.draw(shader, c.getElapsedTime().asSeconds());
        }

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
