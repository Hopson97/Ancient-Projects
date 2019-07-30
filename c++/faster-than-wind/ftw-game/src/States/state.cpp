#include "state.h"

State::State(Game* game)
{
    mGame = game;            //Set the class member's Game pointer to the pointer passed in.
}

Game& State::_mGame()
{
    return *mGame;
}

void State::input    (const float dt){}
void State::update   (const float dt){}
void State::draw     (const float dt){}
