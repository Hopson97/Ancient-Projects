#include "pathfinder.h"

#include "constants.h"

//the A* algorithm was a bit much for me to take in, so I decided to do my own take on a "path finder"

//Constructor is not possible due to the nature of the project, so the vectors have to be set up later (aka when they actually have stuff in them)
void PathFinder::setUp( const std::vector<Room>& rooms, const std::vector<Unit>& units )
{
    this->rooms = &rooms;
    this->units = &units;


}

void PathFinder::createPath(const sf::Vector2f& _oldPos, const sf::Vector2f& _newPos)
{
    currRoom = nullptr;
    oldPos = _oldPos;
    newPos = _newPos;

    convToBase40(oldPos);
    convToBase40(newPos);

    setCurrPos( oldPos );

    while ( !positions.empty() ) {
        positions.pop();
    }

    std::vector<sf::Vector2f> posChecked;
    detectCurrentRoom();
    while ( true )
    {
        checkCurrentTile();
    }


}

void PathFinder::checkCurrentTile()
{
    /*
    if ( goalFound() ) return;
    for ( auto& wall : currRoom->getWalls() ) {
        if( wall.getSprite().getLocalBounds().intersects( curr ) {
           rotCurr();
        }
    }
    */
}

bool PathFinder::goalFound()
{
    return false;
}

void PathFinder::detectCurrentRoom()
{
    curr.setRotation(0);
    sf::Vector2f temp ( curr.getPosition().x, curr.getPosition().y);
    convToBase40( temp );
    curr.setPosition ( temp );

    curr.move( -40, 0);
    for( unsigned int i = 0; i < rooms->size() ; i++ )
    {
        if(curr.getLocalBounds().intersects( rooms->at(i).getSprite().getLocalBounds() ) ) {
           currRoom = &rooms->at(i);
           curr.move( 40, 0);
           return;
        }
    }
}

void PathFinder::rotCurr( )
{
    if ( curr.getRotation() == 270 ) curr.setRotation( 0 );
    else {
        curr.rotate(90);
    }
    setCheckPos();
}

void PathFinder::setCurrPos( const sf::Vector2f& pos)
{
    curr.setPosition( pos.x + ship::TILE_SIZE / 2, pos.y + ship::TILE_SIZE / 2 );

    setCheckPos();
}

void PathFinder::setCheckPos()
{
    int r = curr.getRotation();

    if ( r == 0 ) {
        atPos = sf::Vector2f ( curr.getPosition().x + 40, curr.getPosition().y );
    }
    else if ( r == 90 ) {
        atPos = sf::Vector2f ( curr.getPosition().x - 1, curr.getPosition().y + 39 );
    }
    else if ( r == 180 ) {
        atPos = sf::Vector2f ( curr.getPosition().x - 40, curr.getPosition().y - 1);
    }
    else if ( r == 270 ) {
        atPos = sf::Vector2f ( curr.getPosition().x, curr.getPosition().y - 40 );
    }
}


void PathFinder::convToBase40 ( sf::Vector2f& pos )
{
    if (( (int)pos.x % 40 != 0)){                 //If pos.x divided by 40 does not have a remainder of 0:
        while ( (int)pos.x % 40 != 0){            //While pos.x divided by 40 does not have a remainder of 0:
            pos.x--;                        //Change the X position by 1 (until the above is true).
        }
    }

    if (( (int)pos.y % 40 != 0)){                 //If pos.x divided by 40 does not have a remainder of 0:
        while ( (int)pos.y % 40 != 0){            //While pos.x divided by 40 does not have a remainder of 0:
            pos.y--;                        //Change the X position by 1 (until the above is true).
        }
    }
}
