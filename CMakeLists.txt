cmake_minimum_required(VERSION 3.27)
project(Projekt1_SD_Bodnar)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Projekt1_SD_Bodnar
        LinkedList.cpp
        LinkedList.hpp
        main.cpp
        DynamicArray.cpp
        DynamicArray.hpp)
