#ifndef CURRENTLYSELECTED_H
#define CURRENTLYSELECTED_H

#include <map>

#include "../../texturemanager.h"

#include "../ShipObjects/room.h"
#include "../ShipObjects/unit.h"
#include "../object.h"

#include "objectmenu.h"

//Enum for the room type is in room.h

class CurrentlySelected : public Object
{
    public:
        CurrentlySelected(const sf::Texture& t, const TextureManager& textures);

        bool updateSelected(const RoomType room, const sf::Texture& texture);   //Tell the object what object is currently selected
        bool updateSelected(const UnitType unit, const sf::Texture& texture);   //Tell the object what object is currently selected

        void draw(sf::RenderWindow& window) override;               //Draw the scroll/ rectangle

    private:
        void setTexture(const sf::Texture& texture);

    private:
        std::map<RoomType, std::string> roomTextMap;
        std::map<UnitType, std::string> unitTextMap;

        sf::RectangleShape selected;
        sf::Text selectedText;
        sf::Font font;
};

#endif // CURRENTLYSELECTED_H
