cmake_minimum_required(VERSION 3.19)
project("3 leason" VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 14)

add_executable(go src/main.cpp include/my_math.h src/math.cpp)
target_include_directories(go PUBLIC include)