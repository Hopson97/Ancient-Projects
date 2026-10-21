#ifndef PLAYER_H
#define PLAYER_H

#include "../Engine/drawable.h"

class Player : public Drawable
{
    public:
        Player();                   //Constructor of player
        void logic(sf::RenderWindow &w);    //Logic

    private:
        void input(sf::RenderWindow &w);    //Handle input stuff

        void lookAtMouse(sf::RenderWindow &w);  //Get player to look at mouse
        sf::Vector2f moveVec(sf::RenderWindow &w);  //Return a normalised movement vector
        float mouseAngle(sf::RenderWindow &w);      //Get angle between mouse and player

        void getPlayerDistanceToCursor(float &dx, //Get distance between mouse and player
                                       float &dy,
                                       sf::RenderWindow &w);

        Animation walking;      //Walking animation
        void setUpAnimation();  //Set up the animation

        sf::View camera;
        void setCamera(sf::RenderWindow &w); //Sets up the camera view

        sf::Texture texture; // Texture of a drawable thing
        sf::Sprite sprite;   // Sprite of a drawable thing
};

#endif // PLAYER_H
