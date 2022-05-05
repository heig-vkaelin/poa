cmake_minimum_required(VERSION 3.20)
project(Riviere)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wconversion -Wsign-conversion -pedantic")

add_executable(Riviere main.cpp containers/Container.cpp containers/Container.hpp containers/Boat.cpp containers/Boat.hpp containers/Bank.cpp containers/Bank.hpp persons/Person.cpp persons/Person.hpp Controller.cpp Controller.hpp persons/DependantPerson.cpp persons/DependantPerson.hpp persons/IndependantPerson.cpp persons/IndependantPerson.hpp persons/Girl.cpp persons/Girl.hpp persons/Boy.cpp persons/Boy.hpp persons/Thief.cpp persons/Thief.hpp)
