cmake_minimum_required(VERSION 3.27)
project(Monopoly)

set(CMAKE_CXX_STANDARD 11)

add_executable(Monopoly main.cpp
        src/ScoreBoard.cpp
        include/ScoreBoard.h

)

