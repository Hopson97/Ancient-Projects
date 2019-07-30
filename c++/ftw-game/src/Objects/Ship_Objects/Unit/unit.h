#ifndef UNIT_H
#define UNIT_H

#include <string>

#include "../../../Engine/UI/button.h"
#include "../../../Utilities/rangednum.h"
#include "../../../Engine/animation.h"
#include "level.h"

enum UnitType
{
    UT_RECRUIT
};

class Unit : public ui::Button
{
    public:
                                Unit                (const sf::Texture&  texture,   const UnitType      _type,
                                                    const sf::Vector2f& pos,       const sf::Vector2f& shipPos);

                void            update              (const float dt);
                void            setToShipPos        (const sf::Vector2f& shipPos);

        const   UnitType        getType             () const;

                void            setSelectedState    (const bool isSelected);
        const   bool            getSelectedState    () const;

                void            draw                ( sf::RenderWindow& window) override;

    private: //Private methods
                void            setUpAnimation      ();
                void            drawHealthBar       ( sf::RenderWindow& window);

        const   std::string     typeToString        () const;
                void            setLevels           ();

     private://variables
        UnitType                    mUnitType;

        int                         mXPos,
                                    mYPos;

        bool                        isSelected      { false };

        Animation                   walkingAnim;

        util::RangedNum<int >       mHealth         {0, 10, 3};

        Level                       repairLvl       { 1 };
        Level                       speedLvl        { 1 };

        sf::RectangleShape          healthRect      { { 40.0f, 2.0f } };
        sf::RectangleShape          noHealthRect    { {  0.0f, 2.0f } };
};

#endif // UNIT_H
