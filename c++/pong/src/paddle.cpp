#include "paddle.h"



Paddle::Paddle(pType _t):
    type(_t)
{
    paddleR.setPosition(type, 200);
    sf::Vector2f pSize(25, 200);
    paddleR.setSize(pSize);

    paddleR.setOutlineColor(sf::Color::Blue);
    paddleR.setOutlineThickness(3);

    sf::Vector2f orig(paddleR.getSize().x / 2, paddleR.getSize().y / 2);
    paddleR.setOrigin(orig);
}

void Paddle::logic(sf::RenderWindow &w, Ball &ball)
{
    input(ball);


    limits();

    paddleR.move(0, vel);

    w.draw(paddleR);
}

void Paddle::input(Ball &ball)
{
    if(type == PLAYER)
        p_input(ball);
    else if(type == COMP)
        c_input(ball);
    else if(type == PLAYER2)
        p2_input(ball);
}

void Paddle::p_input(Ball &ball)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        vel -= 0.2;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        vel += 0.2;
    }

    if(ball.getPos().x <= paddleR.getPosition().x + (paddleR.getSize().x/2))
    {
        if(ballInYBounds(ball))
        {
            ball.setDir(RIGHT);
            int dFromCen = -((paddleR.getPosition().y - ball.getPos().y)/10);
            ball.setYVel(dFromCen);
        }
    }

}

void Paddle::c_input(Ball &ball)
{
    if(ball.getPos().y > paddleR.getPosition().y)
    {
        vel += 0.2;
    }
    else if(ball.getPos().y < paddleR.getPosition().y)
    {
        vel -= 0.2;
    }
    if(ball.getPos().x >= paddleR.getPosition().x - (paddleR.getSize().x/2))
    {
        if(ballInYBounds(ball))
         {
            ball.setDir(LEFT);
            int dFromCen = -((paddleR.getPosition().y - ball.getPos().y)/10);
            ball.setYVel(dFromCen);
         }
    }
}

void Paddle::p2_input(Ball &ball)
{

}


void Paddle::limits()
{
    if(vel > 5)
    {
        vel = 4.9;
    }
    else if(vel < -5)
    {
        vel = -4.9;
    }

    if(vel > 0) vel -= 0.1; //Slow paddle down
    if(vel < 0) vel += 0.1; //Slow paddle down

    if((vel > 0 && vel < 0.1)   //Make it so paddle is smoother
       ||
       (vel < 0 && vel > -0.1)) vel = 0;
}



bool Paddle::ballInYBounds(Ball &ball)
{
    if(ball.getPos().y      <= paddleR.getPosition().y + (paddleR.getSize().y/2)
       && ball.getPos().y   >= paddleR.getPosition().y - (paddleR.getSize().y/2))
        return true;
    else
        return false;
}













