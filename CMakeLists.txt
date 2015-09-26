cmake_minimum_required(VERSION 3.3)
project(Lab1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Memory/Memory.cpp Memory/Memory.h Functions/Functions.cpp Functions/Functions.h)
add_executable(Lab1 ${SOURCE_FILES})
