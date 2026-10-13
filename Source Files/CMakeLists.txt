cmake_minimum_required(VERSION 4.3)
project(Source_Files)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Source_Files
        main.cpp
        main.h
        twosidelist.cpp
        twosidelist.h)
