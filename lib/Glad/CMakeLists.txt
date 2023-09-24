cmake_minimum_required(VERSION 3.23)
project(Glad)

add_library(glad)

target_sources(
    glad
    PUBLIC
        include/glad/glad.h
    PRIVATE
        src/glad.c
)

target_include_directories(
    glad
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)



