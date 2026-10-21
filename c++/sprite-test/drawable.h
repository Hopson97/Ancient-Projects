#ifndef DRAWABLE_H
#define DRAWABLE_H

#include <SFML/Graphics.hpp>

#include <string>
#include <iostream>

class Drawable
{
    public:
        Drawable();
        virtual ~Drawable();

        void render(sf::RenderWindow &window);

        bool is_Active();
    protected:
        sf::Sprite sprite;
        sf::Texture texture;
        sf::IntRect subRect;

        void setSprite();

        virtual void logic();
        virtual void update();


        std::string name;
        std::string folder;

        bool isActive;

        float getXPos();
        float getYPos();
    private:
        std::string getName() const;
        std::string getFolder() const;

};

#endif // DRAWABLE_H
