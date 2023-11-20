cmake_minimum_required(VERSION 3.23)
project(Sandbox)

add_executable(Sandbox)

target_sources(
    Sandbox
    PRIVATE
       "${CMAKE_CURRENT_SOURCE_DIR}/sandbox.cpp"
       "${CMAKE_CURRENT_SOURCE_DIR}/sandbox_layer.cpp"
    PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/sandbox_layer.h"
)

# Assuming this is meant to be a public directory
target_include_directories(Sandbox PUBLIC ${INCLUDE_PATH} )

target_link_libraries(
                Sandbox
                    PRIVATE
                        SolarB
)

