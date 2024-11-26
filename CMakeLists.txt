cmake_minimum_required(VERSION 3.30)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(MatrixC VERSION 1.0)
add_executable(matrix main.cpp src/matrixDB.cpp)
