#include "water.h"

Water::Water(double xBegin, double xEnd, double yBegin, double yEnd)
{
    for ( double x = xBegin ; x < xEnd ; x++)
    {
        for ( double y = yBegin ; y < yEnd ; y++ )
        {
            waterShapes.emplace_back(WaterSqaure({
                                                    (float) x * 200,
                                                    (float) y * 200
                                                }));
        }
    }
}

void Water::update(const float dt)
{
    for ( auto& w : waterShapes ) {
        w.update(dt);
    }
}

void Water::draw(sf::RenderWindow& window)
{
    for ( auto& waterShape : waterShapes ) {
        window.draw( waterShape.getSquare() );
    }
}
