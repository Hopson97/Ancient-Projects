#include "Bubbles.h"

#include <iostream>

#include "../Util/Random.h"
#include "../Application.h"

#include "../ResourceManager/ResourceHolder.h"

constexpr static int    SIZE            = 25,
                        MIN_LIFE_SECS   = 5,
                        MAX_LIFE_SECS   = 8;

Bubble::Bubble()
{
    auto red    = (sf::Uint8)Random::get().intInRange(175, 230);
    auto green  = (sf::Uint8)Random::get().intInRange(175, 230);

    m_sprite.setFillColor({red, green, 200});
    reset();
}

void Bubble::update(float dt)
{
    auto xMove = std::sin(m_lifeTime.getElapsedTime().asSeconds()) * m_speed * dt;
    auto yMove = -m_speed * dt;

    m_sprite.move(xMove, yMove);
    m_sprite.setTexture(&ResourceHolder::getTexure("bubble"));

    if (m_lifeTime.getElapsedTime() > m_deathTime)
    {
        reset();
    }

    doFade();
}

void Bubble::doFade()
{
    constexpr auto halfPi = 3.14159f / 2;

    auto fillColour     = m_sprite.getFillColor();
    auto outlineColour  = sf::Color::Black;

    auto timeLived = m_lifeTime.getElapsedTime().asSeconds();
    auto deathTime = m_deathTime.asSeconds();

    //1 cycle = time * halfPi / lifespan
    //* 2 to half the cycle
    auto result = std::sin((timeLived * (halfPi / deathTime)) * 2 );

    auto alphaValue = result * 255;

    fillColour.a    = alphaValue;
    outlineColour.a = alphaValue;

    m_sprite.setFillColor   (fillColour);
    m_sprite.setOutlineColor(outlineColour);
}


void Bubble::draw(sf::RenderWindow& window)
{
    window.draw(m_sprite);
}

void Bubble::reset()
{
    m_sprite.setRadius(Random::get().floatInRange(SIZE/ 4, SIZE));
    m_deathTime     =   sf::seconds(Random::get().intInRange(MIN_LIFE_SECS, MAX_LIFE_SECS));
    m_speed         =   Random::get().intInRange(  m_sprite.getRadius() - 5,
                                                    m_sprite.getRadius() + 5);

    auto x = Random::get().floatInRange(0,      WINDOW_WIDTH - SIZE);
    auto y = Random::get().floatInRange(SIZE,   WINDOW_HEIGHT);

    m_sprite.setPosition({x, y});

    m_lifeTime.restart();
}
