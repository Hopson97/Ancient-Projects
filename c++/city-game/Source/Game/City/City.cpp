#include "City.h"

#include <iostream>
#include <cassert>

#include "../Util/Window.h"
#include "../Util/Random.h"

#include "../Game.h"


City::City( const std::string& name )
:   m_name      ( name )
,   m_builder   ( *this, m_values )
,   m_actionGUI ( { Window::WIDTH / 8, Builder::BUILD_MENU_HEIGHT}, { Window::WIDTH - Window::WIDTH / 8, Builder::BUILD_MENU_SEC_Y } )
,   m_newDayGUI ( { Window::WIDTH / 6, 100 }, {  Window::WIDTH / 2 - Window::WIDTH / 6, 25 } )
{
    m_background.setSize( { WIDTH, HEIGHT } );
    this->init();

    m_actionGUI.setBgColour( { 50, 50, 50 } );

    m_actionGUI.beginColumn( {10, 0 }, 5 );

    m_actionGUI.addSymbolUpdateLabel( { 20, 20 },
                                      Game::getTexture( Texture_Name::Days),
                                      m_day,
                                      "Number of days passed" );

    m_actionGUI.addButton ( {50, 20 },
                            Game::getTexture( Texture_Name::GUI_Next_Day_Button ),
                            std::bind ( &City::nextDay, this ) );

    m_actionGUI.setTitle( "Actions" );
    m_actionGUI.update();
}

void City::removeBuilding( Building& b )
{
    //Re add the resources and then get the group of people of whom were evicted
    m_values.m_resources += b.data.getCost() / 4;

    Person_Group group = b.destroy();

    m_values.m_statistics.homeless              += group.occupants.size ();
    m_values.m_statistics.vacancy               += group.occupants.size ();
    m_values.m_statistics.unemployedPopulation  += group.occupants.size ();

    m_values.m_statistics.jobs                  += group.workers.size   ();
    m_values.m_statistics.unemployedPopulation  += group.workers.size   ();


    //m_values.m_statistics -= b.data.getStats();
    group.clear();
}

void City::tryDestory(sf::FloatRect area)
{
    for ( size_t i = 0 ; i < m_buildings.size() ; i++ )
    {
        Building& b = *m_buildings.at( i );
        if ( b.bounds.intersects ( area ) ) {
            b.destroy();
            removeBuilding( b );
            m_buildings.erase( m_buildings.begin() + i );
        }
    }
}

void City :: update( float dt)
{
    m_builder.input();

    m_values.update();

    m_builder.update();

    m_newDayGUI.update();
    m_actionGUI.update();

    if ( m_dayTimer.getElapsedTime() >= m_dayLength ) {
        nextDay();
    }
}

void City :: draw()
{
    Window::draw( m_background );

    for ( auto& building : m_buildings ) {
        building->draw();
    }

    m_builder.draw();
    m_values.draw(); //aka the gui

    m_actionGUI.draw();
    //m_newDayGUI.draw();
}

void City :: tryAddBuilding ( std::shared_ptr<Building> b )
{
    //Make sure it is actually being added within the bounds of the map
    if ( !b->bounds.intersects( m_background.getGlobalBounds() ) ) return;

    //If all the checks have passed, it will add the buildings
    addBuilding( b );
}

void City :: addBuilding( std::shared_ptr<Building>b )
{
    //Deduct/ Increase the player's resource values
    m_values.m_resources  -= b->data.getCost();
    m_values.m_statistics += b->data.getStats();

    m_buildings.push_back( b );

}

void City :: nextDay ()
{
    m_day++;
    m_dayTimer.restart();
    m_values.newDay( getWorkPlaces() );
    m_values.newDay( getHouses() );


    tryGetHomelessHouses();
    tryGetMoveIns();
    tryAddWorkers();

    m_values.m_statistics.population = m_people.size();
}

int City :: getMoveInCount ( int& stat, int chance )
{
    int people = Random::integer( 0, m_day + 5 );

    if ( people > 5 ) {
        people = 5;
    }
    if ( people > stat ) {
        people = stat;
    }
    return people;
}


void City::tryGetMoveIns()
{
    int& vacant = m_values.m_statistics.vacancy;
    if ( vacant == 0 ) {
        return;
    }
    //Add new people into the city if there are vacancies
    int people = getMoveInCount( vacant, 10 );

    for ( int i = 0 ; i < people ; i++ ) {
        addPerson ();
        vacant --;
    }

    m_values.m_statistics.population = m_people.size();
}

void City::tryGetHomelessHouses()
{
    int& homeless = m_values.m_statistics.homeless;
    if ( homeless == 0 ) {
        return;
    }
    int people = getMoveInCount( homeless, 5 );

    std::vector<PersonPtr> homelessList = getHomelessPeople();

    if ( homelessList.empty() ) {
        return;
    }

    for ( int i = 0 ; i < people ; i++ ) {
        for ( auto& house : getVacantHouses() ) {
            addPersonToHouse( homelessList.at( i ), house );
            homeless--;
        }
    }
}


void City::tryAddWorkers()
{
    auto workPlaces = getWorkPlaces();
    if ( workPlaces.size() == 0 ) return;

    for ( auto& person : getUnemployedPeople() )
    {
        int workPlace = Random::integer( 0, workPlaces.size() - 1 ) ;
        Building& b = *workPlaces.at( workPlace );

        if ( b.isSpaceForWork() ) {
            b.addWorker( person );

            m_values.m_statistics.unemployedPopulation--;
            m_values.m_statistics.jobs--;

            person->setWork ( b );
        }
    }
}


void City :: addPerson ()
{
    for ( auto& house : getVacantHouses() ) {
        PersonPtr p = std::make_shared<Person>();
        m_people.push_back( p );
        addPersonToHouse( p, house );
        m_values.m_statistics.unemployedPopulation++;
        break;
    }
}

void City :: addPersonToHouse( PersonPtr person, BuildingPtr house )
{
    house ->addPerson   ( person );
    person->setHouse    ( *house  );
}

Building_Ptr_Vector City :: getBuildingsOfType( Building_Use use )
{
    Building_Ptr_Vector buildings;
    for ( auto& building : m_buildings ) {
        if ( building->data.getUse() == use ) {
            buildings.push_back( building );
        }
    }
    return buildings;
}

Building_Ptr_Vector City :: getHouses()
{
    return getBuildingsOfType ( Building_Use::Housing );
}

Building_Ptr_Vector City :: getWorkPlaces()
{
    return getBuildingsOfType ( Building_Use::Work );
}

Building_Ptr_Vector City::getVacantHouses()
{
    Building_Ptr_Vector houses;
    for ( auto& house : getHouses() ) {
        if ( house->isSpacesAvalibleToLive() ) {
            houses.push_back( house );
        }
    }
    return houses;
}




Person_Ptr_Vector City::getHomelessPeople()
{
    Person_Ptr_Vector list;

    for ( auto& person : m_people ) {
        if ( person->isHomeless() ) {
                list.push_back( person );
        }
    }
    return list;
}

Person_Ptr_Vector City::getUnemployedPeople()
{
    Person_Ptr_Vector list;

    for ( auto& person : m_people ) {
        if ( person->isUnemployed() ) {
                list.push_back( person );
        }
    }
    return list;
}


const FloatRect_Vector& City :: getWaterSections() const
{
    return m_waterSections;
}

const FloatRect_Vector& City :: getGroundSections() const
{
    return m_groundSections;
}

const FloatRect_Vector& City::getNoBuildSections() const
{
    return m_noBuildSections;
}

const Building_Ptr_Vector& City :: getBuildings () const
{
    return m_buildings;
}
