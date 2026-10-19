#include "powder.h"

Powder::Powder(sf::RenderWindow &w)
{
    //global::powderCount++;
    xVel = 0;
    yVel = 0;
    sf::Vector2f v(sf::Vector2f(1, 1));
    dot.setSize(v);
    dot.setFillColor(sf::Color::White);
    dot.setOrigin({0, 0});
    dot.setPosition({(float)sf::Mouse::getPosition(w).x, (float)sf::Mouse::getPosition(w).y});

}

int Powder::draw(sf::RenderWindow &w)
{
    int del; //1 means remove, 0 means leave alone
    del = logic();

    if(getXVel() > 0 || getYVel() >0)
        update();


    w.draw(dot);
    if (del == 1) std::cout << del << std::endl;
    return del;
}

int Powder::logic()
{
    //setXVel(getXVel()/9.8);
    if(getYPos() < 510.f)
    {
        setYVel(getYVel() + 0.1f);
        return 0;
    }
    else if(getYPos() > 500.f)
    {
        //random rand;
        //int newYVel = 0 - (getYVel()/1.1);
        //setYVel(newYVel);
        setYVel(-25);
        return 0;
    }
    if(getXPos() < 350.f || getXPos() > 800.f)
    {
        return 1;
    }
    return 0;
}

void Powder::update()
{
    dot.move({getXVel(), getYVel()});
}










void Powder::setPos(float x, float y)
{
    dot.setPosition({x, y});
}

void Powder::setXVel(float x)
{
    xVel = x;
}
float Powder::getXVel() const
{
    return xVel;
}
void Powder::setYVel(float y)
{
    yVel = y;
}
float Powder::getYVel() const
{
    return yVel;
}

float Powder::getXPos() const
{
    return dot.getPosition().x;
}
float Powder::getYPos() const
{
    return dot.getPosition().y;
}

Powder::~Powder()
{

}
