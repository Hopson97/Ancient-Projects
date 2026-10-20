cmake_minimum_required(VERSION 3.10)

project(
    gl-waves 
    VERSION 1.0
)

include("$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake")

add_executable(${PROJECT_NAME}
    src/main.cpp
    src/camera.cpp
    src/shader.cpp
)

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_23)
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_EXTENSIONS OFF)

target_compile_definitions(${PROJECT_NAME} PRIVATE GLM_ENABLE_EXPERIMENTAL)

if(MSVC)
    set(CMAKE_CXX_FLAGS_RELEASE "/O2")
    set(CMAKE_CXX_FLAGS_RELEASE "/Ox")
  	target_compile_options(${PROJECT_NAME} PRIVATE /W4 _CRT_SECURE_NO_WARNINGS)
else()
  	target_compile_options(${PROJECT_NAME} PRIVATE 
		-Wall -Wextra -pedantic)		
endif()

find_package(glm CONFIG REQUIRED)
find_package(SFML COMPONENTS system audio network window graphics CONFIG REQUIRED)

add_subdirectory(deps)
target_include_directories(
    ${PROJECT_NAME}
    PRIVATE
    deps
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    sfml-system sfml-audio sfml-network sfml-graphics sfml-window
    glm::glm
    glad 
)
