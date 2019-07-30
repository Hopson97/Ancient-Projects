#ifndef WATER_H
#define WATER_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>    //For sin()

#include "../Engine/constants.h"
#include "../Utilities/random.h"

class Water
{

    class WaterSqaure
    {
        public:
            WaterSqaure(const sf::Vector2f& pos)
            {
                square.setPosition(pos);
                square.setSize({200.0f, 200.0f});
                square.setFillColor(sf::Color(rng ::num(0, 20), rng ::num(0, 20), rng ::num(100, 255), rng ::num(135, 255) ) ) ;

                xPos = square.getPosition().x;
                yPos = square.getPosition().y;
                time = 0;
            }

            const sf::RectangleShape& getSquare() const
            {
                return square;
            }

            void update(const float dt)
            {
                time += dt;
                square.move(sin(time + yPos) * 100 * dt,
                            0 );
            }

        private:
            sf::RectangleShape square;
            sf::Vector2f velocity;

            int xPos;
            int yPos;
            float time;
    };

    public:
        Water(double xBegin, double xEnd, double yBegin, double yEnd);
        void update     (const float dt);
        void draw       (sf::RenderWindow& window);

    private:
        std::vector<WaterSqaure> waterShapes;
};

#endif // WATER_H
