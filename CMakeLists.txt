cmake_minimum_required(VERSION 3.29)
project(TicTacToe)

set(CMAKE_CXX_STANDARD 20)

add_executable(TicTacToe main.cpp
        enemy.cpp
        logic.cpp
        logic.h
        enemy.h
        main.h)
