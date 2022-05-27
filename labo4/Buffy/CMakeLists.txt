cmake_minimum_required(VERSION 3.20)
project(Buffy)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wconversion -Wsign-conversion -pedantic")

add_executable(Buffy main.cpp actors/Buffy.cpp
        actors/Human.cpp actors/Vampire.cpp actors/Humanoid.cpp
        Field.cpp actions/Action.cpp actions/Move.cpp Utils/Direction.cpp Utils/Utils.cpp
        displayers/Displayer.cpp displayers/UnixDisplayer.cpp displayers/WindowsDisplayer.cpp
        Controller.cpp actions/Kill.cpp actions/Transform.cpp Utils/Position.cpp)
