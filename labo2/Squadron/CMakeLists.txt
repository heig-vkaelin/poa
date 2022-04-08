cmake_minimum_required(VERSION 3.20)
project(Squadron)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wconversion -Wsign-conversion -pedantic")

add_executable(Squadron main.cpp ships/TIEFighter.cpp
        ships/cargo/Shuttle.cpp Squadron.cpp ships/Ship.cpp
        ships/cargo/CargoShip.cpp ships/cargo/StarDreadnought.cpp
        ships/TIEInterceptor.cpp ships/ShipSpecs.cpp ships/ShipSpecs.hpp ships/cargo/CargoShipSpecs.cpp ships/cargo/CargoShipSpecs.hpp)
