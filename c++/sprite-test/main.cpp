 #include <SFML/Graphics.hpp>
#include "blob.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");
    window.setFramerateLimit(60);

    blob player;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }


        window.clear();
        //Put everything that needs to be rendered here_______

        player.render(window);


        //end of rendering__________
        window.display();


    }

    return 0;
}
