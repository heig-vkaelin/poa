cmake_minimum_required(VERSION 3.20)
project(Riviere)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wconversion -Wsign-conversion -pedantic")

add_executable(Riviere main.cpp containers/Container.cpp
        containers/Boat.cpp containers/Bank.cpp
        people/Person.cpp Controller.cpp people/IndependantPerson.cpp
        people/Boy.cpp people/Girl.cpp people/Thief.cpp people/Kid.cpp Test.cpp)
