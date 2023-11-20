# Works with 3.14 and tested through 3.27
cmake_minimum_required(VERSION 3.23)

# Project name and a few useful settings. Other commands can pick up the results
project(Sandbox VERSION 0.0.1)

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

add_subdirectory(SolarB)
add_subdirectory(Sandbox)

