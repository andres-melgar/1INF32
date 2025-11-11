cmake_minimum_required(VERSION 4.0)
project(Job_Scheduling)

set(CMAKE_CXX_STANDARD 20)

add_executable(Job_Scheduling main.cpp
        Trabajo.cpp
        Trabajo.h
        Programacion.cpp
        Programacion.h
        AlgoritmoGenetico.cpp
        AlgoritmoGenetico.h)
