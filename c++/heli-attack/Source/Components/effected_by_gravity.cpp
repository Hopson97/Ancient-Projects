#include "effected_by_gravity.h"

#include "Funcs/tile_map_component_funcs.h" //tileSolid(), getNextPosition()

#include <iostream>

namespace Component
{

Effected_By_Gravity :: Effected_By_Gravity ( Entity& entity, const Level& level)
:   m_entity            ( entity )
,   m_level             ( level  )
{ }


    Effected_By_Gravity :: Effected_By_Gravity ( Entity& entity, const Level& level, Window& window)
:   m_entity            ( entity )
,   m_level             ( level  )
,   m_window            ( &window )
{ }

Effected_By_Gravity :: Effected_By_Gravity ( Entity& entity, const Level& level, Window& window, Gravity_Particles& particles )
:   m_entity            ( entity )
,   m_level             ( level  )
,   m_window            ( &window )
,   m_groundParticles   ( &particles )
{ }

Effected_By_Gravity :: Effected_By_Gravity ( Entity& entity, const Level& level, Window& window, Gravity_Particles& particles, Gravity_Particles& particles2)
:   m_entity                ( entity )
,   m_level                 ( level  )
,   m_window                ( &window )
,   m_groundParticles      ( &particles )
,   m_landingParticles     ( &particles2 )
{ }

void
Effected_By_Gravity :: update ( const float dt )
{
    checkIfOnGround ( dt );
    applyGravity    ( dt );
}

void
Effected_By_Gravity :: checkIfOnGround ( const float dt )
{
    sf::Vector2f newPos = getNextPosition( m_entity, dt );  //Gets the position of the underneath the entity (world Coordinates)
    newPos.y += m_entity.getSpriteSize().y;
    float newPosRight = newPos.x + m_entity.getSpriteSize().x; //To check the right bound of the entity

    if ( !tileSolid ( m_level, newPos ) && !tileSolid ( m_level, { newPosRight, newPos.y } ) )
    {
        m_entity.setIfOnGround( false );
        //If the entity is not on the ground, it updates it's "am i on the ground" boolean
    }
}

void
Effected_By_Gravity :: applyGravity    ( const float dt )
{
    sf::Vector2f newPos = getNextPosition( m_entity, dt );          //Gets the position of the underneath the entity (world Coordinates)
    newPos.y += m_entity.getSpriteSize().y;
    float newPosRight = newPos.x + m_entity.getSpriteSize().x; //To check the right bound of the entity, an X-Coordinate

    if ( !m_entity.isOnGround() )
    {
        m_entity.changeVelocity( 0,  m_entity.getGravity() * dt );   //If the entity isn't on the ground, its velocity "increases" (dumb opengl coordinate systems amiright)

        //If the entity lands on a solid tile
        if ( tileSolid( m_level, newPos ) || tileSolid ( m_level, { newPosRight, newPos.y } ) )
        {
            handleParticles( newPos, newPosRight );     //Adds particles and that to the world


            m_entity.resetYVelocity();              // Stops the Y velocity if the entity is on the ground/ touching a solid tile on either side of it's bottom
            m_entity.setIfOnGround( true );         // touching a solid tile on either side of it's bottom
        }
    }
}

void
Effected_By_Gravity :: handleParticles ( const sf::Vector2f& newPos, const float newPosRight )
{
    //Calculate the "intensity" of the fall, divide by big number or else it is just ridiculous. if it is too small then there is no point having intensity
    int fallIntensity = -m_entity.getVelocity().y / 250;
    if ( fallIntensity > -3 ) fallIntensity = 0;

    addParticles( m_groundParticles,  8, fallIntensity, newPos, newPosRight );
    addParticles( m_landingParticles, 5, fallIntensity, newPos, newPosRight );

    //Shake the screen
    if ( m_window )
        m_window->turnOnShake( fallIntensity, 0.1 );
}

void
Effected_By_Gravity :: addParticles ( Gravity_Particles* p, const std::size_t amountMultiplyer, const int fallIntensity, const sf::Vector2f& newPos, const float newPosRight )
{
    //Calculates how many particles to add, and checks if it is going to add too many
    int n = abs ( fallIntensity * amountMultiplyer );
    int maxParticlesToAdd = 15;
    n = n > maxParticlesToAdd ? maxParticlesToAdd : n;

    //Add particles to the landing site, if one was added into this component
    if ( p )
    {
        p->addParticles( n,      //Particles added is proportinal to the fall intensity
                        { ( newPos.x + newPosRight ) / 2                //X position, between the 2 bottom edge vertex of entity,
                        ,   newPos.y - m_entity.getSpriteSize().y / 5}, //Y position -size... so particles don't insta stuck in the ground
                        {0, (float)fallIntensity}                      //Direction
                       );
    }
}

} //Namespace Component
