#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "../Objects/Ship Objects/ship_objects_inc.h"

class PathFinder
{
    public:
        void    setUp               ( const std::vector<Room>& rooms, const std::vector<Unit>& units );
        void    createPath          ( const sf::Vector2f& oldPos, const sf::Vector2f& newPos );

    private:

        void    convToBase40        ( sf::Vector2f& pos );

        void    checkCurrentTile    ( );

        void    detectCurrentRoom   (  );

        void    setCurrPos          ( const sf::Vector2f& pos );


    private:
        const std::vector<Room>* rooms;
        const std::vector<Unit>* units;

        const Room* currRoom;

        std::vector<sf::Vector2f> positions;

        sf::Vector2f oldPos;
        sf::Vector2f newPos;

        sf::RectangleShape curr { { 40.0f, 1.0f } };

        /*
        const
        const
        const
        */
};

#endif // PATHFINDER_H
