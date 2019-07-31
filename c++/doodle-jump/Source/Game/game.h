#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED


#include <SFML/Graphics.hpp>

#include "States/state_handler.h"

#include "Managers/music_manager.h"
#include "Managers/resource_identifier.h"

class Game
{
	public:
		Game		();

		void run	();

		void loadFont       ( const std::string& fileName, Font_Name name   );
		void loadSound      ( const std::string& fileName, Sound_Name name  );
		void loadTexture    ( const std::string& fileName, Texture_Name name);

		const sf::Font&    getFont      ( Font_Name name    ) const;
		const sf::Texture& getTexture   ( Texture_Name name ) const;
		const sf::SoundBuffer& getSound ( Sound_Name name   ) const;

		void popState   ();
		void pushState  ( StatePtr state );
		void changeState( StatePtr state );

		void changeSong( const std::string& name );

		~Game		();

	private:
		State_Handler m_stateHandler;

		Font_Manager    m_fontManager;
		Music_Manager   m_musicManager;
		Sound_Manager   m_soundManager;
		Texture_Manager m_textureManager;
};

#endif // GAME_H_INCLUDED
