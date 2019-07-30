#include "unit.h"

#include <fstream>
#include <iostream>

void Unit::setLevels()
{
    std::string filePath = "Resources/Unit Info/" + typeToString() + ".txt";
    std::ifstream statGetter(filePath);

    if ( statGetter.is_open() ) {
        std::string levelName;
        while ( statGetter >> levelName ) {
            int lvl;
            statGetter >> lvl;
            Level newLvl ( lvl  );

            if ( levelName == "SPEED" ) {
                speedLvl = newLvl;
            }
            else if ( levelName == "REPAIR" ) {
                repairLvl = newLvl;
            }
            else {
                std::cout << "\"" << levelName << "\" not recognised (Inside \" " << filePath << "\") \n";
            }
        }
    }
    else {
        return;
    }

}

const std::string Unit::typeToString() const
{
    switch ( mUnitType )
    {
    case UT_RECRUIT:
        return "Recruit";
    default:
        return "error";
    }
}
