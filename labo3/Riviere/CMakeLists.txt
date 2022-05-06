cmake_minimum_required(VERSION 3.20)
project(Riviere)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wconversion -Wsign-conversion -pedantic")

add_executable(Riviere main.cpp containers/Container.cpp containers/Container.hpp containers/Boat.cpp containers/Boat.hpp containers/Bank.cpp containers/Bank.hpp people/Person.cpp people/Person.hpp Controller.cpp Controller.hpp people/DependantPerson.cpp people/DependantPerson.hpp people/IndependantPerson.cpp people/IndependantPerson.hpp people/Girl.cpp people/Girl.hpp people/Boy.cpp people/Boy.hpp people/Thief.cpp people/Thief.hpp people/Kid.cpp people/Kid.hpp)
