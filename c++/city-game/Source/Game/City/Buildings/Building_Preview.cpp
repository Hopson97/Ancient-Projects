#include "Building_Preview.h"

#include "../../Game.h"

#include "Building_Data.h"

#include <iostream>

// Set up the GUIs
Building_Preview::Building_Preview( const Building_Data* data )
:   m_mainFrame     ( {200.f,100}, {Window::WIDTH-210, Window::HEIGHT-245} )
,   m_nameLabel     ( {180.f,0}, {Window::WIDTH-200, Window::HEIGHT-238} )
,   m_buildingData  ( data )
{
    m_mainFrame  .setBgColour    ( { 180, 180, 180, 100 } );
    m_mainFrame  .changeOutlineColour( {140, 140, 140, 80} );

    m_nameLabel  .setTitle("Building Name");
    m_nameLabel  .setBgColour ( {180, 0, 0, 120 } );
    m_nameLabel  .changeOutlineColour ( {180, 0, 0, 120 } );
    m_nameLabel  .changeOutlineThickness(3);

    m_mainFrame.beginColumn( { 3, 10 }, 2 );

    sf::Vector2f size ( 16, 16 );
    m_mainFrame.addSymbolUpdateLabel ( size,
                                       Game::getTexture( Texture_Name::Resource_Coins ),
                                       m_buildingData->getCost().coins,
                                       "How much this building costs to build." );



    this->state = PR_STATE::HIDE;
}

void Building_Preview::changeState(PR_STATE state)
{
    this->state = state;
}

// Basic Functions to update everything
void Building_Preview::update()
{
   // if ( m_buildingData  ) std::cout << m_buildingData->getCost().coins << std::endl;
    // Update mainFrame
    m_mainFrame.update();
    m_nameLabel.update();
}

void Building_Preview::draw()
{
    // Only draws during Building Mode
    m_mainFrame.draw();
    m_nameLabel.draw();
}

void Building_Preview::setBuildingName(const std::string& str)
{

}
