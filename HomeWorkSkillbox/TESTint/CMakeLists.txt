cmake_minimum_required(VERSION 3.17)
project(TESTint)

set(CMAKE_CXX_STANDARD 20)

add_executable(TESTint src/main.cpp include/tested.h src/tested.cpp)