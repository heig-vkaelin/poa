cmake_minimum_required(VERSION 3.21)
project(Squadron)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wconversion -Wsign-conversion -pedantic")

add_executable(Squadron main.cpp Ship.hpp)
