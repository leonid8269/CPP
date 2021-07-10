cmake_minimum_required(VERSION 3.19)
project("Computer simulator" VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 14)

add_executable(go src/main.cpp include/cpu.h include/ram.h include/disk.h include/gpu.h
                  include/kbd.h src/cpu.cpp src/disk.cpp src/gpu.cpp src/kbd.cpp src/ram.cpp)