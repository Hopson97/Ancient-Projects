cmake_minimum_required(VERSION 3.10)

#Set up project
project(doodle-jump VERSION 1.0)

#Set executable
set(SOURCES
    Source/Game/game.cpp
    Source/Game/Game_Objects/platform.cpp
    Source/Game/Game_Objects/player.cpp
    Source/Game/Managers/music_manager.cpp
    Source/Game/States/menu.cpp
    Source/Game/States/playing.cpp
    Source/Game/States/splash_screen.cpp
    Source/Game/States/state_base.cpp
    Source/Game/States/state_handler.cpp
    Source/Game/Util/random.cpp
    Source/Game/Util/window.cpp
    Source/main.cpp
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
