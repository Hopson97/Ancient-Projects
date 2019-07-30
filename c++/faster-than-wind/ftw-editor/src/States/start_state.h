#ifndef STARTSTATE_H
#define STARTSTATE_H

#include "edit_state.h"
#include "state.h"

class StartState : public State
{
    public:
        StartState                  (Program* p);
        void        input           () override;
        void        update          () override;
        void        draw            () override;
    private:
        void        newShip         ();
        bool        checkDimensions (const sf::Sprite& dimChker);
        void        loadShip        ();
        void        printControls   ();

        std::string filePath;

};

#endif // STARTSTATE_H
