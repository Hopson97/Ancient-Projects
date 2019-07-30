#ifndef STATE_H
#define STATE_H

#include <SFML/Graphics.hpp>
#include "iostream"

class Program;
class State
{
    public:
                                State(Program* p);
        virtual     void        input  () = 0;
        virtual     void        update () = 0;
        virtual     void        draw   () = 0;

    protected:
        Program*                mProgram;

};

#endif // STATE_H
