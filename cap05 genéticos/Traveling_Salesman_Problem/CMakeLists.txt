cmake_minimum_required(VERSION 4.0)
project(Traveling_Salesman_Problem)

set(CMAKE_CXX_STANDARD 20)

add_executable(Traveling_Salesman_Problem main.cpp
        TSP.cpp
        TSP.h
        Cromosoma.cpp
        Cromosoma.h
        AlgoritmoGenetico.cpp
        AlgoritmoGenetico.h)
