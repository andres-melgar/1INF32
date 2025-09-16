cmake_minimum_required(VERSION 3.31)
project(CoinChange)

set(CMAKE_CXX_STANDARD 20)

add_executable(CoinChange main.cpp
        CoinChange.cpp
        CoinChange.h)
