#ifndef STATEHANDLER_H
#define STATEHANDLER_H

#include <memory>
#include <stack>

#include "state.h"

typedef std::shared_ptr<State> statePtr;

class StateHandler
{

    public:
        void                pushState  (const statePtr& state);
        void                changeState(const statePtr& state);
        void                popState   ();
        statePtr            getState   ();

    private:
        std::stack<statePtr> mStates;
};

#endif // STATEHANDLER_H
