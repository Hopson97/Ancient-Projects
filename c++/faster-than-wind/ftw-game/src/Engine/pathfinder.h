#ifndef PATHFINDER_H
#define PATHFINDER_H

#include <stack>

#include "../Objects/Ship_Objects/ship_objects_inc.h"

class PathFinder
{
    public:
        void    setUp               ( const std::vector<Room>& rooms, const std::vector<Unit>& units );
        void    createPath          ( const sf::Vector2f& _oldPos, const sf::Vector2f& _newPos );

    private:

        void    convToBase40        ( sf::Vector2f& pos );

        void    checkCurrentTile    ( );
        bool    goalFound           ( );

        void    detectCurrentRoom   ( );

        void    setCheckPos         ();
        void    setCurrPos          ( const sf::Vector2f& pos );
        void    rotCurr             ( );


    private:
        const std::vector<Room>* rooms;
        const std::vector<Unit>* units;

        std::vector<sf::Vector2f> nodemap;

        const Room* currRoom;

        std::stack<sf::Vector2f> positions;

        sf::Vector2f oldPos;
        sf::Vector2f newPos;

        sf::RectangleShape curr { { 40.0f, 1.0f } };
        sf::Vector2f atPos;

        /*
        const
        const
        const
        */
};

#endif // PATHFINDER_H
