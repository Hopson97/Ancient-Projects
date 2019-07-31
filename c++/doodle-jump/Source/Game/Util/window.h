#ifndef WINDOW_H_INCLUDED
#define WINDOW_H_INCLUDED

#include <SFML/Graphics.hpp>

namespace Window
{
	constexpr static int HEIGHT = 700;
	constexpr static int WIDTH = 650;

	void init	();

	void draw	( const sf::Drawable& toDraw, bool useView = true );

	void clear	( const sf::Color& color = { 0, 0, 0 } );
	void update ();

	bool isOpen	();

	void checkForClose();
	void close	();

	void setView        ( float playerY );
	float getViewBottom ();

	const sf::RenderWindow& get();

	void destroy();
}

#endif
