cmake_minimum_required(VERSION 3.20)
project(MatrixReloaded)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wconversion -Wsign-conversion -pedantic")

add_executable(MatrixReloaded main.cpp Matrix.cpp Matrix.h)
