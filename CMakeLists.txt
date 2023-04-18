cmake_minimum_required(VERSION 3.24)
project(path_finding)

set(CMAKE_CXX_STANDARD 14)

add_executable(path_finding main.cpp sources/SquareGridMap.cpp sources/SquareGridMapWithWeight.cpp)
