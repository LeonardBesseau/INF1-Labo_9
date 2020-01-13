cmake_minimum_required(VERSION 3.15)
project(Labo_9)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wconversion -Wextra -pedantic")

add_executable(Labo_9
        lecture.h
        lecture.cpp
        main.cpp
        recherche.h
        recherche.cpp
        utils.h
        utils.cpp)
