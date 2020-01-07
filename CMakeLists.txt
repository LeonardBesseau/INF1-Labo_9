cmake_minimum_required(VERSION 3.15)
project(Labo_9)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Labo_9
        lecture.h
        lecture.cpp
        main.cpp
        recherche.h
        recherche.cpp
        utils.h
        utils.cpp)
