cmake_minimum_required(VERSION 3.10)

#Set up project
project(op-ftw-game VERSION 1.0)

#Set executable
set(SOURCES
    src/Engine/animation.cpp
    src/Engine/Entity/entity.cpp
    src/Engine/Entity/entity_text.cpp
    src/Engine/game.cpp
    src/Engine/main.cpp
    src/Engine/pathfinder.cpp
    src/Engine/ResourceManagers/font_m.cpp
    src/Engine/ResourceManagers/sound_m.cpp
    src/Engine/ResourceManagers/texture_m.cpp
    src/Engine/shiploader.cpp
    src/Engine/spritedancer.cpp
    src/Engine/UI/button.cpp
    src/Engine/UI/unitshower.cpp
    src/input/keyboard.cpp
    src/Objects/Ship_Objects/room.cpp
    src/Objects/Ship_Objects/Ship/ship_component.cpp
    src/Objects/Ship_Objects/Ship/ship.cpp
    src/Objects/Ship_Objects/Ship/ship_mutators.cpp
    src/Objects/Ship_Objects/Unit/level.cpp
    src/Objects/Ship_Objects/Unit/unit.cpp
    src/Objects/Ship_Objects/Unit/unit_loader.cpp
    src/Objects/Ship_Objects/wall.cpp
    src/Objects/water.cpp
    src/States/mainmenu.cpp
    src/States/newgameshipselector.cpp
    src/States/Playing/play.cpp
    src/States/Playing/play_stationary.cpp
    src/States/splashscreen.cpp
    src/States/state.cpp
    src/States/statehandler.cpp
    src/Utilities/random.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

#Set C++17
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_EXTENSIONS OFF)

#Set flags
if(MSVC)
  	target_compile_options(${PROJECT_NAME} PRIVATE 
    	/W4 /WX)
else()
  	target_compile_options(${PROJECT_NAME} PRIVATE 
		-Wall -Wextra -pedantic)		#Warning flags
endif()

#Set module path
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

#Find libraries
find_package(Threads)
find_package(SFML REQUIRED audio network graphics window system)

#Finally
target_link_libraries(${PROJECT_NAME} 
    Threads::Threads 
    ${SFML_LIBRARIES} 
    ${SFML_DEPENDENCIES}
)
