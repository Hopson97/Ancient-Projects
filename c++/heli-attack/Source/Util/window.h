#ifndef WINDOW_H
#define WINDOW_H

#include <SFML/Graphics.hpp>

namespace Win_Info
{
    constexpr int HEIGHT = 700;
    constexpr int WIDTH  = 1280;
}

class Window
{
    public:
        Window();

        sf::RenderWindow&
        get         ();

        void
        clear       ( const sf::Color& colour = { 0, 0, 0 } );

        void
        update      ();

        bool
        isOpen      () const;

        const sf::Vector2f&
        getCenter   () const;

        const sf::Vector2u
        getSize   () const;

        void
        close       ();

        void
        turnOnShake ( const int intensity, const float timeSecs );

        void
        updateView  ();

        void
        setViewOrigin   ( const sf::Vector2f& viewLoc );

        void
        setViewOffset   ( const float x, const float y );

    private:
        void
        winEvents   ();


    private:
        sf::RenderWindow        m_window;

        sf::View                m_view;
        sf::Clock               m_shakeCamClock;
        float                   m_shakeTime         = 0;
        int                     m_shakeIntensity    = 0;
        const sf::Vector2f*     m_viewOrigin;
        sf::Vector2f            m_viewOffset;
};

#endif // WINDOW_H
