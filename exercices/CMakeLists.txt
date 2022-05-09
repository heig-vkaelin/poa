cmake_minimum_required(VERSION 3.20)
project(exercices)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wconversion -Wsign-conversion -pedantic")

add_executable(exercices main.cpp Season/Season.cpp
        Musician/Musician.cpp Musician/Band.cpp)
