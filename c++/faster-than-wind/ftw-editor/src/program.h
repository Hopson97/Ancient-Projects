#ifndef PROGRAM_H
#define PROGRAM_H

#include <SFML/Graphics.hpp>

#include <iostream>
#include <memory>

#include "States/start_state.h"
#include "States/state.h"

class Program
{
    public:
                                Program         ();
        void                    runProgram      ();
        void                    changeState     (std::shared_ptr<State> mState);

        sf::RenderWindow&       window          ();

    private:
        void                    windowEvents    ();
    private:
        std::shared_ptr<State>  mState;
        sf::RenderWindow        mWindow;

};

#endif // PROGRAM_H
