#include "level.h"

Level::Level( const int initialLevel )
{
    while ( mCurrentLevel != initialLevel ) {
        addExp( 1 );
        if ( mCurrentLevel == MAXIMUM_LEVEL ) {
            break;
        }
    }
}

/**************************************************************************************************************************************************************
*   addExp() adds experience points to the level, and then checks if a level up is possible
*   param1  :   the amount of experience points to add to the level
**************************************************************************************************************************************************************/
void Level::addExp(const int exp)
{
    mCurrentExp += exp;
    mTotalExp   += exp;
    checkForLvlUp();
}

/**************************************************************************************************************************************************************
*   checkForLvlUp() checks if there is enough experience points for level up
**************************************************************************************************************************************************************/
void Level::checkForLvlUp()
{
    if ( levelUpPossible() ) {
        levelUp();
    }
}

/**************************************************************************************************************************************************************
*   levelUp() levels up the character, and if there is an "exp overflow", it gets added to the next level's exp.
              it then checks for level up again
**************************************************************************************************************************************************************/
void Level::levelUp()
{
    if ( mCurrentLevel == MAXIMUM_LEVEL ) {
            return;
    }
    mCurrentLevel++;
    mCurrentExp = getExpOverflow();
    mExpAtNextLvl *= 1.3;           //30% experience increase

    if ( levelUpPossible() ) levelUp(); //Wow my first ever recursion :^D
}

/**************************************************************************************************************************************************************
*   getExpOverflow() checks if there is more exp than the maximum exp of the previous level
**************************************************************************************************************************************************************/
const int Level::getExpOverflow()
{
    int leftOverExp = mCurrentExp - mExpAtNextLvl;

    return (leftOverExp > 0) ? leftOverExp : 0;
}

/**************************************************************************************************************************************************************
*   levelUpPossible() returns true if the current exp is more than or equal to the exp needed for the next level
**************************************************************************************************************************************************************/
const bool Level::levelUpPossible()
{
    return ( mCurrentExp >= mExpAtNextLvl ) ? true : false;
}


const int Level::getLevel() const
{
    return mCurrentLevel;
}

const int Level::getCurrentExp() const
{
    return mCurrentExp;
}

const int Level::getExpForNextLvl() const
{
    return mExpAtNextLvl;
}

const int Level::getTotalExp() const
{
    return mTotalExp;
}
