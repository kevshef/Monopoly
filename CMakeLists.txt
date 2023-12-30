cmake_minimum_required(VERSION 3.22.1)
project(Monopoly)

set(CMAKE_CXX_STANDARD 11)

add_executable(Monopoly main.cpp
        src/Board.cpp
        src/Box.cpp
        include/Box.h
        include/Board.h
        include/RealPlayer.h
        include/Player.h
        include/ComputerPlayer.h
        include/BankAccount.h
        src/BankAccount.cpp)
