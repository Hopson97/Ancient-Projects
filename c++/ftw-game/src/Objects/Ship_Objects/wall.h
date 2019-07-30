#ifndef WALL_H
#define WALL_H

#include "../../Engine/Entity/entity.h"
#include "../../Engine/animation.h"

#include <memory>

enum WallType
{
        WT_DOOR
    ,   WT_WALL
};

class Wall : public Entity
{
    public:
                            Wall            (TextureManager& manager, const sf::Vector2f position, const int rotation,
                                             const WallType type, const int id, const int otherId, const sf::Vector2f& shipPosition );

                void        logic           (const float dt);
                void        setOtherDoor    (Wall& _wall);
                void        setToShipPos     (const sf::Vector2f& shipPosition);
        const   WallType    getType         () const;
        const   int         getId           () const;
        const   int         getOtherId      () const;

    private:
                void        setTexture      (TextureManager& manager);
                void        setUpAnimation  ();

    private:
        WallType        mWallType;

        //For matching doors up with each other
        Wall*           otherDoor;
        int             mId;
        int             mOtherDoorId;

        int             WALL_WIDTH;
        int             WALL_HEIGHT;

        int             xPos,
                        yPos;

        Animation       doorOpen;
};

#endif // WALL_H
