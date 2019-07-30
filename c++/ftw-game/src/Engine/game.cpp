#include "game.h"

#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

#include "../States/splashscreen.h"
#include "../States/mainmenu.h"

Game::Game()
{
    mWindow.setPosition(sf::Vector2i(-1700, 0) );
    mWindow.setFramerateLimit(win::FRAME_RATE_LIMIT);

    quickload();
    //usualload();
}

void Game::quickload()
{
    mTextures.loadTexturesAll();
    mStates.changeState(std::make_shared<state::MainMenu>( this ) );
}

void Game::usualload()
{
    mTextures.loadTexturesSS();

    sf::Thread loader_menu      ( &TextureManager::loadTexturesMenu,         &mTextures );
    sf::Thread loader_rooms     ( &TextureManager::loadTexturesRooms,        &mTextures );
    sf::Thread loader_new_game  ( &TextureManager::loadTexturesNewGame,      &mTextures );
    sf::Thread loader_gbl       ( &TextureManager::loadTexturesGbl,          &mTextures );
    sf::Thread loader_units     ( &TextureManager::loadTexturesUnits,        &mTextures );

    loader_menu     .launch();
    loader_rooms    .launch();
    loader_new_game .launch();
    loader_gbl      .launch();
    loader_units    .launch();


    mStates.changeState(std::make_shared<state::SplashScreen>( this ) );
}

/*****************************************************************************************************************************************************************
*    runGame() defines the main loop of the game
***************************************************************************************************************************************************************/
void Game::runGame()
{
    sf::Clock c;                                    //Clock will be used to work out "delta time" aka time between frames
    changeSong("Resources/Music/undertale.ogg");
    mMusic.setVolume(100);

    while(mWindow.isOpen())
    {
        mWindow.clear(mClearColour);
        float dt = deltaTime( c );

        mStates.getState()->input  ( dt );      //Do the input logic   of the current state
        mStates.getState()->update ( dt );      //Do the input update  of the current state
        mStates.getState()->draw   ( dt );      //Do the input drawing of the current state

        mWindow.display();                  //Display whatever has been drawn to the window
        windowEvents();
    }
    mMusic.stop();
}

/*****************************************************************************************************************************************************************
*   getStates() returns the states of the game, primarily for the purpose of the game states
*   param1  : boolean asking the caller of said function if it wishes to clear the resources
***************************************************************************************************************************************************************/
StateHandler& Game::getStates(const bool clearResources)
{
    if(clearResources) {
        //mResourceManager.clearAll();
    }

    return mStates;
}

/*****************************************************************************************************************************************************************
*   window() returns the window so that it is able to be used for the purpose of drawing sprites and other things to the game window
***************************************************************************************************************************************************************/
sf::RenderWindow& Game::window()
{
    return mWindow;                         //Returns the game window        (as a reference)
}

/*****************************************************************************************************************************************************************
*   deltaTime() calculates and returns "delta time" aka time since the previous game frame
***************************************************************************************************************************************************************/
float Game::deltaTime(sf::Clock& clock)
{
    sf::Time t = clock.restart();
    return t.asSeconds();
}

/*****************************************************************************************************************************************************************
*   changeSong()

PLEASE CHANGE # PLEASE CHANGE # PLEASE CHANGE # PLEASE CHANGE # PLEASE CHANGE # PLEASE CHANGE # PLEASE CHANGE # PLEASE CHANGE # PLEASE CHANGE # PLEASE CHANGE #
*/
void Game::changeSong(const std::string& filePath)
{
    if(mMusic.Playing)
        mMusic.stop();

     mMusic.openFromFile(filePath);

     mMusic.play();
}
/**
PLEASE CHANGE # PLEASE CHANGE # PLEASE CHANGE # PLEASE CHANGE # PLEASE CHANGE # PLEASE CHANGE # PLEASE CHANGE # PLEASE CHANGE # PLEASE CHANGE # PLEASE CHANGE #
***************************************************************************************************************************************************************==
*/

TextureManager& Game::getTexture_m()
{
    return mTextures;
}


/*****************************************************************************************************************************************************************
*   getTexture() returns a texture from the texture manager
***************************************************************************************************************************************************************/
const sf::Texture& Game::getTexture( const TextureName name )
{
    return mTextures.getTexture( name );                //Returns the resource manager  (as a reference)
}


/*****************************************************************************************************************************************************************
*   getSound() returns a sound from the sound manager
***************************************************************************************************************************************************************/
sf::Sound& Game::getSound(const SoundName name)
{
    return mSounds.getSound( name );                //Returns the resource manager  (as a reference)
}

SoundManager& Game::getSounds()
{
    return mSounds;
}

/*****************************************************************************************************************************************************************
*   getFont() returns a font from the font manager
***************************************************************************************************************************************************************/
const sf::Font& Game::getFont(const FontName name)
{
    return mFonts.getFont(name);
}

/*****************************************************************************************************************************************************************
*   windowEvents() checks for events such as window closure, and handles them
***************************************************************************************************************************************************************/
void Game::windowEvents()
{
    sf::Event e;                            //Create a variable to handle window events
    while (mWindow.pollEvent(e)) {          //While the window polls events...
        if (e.type == sf::Event::Closed) {  // if the event type is closed (aka, red cross button)
            mWindow.close();                // the close the window.
        }
    }
}


