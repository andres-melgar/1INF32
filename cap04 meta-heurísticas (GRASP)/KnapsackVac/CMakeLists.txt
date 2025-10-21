cmake_minimum_required(VERSION 4.0)
project(Knapsack)

set(CMAKE_CXX_STANDARD 20)

add_executable(Knapsack main.cpp
        Articulo.cpp
        Articulo.h
        SolucionCandidata.cpp
        SolucionCandidata.h
        Knapsack.cpp
        Knapsack.h
        CasosPrueba.cpp
        CasosPrueba.h)
