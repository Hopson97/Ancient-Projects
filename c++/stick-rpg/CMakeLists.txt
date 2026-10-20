cmake_minimum_required(VERSION 3.10)

#Set up project
project(
    stick-rpg 
    VERSION 1.0
)

include("$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake")

add_executable(${PROJECT_NAME}
    Source/Animation.cpp
    Source/Application.cpp
    Source/Effect/Bubbles.cpp
    Source/GUIMeni/Banner.cpp
    Source/GUIMeni/BasicButton.cpp
    Source/GUIMeni/ColumnMenu.cpp
    Source/GUIMeni/Component.cpp
    Source/GUIMeni/VariableButton.cpp
    Source/Level/LevelLoader.cpp
    Source/LevelRenderer.cpp
    Source/main.cpp
    Source/Player/HealthBar.cpp
    Source/Player/Health.cpp
    Source/Player/Player.cpp
    Source/ResourceManager/ResourceHolder.cpp
    Source/SpecialSprite/ClickableRectangle.cpp
    Source/States/SBase.cpp
    Source/States/SMainMenu.cpp
    Source/States/SPlaying.cpp
    Source/Util/Random.cpp
)

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_23)
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_EXTENSIONS OFF)

if(MSVC)
    set(CMAKE_CXX_FLAGS_RELEASE "/O2")
    set(CMAKE_CXX_FLAGS_RELEASE "/Ox")
  	target_compile_options(${PROJECT_NAME} PRIVATE 
    	/W4)
else()
  	target_compile_options(${PROJECT_NAME} PRIVATE 
		-Wall -Wextra -pedantic)		
endif()

find_package(SFML COMPONENTS system audio network window graphics CONFIG REQUIRED)

add_subdirectory(deps)
target_include_directories(
    ${PROJECT_NAME}
    PRIVATE
    deps
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    sfml-system sfml-audio sfml-network sfml-graphics sfml-window
    imgui::imgui
)
