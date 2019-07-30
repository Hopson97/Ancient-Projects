#ifndef ROOM_H
#define ROOM_H

#include "../../Engine/Entity/entity.h"
#include "wall.h"

#include <vector>

enum RoomType
{
      RT_EMPTY_SMALL
    , RT_EMPTY_LARGE
    , RT_EMPTY_SMALL_WIDE
    , RT_EMPTY_SMALL_TALL
    , RT_EMPTY_HUGE
    , RT_CANNON
};

class Room : public Entity
{
    public:
                Room    (   const    sf::Vector2f&  position,   const  RoomType    roomType,
                            const    sf::Texture&   texture,    const  int         rotation,
                            const    sf::Vector2f&  shipPosition);

        void                addWall     (const Wall& wall);
        void                logic       (const float dt);
        void                draw        (sf::RenderWindow& window) override;

        void                setToShipPos (const sf::Vector2f& shipPosition);

        std::vector<Wall>&  getWalls    ();

    private:
        sf::Vector2f        mPosition;
        RoomType            mRoomType;
        int                 mRotation;

        std::vector<Wall>   mWalls;
};

#endif // ROOM_H
