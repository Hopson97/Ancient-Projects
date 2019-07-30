#ifndef OBJECT_H
#define OBJECT_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Object
{
    public:
        Object                          (const sf::Texture& ghostTexture);
        virtual void draw               (sf::RenderWindow& window);

        void            setPos          (const sf::Vector2f pos);
        sf::Vector2f    getPos          () const;

        sf::Sprite      getSprite       () const;

        void            setColour       (const sf::Color& c);
        void            setTextureRect  (const sf::IntRect&  );

    protected:
        sf::Sprite      mSprite;

};

#endif // OBJECT_H
