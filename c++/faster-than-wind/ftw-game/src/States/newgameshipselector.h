#ifndef NEWGAMESHIPSELECTOR_H
#define NEWGAMESHIPSELECTOR_H

#include <string>

#include "../Objects/Ship_Objects/Ship/ship.h"

#include "../Engine/UI/button.h"
#include "../Engine/UI/unitshower.h"

#include "state.h"
#include "../Engine/game.h"
#include "../Engine/shiploader.h"
#include "../Utilities/rangednum.h"

#include "../Objects/water.h"

namespace state
{

class NewGameShipSelector : public State
{
    public:
                NewGameShipSelector (Game* game, TextureManager& manager);

        void    input               (const float dt) override;
        void    update              (const float dt) override;
        void    draw                (const float dt) override;

    private:
        void    setUpLabels         ();
        void    setUpButtons        ();
        void    addEntitysToVector  ();
        void    addShipsToVector    ();
        void    changeCurrentShip   (const int increment);
        void    resetShip           ();

    private:
        const float                 LIST_BUTTON_Y           { 90 };
        int                         mCurrentShipNumber      { 1  };

        Ship                        mCurrentShip;
        ShipLoader                  mShipLoader;

        Entity                      shipYardLogo            { _mGame().getTexture( RES_TXR_GBL_LONG_SCROLL  ) };
        Entity                      stones                  { _mGame().getTexture( RES_TXR_NEWGAME_STONES   ) };
        Entity                      mCurrShipLabel          { _mGame().getTexture( RES_TXR_GBL_SMALL_SCROLL ) };

        Entity                      mListButtonText         { _mGame().getTexture( RES_TXR_NEWGAME_LIST_ICON  ) };
        ui::Button                  mPrevShipButton         { _mGame().getTexture( RES_TXR_NEWGAME_PREV_ARROW ), { 0.0f,   LIST_BUTTON_Y }, _mGame().getSound ( RES_SOUND_GBL_GENERIC_CLICK ) };
        ui::Button                  mNextShipButton         { _mGame().getTexture( RES_TXR_NEWGAME_NEXT_ARROW ), { 399.0f, LIST_BUTTON_Y }, _mGame().getSound ( RES_SOUND_GBL_GENERIC_CLICK ) };

        ui::Button                  mLayout1Button          { _mGame().getTexture( RES_TXR_GBL_SMALL_SCROLL   ), { win::WIDTH - 570.0f, LIST_BUTTON_Y }, "Layout 1", txtSz::small, _mGame().getFont( RES_FONT_FANCY ), _mGame().getSound ( RES_SOUND_GBL_GENERIC_CLICK ) };
        ui::Button                  mLayout2Button          { _mGame().getTexture( RES_TXR_GBL_SMALL_SCROLL   ), { win::WIDTH - 380.0f, LIST_BUTTON_Y }, "Layout 2", txtSz::small, _mGame().getFont( RES_FONT_FANCY ), _mGame().getSound ( RES_SOUND_GBL_GENERIC_CLICK ) };
        ui::Button                  mLayout3Button          { _mGame().getTexture( RES_TXR_GBL_SMALL_SCROLL   ), { win::WIDTH - 190.0f, LIST_BUTTON_Y }, "Layout 3", txtSz::small, _mGame().getFont( RES_FONT_FANCY ), _mGame().getSound ( RES_SOUND_GBL_GENERIC_CLICK ) };

        ui::Button                  mConfirmSelectionButton { _mGame().getTexture( RES_TXR_GBL_SMALL_SCROLL   ), { win::WIDTH - 190.0f, win::HEIGHT - 100.0f  }, "Select Ship", txtSz::small, _mGame().getFont( RES_FONT_FANCY ), _mGame().getSound ( RES_SOUND_GBL_GENERIC_CLICK ) };

        ui::Button                  mBackToMainMenuButton   { _mGame().getTexture( RES_TXR_GBL_SMALL_SCROLL   ), { 0.0f, 0.0f }, "\t  Back to \n Main Menu", txtSz::small, _mGame().getFont( RES_FONT_FANCY ), _mGame().getSound ( RES_SOUND_GBL_GENERIC_CLICK ) };

        util::RangedNum<int>        mCurrentLayout          { 1,  3, 1 };

        Water                       mWater                  { -1, 8, 0.5, 3 };

        std::vector<ui::UnitShower>     mUnitShowers;
        std::vector<std::string>    mshipNameList;
        std::vector<Entity*>        mEntities;



        std::string                 shipString;
};

}//Namespace state

#endif // NEWGAMESHIPSELECTOR_H
