#include "bird.h"

Bird::Bird()
{
    bird.setPosition(120,100);
    std::string t_path = "res/bee.png";
    if(!texture.loadFromFile(t_path))
        std::cerr << "bee.png not found." << std::endl;

    bird.setTexture(texture);
    bird.setScale(4.5,4.5);

    setUpAnim();
}
/*
==========================================================================
Bird::logic defines any thing that the bird can do in one method
==========================================================================
*/


void Bird::logic(sf::RenderWindow &window)
{
    input();

    update();

    window.draw(bird);
}

void Bird::input()
{
    int inputDelay = 50;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && inputted >= inputDelay)
    {
        yVel += 8;
        inputted = 0;
    }
    if(inputted < inputDelay)
        inputted++;
}

void Bird::update()
{
    if(bird.getPosition().y < gbl::WIN_HEIGHT)
    {
        yVel -= 0.1;
    }
    if(yVel < -5) yVel = -4.9;
    if(bird.getPosition().y <= 11 )
    {
        bird.setPosition(bird.getPosition().x, 15);
        yVel = 0;
    }
    std::cout << yVel << std::endl;
    bird.setPosition(120, bird.getPosition().y - yVel);
    fly.animate(bird);
}


void Bird::setUpAnim()
{
    fly.setFrameGap(8);
    sf::IntRect f1(0,0,16,16);
    fly.addFrame(f1);
    sf::IntRect f2(16,0,16,16);
    fly.addFrame(f2);
    sf::IntRect f3(32,0,16,16);
    fly.addFrame(f3);
    fly.addFrame(f2);
}

void Bird::preLogic(sf::RenderWindow &w)
{
    fly.animate(bird);
    w.draw(bird);
}
