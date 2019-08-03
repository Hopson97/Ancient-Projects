#include "Image.h"

#include "../Util/Window.h"

Image :: Image ( const sf::Vector2f& size,
                 const sf::Vector2f& position,
                 const sf::Vector2f& guiPos,
                 const sf::Texture& image)
:   GUI_Feature ( size, position, guiPos, image )
{

}

void Image :: draw()
{
    Window::draw( m_thing );
}

void Image :: onUpdate()
{

}
