#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>

#include "../ResourceManagers/texture_m.h"
#include "../spritedancer.h"

class Entity
{
    public:
                explicit        Entity          (const sf::Texture& t);
                                Entity          (const sf::Texture& t, const std::string& text, const int textSize, const sf::Font& font);
                                Entity          (const sf::Texture& t, const std::string& text, const sf::Vector2f& pos, const int textSize, const sf::Font& font);
                                Entity          ();
        virtual void            draw            (sf::RenderWindow& window);

                void            setPos          (  const sf::Vector2f& pos  );
                void            setRot          (  const int rot            );
                void            setColour       (  const sf::Color& c       );
                void            setOrigin       (  const sf::Vector2f& org  );
                void            setToRandColour ();

        const   sf::Vector2f    getPos          () const;
        const   sf::Sprite      getSprite       () const;

                void            centerOrigin    (const sf::Vector2f& newPos);

                void            setUpText       (const std::string& text, const int textSize, const sf::Font& font);
                void            setText         (const std::string& text);
                void            setTextSize     (const int characterSize);
                void            moveTextDown    (const int amount);


                void            centerOrigin    ();

                void            dance          (const float dt);

    protected:
                sf::Sprite&     _mSprite        ();
                void            setTextureRect  (const sf::IntRect& rect);
                void            centerText      ();

    private:
        sf::Sprite              mSprite;
        sf::Text                mText;

        SpriteDancer            dancer;
};

#endif // ENTITY_H
