cmake_minimum_required(VERSION 3.22)
project(Buffy)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wconversion -Wsign-conversion -pedantic")

add_executable(Buffy main.cpp)
