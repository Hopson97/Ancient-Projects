cmake_minimum_required(VERSION 3.10)

#Set up project
project(heli-attack VERSION 1.0)

#Set executable
set(SOURCES
    Source/Components/effected_by_gravity.cpp
    Source/Components/friction.cpp
    Source/Components/Funcs/tile_map_component_funcs.cpp
    Source/Components/points_towards_direction.cpp
    Source/Components/tile_collidable.cpp
    Source/Entities/entity.cpp
    Source/Entities/player.cpp
    Source/Entities/test_enemy.cpp
    Source/Entities/Util/animation.cpp
    Source/Functions/out_of_bounds_checks.cpp
    Source/game.cpp
    Source/Guns/bullet.cpp
    Source/level.cpp
    Source/main.cpp
    Source/Managers/font_m.cpp
    Source/Managers/music_m.cpp
    Source/Managers/sound_m.cpp
    Source/Managers/texture_m.cpp
    Source/map_loader.cpp
    Source/Particles/gravity_particle.cpp
    Source/Particles/gravity_particles.cpp
    Source/States/handler.cpp
    Source/States/state_base.cpp
    Source/States/test.cpp
    Source/Tiles/air.cpp
    Source/Tiles/dirt.cpp
    Source/Tiles/grass.cpp
    Source/Tiles/tile.cpp
    Source/Tiles/Util/tile_model.cpp
    Source/Util/camera.cpp
    Source/Util/colours.cpp
    Source/Util/fps_counter.cpp
    Source/Util/rand.cpp
    Source/Util/soundeffect.cpp
    Source/Util/window.cpp
    Source/world.cpp
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
