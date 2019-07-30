#include "entity.h"

#include "../constants.h"

Entity::Entity(const sf::Texture& t, const std::string& text, const sf::Vector2f& pos, const int textSize, const sf::Font& font)
: mSprite(t)
{
    mSprite.setPosition(pos);
    setUpText(text, textSize, font);
}

Entity::Entity(const sf::Texture& t, const std::string& text, const int textSize, const sf::Font& font)
{
    setUpText(text, textSize, font);
}

/*****************************************************************************************************************************************************************
*   setUpText() if the entity should have some text to show, this this the place where it is set up, and tries to estimate where the text should be
*   param1  :   The text to be displayed on the button
*   param2  :   The position of the text
***************************************************************************************************************************************************************/
void Entity::setUpText(const std::string& text, const int textSize, const sf::Font& font)
{
    mText.setString       ( text                                );
    mText.setFont         ( font                                );
    mText.setCharacterSize( textSize                            );
    mText.setColor        ( col::TEXT_COLOUR                    );

    centerText();
}

/*****************************************************************************************************************************************************************
*   setTextSize ()  sets the size of the text (if there is any)
*   param1  :   the size of the text
***************************************************************************************************************************************************************/
void Entity::setTextSize        ( const int cSize               )
{
    mText.setCharacterSize(cSize);
    centerText();
}

void Entity::setText( const std::string& text)
{
    mText.setString(text);

    centerText();
}

void Entity::centerText()
{
    sf::FloatRect tb = mText.getLocalBounds();    //Text bounds
    sf::FloatRect sb = mSprite.getLocalBounds();   //Sprite bounds

    mText.setOrigin({
                    float(tb.width/2),
                    float(tb.height/2)
                    });

    mText.setPosition({
                      ( mSprite.getPosition().x ) + ( sb.width / 2  ),
                      ( ( mSprite.getPosition().y ) + ( sb.height / 2 ) ) - ( tb.height / 2)
                      });
}

void Entity::moveTextDown(const int amount)
{
    mText.move( 0, amount );
}
