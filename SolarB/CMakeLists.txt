# Works with 3.14 and tested through 3.27
cmake_minimum_required(VERSION 3.23)

# Project name and a few useful settings. Other commands can pick up the results
project(SolarB VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_SUPPRESS_REGENERATION true)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

if(CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "-Wall -Wextra")
    set(CMAKE_CXX_FLAGS_DEBUG "-g")
    set(CMAKE_CXX_FLAGS_RELEASE "-O3")
endif(CMAKE_COMPILER_IS_GNUCXX)


set( SOURCE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/src" )
set( INCLUDE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/src" )

find_package(OpenGL REQUIRED)

#add_subdirectory(../lib/Glad/ build)
add_subdirectory(vendor/glfw/ EXCLUDE_FROM_ALL)
add_subdirectory(vendor/Glad/)
add_subdirectory(vendor/stb_image/)
add_subdirectory(vendor/glm/)

#add_executable(SolarB)
add_library(SolarB STATIC)

target_sources(
    SolarB
    PRIVATE
       "${SOURCE_PATH}/entry.cpp"
       "${SOURCE_PATH}/window/win_app.cpp"
       "${SOURCE_PATH}/renderer/renderer.cpp"
       "${SOURCE_PATH}/game/game.cpp"
       "${SOURCE_PATH}/layer/layer.cpp"
    PUBLIC
        "${INCLUDE_PATH}/window/win_app.h"
        "${INCLUDE_PATH}/renderer/renderer.h"
        "${INCLUDE_PATH}/game/game.h"
        "${INCLUDE_PATH}/layer/layer.h"
)

# Assuming this is meant to be a public directory
target_include_directories(SolarB PUBLIC ${INCLUDE_PATH} )

target_link_libraries(
                    SolarB
                    PUBLIC
                        glad
                        glfw
                        stb_image
                        glm
)

