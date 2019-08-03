cmake_minimum_required(VERSION 3.10)

#Set up project
project(city-game VERSION 1.0)

#Set executable
set(SOURCES
    Source/Main.cpp
    Source/Game/Game.cpp
    Source/Game/Util/Mouse.cpp
    Source/Game/Util/Debug_Log.cpp
    Source/Game/Util/Random.cpp
    Source/Game/Util/FPS_Counter.cpp
    Source/Game/Util/Window.cpp
    Source/Game/Managers/Music_Manager.cpp
    Source/Game/GUI/Button.cpp
    Source/Game/GUI/Symbolled_Update_Label.cpp
    Source/Game/GUI/GUI.cpp
    Source/Game/GUI/GUI_Feature.cpp
    Source/Game/GUI/Image.cpp
    Source/Game/States/Splash_Screen.cpp
    Source/Game/States/State_Handler.cpp
    Source/Game/States/Playing.cpp
    Source/Game/States/State_Base.cpp
    Source/Game/States/Menu.cpp
    Source/Game/City/City_Values.cpp
    Source/Game/City/City_Loader.cpp
    Source/Game/City/Person.cpp
    Source/Game/City/City.cpp
    Source/Game/City/Buildings/Building_Loader.cpp
    Source/Game/City/Buildings/Building_Preview.cpp
    Source/Game/City/Buildings/Builder.cpp
    Source/Game/City/Buildings/Building.cpp
    Source/Game/City/Buildings/Building_Data.cpp
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
