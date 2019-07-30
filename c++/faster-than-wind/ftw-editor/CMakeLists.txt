cmake_minimum_required(VERSION 3.10)

#Set up project
project(ftw-editor VERSION 1.0)

#Set executable
set(SOURCES
    src/Editor/background.cpp
    src/Editor/dotmap.cpp
    src/Editor/ghost.cpp
    src/Editor/object.cpp
    src/Editor/ShipObjects/room.cpp
    src/Editor/ShipObjects/Ship/ship.cpp
    src/Editor/ShipObjects/Ship/ship_room_handler.cpp
    src/Editor/ShipObjects/Ship/ship_unit_handler.cpp
    src/Editor/ShipObjects/unit.cpp
    src/Editor/ShipObjects/wall.cpp
    src/Editor/UI/button.cpp
    src/Editor/UI/currentlyselected.cpp
    src/Editor/UI/objectmenu.cpp
    src/main.cpp
    src/program.cpp
    src/States/edit_state.cpp
    src/States/edit_state_file_handler.cpp
    src/States/edit_state_room_mode.cpp
    src/States/edit_state_unit_mode.cpp
    src/States/edit_state_wall_mode.cpp
    src/States/start_state.cpp
    src/States/state.cpp
    src/texturemanager.cpp
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
