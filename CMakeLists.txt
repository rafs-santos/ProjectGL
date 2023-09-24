# Works with 3.14 and tested through 3.27
cmake_minimum_required(VERSION 3.23)

# Project name and a few useful settings. Other commands can pick up the results
project(ProjectGL VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 20)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

if(CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "-Wall -Wextra")
    set(CMAKE_CXX_FLAGS_DEBUG "-g")
    set(CMAKE_CXX_FLAGS_RELEASE "-O3")
endif(CMAKE_COMPILER_IS_GNUCXX)


set( SOURCE_PATH "${PROJECT_SOURCE_DIR}/src" )
set( INCLUDE_PATH "${PROJECT_SOURCE_DIR}/include" )


find_package(OpenGL REQUIRED)

#add_subdirectory(../lib/Glad/ build)
add_subdirectory(lib/glfw/ EXCLUDE_FROM_ALL)
add_subdirectory(lib/Glad/)



add_executable(ProjectGL)

target_sources(
    ProjectGL
    PRIVATE
       "${SOURCE_PATH}/main.cpp"
       "${SOURCE_PATH}/window/win_app.cpp"
    PUBLIC
        "${INCLUDE_PATH}/config.h"
        "${INCLUDE_PATH}/win_app.h"
)

# Assuming this is meant to be a public directory
target_include_directories(ProjectGL PUBLIC ${INCLUDE_PATH} )

target_link_libraries(
                    ProjectGL
                    PRIVATE
                        glfw
                        glad
)

