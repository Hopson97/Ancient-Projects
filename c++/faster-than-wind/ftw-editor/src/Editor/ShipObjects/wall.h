#ifndef WALL_H
#define WALL_H

#include <SFML/Graphics.hpp>
#include <memory>

namespace wallConst
{
    const sf::Color WALL(255, 178, 102);
    const sf::Color DOOR(188,  76,  47);

    const sf::Vector2f SIZE(1, 40);
}

enum Direction
{
    dirHorizontal,
    dirVertical
};

enum WallOrDoor
{
    WT_DOOR = 0,
    WT_WALL = 1
};

class Wall
{
    public:
                                Wall            (const Direction d, const int xPos, const int yPos);

                                Wall            (const Direction d,   const int xPos,  const int yPos,
                                                 const WallOrDoor wod, const int myId, const int otherId);
        void                    draw            (sf::RenderWindow& window);

        WallOrDoor              getType         () const;
        void                    setType         (WallOrDoor type);

        sf::RectangleShape      getRect         () const;

        void                    setOtherWall    ( std::shared_ptr<Wall> other);

        Wall&                   getOtherWall   ();

        sf::Vector2f            getPos          () const;

        int                     getRot          () const ;

        void                    genId           (); //ID for this wall
        int                     getId           () const; //Return the ID of this wall
        int                     getOtherId      () const; //Return the ID of the other wall

        void                    setOtherId      (const  int _otherId);

        static int      idCount;

    private:
        void checkType();

    private:
        sf::RectangleShape      mWallRectangle;

        int                     mXPos;
        int                     mYPos;
        int                     mId;
        int                     otherId;

        WallOrDoor              mType;


        std::shared_ptr<Wall>   otherWall;
};

#endif // WALL_H
