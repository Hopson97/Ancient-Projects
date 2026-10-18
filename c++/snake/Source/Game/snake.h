#ifndef SNAKE_H
#define SNAKE_H

#include <SFML/Graphics.hpp>
#include <vector>

enum class Direction
{
    Up,
    Down,
    Left,
    Right
};

const static std::map<Direction, sf::Vector2i> dirToVector
{
    { Direction::Up     ,   { 0, -1 } },
    { Direction::Down   ,   { 0,  1 } },
    { Direction::Left   ,   { -1, 0 } },
    { Direction::Right  ,   { 1,  0 } }
};

class Snake
{
    struct Segment;
    public:
        Snake();

        void setDirection   ( const Direction direction );
        void update         ();
        void draw           ( sf::RenderWindow& window );
        void addSegment     ( const int amount );

        const sf::Vector2i getNextPosition    () const;

        const std::vector<Segment>& getSegments () const;

    private:
        void checkSelfCollide   ();

        sf::RectangleShape m_segmentRectangle;

        Direction m_direction = Direction::Down;

        struct Segment
        {
            sf::Vector2i position;
        };

        std::vector<Segment> m_segments;
        int m_segmentsToAdd = 0;

};

#endif // SNAKE_H
