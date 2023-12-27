cmake_minimum_required(VERSION 3.27)
project(Monopoly)

set(CMAKE_CXX_STANDARD 11)

add_executable(Monopoly main.cpp
        src/ScoreBoard.cpp
        src/Box.cpp
        include/Box.h
        src/AngularBox.cpp
        include/AngularBox.h
        src/LateralBox.cpp
        include/LateralBox.h
        include/ScoreBoard.h
        include/RealPlayer.h
        include/Player.h
        include/ComputerPlayer.h
        include/BankAccount.h)
