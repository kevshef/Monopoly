cmake_minimum_required(VERSION 3.22.1)
project(Monopoly)

set(CMAKE_CXX_STANDARD 11)

add_executable(Monopoly
        main.cpp
        src/Board.cpp
        include/Board.h
        src/Box.cpp
        include/Box.h
        src/Player.cpp
        include/Player.h
        src/BankAccount.cpp
        include/BankAccount.h
        src/ComputerPlayer.cpp
        include/ComputerPlayer.h
        src/HumanPlayer.cpp
        include/HumanPlayer.h
        src/Game.cpp
        include/Game.h)
