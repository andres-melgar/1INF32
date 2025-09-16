cmake_minimum_required(VERSION 3.31)
project(TravelingSalesman)

set(CMAKE_CXX_STANDARD 20)

add_executable(TravelingSalesman main.cpp
        TravelingSalesman.cpp
        TravelingSalesman.h)
