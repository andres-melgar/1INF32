cmake_minimum_required(VERSION 3.31)
project(Dijkstra)

set(CMAKE_CXX_STANDARD 20)

add_executable(Dijkstra main.cpp
        Grafo.cpp
        Grafo.h)
