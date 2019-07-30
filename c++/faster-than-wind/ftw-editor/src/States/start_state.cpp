#include "start_state.h"

#include <fstream>
#include <string>
#include <sstream>

StartState::StartState(Program* p):
    State(p)
{
    filePath = "../FasterThanWind/Resources/Textures/Ships/";
}


/*
=================================================================================================================================================================
input() is an override method. Here, it prompts the user to choose whether they would like to either create a new ship or load a ship
=================================================================================================================================================================
*/
void StartState::input  ()
{
    std::cout   << "Hello. Are you loading or making new ship? \n"  //Ask
                << "1. New Ship  \n"
                << "2. Load Ship \n";
    int selection;
    while (selection != 1 && selection != 2)        //While the selection is invalid
    {
        std::cin >> selection;                      //Ask user to input selection
        if (selection != 1 && selection != 2)       //If invalid, prompt instructions again
        {
            std::cout << "Please enter either \"1\"(new ship) or \"2\"(load ship). " << std::endl;
        }
        else break;
    }
    if      (selection == 1) newShip();     //if selection is one, create new ship
    else if (selection == 2) loadShip();    //if selection is two, load new ship
}



/*
=================================================================================================================================================================
newShip() is a method called when the user decides to create a new ship
=================================================================================================================================================================
*/
void StartState::newShip()
{
    std::string shipName;
    std::string oldPath = filePath;

    sf::Texture shipTexture;

    bool isReal = false;
    do
    {
        std::cout << "What is the name of the ships texture?" << std::endl;
        std::cin >> shipName;
        filePath += shipName + ".png";
        if (!shipTexture.loadFromFile(filePath))
        {
            std::cout << "Texture \""<< filePath << "\" does not exist! Try again." << std::endl << std::endl;
            filePath = oldPath;
            continue;
        }
        else if(shipTexture.loadFromFile(filePath))
        {
            sf::Sprite dimChker;
            dimChker.setTexture(shipTexture);

            if(checkDimensions(dimChker)) break;
            else continue;

            isReal = true;
        }
        break;
    }
    while (!isReal);

    std::cout << "loading editor..." << std::endl;
    printControls();
    mProgram->changeState(std::make_shared<EditState>(mProgram, filePath, shipName, shipTexture));
}

/*
=================================================================================================================================================================

=================================================================================================================================================================
*/
bool StartState::checkDimensions(const sf::Sprite& dimChker)
{
    if(dimChker.getLocalBounds().width > 600)//Max ship width
    {
        std::cout   << "You're ship has a width of: " << dimChker.getLocalBounds().width
                    << ". The maximum width is 600. Try again." << std::endl;
        return false;
    }
    if(dimChker.getLocalBounds().height > 320)  //Max ship height
    {
        std::cout   << "You're ship has a height of: " << dimChker.getLocalBounds().height
                 << ". The maximum height is 320. Try again." << std::endl;
        return false;
    }
    std::cout << "\n";
    return true;
}

std::string toSting(int n)
{
    std::stringstream conv;
    conv << n;
    return conv.str();
}
std::string getShipName()
{
    std::cout << "What is the ship name to be loaded? \n";
    std::string temp;
    std::getline(std::cin, temp);

    return temp;
}
std::string getShipLayout()
{
    std::cout << "Which layout are you loading? \n";
    int layout;
    std::cin >> layout;
    return toSting(layout);
}

/*
=================================================================================================================================================================

=================================================================================================================================================================
*/
void StartState::loadShip()
{
    std::ifstream checker;
    std::cin.ignore();
    std::string shipName;
    std::string layout;

    std::string temp;

    do
    {
        shipName =  getShipName();
        layout  =   getShipLayout();

        checker.open("../FasterThanWind/Resources/Ship Info/" + shipName + layout + ".ship");
        if(!checker) {
            std::cout << "Ship name does not exist, try again." << std::endl;
            continue;
        }
        else {
            break;
        }


    }
    while(!checker.good());

    std::string filepath;
    checker >> filepath;

    sf::Texture shipTexture;
    shipTexture.loadFromFile(filepath);
    printControls();

    mProgram->changeState(std::make_shared<EditState>(mProgram, filepath, shipName, shipTexture, "../FasterThanWind/Resources/Ship Info/" + shipName + layout + ".ship"));
}

void StartState::printControls()
{
    std::cout   << "====================================================================================\n"
                << "CONTROLS:                                                                           \n"
                << "~~~~~~~~~~                                                                          \n"
                << "Controls for 'room mode':                                                           \n"
                << "Left Click: Add room                                                                \n"
                << "Right Click: Remove room                                                            \n"
                << "R Button: Roll over a room and press 'r' to rotate the room 90 degrees.             \n"
                << "Use the menu below to switch to a new room type.                                    \n"
                << "Pressing the 'switch to wall mode' button will allow placement/ removal of doors    \n"
                << "\n                                                                                  \n"
                << "Controls for 'wall mode':                                                           \n"
                << "Left Click: on a wall (yellow) to turn it into a door.                              \n"
                << "Right Click: on a door (red) to revert back to a wall.                              \n"
                << "R Button: Pressing 'r' will rotate the selection, so you can switch between vertical and horizontal doors/ walls\n"
                << "Pressing the 'switch to room mode' button will allow placement/ removal of rooms    \n"
                << "\n                                                                                  \n"
                << "General controls:                                                                   \n"
                << "Press 's' to save your ship!                                                        \n"
                << "====================================================================================\n";
}

void StartState::update ()
{}

void StartState::draw   ()
{}























