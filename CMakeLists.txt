cmake_minimum_required(VERSION 3.24)
project(path_finding)

set(CMAKE_CXX_STANDARD 14)

add_executable(path_finding main.cpp source/SquareGridMap.cpp source/SquareGridMapWithWeight.cpp)
