#include "gravity_particles.h"

#include <iostream>

Gravity_Particles :: Gravity_Particles( const sf::Color& colour, const Level& level )
:   m_colour        ( colour )
,   m_level         ( level )
{ }

void
Gravity_Particles :: addParticles ( const int count, const sf::Vector2f& location, const sf::Vector2f& direction )
{
    checkForResize();

    for ( int i = 0 ; i < count ; i ++ )
    {
        m_vertices.emplace_back     ( location, m_colour );
        m_particles.emplace_back    ( m_level, direction );
    }
}

void
Gravity_Particles :: update ( const float dt )
{
    for ( std::size_t i = 0 ; i < m_particles.size() ; i++ )
    {
        //Get the vertex and particle at i index for shorthand
        Particle& p     = m_particles[i];
        sf::Vertex& v    = m_vertices[i];

        v.position += p.getVelocity() * dt;

        checkOutOfBounds ( v );

        if ( p.onGround( v, dt ) )
        {
            //m_particles.erase( m_particles.begin() + i );
        }
    }
}

void
Gravity_Particles :: draw  ( sf::RenderTarget& window, sf::RenderStates states ) const
{
    states.transform *= getTransform();

    // our particles don't use a texture
    states.texture = NULL;

    // draw the vertex array
    window.draw(m_vertices.data(), m_vertices.size(), sf::PrimitiveType::Points );
}


//Checks for the size of the particle arrays
//it then erases the first "maxSize - reduceTo" amount
void
Gravity_Particles :: checkForResize ()
{

    static constexpr std::size_t maxSize = 45000;
    static constexpr std::size_t reduceTo = 44000;

    if ( m_vertices.size() > maxSize )
    {
        m_vertices.erase( m_vertices.begin(), m_vertices.begin() + (m_vertices.size() - reduceTo) );
        m_particles.erase( m_particles.begin(), m_particles.begin() + (m_particles.size() - reduceTo) );
    }
}

///Out of bounds chekcs

void
Gravity_Particles :: checkOutOfBounds ( sf::Vertex& vertex )
{
    checkOOBDown    (vertex);
    checkOOBUp      (vertex);
    checkOOBLeft    (vertex);
    checkOOBRight   (vertex);
}

//Check if the entity is at the top of the map
void
Gravity_Particles :: checkOOBUp ( sf::Vertex& vertex )
{
    if ( vertexTilePosition(vertex).y <= 0 )
    {
        vertex.position = { vertex.position.x, 1 };
    }
}

//Check if the entity is at the bottom of the map
void
Gravity_Particles :: checkOOBDown ( sf::Vertex& vertex )
{
    if ( vertexTilePosition(vertex).y >= m_level.getHeight() )
    {
        vertex.position = { vertex.position.x, (float)Tile::TILE_SIZE * m_level.getHeight() - 1 };
    }
}

//Check if the entity is at the left of the map
void
Gravity_Particles :: checkOOBLeft ( sf::Vertex& vertex )
{
    if (vertexTilePosition(vertex).x <= 0 )
    {
        vertex.position = { 1, vertex.position.y };
    }
}

//Check if the entity is at the right of the map
void
Gravity_Particles :: checkOOBRight ( sf::Vertex& vertex )
{
    if ( vertexTilePosition(vertex).x >= m_level.getWidth() )
    {
        vertex.position = { (float)Tile::TILE_SIZE * m_level.getWidth() - 1, vertex.position.y };
    }
}

const sf::Vector2i
Gravity_Particles :: vertexTilePosition ( sf::Vertex& vertex )
{
    int x = vertex.position.x / Tile::TILE_SIZE;
    int y = vertex.position.y / Tile::TILE_SIZE;

    return { x, y };
}

