cmake_minimum_required(VERSION 3.15)
project(Labo_9)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Labo_9
        .gitignore
        dictionary.txt
        lecture.cpp
        lecture.h
        main.cpp
        recherche.cpp
        recherche.h)
