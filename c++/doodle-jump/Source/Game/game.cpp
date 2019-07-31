#include "game.h"

#include "Util/window.h"

#include "States/splash_screen.h"

#include <SFML/System.hpp>

#include "States/playing.h"

Game::Game()
{
	Window::init();
	//m_stateHandler.pushState( std::make_unique<State::Splash_Screen>( *this ) );
	m_stateHandler.pushState( std::make_unique<State::Playing>( *this ) );
}

void Game::run()
{
	sf::Clock clock;
	while ( Window::isOpen() )
	{
		Window::checkForClose();
		if( !Window::isOpen() )
			break;

		float dt = clock.restart().asSeconds();

		Window::clear( { 0, 200, 255 } );

		m_stateHandler.peekState()->input	(dt);
		m_stateHandler.peekState()->update	(dt);
		m_stateHandler.peekState()->draw	(dt);

		Window::update();
	}
}

//General functions that allow quick access to the texture managers and such, as well as states
void Game :: loadFont ( const std::string& fileName, Font_Name name )
{
    m_fontManager.load( fileName, name );
}


void Game :: loadSound ( const std::string& fileName, Sound_Name name )
{
    m_soundManager.load( fileName, name );
}


void Game :: loadTexture ( const std::string& fileName, Texture_Name name )
{
    m_textureManager.load ( fileName, name );
}


const sf::Font& Game::getFont( Font_Name name ) const
{
    return m_fontManager.get ( name );
}


const sf::Texture& Game :: getTexture ( Texture_Name name ) const
{
    return m_textureManager.get( name );
}


const sf::SoundBuffer& Game :: getSound (Sound_Name name) const
{
    return m_soundManager.get( name );
}


void Game :: changeSong ( const std::string& name )
{
    m_musicManager.playSong( name );
}


void Game :: popState()
{
    m_stateHandler.popState();
}

void Game :: pushState ( StatePtr state )
{
    m_stateHandler.pushState( std::move(state) );
}

void Game :: changeState ( StatePtr state )
{
    m_stateHandler.popState();
    m_stateHandler.pushState( std::move(state) );
}










Game::~Game()
{
	Window::destroy();
}

