#ifndef STATE_H
#define STATE_H

class Game;
class State
{
    public:
        explicit        State   (Game* game);

        virtual void    input   (const float dt) = 0;
        virtual void    update  (const float dt) = 0;
        virtual void    draw    (const float dt) = 0;

    protected:
                Game&   _mGame ();


    private:
        Game*   mGame;

};

#endif // STATE_H
