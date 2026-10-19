#include <SFML/Graphics.hpp>

#include <iostream>
#include <vector>
#include <memory>
#include "Random.h"
#include "globals.h"
#include "powder.h"

using namespace std;

int global::powderCount;

Powder addPowder(sf::RenderWindow &w)   //Creates/ Add new powder object to a vector
{
        std::shared_ptr<Powder> px(new Powder(w));
        //Powder px(w);
        return *px;
}

int main()
{
    srand(time(NULL));  //For random
    sf::RenderWindow window(sf::VideoMode({800, 600}), "SFML works!",
                            sf::Style::Titlebar | sf::Style::Close);    //Create window
    window.setFramerateLimit(65);       //Set frame rate limit
    std::vector <Powder> Vpowders;      //Vector of powder objects
    random rand;
    int deletePowder = 0;               //Thing to test if powder needs deleting.
    while (window.isOpen())
    {
        while (auto event = window.pollEvent())
        {
            if (event->is < sf::Event::Closed>())
            {
                window.close();

            }
        }


        if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) //If clicking
        {
            //if(Vpowders.size() < 5)
            Vpowders.push_back(addPowder(window)); //Add powder to the vector list
        }

        global::powderCount = Vpowders.size();  //The powder count = the vector size

//PRINT INFO HERE
         std::cout  << "Powers: "
                    << global::powderCount
                    << std::endl;

         int mousePosX;
         int mousePosY;
         mousePosX = sf::Mouse::getPosition().x;
         mousePosY = sf::Mouse::getPosition().y;

         std::cout  << "Mouse X, Y: "
                    << mousePosX << " , "
                    << mousePosY
                    << std::endl;

//END OF INFO

        for(unsigned int i = 0; i < Vpowders.size(); i++ )  //Check for collisions
        {
            for(unsigned int j = 0; j < Vpowders.size(); j++ )
            {
                if(Vpowders[i].getXPos() == Vpowders[j].getYPos())
                {
                    Vpowders[i].setPos  (Vpowders[i].getXPos() + float(rand.randRange(-3,3)),
                                        float(Vpowders[i].getYPos()));
                }
            }
        }

        window.clear();
        for(unsigned int i = 0; i < Vpowders.size(); i++ )  //Draw powders
        {
            deletePowder = Vpowders[i].draw(window);    //Check if powder can be dleted
            if(deletePowder == 1)
            {
                Vpowders.erase(Vpowders.begin() + i);   //Delete not needed powder
            }
        }
        window.display();
    }

    return 0;
}




