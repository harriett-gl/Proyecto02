cmake_minimum_required(VERSION 3.26)
project(Proyecto02)

set(CMAKE_CXX_STANDARD 17)

add_executable(Proyecto02 main.cpp
        Hash.cpp
        Hash.h
        DobleLista.cpp
        DobleLista.h
        Data.cpp
        Data.h
        Nodo.cpp
        Nodo.h)
