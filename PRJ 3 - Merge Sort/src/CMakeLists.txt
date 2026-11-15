cmake_minimum_required(VERSION 4.3)
project(src)

set(CMAKE_CXX_STANDARD 14)

add_executable(src main.cpp
        mergeSort.cpp
        mergeSort.h)
