#include "player.h"

Player::Player()
    : sprite(texture)
{
    std::string path = "user.png";
    if(!texture.loadFromFile(path))                  //Load Texture
        std::cout << "Could not load player" << std::endl;   //Load Texture
    texture.setSmooth(true);                                //Make it smooth

    sprite.setPosition({(float)gbl::screenWidth / 2,    // Set sprite position to centre of the window
         (float)gbl::screenHeight / 2}); // Set sprite position to centre of the window

    camera.setSize({(float)gbl::screenWidth, (float)gbl::screenHeight});

    setUpAnimation();

    sprite.setOrigin({16, 16}); // Centre the rotation origin of the sprite

    speed = 2;                      //Set sprite speed to 5
}

/*
============================================================================
Player::logic is what is says on tin
============================================================================
*/
void Player::logic(sf::RenderWindow &w)
{
    setCamera(w);

    input(w);       //Get input
    w.draw(sprite); //Draw the sprite
}

/*
============================================================================
Player::input gets player input
============================================================================
*/
void Player::input(sf::RenderWindow &w)
{
    lookAtMouse(w);         //Rotate sprite to look at the mouse
    bool keyDown = false;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) //If W is pressed
    {
        sprite.move(-(moveVec(w)));                 //Move forward
        walking.animate(sprite);                    //Animate
        keyDown = true;                             //A key is down
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) //If S is pressed
    {
        sprite.move(moveVec(w));                    //Move backward
        walking.animate(sprite);                    //Animate
        keyDown = true;                             //A key is down
    }
    if(!keyDown)                        //ie, the player is idle
    {
        sf::IntRect w1({{0, 0}, {32, 32}}); // Set sf::IntRect to the "idle" pose
        sprite.setTextureRect(w1);      //He is standing still
    }

}


/*
============================================================================
Player::lookAtMouse makes player look at mouse
============================================================================
*/

void Player::lookAtMouse(sf::RenderWindow &w)
{
    sprite.setRotation(sf::degrees(mouseAngle(w)));      //Sets rotation to mouse
}

/*
============================================================================
Player::moveVec calculations for finding the length of a vector
============================================================================
*/
sf::Vector2f Player::moveVec(sf::RenderWindow &w)
{
    float dx;
    float dy;
    getPlayerDistanceToCursor(dx, dy, w);        //Gets mouse distance from player

    sf::Vector2f dir(dx, dy);       //Creates vector

    dir = normaliseVector(dir);    //Normalise the vector
    addSpeedToVector(dir);          //Add the player speed to the vector
    return dir;             //Return said vector
}

/*
============================================================================
Player::mouseAngle returns the angle of mouse relative to the player
============================================================================
*/
float Player::mouseAngle(sf::RenderWindow &w)
{
    float dx;
    float dy;
    getPlayerDistanceToCursor(dx, dy, w);   //Gets player distance from cursor

    float rot = (atan2(dy,dx)) * 180 / gbl::pi + 180;   //Gets an angle for rotation

    return rot;     //Returns the angle of mouse relitive to the player
}

/*
============================================================================
Player::getPlayerDistanceToCursor(); Gets the x and y distance from player -> cursor
============================================================================
*/
void Player::getPlayerDistanceToCursor(float &dx, float &dy,  sf::RenderWindow &w)
{
    sf::Vector2f pos = sprite.getPosition();    //Get players position
    sf::Vector2f mousePos = w.mapPixelToCoords(sf::Mouse::getPosition(w));  //Get mouse

    dx = pos.x - mousePos.x;    //Returns distance between mouseX and playerX
    dy = pos.y - mousePos.y;    //Returns distance between mouseX and playerX
}
/*
============================================================================
Player::setCamera basically allows the view to move around the player
============================================================================
*/
void Player::setCamera(sf::RenderWindow &w)
{
    camera.setCenter({sprite.getPosition().x, sprite.getPosition().y});
    w.setView(camera);
}
/*
============================================================================
Player::setUpAnimation(); Sets up the animation
============================================================================
*/
void Player::setUpAnimation()
{
    walking.setFrameGap(5);
    sf::IntRect w2({32, 0}, {32, 32});
    sf::IntRect w3({64, 0}, {32, 32});

    walking.addFrame(w2);
    walking.addFrame(w3);
    walking.addFrame(w2);
}
















