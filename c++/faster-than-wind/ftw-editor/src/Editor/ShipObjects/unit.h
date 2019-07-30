#ifndef UNIT_H
#define UNIT_H

#include "../object.h"
#include "../../texturemanager.h"

enum UnitType
{
    UT_RECRUIT
};

class Unit : public Object
{
    public:
                        Unit        (const sf::Texture& texture, const UnitType _type, const int xPos, const int yPos);
        void            setUp       (const int xPos, const int yPos);

        sf::Vector2f    getPos      () const;
        UnitType        getType     () const;

    private:
        UnitType mType;
        int mXPos, mYPos;
};

#endif // UNIT_H
