#ifndef ROOM_H
#define ROOM_H

#include <memory>

#include "../../texturemanager.h"
#include "../object.h"
#include "wall.h"
#include "unit.h"

//enum to define types of room
enum RoomType
{
      RT_EMPTY_SMALL
    , RT_EMPTY_LARGE
    , RT_EMPTY_SMALL_WIDE
    , RT_EMPTY_SMALL_TALL
    , RT_EMPTY_HUGE
    , RT_CANNON
};

class Room : public Object
{
    public:
        Room            (   const sf::Texture& t,  const RoomType newRt,        const int xPos,
                            const int yPos,        const sf::Vector2f& size,    const int rotation);

        Room            (   const sf::Texture& t,  const RoomType newRt,        const int xPos,
                            const int yPos,        const sf::Vector2f& size,    const int rotation, bool loaded);

        void                    draw        (sf::RenderWindow& window); //draw to window

        RoomType                getType     ()   const;


        sf::Vector2f            pos         ()       const;

        sf::Vector2f            size        ()      const;

        void                    rotate      ();

        void                    addUnit     (std::shared_ptr<Unit> _unit);


        void                    setWalls    (std::vector<std::shared_ptr<Wall>>& walls);
        void                    setUnits    (std::vector<std::shared_ptr<Unit>>& units);

        std::vector<std::shared_ptr<Wall>>&  getWalls    ();
        std::vector<std::shared_ptr<Unit>>&  getUnits    ();

    private:
        bool                    isRotatable () const;
         void                   setUp       (const int rotation);

    private:
        int                     xPos, yPos;


        int                     mWidth, mHeight;

        RoomType                mRoomType;

        std::vector<std::shared_ptr<Wall>>      mWalls;
        std::vector<std::shared_ptr<Unit>>      mUnits;
};

#endif // ROOM_H
