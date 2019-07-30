#include "pathfinder.h"

#include "constants.h"

//the A* algorithm was a bit much for me to take in, so I decided to do my own take on a "path finder"

//Constructor is not possible due to the nature of the project, so the vectors have to be set up later (aka when they actually have stuff in them)
void PathFinder::setUp( const std::vector<Room>& rooms, const std::vector<Unit>& units )
{
    this->walls = &walls;
    this->rooms = &rooms;
    this->units = &units;
}

void PathFinder::createPath(const sf::Vector2f& oldPos, const sf::Vector2f& newPos)
{
    currRoom = nullptr;
    this->oldPos = oldPos;
    this->newPos = newPos;

    setCurrPos( oldPos );

    positions.clear();

    std::vector<sf::Vector2f> posChecked;

    while ( true )
    {

    }


}

void PathFinder::checkCurrentTile()
{
    
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

void PathFinder::setCurrPos( const sf::Vector2f& pos)
{
    curr.setPosition( pos.x + ship::TILE_SIZE / 2, pos.y + ship::TILE_SIZE / 2 );
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
