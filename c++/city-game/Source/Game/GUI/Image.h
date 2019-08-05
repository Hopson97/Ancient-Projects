#ifndef IMAGE_H
#define IMAGE_H

#include "GUI_Feature.h"

class Image : public GUI_Feature
{
    public:
        Image(  const sf::Vector2f& size,
                const sf::Vector2f& position,
                const sf::Vector2f& guiPos,
                const sf::Texture&  image );

        void draw () override;

    private:
        void onUpdate() override;
};

#endif // IMAGE_H
