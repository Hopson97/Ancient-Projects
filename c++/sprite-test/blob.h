#ifndef BLOB_H
#define BLOB_H
#include <SFML/Graphics.hpp>
#include "entity.h"

class blob : public Entity
{
    public:
        blob();
        virtual ~blob();


    protected:
    private:
        void logic() override;
        void input();
        void update() override;
        void collision();

        void physicsLogic();

        bool isUpButtonDown() const;
        void setUpButtonState(bool isDown);

        bool isLeftButtonDown() const;
        void setLeftButtonState(bool isDown);

        bool isRightButtonDown() const;
        void setRightButtonState(bool isDown);

        bool leftArrowDown;
        bool rightArrowDown;
        bool upArrowDown;

        bool canJump;


};

#endif // BLOB_H
