#include "window.h"

#include <memory>

namespace Window
{
	//This is all not in a class because it is very annoying having to pass a render window around to do stuff.
	//It is a pointer to a window because I can initilise it when I want to.
	std::unique_ptr<sf::RenderWindow> window;
	std::unique_ptr<sf::View> view;

	void init()
	{
		window = std::make_unique<sf::RenderWindow>( sf::VideoMode( WIDTH, HEIGHT ), "Pong" );
		window->setFramerateLimit ( 60 );
		view = std::make_unique<sf::View>( sf::FloatRect{ 0, 0, WIDTH, HEIGHT } );

		window->setView ( *view );
	}

	void destroy()
	{
		//delete window;
		window = nullptr;
	}

	void draw( const sf::Drawable& toDraw, bool useView )
	{
	    if ( useView )
	    {
            window->setView ( *view );
            window->draw( toDraw );
	    }
        else
        {
            window->setView ( sf::View() );
            window->draw ( toDraw );
        }
	}

	void clear( const sf::Color& color )
	{
		window->clear( color );
	}

	void update()
	{
		window->display();
	}

	bool isOpen()
	{
		return window->isOpen();
	}

	void checkForClose()
	{
		sf::Event e;
		while ( window->pollEvent( e ) )
		{
			switch( e.type )
			{
				case sf::Event::Closed:
					close();
					break;
                default:
                    break;
			}
		}
	}

	void setView ( float playerY )
	{
	    view->setCenter ( { Window::WIDTH / 2, playerY } );
	}

    float getViewBottom ()
	{
	    return view->getCenter().y + Window::HEIGHT / 2;
	}

	const sf::RenderWindow& get()
	{
	    return *window;
	}

	void close()
	{
		window->close();
	}
}
