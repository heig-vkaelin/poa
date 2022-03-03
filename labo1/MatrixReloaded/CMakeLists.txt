cmake_minimum_required(VERSION 3.20)
project(MatrixReloaded)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wconversion -Wsign-conversion -pedantic")

add_executable(MatrixReloaded main.cpp Matrix.cpp Matrix.hpp Utils.cpp Utils.hpp Operator.hpp Multiply.cpp Multiply.hpp Add.cpp Add.hpp Subtract.cpp Subtract.hpp)
